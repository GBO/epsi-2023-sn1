#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    cout << "Exercice 3" << endl;
    int tableau[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    // Le tableau est consideré comme croissant/decroissant/constant jusqu'a ce qu'un if prouve le contraire
    bool croissant = true, decroissant = true, constant = true;
    for (int i = 1; i < 10; i++) {
        if (tableau[i] > tableau[i-1]) {
            decroissant = false; // Le tableau n'est pas trié par ordre décroissant
            constant = false; // Le tableau n'est pas constant
        } else if (tableau[i] < tableau[i-1]) {
            croissant = false; // Le tableau n'est pas trié par ordre croissant
            constant = false; // Le tableau n'est pas constant
        } else {
            croissant = false; // Le tableau n'est pas trié par ordre croissant
            decroissant = false; // Le tableau n'est pas trié par ordre décroissant
        }
    }

    // Affichage du résultat (je sais pas pourquoi il faut mettre 2 = mais 1 seul ne marche pas)
    if (croissant ==true) {
        cout << "Le tableau est trie par ordre croissant." << endl;
    } else if (decroissant ==true) {
        cout << "Le tableau est trie par ordre decroissant." << endl;
    } else if (constant ==true) {
        cout << "Toutes les valeurs du tableau sont constantes." << endl;
    } else {
        cout << "Le tableau n'est pas trie." << endl;
    }

    return 0;
}
