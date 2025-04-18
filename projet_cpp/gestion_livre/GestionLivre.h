#ifndef GESTIONLIVRE_H
#define GESTIONLIVRE_H


#include <algorithm>
#include <cctype>  // pour std::tolower
#include "livre.h"
#include "../gestion_categorie/Gestion_Categorie.h"

class GestionLivre {
private:
    vector<livre> livres;
    const string fichierLivres = "livre.txt";  // Nom du fichier contenant les livres
    const string fichierCategories = "gestion_categorie/categorie.txt";
    GestionCategorie gestionCategorie;

public:
    GestionLivre(const string& fichierLivres, const string& fichierCategories);
    vector<livre> getLivres() const;
    void chargerLivres();
    void sauvegarderLivres();
    void ajouterLivre();
    void modifierLivre(int ISBN);
    void supprimerLivre(int ISBN);
    void rechercherLivres();
    void afficherLivres();

    GestionCategorie& getGestionCategorie();   // Retourner l'objet gestionCategorie
    void menu();
};

#endif