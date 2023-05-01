#include <iostream>// Bibliothèque d'entrées/sorties standard
#include <unistd.h>// Bibliothèque pour utiliser usleep() pour attendre
#include <string>// Bibliothèque pour manipuler des chaînes de caractères



// Inclure les librairies standard
using namespace std;

//Définition de la taille de la grille
const int TailleG = 30;

//Définition des fonctions
void printGrid(bool OneG[TailleG+1][TailleG+1]);// Fonction pour afficher la grille
void determineState(bool OneG[TailleG+1][TailleG+1]);// Fonction pour déterminer l'état des cellules dans la grille


//Fonction principale
int main(){

    bool OneG[TailleG+1][TailleG+1] = {};// Initialisation de la grille
    int x,y;
    string nbrC;
    string start ;

    //Affichage des règles du jeu de la vie
    cout << " LE JEU DE LA VIE - Mise en oeuvre en C++" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "est un automate cellulaire concu par le mathematicien britannique John Horton Conway en 1970." << endl;
    cout << endl;
    cout << "REGLE DU JEU" << endl;
    cout << "L univers du jeu de la vie est une grille rempli de cellules," << endl;
    cout << "Chacun d'entre eux se trouve dans l'un des deux etats possibles, vivant ou mort." << endl;
    cout << "La cellule interagit avec les 8 voisins qui l'entoure les plus proche" << endl;
    cout << "A chaque etape du temps, les transitions suivantes se produisent :" << endl;
    cout << "1. toute cellule vivante ayant moins de deux voisins vivants meurt, comme si cela etait du a une sous-population" << endl;
    cout << "2. toute cellule vivante ayant deux ou trois voisins vivants reste en vie" << endl;
    cout << "3. Toute cellule vivante ayant plus de trois voisins vivants meurt, comme par surpopulation." << endl;
    cout << "4. Toute cellule morte ayant exactement trois voisins vivants devient une cellule vivante, comme par reproduction." << endl;
    cout << endl;
    cout << "O - cellule vivante" << endl;
    cout << ". - cellule morte" << endl;
    cout << endl;
    cout << "Saisissez le nombre de cellules : ";
    cin >> nbrC;
    cout << endl;


    {
        for(int i=0;i<stoi(nbrC);i++)// Ajouter des cellules
        {
            cout << nbrC << "Entrez les coordonnees de la cellule " << i+1 << " : ";
            cin >> x >> y;
            OneG[x][y] = true;// Mettre une cellule dans la grille
            printGrid(OneG);// Afficher la grille
        }
    }
    cout << "La configuration de la grille est terminee. Commencer le jeu ? (y/n)" << endl;
    printGrid(OneG);// Afficher la grille initiale
    cin >> start; // Lire la réponse de l'utilisateur


    if( start == "y" || start == "Y" )//l'utilisateur choisit de commencer le jeu
    {
        while (true)// Boucle principale pour le jeu
        {
            printGrid(OneG);// Afficher la grille
            determineState(OneG);// Déterminer l'état des cellules dans la grille
            usleep(200000);// Mettre en pause pendant un court moment
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;// Effacer la console pour afficher la grille suivante

        }
    }
    // Si l'utilisateur ne veut pas jouer, quitter le programme
    else
    {

        return 0;

    }
}


// Fonction pour afficher la grille

void printGrid(bool OneG[TailleG+1][TailleG+1]){

    for(int a = 1; a < TailleG; a++)
    {
        for(int b = 1; b < TailleG; b++)
        {
            if(OneG[a][b] == true)
            {
                cout << " O ";
            }
            else
            {
                cout << " . ";
            }
            if(b == TailleG-1)
            {
                cout << endl;
            }
        }
    }
}

// Fonction pour comparer deux grilles
void compareGrid (bool OneG[TailleG+1][TailleG+1], bool gridTwo[TailleG+1][TailleG+1]){
    for(int a =0; a < TailleG; a++)
    {
        for(int b = 0; b < TailleG; b++)
        {
            gridTwo[a][b] = OneG[a][b];
        }
    }
}

// Fonction pour déterminer l'état des cellules dans la grille
void determineState(bool OneG[TailleG+1][TailleG+1]){


    bool TwoG[TailleG+1][TailleG+1] = {};// Créer une grille temporaire pour stocker l'état précédent de chaque cellule
    compareGrid(OneG, TwoG);// Copier la grille actuelle dans la grille temporaire

    // Parcourir chaque cellule dans la grille
    for(int a = 1; a < TailleG; a++)
    {
        for(int b = 1; b < TailleG; b++)
        {
            // Compter le nombre de cellules vivantes autour de la cellule actuelle
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(TwoG[a+c][b+d])
                        {
                            ++alive;
                        }
                    }
                }
            }
            // Appliquer les règles du jeu de la vie pour déterminer l'état de la cellule dans la grille
            if(alive < 2)
            {
                OneG[a][b] = false;
            }
            else if(alive == 3)
            {
                OneG[a][b] = true;
            }
            else if(alive > 3)
            {
                OneG[a][b] = false;
            }
        }
    }
}
