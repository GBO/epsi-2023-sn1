#include <iostream>
#include <vector>
using namespace std;

class Piece {
private:
  string nom;

protected:
  int x;
  int y;

public:
  Piece(string nom, int x, int y) {
    this->nom = nom;
    this->x = x;
    this->y = y;
  }

  string get_nom() { return this->nom; }
  int get_x() { return this->x; }
  int get_y() { return this->y; }

  virtual bool valider(int p_x, int p_y) {
    return true;
  }

  virtual bool deplacer(int x, int y) {
    bool result = false;
    if (this->valider(x, y)) {
      this->x = x;
      this->y = y;
      result = true;
    }
    return result;
  }

  void afficher() {
    cout << "La pièce " << this->nom << " : " << this->x << "x" << this->y << endl;
  }

};

class Pion : public Piece {
public:
  Pion(int x, int y) : Piece("Pion", x, y) {}

  virtual bool valider(int p_x, int p_y) {
    return (p_y == this->y + 1) && (p_x == this->x);
  }

};


int main(int argc, char **argv) {
  cout << "Exercice 7.6" << endl;

  Piece* p1 = new Piece("Pièce Générique", 0, 0);
  p1->afficher();
  p1->deplacer(12, 12);
  p1->afficher();

  Pion* p2 = new Pion(0, 0);
  p2->afficher();
  p2->deplacer(12, 12);
  p2->afficher();
  p2->deplacer(0, 1);
  p2->afficher();

  vector<Piece*> pieces;

  pieces.push_back(p1);
  pieces.push_back(p2);

  for (Piece* p : pieces) {
    p->valider(12, 12);
  }
  

  return 0;
}
