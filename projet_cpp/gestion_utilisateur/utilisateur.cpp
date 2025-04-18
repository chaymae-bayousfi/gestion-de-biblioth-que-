#include "utilisateur.h"
using namespace std;

//constructeurs
Utilisateur::Utilisateur()
{
    idUtilisateur = 0;
    nom = "";
    prenom = "";
    email = "";
    motDePasse ="";
    role_utili = UTILISATEUR;
}
Utilisateur::Utilisateur(int idUtilisateur,string nom,string prenom, string email, string motDePasse, Role role_utili)
{
    this->idUtilisateur=idUtilisateur;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->motDePasse=motDePasse;
    this->role_utili=role_utili;
}
//getters
int Utilisateur::getidUtilisateur() const { return idUtilisateur; }
string Utilisateur::getnom() const { return nom; }
string Utilisateur::getprenom() const { return prenom; }
string Utilisateur::getemail() const { return email; }
string Utilisateur::getmotDePasse() const { return motDePasse; }
Role Utilisateur::getrole_utili() const { return role_utili; }
//setters
void Utilisateur::setnom(string nom) { this->nom=nom; }
void Utilisateur::setprenom(string prenom) { this->prenom=prenom; }
void Utilisateur::setemail(string email) { this->email=email; }
void Utilisateur::setmotDePasse(string motDePasse) { this->motDePasse=motDePasse; }
void Utilisateur::setrole_utili(Role role_utili) { this->role_utili=role_utili; }

//fonctions
string Utilisateur::roleToString() const
{
    switch (role_utili)
    {
        case ADMINISTRATEUR: return "Administrateur";
            break;
        case BIBLIOTHECAIRE: return "bibliothecaire";
            break;
        case UTILISATEUR: return "utilisateur";
            break;
    }
    return "inconnu";
}

void Utilisateur::affiche() const {
    cout << "ID Utilisateur : " << idUtilisateur << endl
         << "Nom : " << nom << endl
         << "Prénom : " << prenom << endl
         << "Email : " << email << endl
         << "Mot de passe : " << motDePasse << endl
         << "Rôle : " << roleToString() << endl;
}

