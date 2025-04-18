// GestionEmprunt.h
#ifndef GESTIONEMPRUNT_H
#define GESTIONEMPRUNT_H

#include <vector>
#include <string>
#include "emprunt.h" // Inclusion de la classe Emprunt

class GestionEmprunt {
private:
    vector<Emprunt> emprunts;
    const string fichierEmprunts = "emprunts.txt";

    // Fonctions privées
    void chargerEmprunts(); // Charge les emprunts depuis un fichier
    void sauvegarderEmprunts(); // Sauvegarde les emprunts dans un fichier

public:
    GestionEmprunt();
    void enregistrerEmprunt(int idUtilisateur, int idLivre, string dateEmprunt, string dateRetourPrevu);
    void enregistrerRetour(int idEmprunt, string dateRetour);
    void afficherHistoriqueEmprunts(int idUtilisateur);
    void afficherHistoriqueLivres(int idLivre);
    void afficherStatistiquesLivres();
    void menu();
};

#endif // GESTIONEMPRUNT_H