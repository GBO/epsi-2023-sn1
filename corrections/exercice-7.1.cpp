#include <iostream>
using namespace std;

class Rectangle { // Définition d'une classe
  private: // Membres privés
    int hauteur;
    int largeur;

  public: // Membres publics
    int get_hauteur() {
      return this->hauteur;
    }
    void set_hauteur(int hauteur) {
      this->hauteur = hauteur;
    }

    int get_largeur() {
      return this->largeur;
    }
    void set_largeur(int largeur) {
      this->largeur = largeur;
    }

    void afficher() {
      cout << "Rectangle (" << this->hauteur << "x" << this->largeur << ")" << endl;
    }

    int get_perimetre() {
      // return (this->get_hauteur() + this->get_largeur()) * 2;
      return (this->hauteur + this->largeur) * 2;
    }

    int get_surface() {
      return this->hauteur * this->largeur;
    }

};

int main(int argc, char **argv) {

  Rectangle r1;

  r1.set_hauteur(12);
  r1.set_largeur(12);


  Rectangle r2(r1);

  cout << "AVANT" << endl;
  r1.afficher();
  r2.afficher();

  r1.set_largeur(24);
  cout << "APRES" << endl;
  r1.afficher();
  r2.afficher();


  Rectangle* p1;
  p1 = new Rectangle();

  // (*p1).set_hauteur(13);
  // (*p1).set_largeur(13);
  // (*p1).afficher();
  // Strictement équivalent mais plus joli :
  p1->set_hauteur(13);
  p1->set_largeur(13);
  p1->afficher();

  Rectangle* p2;
  p2 = p1;

  cout << "AVANT" << endl;
  p1->afficher();
  p2->afficher();

  p1->set_largeur(24);
  cout << "APRES" << endl;
  p1->afficher();
  p2->afficher();


  delete p2;

  return 0;


  r2.set_hauteur(24);
  r2.set_largeur(24);

  cout << "Rectangle 1 : " << endl;
  r1.afficher();
  cout << "Périmètre : " << r1.get_perimetre() << endl;
  cout << "Surface : " << r1.get_surface() << endl;

  cout << "Rectangle 2 : " << endl;
  r2.afficher();
  cout << "Périmètre : " << r2.get_perimetre() << endl;
  cout << "Surface : " << r2.get_surface() << endl;


  return 0;
}
