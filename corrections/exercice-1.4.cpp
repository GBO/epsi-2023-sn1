// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 1.4" << endl;

  int a;
  int somme = 0;
  cout << "A : "; cin >> a; somme = somme + a;
  cout << "B : "; cin >> a; somme = somme + a;
  cout << "C : "; cin >> a; somme = somme + a;
  cout << "D : "; cin >> a; somme = somme + a;
  cout << "E : "; cin >> a; somme = somme + a;

  cout << "Moyenne : " << somme / 5.0 << endl;
  
  return 0;
}