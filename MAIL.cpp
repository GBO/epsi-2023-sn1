#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
 // utilisation du std pour ne pas ecrire à chaque fois std::cout

//exo 0

int main (int argc, char ** argv) {
    cout << "Exo 0:" << endl;

    cout << "0 Sortie:" << endl;
    cout << "1 Exercice 1:" << endl;
    cout << "2 Exercice 2:" << endl;
    cout << "3 Exercice 3:" << endl;


    int valeur;
    cout << "entrer une valeur entre 0 et 3:" << endl;
    cin >> valeur;
    if (valeur == 0) {

    }
    if (valeur == 1) {
        cout << "Exercice 1 :" << endl;
        cout << "combien souhaitez vous de nombre? :" << endl;
        int nb_resultats = 0;
        for (int valeur = 1; valeur < 10; ++valeur) {
            for (int 1 = 2; 1 < 2;
            ++1) {
                if (int valeur 1 == 0);
                cout << "la valeur est un nombre premier : " << endl;
            }
            return 0;
            {
                if (valeur == 2) {
                    cout << "Exercice 2 :" << endl;
                    int n;
                    cout << "combien souhaitez vous de nombre? :" << endl;
                    cin >> n;
                    int nb_resultats = 1
                    for (int 1 = 0; 1 < ; ++1) {
                        
                    }(int valeur = 2; valeur < 10; ++valeur) {
                        resultats = valeur
                        for (int 2 = 3; 2 <;
                        ++2) {
                            if (int valeur 2 == 1){
                                cout << "la valeur est un nombre premier :" << endl
                            }
                            else{
                                return 1;

                                if (valeur == 3) {
                                    cout << "Exercice 3 :" << endl;
                                    cout << "combien souhaitez vous de nombre? :" << endl;
                                    int nb_resultats = 2
                                    for (int valeur = 3; valeur < 10; ++valeur) {
                                        resultats = valeur
                                        for (int 3 = 4; 3 <;
                                        ++3) {
                                            if (int valeur 3 == 1){
                                                cout << "la valeur est un nombre premier :" << endl
                                            }
                                        }
                                    }
                                    else{
                                        return 2;


                                    }
                                }
                            }
                        }


                    }
                }
            }
        }
    }

    //exo 1
    int main(){
        int choix;
        do {
            cout << " Menu des Exercies :" << endl;
            cout << "0- Sortie :" << endl;
            cout << "1- Exercice 1 :" << endl;
            cout << "2- Exercice 2 :" << endl;
            cout << "3- Exercice 3 :" << endl;
        
                    << "saisir le numéro qui correspond à l'exercice que vous voulez réaliser: "; //on fait ça pour choisir une valeur
            cin >> choix;
            switch (choix) {
                case 0 :
                    cout << "Programme termine :" << endl;
                    break;
                case 1; // correspond à l'exercice 1

                    break;
                case 2; // correspond à l'exercice 2

                    break;
                case 3; // correspond l'exercice 3

                    break;
                default:
                    cout << "choix non valide, saisir une autre valeur : " << endl;
            }
            while (choix != 0);
        }
    }


    //exo 2

    int main();

    int joueur = rand() % 6 + 1; // lancer du dé pour le joueur
    int ordinateur = rand() % 6 + 1; // lancer du dé pour l'ordinateur

        // afficher les résultats
        cout <<"Le joueur a lancé : " << joueur << endl;
        cout <<"L'ordinateur a lancé : " << ordinateur << endl;

    // déterminer le vainqueur ou l'égalité
    if (joueur > ordinateur) {
         cout << "Le joueur gagne :" << endl;
    }
        else if (ordinateur > joueur) {
          cout << "L'ordinateur gagne :" << endl;
    }
        else {
         cout << "Egalité :" << endl;
    }

    return 0;
}

  //exo 3


int main (){
    int tab[10]; // initialisation du tableau
    bool triCroissant = true; // initialisation des variables de tri
    bool triDecroissant = true;

    srand(time(NULL)); // initialisation de rand avec le temps actuel

    // remplissage du tableau avec des valeurs aléatoires
    for (int i = 0; i < 10; i++) {
        tab[i] = rand() % 100;
        cout << tab[i] << " ";
    }
    cout << endl;

    // inspection du tableau pour déterminer le tri
    for (int i = 0; i < 9; i++) {
        if (tab[i] > tab[i+1]) {
            triCroissant = false;
        }
        if (tab[i] < tab[i+1]) {
            triDecroissant = false;
        }
    }

    // affichage des résultats
    if (triCroissant) {
        cout << "Le tableau est trié en ordre croissant :" << endl;
    }
    else if (triDecroissant) {
        cout << "Le tableau est trié en ordre décroissant :" << endl;
    }
    else if (tab[0] == tab[9]) {
        cout << "Toutes les valeurs du tableau sont égales :" << endl;
    }
    else {
        cout << "Le tableau n'est pas trié :" << endl;
    }

    return 0;
}