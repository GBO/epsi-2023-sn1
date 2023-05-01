#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <SFML/Audio.hpp>

#ifdef _WIN32

#include <Windows.h>

#endif

using namespace std;

#ifdef _WIN32
HANDLE hstdout;
#endif

#ifdef _WIN32
#define BLEU 9
#define BLANC 15
#define ROUGE 12
#define VERT 10
#define JAUNE 14

#else
#define BLEU 34
#define BLANC 0
#define ROUGE 31
#define VERT 32
#endif

void setcolor(int color) {
#ifdef _WIN32
    SetConsoleTextAttribute(hstdout, color);
#else
    cout << "\033[" + to_string(color) + "m";
#endif
}

void log(string text, int color = BLANC) {
    setcolor(color);
    cout << text;
}

void logln(string text, int color = BLANC) {
    log(text + "\n", color);
}

enum TypeCle {
    CLE_OR,
    CLE_DIAMANT
};

enum TypeCoffre {
    COFFRE_OR,
    COFFRE_DIAMANT
};


class Sorts {
public:
    virtual void soigner(int &vie) {
        int soins = rand() % 16 + 40;
        vie += soins;
        if (vie > 100) {
            vie = 100;
        }
        cout << ": " << soins << " points de vie récupérés." << endl;
    }

    int tours_attaque_reduite = 0; // initialiser le compteur de tours à 0
    bool attaque_reduite = false; // initialiser la variable à false

    void reduireAttaque(int &attaque) {
        if (!attaque_reduite) { // vérifier si l'attaque a déjà été réduite
            int reduction = attaque * 0.75;
            attaque -= reduction;
            if (attaque < 0) {
                attaque = 0;
            }
            attaque_reduite = true; // marquer l'attaque comme réduite
            tours_attaque_reduite = 3; // initialiser le nombre de tours restants à 3
        } else if (tours_attaque_reduite > 0) { // vérifier si l'attaque est réduite pour un certain nombre de tours
            tours_attaque_reduite--; // décrémenter le nombre de tours restants
        } else {
            attaque_reduite = false; // marquer l'attaque comme non réduite
        }
    }


    virtual void renvoyerAttaque(int attaque, int &vieEnnemi) {
        int degats = attaque * 0.5; // réduire les dégâts de l'ennemi de moitié
        vieEnnemi -= degats; // infliger les dégâts à l'ennemi
        cout << "Vous renvoyez l'attaque et infligez " << degats << " dégâts à l'ennemi !" << endl;
    }



};


class Personnage : public Sorts {
private:
    bool aCleOr = false;
    bool aCleDiamant = false;
protected:
    string nom;
    string arme;
    int attaque;
    int defense;
    int vie;
    Sorts sorts;  // variable membre Sorts

public:
    Personnage(string n, string ar, int a, int d) {
        this->nom = n;
        this->arme = ar;
        this->attaque = a;
        this->defense = d;
        this->vie = 100;

    }

    void ramasserClef(TypeCle type) {
        if (type == CLE_OR) {
            aCleOr = true;
            log("\nVous ramassez la cle en or", JAUNE);

        }
    }

    void ramasserCle2(TypeCle type) {
        if (type == CLE_DIAMANT) {
            aCleDiamant = true;
            log("\nVous ramassez la cle en diamant", JAUNE);

        }
    }

    bool ouvrirCoffre(TypeCoffre type) {
        if (type == COFFRE_OR && aCleOr) {
            cout << "Vous ouvrez le coffre" << endl;
            cout << "Vous voila riche !" << endl;
            return true;
        } else {
            cout << "Vous n'avez pas la clé" << endl;
            return false;
        }
    }


    bool ouvrirCoffre2(TypeCoffre type) {
        if (type == COFFRE_DIAMANT && aCleDiamant) {
            cout << "Vous ouvrez le coffre" << endl;
            cout << "Vous y trouvez les plus puissants artefacts magiques du roi YSMAG !" << endl;
            return true;
        } else {
            cout << "Vous n'avez pas la clé" << endl;
            return false;
        }
    }

    void setVie(int v) {
        vie = v;
    }

    int getVie() const {
        return this->vie;
    }


    virtual void attaquer(Personnage *cible) {
        int degats = this->attaque;
        cible->subir(degats);
    }

    virtual void attaquer2(Personnage *cible) {
        int degats = this->attaque;
        sorts.reduireAttaque(attaque); // appel de reduireAttaque
        cible->subir2(degats);
    }

    virtual void attaquer3(Personnage *cible) {
        int degats = this->attaque;
        cible->subir3(degats);
    }

    void subir(int degats) {
        int d = degats * ((100.0 - this->defense) / 100.0);
        log("Vous infligez : ");
        log(to_string(d), BLEU);
        log(" degats.");
        this->vie -= d;
    }

    void subir2(int degats) {
        int d = degats * ((100.0 - this->defense) / 100.0);
        log("\nL'ennemi vous inflige: ");
        log(to_string(d), BLEU);
        log(" degats.");
        this->vie -= d;
    }

    void subir3(int degats) {
        int d = degats * ((100.0 - this->defense) / 100.0);
        log("\nL'ennemi vous inflige: ");
        log(to_string(d), BLEU);
        log(" degats.");
        this->vie -= d;
    }

    void afficher3() {
        log("\n", BLANC);
        log(this->nom, ROUGE);
        log(" passe a " + to_string(this->vie) + " PV  !");
    }

    void afficher4() {
        log("\n", BLANC);
        log(this->nom, JAUNE);
        log(" passe a " + to_string(this->vie) + " PV  !");
    }


};


class Dragon : public Personnage {
protected:
    int attaqueDragon;

public:

    Dragon(string n, string ar, int a, int d) : Personnage(n, ar, a, d) {}

    void afficher2() {
        log(this->nom, ROUGE);
        log(" a " + to_string(this->attaqueDragon) + " degats d'attaque et " + to_string(this->defense) +
            " de defense, ainsi que " + to_string(this->vie) + " PV ");
    }

    void setAttaque(int a) {  // define the setAttaque() member function
        attaqueDragon = a;
    }

    int getAttaque() const {  // define the getAttaque() member function
        return attaqueDragon;
    }
};

class Mimic : public Personnage {
protected:
    int attaqueMimic;
public:

    Mimic(string n, string ar, int a, int d) : Personnage(n, ar, a, d) {}

    void afficher2() {
        log(this->nom, ROUGE);
        log(" a " + to_string(this->attaqueMimic) + " degats d'attaque et " + to_string(this->defense) +
            " de defense, ainsi que " + to_string(this->vie) + " PV ");
    }

    void setAttaque(int a) {  // define the setAttaque() member function
        attaqueMimic = a;
    }

    int getAttaque() const {  // define the getAttaque() member function
        return attaqueMimic;
    }

    bool sortKill(Personnage *target) {
        int chance = rand() % 100 + 1;
        if (chance <= 5) {
            target->setVie(0);
            return true;
        }else{
        cout << "Le sort Kill a échoué." << endl;
        return false;
        }
    }
};

class BossFinal : public Personnage {
protected:
    int attaqueSpeciale;
    int turns; // Utilisé pour compter le nombre de tours avant qu'une boule de feu soit lancée
public:
    BossFinal(string n, string ar, int a, int d, int as) : Personnage(n, ar, a, d), attaqueSpeciale(as) {}

    void afficher2() {
        log(this->nom, ROUGE);
        log(" a " + to_string(this->attaque) + " degats d'attaque, " + to_string(this->defense) +
            " de defense, " + to_string(this->vie) + " PV et une attaque spéciale de " +
            to_string(this->attaqueSpeciale) + " degats");
    }


    void bouleDeFeu(Personnage *target) {
        log("Le Boss Final lance une boule de feu !");
        // inflige des dégâts en fonction de l'attaque spéciale
        int degats = attaqueSpeciale;
        target->setVie(target->getVie() - degats);
        log("La boule de feu inflige " + to_string(degats) + " dégâts !");
    }

    int getAttaque() const {
        return this->attaque + this->attaqueSpeciale;
    }

    // Ajoutez des fonctions getTurns et setTurns
    int getTurns() const {
        return this->turns;
    }

    void setTurns(int turns) {
        this->turns = turns;
    }
};


class Guerrier : public Personnage {

public:


    Guerrier(string n, string ar, int a, int d) : Personnage(n, ar, a, d) {
    }


};


class Brute : public Guerrier {
protected:
    int rage;
public:

    Brute(string n) : Guerrier(n, "Epée_Longue", 25, 10), rage(5) {}

    void afficher0() {

        log("\n Vous avez " + to_string(this->attaque) + " degats d'attaque et " + to_string(this->defense) +
            " de defense, ainsi que " + to_string(this->vie) + " PV et une rage de " + to_string(this->rage) +
            "  !");
    }

    void reduireAttaque(int attaque) { // new method to reduce boss attack
        if (rage >= 10) {
            Sorts::reduireAttaque(attaque);
            rage -= 7;
            logln("Le sort de réduction d'attaque a consommé 10 de rage !");
            logln("Il vous reste " + std::to_string(rage) + " points de rage !");
        } else {
            logln("La Brute n'a pas suffisamment de rage pour lancer le sort de réduction d'attaque !");
        }
    }

    void setRage() {
        rage = 15;
    }

    void augmenterRage() {
        this->rage += 10;
        if (this->rage > 40) {
            this->rage = 40;
        }
    }

    int getRage() const {
        return this->rage;
    }

    void attaquer(Personnage *cible) {
        int degats = this->attaque;
        cible->subir(degats);
        this->augmenterRage(); // ajouter de la rage lors de l'attaque
    }

    void attaquer3(Personnage *cible) {
        int degats = this->attaque;
        cible->subir3(degats);
        this->augmenterRage(); // ajouter de la rage lors de l'attaque
    }
};

class Paladin : public Guerrier {
protected:
    int mana; // nouvel attribut mana

public:
    Paladin(string n) : Guerrier(n, "Epée_bouclier", 20, 15), mana(50) {}


    void afficher1() {

        log("\n Vous avez " + to_string(this->attaque) + " degats d'attaque et " + to_string(this->defense) +
            " de defense, ainsi que " + to_string(this->vie) + " PV " + to_string(this->mana) +
            " Mana et un sort de soins !");
    }

    void setMana() {
        mana = 50;
    }

    int getMana() const {
        return this->vie;
    }

    void soigner() { // nouvelle méthode soigner qui utilise le mana
        if (mana >= 10) { // vérifie si le mana est suffisant
            Guerrier::soigner(vie); // soigne le personnage
            mana -= 10; // consomme le mana
            logln("Le sort de soin a consommé 10 mana !");
            logln("Il vous reste " + std::to_string(mana) + " points de mana !");
        } else {
            logln("Le Paladin n'a pas suffisamment de mana pour lancer le sort de soin !");
        }
    }
};

int main() {

    sf::Music musictheme;
    // Chargement du fichier audio
    if (!musictheme.openFromFile("C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\explorer.wav")) {
        // Gestion de l'erreur si le fichier n'a pas pu être chargé
        // (affichage d'un message d'erreur par exemple)
    }
    // Lecture du fichier audio
    musictheme.play();


    char choix_commun = ' ';
    //Passe la console en UTF8 pour ne plus avoir de problèmes d'accents
    SetConsoleOutputCP(CP_UTF8);
// Récupère le STD_OUTPUT_HANDLE pour manipuler les couleurs de sortie
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cout
            << " Vous êtes un héros sans peur ni reproche, prêt à défier les sombres abysses de la crypte du Roi YSMAG !\nLà-bas, de"
               " redoutables pièges, des dangers mortels et des ennemis sans pitié vous attendent, mais rien ne peut vous arrêter dans"
               " votre quête de gloire et de trésors légendaires.\nVotre courage est votre épée, votre détermination votre bouclier,"
               " et vous êtes prêt à affronter tous les défis que la crypte vous réserve."
               "\nAlors, êtes-vous prêt à entrer dans l'histoire en devenant le conquérant de la crypte du Roi YSMAG ?"
            << endl;

    log("\nIl y a deux clés cachés qui debloqueront la vrai fin si rassemblés !", ROUGE);

    log("\n[Appuyez sur Entrée pour continuer]", BLANC);

    string input;
    getline(std::cin, input);

    string nom;
    cout << "Entrez le nom de votre aventurier : ";
    cin >> nom;
    Guerrier *g = nullptr;
    Brute *b = new Brute(nom);
    Paladin *a = new Paladin(nom);
    bool confirmation = false;
    char choix;
    string reponse;

    while (!confirmation) {
        log("Choisissez une classe : \n", BLANC);
        log("1. Votre classe est ", BLANC);
        log("Brute", JAUNE);
        log(" : ", BLANC);
        b->afficher0();
        log("\n", BLANC);
        log("2. Votre classe est ", BLANC);
        log("Paladin : ", JAUNE);
        a->afficher1();
        log("\n", BLANC);
        log("3. Quitter\n", BLANC);
        log("Votre choix : ", BLANC);
        cin >> choix;
        if (choix == '1') {
            g = new Brute(nom);
            log("Êtes-vous sûr de vouloir choisir Brute ? (oui/non)", BLANC);
            cin >> reponse;
            if (reponse == "oui") {
                // créer le personnage Brute
                confirmation = true;
            }
        } else if (choix == '2') {
            g = new Paladin(nom);
            log("Êtes-vous sûr de vouloir choisir Paladin ? (oui/non)", BLANC);
            cin >> reponse;
            if (reponse == "oui") {
                // créer le personnage Paladin
                confirmation = true;
            }
        } else if (choix == '3') {
            // quitter le programme
            confirmation = true;
            return 0;
        } else {
            log("Choix invalide. Veuillez entrer 1, 2 ou 3.", ROUGE);
        }
    }//fermeture du while


    cout << "Vous voici devant la porte d'entrée de la crypte." << endl;


    char choix2;
    bool choix_valide = false;

    while (!choix_valide) {
        choix0_rate:

        cout << "\nQue désirez-vous faire ?" << endl;
        getline(std::cin, input);

        log("[1] Franchir la porte d'entrée du donjon", BLANC);
        log("\n[2] Examiner la porte à la recherche d'un piège", BLANC);
        log("\n[3] Prendre la fuite et ne jamais revenir", BLANC);

        cin >> choix2; // saisie de la valeur choisie par l'utilisateur

        if (choix2 == '2') {

            cout << "Pour trouver le piège vous devez résoudre cette énigme" << endl;
            log("Quel est le mot de trois lettres que même le plus grand des sages prononce mal ?\n", ROUGE);
            string choix98; // utiliser un string pour stocker la réponse complète
            bool choix_valide11 = false;
            while (!choix_valide11) {
                choix_valide11 = true; // utiliser la variable correcte pour éviter une boucle infinie
                cin >> choix98; // saisie de la valeur choisie par l'utilisateur
                if (choix98 == "mal") { // comparer avec le mot complet plutôt qu'avec une seule lettre
                    log("Il y a effectivement un piège ! .", ROUGE);
                    log("\n[1] Tenter de desamorser le piege pour entrer", BLANC);
                    log("\n[2] Chercher une autre entrée", BLANC);
                    log("\n[3] Ne pas s'inquieter et rentrer dans le donjon", BLANC);
                    log("\n[4] Abandonner devant cette obstacle et rentrer chez vous", BLANC);
                    char choix4;
                    bool choix_valide4 = false;
                    cin >> choix4; // saisie de la valeur choisie par l'utilisateur

                    if (choix4 == '1') {
                        choix_valide4 = true;
                        piege0:
                        log("\nVous devez obtenir un score supérieur a 2.", BLANC);
                        cout << "\nAppuyez sur 'L' pour lancer le dé." << endl;
                        char roll;
                        cin >> roll;
                        if (roll == 'L' || roll == 'l') {
                            srand(time(0));
                            int resultat = rand() % 6 + 1; // simule le lancer d'un dé à 6 faces

                            if (resultat == 1 || resultat == 2) {
                                cout << "Echec ! Vous avez obtenu un " << resultat << "." << endl;
                                log("Vous franchissez la porte .", ROUGE);
                                goto choix2_rate; // redirige le joueur vers le piege choix 1
                            } else {
                                cout << "Réussite ! Vous avez obtenu un " << resultat << "." << endl;
                                log("Vous franchissez la porte apres avoir desamorcé le piege.", BLANC);
                                goto choix4_rate;
                            }
                        }
                    }else if (choix4 == '2') {
                        log("\nUn arbre elfique double sa taille tous les jours. Il lui faut 100 jours pour atteindre sa taille adulte. Combien de jours faut-il pour atteindre la moitié de cette taille ?",
                            ROUGE);
                        string choix11111; // utiliser un string pour stocker la réponse complète
                        bool choix_valide11111 = false;
                        while (!choix_valide11111) {
                            choix_valide11111 = true; // utiliser la variable correcte pour éviter une boucle infinie
                            cin >> choix11111; // saisie de la valeur choisie par l'utilisateur
                            if (choix11111 == "99") {
                                choix_valide11111 = true;
                                log("\lVous empruntez la porte dérobée", BLANC);
                                cout
                                        << "\nLa porte vous mene dans une salle ou ne se trouve qu'un coffre en son centre"
                                        << endl;
                                log("\n[1] Quitter la salle et rentrer dans le donjon", BLANC);
                                log("\n[2] Votre curiosité vous pousse à ouvrir le coffre", BLANC);
                                char choix987;
                                bool choix_valide987 = false;
                                cin >> choix4; // saisie de la valeur choisie par l'utilisateur
                                if (choix987 == '1') {
                                    choix_valide987 = true;
                                    cout
                                            << "Votre confusion sur l'interet de ce coffre vous fait oublier la presence du piege sur la porte"
                                            << endl;
                                    goto choix2_rate;
                                } else if (choix987 = '2') {
                                    log("Vous Examinez le coffre .", BLANC);
                                    cout << "\nVous devez obtenir un score supérieur a 2." << endl;
                                    cout << "\nAppuyez sur 'L' pour lancer le dé." << endl;
                                    char roll;
                                    cin >> roll;

                                    if (roll == 'L' || roll == 'l') {
                                        choix_valide987 = true;
                                        srand(time(0)); // initialisation du générateur de nombres aléatoires

                                        int resultat = rand() % 6 + 1; // simule le lancer d'un dé à 6 faces

                                        if (resultat < 2) {
                                            choix_valide987 = true;
                                            cout << "\nEchec ! Vous avez obtenu un " << resultat << "." << endl;
                                            log("\nLe coffre etait en réalité une Mimic ! .", ROUGE);

                                            logln("\nVous rencontrez une Mimic !", ROUGE);
                                            cout << "\nAppuyez sur Entrée pour continuer..." << endl;
                                            getline(std::cin, input);

                                            sf::Time timeOffset = musictheme.getPlayingOffset();
                                            musictheme.stop();

                                            sf::Music musiccombat;
                                            // Chargement du fichier audio
                                            if (!musiccombat.openFromFile(
                                                    "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\test2.wav")) {
                                                // Gestion de l'erreur si le fichier n'a pas pu être chargé
                                                // (affichage d'un message d'erreur par exemple)
                                            }
                                            // Lecture du fichier audio
                                            musiccombat.play();


                                            Mimic *p = nullptr;
                                            p = new Mimic("Mimic", "Dents pointues", 30, 20);
                                            p->setAttaque(15);
                                            p->setVie(100);
                                            p->afficher2(); // affiche le nom, l'attaque, la défense et la vie de la Mimic

                                            bool aReduit = false; // variable pour indiquer si le Paladin a déjà utilisé soigner


                                            while (p->getVie() > 0 && g->getVie() > 0) {
                                                int choix_action;
                                                cout << " \n Que voulez-vous faire ?" << endl;
                                                cout << "1. Attaquer" << endl;

                                                if (typeid(*g) == typeid(Brute)) {
                                                    if (!aReduit) {
                                                        cout << "2. Intimidation[10 rages]" << endl;
                                                    }
                                                }

                                                if (typeid(*g) == typeid(Paladin)) {
                                                    cout << "2. Lancer un sort de soins [10 mana]" << endl;
                                                }

                                                cout << "Votre choix : ";
                                                cin >> choix_action;

                                                if (choix_action == 1) {
                                                    g->attaquer(p);
                                                    p->afficher3();
                                                    if (p->sortKill(g)) {
                                                        log("a mimic lance le sort kill !", ROUGE);
                                                    }

                                                } else if (choix_action == 2 && typeid(*g) == typeid(Brute) &&
                                                           !aReduit) {
                                                    Brute *bru = static_cast<Brute *>(g);
                                                    if (bru->getRage() < 10) {
                                                        log("Vous n'avez pas assez de rage pour lancer l'intimidation !");
                                                        continue; // revenir au début de la boucle while
                                                    }
                                                    bru->reduireAttaque(p->getAttaque());
                                                    p->afficher4();
                                                    aReduit = true;

                                                } else if (choix_action == 2 && typeid(*g) == typeid(Paladin)) {
                                                    Paladin *pal = static_cast<Paladin *>(g);
                                                    if (pal->getMana() < 10) {
                                                        log("Vous n'avez pas assez de mana pour lancer le sort de soins !");
                                                        continue; // revenir au début de la boucle while
                                                    }
                                                    pal->soigner();
                                                    pal->afficher4();
                                                }
                                                if (aReduit) {
                                                    if (p->getVie() > 0) {
                                                        if (rand() % 50 == 0) { // 60% de chances
                                                            p->attaquer(g);
                                                            g->afficher4();
                                                        } else {
                                                            log("La mimic lance le sort kill !", ROUGE);
                                                            p->sortKill(g);
                                                            g->afficher4();
                                                        }
                                                    }
                                                } else {
                                                    if (p->getVie() > 0) {
                                                        if (rand() % 50 == 0) { // 60% de chances
                                                            p->attaquer(g);
                                                            g->afficher4();
                                                        } else {
                                                            log("La mimic lance le sort kill !", ROUGE);
                                                            p->sortKill(g);
                                                            g->afficher4();
                                                        }
                                                    }

                                                    else {
                                                        cout << "\n Vous avez vaincu la Mimic !" << endl;

                                                        cout << "\n Vous avez survécu de peu !" << endl;
                                                    }
                                                }


                                                if (p->getVie() <= 0) {

                                                    cout << "\nLa mimic est morte. Vous avez gagné !" << endl;
                                                    musiccombat.stop();
                                                    sf::Music musicvictoire;
                                                    // Chargement du fichier audio
                                                    if (!musicvictoire.openFromFile(
                                                            "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\victoire.wav")) {
                                                        // Gestion de l'erreur si le fichier n'a pas pu être chargé
                                                        // (affichage d'un message d'erreur par exemple)
                                                    }
                                                    // Lecture du fichier audio
                                                    musicvictoire.play();

                                                    if (choix == '1') {
                                                        // code précédent

                                                        cout
                                                                << "\nVous ramassez une clé en diamant sur le cadavre de la mimic."
                                                                << endl;
                                                        g->ramasserCle2(CLE_DIAMANT);

                                                        cout << "\nAppuyez sur Entrée pour continuer...";
                                                        cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                                                        cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                                                        musicvictoire.stop();
                                                        musictheme.play();
                                                        musictheme.setPlayingOffset(timeOffset);

                                                        logln("\nVous retournez à la porte d'entrée et tenter de désamorçer le piege",
                                                              BLANC);

                                                        while (true) { // Boucle infinie
                                                            cout << "\nAppuyez sur Entrée pour continuer...";
                                                            cin.ignore();
                                                            if (cin.get() == '\n')
                                                                break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                                                        }

                                                        goto piege0;
                                                    } else if (choix == '2') {


                                                        g->setVie(100);
                                                        cout
                                                                << "\nAprès un repos bien mérité, vos PV et votre mana sont entièrement régénérés !"
                                                                << endl;
                                                        dynamic_cast<Paladin *>(g)->setMana();
                                                        choix_valide = true;

                                                        g->ramasserCle2(CLE_DIAMANT);


                                                        cout << "\nAppuyez sur Entrée pour continuer...";
                                                        cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                                                        cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                                                        musicvictoire.stop();
                                                        musictheme.play();
                                                        musictheme.setPlayingOffset(timeOffset);

                                                        logln("\nVous retournez à la porte d'entrée et tenter de désamorçer le piege",
                                                              BLANC);

                                                        while (true) { // Boucle infinie
                                                            cout << "\nAppuyez sur Entrée pour continuer...";
                                                            cin.ignore();
                                                            if (cin.get() == '\n')
                                                                break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                                                        }

                                                        goto piege0;
                                                    }
                                                }
                                            }

                                                    if (g->getVie() <= 0) {

                                                        musiccombat.stop();
                                                        sf::Music musicdefaite;
                                                        // Chargement du fichier audio
                                                        if (!musicdefaite.openFromFile(
                                                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\defaite.wav")) {
                                                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                                                            // (affichage d'un message d'erreur par exemple)
                                                        }
                                                        // Lecture du fichier audio
                                                        musicdefaite.play();


                                                        cout << "\nLa mimic vous a tué, quel dommage !" << endl;
                                                        return 0;
                                                    }




                                        } else {
                                            choix_valide987 = true;
                                            cout << "Réussite ! Vous avez obtenu un " << resultat << "."
                                                 << endl;
                                            log("Le coffre etait en réalité une Mimic ! .", ROUGE);
                                            log("\nVous arrivez à en sortir une clé sans la réveiller ! .",
                                                BLANC);
                                            g->ramasserCle2(CLE_DIAMANT);
                                            cout
                                                    << "\nVous retournez à la porte d'entrée et tenter de désamorçer le piege "
                                                    << endl;
                                            goto piege0;
                                        }
                                    }

                                } else {
                                    choix_valide11111 = true;
                                    log("Vous ratez votre lancé de des et rentrez dans le donjon !", ROUGE);
                                    goto choix0_rate; // redirige le joueur vers le piege choix 1
                                }
                            }
                        }

                    } else if (choix4 == '3') {
                        goto choix2_rate; // redirige le joueur vers le piege choix 1
                        choix_valide4 = true;
                    } else if (choix4 == '4') {
                        choix_valide4 = true;
                        cout << "Adieu ! " << endl;
                        return 0;
                    }
                } else {
                    log("\nVous échouez à vérifier la présence d'un piège .", ROUGE);
                    log("\nVous franchissez la porte .", BLANC);
                    goto choix2_rate; // redirige le joueur vers le piege choix 1
                }
            }
        }//fin choix 2== '2'





























        if (choix2 == '1') {
            choix_valide = true;

            choix2_rate: // il s'agit du goto d'un choix en choix2 =='2'
            log("\nVous entrez dans la crypte sombre et poussiéreuse.", BLANC);
            log("\nUn piege se declenche", ROUGE);
            // Deduct 10 PV from the player's health
            Paladin *paladin = dynamic_cast<Paladin *>(g);
            if (paladin != nullptr) {
                paladin->setVie(paladin->getVie() - 10);
            } else {
                Brute *brute = dynamic_cast<Brute *>(g);
                if (brute != nullptr) {
                    brute->setVie(brute->getVie() - 10);
                }
            }
        }
        // Code à exécuter après le déclenchement du piège
        log("\nVous perdez 10 PV !", ROUGE);
        log("\nPV restants : " + std::to_string(g->getVie()) + "\n", BLANC);
        choix4_rate:
        // instructions pour le choix 3
        log("\nVous continuez à avance quand vous remarquez plusieurs passages possibles", BLANC);
        log("\n[1] Un escalier en spirale dont les murs sont recouverts de traces de griffes", BLANC);
        log("\n[2] Un tunnel obscur sur votre droite", BLANC);

        bool choix3_valide = true; // initialise à true pour permettre au joueur de choisir son chemin
        char choix3;

        while (choix3_valide) {


            cin >> choix3;
            if (choix3 == '1') {

                logln("\nVous rencontrez un Bebe Dragon !", ROUGE);
                sf::Time timeOffset = musictheme.getPlayingOffset();
                musictheme.stop();

                sf::Music musiccombat;
                // Chargement du fichier audio
                if (!musiccombat.openFromFile("C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\test2.wav")) {
                    // Gestion de l'erreur si le fichier n'a pas pu être chargé
                    // (affichage d'un message d'erreur par exemple)
                }
                // Lecture du fichier audio
                musiccombat.play();


                Dragon *p = nullptr;
                p = new Dragon("Flameche le bebe dragon", "Griffe", 25, 10);
                p->setAttaque(20);
                p->setVie(80);
                p->afficher2(); // affiche le nom, l'attaque, la défense et la vie de boss1

                bool aReduit = false; // variable pour indiquer si la Brute a déjà utilisé reduireAttaque

                while (p->getVie() > 0 && g->getVie() > 0) {
                    int choix_action;
                    cout << " \n Que voulez-vous faire ?" << endl;
                    cout << "1. Attaquer" << endl;

                    if (typeid(*g) == typeid(Brute)) {
                        if (!aReduit) {
                            cout << "2. Intimidation[10 rages]" << endl;
                        }
                    }

                    if (typeid(*g) == typeid(Paladin)) {
                        cout << "2. Lancer un sort de soins [10 mana]" << endl;
                    }

                    cout << "Votre choix : ";
                    cin >> choix_action;

                    if (choix_action == 1) {
                        g->attaquer(p);
                        p->afficher3();
                        if (typeid(*g) == typeid(Brute)) {
                            log("\n Vous avez " + to_string(dynamic_cast<Brute *>(g)->getRage()) + " rage ");
                        }
                    } else if (choix_action == 2 && typeid(*g) == typeid(Brute) && !aReduit) {
                        Brute *bru = static_cast<Brute *>(g);
                        if (bru->getRage() < 10) {
                            log("Vous n'avez pas assez de rage pour lancer l'intimidation !");
                            continue; // revenir au début de la boucle while
                        }
                        bru->reduireAttaque(p->getAttaque());
                        bru->afficher4();
                        aReduit = true;
                    } else if (choix_action == 2 && typeid(*g) == typeid(Paladin)) {
                        Paladin *pal = static_cast<Paladin *>(g);
                        if (pal->getMana() < 10) {
                            log("Vous n'avez pas assez de mana pour lancer le sort de soins !");
                            continue; // revenir au début de la boucle while
                        }
                        pal->soigner();
                        pal->afficher4();
                    }

                    if (aReduit) {
                        if (p->getVie() > 0) {  // Vérifier si le boss a des points de vie avant d'attaquer
                            p->attaquer2(g);
                            g->afficher4();
                        }
                    } else {
                        if (p->getVie() > 0) {  // Vérifier si le boss a des points de vie avant d'attaquer
                            p->attaquer3(g);
                            g->afficher4();
                        } else {
                            cout << "\n Vous avez survécu de peu !" << endl;
                        }
                    }


                    if (p->getVie() <= 0) {
                        log("\nFlameche le bebe dragon est mort. Vous avez gagné !", JAUNE);
                        musiccombat.stop();
                        sf::Music musicvictoire;
                        // Chargement du fichier audio
                        if (!musicvictoire.openFromFile(
                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\victoire.wav")) {
                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                            // (affichage d'un message d'erreur par exemple)
                        }
                        // Lecture du fichier audio
                        musicvictoire.play();

                        if (choix == '1') {
                            g->setVie(100);
                            cout
                                    << "\nAprès un repos bien mérité, vos PV et votre rage sont entièrement régénérés !"
                                    << endl;
                            dynamic_cast<Brute *>(g)->setRage();
                            cout << "\nAppuyez sur Entrée pour continuer...";
                            cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                            cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                            musicvictoire.stop();
                            musictheme.play();
                            musictheme.setPlayingOffset(timeOffset);

                            while (true) { // Boucle infinie
                                cout << "\nAppuyez sur Entrée pour continuer...";
                                cin.ignore();
                                if (cin.get() == '\n')
                                    break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                            }


                        } else if (choix == '2') {
                            g->setVie(100);
                            cout
                                    << "\nAprès un repos bien mérité, vos PV et votre mana sont entièrement régénérés !"
                                    << endl;
                            dynamic_cast<Paladin *>(g)->setMana();
                            cout << "\nAppuyez sur Entrée pour continuer...";
                            cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                            cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                            musicvictoire.stop();
                            musictheme.play();
                            musictheme.setPlayingOffset(timeOffset);


                            logln("\nVous retournez à la porte d'entrée et tenter de désamorçer le piege",
                                  BLANC);

                            while (true) { // Boucle infinie
                                cout << "\nAppuyez sur Entrée pour continuer...";
                                cin.ignore();
                                if (cin.get() == '\n')
                                    break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                            }


                        }//fin regen pv


                    }//fin si flameche meurt
                    else if (g->getVie() <= 0) {
                        musiccombat.stop();
                        sf::Music musicdefaite;
                        // Chargement du fichier audio
                        if (!musicdefaite.openFromFile(
                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\defaite.wav")) {
                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                            // (affichage d'un message d'erreur par exemple)
                        }
                        // Lecture du fichier audio
                        musicdefaite.play();

                        cout << "\nFlameche vous a tué, quel dommage !" << endl;
return 0;
                    } else {
                        // le combat continue
                    }
                }//fin systeme de combat
                log("\nVous marchez dans le couloir sombre derriere le dragon", BLANC);
                cout << "\nVous vous retrouvez devant l'entrée de la chambre funéraire du Roi Ysmag" << endl;
                cout << "\nVous voyez d'etranges runes sur les contours de l'entrée" << endl;
                char choix6;
                bool choix_valide = false;
                while (!choix_valide) {
                    cout << "\nQue désirez-vous faire ?" << endl;
                    getline(std::cin, input);
                    log("[1] Affronter le roi", BLANC);
                    log("\n[2] Examiner les runes", BLANC);
                    cin >> choix6; // saisie de la valeur choisie par l'utilisateur


                    if (choix6 == '1') {
                        choix_valide = true;
                        choix_commun = '1';

                    }//fin choix6 =='1'

                    else if (choix6 == '2') {
                        choix_valide = true;
                        choix_commun = '2';

                    }


                }//fin choix valide 6
            }//fin choix3 =='1'

            if (choix3 == '2') {
                char choixenigme;
                bool choix_valide = false;
                while (!choix_valide) {
                    log("Vous trouvez une énigme à côté d'une porte verrouillée", ROUGE);

                    log("\nSans voix, il crie.\nSans aile, il voltige.\nSans dents, il mord.\nSans bouche, il murmure.\nQui suis-je ?",
                        BLANC);
                    getline(std::cin, input);
                    log("\n[1] L'Espoir", BLANC);
                    log("\n[2] Le Froid", BLANC);
                    log("\n[3] Le Vent", BLANC);
                    log("\n[4] Le Feu", BLANC);
                    cin >> choixenigme; // saisie de la valeur choisie par l'utilisateur
                    if (choixenigme == '3') {
                        choix_valide = true;
                        log("\nVous trouvez la solution à l'énigme ! .", VERT);
                        log("\nVous voici dans une salle vide à l'exception d'un piédestal où se trouve une clé en or.",
                            BLANC);
                        g->ramasserClef(CLE_OR);
                        log("\nVous sortez de cette salle par un escalier", BLANC);
                        cout << "\nVous vous retrouvez devant l'entrée de la chambre funéraire du Roi Ysmag" << endl;
                        cout << "\nVous voyez d'étranges runes sur les contours de l'entrée" << endl;
                        char choix10;
                        bool choix_valide10 = false;
                        while (!choix_valide10) {
                            cout << "\nVous vous retrouvez devant l'entrée de la chambre funéraire du Roi Ysmag"
                                 << endl;
                            cout << "\nVous voyez d'étranges runes sur les contours de l'entrée" << endl;
                            getline(std::cin, input);
                            log("[1] Affronter le roi", BLANC);
                            log("\n[2] Examiner les runes", BLANC);
                            cin >> choix10; // saisie de la valeur choisie par l'utilisateur
                            if (choix10 == '1') {
                                choix_commun = '1';
                                choix_valide10 = true;
                            } else if (choix10 == '2') {
                                choix_commun = '2';
                                choix_valide10 = true;
                            }
                        } // while choix valide 10
                    } else {
                        log("Vous ne parvenez pas à trouver la solution à l'énigme. UNE TRAPPE S OUVRE SOUS VOS PIEDS !.",
                            ROUGE);
                        cout << "[1]Vous vous retrouvez devant l'entrée de la chambre funéraire du Roi Ysmag"
                             << endl;
                        cout << "[2]Vous voyez d'étranges runes sur les contours de l'entrée" << endl;
                        char choix11;
                        bool choix_valide11 = false;
                        while (!choix_valide11) {
                            log("[1] Affronter le roi", BLANC);
                            log("\n[2] Examiner les runes", BLANC);
                            cin >> choix11; // saisie de la valeur choisie par l'utilisateur
                            if (choix11 == '1') {
                                choix_commun = '1';
                                choix_valide = true;
                                choix_valide11 = true;
                            } else if (choix11 == '2') {
                                choix_commun = '2';
                                choix_valide = true;
                                choix_valide11 = true;
                            }


                        }
                    }
                }


            }


            if (choix_commun == '1') {
                cout << "\nVous vous retrouvez face à la liche Ysmag" << endl;


                sf::Time timeOffset = musictheme.getPlayingOffset();
                musictheme.stop();

                sf::Music musicBoss;
                // Chargement du fichier audio
                if (!musicBoss.openFromFile("C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\Boss.wav")) {
                    // Gestion de l'erreur si le fichier n'a pas pu être chargé
                    // (affichage d'un message d'erreur par exemple)
                }
                // Lecture du fichier audio
                musicBoss.play();


                BossFinal *boss1 = nullptr;
                boss1 = new BossFinal("Ysmag la liche", "Sceptre", 15, 20, 35);
                boss1->setVie(500);
                boss1->afficher2(); // affiche le nom, l'attaque, la défense, les PV et l'attaque spéciale du Boss Final
                bool aReduit = false; // variable pour indiquer si le Paladin a déjà utilisé soigner


                while (boss1->getVie() > 0 && g->getVie() > 0) {
                    int choix_action;
                    cout << " \n Que voulez-vous faire ?" << endl;
                    cout << "1. Attaquer" << endl;

                    if (typeid(*g) == typeid(Brute)) {
                        if (!aReduit) {
                            cout << "2. Intimidation[10 rages]" << endl;
                        }
                    }

                    if (typeid(*g) == typeid(Paladin)) {
                        cout << "2. Lancer un sort de soins [10 mana]" << endl;
                    }

                    cout << "Votre choix : ";
                    cin >> choix_action;

                    if (choix_action == 1) {
                        g->attaquer(boss1);
                        boss1->afficher3();
                        if (typeid(*g) == typeid(Brute)) {
                            log("\n Vous avez " + to_string(dynamic_cast<Brute *>(g)->getRage()) + " rage ");
                        }
                    } else if (choix_action == 2 && typeid(*g) == typeid(Brute) && !aReduit) {
                        Brute *bru = static_cast<Brute *>(g);
                        if (bru->getRage() < 10) {
                            log("Vous n'avez pas assez de rage pour lancer l'intimidation !");
                            continue; // revenir au début de la boucle while
                        }
                        bru->reduireAttaque(boss1->getAttaque());
                        bru->afficher4();
                        aReduit = true;
                    } else if (choix_action == 2 && typeid(*g) == typeid(Paladin)) {
                        Paladin *pal = static_cast<Paladin *>(g);
                        if (pal->getMana() < 10) {
                            log("Vous n'avez pas assez de mana pour lancer le sort de soins !");
                            continue; // revenir au début de la boucle while
                        }
                        pal->soigner();
                        pal->afficher4();
                    }

                    if (aReduit) {
                        if (boss1->getVie() > 0) {  // Vérifier si le boss a des points de vie avant d'attaquer
                            if (rand() % 60 == 0) { // 10% de chances
                                boss1->attaquer(g);
                                g->afficher4();
                            } else {
                                // Attendre 1 tours avant de lancer la boule de feu
                                if (boss1->getTurns() == 0) {
                                    boss1->setTurns(1);
                                    log("\nLe Boss Final charge sa boule de feu !", ROUGE);
                                } else {
                                    boss1->setTurns(boss1->getTurns() - 1);
                                    if (boss1->getTurns() == 0) {
                                        boss1->bouleDeFeu(g);
                                        g->afficher4();
                                    }
                                }
                            }
                        }
                    } else {
                        if (boss1->getVie() > 0) {  // Vérifier si le boss a des points de vie avant d'attaquer
                            if (rand() % 60 == 0) { // 10% de chances
                                boss1->attaquer(g);
                                g->afficher4();
                            } else {
                                // Attendre 1 tours avant de lancer la boule de feu
                                if (boss1->getTurns() == 0) {
                                    boss1->setTurns(1);
                                    log("\nLe Boss Final charge sa boule de feu !", ROUGE);
                                } else {
                                    boss1->setTurns(boss1->getTurns() - 1);
                                    if (boss1->getTurns() == 0) {
                                        boss1->bouleDeFeu(g);
                                        g->afficher4();
                                    }
                                }
                            }
                        } else {
                            cout << "\n Vous avez survécu de peu !" << endl;
                        }
                    }


                    if (boss1->getVie() <= 0) {
                        log("\nYsmag est mort. Vous avez gagné !", JAUNE);

                        sf::Music musicvictoire;
                        // Chargement du fichier audio
                        if (!musicvictoire.openFromFile(
                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\victoire.wav")) {
                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                            // (affichage d'un message d'erreur par exemple)
                        }
                        // Lecture du fichier audio
                        musicvictoire.play();

                        if (choix == '1') {
                            g->setVie(100);
                            cout
                                    << "\nAprès un repos bien mérité, vos PV et votre rage sont entièrement régénérés !"
                                    << endl;
                            dynamic_cast<Brute *>(g)->setRage();
                            choix_valide = true;
                            choix_commun = '3';
                            cout << "\nAppuyez sur Entrée pour continuer...";
                            cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                            cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                            musicvictoire.stop();
                            musictheme.play();
                            musictheme.setPlayingOffset(timeOffset);

                            while (true) { // Boucle infinie
                                cout << "\nAppuyez sur Entrée pour continuer...";
                                cin.ignore();
                                if (cin.get() == '\n')
                                    break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                            }


                        } else if (choix == '2') {
                            g->setVie(100);
                            cout
                                    << "\nAprès un repos bien mérité, vos PV et votre mana sont entièrement régénérés !"
                                    << endl;
                            dynamic_cast<Paladin *>(g)->setMana();
                            choix_valide = true;
                            choix_commun = '3';
                            cout << "\nAppuyez sur Entrée pour continuer...";
                            cin.ignore(); // Ignorer les caractères restants dans le flux d'entrée
                            cin.get(); // Attendre que l'utilisateur appuie sur Entrée

                            musicvictoire.stop();
                            musictheme.play();
                            musictheme.setPlayingOffset(timeOffset);


                            logln("\nVous retournez à la porte d'entrée et tenter de désamorçer le piege",
                                  BLANC);

                            while (true) { // Boucle infinie
                                cout << "\nAppuyez sur Entrée pour continuer...";
                                cin.ignore();
                                if (cin.get() == '\n')
                                    break; // Sortir de la boucle si l'utilisateur appuie sur Entrée
                            }


                        }//fin regen pv


                    }//fin sI ysmag meurt
                    else if (g->getVie() <= 0) {

                        sf::Music musicdefaite;
                        // Chargement du fichier audio
                        if (!musicdefaite.openFromFile(
                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\defaite.wav")) {
                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                            // (affichage d'un message d'erreur par exemple)
                        }
                        // Lecture du fichier audio
                        musicdefaite.play();

                        cout << "\nYsmag vous a tué, quel dommage !" << endl;
return 0;
                    } else {
                        // le combat continue
                    }
                }


            }
             else if (choix_commun == '2') {
                cout << "Vous tentez de déchiffre les runes" << endl;
                cout << "Une énigme se forme !" << endl;
                char choix50;
                bool choix_valide = false;

                while (!choix_valide) {

                    cout
                            << "\nUn chevalier possède 8 chevaux de guerre. En un mois de conflit, tous sauf 5 périrent.\n"
                               "Combien en reste-il ?" << endl;
                    getline(std::cin, input);
                    cin >> choix50; // saisie de la valeur choisie par l'utilisateur

                    if (choix50 == '5') {
                        musictheme.stop();
                        sf::Music musicFin;
                        // Chargement du fichier audio
                        if (!musicFin.openFromFile(
                                "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\oblivion.wav")) {
                            // Gestion de l'erreur si le fichier n'a pas pu être chargé
                            // (affichage d'un message d'erreur par exemple)
                        }
                        // Lecture du fichier audio
                        musicFin.play();
                        cout<< "Les runes vous indiquent qu'un mur illusoire menent directement à la salle aux tresors sans avoir à affronter le Roi YSMAG ! Vous y foncez"
                            << endl;
                        cout << "\nVous trouvez le faux mur et entrez dans la salle aux tresors" << endl;
                        choix_valide = true;
                        choix_commun = '3';
                    } else {
                        cout << "testssss" << endl;
                        choix_valide = true;
                        choix_commun = '1';
                    }
                }


            }


            if (choix_commun == '3') {
                char choix9;
                bool choix_valide = false;
                musictheme.stop();
                sf::Music musicFin;
                // Chargement du fichier audio
                if (!musicFin.openFromFile(
                        "C:\\Users\\clemj\\OneDrive\\Bureau\\jeu\\oblivion.wav")) {
                    // Gestion de l'erreur si le fichier n'a pas pu être chargé
                    // (affichage d'un message d'erreur par exemple)
                }
                // Lecture du fichier audio
                musicFin.play();
                cout << "\nVous voila dans la salle aux tresors !" << endl;
                bool coffre_or_ouvert = false;
                bool coffre_diamant_ouvert = false;

                while (!coffre_or_ouvert || !coffre_diamant_ouvert) {
                    cout << "\nQue désirez-vous faire ?" << endl;
                    getline(std::cin, input);
                    cout << "Voulez-vous ouvrir le coffre en or (o), le coffre en diamant (d), ou partir (p) ?" << endl;
                    char choix;
                    cin >> choix;

                    if (choix == 'o') {
                        coffre_or_ouvert = g->ouvrirCoffre(COFFRE_OR);
                    } else if (choix == 'd') {
                        coffre_diamant_ouvert =  g->ouvrirCoffre2(COFFRE_DIAMANT);
                    } else if (choix == 'p') {
                        cout << "Vous quittez le donjon " << endl;
                        return 0;
                    }
                }

                if (coffre_or_ouvert && coffre_diamant_ouvert) {
                    log("\nL'ouverture des 2 coffres à déclencher l'ouverture d'une porte dérobée  !", JAUNE);
                    log("\nVous y trouver l'urne du Roi Ysmag qui lui conférait ses pouvoirs de réssurection !", BLANC);
                    log("\nVous la detruisez !",ROUGE);
                    log("\nVous quittez le donjon en emportant avec vous le plus d'argent et d'artefacts possible! Avec l'assurance que le Roi Ysmag est belle est bien mort !", BLANC);
                    cout << "" << endl;
                    return 0;
                }
            }//choix commun 3
        }
    }//fin choix_commun =='1'
    if (choix2 == '3') {
        cout << "Adieu ! " << endl;
        return 0;
    }//fin choix2 =='3'


    //fermeture du int main
    return 0;
}