#include "GestionUtilisateur.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

void GestionUtilisateur::chargerUtilisateurs() {
    ifstream fichier(fichierutilisateurs);
    if (!fichier.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier " << fichierutilisateurs << " pour charger les utilisateurs." << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne); // Crée un flux pour analyser la ligne
        string temp, nom, prenom, email, motDePasse, rolestr;
        int id = 0;
        Role role = UTILISATEUR;

        // Lecture et découpage de la ligne à l'aide du séparateur '|'
        if (getline(ss, temp, '|')) id = stoi(temp);
        if (getline(ss, nom, '|')) {}
        if (getline(ss, prenom, '|')) {}
        if (getline(ss, email, '|')) {}
        if (getline(ss, motDePasse, '|')) {}
        if (getline(ss, rolestr, '|')) {
            if (rolestr == "administrateur")
                role = ADMINISTRATEUR;
            else if (rolestr == "bibliothecaire")
                role = BIBLIOTHECAIRE;
            else
                role = UTILISATEUR;
        }

        // Ajout de l'utilisateur à la liste
        utilisateurs.push_back(Utilisateur(id, nom, prenom, email, motDePasse, role));
    }

    fichier.close();
    cout << "Les utilisateurs ont été chargés avec succès depuis " << fichierutilisateurs << "." << endl;
}



void GestionUtilisateur::sauvegarderUtilisateur()
{
    ofstream fichier(fichierutilisateurs);
    if (!fichier.is_open())
    {
        cout << "Erreur : impossible d'ouvrir le fichier pour sauvegarder les utilisateurs." << endl;
        return;
    }
    for (const auto& utilisateur : utilisateurs) {
        fichier << utilisateur.getidUtilisateur() << "|"
                << utilisateur.getnom() << "|"
                << utilisateur.getprenom() << "|"
                << utilisateur.getemail() << "|"
                << utilisateur.getmotDePasse() << "|"
                << (utilisateur.getrole_utili() == ADMINISTRATEUR ? "administrateur" :
                    (utilisateur.getrole_utili() == BIBLIOTHECAIRE ? "bibliothecaire" : "utilisateur"))
                << endl;
    }
    fichier.close();
    cout << "Les utilisateurs ont été sauvegardés avec succès !" << endl;
}

GestionUtilisateur::GestionUtilisateur()
{
    chargerUtilisateurs();
}
void GestionUtilisateur::inscrireUtilisateur()
{
    string nom, prenom,email, motDePasse;
    int choixRole;
    Role role;
    cout << "=== Formulaire d'inscription ===" << endl;
    cout << "entre votre nom :"; cin >> nom;
    cout << "entre votre prenom :"; cin >> prenom;
    cout << "entre votre email :"; cin >> email;
    cout << "entre votre mot de pass :"; cin >> motDePasse;
    cout <<  "choisissez un role (1: Administrateur , 2 :  bibliothecaire , 3 : utilisateur) :"; 
    cin >> choixRole;
    switch (choixRole)
    {
        case 1: role= ADMINISTRATEUR; break;
        case 2: role= BIBLIOTHECAIRE; break;
        case 3: role= UTILISATEUR; break;
        default:role= UTILISATEUR; break;
    }
    int id;
    if(utilisateurs.empty())
        id=1;
    else
        id=utilisateurs.back().getidUtilisateur()+1;
    utilisateurs.push_back(Utilisateur(id, nom, prenom, email, motDePasse,role));
    sauvegarderUtilisateur();
    cout<<"inscription reussi !"<<endl;

}

void GestionUtilisateur::modifierUtilisateur(int id) {
    string nom, prenom, email, motDePasse;
    Role role;
    string rolestr;

    for (int i = 0; i < utilisateurs.size(); ++i) {
        if (utilisateurs[i].getidUtilisateur() == id) {
            cout << "=== Modifier l'Utilisateur ===" << endl;
            cout << "Entrez le nouveau nom : "; cin >> nom;
            cout << "Entrez le nouveau prénom : "; cin >> prenom;
            cout << "Entrez le nouvel email : "; cin >> email;
            cout << "Entrez le nouveau mot de passe : "; cin >> motDePasse;

            cout << "Entrez le rôle (administrateur, bibliothecaire, utilisateur) : ";
            cin >> rolestr;

            // Vérification du rôle saisi
            if (rolestr == "administrateur") {
                role = ADMINISTRATEUR;
            } else if (rolestr == "bibliothecaire") {
                role = BIBLIOTHECAIRE;
            } else if (rolestr == "utilisateur") {
                role = UTILISATEUR;
            } else {
                cout << "Erreur : Rôle invalide. Modification annulée !" << endl;
                return;
            }

            utilisateurs[i].setnom(nom);
            utilisateurs[i].setprenom(prenom);
            utilisateurs[i].setemail(email);
            utilisateurs[i].setmotDePasse(motDePasse);
            utilisateurs[i].setrole_utili(role);

            sauvegarderUtilisateur();
            cout << "Utilisateur modifié avec succès !" << endl;
            return;
        }
    }
    cout << "Utilisateur avec ID " << id << " non trouvé !" << endl;
}

void GestionUtilisateur::supprimerUtilisateur(int id) {
    auto it = remove_if(utilisateurs.begin(), utilisateurs.end(), [id](const Utilisateur& utilisateur) {
        return utilisateur.getidUtilisateur() == id;
    });

    if (it != utilisateurs.end()) {
        utilisateurs.erase(it, utilisateurs.end()); // Supprime les éléments déplacés par remove_if
        sauvegarderUtilisateur();
        cout << "Utilisateur supprimé avec succès !" << endl;
    } else {
        cout << "Erreur : Utilisateur avec ID " << id << " non trouvé !" << endl;
    }
}

void GestionUtilisateur::afficherUtilisateurs()
{
    if (utilisateurs.empty())
    {
        cout<<"aucun utilisateur a afficher."<<endl;
    }
    for (int i=0;i<utilisateurs.size();i++)
    {
        cout <<"utilisateur "<<i+1<<":"<<endl;
        utilisateurs[i].affiche();
        cout <<endl;
    }
}
vector<Utilisateur> GestionUtilisateur::getUtilisateurs() const {
    return utilisateurs;
}

void GestionUtilisateur::menu()
{
    int choix;
    int id;

    while (true)
    {
        // Affichage du menu
        cout << "\n=== Menu ===\n";
        cout << "1. Inscrire un utilisateur\n";
        cout << "2. Modifier un utilisateur\n";
        cout << "3. Supprimer un utilisateur\n";
        cout << "4. afficher le utilisateurs\n";
        cout << "5. Quitter\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix)
        {
            case 1:
                inscrireUtilisateur();  // Inscrire un utilisateur
                break;
            case 2:
                cout << "Entrez l'ID de l'utilisateur à modifier : ";
                cin >> id;
                modifierUtilisateur(id);  // Modifier un utilisateur
                break;
            case 3:
                cout << "Entrez l'ID de l'utilisateur à supprimer : ";
                cin >> id;
                supprimerUtilisateur(id);  // Supprimer un utilisateur
                break;
            case 4:
                cout << "Les utilisateurs actuellement enregistrés sont : "<<endl;
                afficherUtilisateurs();  // Afficher les utilisateurs
                break;   
            case 5:
                cout << "Merci d'avoir utilisé le gestionnaire d'utilisateurs. À bientôt !" << endl;
                return;  // Quitter le programme
            default:
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
        }
    }
}
