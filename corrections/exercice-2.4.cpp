// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 2.4" << endl;

  int a = 0;

  // Nwhile (!((30 < a) && (a < 42))) {
  // while ((30 >= a) || (a >= 42)) {
  while (a == 0) {
    cout << "A : "; cin >> a;
    // On est obligé de refaire le test ici si on veut afficher le "Non !"
    if ((30 >= a) || (a >= 42)) {
      cout << "Non !" << endl;
      a = 0;
    }
  }

  cout << "Yes ! Vous êtes dans les bornes ! :) " << endl;

  return 0;
}