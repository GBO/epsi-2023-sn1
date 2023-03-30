#include <iostream>
#include <string>
#include <vector>
using namespace std;

//L'exercice 1
/*
class zombie {
public:
    zombie(string humanName) {
        this->humanName = humanName;
        this->nomZombie = calculerNomZombie(humanName);
    }

    string gethumanName() const {
        return this->humanName;
    }

    string getNomZombie() const {
        return this->nomZombie;
    }
//je declare avec un string mes variables  humanName et nomZombie
private:
    string humanName;
    string nomZombie;

    string calculerNomZombie(string humanName) const {
        string nomZombie;
// ici je  transformer les caractères avec un char
        char lettre = tolower(humanName[0]);
        nomZombie += toupper(lettre);
        nomZombie += lettre;
        nomZombie += lettre;
        return nomZombie;
    }
};

int main() {
    zombie zombie1("Maurice");
    zombie zombie2("Roméo");
    zombie zombie3("Pierre");

    cout << zombie1.gethumanName() << " se transforme en Zombie " << zombie1.getNomZombie() << endl;
    cout << zombie2.gethumanName() << " se transforme en Zombie " << zombie2.getNomZombie() << endl;
    cout << zombie3.gethumanName() << " se transforme en Zombie " << zombie3.getNomZombie() << endl;

    cout << "Exercice 2: " << endl;
    return 0;
}


//L'exercice 2

//Je crée une classe humain et je declare nom avec un string
class humain {
private:
    string nom;

public:
    humain(string n) : nom(n) {}

    string getNom() const {
        return nom;
    }

    // avec un void je lui demande d'afficher "je suis suis un Humain et mon nom est" avec un void

    void afficher() const {
        cout << "Je suis un Humain et mon nom est " << nom << endl;
    }
};

// A partir de la il vas faire ce qu'on lui demande qui est de repondre "Je suis un Humain et mon nom est killian" car je vien d'ajoutyer les noms
int main() {
   humain h1("killian");
   humain h2("Remi");
    h1.afficher();
    h2.afficher();
    return 0;
}



//L'exercice 1

class humain {
private:
    string humainName;

public:
    humain(string n) : humainName(n) {}

    string getnom() const {
        return humainName;
    }

    void afficher() const {
        cout << "Je suis l'humain " << humainName << endl;
    }
};

class zombie {
public:
    zombie(humain* humain) {
        this->humainName = humain->getnom();
        this->nomZombie = calculerNomZombie(humainName);
    }

    string gethumainName() const {
        return this->humainName;
    }

    string getNomZombie() const {
        return this->nomZombie;
    }

    zombie* manger(humain* humain) {
        cout << "Le zombie " << nomZombie << " mange l'humain " << humain->getnom() << endl;
        return new zombie(humain);
    }

    void afficher() const {
        cout << "Je suis le zombie " << nomZombie << endl;
    }

    void affichernewZombie() const {
        cout << humainName << " se transforme en Zombie " << nomZombie << endl;
    }

private:
    string humainName;
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
    humain h1("killian");
    humain h2("Remi");
    humain h3("lili");

    zombie z1(&h1);
    z1.afficher();

    zombie* z2 = z1.manger(&h2);
    z2->affichernewZombie();

    zombie* z3 = z2->manger(&h3);
    z3->affichernewZombie();

    return 0;
}

  */

class humain {
public:
    string nom;
    humain(string nom) : nom(nom) {}
};

class zombie {
public:
    string nom;
    zombie(string nom) : nom(nom) {}
};

class FinDuMonde {
private:
    vector<humain*> humain;
    vector<zombie*> zombie;
public:
    void humainajouter(humain* h) {
        humain.push_back(h);
    }
    void debutetfin() {
        srand(time(NULL));
        int randomIndex = rand() % humain.size();
        humain* premierhumain = humain[randomIndex];
        zombie.push_back(new zombie(premierhumain->nom));
        humain.erase(humain.begin() + randomIndex);
    }
    void faireUnPas() {
        for (int i = 0; i < zombie.size(); i++) {
            if (humain.size() == 0) {
                cout << "Il n'y a plus d'humains, la fin du monde est arrivée !" << endl;
                return;
            }
            int randomIndex = rand() % humain.size();
            humain* victim = humain[randomIndex];
            zombie[i]->nom += " (" + victim->nom + ")";
            delete victim;
            humain.erase(humain.begin() + randomIndex);
        }
    }
    void fin() {
        while (humain.size() > 0) {
            faireUnPas();
        }
        cout << "La fin du monde est arrivée en " << zombie.size() << " tours." << endl;
        for (int i = 0; i < zombie.size(); i++) {
            delete zombie[i];
        }
    }
};

// pas fini, jai pas eu le temps pour faire le int