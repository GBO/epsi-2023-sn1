#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/**/

void exercice1(){
    /*Creation des variable de type 'int' avec l'initialisation de x a 1*/
    int N,y,x=1;
    /*Demande du nombre de nombre premier a afficher*/
    cout << "Choississez le nombre de nombre premier a afficher :";
    cin >> N;
    /*Creation d'un vecteur qui va stocker les nombre premier et d'un bolleen de verification*/
    vector<int> tableau;
    bool premier;
    /*Boucle while pour remplir le vector de la quantite de nombre premier demander*/
    while(tableau.size() != N){
        premier= true;
        x+=1;
        for(y=2;y<x;y++){
            if(x%y == 0){
                premier = false;
            }
        }
        if(premier == true){
            tableau.push_back(x);
        }
    }
    /*Affigage des nombre premier*/
    cout << "Les " << N << " premier nombre premier sont :" << endl;
    for(int i : tableau){
        cout << i << ",";
    }
}

void exercice2(){
    /*Initialisation des variables joueur et ordinateur avec un nombre choie aleatoirement entre 0 et 5
     * et incrementer de 1 pour avoir un nombre entre 1 et 6*/
    srand(time(NULL));
    int joueur = 1 + rand()%6 , ordinateur = 1 + rand()%6 ;

    /*Revelation nombre tirer au hasard*/
    cout << "Le joueur a obtenue le numero :" << joueur << endl;
    cout << "L'ordinateur a obtenue le numero :" << ordinateur << endl;

    /*Revelation des resultats*/
    if(joueur > ordinateur){
        cout << "Le joueur a gagner";
    }else if(ordinateur > joueur){
        cout << "C'est l'ordinateur qui a gagner";
    }else{
        cout << "C'est une egalite";
    }
}

void exercice3(){
    /*Initialisation des variable i pour la boucle trie pour ranger les nombre et verification pour savoir le type de trie */
    int i,trie[10],verification[2] = {0,0};
    /*Boucle pour avoir une liste de 10 nombre*/
    for(i=0;i<10;i++){
        cout << "Rentrez une valeur :";
        cin >> trie[i];
        cout << endl;
    }
    /*Incrementatin des valeur present dans le tableua verification en fonction des condition validé*/
    for(i=1;i<10;i++){
        if(trie[i] < trie[i-1]){
            verification[0] += 1;
        }else if(trie[i] > trie[i-1]){
            verification[1] += 1;
        }else{
            verification[0] += 1;
            verification[1] += 1;
        }
    }
    /*Resultat tu type de trie en fonction des valeur present dans verification*/
    if(verification[0] == 9 and verification[1] == 9){
        cout << "Les nombres dont ranges de facon constante";
    }else if(verification[1] == 9){
        cout << "Les nombres sont ranges en ordre croissant";
    }else if(verification[0] == 9){
        cout << "Les nombres sont ranges en ordre decroissant";
    }else{
        cout << "les nombres sont ranges de maniere quelconque";
    }
}

string exercice0(){
    /*Initialisation de choix*/
    int choix=4;
    /*Boucle pour acceder a l'exercice voulu en verifiant que la valeur entrer est correcte*/
    while(choix>3 or choix<0){
        cout << "0- Sortie" << endl;
        cout << "1- Exercice 1" << endl;
        cout << "2- Exercice 2" << endl;
        cout << "3- Exercice 3" << endl;
        cout << "Veuillez choisir un exercice :";
        cin >> choix;
    }
    /*Soit acced a l'exercice demander soit il sort du programme*/
    if(choix == 0){
        cout << "C'est la fin bonne journee a vous";
    }else if(choix == 1){
        exercice1();
    }else if(choix==2){
        exercice2();
    }else{
        exercice3();
    }
}

int main(int argc, char **argv) {
    exercice0();
}
