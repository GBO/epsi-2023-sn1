#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  cout << "Exercice 3.2" << endl;

  int tableau[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int saisie;
  cout << "Saisissez un nombre : "; cin >> saisie;

  cout << "AVEC UN FOR : " << endl;
  bool trouve = false;
  for (int i = 0; i < 10; i++) {
    if (saisie == tableau[i]) {
      cout << "Trouvé !" << endl;
      trouve = true;
    // Pas de else ici : il faut passer par un flag (trouve)
    // } else {
    //   cout << "Pas trouvé !" << endl;
    }
  }

  cout << "AVEC UN WHILE + OPTIMISE : " << endl;
  trouve = false;
  int i = 0;
  while (i < 10 && !trouve) {
    if (saisie == tableau[i]) {
      cout << "Trouvé !" << endl;
      trouve = true;
    // } else {
    //   cout << "Pas trouvé !" << endl;
    }
    i++;
  }


  // 
  if (!trouve) {
    cout << "Perdu !" << endl;
  }

  return 0;
}