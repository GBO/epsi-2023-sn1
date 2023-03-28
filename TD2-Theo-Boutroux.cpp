#include <iostream>
#include <vector>

using namespace std;

string nom_humain(string nom){
    int firstLetter;
    firstLetter = nom[0];
    string result;
    result += firstLetter;
    for (int j = 0; j < 2; ++j) {
        result += (char) tolower(firstLetter);
    }
    cout << result << endl;
}

class Humain{
protected:
    string nom;

public:
    Humain(string nom){
        this->nom = nom;
    }

    string getNom(){
        cout << this->nom << endl;
    }

    void afficher(){
        cout << "Nom de l'humain : " << this->nom << endl;
    }
};

class Zombie{
private:
    string nom;

public:

    Zombie(string nom) {
        this->nom = nom_humain(nom);
    }

    string getNom(){
        cout << this->nom << endl;
    }

    void manger(Humain* humain){
        Zombie* nouveau_zombie = new Zombie(humain->getNom());
        cout << humain->getNom() << " s'est transformé en zombie" << endl;
    }

    void afficher(){
        cout << "Nom du zombie : " << this->nom << endl;
    }
};

class FinDuMonde{
private:
    vector<string> zombies;
    vector<string> humains;
public:

    void ajouterHumain(Humain* nouveau_humain){
        humains.push_back(nouveau_humain->getNom());
    }

    void debutDeLaFin(Humain* premier_mange){
        Zombie* premier_zombie = new Zombie(premier_mange->getNom());
        zombies.push_back(premier_zombie);
    }

    void fin(){
        int i = 0;
        int j = 0;
        Zombie* zombie;
        Zombie* premier_zombie = debutDeLaFin(humains[0]);
        while (!humains.empty()){
            if (size(zombies) > 1){
                zombie = new Zombie(zombie[j]);
                j++;
            }
            if (size(zombies) == 1){
                zombie = new Zombie(zombie[j]);
            }
            Humain* humain = new Humain(humain[i]);
            zombie->manger(humain);
            i++;
        }
    }

};

int main() {

    /* EXERCICE 1 */

    /*cout << nom_humain("Maurice") <<endl;
    cout << nom_humain("Roméo") << endl;*/

    /* EXERCICE 3 */

    /*Zombie* z1 = new Zombie("Mmm");
    Humain* h1 = new Humain("Maurice");

    z1->manger(h1);
    z1->afficher();*/

    /* Exercice 4 */

    string zombie[1] = {"Zombie"}
    string prenoms[10] = {"Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo"};

    FinDuMonde* finDuMonde = new FinDuMonde(zombie, prenoms);


    return 0;
}
