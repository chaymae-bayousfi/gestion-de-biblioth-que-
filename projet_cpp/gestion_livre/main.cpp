#include "GestionLivre.h"
#include <iostream>
using namespace std;

int main()
{
    GestionLivre gestion("livre.txt", "../gestion_categorie/categorie.txt");
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
                return 0;
            default:
                cout << "Choix invalide, veuillez réessayer.\n";
                break;
        }
    }
    return 0;
}
