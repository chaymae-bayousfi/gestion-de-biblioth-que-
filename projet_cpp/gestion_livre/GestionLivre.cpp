#include "GestionLivre.h"


GestionLivre::GestionLivre(const string& fichierLivres, const string& fichierCategories)
    : fichierLivres(fichierLivres), gestionCategorie(fichierCategories) {
    chargerLivres();
}

GestionCategorie& GestionLivre::getGestionCategorie() {
    return gestionCategorie;
}

vector<livre> GestionLivre::getLivres() const {
    return livres;
}


void GestionLivre::chargerLivres() {
    ifstream fichier(fichierLivres);
    if (!fichier.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier " << fichierLivres << " pour charger les livres." << endl;
        return;
    }
    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne); // lire la ligne
        string titre, auteur, genre, editeur;
        int ISBN = 0, annee_pub = 0, copiesdispo = 0, idCategorie = 0;

        // Lecture et découpage de la ligne à l'aide du séparateur '|'
        string temp;
        if (getline(ss, temp, '|')) ISBN = stoi(temp);
        if (getline(ss, titre, '|')){}
        if (getline(ss, auteur, '|')){}
        if (getline(ss, genre, '|')){}
        if (getline(ss, temp, '|')) annee_pub = stoi(temp);
        if (getline(ss, editeur, '|')){}
        if (getline(ss, temp, '|')) copiesdispo = stoi(temp);
        if (getline(ss, temp, '|')) idCategorie = stoi(temp);

        livres.push_back(livre(titre, auteur, ISBN, genre, annee_pub, editeur, copiesdispo, idCategorie));
    }

    fichier.close();
    cout << "Les livres ont été chargés avec succès depuis " << fichierLivres << "." << endl;
}


void GestionLivre::sauvegarderLivres() {
    ofstream fichier(fichierLivres);
    if (!fichier.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder les livres." << endl;
        return;
    }
    for (int i = 0; i < livres.size(); ++i) {
        fichier << livres[i].getISBN() << "|" << livres[i].getTITRE() << "|"
                << livres[i].getAUTEUR() << "|" << livres[i].getGENRE() << "|"
                << livres[i].getANNEEPUB() << "|" << livres[i].getEDITEUR() << "|"
                << livres[i].getCOPIESDISPO() << "|" 
                << livres[i].getIDCategorie() << endl;
    }
    fichier.close();
}


void GestionLivre::ajouterLivre() {
    string titre, auteur, genre, editeur;
    int ISBN, annee_pub, copiesdispo, idCategorie;
    
    cout << "=== Ajouter un Livre ===" << endl;
    cout << "Entrez le titre : "; cin >> titre;
    cout << "Entrez l'auteur : "; cin >> auteur;
    cout << "Entrez le genre : "; cin >> genre;
    cout << "Entrez l'année de publication : "; cin >> annee_pub;
    cout << "Entrez l'éditeur : "; cin >> editeur;
    cout << "Entrez le nombre de copies disponibles : "; cin >> copiesdispo;

    gestionCategorie.afficherCategories();
    cout << "Entrez l'ID de la catégorie : ";
    cin >> idCategorie;

    bool categorieExistante = false;
    for (const auto& cat : gestionCategorie.getCategories()) {
        if (cat.getID() == idCategorie) {
            categorieExistante = true;
            break;
        }
    }
    if (!categorieExistante) {
        cout << "Erreur : Cette catégorie n'existe pas !" << endl;
        return;
    }

    ISBN = (livres.empty()) ? 1 : livres.back().getISBN() + 1;
    
    livres.push_back(livre(titre, auteur, ISBN, genre, annee_pub, editeur, copiesdispo, idCategorie));
    sauvegarderLivres();
    cout << "Livre ajouté avec succès !" << endl;
}

void GestionLivre::modifierLivre(int ISBN) {
    string titre, auteur, genre, editeur;
    int annee_pub, copiesdispo, idCategorie;
    bool modification = false;

    for (int i = 0; i < livres.size(); ++i) {
        if (livres[i].getISBN() == ISBN) {
            cout << "=== Modifier le Livre ===" << endl;

            cout << "Entrez le nouveau titre (laisser vide pour ne pas modifier) : ";
            cin.ignore(); 
            getline(cin, titre);
            if (!titre.empty()) {
                livres[i].setTitre(titre);
                modification = true;
            }
            cout << "Entrez le nouvel auteur (laisser vide pour ne pas modifier) : ";
            getline(cin, auteur);
            if (!auteur.empty()) {
                livres[i].setAuteur(auteur);
                modification = true;
            }
            cout << "Entrez le nouveau genre (laisser vide pour ne pas modifier) : ";
            getline(cin, genre);
            if (!genre.empty()) {
                livres[i].setGenre(genre);
                modification = true;
            }
            cout << "Entrez la nouvelle année de publication (laisser vide pour ne pas modifier) : ";
            string annee_pub_input;
            getline(cin, annee_pub_input);
            if (!annee_pub_input.empty()) {
                annee_pub = stoi(annee_pub_input);  // Conversion de string en int
                livres[i].setAnneePub(annee_pub);
                modification = true;
            }
            cout << "Entrez le nouvel éditeur (laisser vide pour ne pas modifier) : ";
            getline(cin, editeur);
            if (!editeur.empty()) {
                livres[i].setEditeur(editeur);
                modification = true;
            }
            cout << "Entrez le nouveau nombre de copies disponibles (laisser vide pour ne pas modifier) : ";
            string copiesdispo_input;
            getline(cin, copiesdispo_input);
            if (!copiesdispo_input.empty()) {
                copiesdispo = stoi(copiesdispo_input);
                livres[i].setCopiesDispo(copiesdispo);
                modification = true;
            }
            gestionCategorie.afficherCategories();
            cout << "Entrez l'ID de la catégorie (laisser vide pour ne pas modifier) : ";
            string idCategorie_input;
            getline(cin, idCategorie_input);
            if (!idCategorie_input.empty()) {
                idCategorie = stoi(idCategorie_input);
                bool categorieExistante = false;
                for (const auto& cat : gestionCategorie.getCategories()) {
                    if (cat.getID() == idCategorie) {
                        categorieExistante = true;
                        break;
                    }
                }
                if (!categorieExistante) {
                    cout << "Erreur : Cette catégorie n'existe pas !" << endl;
                    return;
                }
                livres[i].setIDCategorie(idCategorie);
                modification = true;
            }

            if (modification) {
                sauvegarderLivres();
                cout << "Livre modifié avec succès !" << endl;
            } else {
                cout << "Aucune modification n'a été effectuée." << endl;
            }
            return;
        }
    }
    cout << "Livre avec ISBN " << ISBN << " non trouvé !" << endl;
}


void GestionLivre::supprimerLivre(int ISBN) {
    auto it = remove_if(livres.begin(), livres.end(), [ISBN](const livre& livre) {
        return livre.getISBN() == ISBN;
    });
    if (it != livres.end()) {
        livres.erase(it, livres.end());
        sauvegarderLivres();
        cout << "Livre supprimé avec succès !" << endl;
    } else {
        cout << "Livre avec ISBN " << ISBN << " non trouvé !" << endl;
    }
}

void GestionLivre::rechercherLivres() {
    string titre, auteur, genre;
    int annee_pub = 0;
    char filter;

    cout << "=== Recherche Avancée ===" << endl;

    cin.ignore(); // Nettoyer le buffer avant d'utiliser getline
    cout << "Rechercher par titre (laisser vide pour ignorer) : ";
    getline(cin, titre);
    cout << "Rechercher par auteur (laisser vide pour ignorer) : ";
    getline(cin, auteur);
    cout << "Rechercher par genre (laisser vide pour ignorer) : ";
    getline(cin, genre);
    cout << "Rechercher par année de publication (0 pour ignorer) : ";
    cin >> annee_pub;
    cout << "Voulez-vous filtrer par disponibilité (O/N) ? ";
    cin >> filter;
    cout << "=== Résultats de la recherche ===" << endl;

    bool found = false;

    // Convertir les critères en minuscules pour les rendre insensibles à la casse
    transform(titre.begin(), titre.end(), titre.begin(), ::tolower);
    transform(auteur.begin(), auteur.end(), auteur.begin(), ::tolower);
    transform(genre.begin(), genre.end(), genre.begin(), ::tolower);

    for (const auto& livre : livres) {
        string livreTitre = livre.getTITRE();
        string livreAuteur = livre.getAUTEUR();
        string livreGenre = livre.getGENRE();

        transform(livreTitre.begin(), livreTitre.end(), livreTitre.begin(), ::tolower);
        transform(livreAuteur.begin(), livreAuteur.end(), livreAuteur.begin(), ::tolower);
        transform(livreGenre.begin(), livreGenre.end(), livreGenre.begin(), ::tolower);

        if ((!titre.empty() && livreTitre.find(titre) == string::npos) ||
            (!auteur.empty() && livreAuteur.find(auteur) == string::npos) || 
            (!genre.empty() && livreGenre.find(genre) == string::npos) || 
            (annee_pub != 0 && livre.getANNEEPUB() != annee_pub) || 
            (filter == 'O' && livre.getCOPIESDISPO() == 0)) { 
            continue;
        }

        cout << "ISBN: " << livre.getISBN() << ", Titre: " << livre.getTITRE() << ", Auteur: " << livre.getAUTEUR()
             << ", Genre: " << livre.getGENRE() << ", Année: " << livre.getANNEEPUB() << ", Editeur: " << livre.getEDITEUR()
             << ", Copies disponibles: " << livre.getCOPIESDISPO() << endl;

        found = true;
    }

    if (!found) {
        cout << "Aucun livre trouvé avec ces critères." << endl;
    }
}


void GestionLivre::afficherLivres() {
    cout << "=== Liste des Livres ===" << endl;
    for (const auto& livre : livres) {
        cout << "ISBN: " << livre.getISBN() << ", Titre: " << livre.getTITRE() << ", Auteur: " << livre.getAUTEUR()
             << ", Genre: " << livre.getGENRE() << ", Année: " << livre.getANNEEPUB() << ", Editeur: " << livre.getEDITEUR()
             << ", Copies disponibles: " << livre.getCOPIESDISPO()  << ", Catégorie ID: " << livre.getIDCategorie() << endl;
         cout << "----------------------------------" << endl;
    }
}

void GestionLivre::menu() {
    GestionLivre gestion("livre.txt", "categorie.txt");
    int choix;
    int ISBN;

    while (true)
    {
        cout << "\n=== Menu de gestion des livres ===\n";
        cout << "1. Ajouter un livre\n";
        cout << "2. Modifier un livre\n";
        cout << "3. Supprimer un livre\n";
        cout << "4. Afficher tous les livres\n";
        cout << "5. Rechercher des livres\n"; 
        cout << "6. Gérer les catégories\n"; 
        cout << "0. Quitter\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix)
        {
            case 1:
                gestion.ajouterLivre();
                break;
            case 2:
                cout << "Entrez l'ISBN du livre à modifier : ";
                cin >> ISBN;
                gestion.modifierLivre(ISBN);
                break;
            case 3:
                cout << "Entrez l'ISBN du livre à supprimer : ";
                cin >> ISBN;
                gestion.supprimerLivre(ISBN);
                break;
            case 4:
                gestion.afficherLivres();
                break;
            case 5:
                gestion.rechercherLivres();
                break;
            case 6: {
                int gestionCategorieChoix;
                while (true) {
                    cout << "\n=== Menu de gestion des catégories ===\n";
                    cout << "1. Ajouter une catégorie\n";
                    cout << "2. Modifier une catégorie\n";
                    cout << "3. Supprimer une catégorie\n";
                    cout << "4. Afficher toutes les catégories\n";
                    cout << "5. Retour au menu principal\n";
                    cout << "Entrez votre choix : ";
                    cin >> gestionCategorieChoix;

                    switch (gestionCategorieChoix) {
                        case 1: {
                            string nomCategorie;
                            cout << "Entrez le nom de la catégorie : ";
                            cin >> nomCategorie;
                            int idCategorie = gestion.getGestionCategorie().getCategories().size() + 1;
                            categorie nouvelleCategorie(idCategorie, nomCategorie);
                            gestion.getGestionCategorie().ajouterCategorie(nouvelleCategorie);
                            break;
                        }
                        case 2: {
                            int idCategorie;
                            cout << "Entrez l'ID de la catégorie à modifier : ";
                            cin >> idCategorie;
                            string nouveauNomCategorie;
                            cout << "Entrez le nouveau nom de la catégorie : ";
                            cin >> nouveauNomCategorie;
                            categorie nouvelleCategorie(idCategorie, nouveauNomCategorie);
                            gestion.getGestionCategorie().modifierCategorie(idCategorie);
                            break;
                        }
                        case 3: {
                            int idCategorie;
                            cout << "Entrez l'ID de la catégorie à supprimer : ";
                            cin >> idCategorie;
                            gestion.getGestionCategorie().supprimerCategorie(idCategorie);
                            break;
                        }
                        case 4:
                            gestion.getGestionCategorie().afficherCategories();
                            break;
                        case 5:
                            cout << "Retour au menu principal..." << endl;
                            break;
                        default:
                            cout << "Choix invalide, veuillez réessayer." << endl;
                            break;
                    }

                    if (gestionCategorieChoix == 5) break;
                }
                break;
            }
            case 0:
                cout << "Merci d'avoir utilisé le gestionnaire de livres. À bientôt !" << endl;
                return ;
            default:
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
        }
    }
    return ;

}