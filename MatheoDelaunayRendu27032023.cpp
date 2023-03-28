#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string calculerNomZombie(string nomHumain) {
    string nomZombie = "";
    nomZombie += toupper(nomHumain[0]);
    nomZombie += tolower(nomHumain[0]);
    nomZombie += tolower(nomHumain[0]);
    return nomZombie;
}
/*
int main() {
    string nomHumain1 = "Théo";
    string nomZombie1 = calculerNomZombie(nomHumain1);
    cout << nomHumain1 << " se transforme en Zombie \"" << nomZombie1 << "\"" << endl;

    string nomHumain2 = "Alban";
    string nomZombie2 = calculerNomZombie(nomHumain2);
    cout << nomHumain2 << " se transforme en Zombie \"" << nomZombie2 << "\"" << endl;

    return 0;
}

*/

                                                //Exercice 2

/*
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
        cout << "Je suis un Humain nommé " << nom << endl;
    }
};

int main() {
    Humain humain1("Théo");
    Humain humain2("Alban");

    humain1.afficher();
    humain2.afficher();

    return 0;
}
*/


//Exercice 3



/*

class Humain {
private:
    string nom;
public:
    Humain(string n) : nom(n) {}
    string getNom() const { return nom; }
};


class Zombie {
private:
    string nom;
public:
    Zombie(Humain* h) : nom(calculerNomZombie(h->getNom())) {
        cout << "Zombie " << nom << " créé à partir de l'Humain " << h->getNom() << endl;
    }
    string getNom() const { return nom; }
    Zombie* manger(Humain* h) {
        cout << "Zombie " << nom << " mange " << h->getNom() << " et le transforme en Zombie." << endl;
        return new Zombie(h);
    }
    void afficher() {
        cout << "Je suis un Zombie nommé " << nom << endl;
    }
};

int main() {
    Humain h("Théo");
    Zombie* z1 = new Zombie(&h);
    z1->afficher();
    Humain* h2 = new Humain("Alban");
    Zombie* z2 = z1->manger(h2);
    z2->afficher();
    return 0;
}
*/


                                                            //Exercice 4

/*
class Humain {
public:
    Humain(string n) : nom(n) {}
    string getNom() const { return nom; }
private:
    string nom;
};

class Zombie {
public:
    Zombie(string nom) : nom(nom) {}
    string getNom() const { return nom; }

private:
    string nom;
};


class FinDuMonde {
public:
    FinDuMonde() : nbHumains(0), nbZombies(0) {}
    void ajouterHumain(Humain* h) { humains.push_back(h); nbHumains++; }
    void debutDeLaFin() {
        srand(time(NULL)); // Initialisation du générateur aléatoire
        int index = rand() % nbHumains; // Choix aléatoire d'un Humain
        Zombie* z = new Zombie(humains[index]->getNom()); // Transformation en Zombie
        zombies.push_back(z);
        nbZombies++;
        delete humains[index]; // Retrait de l'Humain de la liste
        humains.erase(humains.begin() + index);
        nbHumains--;
    }
    void fin() {
        int tour = 1;
        while (nbHumains > 0) {
            cout << "Tour " << tour << " : " << nbZombies << " zombies contre " << nbHumains << " humains" << endl;
            for (int i = 0; i < nbZombies; i++) {
                if (nbHumains == 0) break; // Arrêt de la boucle si tous les Humains sont morts
                int index = rand() % nbHumains; // Choix aléatoire d'un Humain
                cout << "    " << zombies[i]->getNom() << " mange " << humains[index]->getNom() << endl;
                delete humains[index]; // Retrait de l'Humain de la liste
                humains.erase(humains.begin() + index);
                nbHumains--;
            }
            tour++;
        }
        cout << "Fin du monde ! Tous les Humains ont été transformés en zombies en " << tour - 1 << " tours." << endl;
    }
private:
    vector<Humain*> humains;
    vector<Zombie*> zombies;
    int nbHumains, nbZombies;
};
int main() {
// Déclaration sur une ligne :
    string prenoms[216] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia", "Elea", "Anaelle", "Alyssa", "Ilona", "Aya" };    FinDuMonde fdm;
    for (int i = 0; i < 10; i++) {
        fdm.ajouterHumain(new Humain(prenoms[i]));
    }
    fdm.debutDeLaFin();
    fdm.fin();
    return 0;
}
*/