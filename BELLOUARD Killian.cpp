#include <iostream>
#include <ctime>
#include <cstdlib>

// Inclusion des headers windows pour les charactères unicode (accents...)
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
namespace Windows
{
#include <windows.h>
}
#endif

int exercice1()
{
    // Inititulé de l'exercice et demande de saisie
    std::cout << "Exercice 1" << std::endl;
    std::cout << "Entrez le nombre de nombres entiers à calculer : ";
    int n;
    std::cin >> n;

    // On vérifie que le nombre soit valide
    if(n <= 0)
    {
        std::cerr << "Le nombre de nombres entiers à calculer doit être strictement positif" << std::endl;
        return 1;
    }

    // Le nombre actuellement testé
    int nombre = 2;

    // Boucle principale calculant les nombres premiers jusqu'à en avoir n
    while(n > 0)
    {
        // On cherche à savoir si le nombre a un diviseur autre que 1 et lui-même
        // Si j = nombre, la boucle s'arrête, et on commence la boucle avec j = 2,
        // donc les diviseurs 1 et nombre ne sont pas pris en comptes dans la
        // condition nombre % j == 0
        bool premier = true;
        for(int j = 2; j < nombre; j++)
        {
            // Si le nombre est divisible par j, alors il n'est pas premier
            if(nombre % j == 0)
            {
                premier = false;
                break;
            }
        }

        // Si le nombre est premier, on l'affiche et on décrémente n
        if(premier)
        {
            std::cout << nombre << " ";
            n--;
        }

        // A chaque tour de boucle, on incrémente nombre
        nombre++;
    }

    std::cout << std::endl;

    return 0;
}

int exercice2()
{
    // Intitulé de l'exercice
    std::cout << "Exercice 2" << std::endl;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // On génère un nombre aléatoire entre 0 et 6 (exclus), et on rajoute 1
    // pour avoir un nombre entre 1 et 6
    int de_joueur = rand() % 6 + 1;
    int de_ordinateur = rand() % 6 + 1;

    // On affiche les valeurs des dés et le résultat
    std::cout << "Le joueur a fait " << de_joueur << std::endl;
    std::cout << "L'ordinateur a fait " << de_ordinateur << std::endl;

    if(de_joueur > de_ordinateur)
    {
        std::cout << "Le joueur a gagné" << std::endl;
    }
    else if(de_joueur < de_ordinateur)
    {
        std::cout << "L'ordinateur a gagné" << std::endl;
    }
    else
    {
        std::cout << "Egalité" << std::endl;
    }

    return 0;
}

int exercice3()
{
    // Intitulé de l'exercice
    std::cout << "Exercice 3" << std::endl;

    int tableau[10];

    // On demande à l'utilisateur de saisir 10 nombres
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Entrez un nombre : ";
        std::cin >> tableau[i];
    }

    // Le tableau est constant ? (tab[i] == tab[i+1] pour tout i)
    bool constant = true;
    for(int i = 0; i < 9; i++)
    {
        if(tableau[i] != tableau[i+1])
        {
            constant = false;
            break;
        }
    }

    if(constant)
    {
        std::cout << "Le tableau est constant" << std::endl;
        return 0;
    }

    // Le tableau est croissant ? (tab[i] < tab[i+1] pour tout i)
    bool croissant = true;
    for(int i = 0; i < 9; i++)
    {
        if(tableau[i] > tableau[i+1])
        {
            croissant = false;
            break;
        }
    }

    if(croissant)
    {
        std::cout << "Le tableau est croissant" << std::endl;
        return 0;
    }

    // Le tableau est décroissant ? (tab[i] > tab[i+1] pour tout i)
    bool decroissant = true;
    for(int i = 0; i < 9; i++)
    {
        if(tableau[i] < tableau[i+1])
        {
            decroissant = false;
            break;
        }
    }

    if(decroissant)
    {
        std::cout << "Le tableau est décroissant" << std::endl;
        return 0;
    }

    // Si aucun des trois, le tableau est "quelconque"
    std::cout << "Le tableau n'est ni constant, ni croissant, ni décroissant" << std::endl;
    return 0;
}

int main()
{
    // Activation des charactères unicode (accents...)
#ifdef WIN32
    Windows::SetConsoleOutputCP(65001);
#endif

    // Premier exercice : affichage du menu
    std::cout << "0- Sortie" << std::endl;
    std::cout << "1- Exercice 1" << std::endl;
    std::cout << "2- Exercice 2" << std::endl;
    std::cout << "3- Exercice 3" << std::endl;

    // On récuper le choix de l'utilisateur
    std::cout << "> ";
    int choix;
    std::cin >> choix;

    // On teste chaque possibilité (1,2,3 et 0)
    if(choix == 1)
    {
        return exercice1();
    }
    else if(choix == 2)
    {
        return exercice2();
    }
    else if(choix == 3)
    {
        return exercice3();
    }
    else if(choix == 0)
    {
        return 0;
    }

    // Si aucun des choix n'est valide, on affiche un message d'erreur
    std::cerr << "Choix invalide" << std::endl;
    return 1;
}
