#include "paquet.h"
#include "carte.h"
using namespace std;

/* ========== PUBLIC METHODS ========== */

Paquet::Paquet() {
    for (int suit = 0; suit < NUM_SUITS; suit++) {
        for (int value = CARD_ENUM_START; value < CARD_ENUM_END; value++) {
            Carte::Couleur suit_enum = static_cast<Carte::Couleur>(suit);
            Carte::Valeur val_enum = static_cast<Carte::Valeur>(value);
            Carte *carte = new Carte(suit_enum, val_enum);

            cartes.push_back(carte);
            paquet.push(carte);
        }
    }

}


Paquet::~Paquet() {
    reset_paquet();
    for (Carte *carte : cartes) {
        delete carte;

    }
}

bool Paquet::est_vide() {
    return this->paquet.empty();
}

void Paquet::melanger() {
    reset_paquet(); // Ensure empty deck

    // Obtain random seed based on time (from c++ documentation: https://cplusplus.com/algorithm/shuffle/)
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cartes.begin(), cartes.end(), default_random_engine(seed));

    for (Carte* card : cartes) { paquet.push(card); }
}

// Change to return a Carte* to the card on the top of the drawn card deck
Carte* Paquet::egalite() {
    //std::cout << deck.top()->print() << std::endl;
    Carte* ret = paquet.top();
    paquet.pop();

    return ret;
}

void Paquet::print() {
    for (Carte* card : cartes) {
        cout << card->print() << endl;
    }
}

/* ========== PRIVATE METHODS ========== */
void Paquet::reset_paquet() {
    while (!paquet.empty()) { paquet.pop(); }
}