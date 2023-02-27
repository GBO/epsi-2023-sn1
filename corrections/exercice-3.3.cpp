#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  cout << "Exercice 3.3" << endl;

  int tableau[10] = {1, 2, 3, 4, 4, 4, 7, 8, 9, 10};

  int saisie;
  cout << "Saisissez un nombre : "; cin >> saisie;
  
  int j = 0;
  for (int i = 0; i < 10; i++) {
    // Le pointeur n'est pas sur une valeur à supprimer
    if (tableau[i] != saisie) {
      // Les 2 pointeurs sont différents, donc décalage !
      if (i != j) {
        tableau[j] = tableau[i];
      }
      j++;
    }
  }
  // Remplir avec des 0
  while (j < 10) {
      tableau[j] = 0;
      j++;
  }
  // Afficher le tableau
  for (int i = 0; i < 10; i++) {
    cout << tableau[i] << ", ";
  }

  return 0;
}