#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class categorie{
    private:
        int id;
        string nom;
    public :
    categorie();
    categorie(int id, string nom);

    int getID() const;
    string getNOM()const;

    void setID(int id);
    void setNOM(const string& nom);

    void afficher() const;
};

#endif