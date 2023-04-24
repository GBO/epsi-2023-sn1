#pragma once

#include <iostream>
#include <string>
using namespace std;

class Carte {
public:
    enum Valeur {
        AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI
    };
    enum Couleur { TREFLE, CARREAU, COEUR, PIQUE };

protected:
    uint16_t couleur;
    uint16_t valeur;

public:
    Carte(Couleur couleur, Valeur valeur);
    ~Carte();
    bool est_egal(Carte* carte);
    bool est_egal_couleur(Carte* carte);
    int comparer_valeur(Carte* carte);
    string print();

};