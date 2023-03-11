#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void exercice0(int num){
    if(num == 0){
        cout << "Sortie" << endl;
    }
}


bool estPremier(int n) { //on determine si un nombre donné est premier ou non
    if (n <= 1) {
        return false;
    }
    for (int i=2; i*i <= n; i++) {
        if (n%i == 0) {
            return false; //on utilise la méthode suivante : si un nombre est divible par un nombre compris entre 2 et sa racine alors il n'est pas premier
        }
    }
    return true;
}

void premiers(int N) { // on teste tout tout les nombre a partir de deux, en les affichant s'ils sont premiers jusqu'a en trouver N.
    int i=2, count=0;
    while (count < N) {
        if (estPremier(i)) {
            cout << i << " ";
            count++;
        }
        i++;
    }
}

int main(int argc, char **argv)
/*{
    cout << "Exercice 0" << endl;

    int num = 1;

        while (num != 0) {
            cout << "Saisisser un numero d'exercice ou O pour sortir : ";
            cin >> num;
            exercice0(num);
            cout << "Exercice " << num << endl;
        }

    return 0;
}

{

    cout << "Exercice 1" << endl;

    int N;

    cout << "Combien de nombres premiers a affichers : ";cin >> N;

    premiers(N);

    return 0;
}


{
    cout << "Exercice 2" << endl;

    srand(time(NULL));

    int alea = rand();

    alea = rand() % 6;
    cout << "lancer du joueur : " << alea << endl;

    alea = rand() % 6;
    cout << "lancer de l'ordinateur " << alea << endl;



    return 0;
}*/

{
    cout << "Exercice3" << endl;


    int tableau[10];
    bool croissant = true;
    bool decroissant = true;
    bool constant = true;

    // saisie des valeurs du tableau
    cout << "Entrez les 10 valeurs du tableau : ";
    for(int i = 0; i < 10; i++) {
    cin >> tableau[i];
    }

    // détection de l'ordre du tableau
    for(int i = 1; i < 10; i++) {
    if(tableau[i] < tableau[i-1]) {
    croissant = false;
    }
    if(tableau[i] > tableau[i-1]) {
    decroissant = false;
    }
    if(tableau[i] != tableau[i-1]) {
    constant = false;
    }
    }

    // affichage du résultat
    if(croissant) {
    cout << "Le tableau est en ordre croissant." << endl;
    }
    else if(decroissant) {
    cout << "Le tableau est en ordre décroissant." << endl;
    }
    else if(constant) {
    cout << "Le tableau est constant." << endl;
    }
    else {
    cout << "Le tableau est dans un ordre quelconque." << endl;
    }

    return 0;
}





