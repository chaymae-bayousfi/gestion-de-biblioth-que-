#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "../gestion_categorie/categorie.h"

using namespace std;

class livre
{
    private :
        string titre;
        string auteur;
        int ISBN;
        string genre;
        int annee_pub;
        string editeur;
        int copiesdispo;
        int idCategorie ;

    public :
        livre();
        livre(string titre,  string auteur,  int ISBN, string genre, int annee_pub, string editeur,int copiesdispo,  int idCategorie );
        string getTITRE() const;
        string getAUTEUR() const;
        int getISBN() const;
        string getGENRE() const;
        int getANNEEPUB() const;
        string getEDITEUR() const;
        int getCOPIESDISPO() const;
        int getIDCategorie () const;

        void setTitre(const string& nouveauTitre);
        void setAuteur(const string& nouvelAuteur);
        void setISBN(int nouvelISBN);
        void setGenre(const string& nouveauGenre);
        void setAnneePub(int nouvelleAnneePub);
        void setEditeur(const string& nouvelEditeur);
        void setCopiesDispo(int nouvellesCopies);
        void setIDCategorie(int idcategorie);

        void afficher ()const;
};

#endif 