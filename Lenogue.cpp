#include <iostream>
using namespace std;

string transforme(string nom){
    string nomzombie, lettre ;
    lettre = (char) tolower(nom[0]);
    nomzombie = nom[0] + lettre + lettre ;
    return nomzombie;
}

class Humain{
private:
    string nom;
public:

    Humain(string n){
        this->nom = n;
    }

    string get_nom(){
        return this->nom;
    }

    void afficher(){
        cout << "Humain: " + this->nom;
    }
};

class Zombie{
private:
    string nom;
public:

    string get_nom(){
        return this->nom;
    }

    Zombie(Humain()){
        this->nom = transforme(nom);
    }

    void manger(Humain){
        Zombie* zombie = new Zombie(Humain);
    }

    void afficher(){
        cout << "Zombie: " + this->nom;
    }

};

int main() {
    string Humain1="Ewan",Humain2 = "Moumine",zombie,zombie2;
    cout << "Humain = " + Humain1 + " " + "Humain2 =" + Humain2 << endl;
}
