#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // pour rand()
#include <ctime> // pour time()
using namespace std;
// Pensez = bien enlever les /* et */ entre chaques exercices pour pouvoir les tester


/*
string getZombieName(const string & humanName) {
    string zombieName = "Zombie ";
    for (char c : humanName) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                zombieName += 'm';
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                zombieName += 'M';
                break;
            default:
                zombieName += 'r';
                break;
        }
    }
    return zombieName;
}

int main() {
    cout << "Exercice 1" <<endl;
    string human1 = "Maurice";
    string human2 = "Roméo";

    cout << "Human name: " << human1 << endl;
    cout << "Zombie name: " << getZombieName(human1) << endl;

    cout << "Human name: " << human2 << endl;
    cout << "Zombie name: " << getZombieName(human2) << endl;

    return 0;
}
*/

/*
class Humain {
private:
    string nom;

public:
    Humain(string nom) {
        this->nom = nom;
    }

    string getNom() const {
        return nom;
    }

    void afficher() const {
        cout << "Je suis bien un Humain Francais, mon nom est " << nom << endl;
    }
};

int main() {
    cout << "Exercice 2" <<endl;
    Humain h1("Alice");
    Humain h2("Bob");

    h1.afficher();
    h2.afficher();

    return 0;
}
*/

/*
using namespace std;

class Humain {
public:
    Humain(string nom) : nom(nom) {}
    string getNom() const { return nom; }
private:
    string nom;
};

class Zombie {
public:
    Zombie(Humain* humain) : nom(calculerNomZombie(humain)), humain(humain) {}
    string getNom() const { return nom; }
    Zombie* manger(Humain* humain) {
        cout << "Le Zombie " << nom << " mange " << humain->getNom() << endl;
        return new Zombie(humain);
    }
    void afficher() const {
        cout << "Je suis un Zombie nommé " << nom << endl;
    }
private:
    string nom;
    Humain* humain;
    string calculerNomZombie(Humain* humain) {
        return "Zombie de " + humain->getNom();
    }
};

int main() {
    cout << "Exercice 3" <<endl;
    Humain* humain1 = new Humain("Bob");
    cout << "Le nom de l'Humain est : " << humain1->getNom() << endl;

    Zombie* zombie1 = new Zombie(humain1);
    zombie1->afficher();

    Humain* humain2 = new Humain("Alice");
    Zombie* zombie2 = zombie1->manger(humain2);
    zombie2->afficher();

    delete humain1;
    delete humain2;
    delete zombie1;
    delete zombie2;

    return 0;
}
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Humain {
public:
    Humain() {}
    ~Humain() {}
};

class Zombie {
public:
    Zombie() {}
    ~Zombie() {}
};

class FinDuMonde {
public:
    FinDuMonde() {
        srand(time(nullptr)); // Initialisation de la graine aléatoire pour choisir le premier zombie
    }
    ~FinDuMonde() {}

    void ajouterHumain(Humain* h) {
        humains_.push_back(h);
    }

    void debutDeLaFin() {
        // Choisir un humain aléatoire dans la liste pour le transformer en zombie
        int index = rand() % humains_.size();
        Humain* h = humains_[index];
        humains_.erase(humains_.begin() + index);
        zombies_.push_back(new Zombie());
        cout << "Un humain est transformé en zombie !" << endl;
    }

    void fin() {
        while (!humains_.empty()) {
            for (Zombie* z : zombies_) {
                if (!humains_.empty()) {
                    // Choisir un humain aléatoire dans la liste pour le manger
                    int index = rand() % humains_.size();
                    Humain* h = humains_[index];
                    humains_.erase(humains_.begin() + index);
                    cout << "Un zombie mange un humain !" << endl;
                }
            }
        }
        cout << "Fin du monde : tous les humains ont été mangés !" << endl;
    }

private:
    vector<Humain*> humains_;
    vector<Zombie*> zombies_;
};

int main() {
    cout << "Exercice 4 " <<endl;
    // Initialisation de la population d'humains
    FinDuMonde fdm;
    for (int i = 0; i < 10; ++i) {
        fdm.ajouterHumain(new Humain());
    }

    // Début de la fin : choisir un premier zombie
    fdm.debutDeLaFin();

    // Lancement de la fin du monde
    fdm.fin();

    return 0;
}




