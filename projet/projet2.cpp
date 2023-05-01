//Bataille (Chloé)

//on inclus toutes les bibliotheques nécessaires au fonctionnement du jeu
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <random>
#include <chrono>
#include <time.h>
#include <ctime>
using namespace std;

int manche = 1;

//on crée une classe Carte qui va contenir toutes les actions possibles sur les cartes
class Carte {
private:
    int numero_;
    string couleur_;
public:
    Carte(int numero, const string couleur){  //on initialise les cartes grace a ce constructeur
        this->numero_ = numero;
        this->couleur_=couleur;
    }
    //recuperation du numero de la carte
    int get_numero(){
        return this->numero_;
    }

    string get_couleur(){
        return this->couleur_;
    }
    //methode d'affichage du numero et du symbole de la carte
    void afficher(){
        if (numero_ == 14){
            cout << "l'As de " << couleur_ <<endl;
        }else if (numero_ ==11){
            cout << "le valet de " << couleur_ <<endl;
        }else if (numero_ == 12){
            cout << "la dame de " << couleur_ <<endl;
        }else if (numero_ == 13){
            cout << "le roi de " << couleur_ <<endl;
        }else{
            cout << "le "<< numero_ << " de " << couleur_ <<endl;
        }
    }


};

//on crée une classe Joueur qui contient toutes les actions pouvant etre effectués par les joueurs
class Joueur {
private:
    string nom_;
    vector<Carte> main_;  // création d'une liste de carte (paquet du joueur)
public:
    Joueur(string nom_){    //initialisation des joueurs
        this->nom_ = nom_;
    }

    string get_nom(){
        return nom_;
    }

    //methode d'ajout de cartes aux paquets du joueur en cas de victoire
    void ajouter_carte(Carte carte){
        auto it = main_.begin();
        main_.insert(it,carte);
    }

    //verification du nombre de cartes restants aux joueurs
    int taille(){
        return size(this->main_);
    }
    //on verifie si tous les joueurs ont encore des cartes
    bool a_des_cartes()  {
        return !main_.empty();
    }

    //pour jouer une carte, on doit la stocker dans une variable pour la reutiliser puis l'enlever du paquet du joueur
    Carte jouer_carte() {
        Carte carte_jouee = main_.back();
        main_.pop_back();
        return carte_jouee;
    }

};
//verification du gagnant
//on donne toutes les cartes de la pioche au joueur gagnant
void victoire(Joueur& joueur1, Joueur& joueur2, Joueur& pioche, string gagnant){
    if(gagnant == "Joueur1"){
        while(pioche.a_des_cartes()){
            joueur1.ajouter_carte(pioche.jouer_carte());
        }
        cout << joueur1.get_nom() << " remporte la manche" << endl;

    }else if (gagnant == "Joueur2"){
        while(pioche.a_des_cartes()){
            joueur2.ajouter_carte(pioche.jouer_carte());
        }
        cout << joueur2.get_nom() << " remporte la manche" << endl;
    }
    cout <<endl;
}

//les 2 joueurs ont la meme carte :
void bataille(Joueur& joueur1, Joueur& joueur2,  Joueur& pioche,string gagnant) {

    cout << "Bataille ! "<<endl;
    // on prend 1 carte cachée par joueurs:
    Carte carte_cachee_joueur1 = joueur1.jouer_carte();
    Carte carte_cachee_joueur2 = joueur2.jouer_carte();
    //on les ajoute a la pioche
    pioche.ajouter_carte(carte_cachee_joueur1);
    pioche.ajouter_carte(carte_cachee_joueur2);

    cout << joueur1.get_nom() << " cache ";
    carte_cachee_joueur1.afficher();
    cout << joueur2.get_nom() << " cache ";
    carte_cachee_joueur2.afficher();

    // Les joueurs jouent une carte chacun
    Carte carte2_joueur1 = joueur1.jouer_carte();
    Carte carte2_joueur2 = joueur2.jouer_carte();

    //on les ajoute a la pioche
    pioche.ajouter_carte(carte2_joueur1);
    pioche.ajouter_carte(carte2_joueur2);

    cout << joueur1.get_nom() << " joue ";
    carte2_joueur1.afficher();
    cout << joueur2.get_nom() << " joue ";
    carte2_joueur2.afficher();

}
//comparaison des numeros de cartes pour trouver le gagnant
void comparaison (Joueur& joueur1, Joueur& joueur2, Joueur& pioche){
    bool verif = true;
    while(verif){
        Carte valeur1= pioche.jouer_carte();
        Carte valeur2= pioche.jouer_carte();

        if (valeur1.get_numero() > valeur2.get_numero()) {
            pioche.ajouter_carte(valeur1);
            pioche.ajouter_carte(valeur2);
            string gagnant="Joueur1";
            victoire(joueur1, joueur2,pioche,gagnant);
            verif=false;

        } else if (valeur2.get_numero() > valeur1.get_numero()) {
            pioche.ajouter_carte(valeur1);
            pioche.ajouter_carte(valeur2);
            string gagnant="Joueur2";
            victoire(joueur1, joueur2, pioche, gagnant);
            verif=false;

        } else {
            if (joueur1.taille() < 2){
                cout <<"Partie termine :"<<endl;
                cout << "Le gagnant est "<< joueur2.get_nom()<<endl;
                string gagnant="Joueur2";
                victoire(joueur1, joueur2, pioche, gagnant);
                return;
            }else if (joueur2.taille() < 2){
                cout <<"Partie termine :"<<endl;
                cout << "Le gagnant est "<< joueur1.get_nom()<<endl;
                string gagnant="Joueur1";
                victoire(joueur1, joueur2, pioche, gagnant);
                return;
            }else{
                string gagnant = "";
                pioche.ajouter_carte(valeur1);
                pioche.ajouter_carte(valeur2);
                bataille(joueur1, joueur2, pioche, gagnant);
            }
        }
    }
}

int main(int argc, char **argv) {
    vector<Carte> paquet;      //liste de toutes les cartes disponibles
    const string couleurs[4] = {"coeur", "trefle", "pique", "carreau"};
    for(string couleur :couleurs){
        for (int i = 2; i <=14; i++){
            paquet.push_back(Carte(i, couleur));
        }
    }

    // Mélange des cartes
    random_device rd;
    mt19937 g(rd());
    shuffle(paquet.begin(), paquet.end(),g);

    // Création des joueurs et de la pioche
    Joueur joueur1("Joueur 1");
    Joueur joueur2("Joueur 2");
    Joueur pioche("pioche");

    // Distribution des cartes
    for (int i = 0; i < 52; i++) {
        if (i % 2 == 0) {
            joueur1.ajouter_carte(paquet[i]);
        } else {
            joueur2.ajouter_carte(paquet[i]);
        }
    }

    bool test = true;
    while (test) {

        cout << "Manche " << manche << endl;

        // Les joueurs jouent une carte chacun
        Carte carte_joueur1 = joueur1.jouer_carte();
        Carte carte_joueur2 = joueur2.jouer_carte();

        pioche.ajouter_carte(carte_joueur1);
        pioche.ajouter_carte(carte_joueur2);

        cout << joueur1.get_nom() << " joue ";
        carte_joueur1.afficher();
        cout << joueur2.get_nom() << " joue ";
        carte_joueur2.afficher();

        comparaison(joueur1, joueur2, pioche);

        manche +=1;
        cout << "il reste "<< joueur1.taille()<< " cartes au joueur 1"<<endl;
        cout << "il reste "<< joueur2.taille()<< " cartes au joueur 2"<<endl;
        test = joueur2.a_des_cartes() && joueur1.a_des_cartes();
    }
    cout << "Partie termine ! " <<endl;

    //on verifie lequel des joueurs est a court de cartes pour afficher le gagnant
    if (joueur1.a_des_cartes()==false){
        cout << "Le gagnant est le joueur 2" <<endl;
    }else if (joueur2.a_des_cartes()==false){
        cout << "Le gagnant est le joueur 1 "<<endl;
    }
    return 0;
}

//Autoroute(orlane)


char guess;


int score = 0; //score general
void augmenter_score(Joueur& Joueur){
    score += 1;
}

void reinitialiser_score(Joueur& Joueur){ //le score redemarre de 0
    score = 0;
}

void afficher_score(Joueur& Joueur){ //afficher score va a la ligne pour l'afficher
    cout << "Score : " << score <<endl;
}

void comparaison (Joueur& Joueur, Carte currentCard, Carte nextCard,char guess) { // compare les scores des joueur est annonce bravo au gagnant
    if (nextCard.get_numero() >= currentCard.get_numero() && guess == '+') {
        cout << "Bravo !" << endl;
        augmenter_score(Joueur);
        currentCard = nextCard;
    } else if (nextCard.get_numero() <= currentCard.get_numero() && guess == '-') {
        cout << "Bravo" << endl;
        augmenter_score(Joueur);
        currentCard = nextCard;
    } else {
        cout <<" Dommage" <<endl; // compare les scores des joueur est annonce dommage au perdant et retourne à zero
        reinitialiser_score(Joueur);
    }
}

int main(int argc, char **argv) {
    vector<Carte> paquet;
    const string couleurs[4] = {"coeur", "trefle", "pique", "carreau"}; //creation d'un paquet carte avec les differents nom
    for(string couleur :couleurs){
        for (int i = 2; i <=10; i++){
            paquet.push_back(Carte (i, couleur));
        }
    }

    // Mélange des cartes
    random_device rd;
    mt19937 g(rd());
    shuffle(paquet.begin(), paquet.end(),g);

    // Création des joueurs
    Joueur joueur1("Joueur 1");
    Joueur joueur2("Joueur 2");

    // Distribution des cartes
    for (int i = 1; i < 60; i++) {
        if (i % 2 == 0) {
            joueur1.ajouter_carte(paquet[i]);
        } else {
            joueur2.ajouter_carte(paquet[i]);
        }
    }

    while (score !=12) { //nombre de manche
        cout << "Manche " << manche << endl;

        // Les joueurs jouent une carte chacun
        Carte currentCard = joueur1.jouer_carte();
        cout << joueur1.get_nom() << " tire ";
        currentCard.afficher();
        cout << "Devinez si la prochaine carte sera plus grande (+) ou plus petite (-) : ";
        cin >> guess;

        Carte nextCard = joueur1.jouer_carte(); //joueur tire une carte
        cout << joueur1.get_nom() << " tire ";
        nextCard.afficher();

        comparaison(joueur1, currentCard, nextCard, guess); //fonction comparaison
        afficher_score(joueur1);
            if (score == 12){
                cout << "Victoire du joueur 1 " <<endl; //annonce victoire du joueur 1
                return 0;
        }
        cout <<endl;
        cout <<endl;

        // Les joueurs jouent une carte chacun
        Carte currentCard2 = joueur2.jouer_carte();
        cout << joueur2.get_nom() << " tire ";
        currentCard2.afficher();
        cout << "Devinez si la prochaine carte sera plus grande (+) ou plus petite (-) : ";
        cin >> guess;
        Carte nextCard2 = joueur2.jouer_carte(); //joueur 2 joue une carte
        cout << joueur2.get_nom() << " tire ";
        nextCard2.afficher();
        comparaison(joueur2, currentCard2, nextCard2, guess);
        afficher_score(joueur2);
        if (score == 12) {
            cout << "Victoire du joueur 2 " <<endl; //annonce de la victoire du joueur 2
            return 0 ;
        }
        cout << endl;
        cout << endl;
        manche +=1;
    }

    cout << "Merci d'avoir joué !" << endl; //remercie au joueur d'avoir jouer
    return 0;
}


//President (Enzo)

// Définition de la structure d'une carte
struct Card {
    int value; // Valeur de la carte
    string name; // Nom de la carte

    // Constructeur de la structure Card
    Card(int v, string n) {
        value = v;
        name = n;
    }
};

// Définition de la structure d'un joueur
struct Player {
    string name; // Nom du joueur
    vector<Card> hand; // Main du joueur

    // Constructeur de la structure Player
    Player(string n) {
        name = n;
    }
};

// Fonction pour afficher une carte
void displayCard(Card card) {
    cout << card.name;
}

// Fonction pour afficher une main de cartes
void displayHand(vector<Card> hand) {
    for (int i = 0; i < hand.size(); i++) {
        displayCard(hand[i]);
        if (i < hand.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

// Fonction pour initialiser le jeu avec toutes les cartes
vector<Card> initializeDeck() {
    vector<Card> deck;

    // Ajout des cartes dans le deck
    for (int i = 3; i <= 14; i++) {
        if (i == 11) {
            deck.push_back(Card(i, "Valet"));
        } else if (i == 12) {
            deck.push_back(Card(i, "Dame"));
        } else if (i == 13) {
            deck.push_back(Card(i, "Roi"));
        } else if (i == 14) {
            deck.push_back(Card(i, "As"));
        } else {
            deck.push_back(Card(i, to_string(i)));
        }
    }

    // Mélange des cartes dans le deck
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(),deck.end(),g);

    return deck;
}

// Fonction pour distribuer les cartes aux joueurs
void dealCards(vector<Player>& players, vector<Card>& deck) {
    int numPlayers = players.size();
    int numCards = deck.size() / numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numCards; j++) {
            players[i].hand.push_back(deck[numCards * i + j]);
        }
    }
}

// Fonction pour déterminer le joueur qui commence la partie
int determineFirstPlayer(vector<Player>& players) {
    int numPlayers = players.size();

    // Recherche de la carte la plus faible parmi les joueurs
    int minCardValue = 15;
    int firstPlayerIndex = -1;
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < players[i].hand.size(); j++) {
            if (players[i].hand[j].value < minCardValue) {
                minCardValue = players[i].hand[j].value;
                firstPlayerIndex = i;
            }
        }
    }
    return firstPlayerIndex;
}

