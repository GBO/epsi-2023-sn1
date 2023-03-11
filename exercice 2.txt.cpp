#include <iostream>
#include <cstdlib> // pour utiliser la fonction rand()
#include <ctime> // pour time()

using namespace std;

int main(int argc, char **argv)

{
  cout << "Exercice 2" << endl;
    int joueur, ordinateur;

    // Le générateur de nombre aléatoire doit être initialisé avec la fonction srand() en utilisant une graine (l’heure est communément utilisée grâce à la fonction time() de la bibliothèque ctime).
    srand(time(NULL));

    // La fonction rand() de la bibliothèque cstdlib permet de générer un nombre aléatoire entre 0 & RAND_MAX
    // Le +1 est necessaire sinon le des peut faire un 0
    joueur = rand() % 6 + 1;


    ordinateur = rand() % 6 + 1;

    // affichage des nombres aléatoires
    cout << "Le joueur a obtenu : " << joueur << endl;
    cout << "L'ordinateur a obtenu : " << ordinateur << endl;



    if (joueur > ordinateur) {
        //Si le joueur a un nombre superieur a celui de l'ordinateur ce message s'affiche:
        cout << "Le joueur a gagne, felicitation ! " << endl;
    }
        //Sinon ce message s'affiche
    else if (joueur < ordinateur)
        {
            cout << " Le vainqueur est l'ordinateur, dommage !" << endl;
        }
    
    //et bien sur il ne faut pas oublier l'egaliter !(non je l'avais pas oublie au debut, c'est faux)
            else {
                cout << "Egalite, c'est balo !" << endl;
            }

    return 0;
}
