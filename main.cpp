#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Fonction pour vérifier si un nombre est premier (Exercice 1)
bool est_premier(int n) {
    if (n < 2) {  // 0 et 1 ne sont pas premiers
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {  // On teste tous les diviseurs potentiels jusqu'à la racine carrée de n
        if (n % i == 0) {  // Si n est divisible par i, il n'est pas premier
            return false;
        }
    }
    return true;  // Si on n'a pas trouvé de diviseur, n est premier
}

int main() {

    // Exercice 0

    int choix;
    choix = 1;

    while (choix != 0) {
        cout << "Veuillez selectionner un exercice :" << endl
             << "1 - Exercice 1" << endl
             << "2 - Exercice 2" << endl
             << "3 - Exercice 3" << endl
             << "0 - Sortie" << endl;
        cin >> choix;

        int n, c, d, v;
        c = 0;
        d = 1;
        v = 2;

        // Exercice 1

        if (choix == 1) {
            cout << "Exercice 1" << endl;
            int n;
            cout << "Entrez le nombre de nombres premiers a afficher : ";
            cin >> n;  // On demande à l'utilisateur de saisir n
            int count = 0;  // On initialise un compteur de nombres premiers trouvés à 0
            int num = 2;    // On commence la recherche à partir du premier nombre premier connu (2)
            while (count < n) {  // On boucle jusqu'à avoir trouvé n nombres premiers
                if (est_premier(num)) {   // Si le nombre courant est premier
                    cout << num << ", ";  // On l'affiche
                    count++;  // On incrémente le compteur de nombres premiers trouvés
                }
                num++;  // On passe au nombre suivant

                // Exercice 2

                int ordi, joueur;

                srand(time(NULL));           // Initialisation du générateur de nombre aléatoire
                ordi = rand() % 6 + 1;                  // Génère un nombre aléatoire entre 1 et 6
                joueur = rand() % 6 + 1;                // Génère un nombre aléatoire entre 1 et 6

                if (choix == 2) {
                    cout << "Exercice 2" << endl;
                    cout << "De de l'ordinateur :" << ordi << endl;
                    cout << "Votre de :" << joueur << endl;
                    if (joueur > ordi) {
                        cout << "Victoire !" << endl;
                    } else if (ordi == joueur) {
                        cout << "Egalite !" << endl;
                    } else {
                        cout << "Dommage :(" << endl;
                    }
                }
            }

                // Exercice 3

                if (choix == 3) {
                    cout << "Exercice 3" << endl;
                    int tableau[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // Exemple de tableau trié de manière croissante

                    bool estTrieCroissant = true;
                    bool estTrieDecroissant = true;
                    bool estTrieConstant = true;

                    for (int i = 0; i < 9; i++) // Parcours du tableau
                    {
                        if (tableau[i] > tableau[i+1]) // Vérification si le tableau est trié dans l'ordre croissant
                        {
                            estTrieCroissant = false;
                        }
                        else if (tableau[i] < tableau[i+1]) // Vérification si le tableau est trié dans l'ordre décroissant
                        {
                            estTrieDecroissant = false;
                        }

                        if (tableau[i] != tableau[i+1]) // Vérification si toutes les valeurs sont égales
                        {
                            estTrieConstant = false;
                        }
                    }

                    if (estTrieCroissant) // Affichage du résultat
                    {
                        cout << "Le tableau est trié dans l'ordre croissant." << endl;
                    }
                    else if (estTrieDecroissant)
                    {
                        cout << "Le tableau est trié dans l'ordre décroissant." << endl;
                    }
                    else if (estTrieConstant)
                    {
                        cout << "Toutes les valeurs du tableau sont égales." << endl;
                    }
                    else
                    {
                        cout << "Le tableau n'est pas trié." << endl;
                    }
                }
            }
    }
    return 0;
}