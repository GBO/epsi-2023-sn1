#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Déclaration des fonctions avant leur utilisation
void exercice0();
void exercice1();
void exercice2();
void exercice3();

bool estPremier(int nombre);

int main() {
    exercice0();
    int choix;

    // Affichage du menu
    cout << "MENU" << endl;
    cout << "0. exercice 0" << endl;
    cout << "1. exercice 1" << endl;
    cout << "2. exercice 2" << endl;
    cout << "3. exercice 3" << endl;

    // Demande à l'utilisateur de saisir son choix
    cout << "Veuillez saisir le numero de l'exercice souhaite : ";
    cin >> choix;

    // Traitement du choix de l'utilisateur
    switch (choix) {
        case 0:
            cout << "Vous avez choisi l'exercice 0." << endl;
            exercice0(); // appel de la fonction exercice0
            break;
        case 1:
            cout << "Vous avez choisi l'exercice 1." << endl;
            exercice1(); // appel de la fonction exo
            break;
        case 2:
            cout << "Vous avez choisi l'exercice 2." << endl;
            exercice2(); // appel de la fonction exos
            break;
        case 3:
            cout << "Vous avez choisi l'exercice 3." << endl;
            exercice3(); // appel de la fonction exos
            break;
        default:
            cout << "Choix invalide." << endl;
            break;
    }

    return 0;
}

void exercice0() {
    cout << "Exercice 0" << endl;
    // Ici une résolution du problème posé par l'exercice 1
}

void exercice1() {

    exercice1;
    int n;
    cout << "Combien de nombres premiers souhaitez-vous afficher ? ";
    cin >> n;
    int compteur = 0;
    int nombre = 2;
    while (compteur < n) {
        if (estPremier(nombre)) {
            cout << nombre << " ";
            compteur++;
        }
        nombre++;
    }
    cout << endl;
}

bool estPremier(int nombre) {
        if (nombre <= 1) {
            return false;
        }
        for (int i = 2; i*i <= nombre; i++) {
            if (nombre % i == 0) {
                return false;
            }
        }
        return true;
}

void exercice2() {
    exercice2;
    // Initialisation de la génération de nombres aléatoires
    srand(time(NULL));

    // Lancement du dé pour le joueur
    int joueur = rand() % 6 + 1;
    cout << "Le joueur a lance le de et a obtenu : " << joueur << endl;

    // Lancement du dé pour l'ordinateur
    int ordinateur = rand() % 6 + 1;
    cout << "L'ordinateur a lance le de et a obtenu : " << ordinateur << endl;

    // Comparaison des résultats
    if (joueur > ordinateur) {
        cout << "Le joueur a gagne !" << endl;
    } else if (joueur < ordinateur) {
        cout << "L'ordinateur a gagne !" << endl;
    } else {
        cout << "Egalite !" << endl;
    }
}

void exercice3(){
    int tableau[10];
    for (int i = 0; i < 9; i++) {
        cout << "Saisissez un nombre : "; cin >> tableau[i];
    }
    // Indicateur d'ordre
    string ordre = "quelconque";
    // Vérification de l'ordre croissant
    bool estCroissant = true;
    for (int i = 0; i < 9; i++) {
        if (tableau[i] > tableau[i+1]) {
            estCroissant = false;
            break;
        }
    }
    // Vérification de l'ordre décroissant
    bool estDecroissant = true;
    for (int i = 0; i < 9; i++) {
        if (tableau[i] < tableau[i+1]) {
            estDecroissant = false;
            break;
        }
    }
    // Vérification de l'ordre constant
    bool estConstant = true;
    for (int i = 0; i < 9; i++) {
        if (tableau[i] != tableau[i+1]) {
            estConstant = false;
            break;
        }
    }
    // Détermination de l'ordre global
    if (estCroissant) {
        ordre = "croissant";
    } else if (estDecroissant) {
        ordre = "décroissant";
    } else if (estConstant) {
        ordre = "constant";
    }
    // Affichage de l'ordre global
    cout << "L'ordre du tableau est : " << ordre << endl;
}