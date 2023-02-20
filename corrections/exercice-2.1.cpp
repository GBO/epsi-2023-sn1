// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 2.1" << endl;

  int a;
  cout << "A : "; cin >> a;

  int result = 0;
  // Comparaison stricte déduite de l'exigence trop imprécise à mon goût
  if ((30 < a) && (a < 42)) {
    cout << "Yes ! Vous êtes dans les bornes ! :) " << endl;
    result = 0;
  } else {
    cout << "Erf ! Vous en dehors des bornes ! :/ " << endl;
    result = 1;
  }

  return result;
}