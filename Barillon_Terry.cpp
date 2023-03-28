#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// écrire une fonction permettant de calculer le nom d'un Zombie
// prend en paramètres un string, retourne un string

string calculer_nom_zombie(string nom_humain) {
    int i;
    string nom_zombie = "ntr";
    for (i=0; i!=3; i=i+1)  {
        nom_zombie[i] = nom_humain[0];
    }
    return string(nom_zombie);
}

// écrire une classe Humain avec un attribut nom, et un constructeur prenant un paramètre pour le nom.
// attribut privé nom-string / accesseur/getter
// méthode afficher()

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

//
// écrire une classe zombie avec un attribut nom, et un constructeur prenant un Humain en paramètre
//

class Zombie {
private:
    string nom;

public:
    Zombie(Humain* humain) {
        nom = "Zombie " + calculer_nom_zombie(humain->getNom());
    }

    Zombie* manger(Humain* humain) {
        cout << nom << " mange " << humain->getNom() << endl;
        return new Zombie(humain);
    }

    void afficher() {
        cout << nom << endl;
    }

    string getNom() {
        return nom;
    }
};

//
//exercice 4
//

class FinDuMonde {
private:
    vector<Humain*> humains;
    vector<Zombie*> zombies;
public:
    void ajouterHumain(Humain* humain) {
        // ajouter un humain
        humains.push_back(humain);
    }

    void debutDeLaFin(Zombie, Humain) {
        int index = rand() % humains.size();
        Humain* humain = humains[index];

        Zombie* zombie = new Zombie(humain);
        zombies.push_back(zombie);

        humains.erase(humains.begin() + index);

        cout << "Le premier Zombie est " << zombie->getNom() << "." << endl;
    }

    void faireUnPas() {
        for (int i = 0; i < zombies.size(); i++) {
            // Pour autant de zombies présents
            Zombie* zombie = zombies[i];

            if (humains.empty()) {
                // permet de savoir si il reste des humains ou non.
                cout << "Il n'y a plus d'humains sur Terre, la fin du monde est arrivée" << endl;
            }

            else {
                // Nous choisissons un humain au hasard dans la liste car pas de jaloux
                int index = rand() % humains.size();
                Humain* humain = humains[index];

                // Il se fait mordre et devient donc un zombie, lui permettant de rentrer dans la liste
                zombies.push_back(zombie->manger(humain));

                // Il n'est plus humain donc  nous le supprimons de la liste des humains
                humains.erase(humains.begin() + index);
            }
        }
    }

    void fin() {
        // les manches continues de s'enchaîner jusqu'a la fin du monde
        while (true) {
            faireUnPas();
        }
    }
};

//
//
//
int main(){
    // exercice 1

    string prenom1 = "Maurice";
    string prenom2 = "Romeo";
    cout << "Nom humain : " << prenom1 << "  ->  Nom zombie : " << calculer_nom_zombie(prenom1) << endl;
    cout << "Nom humain : " << prenom2 << "   ->  Nom zombie : " << calculer_nom_zombie(prenom2) << endl;

    // exercice 2
    cout << "------------------------------" << endl;
    //

    Humain humain1("Terry");
    Humain humain2("Barillon");

    humain1.afficher();
    humain2.afficher();

    // exercice 3
    cout << "------------------------------" << endl;
    //

    Humain* humain = new Humain("Bob");
    Zombie* zombie = new Zombie(humain);

    zombie->afficher();
    humain->afficher();

    Zombie* nouveauZombie = zombie->manger(humain);
    nouveauZombie->afficher();

    delete humain;
    delete zombie;
    delete nouveauZombie;

    //exercice 4
    cout << "------------------------------" << endl;
    //

    srand(time(NULL));
    FinDuMonde finDuMonde;
    string prenoms[216] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia", "Elea", "Anaelle", "Alyssa", "Ilona", "Aya" };

    ddeub

    return 0;
}

