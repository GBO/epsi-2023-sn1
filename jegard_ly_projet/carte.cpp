#include "carte.h"
using namespace std;

Carte::Carte(Couleur couleur, Valeur valeur) {
    this->couleur = couleur;
    this->valeur = valeur;
}

Carte::~Carte() {}


bool Carte::est_egal(Carte* carte) { return (this->couleur == carte->couleur) && (this->valeur == carte->valeur); }

bool Carte::est_egal_couleur(Carte* carte) { return this->couleur == carte->couleur; }

/*
Returns 0 if values/types are the same
Returns 1 if this card has a higher valeur/type than the card passed in
Returns -1 if this card has a lower valeur/type than the card passed in
*/
int Carte::comparer_valeur(Carte* carte) {
    if (this->valeur == carte->valeur) { return 0; }
    else if (this->valeur > carte->valeur) { return 1; }
    else { return -1; }

    /*
    Could also do return this->type - card->type;

    But probably better to only have 3 possible integers to return, rather than a range of them.
    */
}

// Take a look at this:
// https://stackoverflow.com/questions/11623608/passing-enum-to-a-constructor
string Carte::print() {
    string suits[4] = {"Trefle", "Carreau", "Coeur", "Pique"};
    string values[13] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};

    // CardTypes Enum starts at 2, so we subtract to not get a segfault during possible edge case
    int idx_values = valeur - 2;

    // Example output:
    // [Ace of Spades]
    return ("[ " + values[idx_values] + " de " + suits[this->couleur] + " ]");
}