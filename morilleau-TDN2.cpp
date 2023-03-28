#include <iostream>
#include <cctype>

using namespace std;
//Exercice 1

// On définit la fonction avec comme paramètre nom_humain
string nom_zombie(string nom_humain){
    // On sélectionne la 1ère lettre de nom_humain
    string lettre = nom_humain.substr(0,1);
    // Et on crée le nom du zombie en l'écrivant 3 fois
    string zombie = lettre + lettre + lettre;
    return zombie;
}

//Exercice 2
// On crée une classe humain avec comme atribut nom et comme méthode afficher pour afficher le nom de l'humain
class Humain{
private:
    string nom;

public:
    string get_nom(){
        return this-> nom;
    }

    void set_nom(string n) {
        this -> nom = n;
    }

    void afficher() {
        cout << "Le nom de l'humain est : " << this->nom << endl;
    }
};


//Exercice 3

class Zombie{
private:
    string nom;
    Humain* humain;

public:
    string get_nom(){
        return this-> nom;
    }

    Zombie(string nom){
        this->nom = nom_zombie(nom);
    }

    void afficher() {
        cout << "Le nom du zombie est : " << this->nom << endl;
    }

};

int main(int argc, char **argv)
{
    /*
    //Exercice 1

    string humain;
    cout << "Entrer un nom d'humain" << endl; cin >> humain;
    cout << "Son nom de zombie est : " << nom_zombie(humain) << endl;

    //Exercice 2
    // On initialise 2 humains avec comme nom Yassine et Mika et on les affiche
    Humain h1, h2;

    h1.set_nom("Yassine");
    h1.afficher();
    h2.set_nom("Mika");
    h2.afficher();
    */
    //Exercice 3

    Zombie* freddy = new Zombie("Moumine");
    freddy->afficher();

    Humain h3;

    h3.set_nom("Timeo");
    h3.afficher();

    return 0;
}
