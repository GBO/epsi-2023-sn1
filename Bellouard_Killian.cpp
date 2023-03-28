#include <iostream>
#include <vector>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

// Liste des prenoms utilisés pour les humains
const int NB_PRENOMS = 216;
std::string prenoms[NB_PRENOMS] = { "Axel", "Arthur", "Evan", "Adrien", "Alexis", "Antoine", "Adam", "Alexandre", "Baptiste", "Enzo", "Julien", "Leo", "Lucas", "Matteo", "Mael", "Maxime", "Gabriel", "Raphael", "Pierre", "Quentin", "Hugo", "Romain", "Theo", "Tom", "Jules", "Nicolas", "Louis", "Mathis", "Nathan", "Paul", "Valentin", "Ethan", "Kylian", "Matheo", "Aaron", "Antonin", "Anthony", "Ayoub", "Bastien", "Alan", "Aymeric", "Bryan", "Charles", "Elias", "Dorian", "Dylan", "Alex", "Augustin", "Alban", "Aurelien", "Benjamin", "Arnaud", "Gael", "Gabin", "Guillaume", "Florian", "Corentin", "Jean", "Jeremy", "Diego", "Emilien", "Esteban", "David", "Etienne", "Damien", "Erwan", "Lukas", "Loic", "Lorenzo", "Mathias", "Matthieu", "Gaetan", "Gaspard", "Morgan", "Rafael", "Kilian", "Samuel", "Simon", "Kevin", "Sacha", "Tristan", "Victor", "Jordan", "Killian", "Marius", "Vincent", "Martin", "Yann", "Mateo", "William", "Luca", "Remi", "Oscar", "Robin", "Noe", "Tony", "Tiago", "Thibaut", "Bilal", "Thibault", "Eliot", "Elouan", "Ilan", "Eliott", "Julian", "Kyllian", "Ewan", "Luka", "Camille", "Anais", "Clara", "Emma", "Charlotte", "Celia", "Eva", "Ambre", "Clemence", "Juliette", "Lena", "Lea", "Jeanne", "Julie", "Maeva", "Mathilde", "Louise", "Lucie", "Manon", "Noemie", "Jade", "Ines", "Sarah", "Laura", "Lola", "Oceane", "Pauline", "Romane", "Zoe", "Lina", "Lisa", "Maëlys", "Alicia", "Andrea", "Audrey", "Angele", "Adele", "Alexia", "Amandine", "Angelina", "Chiara", "Claire", "Coralie", "Elsa", "Agathe", "Constance", "Eleonore", "Elisa", "Elodie", "Fanny", "Alice", "Anna", "Apolline", "Candice", "Charline", "Elise", "Emilie", "Amelie", "Axelle", "Capucine", "Flavie", "Heloise", "Emeline", "Eloise", "Leonie", "Carla", "Cassandra", "Clarisse", "Elina", "Clementine", "Elena", "Marion", "Melina", "Marine", "Melissa", "Lise", "Mailys", "Melanie", "Flora", "Gabrielle", "Ninon", "Rose", "Salome", "Julia", "Lana", "Valentine", "Sofia", "Justine", "Myriam", "Maelle", "Maud", "Yasmine", "Lucile", "Maya", "Olivia", "Nina", "Sara", "Chaima", "Solene", "Clea", "Victoire", "Victoria", "Assia", "Elea", "Anaelle", "Alyssa", "Ilona", "Aya" };

// Génère un nom de zombie à partir d'un nom d'humain
// Le nom du zombie est composé de la première lettre du nom de l'humain
// en majuscule, suivi de deux fois cette même lettre en minuscule
std::string nomZombie(std::string nomHumain)
{
    char premiereLettre = nomHumain[0];

    std::string nom;
    nom.resize(3);

    nom[0] = toupper(premiereLettre);
    nom[1] = tolower(premiereLettre);
    nom[2] = tolower(premiereLettre);

    return nom;
}

// Une classe représentant un humain. Son constructeur
// prend en paramètre son nom.
// Il possède une méthode getNom() qui retourne son nom
// et une méthode afficher() qui affiche son nom
class Humain
{
public:
    Humain(std::string nom) : nom(nom) {}

    [[nodiscard]] inline std::string getNom() const { return nom; }

    void afficher() const
    {
        std::cout << "[HUMAIN] " << nom << std::endl;
    }

private:
    std::string nom;
};

// Une classe représentant un zombie. Son constructeur
// prend en paramètre un humain. L'humain va se transformer en zombie
// et son nom va être modifié en nomZombie(nomHumain)
// L'humain transformé en zombie est supprimé
// Il possède une méthode getNom() qui retourne son nom,
// une méthode manger(Humain* humain) qui transforme l'humain en zombie
// et une méthode afficher() qui affiche son nom
class Zombie
{
public:
    Zombie(Humain* humain)
    {
        nom = nomZombie(humain->getNom());
        delete humain;
    }

    [[nodiscard]] inline std::string getNom() const { return nom; }

    Zombie* manger(Humain* humain)
    {
        // On récupère le nom de l'humain mangé
        std::string nomHumain = humain->getNom();

        // On transforme l'humain en zombie
        Zombie* zombie = new Zombie(humain);

        // On affiche le résultat
        std::cout << nomHumain << " a été mangé par " << nom << " et devient " << zombie->getNom() << std::endl;
        
        return zombie;
    }

    void afficher()
    {
        std::cout << "[ZOMBIE] " << nom << std::endl;
    }

private:
    std::string nom;
};

// Une classe représentant la fin du monde. Elle contient
// une liste d'humains et une liste de zombies.
// Elle possède une méthode ajouterHumain(Humain* humain) qui ajoute un humain à la liste,
// une méthode debutDeLaFin() qui choisit un humain au hasard dans la liste
// et le transforme en zombie, en retournant le nom de l'humain transformé en zombie,
// et une méthode fin() qui fait se battre les zombies et les humains jusqu'à ce
// qu'il n'y ait plus d'humains
class FinDuMonde
{
public:
    void ajouterHumain(Humain* humain)
    {
        humains.push_back(humain);
    }

    std::string debutDeLaFin()
    {
        // On choisit un humain au hasard dans la liste
        int index = rand() % humains.size();

        std::string nomHumain = humains[index]->getNom();
        
        // On transforme l'humain en zombie
        zombies.push_back(new Zombie(humains[index]));
        humains.erase(humains.begin() + index);

        // Et on retourne le nom de l'humain transformé en zombie
        return nomHumain;
    }

    void fin()
    {
        // On affiche le statut actuel : nombre d'humains, et premier zombie créé.
        std::cout << "Il y a actuellement " << humains.size() << " humains." << std::endl;
        std::string nouveauZombie = debutDeLaFin();
        std::cout << nouveauZombie << " est devenu un zombie, c'est le début de la fin !" << std::endl;

        int tour = 0;
        while (humains.size() > 0)
        {
            // A chaque tour, on affiche le nombre d'humains et de zombies.
            // On fait manger un humain à chaque zombie, et on supprime l'humain mangé.
            // Si il n'y a plus d'humains, on sort de la boucle.
            // A la fin du tour, on ajoute les nouveaux zombies à la liste des zombies.
            std::cout << "Tour " << tour + 1
                << " - Il reste " << humains.size() << " humains en vie, et il y a "
                << zombies.size() << " zombies." << std::endl;
            
            std::vector<Zombie*> nouveauxZombies;
            for (Zombie* zombie : zombies)
            {
                // On trouve un humain au hasard
                int index = rand() % humains.size();

                // On fait manger l'humain au zombie
                // On affiche -> pour plus de lisibilité
                std::cout << " -> ";
                nouveauxZombies.push_back(zombie->manger(humains[index]));

                // On supprime l'humain mangé (la mémoire est libérée par le zombie)
                humains.erase(humains.begin() + index);

                // Si il n'y a plus d'humains, on sort de la boucle
                if (humains.size() == 0)
                {
                    break;
                }
            }

            // On ajoute les nouveaux zombies à la liste des zombies
            zombies.insert(zombies.end(), nouveauxZombies.begin(), nouveauxZombies.end());

            tour++;
        }

        // c'est la fin du monde ! On affiche le nombre de tours pendant lesquels les humains ont survécu.
        std::cout << "Il n'y a plus d'humains en vie, les zombies ont gagné en " << tour << " tours !" << std::endl;
    }

    ~FinDuMonde()
    {
        // On libère la mémoire des humains et des zombies
        for (Humain* humain : humains)
        {
            delete humain;
        }

        for (Zombie* zombie : zombies)
        {
            delete zombie;
        }
    }

private:
    std::vector<Humain*> humains;
    std::vector<Zombie*> zombies;
};

int main()
{
#ifdef WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    srand(time(NULL));

    // Exercice 1
    std::cout << "Bob -> " << nomZombie("Bob") << std::endl;
    std::cout << "Alice -> " << nomZombie("Alice") << std::endl;

    // Exercice 2
    Humain* bob = new Humain("Bob");
    Humain* alice = new Humain("Alice");

    bob->afficher();
    alice->afficher();

    // Exercice 3
    Zombie* zombieBob = new Zombie(bob);
    Humain* Alex = new Humain("Alex");

    zombieBob->afficher();
    Alex->afficher();

    Zombie* zombieAlex = zombieBob->manger(Alex);
    zombieAlex->afficher();

    // Exercice 4
    FinDuMonde* finDuMonde = new FinDuMonde();

    // On cherche 10 prénoms au hasard dans la liste, il faut donc
    // stocker les indices des prénoms déjà choisis pour ne pas les
    // choisir deux fois
    std::vector<int> indices;
    for(int i = 0; i < 10; i++)
    {
        // On cherche un index au hasard, et on recommence tant que
        // l'index est présent dans la liste des indices déjà choisis
        // (std::find(it_begin, it_end, value) cherche value entre it_begin
        // et it_end, et retourne it_end si value n'est pas trouvé)
        int index;
        do
        {
            index = rand() % NB_PRENOMS;
        } while(std::find(indices.begin(), indices.end(), index) != indices.end());

        // On ajoute l'index à la liste des indices déjà choisis
        indices.push_back(index);

        // On crée un humain et on l'ajoute à la fin du monde
        Humain* humain = new Humain(prenoms[index]);
        finDuMonde->ajouterHumain(humain);
    }

    // Finalement, on déclenche la fin du monde
    finDuMonde->fin();

    delete finDuMonde;

    // Pour tester avec 216 humains :
    finDuMonde = new FinDuMonde();

    for(int i = 0; i < NB_PRENOMS; i++)
    {
        Humain* humain = new Humain(prenoms[i]);
        finDuMonde->ajouterHumain(humain);
    }

    finDuMonde->fin();

    // On libère la mémoire
    delete finDuMonde;
    delete zombieAlex;
    delete zombieBob;
    delete alice;

    return 0;
}