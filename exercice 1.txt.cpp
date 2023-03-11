#include <iostream>
using namespace std;

int main(int argc, char **argv) {

    cout << "Exercice 1" << endl;
    int N;
    cout << "Entrez le nombre de nombres premiers a afficher : ";
    cin >> N;

    int i = 2; // commencer à tester les nombres à partir de 2 car 0 et 1 ne sont pas premiers
    int compteur = 0; // compteur de nombres premiers trouvés

    while (compteur < N) { // continuer jusqu'à ce que nous ayons N nombres premiers
        bool est_premier = true; // supposer que i est premier
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) { // si i est divisible par j, il n'est pas premier
                est_premier = false;
                break; // sortir de la boucle for
            }
        }
        if (est_premier) { // si i est premier, l'afficher
            cout << i << " ";
            compteur++; // incrémenter le compteur
        }
        i++; // passer au nombre suivant
    }

    cout << endl;

    return 0;
}
