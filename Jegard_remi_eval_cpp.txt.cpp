Exercice 0 :








Exercice 1 : 


#include <iostream>


// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`

using namespace std;

// fonction qui teste si un nombre est premier ou non
bool estPremier(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        // On utilise le Modulo qui permet de calculer le reste d'une division entière
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cout << "Nombre de nombres premiers à afficher : "; cin >> N;

    cout << "Les " << N << " premiers nombres premiers sont : " << endl;
    int nbPremiers = 0;
    int i = 2;
    while (nbPremiers < N) {
        if (estPremier(i)) {
            cout << i << " ";
            nbPremiers++;
        }
        i++;
    }

    cout << endl;
    return 0;
}





Exercice 2 : 


// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> // pour time()

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`

using namespace std;

int main (int argc, char **argv)
{

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));

    // Génération de nombres aléatoires
    int joueur = rand() % 6 + 1; // Score du joueur
    int ordinateur = rand() % 6 + 1; // Score de l'ordinateur

    cout << "Le score du joueur est : " << joueur << endl;
    cout << "Le score de l'ordinateur est : " << ordinateur << endl;

    if (joueur > ordinateur) {
        cout << "Victoire du joueur" << endl;
    } else if (ordinateur > joueur) {
        cout << "Victoire de l'ordinateur" << endl;
    } else {
        cout << "Match nul" << endl;
    }

    return 0;
}






Exercice 3 : 


#include <iostream>

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`


using namespace std;

int main() {
    int tableau[10] = { 1,2,3,4,5,6,7,8,9,10};
    bool estCroissant = true;
    bool estDecroissant = true;
    bool estConstant = true;

// On teste chaque valeur du tabkeau par rapport à la suivante en utilisant la variable i

    for (int i = 0; i < 9; i++) {
        if (tableau[i] > tableau[i+1]) {
            estCroissant = false;
        }
        if (tableau[i] < tableau[i+1]) {
            estDecroissant = false;
        }
        if (tableau[i] != tableau[i+1]) {
            estConstant = false;
        }
    }

    if (estCroissant) {
        cout << "Le tableau est trié en ordre croissant." << endl;
    } else if (estDecroissant) {
        cout << "Le tableau est trié en ordre décroissant." << endl;
    } else if (estConstant) {
        cout << "Le tableau a toutes les valeurs constantes." << endl;
    } else {
        cout << "Le tableau n'est pas trié." << endl;
    }

    return 0;
}
