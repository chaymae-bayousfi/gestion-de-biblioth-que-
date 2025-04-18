#ifndef GESTIONUTILISATEUR_H
#define GESTIONUTILISATEUR_H

#include "utilisateur.h"
#include <vector>
#include <string>
using namespace std;

class GestionUtilisateur
{
private:
    vector<Utilisateur> utilisateurs;
    const string fichierutilisateurs = "utilisateur.txt";

    void chargerUtilisateurs();
    void sauvegarderUtilisateur();

public:
    vector<Utilisateur> getUtilisateurs() const;
    GestionUtilisateur();
    void inscrireUtilisateur();
    void modifierUtilisateur(int id);
    void supprimerUtilisateur(int id);
    void afficherUtilisateurs();
    void menu();
};
#endif