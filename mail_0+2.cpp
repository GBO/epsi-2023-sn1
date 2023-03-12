// Exercice 0 + 2

#include <iostream>
using namespace std;

int main() {
    int choix = -1;

    while (choix != 0) {
        cout << "0- Sortie" << endl;
        cout << "1- Exercice 1" << endl;
        cout << "2- Exercice 2" << endl;
        cout << "3- Exercice 3" << endl;
        cout << "Entrez votre choix : ";
        cin >> choix;
        switch (choix) {
            case 0:
                cout << "Le programme est terminé" << endl;

            case 1:
                // code exercice 1

            case 2:

                {
    srand(time(NULL));
    int joueur = rand() % 6 + 1;
    int ordinateur = rand() % 6 + 1;
    cout << "Le joueur a tiré un : " << joueur << endl;
    cout << "L'ordinateur a tiré un : " << ordinateur << endl;
    if (joueur > ordinateur) {
        cout << "Le joueur a gagné" << endl;
    } else if (joueur < ordinateur) {
        cout << "L'ordinateur a gagné" << endl;
    } else {
        cout << "Égalité" << endl;
    }
    return 0;
}

            case 3:
                // code exercice 3
                
            default:
                cout << "Choix invalide." << endl;
                
        }
    }
    return 0;
}
