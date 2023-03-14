#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

/*******************************************************************************
 * Gestion des couleurs de sortie console (multiplateforme)
 */

#ifdef _WIN32
HANDLE hstdout;
#endif

#ifdef _WIN32
  #define BLEU 9
  #define BLANC 15
  #define ROUGE 12
  #define VERT 10
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


/*******************************************************************************
 * Classe Eleve
 *
 * Représente un Eleve de notre arène.
 * Permet d'attaquer un autre Eleve et de subir des dégâts
 */
class Eleve {
private:
    string nom;
    string arme;
    int attaque;
    int defense;
    int vie;
public:

    /**
     * Constructeur
     * @param n : Le nom
     * @param ar : L'arme
     * @param n : Le niveau d'attaque
     * @param n : Le niveau de défense
     */
    Eleve(string n, string ar, int a, int d) {
        this->nom = n;
        this->arme = ar;
        this->attaque = a;
        this->defense = d;
        this->vie = 100;
    }

    /** Getter */
    string getNom() { return this->nom; }
    string getArme() { return this->arme; }
    int getAttaque() { return this->attaque; }
    int getDefense() { return this->defense; }
    int getVie() { return this->vie; }

    /**
     * Afficher le Eleve et ses stats
     */
    void afficher() {
        log(this->nom, BLEU);
        log("(" + to_string(this->attaque) + "/" + to_string(this->defense) + ") [" + to_string(this->vie) + "] ");
    }

    /**
     * Attaquer un autre Eleve
     * @param adversaire à attaquer
     */
    void attaquer(Eleve &adversaire) {
        int degats = this->attaque;
        this->afficher();
        log("donne un coup de ");
        log(this->arme, ROUGE);
        log(" à ");
        adversaire.afficher();
        adversaire.subir(degats);
    }

    /**
     * Subir des dégats (pondérés par la défense du Eleve)
     * @param degats : le nombre de dégats à subir
     */
    void subir(int degats) {
        int d = degats * ((100.0 - this->defense) / 100.0);
        log(": ");
        log(to_string(d), ROUGE);
        log(" degats.");
        this->vie -= d;
    }
};


/*******************************************************************************
 * Classe Arene
 *
 * Représente notre arène.
 * Possède une liste de Eleve (debout) et une liste de kos au combat
 * Permet de recruter des eleves, et de lancer la baston
 */
class Arene {
private:
    vector<Eleve*> eleves;
    vector<Eleve*> kos;

public:

    /**
     * Destructeur
     * Libère les instances de eleves créés pendant la phase de recrutement
     */
    ~Arene() {
        for (unsigned int i = 0; i < this->eleves.size(); i++) {
            delete this->eleves[i];
        }
        for (unsigned int i = 0; i < this->kos.size(); i++) {
            delete this->kos[i];
        }
    }

    /**
     * Recruter un Eleve (et l'instancie)
     * @param n : Le nom du Eleve
     * @param ar : L'arme du Eleve
     * @param n : Le niveau d'attaque du Eleve
     * @param n : Le niveau de défense du Eleve
     */
    void recruter(string n, string ar, int a, int d) {
        log("Nouveau Eleve : ");
        Eleve* c = new Eleve(n, ar, a, d);
        c->afficher(); log(": ");
        logln(c->getArme(), ROUGE);
        this->eleves.push_back(c);
    }

    /**
     * Méthode coeur : on implémente la baston ici :)
     */
    void baston() {
        int tour = 1;
        int debout;
        // On mélange les eleves...
        random_shuffle(this->eleves.begin(), this->eleves.end());
        // ...et on lance un round tant qu'il est plus d'un eleve debout...
        while (this->eleves.size() > 1) {
            debout = this->round(tour++);
        }
        // Ensuite, on éxplique la situation
        logln(""); logln("");
        logln("... Le vainqueur (et dernier debout) est : "); logln("");
        this->eleves[debout]->afficher(); logln(""); logln("");
        logln(""); logln("");
        logln("... Et les KOs sont (dans l'ordre) :"); logln("");
        for (unsigned int i = 0; i < this->kos.size(); i++) {
            this->kos[i]->afficher();
        }
        logln("");
    }

    /**
     * Effectue un round de baston
     * Chaque Eleve (encore debout) a l'opportunité d'en attaquer un autre
     * @return le numéro dernier Eleve ayant levé la main
     */
    int round(int tour) {
        unsigned int debout, adversaire;
        logln("");
        logln("ROUND " + to_string(tour), VERT);
        // On ne fait pas un for classique, car la liste d'Eleve évolue pendant la baston...
        // Les règles d'incrémentation du i sont donc complexes.
        unsigned int i = 0;
        while (i < this->eleves.size()) {
            debout = i;
            adversaire = rand() % (this->eleves.size() - 1);
            if (adversaire >= i) {
                adversaire++;
            }
            this->eleves[i]->attaquer(*(this->eleves[adversaire]));
            // Gestion de la mort de l'adversaire (on enlève le Eleve et le stock avec les kos)
            if (this->eleves[adversaire]->getVie() <= 0) {
                log(" Qui tombe dans les vapes... :'(");
                this->kos.push_back(this->eleves[adversaire]);
                this->eleves.erase(this->eleves.begin() + adversaire, this->eleves.begin() + adversaire + 1);
                // On modifie le tableau, donc on incrémente que lorsqu'on a enlevé un élément après le Eleve courant.
                if (adversaire > i) { i++; }
            } else {
                // Pas de modification de tableau, on incrémente
                i++;
            }
            logln("");
        }
        return debout;
    }

};

/*******************************************************************************
 * MAIN ENTRANCE
 */
int main()
{
    #ifdef _WIN32
    // Passe la console en UTF8 pour ne plus avoir de problèmes d'accents
    SetConsoleOutputCP(CP_UTF8);
    // Récupère le STD_OUTPUT_HANDLE pour manipuler les couleurs de sortie
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

    char buffer[9]; // 8 caractères + 1 cartère de fin de chaine

    // Récupérer la date courante
    time_t rawtime;
    time(&rawtime);
    struct tm * timeinfo = localtime(&rawtime);

    // La transformer en chaine de caractère
    strftime(buffer, 9, "%d%m%Y", timeinfo);
    string date(buffer);

    // Intro et question du jour
    logln("BATTLE ROYALE EPSI 2022 : SN1 !");
    logln("Quelle date de match (toujours le même résultat pour une date donnée) ? (par défaut, aujourdhui : " + date + " (saisir 0))");
    int seed;
    cin >> seed;

    // Si l'utilisateur saisit 0 on prend la date précalculée
    if (seed == 0) {
        seed = stoi(date);
    }

    // On initalise avec notre "graine"
    srand(seed);

    // Et BASTON !!
    Arene arene;
    int nbEleve = 26;
    string noms[26] = {"Terry", "Killian", "Yassine", "Louis", "Théo", "Even", "Timéo", "Mathéo", "Titouan", "Enzo", "Rémi", "Clément", "Martin", "Moumine", "Ewan", "Chloé", "Mika", "Akban", "Freddy", "Orlane", "Claire", "Kaïs", "Hugo", "Paul", "Gorane", "Sasha"};
    string armes[6] = {"hâche", "katana", "dague", "hallebarde", "masse", "marteau"};
    int stat;
    for (int i = 0; i < nbEleve; i++ ) {
        stat = 10 + (rand() % 11);
        arene.recruter(noms[i], armes[rand() % 6], stat, 30 - stat);
    }
    arene.baston();

    return 0;
}
