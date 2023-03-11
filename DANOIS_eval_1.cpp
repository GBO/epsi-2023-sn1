#include <iostream>
#include <vector>
#include <cstdlib> // pour rand
#include <ctime> // pour time()

using namespace std;




int main(int argc, char **argv){
    int exercice = 5;

    while (exercice !=0){
        cout << "choisir un exercice (0- Sortie\n"
                "1- Exercice 1\n"
                "2- Exercice 2\n"
                "3- Exercice 3) :" <<endl;
        cin >> exercice;

        if (exercice==1){

            int N;
            int nb_premiers[25] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,47,53,59,61,67,71,73,79,83,89,97 };
            cout << "Combien voulez-vous afficher de nombre premiers ?" << endl; cin >> N;
            for (int i= 0; i < N; i++){
                cout << nb_premiers[i] << endl;
            }

        }

        if (exercice==2){
            cout << "Exercice 2:" << endl;

            srand(time(NULL));
            int joueur = rand(),  ordinateur = rand();
            joueur = rand() % 6 + 1;
            cout << "tirage joueur : " << joueur << endl;

            ordinateur = rand() % 6 + 1;
            cout << "tirage ordinateur : " << ordinateur << endl;

            if (joueur > ordinateur){
                cout << "le joueur a gagné" << endl;
            } else{
                if (joueur < ordinateur){
                    cout << "l'ordinateur a gagné" << endl;
                } else{
                    cout << "égalité" << endl;
                }
            }

            cout << "Fin de l'exercice 2" << endl;


        }

        if (exercice==3){
            cout << "Exercice 3:" << endl;
            int tableau[10] = {1,1,2,2,3,1,5,6,7,7}, z;
            bool egalite = true;


            for (int i = 0; i < 10; ++i) {
                z = i + 1;
                if( tableau[i]!=tableau[z]){
                    egalite = false;
                }
            }

            if(egalite==true){
                cout << "toutes les valeurs sont égales" << endl;
            } else {

                if (tableau[0] < tableau[1] && tableau[1] < tableau[2]) {
                    cout << "l'ordre est croissant" << endl;
                } else {
                    if (tableau[0] > tableau[1] && tableau[1] > tableau[2]) {
                        cout << "l'ordre est décroissant" << endl;
                    } else {
                        cout << "aucun ordre" << endl;
                    }
                }
            }
        }
    }



    return 0;
}