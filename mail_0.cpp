
#include <iostream>

using namespace std;

int main() {
    int choix=-1;

    while (choix != 0) {

        cout << "vous devez choisir entre :" << endl;


        cout << "1 - Exercice 1" << endl;
        cout << "2 - Exercice 2" << endl;
        cout << "3 - Exercice 3" << endl;
        cout << "0 - Sortie" << endl;


        cout<<  endl;

        cout << "Choisissez une option : ";
        cin >> choix;

        cout<<  endl;

        if (choix < 0 || choix > 3) {
            cout << "Option invalide. Veuillez reessayer." << endl;
        }  else if (choix == 1) {
            cout << "Exercice 1 selectionner" << endl;
        } else if (choix == 2) {
            cout << "Exercice 2 selectionner" << endl;
        }  else if (choix == 3) {
            cout << "Exercice 3 selectionner" << endl;
        }else if (choix == 0) {
            cout << "Programme terminee." << endl;
        }
    }

    return 0;
}
