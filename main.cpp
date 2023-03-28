//PAR CLEMENT JUBILO//

#include <iostream>
#include <vector>
using namespace std;
//sinon le getzombiename ne marche pas
string getZombieName(string humanName);



class Humain {
private:
    string nom;
public:
    //voici le constructeur
    Humain(string nom) : nom(nom) {}
    void afficher() {
        cout << "Humain: " << nom << endl;
    }
    string getNom() {
        return nom;
    }
};

class Zombie {
private:
    string nomZ;
public:
    Zombie(Humain* humain) : nomZ(getZombieName(humain->getNom())) {
        cout << "Zombie cree: " << nomZ << endl;
    }
    Zombie* manger(Humain* humain) {
        cout << nomZ << " mange " << humain->getNom() << endl;
        Zombie* nouveauZombie = new Zombie(humain);
        return nouveauZombie;
    }
    void afficher() {
        cout << "Zombie: " << nomZ << endl;
    }
};

class FinDuMonde{
private:
    //liste des victimes//
    string prenoms[15] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael"};
    //tableau de chaines de caracteres pour stockage
    vector<string> humains;
    vector<string> zombies;

public:

    FinDuMonde(){
        //les 5 premiers noms sont humains
        for(int i=0; i<5; i++){
            humains.push_back(prenoms[i]);
        }
        //les 10 derniers des zombies//
        for(int i=5; i<15; i++){
            zombies.push_back(prenoms[i]);
        }
    }
//si il y a au moin un humain et un zombie, le dernier humain de la liste devient un zombie
    void faireUnPas(){
        if(humains.size() > 0 && zombies.size() > 0){
            string humain = humains.back();
            humains.pop_back();
            string zombie = zombies.back();
            zombies.pop_back();
            zombies.push_back(humain);
            cout << zombie << " a mange " << humain << endl;
        }
    }
//continuer jusqu'a ce que le nombre d'humain soit à 0
    void fin(){
        while(humains.size() > 0 && zombies.size() > 0){
            faireUnPas();
        }
        if(humains.size() == 0){
            cout << "Tous les humains ont ete manges." << endl;
        }else{
            cout << "Tous les zombies ont ete tues." << endl;
        }
    }
};







//comment mettre tout en minuscule :
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}
//si le caractere en minuscule et une voyelle, il la change par un m,sinon par un r
string getZombieName(string humanName) {
    string zombieName = "";
    //permet de faire chaque charactere de la ligne//
    for (int i = 0; i < humanName.length(); i++) {
        char c = toLowerCase(humanName[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'|| c == 'y') {
            zombieName += 'm';
        } else {
            zombieName += 'r';
        }
    }
    return zombieName;
}

//exercice 1//
int main(int argc, char **argv) {
    string prenom1 = "Maurice";
    string prenom2 = "Romeo";
    cout << prenom1 << " devient Zombie: " << getZombieName(prenom1) << endl;
    cout << prenom2<< " devient Zombie: " << getZombieName(prenom2) << endl;



    //exercice 2//
//une classe un object;
    Humain humain1("Alice");
    Humain humain2("Bob");
    //La méthode
    humain1.afficher();
    humain2.afficher();

    //exercice 3//
    Zombie* zombie1 = new Zombie(&humain1);
    zombie1->afficher();
    Zombie* zombie2 = zombie1->manger(&humain2);
    zombie2->afficher();


    //exercice 4//
//lancement de la fin du monde !
    FinDuMonde finDuMonde;
    finDuMonde.fin();

    //fin du programme//
    return 0;


}

