#include <iostream>
#include <vector>
using namespace std;

string nomzombie(string nom) {

    string caractere;

    nom = nom[0];
    caractere = (char) tolower(nom[0]);
    nom.append(caractere);
    nom.append(caractere);

    return nom;
}

class Humain {

    private :
    string nom;

    public :

    Humain(string nom) {
        this -> nom = nom;
    }

    void afficher() {
        cout << "Nom de l'humain : " << this -> nom << endl;
    }

};

class Zombie {

private :
    string nom;
    Humain* humain;

public :
    Zombie(Humain* humain) {
        this -> nom = nomzombie(nom);
    }

    string get_nom() {
        return this -> nom;
    }

    void manger(Humain*) {
        return this -> new Zombie(Humain*);
    }

    void afficher() {
        cout << "Nom du zombie : " << this -> nom << endl;
    }


};

int main() {

    cout << "Exercice 1" << endl;

    string nom;

    cout << " Entrez le nom d'un humain : " << endl;
    cin >> nom;

    cout << "Avant : " << nom << endl;
    cout << "Apres : " << nomzombie(nom) << endl;


    cout << "Exercice 2" << endl;

    Humain* h1 = new Humain("Jean");
    h1 -> afficher();

    Humain* h2 = new Humain("Georges");
    h2 -> afficher();


    cout << "Exercice 3" << endl;


    return 0;
}
