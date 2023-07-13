#include <iostream>

#include "Joueur.hpp"
#include "Zone.hpp"

int main() {
    // Initialisation des données

    // Création du joueur
    Joueur joueur("Seonay", 50, 1);

    // Création de la zone de jeu
    Zone zone;

    // Boucle principale du jeu
    bool continuer = true;
    while (continuer) {
        // Affichage du menu principal
        std::cout << std::endl << "*** MENU PRINCIPAL ***" << std::endl;
        std::cout << "1. Couper du bois" << std::endl;
        std::cout << "2. Vendre du bois" << std::endl;
        std::cout << "3. Afficher l'inventaire" << std::endl;
        std::cout << "4. Afficher les statistiques" << std::endl;
        std::cout << "5. Quitter le jeu" << std::endl;
        std::cout << "Que voulez-vous faire ?" << std::endl;

        // Lecture de l'option choisie
        int choix;
        std::cin >> choix;

        // Exécution de l'option choisie
        switch (choix) {
            case 1:
                joueur.couperBois(joueur, zone);
                break;
            case 2:
                joueur.vendreBois();
                break;
            case 3:
                joueur.afficherInventaire();
                break;
            case 4:
                joueur.afficherStatistiques();
                break;
            case 5:
                std::cout << "Au revoir !" << std::endl;
                continuer = false;
                break;
            default:
                std::cout << "Choix invalide." << std::endl;
                break;
        }
    }

    return 0;
}
