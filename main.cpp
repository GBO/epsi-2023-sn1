#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> // pour time()
using namespace std;

int main(int argc, char **argv) {
    int exercice = 4;
    cout << "Voici la liste des option: " <<endl;
    cout << "0- Sortie" << endl;
    cout <<"1- Exercice"<< endl;
    cout << "2- Exercice" << endl;
    cout <<"3- Exercice " << endl;

    while (exercice != 0) {
        cout << "Choisie un exercice: " <<endl;
                "0- Sortie\n"
                "1- Exercice 1\n"
                "2- Exercice 2\n"
                "3- Exercice 3\n";
        cin >> exercice;

        if (exercice == 1 ){
            cout << "Exercice 1:";
        }
        if (exercice == 2) {
            cout << "Exercice 2: ";
        // J'initialise  la variable affichage qui contient le nombre de nombre premier a afficher
        // et j'initialise  le tableau nb_premier
        int affichage;
        int nb_premiers[10] {17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
        cout << "Il y a 10 nombres au maximum que vous pouvez selectionez" << endl;
        cout << "Saisissez le nombre de nombre premier que vous voulez: " << endl; cin >> affichage;
        for (int i= 0; i < affichage; i++){
            cout << nb_premiers[i] << endl;
        }

        }

        if (exercice == 3) {
            cout << "Exercice 3 : ";
            // Dabord je vais initialise le générateur avec SRAND qui définit le point de départ pour produire une série d'entiers pseudo-aléatoires.
                 srand(time(NULL));
            // On initialise les variables joueur et ordi qui contiendront les résultats des tirs de dé
            int ordinateur;
            int joueur;

            joueur = rand() %6 + 1;
            ordinateur = rand() %6 + 1;

            cout << "1 Tiré par Le joueur " << joueur << endl;
            cout << "1 Tiré par L'ordinateur " << ordinateur << endl;
            if (joueur > ordinateur){
                cout << "BIEN JOUER!! VOUS AVEZ GAGNER L'ORDI";
            }
            if (ordinateur > joueur){
                cout << "Désoler l'ordi vous a gagner";
            }
            if (joueur == ordinateur) {
                cout << "vous etes en egalité avec l'ordi";
            }

        }

        if (exercice == 4) {
            cout << "Exercice 4 : ";

            //Inicialisation des 10 nombres
            int tableau[10] {1,2,3,4,5,6,7,8,9,10};

            bool decroissant = true;
            bool croissant = true;
            bool constant = true;

            for (int i = 0; i < 10; i++){
                if (tableau[i] > tableau[i+1]){
                    croissant = false;
                }
                if (tableau[i] < tableau[i+1]){
                    decroissant = false;
                }
                if (tableau[i] != tableau[i+1]){
                    constant = false;
                }
            }
            if (decroissant) {
                cout << "Les elements du tableau sont dans l'ordre decroissant";
            }

            // on affiche de quelle manière est trié le tableau
            if (croissant) {
                cout << "Les elements du tableau sont dans l'ordre croissant";
            }

            if (constant) {
                cout << "Les élements sont cronstant";
            }
            else {
                cout << "Desolé les éléments sont ni croissans, ni decroissant, ni constant";
            }

        }
    }






}


