# TDN1 - 28/06/2023

**Attendu en fin de session** :
* Une application console C++ dans un unique fichier .cpp dont le nom commence par **votre nom de famille** et contenant les sources des différents exercices.
* Les classes qu’il est demandé de produire seront créées en début de fichier, les tests d’utilisation de ces classes seront mis dans la fonction `main` du fichier CPP, l’exercice clairement identifié.

**Critères de notation** :
* Originalité du code produit : dans le sens donner l'impression que le code est bien de l'auteur, et non un copier/coller barbare. Ce peut être mis en évidence par une bonne documentation du code, mettant en évidence la maitrise de ce qui est écrit.
* Lisibilité du code (commentaires dans le code, sortie explicite, …).
* Respect des exigences *Attendu en fin de session*.
* Respect des exigences de chaque exercice.
* Résultat attendu prouvé par un test.

**Conseils** :
* Lisez bien les intitulés : le respect de toutes les exigences est important.
* Ne restez pas bloqué sur un problème, essayez de contourner (retourner une valeur statique pour un calcul en respectant les consignes par exemple).
* Utilisez l’aide à votre disposition.
* Pour les instances de vos classes : utilisez des pointeurs pour en stocker les réfénces. Ca vous simplifiera la vie.
  * Dit autrement : faites toujours des `MaClasse* p = new MaClasse(...);`.



# Général (2 points)
Note sur l'aspect général de la copie :
* Lisibilité
* Respects des exigences



# Exercice 1 (5 points)
Ecrire une fonction permettant de générer un nombre aléatoire entre 2 bornes.

**Exigences** :
* La fonction doit retourner une valeur aléatoire.
* Les bornes minimum et maximum doivent être passées en paramètre.

**Tests** :
* Afficher un nombre aléatoire entre 1 (inclus) et 6 (inclus).
* Afficher 10 nombre aléatoires entre 100 (inclus) & 200 (inclus).



# Exercice 2 (6 points)
Ecrire une fonction permettant de simuler le lancement de 5 dés et d’annoncer la meilleure annonce produite.
Une annonce est au choix et dans l’ordre croissant de « puissance » :
1. Une paire : 2 dés avec la même valeur
2. Un brelan : 3 dés avec la même valeur
3. Un full : une paire & un brelan

**Exigences** :
* Le lancement d’un dé est un tir aléatoire entre 1 et 6.
* Après chaque tir, on affiche les valeurs de dés tirées, puis l’annonce trouvée (s’il y en a) avec les valeurs associées (Ex : Une paire de 4).

**Tests** :
* Exécuter la méthode pour prouver le tirage des 5 dés et de la détection de l'annonce



# Exercice 3 (7 points)
Ecrire une classe `Grille` implémentant un grille d’entiers à deux dimensions.

**Exigences** :
* Le constructeur prend en paramètre les dimensions de la grille.
* Une méthode `getValue` prenant en paramètre les coordonnées `x` & `y` dans la grille et retournant la valeur aux coordonnées indiquées.
* Une méthode `setValue` prenant en paramètre les coordonnées `x` & `y` dans la grille ainsi que la valeur à affecter.
* Une méthode `clear` permet de remettre à zéro toutes les valeurs de la grille.
* Une méthode `display` permet d’afficher la grille.

**Tests** :
* Initialiser une grille de 20 par 20 et l’afficher.
* Mettre des 1 dans les 2 diagonales (0x0, 1x1, 2x2, … Et 0x20, 1x19, 2x18, …).
* Afficher la grille.
* Refaire la même chose avec une 2ème grille de 10 par 10.



# Aide globale
* La fonction [`rand()`](https://en.cppreference.com/w/cpp/numeric/random/rand) de la bibliothèque [`cstdlib`](https://en.cppreference.com/w/cpp/header/cstdlib) permet de générer un nombre aléatoire entre `0` & [`RAND_MAX`](https://en.cppreference.com/w/cpp/numeric/random/RAND_MAX).
* Le générateur de nombre aléatoire doit être initialisé avec la fonction [`srand()`](https://en.cppreference.com/w/cpp/numeric/random/srand) en utilisant une graine (l’heure est communément utilisée grâce à la fonction [`time()`](https://en.cppreference.com/w/cpp/chrono/c/time) de la bibliothèque [`ctime`](https://en.cppreference.com/w/cpp/header/ctime)).
* Ci dessous un petit exemple d'utilisation :

```c++
// Inclusion des librairies
#include <iostream> // pour cin / cout
#include <cstdlib> // pour rand()
#include <ctime> // pour time()

// Utilisation du namespace std pour s'économiser quelques caractères plus bas.
// Sans cette instruction, il faudrait toujours utiliser `std::cout` au lieu de `cout`
using namespace std;

/** Un petit bloc de commentaire pour passer quelques infos sur l'exercice 1.
 * La fonction identifie clairement l'exercice...
 */
void exercice1() {
  // Ca nous empêche pas de le sortir sur la console au cas où.
  cout << "Exercice 1" << endl;
  // Ici une résolution du problème posé par l'exercice 1
}

// Un main dans lequel j'invoque quelques fonctions d'exercice...
int main(int argc, char **argv)
{
  cout << "TD Noté de Ghislain BOUCHET - EPSI - 16/03/2022" << endl;

  // Initialisation du générateur de nombre aléatoire
  srand(time(NULL));
  // Génération de nombres aléatoires
  int alea = rand();
  cout << "Nombre aléatoire brut : " << alea << endl;
  alea = rand() % 100;
  cout << "Nombre aléatoire entre 0 (inclu) et 99 (inclu) : " << alea << endl;

  // Et c'est parti !
  exercice1();

  return 0;
}
```
