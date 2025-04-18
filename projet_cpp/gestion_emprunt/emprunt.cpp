// Emprunt.cpp
#include "emprunt.h"
#include <iostream>
using namespace std;

// Constructeur
Emprunt::Emprunt(int id, int utilisateur, int livre, string emprunt, string retourPrevu)
    : idEmprunt(id), idUtilisateur(utilisateur), idLivre(livre), dateEmprunt(emprunt), dateRetourPrevu(retourPrevu), dateRetour("") {}

// Méthodes d'accès
int Emprunt::getIdEmprunt() const {
    return idEmprunt;
}

int Emprunt::getIdUtilisateur() const {
    return idUtilisateur;
}

int Emprunt::getIdLivre() const {
    return idLivre;
}

string Emprunt::getDateEmprunt() const {
    return dateEmprunt;
}

string Emprunt::getDateRetourPrevu() const {
    return dateRetourPrevu;
}

string Emprunt::getDateRetour() const {
    return dateRetour;
}

// Méthode pour enregistrer un retour de livre
void Emprunt::retournerLivre(string retour) {
    dateRetour = retour;
}

// Méthode pour afficher un emprunt
void Emprunt::afficherEmprunt() const {
    cout << "ID Emprunt: " << idEmprunt << ", Livre ID: " << idLivre
         << ", Utilisateur ID: " << idUtilisateur << ", Date Emprunt: " << dateEmprunt
         << ", Date Retour Prévu: " << dateRetourPrevu << ", Date Retour: " << (dateRetour.empty() ? "Pas encore retourné" : dateRetour) << endl;
}