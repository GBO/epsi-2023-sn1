#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> 

using namespace std;

//exercice 1
// je créé une fonction qui permet de savoir si un nombre est premier ou non
bool estPremier(int nombre){
    if (nombre <= 1) {
        return false;
    }
    for (int i = 2; i <= nombre / 2; i++) {
        if (nombre % i == 0) {
            return false;
        }
    }
    return true;
}
int nb_premier() {
    int n;
    cout << "Entrez un nombre de nombres premiers à afficher : ";
    cin >> n;
    int nombre = 2;
    int nombresPremiers = 0;
    while (nombresPremiers < n) {
        if (estPremier(nombre)) {
            cout << nombre << " ";
            nombresPremiers++;
        }
        nombre++;
    }
    cout << endl;
    return 0;
}

//exercice 2
int jeu_de_dé(){
    srand(time(0));

    // Lancer de dé pour le joueur
    int joueur = rand() % 6 + 1;
    cout << "Le joueur a lancé le dé et a obtenu : " << joueur << endl;

    // Lancer de dé pour l'ordinateur
    int ordinateur = rand() % 6 + 1;
    cout << "L'ordinateur a lancé le dé et a obtenu : " << ordinateur << endl;

    // On détermine le vainqueur
    if (joueur > ordinateur) {
        cout << "Le joueur gagne !" << endl;
    } else if (ordinateur > joueur) {
        cout << "L'ordinateur gagne !" << endl;
    } else {
        cout << "Egalité !" << endl;
    }

    return 0;
}

//exercice 3
int tri() {
    int tab[10];
    bool croissant = true;
    bool decroissant = true;
    bool constant = true;

    cout << "Entrez les 10 éléments du tableau : " << endl;

    //création d'une boucle pour savoir comment est trié le tableau
    for (int i = 0; i < 10; i++) {
        cin >> tab[i];
        if (i > 0) {
            if (tab[i] > tab[i-1]) {
                decroissant = false;
            }
            else if (tab[i] < tab[i-1]) {
                croissant = false;
            }
        }
        if (tab[i] != tab[0]) {
            constant = false;
        }
    }

    //On détermine le tri du tableau en fonction des éléments fournis par l'utilisateur
    if (croissant) {
        cout << "Le tableau est trié par ordre croissant." << endl;
    }
    else if (decroissant) {
        cout << "Le tableau est trié par ordre décroissant." << endl;
    }
    else if (constant) {
        cout << "Le tableau est constant." << endl;
    }
    else {
        cout << "Le tableau n'est pas trié." << endl;
    }

    return 0;
}


int main(int argc, char **argv){
    cout << "TD Noté de Paul SUPIOT - 06/03/2023" << endl;

    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));
    // Génération de nombres aléatoires
    int alea = rand();
    cout << "Nombre aléatoire brut : " << alea << endl;
    alea = rand() % 100;
    cout << "Nombre aléatoire entre 0 (inclu) et 99 (inclu) : " << alea << endl;

    int choix;
    do {
        // Affichage du menu
        cout << endl << "MENU : " << endl;
        cout << "1. Afficher les n premiers nombres premiers" << endl;
        cout << "2. Jeu de dé" << endl;
        cout << "3. Tri d'un tableau" << endl;
        cout << "0. Quitter le programme" << endl;
        // Lecture du choix de l'utilisateur
        cout << "Entrez votre choix : ";
        cin >> choix;
        cout << endl;

        switch (choix) {
            case 1:
                cout << "Exercice 1" << endl;
                nb_premier();
                break;
            case 2:
                cout << "Exercice 2" << endl;
                jeu_de_dé();
                break;
            case 3:
                cout << "Exercice 3" << endl;
                tri();
                break;
            case 0:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
        }
    } while (choix != 0);

    return 0;
}