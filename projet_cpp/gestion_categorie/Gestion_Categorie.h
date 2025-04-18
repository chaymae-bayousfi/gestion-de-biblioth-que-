#ifndef GESTIONCATEGORIE_H
#define GESTIONCATEGORIE_H

#include "categorie.h"

class GestionCategorie {
private:
    vector<categorie> categories;
    const string fichierCategories = "categorie.txt";

public:
    GestionCategorie(const string& fichier);
    const vector<categorie>& getCategories() const;

    void sauvegarderCategories();
    void ajouterCategorie(const categorie& cat);
    void modifierCategorie(int id);
    void supprimerCategorie(int id);
    void afficherCategories();
};


#endif