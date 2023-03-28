#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

/*

//Exercice 1 : fonction permettant de calculer le nom d'un Zombie.
class Zombie {
private:
    string nomHumain;
public:
    void set_nomHumain(string nomHumain) {
        this->nomHumain = nomHumain;
    }

    string get_nomHumain(){
        return this->nomHumain;
    }

    void afficher(){
        cout << nomHumain[0] << (char) tolower (nomHumain[0])<< (char) tolower (nomHumain[0])<<endl;
    }
};

int main(int argc, char **argv) {
    Zombie z1;
    Zombie z2;
    z1.set_nomHumain("Maurice");
    z2.set_nomHumain("Romeo");
    cout<<"Avant : "<<endl;
    cout << "Zombie 1 : " << z1.get_nomHumain() << endl;
    cout << "Zombie 2 : " << z2.get_nomHumain() << endl;

    cout<<"Apres : "<<endl;
    cout << "Zombie 1 : ";
    z1.afficher();

    cout << "Zombie 2 : ";
    z2.afficher();
}
*/

//Exercice 2 : Ecrire une classe Humain avec un attribut nom et un constructeur pour le nom

class Humain {
private:
    string nom;
public:
    Humain(string nom) {
        this->nom = nom;
    }
    string get_nom(){
        return this->nom;
    }
    void afficher(){
        cout << "Humain : "<< this->nom << endl;
    }

};
// Exercice 3 : Écrire une classe Zombie avec un attribut nom, et un constructeur prenant un Humain en paramètre.
class Zombie {
private:
    string nom;
    Humain* Humain;
public:
    Zombie(string nom) {
        this->nom = nom;
    }

    string get_nom(){
        cout << nom[0] << (char) tolower (nom[0])<< (char) tolower (nom[0])<< endl;
        ;
    }

    Zombie* manger(class Humain*){  //modifie le nom de l'humain mangé par on nom de Zombie
        cout << "le zombie : "<< this->get_nom()<< "mange un humain"<<endl;
        cout << Humain->get_nom() << "a ete mange, il s'appelle desormais : "<<Humain ->get_nom()<<endl;
        Zombie* Maurice = new Zombie("Maurice");
    }
    void afficher(){
        cout << "Zombie : "<< get_nom()<<endl;
    }
};
//Exercice 4 : Écrire une classe FinDuMonde illustrant la conversion d’une population d’Humain en Zombie.
class FinDuMonde {
private:
    //on recupere les listes d'humains et de zombies
    vector<Humain> humain;
    vector<Zombie> zombie;
public:
    string nom_humain;
    void ajouterHumain(Humain*){ //instanciation d'un nouvel humain
        cout << "nom de l humain: " ;
        cin >>nom_humain;
        humain.push_back(nom_humain); //ajout de l'humain a la liste
    }

    void debutDeLaFin(){
    }
    void fin(){ //chaque zombie mange un humain
        for (int i =0; i < 10; i++){
            zombie[i].manger(class Humain*);
        }
        
    }
};

int main(int argc, char **argv){
    Humain* Maurice = new Humain ("Maurice");
    Maurice->afficher();
    cout << "nom : "<< Maurice->get_nom()<<endl;
    Humain* Romeo = new Humain ("Romeo");
    Romeo->afficher();
    Zombie* test = new Zombie("test");
    test->get_nom();
    test->manger(Maurice);
    Maurice->afficher();

}