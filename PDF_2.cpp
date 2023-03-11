
#include <iostream>
using namespace std;
int main()
{
  // Initialisation du générateur de nombres aléatoires
  srand(time(0));
  // Tirage du dé pour le joueur
  int joueur = rand() % 6 + 1;
  // Tirage du dé pour l'ordinateur
  int ordinateur = rand() % 6 + 1;
  // Affichage des résultats
  cout << "Le joueur a tiré : " << joueur << endl;
  cout << "L'ordinateur a tiré : " << ordinateur << endl;
  // Déterminer le vainqueur ou l'égalité
  if (joueur > ordinateur)
  {
    cout << "Le joueur a gagné !" << endl;
  }
  else if (joueur < ordinateur)
  {
    cout << "L'ordinateur a gagné !" << endl;
  }
  else
  {
    cout << "Match nul !" << endl;
  }
  return 0;
}
