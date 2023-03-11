#include <iostream>
using namespace std;

int main(int argc, char **argv) {

    cout << "Exercice 0" << endl;
    int choix;
    do { // boucle do-while pour afficher le menu et permettre à l'utilisateur de choisir une option
        cout << "MENU" << endl;
        cout << "1. Exercice 1" << endl;
        cout << "2. Exercice 2" << endl;
        cout << "3. Exercice 3" << endl;
        cout << "4. Quitter" << endl; // afficher l'option pour quitter le menu
        cout << "Entrez votre choix (1-4) : "; // demander à l'utilisateur d'entrer son choix
        cin >> choix;

        if (choix == 1) { // Exécuter le code pour l'option 1 si choix est égal à 1
            cout << "Vous avez choisi l'option 1." << endl;
        } else if (choix == 2) { // Exécuter le code pour l'option 2 si choix est égal à 2
            cout << "Vous avez choisi l'option 2." << endl;
        } else if (choix == 3) { // Exécuter le code pour l'option 3 si choix est égal à 3
            cout << "Vous avez choisi l'option 3." << endl;
        } else if (choix == 4) { // Sortir de la boucle si choix est égal à 4
            cout << "Au revoir !" << endl; // afficher un message d'au revoir
        } else { // Message d'erreur si le choix est invalide
            cout << "Choix invalide. Veuillez entrer un nombre entre 1 et 4." << endl;
        }

    } while (choix != 4); // continuer à afficher le menu tant que l'utilisateur ne choisit pas l'option pour quitter

    return 0;
}
