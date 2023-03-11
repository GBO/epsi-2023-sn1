#include <iostream>
#include <vector>

using namespace std;
bool est_premier(int n){
int main(int argc, char **argv){
    //Exercice 0
    int exo = 4;

    while (exo !=0){         //On fait une boucle qui s'arrete quand l'utilisateur veut quitter le menu en tapant 0
        cout << "choisi un exo (0- Sortie)\n"
                "1- Exercice 1\n"
                "2- Exercice 2\n"
                "3- Exercice 3\n"
                "Exercice souhaiter :"<<endl;

        cin >> exo ;

        if (exo==1){
            cout <<"exo 1:" <<endl;  //On dit quoi afficher en fonction de la reponse de l'user
        }
        if (exo==2){
            cout <<"exo 2:"<<endl;
        }
        if (exo==3){
            cout <<"exo 2:"<<endl;
        }
    }

    //Exercice 1
    cout << "Voici l'exo 1" << endl;


        if (n < 2) {
            return false;
        }

        for (int i = 2; i < n; i++) {  //Probleme de main et de fonction que je n'ai pas reussi a resoudre

            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }


        int n;

        cout << "Entrez le nombre de nombres premiers à afficher : ";
        cin >> n;

        int nombre = 2;
        int compteur = 0;
        cout << "Les " << n << " premiers nombres premiers sont : ";  *
        //on affiche les reponses en fonction de ce que l'user veut
        while (compteur < n) {
            if (est_premier(nombre)) {
                cout << nombre << " ";
                compteur++;
            }
            nombre++;
        }

        cout << endl;

        return 0;


    //Exercice 2
    cout << "Voici l'exo 2" << endl;
        srand(time(0)); // création du générateur de nombres aléatoires

        int utilisateur = rand() % 6 + 1; // lancer de dé de l'utilisateur
        int ordi = rand() % 6 + 1; // lancer de dé de l'ordi

        cout << "Vous avez obtenu un " << utilisateur << endl;
        cout << "L'ordinateur a obtenu un " << ordi << endl;

        if (utilisateur > ordi) {
            cout << "Vous avez gagner !" << endl;
        } else if (utilisateur < ordi) {
            cout << "L'ordinateur a gagner !" << endl;
        } else {
            cout << "Relancez" << endl;
        }

        return 0;
//ExExercice 3
    cout << "Voici l'exo 3" << endl;
        int tab[10];
        bool croissant = true;
        bool decroissant = true;
        bool constant = true;

        cout << "Entrez les 10 éléments du tableau :" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> tab[i];
        }

        for (int i = 1; i < 10; i++) {  //On range les valeurs que donne l'user
            if (tab[i] > tab[i-1]) {
                decroissant = false;
                constant = false;
            } else if (tab[i] < tab[i-1]) {
                croissant = false;
                constant = false;
            } else {
                croissant = false;
                decroissant = false;
            }
        }

        if (croissant) {
            cout << "Le tableau est trié par ordre croissant." << endl;
        } else if (decroissant) {
            cout << "Le tableau est trié par ordre décroissant." << endl;    //On affiche la réponse
        } else if (constant) {
            cout << "Toutes les valeurs du tableau sont égales." << endl;
        } else {
            cout << "Le tableau est dans un ordre quelconque." << endl;
        }

        return 0;
    }




}
