#include <iostream>
#include <string>
#include <cmath>
#include <vector>

//exercice 1

std::string getZombieName(std::string humanName) {
    // Initialise une chaîne de caractères pour stocker le nom du zombie
    std::string zombieName = "";

    // Mets la première lettre du nom de l'ancien humain en majuscule au nom du zombie
    zombieName += toupper(humanName[0]);

    // Mets 2 fois la première lettre du nom de l'ancien humain en minuscule au nom du zombie
    zombieName += std::string(2, tolower(humanName[0]));

    // Renvoie le nom du zombie
    return zombieName;
}

int main(int argc, char **argv) {
    // Demande à l'utilisateur d'entrer un nom
    std::cout << "Entrez un nom : ";
    std::string humanName;
    std::cin >> humanName;

    // La fonction getZombieName qui va nous permettre d'obtenir le nom du zombie
    std::string zombieName = getZombieName(humanName);

    // Affiche le nom de l'ancien humain et le nom du zombie qui correspond
    std::cout << "Le nom du zombie est : " << zombieName << std::endl;

    return 0;
}


// Exercice 2
#include <iostream>
#include <string>

using namespace std;

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
        cout << "Je m'appelle " << nom << endl;
    }
};

int main(int argc, char **argv) {
    // Instancier 2 objets de la classe Humain
    Humain h1("Yassine");
    Humain h2("Freddy");

    // Afficher les objets Humain créés
    h1.afficher();
    h2.afficher();

    return 0;
}

//exercice 3
#include <iostream>
#include <string>

class Humain {
public:
    Humain(std::string nom) : nom(nom) {}
    std::string getNom() const { return nom; }
private:
    std::string nom;
};

class Zombie {
public:
    Zombie(Humain* humain) : nom("Zombie " + humain->getNom()), humain(humain) {}
    std::string getNom() const { return nom; }
    Zombie* manger(Humain* humain) {
        std::cout << nom << " mange " << humain->getNom() << " !" << std::endl;
        return new Zombie(humain);
    }
    void afficher() const {
        std::cout << "Je m'appelles " << nom << "." << std::endl;
    }
private:
    std::string nom;
    Humain* humain;
};

int main(int argc, char **argv) {
    Humain* humain = new Humain("Even");
    std::cout << "Humain : " << humain->getNom() << std::endl;

    Zombie* zombie = new Zombie(humain);
    std::cout << "Zombie : ";
    zombie->afficher();

    Humain* victime = new Humain("Yassine");
    Zombie* nouveauZombie = zombie->manger(victime);
    std::cout << "Nom de zombe : ";
    nouveauZombie->afficher();

    delete humain;
    delete zombie;
    delete victime;
    delete nouveauZombie;

    return 0;
}



//exercice 4
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

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
    Zombie(Humain* humain) : humain(humain) {}
    string getNom() const { return humain->getNom(); }
private:
    Humain* humain;
};

class FinDuMonde {
public:
    FinDuMonde() {}
    void ajouterHumain(Humain* humain) { humains.push_back(humain); }
    void debutDeLaFin() {
        if (humains.empty()) {
            cout << "Pas d'humain, pas de zombie. Fin de la partie." << endl;
            return;
        }
        srand(time(nullptr));
        int indice = rand() % humains.size();
        Humain* humain = humains[indice];
        zombies.push_back(Zombie(humain));
        cout << humain->getNom() << " est devenue le premier zombie ! FUYEZ !" << endl;
    }
    void fin() {
        while (!humains.empty()) {
            for (Zombie& zombie : zombies) {
                if (humains.empty()) {
                    break;
                }
                int indice = rand() % humains.size();
                Humain* humain = humains[indice];
                cout << zombie.getNom() << " mange " << humain->getNom() << endl;
                humains.erase(humains.begin() + indice);
            }
        }
        cout << "Il n'y a pas de survivant !" << endl;
    }
private:
    vector<Humain*> humains;
    vector<Zombie> zombies;
};

int main(int argc, char **argv) {
    FinDuMonde finDuMonde;
    finDuMonde.ajouterHumain(new Humain("Yassine"));
    finDuMonde.ajouterHumain(new Humain("Freddy"));
    finDuMonde.ajouterHumain(new Humain("Even"));
    finDuMonde.ajouterHumain(new Humain("Moumine"));
    finDuMonde.ajouterHumain(new Humain("Kais"));
    finDuMonde.ajouterHumain(new Humain("Timéo"));
    finDuMonde.ajouterHumain(new Humain("Mika"));
    finDuMonde.ajouterHumain(new Humain("Gorane"));
    finDuMonde.ajouterHumain(new Humain("Martin"));
    finDuMonde.ajouterHumain(new Humain("Louis"));
    finDuMonde.debutDeLaFin();
    finDuMonde.fin();
    return 0;
}
