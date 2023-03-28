#include <iostream>
using namespace std;
/*
//Exercice 1 :

class Zombie {
public:
    Zombie(string nomHumain) {
        this->nomHumain = nomHumain;
        this->nomZombie = calculerNomZombie(nomHumain);
    }

    string getNomHumain() const {
        return this->nomHumain;
    }

    string getNomZombie() const {
        return this->nomZombie;
    }

private:
    string nomHumain;
    string nomZombie;

    string calculerNomZombie(string nomHumain) const {
        string nomZombie;
        char l1 = tolower(nomHumain[0]);
        nomZombie += toupper(l1);
        nomZombie += l1;
        nomZombie += l1;
        return nomZombie;
    }
};

int main() {
    Zombie zombie1("Maurice");
    Zombie zombie2("Roméo");
    Zombie zombie3("Pierre");

    cout << zombie1.getNomHumain() << " se transforme en Zombie " << zombie1.getNomZombie() << endl;
    cout << zombie2.getNomHumain() << " se transforme en Zombie " << zombie2.getNomZombie() << endl;
    cout << zombie3.getNomHumain() << " se transforme en Zombie " << zombie3.getNomZombie() << endl;
    return 0;
}

//Exercice 2 :

class Humain {
private:
    string nomHumain;

public:
    Humain(string n) : nomHumain(n) {}

    string getNom() const {
        return nomHumain;
    }

    void afficher() const {
        cout << "Je suis l'humain " << nomHumain << endl;
    }
};

int main() {
    Humain h1("Timeo");
    Humain h2("Moumine");
    h1.afficher();
    h2.afficher();
    return 0;
}
*/
// Exercice 3 :


class Humain {
private:
    string nomHumain;

public:
    Humain(string n) : nomHumain(n) {}

    string getNom() const {
        return nomHumain;
    }

    void afficher() const {
        cout << "Je suis l'humain " << nomHumain << endl;
    }
};

class Zombie {
public:
    Zombie(Humain* humain) {
        this->nomHumain = humain->getNom();
        this->nomZombie = calculerNomZombie(nomHumain);
    }

    string getNomHumain() const {
        return this->nomHumain;
    }

    string getNomZombie() const {
        return this->nomZombie;
    }

    Zombie* manger(Humain* humain) {
        cout << "Le zombie " << nomZombie << " mange l'humain " << humain->getNom() << endl;
        return new Zombie(humain);
    }

    void afficher() const {
        cout << "Je suis le zombie " << nomZombie << endl;
    }

    void affichernewZombie() const {
        cout << nomHumain << " se transforme en Zombie " << nomZombie << endl;
    }

private:
    string nomHumain;
    string nomZombie;

    string calculerNomZombie(string nomHumain) const {
        string nomZombie;
        char l1 = tolower(nomHumain[0]);
        nomZombie += toupper(l1);
        nomZombie += l1;
        nomZombie += l1;
        return nomZombie;
    }
};

int main() {
    Humain h1("Timeo");
    Humain h2("Moumine");
    Humain h3("kais");

    Zombie z1(&h1);
    z1.afficher();

    Zombie* z2 = z1.manger(&h2);
    z2->affichernewZombie();

    Zombie* z3 = z2->manger(&h3);
    z3->affichernewZombie();

    return 0;
}

/*
//Exercice 4 :

#include <vector>

class Humain {
public:
    Humain(string n): nom(n) {}
    string getNom() { return nom; }
private:
    string nom;
};

class Zombie {
public:
    Zombie(Humain* h): humain(h) {}
    string getNomHumain() { return humain->getNom(); }
private:
    Humain* humain;
};

class FinDuMonde {
public:


};*/