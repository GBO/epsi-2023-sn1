#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {

    // Exercice 0

    //On initialise la variable choix qui contient le choix d'où veut aller l'utilisateur
    int choix;

    cout << "0- Sortie" << endl;
    cout << "1- Exercice 1" << endl;
    cout << "2- Exercice 2" << endl;
    cout << "3- Exercice 3" << endl;

    //On demande où l'utilisateur veux aller
    cout << "Ou souhaitez-vous aller" << endl; cin >> choix;

    if (choix == 0){

        // Si l'utilisateur sélctionne 0, le programme s'arrête

    }
    if (choix == 1){

        // Si l'utilisateur sélctionne 1, le programme exécute l'exercice 1

        cout << "Voici l'exercice 1" << endl;

        //Exercice 1
        // On initialise d'abord la variable affichage qui contient le nombre de nombre premier a afficher
        int affichage;
        // On initialise ensuite le tableau nb_premier qui contient les 10 premiers nombres premier
        int nb_premiers[10] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        //On demande à l'utilisatuer combien il veut afficher de nombre premiers
        cout << "Combien voulez-vous afficher de nombre premiers ? (max 10)" << endl; cin >> affichage;
        // Puis on créer un boucle for qui affiche les nombres premiers
        for (int i= 0; i < affichage; i++){
            cout << nb_premiers[i] << endl;
        }

    }
    if (choix == 2){

        // Si l'utilisateur sélctionne 2, le programme exécute l'exercice 2

        cout << "Voici l'exercice 2" << endl;

        // On initialise le générateur de nombre aléatoire
        srand(time(NULL));
        // On initialise les variables joueur et ordi qui contiendront les résultats des tirs de dé
        int joueur;
        int ordi;
        // On fait l'équivalent d'un tirage de dé à 6 faces pour les 2 variables
        joueur = rand() %6 + 1;
        ordi = rand() %6 + 1;
        //On affiche les résultats des 2 tirs
        cout << "Le joueur a tire un " << joueur << endl;
        cout << "L'ordinateur a tire un " << ordi << endl;
        // Et enfin on teste qui à fait le meilleur score ou si il y a égalité
        if (joueur > ordi){
            cout << "Le joueur a gagne";
        }
        if (ordi > joueur){
            cout << "L'ordinateur a gagne";
        }
        if (joueur == ordi) {
            cout << "Il y a egalite";
        }
    }
    if (choix == 3){

        // Si l'utilisateur sélctionne 3, le programme exécute l'exercice 3

        cout << "Voici l'exercice 3" << endl;

        //On initialise le tableau de 10 nombres
        int tableau[10] {1,2,3,4,5,6,7,8,9,10};

        //On initialise 3 variables croissant, décroissant et constant
        bool croissant = true;
        bool decroissant = true;
        bool constant = true;

        //On teste si le tableau est croissant, décroissant, constant ou non trié
        for (int i = 0; i < 10; i++){
            if (tableau[i] > tableau[i+1]){
                croissant = false;
            }
            if (tableau[i] < tableau[i+1]){
                decroissant = false;
            }
            if (tableau[i] != tableau[i+1]){
                constant = false;
            }
        }

        // on affiche de quelle manière est trié le tableau
        if (croissant) {
            cout << "Les elements du tableau sont tries en ordre croissant";
        }
        if (decroissant) {
            cout << "Les elements du tableau sont tries en ordre decroissant";
        }
        if (constant) {
            cout << "Les elements du tableau sont tous les memes";
        }
        else {
            cout << "Les elements du tableau ne sont pas tries";
        }
    }

    return 0;
}