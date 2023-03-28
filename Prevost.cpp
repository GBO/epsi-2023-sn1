/*
//Exercice 1
#include <iostream>
#include <string>
using namespace std;
std::string humainToZombie(std::string name) {
    std::string zombieName = "";
    for (char c : name) {
        switch (c) {
            case 'a':
            case 'A':
                zombieName += "ra";
                break;
            case 'o':
            case 'O':
                zombieName += "rorr";
                break;
            case 'u':
            case 'U':
                zombieName += "grrr";
                break;
            default:
                zombieName += c;
                break;
            case 'g':
            case 'G':
                zombieName += "grgr";
                break;
            case 'h':
            case 'H':
                zombieName += "Hhh";
                break;
            case 'r':
            case 'R':
                zombieName += "rrr";
                break;
            case 's':
            case 'S':
                zombieName += "Sss";
                break;
        }
    }
    return zombieName;
}

int main() {
    std::string name1 = "Hugo";
    std::string name2 = "Sara";
    std::cout << "Nom d'origine: " << name1 << std::endl;
    std::cout << "Nom de Zombie: " << humainToZombie(name1) << std::endl;
    std::cout << "Nom d'origine: " << name2 << std::endl;
    std::cout << "Nom de Zombie: " << humainToZombie(name2) << std::endl;
    return 0;
}
*/

/*
//Exercice 2
#include<iostream> // bibliothèque d'entrée-sortie standard
#include<string> // bibliothèque de chaînes de caractères
using namespace std;

class Humain { // Définition de la classe Humain
private:
    string nom; // Attribut privé de la classe Humain

public:
    Humain(string n) { // Constructeur prenant un paramètre pour le nom
        nom = n; // Assigner la valeur du paramètre à l'attribut nom de la classe Humain
    }

    string getNom() { // Accesseur / getter : méthode qui retourne la valeur de l'attribut nom
        return nom;
    }

    void afficher() { // Méthode publique permettant d'afficher le nom complet de l'humain
        cout << "Humain " << nom << endl; // Affichage dans la console avec le nom de l'objet courant
    }
};

int main() { // Fonction principale
    Humain h1("Sylvain"); // Instanciation d'un objet h1 de la classe Humain avec le nom "Alice"
    Humain h2("Jade"); // Instanciation d'un objet h2 de la classe Humain avec le nom "Bob"

    h1.afficher(); // Appel de la méthode afficher() pour l'objet h1
    h2.afficher(); // Appel de la méthode afficher() pour l'objet h2

    return 0; // Fin du programme
}
*/

/*
//Exercice 3
#include <iostream>
#include <string>

class Humain {
public:
    Humain(const std::string& name) : m_name(name) {}

    const std::string& getName() const { return m_name; }

private:
    std::string m_name;
};

class Zombie {
public:
    Zombie(Humain* human)
            : m_name(calculateZombieName(human->getName()))
    {
        std::cout << "Le Zombie " << " mange " << human->getName() << "." << std::endl;
    }

    const std::string& getName() const { return m_name; }

    Zombie* manger(Humain* human) {
        std::cout << m_name << " mange " << human->getName() << " et devient un Zombie."<< std::endl;
        return new Zombie(human);
    }

    void afficher() const {
        std::cout << "Il devient " << m_name << "." << std::endl;
    }

private:
    std::string m_name;

    std::string calculateZombieName(const std::string& humanName) {
        // Code pour calculer le nom du zombie
        return "Zombie_" + humanName;
    }
};

int main() {
    Humain human("John");
    std::cout << " Humain " << human.getName() << "." << std::endl;
    Zombie* zombie = new Zombie(&human);

    zombie->afficher();
    std::cout << " grrr " << "." << std::endl;

    Humain human2("Alice");
    Zombie* newZombie = zombie->manger(&human2);
    std::cout << " Humain " << human2.getName() << "." << std::endl;

    newZombie->afficher();

    delete zombie;
    delete newZombie;

    return 0;
}
*/

//Exercice 4

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Humain {
public:
    Humain(const string& nom = "") : m_nom(nom) {}
    const string& getNom() const { return m_nom; }
private:
    string m_nom;
};

class Zombie : public Humain {};

class FinDuMonde {
private:
    vector<Humain*> humains;
    vector<Zombie*> zombies;

public:
    void ajouterHumain(Humain *h) {
        humains.push_back(h);
    }

    void debutDeLaFin() {
        if (!humains.empty()) {
            srand(time(NULL));
            int i = rand() % humains.size(); // choisir un Humain au hasard
            Humain *h = humains[i];
            humains.erase(humains.begin() + i); // retirer l'Humain de la liste
            Zombie *z = new Zombie();
            zombies.push_back(z); // créer et ajouter un Zombie à la liste
            cout << "Le premier Zombie est apparu ! Il a transforme un Humain en Zombie !" << endl;
        } else {
            cout << "Il n'y a pas d'Humain dans la liste." << endl;
        }
    }

    void fin() {
        int tour = 1;
        while (!humains.empty()) {
            cout << "Tour " << tour << " : " << endl;
            for (auto z : zombies) {
                if (!humains.empty()) {
                    int i = rand() % humains.size(); // choisir un Humain au hasard
                    Humain *h = humains[i];
                    humains.erase(humains.begin() + i); // retirer l'Humain de la liste
                    cout << "Un Zombie mange un Humain !" << endl;
                }
            }
            tour++;
        }
        cout << "Il n'y a plus d'Humain dans la liste. La fin du monde est arrivee en " << tour - 1 << " tours." << endl;
    }

    ~FinDuMonde() {
        // libérer la mémoire allouée pour les Zombies
        for (auto z : zombies) {
            delete z;
        }
    }
};

int main() {
    string prenoms[216] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia", "Elea", "Anaelle", "Alyssa", "Ilona", "Aya" };
    FinDuMonde fdm;
    for (int i = 0; i < 10; i++) {
        int index = rand() % 216;
        fdm.ajouterHumain(new Humain(prenoms[index]));
        Humain *h = new Humain();
        fdm.ajouterHumain(h);
    }
    fdm.debutDeLaFin();
    fdm.fin();
    return 0;
}