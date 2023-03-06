#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
int main() {
    int exercice;

    cout << "Entrez le numéro de l'exercice : ";
    cin >> exercice;

    switch (exercice) {
        case 1:
            ::printf("aller a la ligne 35 et ensuite supprimer les /* au début du code et les /* à la fin du code a la ligne 63");
            break;
        case 2:
            ::printf("aller a la ligne 66 et ensuite supprimer les /* au début du code et les /* à la fin du code a la ligne 95");
            break;
        case 3:
            ::printf("aller a la ligne 96 et ensuite supprimer les /* au début du code et les /* à la fin du code a la ligne 126");
            break;
            // Ajouter des cas pour d'autres exercices si nécessaire
        default:
            cout << "Exercice non trouvé." << endl;
            break;
    }

    return 0;
}
*/

/*
// Fonction qui détermine si un nombre est premier
bool estPremier(int n) {
    if (n <= 1) { // Si le nombre est 1 ou inférieur, il n'est pas premier
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) { // On teste les diviseurs potentiels de 2 à la racine carrée de n
        if (n % i == 0) { // Si n est divisible par i, il n'est pas premier
            return false;
        }
    }
    return true; // Si aucun diviseur n'est trouvé, n est premier
}

int main(int argc,char** argv) {
    cout << "Exercice 1" << endl;

    int n;
    cout << "Entrez un nombre : ";
    cin >> n; // On demande à l'utilisateur d'entrer un nombre
    cout << "Les nombres premiers inférieurs à " << n << " sont : ";
    for (int i = 2; i < n; i++) { // On teste tous les nombres de 2 à n-1
        if (estPremier(i)) { // Si le nombre est premier, on l'affiche
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
*/


/*
int main(int argc,char** argv) {
    cout << "Exercice 2" << endl;

    // Initialisation du générateur de nombres aléatoires
    srand(time(0));

    // Tirage du joueur
    int joueur = rand() % 6 + 1;
    cout << "Le joueur a tiré un " << joueur << endl;

    // Tirage de l'ordinateur
    int ordinateur = rand() % 6 + 1;
    cout << "L'ordinateur a tiré un " << ordinateur << endl;

    // Détermination du vainqueur
    if (joueur > ordinateur) {
        cout << "Le joueur a gagné !" << endl;
    } else if (joueur < ordinateur) {
        cout << "L'ordinateur a gagné !" << endl;
    } else {
        cout << "Egalité !" << endl;
    }

    return 0;
}
*/
/*
int main(int argc,char** argv) {
    cout << "Exercice 3" << endl;
    int tableau[8] = {3, 3, 3, 3, 3,7,7,7};
    bool croissant = true, decroissant = true, constant = true;

    for (int i = 0; i < 4; i++) {
        if (tableau[i] > tableau[i+1]) {
            croissant = false;
        }
        if (tableau[i] < tableau[i+1]) {
            decroissant = false;
        }
        if (tableau[i] != tableau[i+1]) {
            constant = false;
        }
    }

    if (croissant) {
        cout << "Le tableau est trie en ordre croissant." << endl;
    } else if (decroissant) {
        cout << "Le tableau est trie en ordre decroissant." << endl;
    } else if (constant) {
        cout << "Toutes les valeurs du tableau sont egales." << endl;
    } else {
        cout << "Le tableau n'est pas trie." << endl;
    }

    return 0;
}
*/







