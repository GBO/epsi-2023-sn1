#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Exercice 1
string calculNomZombie(string humanName) {
    char premierelettre = humanName[0];
    string zombieName(3, premierelettre); // répète la première lettre 3 fois
    return zombieName;
}

// Exercice 2
class Humain {
private:
    string nom;
public:
    Humain(string nom) {
        this->nom = nom;
    }
    string getNom() {
        return nom;
    }
    void afficher() {
        cout << "Je suis un Humain, mon nom est " << nom << "." << endl;
    }
};

// Exercice 3
class Zombie {
private:
    string nom;
public:
    Zombie(Humain* humain) {
        string nomHumain = humain->getNom();
        nom = "Z" + calculNomZombie(nomHumain);
        cout << "Le Zombie " << nom << " vient de manger " << nomHumain << "." << endl;
        delete humain;
    }
    string getNom() {
        return nom;
    }
    Zombie* manger(Humain* humain) {
        Zombie* nouveauZombie = new Zombie(humain);
        return nouveauZombie;
    }
    void afficher() {
        cout << "Je suis un Zombie, mon nom est " << nom << "." << endl;
    }
};

// Exercice 4
class FinDuMonde {
private:
    vector<Humain*> listeHumains;
    vector<Zombie*> listeZombies;
public:
    void ajouterHumain(Humain* humain) {
        listeHumains.push_back(humain);
    }
    void debutDeLaFin() {
        Humain* premierHumain = listeHumains.front();
        listeHumains.erase(listeHumains.begin());
        Zombie* premierZombie = new Zombie(premierHumain);
        listeZombies.push_back(premierZombie);
    }
    void faireUnPas() {
        for (vector<Zombie*>::iterator it = listeZombies.begin(); it != listeZombies.end(); ++it) {
            Zombie* zombie = *it;
            if (!listeHumains.empty()) {
                Humain* humainAManger = listeHumains.front();
                listeHumains.erase(listeHumains.begin());
                Zombie* nouveauZombie = zombie->manger(humainAManger);
                listeZombies.push_back(nouveauZombie);
            }
        }
    }
    void fin() {
        while (!listeHumains.empty()) {
            faireUnPas();
        }
        cout << "La fin du monde est arrivée après " << listeZombies.size() << " tours." << endl;
    }
};

// Tests
int main() {
    // Exercice 1
    cout << "Exercice 1 :" << endl;
    string nom1 = "Paul";
    string nom2 = "Titouan";
    cout << "Nom d'origine : " << nom1 << ", nom de Zombie : " << calculNomZombie(nom1) << endl;
    cout << "Nom d'origine : " << nom2 << ", nom de Zombie : " << calculNomZombie(nom2) << endl;

    //Exercice 2
    cout << "Exercice 2 :" << endl;
    Humain h1("Paul");
    Humain h2("Titouan");
    h1.afficher();
    h2.afficher();

    //Exercice 3
    cout << "Exercice 3 :" << endl;
    Humain h3("Paul");
    Zombie* z1 = new Zombie(&h1);
    Humain h4("Titouan");
    Zombie* z2 = z1->manger(&h2);
    z2->afficher();
    
    //Exercice 4
    cout << "Exercice 4 :" << endl;
    vector<Humain*> population;
    for (int i = 0; i < 10; i++) {
        population.push_back(new Humain("Humain " + to_string(i)));
    }
    FinDuMonde finDuMonde;
    for (int i = 0; i < population.size(); i++) {
        finDuMonde.ajouterHumain(population[i]);
    }
    finDuMonde.debutDeLaFin();
    finDuMonde.fin();
    cout << "La fin du monde a eu lieu en 1 tour." << endl;
    return 0;
}