#include <iostream>
using namespace std;

class Tete {
private:
  string nom;

public:
  Tete(string n) {
    this->nom = n;
  }

  void afficher() {
    cout << this->nom << endl;
  }
};

class Chapeau {
private:
  string nom;

public:
  Chapeau(string n) {
    this->nom = n;
  }

  void afficher() {
    cout << this->nom << endl;
  }
};

class Personne {
private:
  string nom;
  Tete* tete;
  Chapeau* chapeau;

public:
  Personne(string nom) {
    this->nom = nom;
    this->tete = new Tete("Tête de " + nom);
    this->chapeau = nullptr;
  }
  ~Personne() {
    delete this->tete;
  }

  void afficher() {
    cout << "Personne : " << this->nom << " :" << endl;
    this->tete->afficher();
    if (this->chapeau == nullptr) {
      cout << "Sans chapeau !" << endl;
    } else {
      this->chapeau->afficher();
    }
  }

  void mettre(Chapeau* c) {
    this->chapeau = c;
  }

};

int main(int argc, char **argv) {

  Personne* ghislain = new Personne("Ghislain");
  ghislain->afficher();

  Personne* herbert = new Personne("Herbert");
  herbert->afficher();

  Chapeau* chapeau = new Chapeau("Chapeau vert");

  ghislain->mettre(chapeau);
  ghislain->afficher();

  herbert->mettre(chapeau);
  herbert->afficher();


  delete ghislain;
  delete herbert;
  delete chapeau;
  return 0;
}
