// Inclusion de la librairie iostream qui permet d'utiliser entre autre `cin` & `cout`
#include <iostream>
// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

// Déclaration et implémentation de la fonction `main`, le point d'entrée de l'application
int main(int argc, char **argv)
{
  cout << "Exercice 2.5" << endl;

  int saisie = -1;
  float somme = 0; // On le met en float pour assurer la division flottante plus bas
  int nombre = 0;

  while (saisie != 0) {
    cout << "Saisissez un nombre : "; cin >> saisie;
    if (saisie < 0) {
      cout << "Nombre négatif interdit !" << endl;
    } else {
    // if (saisie != 0) {
      // somme += saisie;
      // Strictement équivalent à
      somme = somme + saisie;
      nombre++;
    // }
    }
  }

  if (nombre > 1) {
    // `nombre - 1` parce que le dernier incrément était pour le 0 de sortie.
    cout << "La moyenne est donc : " << somme / (nombre - 1) << endl;
  } else {
    cout << "Je ne peux pas faire la moyenne de 0 nombre !" << endl;
  }

  return 0;
}