// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand
#include <ctime> // pour time()

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

/** Un petit bloc de commentaire pour passer quelques infos sur l'exercice 1.
 * La fonction identifie clairement l'exercice...
 */

//exercice 0
int main(int argc, char **argv)
{
    cout <<"Exercice 0 : "<<endl;
    //on crée un menu avec les differentes possibilités pour l'utilisateur
    cout <<"Menu : "<<endl;
    cout <<"0 - Sortie : "<<endl;
    cout <<"1 - Exercice 1 : "<<endl;
    cout <<"2 - Exercice 2 : "<<endl;
    cout <<"3 - Exercice 3 : "<<endl;

    int valeur;
    cout <<"entrer une valeur entre 0 et 3 : " <<endl;
    cin >> valeur;

    if (valeur == 0){
        return 0;
    }

    if (valeur == 1 ){
        cout << "Exercice 1 : " <<endl;
        int N;
        cout <<"combien de nombres premiers voulez-vous ? "<<endl;
        cin >> N; //on recupere le nombre entré par l’utilisateur
     int nb_resultats =0;
            for (int valeur = 1; valeur <= 10; valeur++){
                for (int i=1; i<10;i++){
                    if (valeur % i == 0 ){
                        cout << valeur <<"n'est pas un nombre premier"<<endl;
                    }else {
                        continue;
                    }
                }
        }
    }

    if (valeur == 2){ //l'utilisateur demande l'accès à l'exercice 2
        cout <<"Exercice 2: "<<endl;

        //tirage du 1er joueur
        int joueur = rand() % 7;
        cout << "Nombre aléatoire entre 0 (inclu) et 6 (inclu) : " << joueur << endl;

        //tirage de l'ordinateur
        int ordi = rand() % 7;
        cout << "Nombre aléatoire entre 0 (inclu) et 6 (inclu) : " << ordi << endl;

        //les différents résultats possibles
        if (joueur > ordi){
            cout<<"Félicitations ! Vous avez gagné "<<endl;
        }
        if (joueur == ordi){
            cout<<"Egalité"<<endl;
        }
        if (joueur <ordi){
            cout<<"La victoire sera pour la prochaine fois " << endl;
        }
    }
    if (valeur == 3){
        bool croissant = true;
        bool decroissant = true;

        cout <<"Exercice 3 : "<<endl;
        int tableau[5] ={1,2,3,4,5 },i; //initialisation du tableau
        string resultat;
        for (i=0;i < 5;i++){ //on parcourt le tableau
            //on vérifie les différentes conditions possibles
            if (tableau[i]>tableau[i+1]){
                resultat="tri décroissant";
                croissant =false;
            }
            if (tableau[i]<tableau[i+1]){
                resultat = "tri croissant";
                decroissant = false;
            }
            if (tableau[i]==tableau[i+1]){
                resultat="le tableau est constant";
                croissant = false;
                decroissant = false;
            }



        }
        if (croissant == true){
            cout<<"le tableau est croissant"<<endl;
        }
        if (decroissant == true){
            cout<<"le tableau est decroissant"<<endl;
        }
        if (croissant == false && decroissant == false){
            cout<<"le tableau n'est pas trié"<<endl;
        }
        return 0;
    }
    }