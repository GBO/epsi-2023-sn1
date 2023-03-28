#include <iostream>
#include <string>

//Exo 1
std::string getzombiename(std::string humanname) {
    std::string zombiename = "";
    for (char c : humanname) {                  //on demande le nom de l'humain
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                zombiename += 'm';               //Pour savoir le nom du zombie
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                zombiename += 'M';
                break;
            default:
                zombiename += c;
                break;
        }
    }
    zombiename += zombiename[0];
    zombiename += zombiename[0];
    return zombiename;
}
int main() {
    std::string humanname = "Yacine";
    std::string zombiename = getzombiename(humanname);
    std::cout << humanname << " se transforme en " << zombiename << std::endl;
    return 0;
}

//Exo 2

using namespace std;
class humain {
private:
    string nom;
public:
    humain(string n) : nom(n) {}       //on demande le nom de l'homme
    string getnom() const {
        return nom;
    }
    void afficher() const {
        cout << "Je suis un humain, je m'appelle " << nom << endl;
    }
};
int main() {
    humain h("Mika");
    h.afficher();
    return 0;
}


//Exo 3

using namespace std;

class humain {
private:
    string nom;                                 //On crée la class "humain"
public:
    humain(string n) : nom(n) {}

    string getnom() const {
        return nom;
    }
};
class zombie {
private:
    string nom;
public:
    zombie(humain* h) : nom("zombie_" + h->getnom()) {
        cout << nom << " a été créé parce qu'il a manger " << h->getnom() << endl;   //On crée la classe zombie avec un algorithme qui choisi aléatoirement un humain a transformé
    }
    string getnom() const {
        return nom;
    }
    zombie* manger(humain* h) {
        cout << nom << " a mangé " << h->getnom() << " et l'a transformé en zombie" << endl;
        return new zombie(h);
    }
    void afficher() const {
        cout << "Je suis un zombie, je m'appelle " << nom << endl;
    }
};
int main() {
    Humain* h1 = new humain("Timéo");
    Humain* h2 = new humain("Moumine");
    Zombie* z1 = new zombie(h1);                          
    Zombie* z2 = z1->manger(h2);
    z1->afficher();
    z2->afficher();
    delete h1;
    delete h2;
    delete z1;
    delete z2;

    return 0;
}

//Exo 4

#include <cstdlib>            
#include <ctime>            

using namespace std;

class findumonde {
private:
    vector<humain*> listehumains;
    vector<zombie*> listezombies;
public:
    findumonde() {
        srand(time(NULL)); 
    }
    void ajouterhumain(humain* h) {
        listehumains.push_back(h);
    }
    void debutdelafin() {
        if (listehumains.size() > 0) {
            int indice = rand() % listehumains.size();   // choix aléatoire d'un homme
            humain* h = listehumains[indice];
            zombie* z = new zombie(h);
            listehumains.erase(listehumains.begin() + indice); // suppression de l'Humain transformé en Zombie de la liste des Humains
            listezombies.push_back(z);
            cout << "Le premier zombie a été créé : " << z->afficher() << endl;
        }
    }
    void fin() {
        while (listehumains.size() > 0 && listezombies.size() > 0) {
            for (int i = 0; i < listezombies.size(); i++) {
                if (listehumains.size() > 0) {
                    int indice = rand() % listehumains.size();  
                    humain* h = listehumains[indice];
                    zombie* z = listezombies[i]->manger(h);
                    listehumains.erase(listehumains.begin() + indice);   
                    if (z != NULL) {               // si l'Humain a été transformé en Zombie
                        listezombies.push_back(z);
                        cout << z->afficher() << " a été créé en mangeant " << h->getNom() << endl;
                    }
                }
            }
        if (listehumains.size() == 0) {
            cout << "Il n'y a plus d'Humain, c'est la fin de la fin du monde." << endl;
        }
        else if (listezombies.size() == 0) {
            cout << "Il n'y a plus de Zombie, les Humains ont Gagnées." << endl;
        }
    }
};
}
































