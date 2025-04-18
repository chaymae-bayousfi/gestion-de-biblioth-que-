// GestionEmprunt.cpp
#include "GestionEmprunt.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

// Constructeur
GestionEmprunt::GestionEmprunt() {
    chargerEmprunts(); // Charge les emprunts depuis le fichier lors de l'initialisation
}

// Fonction pour enregistrer un emprunt
void GestionEmprunt::enregistrerEmprunt(int idUtilisateur, int idLivre, string dateEmprunt, string dateRetourPrevu) {
    int idEmprunt = emprunts.empty() ? 1 : emprunts.back().getIdEmprunt() + 1;
    emprunts.push_back(Emprunt(idEmprunt, idUtilisateur, idLivre, dateEmprunt, dateRetourPrevu));
    sauvegarderEmprunts();
    cout << "Emprunt enregistré avec succès !" << endl;
}

// Fonction pour enregistrer un retour de livre
void GestionEmprunt::enregistrerRetour(int idEmprunt, string dateRetour) {
    for (auto& emprunt : emprunts) {
        if (emprunt.getIdEmprunt() == idEmprunt) {
            emprunt.retournerLivre(dateRetour);
            sauvegarderEmprunts();
            cout << "Retour du livre enregistré !" << endl;
            return;
        }
    }
    cout << "Emprunt non trouvé !" << endl;
}

// Fonction pour afficher l'historique des emprunts pour un utilisateur
void GestionEmprunt::afficherHistoriqueEmprunts(int idUtilisateur) {
    for (const auto& emprunt : emprunts) {
        if (emprunt.getIdUtilisateur() == idUtilisateur) {
            emprunt.afficherEmprunt();
        }
    }
}

// Fonction pour afficher l'historique des emprunts pour un livre
void GestionEmprunt::afficherHistoriqueLivres(int idLivre) {
    for (const auto& emprunt : emprunts) {
        if (emprunt.getIdLivre() == idLivre) {
            emprunt.afficherEmprunt();
        }
    }
}

// Fonction pour afficher les statistiques des livres les plus empruntés
void GestionEmprunt::afficherStatistiquesLivres() {
    map<int, int> empruntsParLivre;
    for (const auto& emprunt : emprunts) {
        empruntsParLivre[emprunt.getIdLivre()]++;
    }

    for (const auto& pair : empruntsParLivre) {
        cout << "Livre ID: " << pair.first << " - Nombre d'emprunts: " << pair.second << endl;
    }
}

// Fonction pour charger les emprunts depuis un fichier
void GestionEmprunt::chargerEmprunts() {
    ifstream fichier(fichierEmprunts);
    if (!fichier.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier des emprunts !" << endl;
        return;
    }
    int idEmprunt, idUtilisateur, idLivre;
    string dateEmprunt, dateRetourPrevu;
    while (fichier >> idEmprunt >> idUtilisateur >> idLivre >> dateEmprunt >> dateRetourPrevu) {
        emprunts.push_back(Emprunt(idEmprunt, idUtilisateur, idLivre, dateEmprunt, dateRetourPrevu));
    }
}

// Fonction pour sauvegarder les emprunts dans un fichier
void GestionEmprunt::sauvegarderEmprunts() {
    ofstream fichier(fichierEmprunts);
    if (!fichier.is_open()) {
        cout << "Erreur lors de la sauvegarde des emprunts !" << endl;
        return;
    }
    for (const auto& emprunt : emprunts) {
        fichier << emprunt.getIdEmprunt() << " " << emprunt.getIdUtilisateur() << " "
                << emprunt.getIdLivre() << " " << emprunt.getDateEmprunt() << " "
                << emprunt.getDateRetourPrevu() << endl;
    }
}

void GestionEmprunt::menu()
{
    GestionEmprunt gestionEmprunt;
    int choix;

    do {
        cout << "\n=== Menu de Gestion des Emprunts ===" << endl;
        cout << "1. Enregistrer un emprunt" << endl;
        cout << "2. Enregistrer un retour" << endl;
        cout << "3. Afficher l'historique des emprunts d'un utilisateur" << endl;
        cout << "4. Afficher l'historique des emprunts d'un livre" << endl;
        cout << "5. Afficher les statistiques des livres empruntés" << endl;
        cout << "6. Quitter" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int idUtilisateur, idLivre;
                string dateEmprunt, dateRetourPrevu;

                cout << "=== Enregistrer un emprunt ===" << endl;
                cout << "Entrez l'ID de l'utilisateur : ";
                cin >> idUtilisateur;
                cout << "Entrez l'ID du livre : ";
                cin >> idLivre;
                cout << "Entrez la date d'emprunt (YYYY-MM-DD) : ";
                cin >> dateEmprunt;
                cout << "Entrez la date de retour prévue (YYYY-MM-DD) : ";
                cin >> dateRetourPrevu;

                gestionEmprunt.enregistrerEmprunt(idUtilisateur, idLivre, dateEmprunt, dateRetourPrevu);
                break;
            }
            case 2: {
                int idEmprunt;
                string dateRetour;

                cout << "=== Enregistrer un retour ===" << endl;
                cout << "Entrez l'ID de l'emprunt : ";
                cin >> idEmprunt;
                cout << "Entrez la date de retour (YYYY-MM-DD) : ";
                cin >> dateRetour;

                gestionEmprunt.enregistrerRetour(idEmprunt, dateRetour);
                break;
            }
            case 3: {
                int idUtilisateur;

                cout << "=== Afficher l'historique d'un utilisateur ===" << endl;
                cout << "Entrez l'ID de l'utilisateur : ";
                cin >> idUtilisateur;

                gestionEmprunt.afficherHistoriqueEmprunts(idUtilisateur);
                break;
            }
            case 4: {
                int idLivre;

                cout << "=== Afficher l'historique d'un livre ===" << endl;
                cout << "Entrez l'ID du livre : ";
                cin >> idLivre;

                gestionEmprunt.afficherHistoriqueLivres(idLivre);
                break;
            }
            case 5:
                cout << "=== Statistiques des livres empruntés ===" << endl;
                gestionEmprunt.afficherStatistiquesLivres();
                break;

            case 6:
                cout << "Au revoir !" << endl;
                break;

            default:
                cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    } while (choix != 6);

    return ;
}