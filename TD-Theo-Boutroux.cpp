#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fonction pour déterminer si un nombre est premier

bool estPremier(int nb){
    int i = 2;
    while(i < nb) {
        if (nb % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}
void exercice1(){

    int nombrePremier;
    cout << "Combien de nombres premiers voulez-vous ? ";
    cin >> nombrePremier;

    int i=2, compteur = 0;
    while (compteur < nombrePremier) {
        if (estPremier(i)) {
            cout << i << " ";
            compteur++;
        }
        i++;
    }
    cout << endl;

}

void exercice2(){

    srand(time(nullptr));

    int tirageJoueur = rand()% 6+1;
    int tirageOrdi = rand()% 6+1;

    cout << "Votre tirage : " << tirageJoueur << endl;
    cout << "Le tirage de l'ordi : " << tirageOrdi << endl;

    if (tirageJoueur < tirageOrdi){
        cout << "Vous avez gagne !";
    } else if (tirageOrdi == tirageJoueur){
        cout << "Egalite";
    } else {
        cout << "L'ordinateur a gagne";
    }
}

void exercice3(){

    int tableau[10] = {1,2,3,4,5,6,7,8,9,10};
    //int tableau[10] = {10,9,8,7,6,5,4,3,2,1};
    // tableau[10] = {1,1,1,1,1,1,1,1,1,1};
    //int tableau[10] = {1,10,2,9,3,8,4,7,6,5};

    cout << "Le tableau est : [ ";
    for (int i = 0; i < size(tableau); ++i) {
        cout << tableau[i] << ", ";
    }
    cout << "]" << endl;

    int i = 0;
    string result;

    for (int j = 0; j < size(tableau); ++j) {
        if (tableau[i+1] > tableau[i]) {
            result = "Croissant";
        }
        else if (tableau[i+1] < tableau[i]){
            result = "Decroissant";
        }
        else if (tableau[i+1] == tableau[i]){
            result = "Constant";
        }
        else {
            result = "Quelconque";
        }

    }
    cout << result <<endl;
}

void exercice0(){

    cout << "0 - Sortie" << endl;
    cout << "1 - Exercice 1" << endl;
    cout << "2 - Exercice 2" << endl;
    cout << "3 - Exercice 3" << endl;

    int choix;
    cout << "Choisissez votre menu : " << endl;
    cin >> choix;

    if (choix == 0){
        cout << "Fin du programme" << endl;
    }
    else if (choix == 1){
        exercice1();
    }
    else if (choix == 2){
        exercice2();
    }
    else if (choix == 3){
        exercice3();
    }
    else {
        cout << "Nombre invalide" << endl;
        exercice0();
    }
}

int main() {

    exercice0();

}
