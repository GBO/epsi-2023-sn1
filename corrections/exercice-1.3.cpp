// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 1.3" << endl;

  int a, b;
  cout << "A : "; cin >> a;
  cout << "B : "; cin >> b;

  // Inversons !
  int c = a;
  a = b;
  b = c;

  cout << "A : " << a << endl;
  cout << "B : " << b << endl;

  // Retourner 1 permet d'indiquer à la console que le programme est en erreur
  // (ce qui est faux ici)
  return 1;
}