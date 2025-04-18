#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

enum Role {ADMINISTRATEUR, BIBLIOTHECAIRE, UTILISATEUR};
class Utilisateur
{
private:
    int idUtilisateur;
    string nom;
    string prenom;
    string email;
    string motDePasse;
    Role role_utili;
public:
    //constructeur
    Utilisateur();
    Utilisateur(int idUtilisateur, string nom, string prenom, string email, string motDePasse, Role role_utili);

    //getters
    int getidUtilisateur() const;
    string getnom() const;
    string getprenom() const;
    string getemail() const;
    string getmotDePasse() const;
    Role getrole_utili() const;

    //setters
    void setnom(string nom);
    void setprenom(string nom);
    void setemail(string nom);
    void setmotDePasse(string nom);
    void setrole_utili(Role role_utili);

    void affiche() const;

    // Méthode utilitaire pour convertir le rôle en string
    string roleToString() const;
};

#endif