#include <iostream>
#include <string>
#include <ctype.h> // nécessaire pour la fonction tolower()

using namespace std;

string nomZombie(string nomHumain) {
    string nomZombie = "Zombie ";

    // Pour chaque caractère du nom de l'Humain, on ajoute le son correspondant à celui du Zombie
    for(int i = 0; i < nomHumain.length(); i++) {
        char c = tolower(nomHumain[i]);
        switch(c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'r':
                nomZombie += 'r'; // le son commun à tous les Zombies
                break;
            case 'b':
            case 'd':
            case 'h':
            case 'k':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                nomZombie += toupper(c); // le caractère en majuscule
                break;
            default:
                nomZombie += 'm'; // le son par défaut
                break;
        }
        nomZombie += 'm';
    }

    return nomZombie;
}


class Humain {
private:
    std::string nom;

public:
    Humain(std::string nom) {
        this->nom = nom;
    }

    std::string getNom() {
        return nom;
    }

    void afficher() {
        std::cout << "Je suis un Humain nommé " << nom << std::endl;
    }
};

int main() {

    Humain h1("Alice");
    Humain h2("Bob");

    h1.afficher();
    h2.afficher();

    return 0;
}
