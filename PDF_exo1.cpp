#include <iostream>
#include <random>

// Fonction pour générer un nombre aléatoire entre min et max
int genererNombreAleatoire(int min, int max) {
  // Création d'un générateur de nombres aléatoires
  std::random_device rd;
  std::mt19937 generator(rd());
  // Définition de la plage de nombres possibles
  std::uniform_int_distribution<int> distribution(min, max);
  // Génération d'un nombre aléatoire
  int nombreAleatoire = distribution(generator);
  return nombreAleatoire;
}

int main() {
  // Afficher un nombre aléatoire entre 1 et 6
  int nombre1 = genererNombreAleatoire(1, 6);
  std::cout << "Nombre aléatoire entre 1 et 6 : " << nombre1 << std::endl;
  // Afficher 10 nombres aléatoires entre 100 et 200
  std::cout << "Nombres aléatoires entre 100 et 200 : ";
  for (int i = 0; i < 10; i++) {
    int nombre2 = genererNombreAleatoire(100, 200);
    std::cout << nombre2 << " ";
  }
  std::cout << std::endl;
  return 0;
}