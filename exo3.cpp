#include <iostream>
#include <string>

class Humain {
    private:
        std::string nom;

    public:
        Humain(std::string nom) {
            this->nom = nom;
        }

        std::string getNom() {
            return nom;
        }

        void afficher() {
            std::cout << "Humain " << nom << std::endl;
        }
};

class Zombie {
    private:
        std::string nom;

    public:
        Zombie(Humain* humain) {
            nom = getZombieName(humain->getNom());
        }

        std::string getNom() {
            return nom;
        }

        Zombie* manger(Humain* humain) {
            std::cout << nom << " mange " << humain->getNom() << std::endl;
            return new Zombie(humain);
        }

        void afficher() {
            std::cout << nom << " devient un Zombie " << std::endl;
        }

        static std::string getZombieName(std::string humanName) {
            std::string zombieName = "";

            for (char c : humanName) {
                switch (c) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        zombieName += 'm';
                        break;
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        zombieName += 'M';
                        break;
                    default:
                        zombieName += c;
                        break;
                }
            }

            zombieName += zombieName[0];
            zombieName += zombieName[0];

            return zombieName;
        }
};

int main() {
    // création d'un humain
    Humain* humain1 = new Humain("Gorane");
    humain1->afficher();

    // création d'un Zombie à partir de l'Humain
    Zombie* zombie1 = new Zombie(humain1);
    zombie1->afficher();

    // création d'un 2ème humain
    Humain* humain2 = new Humain("Louis");
    humain2->afficher();

    // Le Zombie mange le second Humain et créé un nouveau Zombie
    Zombie* zombie2 = zombie1->manger(humain2);
    zombie2->afficher();

    
    delete humain1;
    delete zombie1;
    delete humain2;
    delete zombie2;

    return 0;
}
