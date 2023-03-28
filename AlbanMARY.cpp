#include <iostream>
#include <vector>
using namespace std;



//Exercice 1
/*
 * Cette Exercice renvoie le nom les 3 fois la première lettre d'une chaine de caractère
 */

// Cette fonction permet de
char toLower(char c) {
    return static_cast<char>(tolower(static_cast<int>(c)));
}

string transformation(string nomHumain) {
    if (nomHumain.empty()) {
        return " "; // Si la chaîne est vide, on retourne une chaîne vide
    } else {
        char premiereLettre = tolower(nomHumain[0]); // On récupère la première lettre en minuscule
        string resultat(2, premiereLettre); // On crée une chaîne contenant 2 fois cette lettre
        return string(1, nomHumain[0]) + resultat;
    }
}

//Exercice 2
class Humain { // Définition de la classe Humain
private: // Membres privés
    // Quelques attributs
    string nom;

public: // Membres publics
    // Une méthode déclarée _et_ implémentée dans le corps de la classe
    void afficher() {
        // this est un pointeur vers l'instance en cours...
        cout << "Humain : " <<this->nom << endl;
    }

    string getNom() {
        return nom;
    }

    Humain(string n){
        this->nom = n;
    }
};

//Exercice 3
class Zombie {
private:
    string nom;
public:
    Zombie(Humain* humain) {
        nom = transformation(humain->getNom());
        cout << "Un Zombie nommé " << nom << " a été créé." << endl;
    }
    string getNom() {
        return nom;
    }
    Zombie* manger(Humain* humain) {
        cout << nom << " a mangé " << humain->getNom() << " !" << endl;
        return new Zombie(humain);
    }
    void afficher() {
        cout << "Je suis " << nom << " !" << endl;
    }
};


//Exercice 4
class FinDuMonde {
private:
    vector<Humain*> humains;
    vector<Zombie*> zombies;
public:
    void ajouterHumain(Humain* humain) {
        humains.push_back(humain);
    }
    void debutDeLaFin() {
        if (!humains.empty()) { // On vérifie qu'il y a des humains dans la liste
            Humain* premierHumain = humains.front(); // On récupère le premier humain de la liste
            humains.erase(humains.begin()); // On le supprime de la liste des humains
            Zombie* premierZombie = new Zombie(premierHumain); // On crée un zombie avec le premier humain
            zombies.push_back(premierZombie); // On ajoute le zombie à la liste des zombies
        }
    }
    bool fin() {
        while (!humains.empty()) { // Tant qu'il reste des humains dans la liste
            for (auto zombie : zombies) { // On boucle sur tous les zombies de la liste
                if (!humains.empty()) { // On vérifie qu'il reste des humains à manger
                    Humain* humainAManger = humains.front(); // On récupère le premier humain de la liste
                    humains.erase(humains.begin()); // On le supprime de la liste des humains
                    Zombie* nouveauZombie = zombie->manger(humainAManger); // Le zombie mange l'humain et crée un nouveau zombie
                    zombies.push_back(nouveauZombie); // On ajoute le nouveau zombie à la liste des zombies
                }
            }
        }
    }
};



int main() {
    string maChaine1 = "Alban";
    cout << maChaine1 << endl; // Affiche "Alban"
    cout << transformation(maChaine1) << endl; // Affiche "Aaa"
    string maChaine2 = "Mathéo";
    cout << maChaine2 << endl; // Affiche "Mmm"
    cout << transformation(maChaine2) << endl; // Affiche "Mmm"



    Humain* ghislain = new Humain("Ghislain");
    ghislain->afficher();
    Humain* alban = new Humain("Alban");
    alban->afficher();




    cout << "Un humain nommé " << alban->getNom() << " a été mordu." << endl;
    Zombie* zombie = new Zombie(alban);
    zombie->afficher();
    Zombie* nouveauZombie = zombie->manger(alban);
    nouveauZombie->afficher();

    delete nouveauZombie;
    delete zombie;
    delete alban;



    FinDuMonde finDuMonde;

    // Déclaration sur une ligne :
    string prenoms[216] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia", "Elea", "Anaelle", "Alyssa", "Ilona", "Aya" };
    for (int i = 0; i < 10; i++) {
        finDuMonde.ajouterHumain(new Humain("Humain " + to_string(i)));
    }
    finDuMonde.debutDeLaFin();
    int tour = 1;
    while (finDuMonde.fin() != false) { // On boucle tant que la fin du monde n'est pas arrivée
        cout << "Tour " << tour << endl;
        tour++;
    }

    return 0;
}


