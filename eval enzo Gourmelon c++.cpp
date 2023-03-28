//
// Created by Enzo on 27/03/2023.
//ex 1
/*
 #include <string>
#include <iostream>
using namespace std;

string zombieName(string humanName) {
    string zombieName = "Zombie ";
    for (int i = 0; i < humanName.length(); i++) {
        char c = tolower(humanName[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            zombieName += tolower(c);
        }
    }
    if (zombieName.length() == 7) {
        zombieName = "Zombie";
    } else if (zombieName.length() == 6) {
        zombieName = "Zombie";
    }
    return zombieName;
}

int main() {
    string name1 = "Maurice";
    string name2 = "Romeo";
    cout << "Before: " << name1 << endl;
    cout << "Zombie name: " << zombieName(name1) << endl;
    cout << "Before: " << name2 << endl;
    cout << "Zombie name: " << zombieName(name2) << endl;
    return 0;
}

//ex2
#include <iostream>
#include <string>

class Humain {   //La classe Humain a un attribut privé nom de type string.
private:
    std::string nom;

public:
    Humain(std::string nom) { //Le constructeur Humain prend un paramètre nom de type string et l'utilise pour initialiser l'attribut nom.
        this->nom = nom;
    }

    std::string getNom() { //La méthode getNom() est un accesseur (ou getter) qui retourne la valeur de l'attribut nom.
        return nom;
    }

    void afficher() {  //La méthode afficher() affiche une chaîne de caractères dans la console contenant "Humain" et le nom de l'objet.
        std::cout << "Je suis un Humain nomme " << nom << std::endl;
    }
};

int main() {    //Dans la fonction main(), on crée deux objets humain1 et humain2 de la classe Humain en leur passant un nom comme paramètre pour le constructeur.
    Humain humain1("Alice");
    Humain humain2("Bob");

    humain1.afficher();
    humain2.afficher();

    return 0;
}

// ex 3
#include <iostream>
#include <string>

using namespace std;

class Humain {   //La classe Humain est définie avec un attribut nom et un constructeur prenant en paramètre le nom de l'Humain.
public:
    Humain(string nom) : nom(nom) {}
    string getNom() { return nom; }
private:
    string nom;
};

class Zombie { //La classe Zombie a un attribut nom de type string, un constructeur prenant en paramètre un pointeur vers un Humain et une méthode manger()
 //* prenant en paramètre un pointeur vers un Humain et en retournant un pointeur vers un nouveau Zombie créé à partir de l'Humain.
public:
    Zombie(Humain* humain) : nom(calculerNomZombie(humain->getNom())) {
        cout << "Creation d'un zombie nomme " << nom << " à partir de l'humain " << humain->getNom() << endl;
    }
//Lors de la création d'un Zombie à partir d'un Humain, la méthode calculerNomZombie() est appelée pour définir le nom du Zombie.
    Zombie* manger(Humain* humain) {
        cout << nom << " mange " << humain->getNom() << " et le transforme en zombie" << endl;
        return new Zombie(humain);
    }
//Lorsque la méthode manger() est appelée, le nom du Zombie est affiché, ainsi que le nom de l'Humain mangé. Ensuite, un nouveau Zombie est créé à partir de l'Humain mangé,
// (...) en appelant le constructeur de la classe Zombie.
    void afficher() {
        cout << "Je suis un zombie nomme " << nom << endl;
    }
//La méthode afficher affiche une chaîne de caractères contenant le nom du Zombie.
    string getNom() { return nom; }

private:
    string nom;

    string calculerNomZombie(string nomHumain) {
        return "Z" + nomHumain;
    }
};

int main() {
    // instanciation de l'humain
    Humain* humain = new Humain("Bob");
    cout << "Un humain nomme " << humain->getNom() << " a ete cree" << endl;

    // nstanciation d'un Zombie à partir de l'humain
    Zombie* zombie = new Zombie(humain);

    // Invocation de la méthode manger() du Zombie
    Zombie* nouveauZombie = zombie->manger(humain);

    // Affichage du nouveau Zombie
    nouveauZombie->afficher();

    delete humain;
    delete zombie;
    delete nouveauZombie;

    return 0;
}
 */
// ex 4
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Humain {
public:
    Humain(string n) : nom(n) {}
    string getNom() { return nom; }
private:
    string nom;
};

class Zombie {
public:
    Zombie(Humain* h) : humain(h) {}
    string getNom() { return humain->getNom() + " (zombie)"; }
private:
    Humain* humain;
};

class FinDuMonde {
public:
    FinDuMonde() : tour(0) {}
    void ajouterHumain(Humain* h) { humains.push_back(h); }
    void debutDeLaFin() {
        if (humains.empty()) return; // pas d'humain = pas de zombie
        srand(time(NULL)); // initialisation de rand
        int idx = rand() % humains.size(); // choix aléatoire d'un humain
        Humain* h = humains[idx];
        humains.erase(humains.begin() + idx); // suppression de l'humain transformé en zombie
        zombies.push_back(Zombie(h));
        tour++;
        cout << "Tour " << tour << " : " << h->getNom() << " se transforme en " << zombies.back().getNom() << endl;
    }
    void faireUnPas() {
        if (humains.empty()) return; // plus d'humain = fin du monde
        vector<Zombie> nouveauxZombies;
        for (auto& z : zombies) {
            if (humains.empty()) return; // plus d'humain = fin du monde
            int idx = rand() % humains.size(); // choix aléatoire d'un humain
            Humain* h = humains[idx];
            humains.erase(humains.begin() + idx); // suppression de l'humain mangé par le zombie
            nouveauxZombies.push_back(Zombie(h));
        }
        zombies.insert(zombies.end(), nouveauxZombies.begin(), nouveauxZombies.end());
        tour++;
    }
    void fin() {
        while (!humains.empty()) {
            faireUnPas();
        }
        cout << "La fin du monde est arrivee en " << tour << " tours." << endl;
    }
private:
    vector<Humain*> humains;
    vector<Zombie> zombies;
    int tour;
};