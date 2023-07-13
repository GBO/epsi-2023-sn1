#include <iostream>
#include <vector>
class Grille {
private:
  std::vector<std::vector<int>> grille;
  int taille;

public:
  // Constructeur
  Grille(int taille) : taille(taille) {
    // Initialiser la grille avec des valeurs par défaut (0)
    grille.resize(taille, std::vector<int>(taille, 0));
  }
  // Méthode pour obtenir la valeur x & y
  int getValue(int x, int y) { return grille[x][y]; }
  // Méthode pour définir la valeur x & y
  void setValue(int x, int y, int valeur) { grille[x][y] = valeur; }
  // Méthode pour remettre à zéro toutes les valeurs de la grille
  void clear() {
    for (int i = 0; i < taille; i++) {
      for (int j = 0; j < taille; j++) {
        grille[i][j] = 0;
      }
    }
  }
  // Méthode pour afficher la grille
  void display() {
    for (int i = 0; i < taille; i++) {
      for (int j = 0; j < taille; j++) {
        std::cout << grille[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
};


int main() {
  // Initialiser une grille de 20 par 20 et l'afficher
  Grille grille1(20);
  grille1.display();
  // Mettre des 1 dans les 2 diagonales
  for (int i = 0; i < 20; i++) {
    grille1.setValue(i, i, 1);
    grille1.setValue(i, 20 - i - 1, 1);
  }
  // Afficher la grille après modification
  grille1.display();
  // Initialiser une deuxième grille de 10 par 10 et l'afficher
  Grille grille2(10);
  grille2.display();
  // Mettre des 1 dans les 2 diagonales
  for (int i = 0; i < 10; i++) {
    grille2.setValue(i, i, 1);
    grille2.setValue(i, 10 - i - 1, 1);
  }
  // Afficher la deuxième grille après modification
  grille2.display();
  return 0;
}