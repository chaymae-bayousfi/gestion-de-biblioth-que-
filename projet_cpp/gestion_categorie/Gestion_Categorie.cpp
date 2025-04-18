#include "Gestion_Categorie.h"

using namespace std;

GestionCategorie::GestionCategorie(const string& fichier) : fichierCategories(fichier) {
    ifstream fichierStream(fichier);
    if (!fichierStream.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier " << fichier << " pour charger les catégories." << endl;
        return;
    }

    int id;
    string nom;
    while (fichierStream >> id) {
        fichierStream.ignore(); // Ignore le caractère séparateur
        getline(fichierStream, nom);
        categories.emplace_back(id, nom); // Ajoute une catégorie avec l'ID et le nom a categories
    }

    fichierStream.close();
    cout << "Catégories chargées avec succès depuis " << fichier << "." << endl;
}


const vector<categorie>& GestionCategorie::getCategories() const {
    return categories; 
}

void GestionCategorie::sauvegarderCategories() {
    ofstream fichier(fichierCategories);
    if (!fichier) {
        cout << "Erreur d'ouverture du fichier " << fichierCategories << endl;
        return;
    }

    for (const auto& cat : categories) {
        fichier << cat.getID() << "|" << cat.getNOM() << endl;
    }

    fichier.close();
    cout << "Les catégories ont été sauvegardées dans " << fichierCategories << "." << endl;
}


void GestionCategorie::ajouterCategorie(const categorie& cat) {
    for (const auto& existingCat : categories) {
        if (existingCat.getID() == cat.getID()) {
            cout << "Erreur : Une catégorie avec cet ID existe déjà !" << endl;
            return;
        }
    }
    categories.push_back(cat);
    sauvegarderCategories(); 
    cout << "Catégorie ajoutée avec succès !" << endl;
}


void GestionCategorie::modifierCategorie(int id) {
    string nom;
    for (auto& cat : categories) {
        if (cat.getID() == id) {
            cout << "Entrez le nouveau nom de la catégorie : ";
            cin.ignore(); 
            getline(cin, nom);
            cat.setNOM(nom);
            sauvegarderCategories();
            cout << "Catégorie modifiée avec succès !" << endl;
            return;
        }
    }
    cout << "Catégorie avec ID " << id << " non trouvée !" << endl;
}


void GestionCategorie::supprimerCategorie(int id) {
    auto it = remove_if(categories.begin(), categories.end(), [id](const categorie& cat) {
        return cat.getID() == id;
    });

    if (it != categories.end()) {
        categories.erase(it, categories.end());
        sauvegarderCategories();
        cout << "Catégorie supprimée avec succès !" << endl;
    } else {
        cout << "Catégorie avec ID " << id << " non trouvée !" << endl;
    }
}

void GestionCategorie::afficherCategories() {
    cout << "=== Liste des Catégories ===" << endl;
    for (const auto& cat : categories) {
        cat.afficher();
    }
}