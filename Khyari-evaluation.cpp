#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//piste trouvé sur internet pour la partie nombre premier notamment  le booléen ci-dessous
bool est_premier(int nombre) {
    if (nombre <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(nombre); i++) {
        if (nombre % i == 0) {
            return false;
        }
    }

    return true;
}


int main(int argc, char **argv) {
    cout << "TD Note de Martin KHYARI - 06/03/2023" << endl;


    //echec de l'exercice 1
    //int choix;
    //while (choix != 0) {
        //cout << "choissisez l'exercice" << endl;
        //cout << "1- Exercice 1" << endl;
        //cout << "2- Exercice 2" << endl;
        //cout << "3- Exercice 3" << endl;

        //cout << "Votre choix : ";
        //cin >> choix;

       // switch (choix) {


            //case 1:
                // Code pour l'exercice 1

                int p;

                cout << "Saisir un nombre de nombre premier :" << endl;
                cin >> p;
                int prmr = 0;
                int nbre = 2;
                while (prmr < p) {
                    if (est_premier(nbre)) {
                        cout << nbre << " ";
                        ++prmr;
                    }
                    ++nbre;
                }
// je n'ai pas réussi a corrigé le probleme qui fait que les nombres premiers indiqué sont supérieur a celui entrer par l'utilisateur
                //break;

            //case 2:
                // Code pour l'exercice 2

                srand(time(NULL));
                int n;
                int m;
                n = rand() % 6 + 1; //enleve le 0 dans le lancé de dé
                m = rand() % 6 + 1;
                cout <<endl<< "Le joueur 1 lance le de = " << n << endl;

                cout << "Le joueur 2 lance Le de = " << m << endl;

                if (n > m)
                    cout << "joueur 1 a gagne"<<endl;
                else if (n < m)
                    cout << "joueur 2 a gagne"<<endl;
                else
                    cout << "Egalite"<< endl;
                //break;
            //case 3:
                // Code pour l'exercice 3

                int tableau[10];
                bool crst = true, dcrst = true, cnst = true;
                //booléen permettant de déterminer dans quel ordre sera le tableau

                for (int i = 0; i < 10; i++) {
                    cout << "Saisissez un nombre : ";
                    cin >> tableau[i];
                }

                for (int i = 0; i < 9; i++) {
                    if (tableau[i] > tableau[i + 1]) {
                        crst = false;
                    }
                }
                for (int i = 0; i < 9; i++) {
                    if (tableau[i] < tableau[i + 1]) {
                        dcrst = false;
                    }
                }
                for (int i = 0; i < 9; i++) {
                    if (tableau[i] != tableau[i + 1]) {
                        cnst = false;
                    }
                }
                if (crst) {
                    cout << "Le tableau est trie dans l'ordre croissant" << endl;
                } else if (dcrst) {
                    cout << "Le tableua est trie dans l'ordre decroissant" << endl;
                } else if (cnst) {
                    cout << "toutes les valeurs sont egales" << endl;
                } else {
                    cout << "ordre quelconque" << endl;
                }
                //break;

     //   }
    //}
    return 0;
}
