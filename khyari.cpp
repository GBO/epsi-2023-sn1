#include <iostream>
#include <string>
#include <vector>

using namespace std;


string nomzombie(const string &nomhumain) {
    string zombie;

    // Converti le nom humain en majuscule
    string majuscule;
    for (char c: nomhumain) {
        majuscule += toupper(c);
    }

    // Cherche la premiere lettre du nom humain
    char premiereLettre = majuscule[0];
    switch (premiereLettre) {
        case 'A':
            zombie = "Aaa";
            break;
        case 'B':
            zombie = "Bbb";
            break;
        case 'C':
            zombie = "Ccc";
            break;
        case 'D':
            zombie = "Ddd";
            break;
        case 'E':
            zombie = "Eee";
            break;
        case 'F':
            zombie = "Fff";
            break;
        case 'G':
            zombie = "Ggg";
            break;
        case 'H':
            zombie = "Hhh";
            break;
        case 'I':
            zombie = "Iii";
            break;
        case 'J':
            zombie = "Jjj";
            break;
        case 'K':
            zombie = "Kkk";
            break;
        case 'L':
            zombie = "Lll";
            break;
        case 'M':
            zombie = "Mmm";
            break;
        case 'N':
            zombie = "Nnn";
            break;
        case 'O':
            zombie = "Ooo";
            break;
        case 'P':
            zombie = "Paa";
            break;
        case 'Q':
            zombie = "Qqq";
            break;
        case 'R':
            zombie = "Rrr";
            break;
        case 'S':
            zombie = "Sss";
            break;
        case 'T':
            zombie = "Ttt";
            break;
        case 'U':
            zombie = "Uuu";
            break;
        case 'V':
            zombie = "Vvv";
            break;
        case 'W':
            zombie = "Www";
            break;
        case 'X':
            zombie = "Xxx";
            break;
        case 'Y':
            zombie = "Yyy";
            break;
        case 'Z':
            zombie = "Zzz";
            break;
    }

    return zombie;
}

//Création de la classe humain
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


    //Affichage du nom de l'humain
    void afficherh() {
        cout << " Je m'appelle " << nom << endl;
    }
};

//Création de la classe zombie
class Zombie {
private:
    string nom;

public:
    Zombie(Humain *humain) {
        this->nom = humain->getNom() + " le mangeur de cerveau";
    }


    string getNom() {
        return nom;
    }


    //création de la méthode manger
    Zombie *manger(Humain *humain) {
        cout << "Le fameux zombie mangeur de chat " << nom << " mange l'Humain " << humain->getNom() << endl;
        return new Zombie(humain);
    }

    //Affichage du nom du zombie
    void afficherz() {
        cout << "je suis le zombie mangeur de cerveau et je m'appelle " << nom << endl;
    }
};


int main() {
    // Demande le nom humain
    string nom;
    cout << "Entrer votre nom d'humain: ";
    cin >> nom;
    string zombie = nomzombie(nom);
    // Affiche le nom zombie
    cout << "Vous vous appelez " << nom << " et si vous etiez un zombie vous vous appeleriez : " << zombie << endl;

    Humain h1("Killian");
    Humain h2("Louis");

    h1.afficherh();
    h2.afficherh();

    //Création de l'humain et du zombie
    Humain *h3 = new Humain("Remi");
    Zombie *z1 = new Zombie(h3);

    z1->afficherz();
    Humain *h4 = new Humain("Kais");

    cout << "L'humain s'appelle " << h4->getNom() << endl;
    //Création du nouveau zombie a partir de l'humain
    Zombie *z2 = z1->manger(h4);

    z2->afficherz();

    delete h4;
    delete h4;
    delete z1;
    delete z2;


    return 0;
}
