#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

// Déclaration des fonctions
void afficherPlateau(const vector<vector<char>> &plateau) {
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            cout << "| " << plateau[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------" << endl;
}

bool placerJeton(int colonne, char jeton, vector<vector<char>> &plateau) {
    for (int i = 0; i < ROWS; i++) {
        if (plateau[i][colonne] == ' ') {
            plateau[i][colonne] = jeton;
            return true;
        }
    }
    return false;
}

bool aGagne(char jeton, const vector<vector<char>> &plateau) {
    // Vérification des lignes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (plateau[i][j] == jeton && plateau[i][j + 1] == jeton && plateau[i][j + 2] == jeton &&
                plateau[i][j + 3] == jeton) {
                return true;
            }
        }
    }

    // Vérification des colonnes
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (plateau[i][j] == jeton && plateau[i + 1][j] == jeton && plateau[i + 2][j] == jeton &&
                plateau[i + 3][j] == jeton) {
                return true;
            }
        }
    }

    // Vérification des diagonales ascendantes (en partant de la gauche)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (plateau[i][j] == jeton && plateau[i + 1][j + 1] == jeton && plateau[i + 2][j + 2] == jeton &&
                plateau[i + 3][j + 3] == jeton) {
                return true;
            }
        }
    }

    // Vérification des diagonales descendantes (en partant de la gauche)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (plateau[i][j] == jeton && plateau[i - 1][j + 1] == jeton && plateau[i - 2][j + 2] == jeton &&
                plateau[i - 3][j + 3] == jeton) {
                return true;
            }
        }
    }
    return false;
}

void Puissance4() {
    // Initialisation du plateau de jeu
    vector<vector<char>> plateau(ROWS, vector<char>(COLS, ' '));

    // Variables pour le joueur courant et le jeton à placer
    int joueur = 1;
    char jeton = 'X';

    // Boucle principale du jeu
    while (true) {
        afficherPlateau(plateau);

        // Demande au joueur courant de choisir une colonne où placer son jeton
        cout << "Joueur " << joueur
             << ", à vous de jouer ! Dans quelle colonne voulez-vous placer votre jeton ? : ";
        int colonne;
        cin >> colonne;
        colonne --;

        // Vérifie que la colonne choisie est valide et place le jeton
        if (colonne < 0 || colonne >= COLS) {
            cout << "Cette colonne n'existe pas ! Veuillez en choisir une autre." << endl;
            continue;
        } else if (!placerJeton(colonne, jeton, plateau)) {
            cout << "Cette colonne est déjà pleine ! Veuillez en choisir une autre." << endl;
            continue;
        }

        // Vérifie si le joueur courant a gagné
        if (aGagne(jeton, plateau)) {
            afficherPlateau(plateau);
            cout << "Félicitations joueur " << joueur << ", vous avez gagné !!" << endl;
            break;
        }

        // Vérifie si le plateau est plein, dans ce cas il y a match nul
        bool plateauPlein = true;
        for (int i = 0; i < COLS; i++) {
            if (plateau[ROWS - 1][i] == ' ') {
                plateauPlein = false;
                break;
            }
        }
        if (plateauPlein) {
            afficherPlateau(plateau);
            cout << "Match nul !" << endl;
            break;
        }

        // Change de joueur et de jeton pour le prochain tour
        joueur = joueur == 1 ? 2 : 1;
        jeton = jeton == 'X' ? 'O' : 'X';
    }
}


// Déclaration de la fonction generateCombination
vector<int> generateCombination();

vector<int> comparerCombinaisons(vector<int> guess, vector<int> combination) {
    vector<int> result;
    for (int i = 0; i < 4; i++) {
        if (guess[i] == combination[i]) {
            result.push_back(2);
        } else if (find(combination.begin(), combination.end(), guess[i]) != combination.end()) {
            result.push_back(1);
        } else {
            result.push_back(0);
        }
    }
    return result;
}

// Définition de la fonction generateCombination
vector<int> genererCombinaison() {
    vector<int> combination;
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        combination.push_back(rand() % 6 + 1);
    }
    cout << "Bonne chance" << endl;
    return combination;
}

int Mastermind() {
    vector<int> combinaison;
    int nb_joueurs;
    cout << "Voulez vous jouer seul ou a 2 ?" << endl;
    cin >> nb_joueurs;
    while (true) {
        if (nb_joueurs == 1) {
            combinaison = genererCombinaison();
            break;
        } else if (nb_joueurs == 2) {
            cout << "Entrer une combinaison de 4 chiffres de 1 a 6 separes par des espaces a faire deviner" << endl;
            for (int i = 0; i < 4; i++) {
                int couleur;
                cin >> couleur;
                combinaison.push_back(couleur);
            }
            break;
        } else {
            cout << "Erreur : Entrer un nombre de joueur de 1 ou de 2";
        }
    }
    cout << endl << endl << endl << endl << endl;
    int essais = 0;
    while (essais < 10) { // Le joueur a 10 essais pour trouver la combinaison
        vector<int> combinaison_devine;
        cout << "Entrez une combinaison de 4 chiffres de 1 a 6 separes par des espaces: ";
        for (int i = 0; i < 4; i++) {
            int couleur;
            cin >> couleur;
            combinaison_devine.push_back(couleur);
        }
        vector<int> result = comparerCombinaisons(combinaison_devine, combinaison);
        cout << "Resultat: ";
        for (int i = 0; i < result.size(); i++) {
            if (result[i] == 0) {
                cout << "X";
            } else if (result[i] == 1) {
                cout << "I";
            } else {
                cout << "O";
            }
        }
        cout << endl;
        if (result == vector<int>(4, 2)) { // Le joueur a trouvé la combinaison
            cout << "Felicitations, vous avez trouve la combinaison ! La combinaison etait en effet : ";
            for (int i = 0; i < combinaison.size(); i++) {
                cout << combinaison[i] << " ";
            }
            cout << endl;
            return 0;
        }
        essais++;
    }
    cout << "Desole, vous n'avez pas trouve la combinaison. La combinaison etait : ";
    for (int i = 0; i < combinaison.size(); i++) {
        cout << combinaison[i] << " ";
    }
    cout << endl;
    return 0;
}

void jeuPendu(){
    const int essais_max = 6; // maximum d'essais autorisés

    string mot;
    cout << "Entrer un mot a faire devine : " << endl; cin >> mot;
    transform(mot.begin(), mot.end(), mot.begin(),[](unsigned char c){ return std::tolower(c); });

    int nb_essai = 0; // nombre d'essais effectués par le joueur
    string lettres_devinees = ""; // lettres que le joueur a devinées
    string motdevine(mot.length(), '_'); // initialiser le mot deviné jusqu'à présent avec des traits de soulignement

    cout << "Bienvenue au jeu du pendu!" << endl << endl;

    // boucle jusqu'à ce que le joueur ait fait trop d'essais ou ait deviné le mot correctement
    while (nb_essai < essais_max && mot != motdevine) {
        cout << "Il vous reste " << essais_max - nb_essai << " essais." << endl;
        cout << "Lettres devinees: " << lettres_devinees << endl;
        cout << "Mot: " << motdevine << endl;

        char essai;
        cout << "Deviner une lettre: ";
        cin >> essai;

        // vérifier si le joueur a déjà deviné cette lettre
        if (lettres_devinees.find(essai) != string::npos) {
            cout << "Vous avez deja devine cette lettre." << endl;
        } else {
            lettres_devinees += essai;

            // vérifier si la supposition est dans le mot
            bool found = false;
            for (int i = 0; i < mot.length(); i++) {
                if (mot[i] == essai) {
                    motdevine[i] = essai;
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

    if (mot == motdevine) {
        cout << "Felicitation, vous aves devine le mot! Le mot était : " << mot << "." << endl;
    } else {
        cout << "Desole, vous n'avez plus d'essai. Le mot etait " << mot << "." << endl;
    }

}

// Définition de la classe Carte
class Carte {
private:
    string valeur;
    string couleur;
    int puissance;

public:
    // Constructeur de la classe Carte
    Carte(string v, string c, int p) : valeur(v), couleur(c), puissance(p) {}

    // Méthode pour afficher les informations de la carte
    void afficher() const {
        cout << valeur << " de " << couleur << " (" << puissance << ")" << endl;
    }

    int getPuissanceCarte() const{
        return puissance;
    }
};

// Définition de la classe Pioche
class Pioche {
private:
    vector<Carte> cartes;

public:
    // Constructeur de la classe Pioche
    Pioche() {
        // Définition des couleurs, valeurs et puissances des cartes
        string couleurs[] = {"Pique", "Coeur", "Carreau", "Trefle"};
        string valeurs[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi", "As"};
        int puissances[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

        // Boucle pour créer toutes les cartes et les ajouter à la pioche
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                Carte carte(valeurs[j], couleurs[i], puissances[j]);
                cartes.push_back(carte);
            }
        }
        // Mélanger les cartes dans la pioche
        melanger();
    }

    // Méthode pour mélanger les cartes dans la pioche
    void melanger() {
        srand(time(NULL)); // initialiser le générateur de nombres aléatoires avec le temps actuel
        random_shuffle(cartes.begin(), cartes.end()); // mélanger les cartes dans la pioche
    }

    // Méthode pour afficher toutes les cartes de la pioche
    void afficher_pioche() const {
        for (int i = 0; i < cartes.size(); i++) {
            cartes[i].afficher();
        }
    }

    bool estVide() const {
        return cartes.empty();
    }

    Carte piocher() {
        Carte carte = cartes.back();
        cartes.pop_back();
        return carte;
    }
};



class Joueur {
private:
    string nom;
    vector<Carte> cartes;

public:
    Joueur(string n) : nom(n) {}

    string getNom() const {
        return nom;
    }

    int getNbCarte(){
        return cartes.size();
    }

    void piocher(Pioche& pioche) {
        Carte carte = pioche.piocher();
        cartes.push_back(carte);
        /*cout << nom << " pioche : ";
        carte.afficher();                           pour voir qui pioche quoi */
    }

    Carte poserCarte() {
        Carte carte = cartes[0];
        cartes.erase(cartes.begin());
        return carte;
    }



    void recupererTas(vector<Carte>& Tas) {
        for (int i = 0; i < Tas.size(); i++) {
            cartes.push_back(Tas[i]);
        }
    }

    void afficher_cartes_main() const {
        cout << nom << " a les cartes suivantes :" << endl;
        for (int i = 0; i < cartes.size(); i++) {
            cartes[i].afficher();
        }
    }
    void afficher_nb_carte_main() const{
        cout << nom << " a " << cartes.size() << " cartes en main" << endl;
    }

    bool paquetvide() const {
        return cartes.empty();
    }
    bool une_carte_paquet() const {
        return cartes.size()==1;
    }

    void melanger_son_paquet() {
        srand(time(NULL)); // initialiser le générateur de nombres aléatoires avec le temps actuel
        random_shuffle(cartes.begin(), cartes.end()); // mélanger les cartes dans la pioche
    }


};




class Partie {
private:
    vector<Joueur*> joueurs;
    vector<Joueur*> joueursPerdants;
    vector<Carte> tas;

public:
    Partie() {}

    void recruter(Joueur* joueur){
        joueurs.push_back(joueur);
    }

    void initialiser(){

        // creer la pioche (carte + melanger)
        Pioche pioche;

        // Distribuer les cartes aux joueurs
        while (!pioche.estVide()) {
            for (int i = 0; i < this->joueurs.size(); i++) {
                if (pioche.estVide()) {
                    break;
                }
                joueurs[i]->piocher(pioche);
            }
        }

        //Afficher le nombres de cartes de chaque joueur
        this->afficher_nb_carte_tt_joueurs();
    }

    void lancer_une_partie_bataille(){
        while (!fin_de_partie()){
            cout << "----------------------------------------------------------"<< endl;
            this->tour_suivant();
            this->tour();
            this->verif_carte_fin_manche();
        }
        cout << "choisir un autre jeu :"<<endl;
    };


    //Afficher le nombres de cartes de chaque joueur
    void afficher_nb_carte_tt_joueurs(){
        for (int i = 0; i < this->joueurs.size(); i++) {
            joueurs[i]->afficher_nb_carte_main();
        }
    };

    void tour() {
        vector<Joueur*> vainqueur_id;
        int vainqueur_valeur = 0;
        for (int i = 0; i < this->joueurs.size(); i++) {

            Carte carte = this->joueurs[i]->poserCarte();
            tas.push_back(carte);
            cout << joueurs[i]->getNom() << " a posé la carte suivante : ";
            tas.back().afficher();


            //enregistrement du/des gagnant(s)
            if (vainqueur_valeur == carte.getPuissanceCarte()){
                vainqueur_id.push_back(this->joueurs[i]);
                vainqueur_valeur = carte.getPuissanceCarte();
            } else if (vainqueur_valeur < carte.getPuissanceCarte()){
                vainqueur_id.clear();
                vainqueur_id.push_back(this->joueurs[i]);
                vainqueur_valeur = carte.getPuissanceCarte();
            }
        }

        if (vainqueur_id.size() != 1){
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   il y a bataille    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

            this->verif_carte_pour_bataille(vainqueur_id);

            tour_suivant();

            bataille(vainqueur_id);
        } else {
            cout << vainqueur_id[0]->getNom() << " gagne la manche. Il prend les " << tas.size() << " cartes du tas" << endl;

            this->vide_tas(vainqueur_id);

        }
    }

    void bataille(vector<Joueur*>& Exvainqueur_id){
        int vainqueur_valeur = 0;
        vector<Joueur*> vainqueur_id;
        for (int i = 0; i < Exvainqueur_id.size(); i++) {

            //Poser une carte retourner
            Carte carte_cachee = Exvainqueur_id[i]->poserCarte();
            tas.push_back(carte_cachee);
            cout << Exvainqueur_id[i]->getNom() << " a posé une carte retournée" << endl;

            //Poser la carte qui gagne la bataille
            Carte carte = Exvainqueur_id[i]->poserCarte();
            tas.push_back(carte);
            cout << Exvainqueur_id[i]->getNom() << " a posé la carte suivante : ";
            tas.back().afficher();



            //enregistrement du/des gagnant(s) de la manche
            if (vainqueur_valeur == carte.getPuissanceCarte()){
                vainqueur_id.push_back(Exvainqueur_id[i]);

            } else if (vainqueur_valeur < carte.getPuissanceCarte()){
                vainqueur_id.clear();
                vainqueur_id.push_back(Exvainqueur_id[i]);
                vainqueur_valeur = carte.getPuissanceCarte();
            }
        }

        if (vainqueur_id.size() != 1){
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   il y a encore bataille    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

            this->verif_carte_pour_bataille(vainqueur_id);

            this->tour_suivant();
            this->bataille(vainqueur_id);


        } else {
            cout << vainqueur_id[0]->getNom() << " gagne la bataille. Il prend les " << tas.size() << " cartes du tas" << endl; // annonce du vainqueur de la bataille

            this->vide_tas(vainqueur_id);
        }
    }

    //donne le tas de carte au vainqueur de la manche et relance une manche
    void vide_tas(vector<Joueur*>& vainqueur_id){
        vainqueur_id[0]->recupererTas(tas);
        tas.clear();

        //Afficher le nombres de cartes de chaque joueur
        this->afficher_nb_carte_tt_joueurs();
    }

    void verif_carte_pour_bataille(vector<Joueur*>& joueur_bataille){
        for (int i = 0; i < joueur_bataille.size(); ++i) {
            if (joueur_bataille[i]->paquetvide()) {
                cout << joueur_bataille[i]->getNom() << " a 0 carte, il a besoin de deux cartes." << endl;

                Joueur* meilleurjoueur = joueurs[0];
                for (int p = 1; p < this->joueurs.size(); p++) {
                    if (meilleurjoueur->getNbCarte() < joueurs[p]->getNbCarte()){
                        meilleurjoueur = joueurs[p];
                    }
                }

                cout << meilleurjoueur->getNom() << " a le plus de cartes, il melange son paquet et laisse " << joueur_bataille[i]->getNom() << " lui prendre deux cartes" << endl;

                meilleurjoueur->melanger_son_paquet();

                vector<Carte> carteDonne;

                for (int j = 0; j < 2; ++j) {
                    carteDonne.push_back(meilleurjoueur->poserCarte());
                    joueur_bataille[i]->recupererTas(carteDonne);
                    carteDonne.clear();
                }

            } else if(joueur_bataille[i]->une_carte_paquet()){
                cout << joueur_bataille[i]->getNom() << " a besoin d'une 2eme cartes" << endl;
                Joueur* meilleurjoueur = joueurs[0];
                for (int p = 1; p < this->joueurs.size(); p++) {
                    if (meilleurjoueur->getNbCarte() < joueurs[p]->getNbCarte()){
                        meilleurjoueur = joueurs[p];
                    }
                }

                cout << meilleurjoueur->getNom() << " a le plus de cartes, il melange son paquet et laisse " << joueur_bataille[i]->getNom() << " lui prendre 1 cartes" << endl;

                meilleurjoueur->melanger_son_paquet();

                vector<Carte> carteDonne;


                carteDonne.push_back(meilleurjoueur->poserCarte());
                joueur_bataille[i]->recupererTas(carteDonne);



            };
        }
    }

    void verif_carte_fin_manche(){
        for (int i = 0; i < joueurs.size(); ++i) {
            if (joueurs[i]->paquetvide()) {
                cout << joueurs[i]->getNom() << " a 0 carte, il est disqualifié" << endl;
                this->joueursPerdants.push_back(joueurs[i]);
                this->joueurs.erase(joueurs.begin()+i);
            }
        }/*
        cout << "-------------voici les joueurs perdants :" << endl;
        for (int p = 0; p < joueursPerdants.size(); ++p) {
            cout << "Le " << p+1 << " perdant est : " << joueursPerdants[p]->getNom() << endl;
        }
        cout << "--------------------------------------------------" << endl;*/
    }

    bool fin_de_partie(){
        if (joueurs.size() == 1) {
            cout << joueurs[0]->getNom() << " gagne la partie !!!!!!!!" << endl;
            this->joueursPerdants.push_back(joueurs[0]);
            this->joueurs.erase(joueurs.begin());
        }
        return joueurs.size() <= 1;
    }

    void tour_suivant(){
        int validation_tour;
        cout << "Taper 1 pour continuer et 0 pour stopper le jeu : ";
        cin >> validation_tour;
        if (validation_tour == 0){
            cout << "ok salut :(";
            exit(0);
        }
    }

    void afficher_le_tas(){
        cout << "voici les cartes sur la table :" << endl;
        for (int p = 0; p < tas.size(); ++p) {
            tas[p].afficher();
        }
    }
};

void Bataille(){
    // Demander le nombre de joueurs
    int nbJoueurs;
    cout << "Combien de joueurs ? ";
    cin >> nbJoueurs;

    // Demander le nom de chaque joueur
    Partie* partie = new Partie();
    for (int i = 1; i <= nbJoueurs; i++) {
        string nomJoueur;
        cout << "Nom du joueur " << i << " : ";
        cin >> nomJoueur;
        Joueur* joueur = new Joueur(nomJoueur);
        partie->recruter(joueur);
    }

    // Distribuer les cartes aux joueurs
    partie->initialiser();
    partie->lancer_une_partie_bataille();

    /*Afficher les cartes de chaque joueur
    for (int i = 0; i < nbJoueurs; i++) {
        joueurs[i].afficher_cartes_main();
    }*/

}


int boucleWhile() {
    while (true) {
        cout << "\nMenu :\n";
        cout << "0 - Sortie\n";
        cout << "1 - Puissance 4\n";
        cout << "2 - Master Mind\n";
        cout << "3 - Le pendu\n";
        cout << "4 - Jeux de carte\n\n";

        cout << "A quel jeu voulez-vous jouer ? : ";

        // Le choix fait devra être un entier
        int choix;
        cin >> choix;

        // Si c'est 0, on casse le programme, c'est-à-dire le programme s'arrête
        if (choix == 0) {
            cout << "C'est dommage ! Vous nous quittez déjà ! J'espère vous revoir très vite..." << endl;
            break;
        }

        // Jeu 1 est choisi
        if (choix == 1) {
            cout << "Vous avez choisi le jeu Puissance 4 ! Bonne chance !" << endl;
            Puissance4();
            cout << "Que faites vous ensuite ?" << endl;
            boucleWhile();
        }

        // Jeu 2 est choisi
        if (choix == 2) {
            cout << "Bienvenue au jeu du MasterMind!" << endl << endl;
            Mastermind();
            cout << "Que faites vous ensuite ?" << endl;
            boucleWhile();
        }


        // jeux 3 est choisi
        if (choix == 3) {
            cout << "Bienvenue au jeu du pendu!" << endl << endl;
            jeuPendu();
            cout << "Que faites vous ensuite ?" << endl;
            boucleWhile();
        }

        if (choix == 4) {
            cout << "Bienvenue au jeu de la bataille!" << endl << endl;
            Bataille();
            cout << "Que faites vous ensuite ?" << endl;
            boucleWhile();
        }

        return 0;
    }

}

// Fonction principale
int main(int argc, char **argv) {
    boucleWhile();
}