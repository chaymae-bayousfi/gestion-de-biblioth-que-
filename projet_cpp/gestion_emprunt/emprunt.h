// Emprunt.h
#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <string>
using namespace std;

class Emprunt {
private:
    int idEmprunt;
    int idUtilisateur;
    int idLivre;
    string dateEmprunt;
    string dateRetourPrevu;
    string dateRetour;

public:
    // Constructeur
    Emprunt(int id, int utilisateur, int livre, string emprunt, string retourPrevu);

    // Méthodes d'accès
    int getIdEmprunt() const;
    int getIdUtilisateur() const;
    int getIdLivre() const;
    string getDateEmprunt() const;
    string getDateRetourPrevu() const;
    string getDateRetour() const;

    // Méthode pour enregistrer un retour de livre
    void retournerLivre(string retour);

    // Méthode pour afficher un emprunt
    void afficherEmprunt() const;
};

#endif // EMPRUNT_H