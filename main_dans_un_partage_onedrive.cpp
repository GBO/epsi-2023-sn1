#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void trans_zombi(string nom) {
    cout << nom[0];
    cout << (char) tolower(nom[0]);
    cout << (char) tolower(nom[0]);
}


class Humain {
private:
    string nom;

public:
    Humain(string nom) {
        this->nom = nom;
    }

    // Accesseur pour l'attribut nom
    string obtenirNom() {
        return nom;
    }

    // Méthode pour afficher le nom de l'Humain
    void afficher() {
        cout << "Humain : " << nom << endl;
    }
};


class Zombie {
private:
    string nom;

public:
    Zombie(Humain* humain){
        string nom_humain = humain->obtenirNom();
        trans_zombi(nom_humain);
    }

    string obtenirNom() {
        return nom;
    }

    void afficher() {
        cout << "Zombie : " << nom << endl;
    }

    void mange(Humain* humain){
        
    }

};


int main(int argc, char **argv) {

    //Exercice 1
    /*string nom;
    cout << "Entrer un nom : "; cin >> nom ;
    trans_zombi(nom);*/

    //Exercice 2
    Humain sasha("Sasha");
    Humain hugo("Hugo");

    sasha.afficher();
    hugo.afficher();

    Zombie azerty(Humain);


    return 0;
}

