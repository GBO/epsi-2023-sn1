#include <iostream>
#include <string>
#include "vector"

using namespace std;

string nom_zombie(string nom_humain) {
    string nom_zombie = "";
    char premiere_lettre = nom_humain[0];

    // Génération du nom de zombie en fonction de la première lettre du nom d'humain
    switch (premiere_lettre) {
        case 'A':
        case 'a':
            nom_zombie = "Aaa";
            break;
        case 'B':
        case 'b':
            nom_zombie = "Bbb";
            break;
        case 'C':
        case 'c':
            nom_zombie = "Ccc";
            break;
        case 'D':
        case 'd':
            nom_zombie = "Ddd";
            break;
        case 'E':
        case 'e':
            nom_zombie = "Eee";
            break;
        case 'F':
        case 'f':
            nom_zombie = "Fff";
            break;
        case 'G':
        case 'g':
            nom_zombie = "Ggg";
            break;
        case 'H':
        case 'h':
            nom_zombie = "Hhh";
            break;
        case 'I':
        case 'i':
            nom_zombie = "Iii";
            break;
        case 'J':
        case 'j':
            nom_zombie = "Jjj";
            break;
        case 'K':
        case 'k':
            nom_zombie = "Kkk";
            break;
        case 'L':
        case 'l':
            nom_zombie = "Lll";
            break;
        case 'M':
        case 'm':
            nom_zombie = "Mmm";
            break;
        case 'N':
        case 'n':
            nom_zombie = "Nnn";
            break;
        case 'O':
        case 'o':
            nom_zombie = "Ooo";
            break;
        case 'P':
        case 'p':
            nom_zombie = "Ppp";
            break;
        case 'Q':
        case 'q':
            nom_zombie = "Qqq";
            break;
        case 'R':
        case 'r':
            nom_zombie = "Rrr";
            break;
        case 'S':
        case 's':
            nom_zombie = "Sss";
            break;
        case 'T':
        case 't':
            nom_zombie = "Ttt";
            break;
        case 'U':
        case 'u':
            nom_zombie = "Uuu";
            break;
        case 'V':
        case 'v':
            nom_zombie = "Vvv";
            break;
        case 'W':
        case 'w':
            nom_zombie = "Www";
            break;
        case 'X':
        case 'x':
            nom_zombie = "Xxx";
            break;
        case 'Y':
        case 'y':
            nom_zombie = "Yyy";
            break;
        case 'Z':
        case 'z':
            nom_zombie = "Zzz";
            break;
        default:
            nom_zombie = "Zombie Inconnu";
            break;
    }

    return nom_zombie;
}

class Humain {
private:
    string nom;

public:
    Humain(string nom) : nom(nom) {}

    string getNom() const {
        return nom;
    }

    void afficher() const {
        cout << "Je suis un Humain, mon nom est " << nom << "." << endl;
    }
};

class Zombie {
private:
    string nom;
public:
    Zombie(Humain* humain) {
        nom = "Zombie " + humain->getNom() + " ";
        cout << "Création du Zombie " << nom << endl;
    }
    string getNom() {
        return nom;
    }
    Zombie* manger(Humain* humain) {
        cout << nom << " mange " << humain->getNom() << endl;
        return new Zombie(humain);
    }
    void afficher() {
        cout << "Je suis " << nom << endl;
    }
};

class FinduMonde {
private:
    vector<Humain*> humain;
    vector<Zombie*> zombie;
public:
    void ajouterHumain(Humain* humain1) {
        humain.push_back(humain1);
    }
    void debutDeLaFin() {
        if (!humain.empty()) {
            //Je ne comprends pas ce qui ne va pas dans la ligne du dessous
        Zombie* zombie1 = new Zombie(humain[0]->getNom());
            zombie.push_back(zombie1);
            humain.erase(humain.begin());
        }
    }
    void fin() {
        while (!humain.empty()) {
            for (int i = 0; i < zombie.size(); i++) {
                if (humain.empty()) {
                    break;
                }
                humain.erase(humain.begin());
            }
        }
    }
};
int main(int argc, char **argv) {

//    cout << "Exercice 1: " << endl;
//


// Je ne comprends pas le problème dans l'exercice donc je le passe en commentaires.

//    string nom_humain = "Maurice";
//    string nom_zombie = nom_zombie(nom_humain);
//    cout << "Nom d'humain : " << nom_humain << endl;

    cout << "Exercice 2: " << endl;

    Humain h1("Franck");
    Humain h2("Patricia");

    h1.afficher();
    h2.afficher();

    cout << "Exercice 3: " << endl;

    // Instancier un Zombie et l’afficher dans la console.
    Humain* humain = new Humain("Jean");
    Zombie* zombie = new Zombie(humain);
    zombie->afficher();
    cout << endl;

    // Instancier un Humain et l’afficher dans la console.
    Humain* humain2 = new Humain("Marie");
    cout << "Création de l'Humain " << humain2->getNom() << endl;
    cout << endl;

    // Invoquer la méthode manger du Zombie avec l’Humain en paramètre.
    Zombie* nouveauZombie = zombie->manger(humain2);
    cout << endl;

    // Afficher le nouveau Zombie (résultat de la méthode manger).
    nouveauZombie->afficher();



    cout << "Exercice 4 : " << endl;




    return 0;
}