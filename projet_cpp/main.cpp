#include <iostream>
#include "gestion_utilisateur/GestionUtilisateur.h"
#include "gestion_livre/GestionLivre.h"
#include "gestion_emprunt/GestionEmprunt.h"
#include "gestion_categorie/Gestion_Categorie.h"

using namespace std;

void afficherMenu() {
    cout << "\n=== Menu Principal ===\n";
    cout << "1. Gestion des Utilisateurs\n";
    cout << "2. Gestion des Livres\n";
    cout << "3. Gestion des Emprunts\n";
    cout << "4. Quitter\n";
    cout << "Entrez votre choix : ";
}

int main() {
    GestionUtilisateur gestionUtilisateur;
    GestionLivre gestion("gestion_livre/livre.txt", "/gestion_categorie/categorie.txt");
    GestionEmprunt gestionEmprunt;

    int choix;

    while (true) {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1:
                gestionUtilisateur.menu();  // Appelle le menu de gestion des utilisateurs
                break;
            case 2:
                gestion.menu();  // Appelle le menu de gestion des livres
                break;
            case 3:
                gestionEmprunt.menu();  // Appelle le menu de gestion des emprunts
                break;
            case 4:
                cout << "Merci d'avoir utilisé le gestionnaire de bibliothèque. À bientôt !" << endl;
                return 0;  // Quitter le programme
            default:
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
        }
    }
    return 0;
}

