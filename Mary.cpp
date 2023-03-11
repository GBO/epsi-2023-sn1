// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <vector> // pour que les tableaux soit plus simples
#include <cstdlib> // pour rand
#include <ctime> // pour time()

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

void exercice1();
void exercice2();
void exercice3a();
void exercice3b();

// Un main dans lequel j'invoque quelques fonctions d'exercice...
int main(int argc, char **argv) {
#ifdef WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "TD Noté de Alban MARY - 06/03/2023" << endl;
    int choix = -1;

    while (choix != 0) {
        cout << "0- Sortie" << endl;
        cout << "1- Exercice 1" << endl;
        cout << "2- Exercice 2" << endl;
        cout << "3- Exercice 3a" << endl;
        cout << "4- Exercice 3b" << endl;
        cout << "Entrez votre l'exercice de votre choix:";
        cin >> choix;
        if (choix == 1) {
            exercice1();
        } else if (choix == 2) {
            exercice2();
        } else if (choix == 3) {
            exercice3a();
        }else if (choix == 4) {
            exercice3b();
        } else {
            cout << "Cela ne correspond à aucun exercice";
        }
    }
}

/* Cette exercice sert à déterminer les N premier nombre qui sont premier, N étant déterminer par l'utilisateur
 *  -J'essaye ici tout les chiffre possible qui sont impaires c'est une méthode peu efficace mais ça suffit
 */
void exercice1() {
    // on instancie des entiers qui vont nous servir plus tard
    int nombreDeNombrePremier;
    int i = 0;
    int nb = 1;
    int iteration = 2;
    // on instancie un vector qui va nous servir à stockées les nombresPremier
    vector<int> nombresPremier;

    cout << "Saisissez le nombre de nombre premier à afficher:";
    cin >> nombreDeNombrePremier;

    if(nombreDeNombrePremier != 0){ //On regarde si le nombre de nombres de nombres premier n'est pas égale à 0 au quel cas on rajoute à la liste de nombre premier 2 qui n'est pas compter dans ma fonction car il n'est pas impaire
        nombresPremier.push_back(2);
        nombreDeNombrePremier--;
    }

    while (i < nombreDeNombrePremier) { // Tant que le nombre de nombre premier n'est pas atteint on continue
        nb += 2; // On regarde que les nombres impaires car les nombres paires sont divisibles par 2
        while (iteration <= nb / 2) { // On regarde que les nombres impaires car les nombres paires sont divisibles par 2
            if (nb % iteration == 0) { // On regarde si le modulo de tout les chiffres inférieur au nombres actuel est égale à 0 auquel cas il n'est pas premier et on arrête la boucle pour ce nombre
                break;
            }
            iteration++; // On ajoute à iteration 1
        }
        if (iteration > nb / 2) { // Si on arrive la c'est que la boucle n'a pas break et ça veut dire que le nombre est premier
            i++;
            nombresPremier.push_back(nb); // On ajoute alors la valeur au vector
        }
    }

    //fonction qui affiche le vector sous forme de liste: nombresPremier
    cout << "[";
    for (int j = 0; j < nombresPremier.size(); j++) {
        if (j < nombresPremier.size() - 1) {
            cout << nombresPremier[j] << ", ";
        } else {
            cout << nombresPremier[j] << "]";
        }
    }
}

void exercice2() {
    int joueur;
    int ordinateur;
    // Initialisation du générateur de nombre aléatoire
    srand(time(NULL));
    // Génération de nombres aléatoires
    int alea = rand();

    //On génère un chiffre aléatoire entre 1 et 6
    alea =rand() % 6 + 1;
    //On donne la valeur obtenu par le lancé de dé au joueur
    joueur = alea;
    //On affiche la valeur obtenu
    cout << "Le joueur obtient un : " << alea << endl;

    //On génère un chiffre aléatoire entre 1 et 6
    alea = rand() % 6 + 1;
    //On donne la valeur obtenu par le lancé de dé à l'ordinateur
    ordinateur = alea;
    //On affiche la valeur obtenu
    cout << "L'ordinateur obtient un : " << alea << endl;

    // On regarde le résultat, si la valeur joueur est plus grande que celle de l'ordinateur alors il a gagné
    // si c'est l'inverse alors c'est l'ordinateur qui gagne
    // sinon c'est une égalité
    if(joueur > ordinateur){
        cout << "Le joueur à gagné" << endl;
    }else if(joueur < ordinateur){
        cout << "L'ordinateur à gagné" << endl;
    }else{
        cout << "C'est une égalité" << endl;
    }
}


/* L'exercice 3a détermine si les élements d'une liste sont triés de façon croissante, décroissante, constante ou pas
 *  -J'ai fait cette exercice chez moi à partir d'un tri car c'était la seul façon que j'avais en tête à ce moment la
 */
void exercice3a() {
    // on instancie des entiers qui vont nous servir plus tard
    int tampon;
    int iteration;
    int nberreur;
    // on crée le tableau dont on ne connait pas le tri
    int tableau[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int tableaunontrier[10];

    // On copie le tableau dans tableaunontrier
    for (int q = 0; q < 10; q++) {
        tableaunontrier[q] = tableau[q];
    }

    //On trie le tableau d'un tri naif
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (tableau[j] > tableau[j + 1]) {
                iteration++;
                tampon = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tampon;
            }
        }
    }

    //On regarde la manière dont le tableau est trié
    if (iteration == 0) { //Si aucune opération n'a été effectué cela veut dire que le tableau est déjà trié donc soit croissant, soit constant
        if (tableau[0] == tableau[9]) { // On regarde la première et la dernière valeur si elles sont les mêmes après le tri cela veut dire que tout le tableau est pareil
            cout << "Les valeurs du tableau sont triées dans l\'ordre \"constant\""<< endl;
        } else {
            cout << "Les valeurs du tableau sont triées dans l\'ordre croissant"<< endl;
        }
    } else { //On regarde le nombre d'erreurs entre le tableau trier et le non trier car on peut déterminer leur ordre
        for (int p = 0; p < 10; p++) {
            if (tableaunontrier[p] != tableau[p]) {
                nberreur++;
            }
        }
        if (nberreur != 10) { // si il n'a pas 10 erreurs alors il est quelconque
            cout << "Les valeurs du tableau sont triées dans l\'ordre quelconque" << endl;
        } else { //sinon il est décroissant
            cout << "Les valeurs du tableau sont triées dans l\'ordre décroissant"<< endl;
        }
    }
}

void exercice3b() {
    // on instancie des entiers qui vont nous servir plus tard
    int tab[10];
    // on instancie des booleans qui vont nous servir plus tard
    bool estCroissant = true;
    bool estDecroissant = true;
    bool estConstant = true;

    // on crée le tableau dont on ne connait pas le tri
    int tableau[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    int premierElement = tab[0];
    for (int i = 1; i < 10; i++) {
        if (tab[i] < tab[i-1]) { //on regarde pour tout les élements si ils sont plus petit que leurs voisins d'avant
            estCroissant = false;
        }
        if (tab[i] > tab[i-1]) { //on regarde pour tout les élements si ils sont plus grand que leurs voisins d'avant
            estDecroissant = false;
        }
        if (tab[i] != premierElement) {
            estConstant = false;
        }
    }

    if (estCroissant) {
        cout << "Le tableau est trié dans l'ordre croissant." << endl;
    } else if (estDecroissant) {
        cout << "Le tableau est trié dans l'ordre décroissant." << endl;
    } else if (estConstant) {
        cout << "Le tableau est constant." << endl;
    } else {
        cout << "Le tableau n'est pas trié." << endl;
    }
}