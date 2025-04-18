#include "categorie.h"

categorie::categorie (){ id = 0; nom="";}
categorie:: categorie(int id, string nom){this->id = id; this->nom = nom;}

int categorie:: getID() const{return id;}
string categorie:: getNOM()const{return nom;}

void categorie:: setID(int id){this->id = id;}
void categorie:: setNOM(const string& nom){this->nom = nom;}

 void categorie::  afficher() const{
	cout<<"id de categorie est :"<<id << "||"
	<<"le nom de categorie est :"<<nom << endl;
 }


