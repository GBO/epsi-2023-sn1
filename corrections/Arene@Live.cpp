#include <iostream>
#include <vector>
#include <cstdlib> // pour rand
#include <ctime> // pour time()
using namespace std;


class Etudiant {
private:
  string nom;
  int attaque;
  int defense;
  int vie;

public:
  Etudiant(string nom, int attaque, int defense) {
    this->nom = nom;
    this->attaque = attaque;
    this->defense = defense;
    this->vie = 100;
  }

  string get_nom() { return this->nom; }
  int get_attaque() { return this->attaque; }
  int get_defense() { return this->defense; }
  int get_vie() { return this->vie; }

  void afficher() {
    cout << "Etudiant " << this->affichage() << endl;
  }

  string affichage() {
    return this->nom + " (" + to_string(this->attaque) + "/" + to_string(this->defense) + ")[" + to_string(this->vie) + "]";
  }

  void attaquer(Etudiant* cible) {
    int degats = this->attaque;
    cout << this->affichage() << " attaque " << cible->affichage() << " avec " << degats << " dégats." << endl;
    cible->subir(degats);
  }

  void subir(int degats) {
    int degats_minores = degats - this->defense;
    if (degats_minores < 0) {
      degats_minores = 0;
    }
    cout << this->affichage() << " subit " << degats_minores << " dégats !" << endl;
    this->vie -= degats_minores;
  }
};

class Arene {
private:
  vector<Etudiant*> etudiants;

public:
  Arene() {

  }

  void recruter(Etudiant* etudiant) {
    this->etudiants.push_back(etudiant);
  }

  int nombre_non_ko() {
    int result = 0;
    for (Etudiant* etudiant : this->etudiants) {
      if  (etudiant->get_vie() > 0) {
        result++;
      }
    }
    return result;
  }

  void lancer_un_round() {
    for (Etudiant* attaquant : this->etudiants) {
      if (attaquant->get_vie() > 0) {
        // TODO Gérer les étudiants déjà KO

        Etudiant* cible = attaquant;
        while ((cible == attaquant) || (cible->get_vie() <= 0)) {
          cible = this->etudiants[rand() % this->etudiants.size()];
        }

        attaquant->attaquer(cible);
      }
    }
  }

  void lancer_la_bataille() {
    int round = 1;
    while (this->nombre_non_ko() > 1) {
      cout << endl << "### ROUND " << round << " : " << this->nombre_non_ko() << " étudiants..." << endl;
      round++;
      this->lancer_un_round();
    }

  }

};



int main(int argc, char **argv) {
  cout << "Arène 13/03" << endl;

  // Initialisation du générateur de nombre aléatoire
  srand(time(NULL));

  Etudiant* ghislain = new Etudiant("Ghislain", 10, 10);
  Etudiant* even = new Etudiant("Even", 1, 1);

  /*
  while (ghislain->get_vie() > 0 && even->get_vie() > 0) {
    ghislain->attaquer(even);
    even->attaquer(ghislain);
  }

  cout << endl;
  ghislain->afficher();
  even->afficher();
  */

  Arene* arene = new Arene();

  arene->recruter(even);
  arene->recruter(ghislain);
  arene->recruter(new Etudiant("Polo", 10, 10));
  arene->recruter(new Etudiant("Tobby", 10, 10));

  arene->lancer_la_bataille();


  delete ghislain;
  delete even;

  return 0;
}
