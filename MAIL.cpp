#include <iostream>
#include <cstdlib>
#include <ctime>

int sommeChiffres(int nombre) {
    int somme = 0;

    while (nombre != 0) {
        somme += nombre % 10;
        nombre /= 10;
    }

    return somme;
}

void determineTriTableau(int tab[], int taille) {
    bool trie;
    int temp;

    do {
        trie = true;

        for (int i = 0; i < taille - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                trie = false;
            }
        }
    } while (!trie);

    std::cout << "Le tableau trié est : ";
    for (int i = 0; i < taille; i++) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int choix = -1;
    int i, count;
    int joueur, ordinateur; // Déclaration des variables ici

    std::srand(std::time(nullptr)); // Initialisation du générateur de nombres aléatoires

    while (choix != 0) {
        std::cout << "0- Sortie\n"
                  << "1- Exercice 1\n"
                  << "2- Exercice 2\n"
                  << "3- Exercice 3\n"
                  << "4- Note\n"
                  << "Votre choix : ";
        std::cin >> choix;

        switch (choix) {
            case 0:
                std::cout << "Au revoir !" << std::endl;
                break;

            case 1:
                int n;
                std::cout << "Entrez le nombre de nombres premiers à afficher : ";
                std::cin >> n;

                i = 2;
                count = 0;

                while (count < n) {
                    bool isPrime = true;

                    for (int j = 2; j <= i / 2; j++) {
                        if (i % j == 0) {
                            isPrime = false;
                            break;
                        }
                    }

                    if (isPrime) {
                        std::cout << i << " ";
                        count++;
                    }

                    i++;
                }
                std::cout << std::endl;
                break;

            case 2:
                // Exercice 2 : Jeu de dé en 1 tour
                std::srand(std::time(nullptr)); // Initialisation du générateur de nombres aléatoires
                int joueur = std::rand() % 6 + 1; // Tirage aléatoire pour le joueur
                int ordinateur = std::rand() % 6 + 1; // Tirage aléatoire pour l'ordinateur
                std::cout << "Le joueur a lancé un dé : " << joueur << std::endl;
                std::cout << "L'ordinateur a lancé un dé : " << ordinateur << std::endl;
                if (joueur > ordinateur) {
                    std::cout << "Le joueur a gagné !" << std::endl;
                } else if (joueur < ordinateur) {
                    std::cout << "L'ordinateur a gagné !" << std::endl;
                } else {
                    std::cout << "Egalité !" << std::endl;
                }
                break;

            case 3:
                int tab[10];

                for (int i = 0; i < 10; i++) {
                    std::cout << "Entrer la valeur pour tab[" << i << "] : ";
                    std::cin >> tab[i];
                }

                determineTriTableau(tab, 10);

                break;

            default:
                std::cout << "Choix invalide !" << std::endl;
                break;
        }
    }

    return 0;
}