#include "bataille.h"
using namespace std;


Bataille::Bataille() {

}

Bataille::~Bataille() {
    while (!this->main_joueur1.empty()) {
        this->main_joueur1.pop();
    }
    while (!this->main_joueur2.empty()) {
        this->main_joueur2.pop();
    }

    /*
      this->deck sera supprimé automatiquement lorsque l'objet this (war) sortira de portée.
    (Son destructeur sera appelé)
*/
}

void Bataille::jouer() {
    cout << "Bienvenue dans la bataille! " << endl;

    suspense("Le jeu commence.", DEFAULT_WAIT_TIME, NO_WHITESPACE);

    game_loop();
}

/* ========== PRIVATE METHODS =========== */

bool Bataille::verifier_gagnant() {
    return false;
}

void Bataille::distrubuer_main() {
    suspense("Distribution des cartes", DEFAULT_WAIT_TIME, NO_WHITESPACE);
    cout << endl;

    while(!this->paquet.est_vide()) {
        // On distribue les cartes
        this->main_joueur1.push(this->paquet.egalite());
        this->main_joueur2.push(this->paquet.egalite());

    }

}

void Bataille::game_loop() {
    suspense("Melange des cartes", DEFAULT_WAIT_TIME, SMALL_WHITESPACE);
    this->paquet.melanger();
    distrubuer_main();

    bool quit = false;
    while (!quit) {

        // On affiche le nombre de cartes dont dispose chaque joueur
        sleep(SLEEP_TIME); // Petit effet pour ajouter un suspense
        cout << "Le joueur 1 a : " << this->main_joueur1.size() << " cartes." << endl;
        sleep(SLEEP_TIME);
        cout << "Le joueur 2 a : " << this->main_joueur2.size() << " cartes." << endl;
        sleep(SLEEP_TIME);
        cout << endl;

        // verifier si qlq a gagner
        if (main_joueur1.empty()) {
            cout << endl << "Le joueur 2 gagne la manche !" << endl;
            return;
        }
        else if (main_joueur2.empty()) {
            cout << endl << "Le joueur 1 gagne la manche !" << endl;
            return;
        }

        // jouer les cartes
        this->carte_a_jouer.push(this->main_joueur1.front());
        cout << "Joueur 1 joue : " << this->carte_a_jouer.back()->print() << endl;
        sleep(SLEEP_TIME);

        this->carte_a_jouer.push(this->main_joueur2.front());
        cout << "Joueur 2 joue : " << this->carte_a_jouer.back()->print() << endl;
        sleep(SLEEP_TIME);

        // Comparer les cartes
        int comparison = this->main_joueur1.front()->comparer_valeur(this->main_joueur2.front());

        // Ne pas oublier de retirer les cartes des mains des joueurs par la suite
        this->main_joueur1.pop();
        this->main_joueur2.pop();

        if (comparison == 0) { // Si les cartes sont les mêmes
            bool war = true;
            while (war) {
                cout << endl << "Les cartes sont identiques !" << endl;
                suspense("C'est une bataille !", DEFAULT_WAIT_TIME, NO_WHITESPACE);


                // On s'assure qu'il reste des cartes aux joueurs
                if (main_joueur1.empty() || main_joueur2.empty()) { continue; }

                // On tire les cartes faces cachées
                carte_a_jouer.push(this->main_joueur1.front());
                carte_a_jouer.push(this->main_joueur2.front());
                this->main_joueur1.pop();
                this->main_joueur2.pop();

                cout << "Le joueur 1 pioche une carte et la retourne." << endl;
                sleep(SLEEP_TIME);
                cout << "Le joueur 2 pioche une carte et la retourne." << endl;
                sleep(SLEEP_TIME);
                cout << endl;

                // On s'assure à nouveau qu'il reste des cartes aux joueurs
                if (main_joueur1.empty() || main_joueur2.empty()) { continue; }

                // On tire les cartes et vérifie qu'il n'yait pas à nouveau bataille
                this->carte_a_jouer.push(this->main_joueur1.front());
                cout << "Le joueur 1 joue :" << this->carte_a_jouer.back()->print() << endl;
                sleep(SLEEP_TIME);

                this->carte_a_jouer.push(this->main_joueur2.front());
                cout << "Le joueur 2 joue :" << this->carte_a_jouer.back()->print() << endl;
                sleep(SLEEP_TIME);

                int war_comparison = main_joueur1.front()->comparer_valeur(main_joueur2.front());
                this->main_joueur1.pop();
                this->main_joueur2.pop();

                // Si les cartes ne sont pas pareilles -> Fin de la bataille
                if (war_comparison != 0) {
                    war = false;

                    // On donne les cartes au gagnant
                    if (war_comparison == 1) { donner_cartes(&war_comparison); }
                    else { donner_cartes(&war_comparison); }
                }
            }
        }

        else if (comparison == 1) { donner_cartes(&comparison); }
        else { donner_cartes(&comparison); }

        /* Pris sur Github
         * For DEBUG purposes. If SLEEP_TIME is 0 I want the game to run fast to the end
         */
        if (SLEEP_TIME != 0) {
            // On vérifie que les joueurs ne veuillent pas quitter la partie
            cout << "Souhaitez-vous quitter le jeu ?" << endl;

            cout << "\"Quitter\" pour quitter. Sinon, entrez \"non\" pour continuer.";
            string fin_partie;
            cin >> fin_partie;
            cout << std::endl;

            if (!fin_partie.empty()) {
                // Make the string lowercase
                transform(fin_partie.begin(), fin_partie.end(), fin_partie.begin(), ::tolower);

                if (fin_partie == "quitter" || fin_partie == "q") {
                    quit = true;
                    continue;
                }
            }
        }

    }


    // Afficher le nombre de cartes dont dispose chaque joueur et annoncer le nom du gagnant.
    sleep(SLEEP_TIME);
    cout << "Le joueur 1 possède : " << this->main_joueur1.size() << " cartes." << endl;
    sleep(SLEEP_TIME);
    cout << "Le joueur 2 possède: " << this->main_joueur2.size() << " cartes." << endl;
    sleep(SLEEP_TIME);
    cout << endl;

    if (main_joueur1.size() > main_joueur2.size()) {
        cout << "joueur 1 gagne!" << endl;
    }
    else {
        cout << "joueur 2 gagne!" << endl;
    }
}

void Bataille::donner_cartes(int *gagnant) {
    if (*gagnant == 1) { cout << endl << "joueur 1 "; }
    else { cout << endl << "joueur 2 "; }

    cout << "gagne " << this->carte_a_jouer.size() << " cartes!" << endl << endl;

    while (!this->carte_a_jouer.empty()) {
        if (*gagnant == 1) { // Player 1 won
            this->main_joueur1.push(this->carte_a_jouer.front());
        }
        else if (*gagnant == -1) { // Player 2 won
            this->main_joueur2.push(this->carte_a_jouer.front());
        }

        this->carte_a_jouer.pop();
    }
}

void Bataille::suspense(string msg, int temps_attente, int vert_whitespace) {
    for (int i = 0; i < vert_whitespace; i++) { cout << endl; }

    cout << msg;

    for (int i = 0; i < temps_attente; i++) {
        cout << ".";
        cout.flush();
        sleep(SLEEP_TIME);
    }
    cout << endl;

    for (int i = 0; i < vert_whitespace; i++) { cout << endl; }
}