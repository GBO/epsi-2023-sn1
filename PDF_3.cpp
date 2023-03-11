
#include <iostream>
using namespace std;
int main()
{
  int tab[10] = {2, 7, 5, 13, 15, 18, 23, 27, 31, 34}; // on entre les 10 valeurs
  int i, n, k;                                         // pour comparer les différent ordre ils nous faut des variables
  // Vérification pour voir si les éléments sont dans l'ordre croissant
  for (i = 0; i < 9; i++)
  {
    if (tab[i] > tab[i + 1])
    {
      break;
    }
  }
  if (i == 9)
  {
    cout << "Le tableau est en ordre croissant." << endl;
    return 0;
  }
  // Vérification pour voir si les éléments sont en ordre décroissant
  for (n = 0; j < 9; n++)
  {
    if (tab[n] < tab[n + 1])
    {
      break;
    }
  }
  if (n == 9)
  {
    cout << "Le tableau est en ordre décroissant." << endl;
    return 0;
  }
  // Vérification pour voir si tous les éléments sont égaux
  for (k = 0; k < 9; k++)
  {
    if (tab[k] != tab[k + 1])
    {
      break;
    }
  }
  if (k == 9)
  {
    cout << "Tous les éléments du tableau sont égaux." << endl;
    return 0;
  }
  // Si les éléments ne sont pas dans l'ordre croissant, décroissant ou égaux,alors ils sont dans un ordre quelconque
          cout
      << "Le tableau est dans un ordre quelconque." << endl;
  return 0;
}
