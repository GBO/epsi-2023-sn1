#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

// Fonction pour générer un nombre aléatoire entre min et max
int genererNombreAleatoire(int min, int max) {
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

// Fonction pour simuler le lancement de 5 dés
void lancerDes() {
  std::vector<int> des;
  // Lancer les 5 dés et stocker les valeurs
  for (int i = 0; i < 5; i++) {
    int valeur = genererNombreAleatoire(1, 6);
    des.push_back(valeur);
  }
  // Afficher les valeurs des dés tirées
  std::cout << "Valeurs des dés tirées : ";
  for (int i = 0; i < 5; i++) {
    std::cout << des[i] << " ";
  }
  std::cout << std::endl;
  // Compter le nombre d'occurrences de chaque valeur
  std::map<int, int> occurences;
  for (int i = 0; i < 5; i++) {
    occurences[des[i]]++;
  }
  // Vérifier si une paire, un brelan ou un full est présent
  bool paire = false;
  bool brelan = false;
  for (const auto &it : occurences) {
    if (it.second == 2) {
      paire = true;
    } else if (it.second == 3) {
      brelan = true;
    }
  }
  // Afficher l'annonce trouvée
  if (brelan && paire) {
    std::cout << "Annonce : Un full" << std::endl;
  } else if (brelan) {
    std::cout << "Annonce : Un brelan" << std::endl;
  } else if (paire) {
    std::cout << "Annonce : Une paire" << std::endl;
  } else {
    std::cout << "Annonce : Aucune" << std::endl;
  }
}

int main() {
  // Simuler le lancement des dés
  lancerDes();
  return 0;
}