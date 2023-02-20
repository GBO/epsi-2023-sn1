// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 2.3" << endl;

  int saisie;
  int plus_petit = 0;

  /* Solution alternative :
    cout << "Saisissez un nombre : "; cin >> saisie;
    plus_petit = saisie;
    for (int i = 0; i < 4; i++) {
      cout << "Saisissez un nombre : "; cin >> saisie;
      if (saisie < plus_petit) {
        plus_petit = saisie;
      }
    }
  */

  for (int i = 0; i < 5; i++) {
    cout << "Saisissez un nombre : "; cin >> saisie;
    if ((saisie < plus_petit) || (i == 0)) {
      plus_petit = saisie;
    }
  }

  cout << "Le plus petit était : " << plus_petit << endl;

  return 0;
}