//
// Created by Mika.Ly on 27/03/2023.

//exercice1

#include <iostream>
#include <string>

using namespace std;

string Zombie(string personne) {
    string nom_z = "Zombie ";
    for (char x : personne) {
        if (tolower(x) == 'a') {
            nom_z += "Argh";
        } else if (tolower(x) == 'e') {
            nom_z += "Err";
        } else if (tolower(x) == 'i') {
            nom_z += "Urr";
        } else if (tolower(x) == 'o') {
            nom_z += "Graa";
        } else if (tolower(x) == 'u') {
            nom_z += "Braa";
        } else {
            nom_z += "Mmm";
        }
    }
    return nom_z;
}

int main() {
    string p1 = "Mika";
    string p2 = "Remy";
    cout << "Avant transformation : " << p1 << ", " << p2 << endl;
    cout << "Après transformation : " << Zombie(p1) << ", " << Zombie(p2) << endl;
    return 0;
}




//exercice2
#include <iostream>
#include <string>

using namespace std;

class Humain {

public:
    Humain(string nom) {this->nom = nom;}

    string get_nom() {return this->nom;}

    void afficher() {cout << "Je suis un Humain et mon nom est  " << nom << endl;}

    string nom;
};
int main() {
    Humain h1("Mika");
    h1.afficher();

    Humain h2("Even");
    h2.afficher();

    return 0;
}



//exercice3
#include <iostream>
#include <string>
using namespace std;

class Zomb {
private:
    string nom;
public:
    Zomb(Humain* humain) {
        nom = "Zombie_" + humain->nom;
        cout << nom << " a été créé !" << endl;
    }
    Zomb* manger(Humain* humain) {
        cout << nom << " a mangé " << humain->nom << " !" << endl;
        return new Zomb(humain);
    }
    string getNom() {
        return nom;
    }
    void afficher() {
        cout << "Je suis un Zombie et je m'appelle " << nom << "." << endl;
    }
};

int main() {
    Humain* M;
    M = new Humain("Mika");
    Zomb* Z;
    Z= new Zomb(M);
    Z->afficher();


    Humain* F;
    F = new Humain("Fredy");

    Zomb* nouveauZomb = Z->manger(F);
    nouveauZomb->afficher();
    return 0;
}



//exercice 4
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class FinDuMonde {
private:
    vector<Humain*> humains;
    vector<Zomb*> zombies;
public:
    void ajouterHumain(Humain* humain) { humains.push_back(humain); }
    void debutDeLaFin() {
        srand(time(NULL));   int i = rand() % humains.size();  Humain* humainTransforme = humains[i];humains.erase(humains.begin() + i);
        zombies.push_back(new Zomb(humainTransforme));
    }
    bool faireUnPas() {
        if (humains.size() > 0 && zombies.size() > 0) {
            int i = rand() % zombies.size();
            Zomb* zombieQuiMange = zombies[i];
            i = rand() % humains.size();
            Humain* humainMange = humains[i];
            zombies.push_back(zombieQuiMange->manger(humainMange));
            humains.erase(humains.begin() + i);
            return true;
        }
        return false;
    }
    void fin() {
        int tours = 0;
        while (faireUnPas()) {
            tours++;
        }
        cout << "La fin du monde est arrivee en " << tours << " tours." << endl;
    }
};

int main() {
   //J'ai pas eu le temps de tester
   // Merci
    return 0;
}

