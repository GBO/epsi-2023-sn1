#include <iostream>
#include <string>

class Humain {
public:
    Humain(const std::string& nom) : nom_(nom) {} // je defini le nom avec string

    std::string getNom() const { return nom_; } // j'utilise un getter pour l'attribut du nom

    void afficher() const { std::cout << "Je suis un Humain et mon prénom est " << nom_ << std::endl; } // j'utilise la méthode afficher()

private:
    std::string nom_; // attribut privé
};

int main() {
    Humain h1("Gorane");
    Humain h2("Louis");

    h1.afficher();
    h2.afficher();

    return 0;
}
