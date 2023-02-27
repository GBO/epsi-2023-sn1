#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  cout << "Exercice 3.1" << endl;

  int tableau[10];

  for (int i = 0; i < 10; i++) {
    cout << "Saisissez un nombre : "; cin >> tableau[i];
  }

  for (int i = 0; i < 10; i++) {
    if (tableau[i] > 10) {
      cout << "Une valeur supérieure à 10 en case " << i << " : " << tableau[i] << endl;
    }
  }

  cout << tableau << endl;

  return 0;
}