// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 2.2" << endl;

  cout << "Dans un for : ";
  for (int i = 1; i <= 100; i++) {
    cout << i << ", ";
  }
  cout << endl;

  cout << "Dans un while : ";
  int i = 1;
  while (i <= 100) {
    cout << i << ", ";
    i++;
  }
  cout << endl;

  return 0;
}