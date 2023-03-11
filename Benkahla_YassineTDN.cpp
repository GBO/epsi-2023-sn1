#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv) {

    //Création d'une boucle qui nous permettra de chosir l'exercice souhaité
    while (true) {
        cout << "\nMenu :\n";
        cout << "0 - Sortie\n";
        cout << "1 - Exercice 1\n";
        cout << "2 - Exercice 2\n";
        cout << "3 - Exercice 3\n\n";

        cout << "Quel exercice souhaitez-vous voir? : ";

        //le choix fait devra être un entier
        int choix;
        cin >> choix;

        //si c'est 0 on casse le programme c'est a dire le programme s'arrête
        if (choix == 0) {
            cout << "Sortie" << endl;
            break;
        }
        if (choix == 1) {
            cout << "Exercice 1" << endl;

        }
        //si le choix est 2 il sortira l'exercice 2 sans rien avoir à faire
        if (choix == 2) {

            srand(time(0)); //programme qui permet de lancer des chiffres au pif

            int Yassine = rand() % 6 + 1;// lancer de dé du joueur (nombre aléatoire entre 1 et 6)
            int Prof = rand() % 6 + 1; // lancer de dé du joueur (nombre aléatoire entre 1 et 6)

            cout << "Yassine a obtenu : " << Yassine << endl;
            cout << "Le prof a obtenu : " << Prof << endl;

            //lecture du résultats
            if (Yassine > Prof) {
                cout << "Yassine gagne et donc il mérite des points bonus!" << endl;
            } else if (Prof > Yassine) {
                cout << "Le prof gagne !" << endl;
            } else {
                cout << "Égalité Vous avez de la chance!" << endl;
            }
            cout << "Exercice 2" << endl;
        }
        // si l'exercice 3 est choisi alors nous devrions rentré les chiffres souhaité
        if (choix == 3) {

            // attribution d'une liste de numéro qui sera des booléens car ca sera uniquement une listes de chiffres et nombre pas de lettre
            int tableau[10];
            bool croissant = true;
            bool decroissant = true;

            // on lit les éléments du tableau
            for (int v = 0; v < 10; v++) {
                cout << "Le numéro " << v + 1 << " du tableau est : ";
                cin >> tableau[v];
            }
            // classement par ordre des éléments
            for (int v = 1; v < 10;
                 v++) {
                if (tableau[v] < tableau[v - 1]) {
                    croissant = false;
                }
                if (tableau[v] > tableau[v - 1]) {
                    decroissant = false;
                }

                // Lire le résultat des éléments du tableau
                //si croissant alors afficher
                if (croissant) {
                    cout << "OH il est en dans l'ordre croissant" << endl;
                }
                //si décroissant alors afficher
                if (decroissant) {
                    cout << "OH c'est dans l'ordre décroissant." << endl;
                }
                    //si ni croissant ni décroissant alors afficher
                else {
                    cout << "Le tableau n'est pas trié ou à 2 fois la même valeur " << endl;
                }

                cout << "Exercice 3" << endl;
            }

        }

        return 0;
    }
}