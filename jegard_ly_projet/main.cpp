#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <time.h>
#pragma once


#include "bataille.h"
#include "morpion.h"

using namespace std;


void jeu_de_carte(){
    Bataille bataille;
    bataille.jouer();

};
void pendu() {
    const int m_essais = 6;


    string mots[] = {"Messi", "Ronaldo", "Neymar", "Mbappe", "Lewandowski", "Haaland", "Pedri", "Salah", "Mane",
                     "Firmino", "Kane", "Son", "Foden", "Sterling", "Grealish", "Gavi", "Ramos", "Varane", "Alaba",
                     "Robertson", "saka"};
    srand(time(NULL));
    string mot = mots[rand() % (sizeof(mots) / sizeof(mots[0]))];
    transform(mot.begin(), mot.end(), mot.begin(), [](unsigned char c) { return std::tolower(c); });

    int nb_essai = 0;
    string lettres_dvne = "";
    string mot_a_deviner(mot.length(), '_');

    const vector<string> images_pendu = {
            "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
            "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };
    cout << "Bienvenue au jeu du pendu! (version Football)" << endl << endl;


    while (nb_essai < m_essais && mot != mot_a_deviner) {
        cout << images_pendu[nb_essai] << endl;
        cout << "Il vous reste " << m_essais - nb_essai << " essais restants." << endl;
        cout << "Lettres devinees: " << lettres_dvne << endl;
        cout << "Mot: " << mot_a_deviner << endl;

        char essai;
        cout << "Deviner une lettre: ";
        cin >> essai;


        if (lettres_dvne.find(essai) != string::npos) {
            cout << "Vous avez deja devine cette lettre." << endl;
        } else {
            lettres_dvne += essai;


            bool found = false;
            for (int i = 0; i < mot.length(); i++) {
                if (mot[i] == essai) {
                    mot_a_deviner[i] = essai;
                    found = true;
                }
            }

            if (found) {
                cout << "Correct!" << endl;
            } else {
                cout << "Incorrect!" << endl;
                nb_essai++;
            }
        }
    }

    if (mot == mot_a_deviner) {
        cout << "Felicitation, vous aves devine le mot! " << mot << "." << endl;
    } else {
        cout << "Desole, vous n'avez plus d'essai. Le mot etait " << mot << "." << endl;
        cout << images_pendu[nb_essai] << endl;
    }
};

int blackjack(){

        srand(time(0)); // Initialise le générateur de nombres aléatoires

        const int MIN = 1;
        const int MAX = 10;
        const int BLACKJACK = 21;

        int joueurCarte1 = rand() % (MAX - MIN + 1) + MIN;
        int joueurCarte2 = rand() % (MAX - MIN + 1) + MIN;
        int croupierCarte1 = rand() % (MAX - MIN + 1) + MIN;
        int croupierCarte2 = rand() % (MAX - MIN + 1) + MIN;

        cout << "Joueur: " << joueurCarte1 << ", " << joueurCarte2 << endl;
        cout << "Croupier: " << croupierCarte1 << endl;

        int joueurTotal = joueurCarte1 + joueurCarte2;
        int croupierTotal = croupierCarte1 + croupierCarte2;

        char choix;
        do {
            cout << "Voulez-vous tirer une carte ? (o/n) ";
            cin >> choix;
            if (choix == 'o') {
                int nouvelleCarte = rand() % (MAX - MIN + 1) + MIN;
                cout << "Vous avez tire: " << nouvelleCarte << endl;
                joueurTotal += nouvelleCarte;
                cout << "Total du joueur: " << joueurTotal << endl;
                if (joueurTotal > BLACKJACK) {
                    cout << "Vous avez depasse 21, vous avez perdu!" << endl;
                    return 0;
                }
            }
        } while (choix != 'n');

        // Croupier tire des cartes
        while (croupierTotal < 17) {
            int nouvelleCarte = rand() % (MAX - MIN + 1) + MIN;
            cout << "Le croupier a tire: " << nouvelleCarte << endl;
            croupierTotal += nouvelleCarte;
            cout << "Total du croupier: " << croupierTotal << endl;
            if (croupierTotal > BLACKJACK) {
                cout << "Le croupier a depasse 21, vous avez gagne!" << endl;
                return 0;
            }
        }

        // Détermine le gagnant
        if (joueurTotal > croupierTotal) {
            cout << "Vous avez gagne!" << endl;
        } else if (joueurTotal < croupierTotal) {
            cout << "Vous avez perdu!" << endl;
        } else {
            cout << "Match nul!" << endl;
        }

}

void morpion(){
    startMorpion();
}

int main() {


    int choix = -1;
    while (choix != 0) {
        cout<< "Veuillez choisir le jeu auquel vous voulez jouer";
        cout<< endl;

        cout  << "1- Pendu \n"
              << "2- Bataille\n"
              << "3- Black Jack\n"
              << "4- Morpion\n"
              << "0- Sortie\n"
              << "Entrez votre choix : ";

        cin >> choix;

        cout<< endl;

        switch (choix) {
            case 0:
                cout << "Au revoir !\n";
                break;
            case 1:

                cout << "Vous avez choisi le jeu du pendu.\n";
                pendu();
                break;
            case 2:

                cout << "Vous avez choisi le jeu de cartes.\n";
                jeu_de_carte();
                break;
            case 3:
                // exécuter le jeu 3
                cout << "Vous avez choisi le Black Jack.\n";
                blackjack();
                break;
            case 4:
                // exécuter le jeu 4
                cout << "Vous avez choisi le Morpion.\n";
                morpion();
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
                break;
        }
    }

    return 0;
}