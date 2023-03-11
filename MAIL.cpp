#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Fonction pour afficher le menu et exécuter l'option choisie par l'utilisateur
void menu(){
    int choice = -1;
    while (choice != 0) {
        cout << "0- Sortie" << endl;
        cout << "1- Exercice1" << endl;
        cout << "2- Exercice2" << endl;
        cout << "3- Exercice3" << endl;
        cout << "Entrez votre choix : ";
        cin >> choice;

        }
    }


// Fonction pour afficher les N premiers nombres premiers
void Exercice1(){
    int n;
    cout << "Entrez le nombre de nombres premiers à afficher : ";
    cin >> n;
    if (n <= 0) {
        cout << "Le nombre doit être supérieur à 0." << endl;
        return;
    }
    int i = 2;
    int count = 0;
    while (count < n) {
        bool is_prime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            cout << i << " ";
            count++;
        }
        i++;
    }
    cout << endl;
}

// Fonction pour simuler un tour de jeu de dé
void Exercice2(){
    srand(time(NULL));
    int Joueur = rand() % 6 + 1;
    int Ordinateur = rand() % 6 + 1;

    cout << "Joueur : " << Joueur << endl;
    cout << "Ordinateur : " << Ordinateur<< endl;

    if (Joueur == Ordinateur) {
        cout << "Egalité" << endl;
    } else if (Joueur > Ordinateur) {
        cout << "Le joueur gagne" << endl;
    } else {
        cout << "L'ordinateur gagne" << endl;
    }
}

// Fonction pour déterminer l'ordre d'un tableau de 10 entiers
void Exercice3() {
    int arr[10];
    cout << "Entrez 10 entiers : ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    bool increasing = true;
    bool decreasing = true;
    bool constant = true;
    for (int i = 1; i < 10; i++) {
        if (arr[i] > arr[i-1]) {
            decreasing = false;
            constant = false;
        } else if (arr[i] < arr[i-1]) {
            increasing = false;
            constant = false;
        } else {
            increasing = false;
            decreasing = false;
        }
    }

    if (increasing) {
        cout << "Les entiers sont en ordre croissant" << endl;
    } else if (decreasing) {
        cout << "Les entiers sont en ordre décroissant" << endl;
    } else if (constant) {
        cout << "Tous les entiers sont identiques" << endl;
    } else {
        cout << "Les entiers ne sont pas en ordre" << endl;
    }
}