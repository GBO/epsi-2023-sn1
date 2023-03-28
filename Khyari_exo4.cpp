#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Humain {
public:
    string nom;

    Humain(string nom) : nom(nom) {}
};

class Zombie {
public:
    string nom;

    Zombie(string nom) : nom(nom) {}
};

class FinDuMonde {
private:
    vector<Humain *> listeHumains;
    vector<Zombie *> listeZombies;

public:
    void ajouterHumain(Humain *h) {
        listeHumains.push_back(h);
    }

    void debutDeLaFin() {
        srand(time(NULL));
        int i = rand() % listeHumains.size();
        Humain *premierHumain = listeHumains[i];
        listeZombies.push_back(new Zombie(premierHumain->nom));
        listeHumains.erase(listeHumains.begin() + i);
        cout << "Le premier zombie " << listeZombies[0]->nom << " est né." << endl;
    }

    void faireUnPas() {
        for (int i = 0; i < listeZombies.size(); i++) {
            if (listeHumains.size() == 0) {
                cout << "Il ne reste plus d'humains à manger." << endl;
                return;
            }
            int j = rand() % listeHumains.size();
            Humain *humainMange = listeHumains[j];
            listeHumains.erase(listeHumains.begin() + j);
            cout << listeZombies[i]->nom << " a mangé " << humainMange->nom << "." << endl;
        }
    }

    void fin() {
        while (listeHumains.size() > 0) {
            faireUnPas();
        }
        cout << "La fin du monde est arrivée." << endl;
    }
};

int main() {
    string prenoms[216] = {"Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste",
                           "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre",
                           "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan",
                           "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub",
                           "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex",
                           "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume",
                           "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne",
                           "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard",
                           "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor",
                           "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca",
                           "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot",
                           "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara",
                           "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea",
                           "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines",
                           "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys",
                           "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara",
                           "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny",
                           "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle",
                           "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra",
                           "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise",
                           "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana",
                           "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya",
                           "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia",
                           "Elea", "Anaelle", "Alyssa", "Ilona", "Aya"};
    FinDuMonde finDuMonde;
    for (int i = 0; i < 10; i++) {
        finDuMonde.ajouterHumain(new Humain(prenoms[i]));
    }
    finDuMonde.debutDeLaFin();
    finDuMonde.fin();
    return 0;
}

