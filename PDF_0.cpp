
#include <iostream>
using namespace std;
int main()
{
  int choix;
  do
  {
    cout << "Bienvenue dans le menu des exercices :" << endl;
    cout << "0- Sortie" << endl;
    cout << "1- Exercice 1" << endl;
    cout << "2- Exercice 2" << endl;
    cout << "3- Exercice 3" << endl;
    cout << "saisir le numéro correspondant à l'exercice que vous voulez réaliser: "; // pour choisir une valeur
    cin >> choix;
    switch (choix)
    {
    case 0:
      cout << "Programme terminé." << endl;
      break;
    case 1:
      // Code pour l'exercice 1
      break;
    case 2:
      // Code pour l'exercice 2
      break;
    case 3:
      // Code pour l'exercice 3
      break;
    default:
      cout << "Choix impossible. Veuiller saisir une autre valeur." << endl; // pour choisir une valeur break;
    }
  } while (choix != 0);
  return 0;
}