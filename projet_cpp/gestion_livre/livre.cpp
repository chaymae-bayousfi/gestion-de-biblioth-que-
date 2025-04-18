#include "livre.h"

livre::livre() {
    titre = "";
    auteur = "";
    ISBN = 0;
    genre = "";
    annee_pub = 0;
    editeur = "";
    copiesdispo = 0;
   idCategorie  = 0 ;
    
}

livre:: livre(string titre,  string auteur,  int ISBN, string genre, int annee_pub, string editeur,int copiesdispo, int idCategorie )
        {
            this->titre = titre;
            this->auteur = auteur;
            this->ISBN = ISBN;
            this->genre = genre;
            this->annee_pub = annee_pub;
            this->editeur = editeur;
            this->copiesdispo = copiesdispo;
            this->idCategorie  = idCategorie ;
        }

string livre:: getTITRE() const{return titre;}
string livre::  getAUTEUR() const{return auteur;}
int livre:: getISBN() const{return ISBN;}
string livre::  getGENRE()  const{return genre;}
int livre:: getANNEEPUB() const{return annee_pub;}
string livre::  getEDITEUR() const{return editeur;}
int livre:: getCOPIESDISPO() const{return copiesdispo;}
int livre:: getIDCategorie () const{return idCategorie;}


void livre:: setTitre(const string& nouveauTitre){
    if(!nouveauTitre.empty())
        titre = nouveauTitre;
    else
        cout <<"erreur : le titre ne peut pas etre vide!!"<<endl;
}
void livre:: setAuteur(const string& nouvelAuteur){
        if(!nouvelAuteur.empty())
        auteur = nouvelAuteur;
    else
        cout <<"erreur : l'auteur  ne peut pas etre vide!!"<<endl;
}
void livre:: setISBN(int nouvelISBN){
    if(nouvelISBN<0)
        cout <<"erreur : entrer une valeur positive !!"<<endl;
    ISBN = nouvelISBN;
}
void livre:: setGenre(const string& nouveauGenre){
    if(!nouveauGenre.empty())
       genre = nouveauGenre;
    else
        cout <<"erreur : le genre ne peut pas etre vide!!"<<endl;
}
void livre:: setAnneePub(int nouvelleAnneePub){
    annee_pub = nouvelleAnneePub;
}
void livre:: setEditeur(const string& nouvelEditeur){
    if(!nouvelEditeur.empty())
        editeur = nouvelEditeur;
    else
        cout <<"erreur : l'editeur' ne peut pas etre vide!!"<<endl;
}
void livre:: setCopiesDispo(int nouvellesCopies){
    if(nouvellesCopies<0)
        cout <<"erreur : entrer une valeur positive !!"<<endl;
    copiesdispo = nouvellesCopies;
}

void livre:: setIDCategorie(int idcategorie){idCategorie = idcategorie;}

void livre:: afficher() const{
    cout<<"Titre :"<<titre<<endl
        << "Auteur : " << auteur << endl
        << "ISBN : " << ISBN << endl
        << "Genre : " << genre << endl
        << "Annee : " << annee_pub << endl
        << "Editeur : " << editeur << endl
        << "Copies disponibles : " << copiesdispo << endl
        <<"id de categorie: "<<idCategorie<<endl;
}
