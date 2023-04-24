#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

vector<string> listeCouleur = {"Coeur", "Carreau", "Trèfle", "Pique"};
vector<string> listeFigure = {"As", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf", "Dix", "Valet", "Dame", "Roi"};

class Carte {
 private:
    int valeur;
    string figure;
    string couleur;

public :
    Carte(string figure, string couleur){
        this->figure = figure;
        this->couleur = couleur;
        int chercheFigure = distance(listeFigure.begin(),find(listeFigure.begin(), listeFigure.end(),figure));
        if (figure == listeFigure[0]) {
            valeur = 11;
            }
        else if ( chercheFigure >= 9) {
            valeur = 10;
        }
        else {
            valeur = chercheFigure + 1;
        }
        this->valeur = valeur;
    }

    string get_figure() {
        return this->figure;
    }

    string get_couleur() {
        return this->couleur;
    }

    void set_valeur(int nouvelle_valeur) {
        this->valeur = nouvelle_valeur;
    }

    int get_valeur() {
        return this->valeur;
    }

    string cartes[52] = {"+-------+\n"
                         "|A      |\n"
                         "|       |\n"
                         "|   ♥   |\n"
                         "|       |\n"
                         "|      A|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|2      |\n"
                         "|   ♥   |\n"
                         "|       |\n"
                         "|   ♥   |\n"
                         "|     2 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|3      |\n"
                         "|   ♥   |\n"
                         "|   ♥   |\n"
                         "|   ♥   |\n"
                         "|     3 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|4      |\n"
                         "| ♥   ♥ |\n"
                         "|       |\n"
                         "| ♥   ♥ |\n"
                         "|     4 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|5      |\n"
                         "| ♥   ♥ |\n"
                         "|   ♥   |\n"
                         "| ♥   ♥ |\n"
                         "|      5|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|6      |\n"
                         "| ♥   ♥ |\n"
                         "| ♥   ♥ |\n"
                         "| ♥   ♥ |\n"
                         "|     6 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|7♥   ♥ |\n"
                         "|   ♥   |\n"
                         "| ♥   ♥ |\n"
                         "| ♥   ♥ |\n"
                         "|      7|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|8      |\n"
                         "| ♥ ♥ ♥ |\n"
                         "|  ♥ ♥  |\n"
                         "| ♥ ♥ ♥ |\n"
                         "|      8|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|9      |\n"
                         "| ♥ ♥ ♥ |\n"
                         "| ♥ ♥ ♥ |\n"
                         "| ♥ ♥ ♥ |\n"
                         "|      9|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|10 ♥ ♥ |\n"
                         "| ♥ ♥ ♥ |\n"
                         "|  ♥ ♥  |\n"
                         "| ♥ ♥ ♥ |\n"
                         "|     10 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|J♥     |\n"
                         "|       |\n"
                         "|   ♗  |\n"
                         "|       |\n"
                         "|     ♥J|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|Q♥     |\n"
                         "|       |\n"
                         "|   ♔  |\n"
                         "|       |\n"
                         "|     ♥Q|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|K♥     |\n"
                         "|       |\n"
                         "|   ♕   |\n"
                         "|       |\n"
                         "|     ♥K|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|A      |\n"
                         "|       |\n"
                         "|   ♦   |\n"
                         "|       |\n"
                         "|      A|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|2      |\n"
                         "|   ♦   |\n"
                         "|       |\n"
                         "|   ♦   |\n"
                         "|     2 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|3      |\n"
                         "|   ♦   |\n"
                         "|   ♦   |\n"
                         "|   ♦   |\n"
                         "|     3 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|4      |\n"
                         "| ♦   ♦ |\n"
                         "|       |\n"
                         "| ♦   ♦ |\n"
                         "|     4 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|5      |\n"
                         "| ♦   ♦ |\n"
                         "|   ♦   |\n"
                         "| ♦   ♦ |\n"
                         "|      5|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|6      |\n"
                         "| ♦   ♦ |\n"
                         "| ♦   ♦ |\n"
                         "| ♦   ♦ |\n"
                         "|     6 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|7♦   ♦ |\n"
                         "|   ♦   |\n"
                         "| ♦   ♦ |\n"
                         "| ♦   ♦ |\n"
                         "|      7|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|8      |\n"
                         "| ♦ ♦ ♦ |\n"
                         "|  ♦ ♦  |\n"
                         "| ♦ ♦ ♦ |\n"
                         "|      8|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|9      |\n"
                         "| ♦ ♦ ♦ |\n"
                         "| ♦ ♦ ♦ |\n"
                         "| ♦ ♦ ♦ |\n"
                         "|      9|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|10 ♦ ♦ |\n"
                         "| ♦ ♦ ♦ |\n"
                         "|  ♦ ♦  |\n"
                         "| ♦ ♦ ♦ |\n"
                         "|     10 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|J♦     |\n"
                         "|       |\n"
                         "|   ♗  |\n"
                         "|       |\n"
                         "|     ♦J|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|Q♦     |\n"
                         "|       |\n"
                         "|   ♔  |\n"
                         "|       |\n"
                         "|     ♦Q|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|K♦     |\n"
                         "|       |\n"
                         "|   ♕   |\n"
                         "|       |\n"
                         "|     ♦K|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|A      |\n"
                         "|       |\n"
                         "|   ♣   |\n"
                         "|       |\n"
                         "|      A|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|2      |\n"
                         "|   ♣   |\n"
                         "|       |\n"
                         "|   ♣   |\n"
                         "|     2 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|3      |\n"
                         "|   ♣   |\n"
                         "|   ♣   |\n"
                         "|   ♣   |\n"
                         "|     3 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|4      |\n"
                         "| ♣   ♣ |\n"
                         "|       |\n"
                         "| ♣   ♣ |\n"
                         "|     4 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|5      |\n"
                         "| ♣   ♣ |\n"
                         "|   ♣   |\n"
                         "| ♣   ♣ |\n"
                         "|      5|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|6      |\n"
                         "| ♣   ♣ |\n"
                         "| ♣   ♣ |\n"
                         "| ♣   ♣ |\n"
                         "|     6 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|7♣   ♣ |\n"
                         "|   ♣   |\n"
                         "| ♣   ♣ |\n"
                         "| ♣   ♣ |\n"
                         "|      7|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|8      |\n"
                         "| ♣ ♣ ♣ |\n"
                         "|  ♣ ♣  |\n"
                         "| ♣ ♣ ♣ |\n"
                         "|      8|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|9      |\n"
                         "| ♣ ♣ ♣ |\n"
                         "| ♣ ♣ ♣ |\n"
                         "| ♣ ♣ ♣ |\n"
                         "|      9|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|10 ♣ ♣ |\n"
                         "| ♣ ♣ ♣ |\n"
                         "|  ♣ ♣  |\n"
                         "| ♣ ♣ ♣ |\n"
                         "|     10 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|J♣     |\n"
                         "|       |\n"
                         "|   ♗  |\n"
                         "|       |\n"
                         "|     ♣J|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|Q♣     |\n"
                         "|       |\n"
                         "|   ♔  |\n"
                         "|       |\n"
                         "|     ♣Q|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|K♣     |\n"
                         "|       |\n"
                         "|   ♕   |\n"
                         "|       |\n"
                         "|     ♣K|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|A      |\n"
                         "|       |\n"
                         "|   ♠   |\n"
                         "|       |\n"
                         "|      A|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|2      |\n"
                         "|   ♠   |\n"
                         "|       |\n"
                         "|   ♠   |\n"
                         "|     2 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|3      |\n"
                         "|   ♠   |\n"
                         "|   ♠   |\n"
                         "|   ♠   |\n"
                         "|     3 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|4      |\n"
                         "| ♠   ♠ |\n"
                         "|       |\n"
                         "| ♠   ♠ |\n"
                         "|     4 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|5      |\n"
                         "| ♠   ♠ |\n"
                         "|   ♠   |\n"
                         "| ♠   ♠ |\n"
                         "|      5|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|6      |\n"
                         "| ♠   ♠ |\n"
                         "| ♠   ♠ |\n"
                         "| ♠   ♠ |\n"
                         "|     6 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|7♠   ♠ |\n"
                         "|   ♠   |\n"
                         "| ♠   ♠ |\n"
                         "| ♠   ♠ |\n"
                         "|      7|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|8      |\n"
                         "| ♠ ♠ ♠ |\n"
                         "|  ♠ ♠  |\n"
                         "| ♠ ♠ ♠ |\n"
                         "|      8|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|9      |\n"
                         "| ♠ ♠ ♠ |\n"
                         "| ♠ ♠ ♠ |\n"
                         "| ♠ ♠ ♠ |\n"
                         "|      9|\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|10 ♠ ♠ |\n"
                         "| ♠ ♠ ♠ |\n"
                         "|  ♠ ♠  |\n"
                         "| ♠ ♠ ♠ |\n"
                         "|     10 |\n"
                         "+-------+\n",

                         "+-------+\n"
                         "|J♠     |\n"
                         "|       |\n"
                         "|   ♗  |\n"
                         "|       |\n"
                         "|     ♠J|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|Q♠     |\n"
                         "|       |\n"
                         "|   ♔  |\n"
                         "|       |\n"
                         "|     ♠Q|\n"
                         "+------+\n",

                         "+-------+\n"
                         "|K♠     |\n"
                         "|       |\n"
                         "|   ♕   |\n"
                         "|       |\n"
                         "|     ♠K|\n"
                         "+-------+\n"
    };

    void afficher_carte() {
        int index = distance(listeFigure.begin(),find(listeFigure.begin(), listeFigure.end(),figure));
        if (this->couleur == listeCouleur[1]) {
            index += 13;
        }
        else if (this->couleur == listeCouleur[2]) {
            index += 26;
        }
        else if (this->couleur == listeCouleur[3]) {
            index += 39;
        }
        cout << cartes[index] << endl;
    }

};

class PaquetDeCartes {

private:
    vector<Carte> jeu;
    int nbCarte;

public:

    PaquetDeCartes(int nb=52) {
        this->nbCarte = nb;
    }

    void CreerJeu() {
        if (this->nbCarte == 52){
            for (int j = 0; j < 4 ; j++) {
                for (int i = 0; i < 13; ++i) {
                    Carte c = Carte(listeFigure[i], listeCouleur[j]);
                    this->jeu.emplace_back(move(c));
                }
            }
        } else if (this->nbCarte == 0){
            this->jeu;
        }
    }

     vector<Carte> get_jeu() {
        return this->jeu;
    }

    void melanger() {
        random_device rd;
        mt19937 g(rd());
        shuffle(this->jeu.begin(), this->jeu.end(), g);
    }

    void afficherPaquet(){
        cout << this->jeu.size() << endl;
        for (int i = 0; i < this->jeu.size(); ++i) {
            this->jeu[i].afficher_carte();
        }
    }

    void supprimerCarte(){
        this->jeu.erase(this->jeu.begin());
    }
};

class Joueur{
private:
    string nomJoueur;
    vector<Carte> mainDuJoueur;
    int nbCartes;
    int score = 0;

public:
    Joueur(string nom, vector<Carte> mainDuJoueur) {
        this->nomJoueur = nom;
        this->mainDuJoueur = mainDuJoueur;
        this->nbCartes = mainDuJoueur.size();
        for (int q = 0; q < nbCartes; q++) {
            if (score > 21 && mainDuJoueur[q].get_figure() == "As") {
               mainDuJoueur[q].set_valeur(1);
            }
            score += mainDuJoueur[q].get_valeur();
        }
        this->score = score;
    }

    string getNom(){
        return this->nomJoueur;
    }

    vector<Carte> getMainJoueur() {
        return this->mainDuJoueur;
    }

    void afficherMainJoueur() {
        for (int i = 0; i < this->mainDuJoueur.size(); i++) {
            cout << "Carte " << i + 1 << " : " << this->mainDuJoueur[i].get_figure() << " de " << this->mainDuJoueur[i].get_couleur() << endl;
        }
    }

    int getScore() {
        return this-> score;
    }

    int getNbCartes(){
        return this->nbCartes;
    }

    void setNom(string new_name){
        this->nomJoueur = new_name;
    }

    void setMainJoueur(vector<Carte> new_hand){
        this->mainDuJoueur = new_hand;
    }

    void setScore(int toAdd){
        this->score += toAdd;
    }

    void ajouterCarte(Carte new_card){
        this->mainDuJoueur.push_back(new_card);
    }
};

string BlackJack() {

    // Initialisation du prénom des joueurs

    int nbJoueurs;
    string demandePrenom;
    vector<string> prenoms;

    cout << "Combien de joueurs participeront à la la partie ? " << endl;
    cin >> nbJoueurs;
    cout << "Voulez-vous ajouter des prénoms ?" << endl;
    cin >> demandePrenom;
    if (demandePrenom == "oui") {
        for (int i = 0; i < nbJoueurs; ++i) {
            string new_prenom;
            cout << "Qui es-tu, Joueur " << i + 1 << " ?" << endl;
            cin >> new_prenom;
            prenoms.push_back(new_prenom);
        }
    } else {
        cout << "Les joueurs seront définis par des numeros" << endl;
        for (int j = 0; j < nbJoueurs; ++j) {
            string joueur = "Joueur " + to_string(j + 1);
            prenoms.push_back(joueur);
        }
    }

    prenoms.push_back("Croupier");

    // Création du paquet de cartes

    PaquetDeCartes paquet = PaquetDeCartes();
    paquet.CreerJeu();
    paquet.melanger();

    // Ajout des cartes dans la main de chaque joueur
    vector<Joueur> joueurs;
    for (int i = 0; i < nbJoueurs + 1; ++i) {
        vector<Carte> mainJoueur;
        int j = 0;
        while (j < 2) {
            Carte carte = paquet.get_jeu()[j];
            mainJoueur.push_back(carte);
            paquet.supprimerCarte();
            j++;
        }
        Joueur nouveauJoueur = Joueur(prenoms[i], mainJoueur);
        joueurs.push_back(nouveauJoueur);
    }

    // Tour des joueurs

    bool fin = false;
    int nbJoueurstotal = nbJoueurs;

    cout << "Main du croupier : " << endl;
    joueurs[joueurs.size() - 1].getMainJoueur();
    joueurs[joueurs.size() - 1].afficherMainJoueur();
    cout << "Le nombre de points du croupier : " << joueurs[joueurs.size() - 1].getScore() << endl;
    cout << endl;

    while (fin == false) {

        int a = 0;
        for (a; a < nbJoueurs; a++) {

            //Tour d'un joueur
            if (joueurs[a].getNom() != "Croupier"){
                cout << joueurs[a].getNom() << ", c'est à toi !" << endl;
                joueurs[a].afficherMainJoueur();
                cout << "Ton nombre de points actuel : " << joueurs[a].getScore() << endl;

                string ajouterUneCarte;
                cout << "Voulez-vous ajouter une carte dans votre main ? " << endl;
                cin >> ajouterUneCarte;

                if (joueurs[a].getScore() > 21 or ajouterUneCarte == "Non" || ajouterUneCarte == "non") {

                    cout << joueurs[a].getNom() << ", tu as terminé." << "\n Ton score est : " << joueurs[a].getScore() << endl;
                    continue;
                    nbJoueurs -= 1;

                } else if (ajouterUneCarte == "Oui" || ajouterUneCarte == "oui") {
                    Carte carteAAjouter = paquet.get_jeu()[0];
                    joueurs[a].ajouterCarte(carteAAjouter);
                    joueurs[a].setScore(carteAAjouter.get_valeur());
                    paquet.supprimerCarte();

                    cout << "Vous venez d'ajouter la carte suivante dans votre main : " << endl;
                    carteAAjouter.afficher_carte();
                    cout << "Votre score est désormais : " << joueurs[a].getScore() << endl;

                    if (joueurs[a].getScore() > 21){

                        if (joueurs[a].getScore() > 21) {
                            cout << joueurs[a].getNom() << ", tu as perdu :(" << "\n Ton score est : " << joueurs[a].getScore() << endl;

                            // Retirer le joueur de la partie
                            string nom_a_supprimer = joueurs[a].getNom();

                            auto joueur_a_supprimer = std::find_if(joueurs.begin(), joueurs.end(), [nom_a_supprimer](Joueur j) { return j.getNom() == nom_a_supprimer; });

                            if (joueur_a_supprimer != joueurs.end()) {
                                joueurs.erase(joueur_a_supprimer);
                            }

                            a--; // ajuster l'indice car un joueur a été supprimé
                            fin = true; // passer au joueur suivant
                        }

                    }

                } else {
                    cout << "Veuillez répondre par oui ou par non." << endl;
                }
            }

            //Tour du croupier
            if (joueurs[a].getNom() == "Croupier") {
                cout << "C'est au tour du croupier de jouer" << endl;

                // Le croupier tire une carte s'il a moins de 17 points
                if (joueurs[a].getScore() < 17) {
                    cout << "Le croupier va tirer une carte..." << endl;
                    Carte carteAAjouter = paquet.get_jeu()[0];
                    joueurs[a].ajouterCarte(carteAAjouter);
                    paquet.supprimerCarte();

                    cout << "La carte suivante a été ajoutée à la main du croupier : " << endl;
                    carteAAjouter.afficher_carte();
                    joueurs[a].setScore(carteAAjouter.get_valeur());
                    cout << "Sa main est la suivante : " << endl;
                    joueurs[a].afficherMainJoueur();
                    cout << "Son nombre de points est désormais " << joueurs[a].getScore() << endl;

                    if (joueurs[a].getScore() > 21) {
                        cout << "Le croupier a dépassé les 21 points, la partie est terminée" << endl;
                        fin = true;
                    }
                }

                    //S'il a plus de 21 points, la partie s'arrête.
                else if (joueurs[a].getScore() > 21) {
                    cout << "Le croupier a dépassé les 21 points, la partie est terminée" << endl;
                    fin = true;
                }

                    //S'il a entre 17 et 21 points, il termine son tour.
                else {
                    cout << "Le croupier a terminé son tour. \n Il ne tirerera plus de cartes." << endl;
                    // Recherche de l'index du joueur à supprimer
                    int index_joueur_a_supprimer = -1;
                    for (int i = 0; i < joueurs.size(); i++) {
                        if (joueurs[i].getNom() == joueurs[a].getNom()) {
                            index_joueur_a_supprimer = i;
                            break;
                        }
                    }

                    // Suppression du joueur s'il est trouvé
                    if (index_joueur_a_supprimer != -1) {
                        joueurs.erase(joueurs.begin() + index_joueur_a_supprimer);
                    }

                }

            }
        }
        for (int f = 0; f < nbJoueurstotal; f++) {
            vector<string> gagnants;
            for (int i = 0; i < joueurs.size(); ++i) {
                if (joueurs[i].getScore() > joueurs[joueurs.size() - 1].getScore()) {
                    gagnants.push_back(joueurs[f].getNom());
                }
            }
            for (int a = 0; a < gagnants.size(); a++) {
                cout << "BRAVOOOO " << gagnants[a] << " TU AS GAGNÉ !!" << endl;
            }
        }
    }
}



int main() {
    #ifdef WIN32
        SetConsoleOutputCP(65001);
    #endif

    BlackJack();
    
    return 0;
}
