// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 1.2" << endl;


  int largeur;
  int longueur;

  cout << "Largeur : ";
  cin >> largeur;

  cout << "Longueur : ";
  cin >> longueur;

  int perimetre = (largeur + longueur) * 2;

  cout << "Périmètre : " << perimetre << endl;
  cout << "Air : " << largeur * longueur << endl;


  return 0;
}