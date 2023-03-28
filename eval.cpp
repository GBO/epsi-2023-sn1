#include <iostream>

#include <ctime>

#include <cstdlib>

#include <string>

#include <vector>


//exo1//


class Zombie{
private:
    string nomhumain
public:
    string afficher (){
        cout<< nomhumain[0]<< tolower (nomhumain)<<endl;
    }

    std::string nomZombie(std::string nomHumain) {
        std::string nomZombie = "";
        for (char& c : nomHumain) {

                    nomZombie += "r";
                    nomZombie += "R";
            }
        }
        nomZombie += "rrr";
    return nomZombie;
    }

int main(){

        std::string nomHumain1 = "Maurice";
        std::string nomHumain2 = "Roméo";
        std::cout << "Nom d'humain 1 : " << nomHumain1 << std::endl;
        std::cout << "Nom de zombie 1 : " << nomZombie(nomHumain1) << std::endl;
        std::cout << "Nom d'humain 2 : " << nomHumain2 << std::endl;
        std::cout << "Nom de zombie 2 : " << nomZombie(nomHumain2) << std::endl;

        Nom d'humain 1 : Maurice
        Nom de zombie 1 : Mrrrr
        Nom d'humain 2 : Roméo
        Nom de zombie 2 : Rrrrr

        return 0;
    }

//exo2//

class Humain {
public:
    Humain(std::string nom);
    std::string getNom() const;
    void afficher() const;

private:
    std::string nom;
};

Humain::Humain(std::string nom) {
    this->nom = nom;
}

std::string Humain::getNom() const {
    return nom;
}

void Humain::afficher() const {
    std::cout << "Je suis un Humain nommé " << nom << "." << std::endl;
}

int main() {
    Humain h1("Alice");
    Humain h2("Bob");

    h1.afficher();
    h2.afficher();

    return 0;
}


//exo3//

// Déclaration anticipée de la classe Humain
class Humain;

class Zombie {
public:
    Zombie(Humain* humain);
    std::string getNom() const;
    void afficher() const;
    Zombie* manger(Humain* humain);

private:
    std::string nom;
};

class Humain {
public:
    Humain(std::string nom);
    std::string getNom() const;
    void afficher() const;

private:
    std::string nom;
};

Humain::Humain(std::string nom) {
    this->nom = nom;
}

std::string Humain::getNom() const {
    return nom;
}

void Humain::afficher() const {
    std::cout << "Je suis un Humain nommé " << nom << "." << std::endl;
}

Zombie::Zombie(Humain* humain) {

    // Appel de la fonction pour calculer le nom du Zombie
    std::string nomZombie = "";
    std::string nomHumain = humain->getNom();
    for (char c : nomHumain) {
        switch (c) {
            case 'a':
                nomZombie += "a";
                break;
            case 'e':
                nomZombie += "e";
                break;
            case 'i':
                nomZombie += "i";
                break;
            case 'o':
                nomZombie += "o";
                break;
            case 'u':
                nomZombie += "u";
                break;
            default:
                break;
        }
    }
    nom = nomZombie;
}

std::string Zombie::getNom() const {
    return nom;
}

void Zombie::afficher() const {
    std::cout << "Je suis un Zombie nommé " << nom << "." << std::endl;
}

Zombie* Zombie::manger(Humain* humain) {

    // Création d'un nouveau Zombie avec le nom du Humain mangé
    Zombie* nouveauZombie = new Zombie(humain);

    // Affichage dans la console
    std::cout << "Le Zombie " << nom << " mange l'Humain " << humain->getNom() << " et devient " << nouveauZombie->getNom() << "." << std::endl;

    // Retour du nouveau Zombie
    return nouveauZombie;
}

int main() {
    Humain* h = new Humain("Alice");
    h->afficher();

    Zombie* z = new Zombie(h);
    z->afficher();

    Zombie* nouveauZombie = z->manger(h);
    nouveauZombie->afficher();

    delete h;
    delete z;
    delete nouveauZombie;

    return 0;
}

//exo4//

using namespace std;

// Classe Humain
class Humain {
public:

    // Constructeur
    Humain(string nom) {
        this->nom = nom;
    }

    // Accesseur
    string getNom() const {
        return nom;
    }
private:
    string nom;
};

// Classe Zombie
class Zombie {
public:

    // Constructeur
    Zombie(Humain* humain) {
        this->nom = calculerNomZombie(humain->getNom());
        cout << "Nouveau Zombie : " << nom << endl;
    }

    // Accesseur
    string getNom() const {
        return nom;
    }

    // Méthode manger
    Zombie* manger(Humain* humain) {
        cout << nom << " mange " << humain->getNom() << endl;
        return new Zombie(humain);
    }
private:
    string nom;
    string calculerNomZombie(string nomHumain) {
        string nomZombie = "";
        for (int i = 0; i < nomHumain.length(); i++) {
            switch (nomHumain[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    nomZombie += tolower(nomHumain[i]);
                    break;
                default:
                    nomZombie += 'r';
                    break;
            }
        }
        nomZombie += 'h';
        return nomZombie;
    }
};

// Classe FinDuMonde
class FinDuMonde {
public:

    // Constructeur
    FinDuMonde() {}

    // Méthode ajouterHumain
    void ajouterHumain(Humain* humain) {
        humains.push_back(humain);
    }

    // Méthode debutDeLaFin
    void debutDeLaFin() {
        srand(time(0));            // initialisation de rand avec le temps
        int indice = rand() % humains.size();           // choix aléatoire d'un humain
        Humain* humain = humains[indice];
        humains.erase(humains.begin() + indice);         // suppression de l'humain de la liste
        zombies.push_back(new Zombie(humain));           // transformation de l'humain en zombie
    }
    // Méthode fin
    void fin() {
        int tour = 1;
        while (!humains.empty()) {            // tant qu'il reste des humains
            cout << "Tour " << tour << " : " << humains.size() << " Humains, " << zombies.size() << " Zombies" << endl;
            for (int i = 0; i < zombies.size(); i++) {          // chaque zombie mange un humain
                int indice = rand() % humains.size();
                Humain* humain = humains[indice];
                humains.erase(humains.begin() + indice);
                Zombie* nouveauZombie = zombies[i]->manger(humain);
                zombies.push_back(nouveauZombie);
            }
            zombies.erase(zombies.begin(), zombies.begin() + zombies.size() / 2);        // suppression des zombies les plus anciens
            tour++;
        }
        cout << "Fin du monde en " << tour - 1 << " tours !" << endl;
    }
private:
    vector<Humain*> humains;
    vector<Zombie*> zombies;
};



