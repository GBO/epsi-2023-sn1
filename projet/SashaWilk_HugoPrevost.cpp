#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

//définition de la classe Capacite, qui représente les capacités d'un Combattant
class Capacite {
private:
    string nom; //nom de la capacité
    int cout_energie; //coût en énergie de la capacité
    int puissance_atk; //puissance d'attaque de la capacité
    int puissance_ki; //puissance de ki de la capacité
    int cooldown; //temps de recharge de la capacité
    int temps_restant; //temps restant avant de pouvoir réutiliser la capacité

public:
    Capacite(string nom, int cout_energie, int puissance_atk, int puissance_ki, int cooldown) { //constructeur de la classe Capacite
        this->nom = nom;
        this->cout_energie = cout_energie;
        this->puissance_atk = puissance_atk;
        this->puissance_ki = puissance_ki;
        this->cooldown = cooldown;
        this->temps_restant = 0;
    }

    string getNom_capacite() { //méthode pour obtenir le nom de la capacité
        return nom;
    }

    int getCout_energie() { //méthode pour obtenir le coût en énergie de la capacité
        return cout_energie;
    }

    int getPuissance_atk() { //méthode pour obtenir la puissance d'attaque de la capacité
        return puissance_atk;
    }

    int getPuissance_ki() { //méthode pour obtenir la puissance de ki de la capacité
        return puissance_ki;
    }

    int getCooldown() { //méthode pour obtenir le temps de recharge de la capacité
        return cooldown;
    }

    int getTemps_restant() { //méthode pour obtenir le temps restant avant de pouvoir réutiliser la capacité
        return temps_restant;
    }

    void setTemps_restant(int temps) { //méthode pour modifier le temps restant avant de pouvoir réutiliser la capacité
        temps_restant = temps;
    }
};

//définition de la classe Combattant, qui représente un combattant quelconque
class Combattant {
public:
    int _pv; //points de vie du combattant
    int _Maxpv; //points de vie maximum du combattant
    int _atk; //puissance d'attaque du combattant
    int _def; //puissance de défense du combattant
    int _ki; //puissance de Ki du combattant
    int _rki; //valeur de recharge de Ki du combattant
    int _vit; //vitesse du combattant
    int _mp; //points d'énergie (MP) du combattant
    vector<Capacite*> vecteur_capacite; //vecteur contenant les capacités acquises par le combattant
    vector<Capacite*> vecteur_capacite_base; //vecteur contenant les capacités de base (non acquises) du combattant

    Combattant(int pv, int Maxpv, int atk, int def, int ki, int rki, int vit, int mp, vector<Capacite*> vecteur, vector<Capacite*> vecteur_base) : _pv(pv), _Maxpv(Maxpv), _atk(atk), _def(def), _ki(ki), _rki(rki), _vit(vit), _mp(mp), vecteur_capacite(vecteur), vecteur_capacite_base(vecteur_base) {} //constructeur de la classe Combattant

    virtual void action() {} //méthode virtuelle pour représenter une action (à redéfinir dans les classes filles)
};

//définition de la classe Perso, qui représente le personnage du joueur
class Perso : public Combattant {
private:
    string p_nom; //nom du personnage

public:
    Perso() = default;
    Perso(string nom, int pv,int Maxpv, int atk, int def, int ki, int rki, int vit, int mp, vector<Capacite*> vecteur, vector<Capacite*> vecteur_base) : Combattant(pv, Maxpv, atk, def, ki, rki, vit, mp, vecteur, vecteur_base), p_nom(nom) {}

    string getNom() { //méthode pour obtenir le nom du personnage
        return p_nom;
    }

    int getPV() { //méthode pour obtenir les points de vie de la personnage
        return _pv;
    }

    int getMaxPV() { //méthode pour obtenir les points de vie maximum de la personnage
        return _Maxpv;
    }

    int getAttaque() { //méthode pour obtenir la puissance d'attaque du personnage
        return _atk;
    }

    int getDeffense() { //méthode pour obtenir la puissance de défense du personnage
        return _def;
    }

    int getKi() { //méthode pour obtenir la puissance de Ki du personnage
        return _ki;
    }

    int getVitesse() { //méthode pour obtenir la vitesse du personnage
        return _vit;
    }

    int getEnergie() { //méthode pour obtenir les points d'énergie (MP) du personnage
        return _mp;
    }

    int getMaxEnergie() { //méthode pour obtenir la valeur de recharge de Ki du personnage
        return _rki;
    }

    void afficherInfo() { //méthode pour afficher les informations principales du personnage (nom, PV et MP)
        cout << p_nom << " - PV : " << _pv << "/" << _Maxpv << " - Energie : " << _mp << "/" << _rki << endl;
    }

    void afficherAllInfo() { //méthode pour afficher toutes les informations du personnage (nom, PV max, MP max, attaque, défense, puissance de Ki, recharge de Ki et vitesse)
        cout << p_nom << " - PV : " << _Maxpv << " - Energie Max :  " << _rki << " - Attaque : " << _atk << " - Defense : " << _def
             << " - Puissance de Ki : " << -_ki << " - Recharge de Ki : " << _rki << " - Vitesse : " << _vit << endl;
    }

    bool estVivant() { //méthode pour déterminer si le personnage est vivant (PV > 0)
        return _pv > 0;
    }

//methode de calcul de degat
// il faut faire en sorte que quand une capacite n'est pas utilisable on repropose le choix
    void calcul_degat(Perso& cible, Capacite* capacite) {
        if (capacite->getTemps_restant() == 0) { // Verifie si la capacité est disponible
            _mp -= capacite->getCout_energie(); // Enlève le coût de la capacité à l'énergie du personnage utilisant la capacité
            int degats = (_atk * capacite->getPuissance_atk() + _ki * capacite->getPuissance_ki()) / _def; // Calcul les dégâts infligés
            cible._pv -= degats; // Enlève les points de vie correspondants aux dégâts infligés à la cible
            cout << p_nom << " utilise " << capacite->getNom_capacite() << " et fait " << degats << " degats a " << cible.getNom() << "." << endl;
            capacite->setTemps_restant(capacite->getCooldown()); // Initialise le temps de recharge de la capacité
        } else {
            cout << p_nom << " ne peut pas utiliser cette capacite - Cooldown : " << capacite->getTemps_restant() << endl;
        }
    }

//methode pour la recharge
    void recharge(Perso& cible) {
        int bonnus = 20 + _rki / 5; // Calcul le bonus d'énergie gagnée par le personnage
        _mp += bonnus; // Ajoute le bonus d'énergie au personnage
        if (_mp > _rki) { // Vérifie si l'énergie totale est supérieure à la limite
            _mp = _rki; // Limite l'énergie totale au maximum
        }
    }

};

class Bot : public Combattant {
private:
    string b_nom;

public:
    Bot(string nom, int pv, int Maxpv, int atk, int def, int ki, int rki, int vit, int mp, vector<Capacite*> vecteur, vector<Capacite*> vecteur_base)
            : Combattant(pv, Maxpv, atk, def, ki, rki, vit, mp, vecteur, vecteur_base), b_nom(nom) {}

};

class Combat {
private:
    Perso *combattant1;
    Perso *combattant2;

public:
    Combat(Perso *p1, Perso *p2) { // Initialise les deux personnages combattants du combat
        combattant1 = p1;
        combattant2 = p2;
    }

    bool peut_utiliser_capacite(int index, int a) const { // Vérifie si le personnage a assez d'énergie pour utiliser une capacité donnée
        if (index == -1) {
            return true; // Si le choix est 0 la méthode prend en index -1 qui n'existe pas, donc on return automatiquement true
        } else if (a == 0 && index != 1) { // Vérifie si la capacité est de base et si le choix est différent de "recharge"
            return true;
        } else {
            return (combattant1->getEnergie() >= combattant1->vecteur_capacite[index]->getCout_energie()); // Vérifie si l'énergie disponible est suffisante pour la capacité sélectionnée
        }
    }

    void choix() {
        for (int i = 0; i < 2; ++i) {// Boucle pour les deux joueurs
            if (i == 1) {
                swap(combattant1, combattant2); // Échange les personnages combattants pour le tour du joueur 2
            }

            // Choix de l'action
            etiquette_retour :
            int choix_capacite;
            do { // Boucle pour forcer un choix valide de l'utilisateur
                cout << "1 - Capacite De Base " << endl;
                cout << "2 - Capacite Speciale " << endl;
                cout << " choisir une action : ";
                cin >> choix_capacite;
            } while (choix_capacite < 1 || choix_capacite > 2);

            if (choix_capacite == 1) { // Si l'utilisateur choisit d'utiliser une capacité basique
                int choix_capacite_base = 0;
                do { // Boucle pour forcer un choix valide de l'utilisateur
                    if (!peut_utiliser_capacite(choix_capacite_base - 1, 0)) {
                        cout << combattant1->getNom() << " ne peut pas utiliser cette capacite - Energie restante : "
                             << combattant1->getEnergie() << endl;
                    }
                    cout << "0 - Retour" << endl;
                    cout << "1 - Attaque Physique - puissance physique : 20 - cout : 0 " << endl;
                    cout << "2 - Attaque de Ki - puissance de ki : 30 - cout : 5 " << endl;
                    cout << "3 - Recharge - cout : 0 " << endl;
                    cout << " choisir une action : ";
                    cin >> choix_capacite_base; // Demande à l'utilisateur un choix de capacité de base
                } while (choix_capacite_base < 0 || choix_capacite_base > 3 || !peut_utiliser_capacite(choix_capacite_base - 1, 0));

                if (choix_capacite_base == 0) { // Si l'utilisateur choisit de retourner au menu précédent
                    goto etiquette_retour;
                }
                else if (choix_capacite_base == 1) {
                    combattant1->calcul_degat(*combattant2, combattant1->vecteur_capacite_base[0]); // Utilise la capacité d'attaque physique de base
                } else if (choix_capacite_base == 2) {
                    combattant1->calcul_degat(*combattant2, combattant1->vecteur_capacite_base[1]); // Utilise la capacité d'attaque de Ki de base
                } else {
                    combattant1->recharge(*combattant1); // Utilise la capacité de recharge
                }
            } else if (choix_capacite == 2) { // Si l'utilisateur choisit d'utiliser une capacité spéciale
                int choix_capacite_spe = 0;
                do { // Boucle pour forcer un choix valide de l'utilisateur
                    if (!peut_utiliser_capacite(choix_capacite_spe - 1, 1)) {
                        cout << combattant1->getNom() << " ne peut pas utiliser cette capacite - Energie restante : "
                             << combattant1->getEnergie() << endl;
                    }
                    cout << "0 - Retour" << endl;
                    for (int i = 0; i < 4; i++) { // Boucle pour afficher les choix possibles de capacités
                        cout << i + 1 << " - ";
                        cout << (i == 3 ? "ULTIMATE : " : "") << combattant1->vecteur_capacite[i]->getNom_capacite()
                             << " - puissance physique : " << combattant1->vecteur_capacite[i]->getPuissance_atk()
                             << " - puissance de ki : " << combattant1->vecteur_capacite[i]->getPuissance_ki()
                             << " - cout : " << combattant1->vecteur_capacite[i]->getCout_energie() << endl;
                    }
                    cout << " choisir une action : ";
                    cin >> choix_capacite_spe; // Demande à l'utilisateur un choix de capacité spéciale
                } while (choix_capacite_spe < 0 || choix_capacite_spe > 4 || !peut_utiliser_capacite(choix_capacite_spe - 1, 1));

                if (choix_capacite_spe == 0) { // Si l'utilisateur choisit de retourner au menu précédent
                    goto etiquette_retour;
                }
                for (int i = 0; i < combattant1->vecteur_capacite.size(); i++) {
                    if (choix_capacite_spe == i + 1) {
                        combattant1->calcul_degat(*combattant2, combattant1->vecteur_capacite[i]); // Utilise la capacité spéciale choisie
                        break; // Arrête la boucle une fois la méthode exécutée
                    }
                }
            }
            if (!combattant2->estVivant()) { // Vérifie si le personnage 2 est mort, si oui arrête le combat
                break;
            }
            if (i == 1) {
                swap(combattant1, combattant2); // Échange les personnages combattants pour afficher les informations dans le bon ordre
            }
        }
    }

    void combat_start() {

        cout << combattant1->getNom() << " VS " << combattant2->getNom() << " !! " << endl;
        cout << "Le combat commence !" << endl;// debut du combat

        int echange = 0; //pour que l'afichage des infos des perso reste dans le bon ordre
        int tour = 1; // initialisation du compteur de tour
        while (combattant1->estVivant() && combattant2->estVivant()) {

            if (echange == 1) {
                swap(combattant1, combattant2);
                echange = 0;
            }//pour que l'afichage des infos des perso reste dans le bon ordre
            // Affichage des informations des personnages
            combattant1->afficherInfo();
            combattant2->afficherInfo();

            // Calcul de qui commence en fonction de la vitesse
            int random_start = rand() % 2; // si meme vitesse, le joueur qui commence est defini aléatoirement
            if (combattant2->getVitesse() > combattant1->getVitesse() ||
                (combattant2->getVitesse() == combattant1->getVitesse() && random_start == 1)) {
                swap(combattant1, combattant2);
                echange = 1;
            }
            cout << "Tour " << tour << endl; // affichage du numéro de tour
            tour++;
            cout << combattant1->getNom() << " est plus rapide, il commence." << endl;

            choix();

            // Fin de partie
            if (!combattant1->estVivant()) {
                cout << combattant1->getNom() << " est KO. " << combattant2->getNom() << " a gagne !" << endl;
            } else if (!combattant2->estVivant()) {
                cout << combattant2->getNom() << " est KO. " << combattant1->getNom() << " a gagne !" << endl;
            }
        }
    }
};


int main() {

    //création des capacités des persos
    vector<Capacite*> capacite_goku{
            new Capacite ("Teleportation", 10, 20, 0, 2),//evite la prochaine attk
            new Capacite ("Poing du dragon", 0, 60, 0, 2),
            new Capacite ("Kamehameha", 60, 0, 80, 1),
            new Capacite ("Charge et Super Kamehameha", 100, 50, 100, 4),//+1atk/ki
    };

    vector<Capacite*> capacite_vegeta{
            new Capacite ("Rafale d Energie", 30, 0, 20*2, 1),
            new Capacite ("Garrick Canon", 50, 0, 60, 1),
            new Capacite ("Finnal Flash", 70, 0, 80, 1),
            new Capacite ("Big Bang Attack", 130, 0, 150, 3),
    };

    vector<Capacite*> capacite_gohan{
            new Capacite ("Rapide Kamehameha", 30, 0, 40, 1),
            new Capacite ("Coup de Pied Circulaire", 0, 50, 0, 2),
            new Capacite ("Makankosappo", 70, 0, 80, 1),
            new Capacite ("Kamehameha Pere Fils", 110, 0, 170, 3),//-1atk/ki
    };

    vector<Capacite*> capacite_cell{
            new Capacite ("Regeneration", 30, 0, 0, 2),//+100hp
            new Capacite ("Clones Explosifs", 10, 20, 0, 1),//40atk quand sub dgt
            new Capacite ("Kamehameha/Makankosappo/Finnal Flash", 70, 0, 80, 1),
            new Capacite ("Auto Destruction", 110, 140, 0, 4),//+60hp
    };

    vector<Capacite*> capacite_freezer{
            new Capacite ("Etrabglement", 10, 20, 10, 2),//-1vit pour enemi
            new Capacite ("Telekinesie", 0, 50, 0, 2),//-1vit pour enemi
            new Capacite ("Rayon de la Mort", 60, 0, 60, 1),//ignore 1 def
            new Capacite ("Boule de la Mort", 120, 0, 140, 3),//+1vit et +50hp
    };

    vector<Capacite*> capacite_broly{
            new Capacite ("Eraser Canon", 40, 10, 40, 1),
            new Capacite ("Bouclier d Energie", 50, 0, 50, 1),//+1def -50dgt
            new Capacite ("Gigantic Hammer", 0, 80, 0, 2),
            new Capacite ("Omega Blaster", 90, 0, 140, 3),//invincible au prochain tour et tjs 140 de ki
    };

    vector<Capacite*> capacite_base{
            new Capacite ("Attaque Physique", 0, 20, 0, 0),
            new Capacite ("Attaque de Ki", 5, 0, 30, 0),
            new Capacite ("Recharge", 0, 0, 0, 0),//recharge de l'energie
    };
    srand(time(0)); // pour la fonction rand
    // Création des personnages
    vector<Perso*> personnages{
            new Perso ("Goku", 300, 300, 120, 100, 110, 100, 130, 50, capacite_goku, capacite_base),
            new Perso ("Vegeta", 300, 300, 100, 100, 130, 130, 100, 65, capacite_vegeta, capacite_base),
            new Perso ("Gohan", 270, 270, 120, 100, 120, 110, 120, 55, capacite_gohan, capacite_base),
            new Perso ("Cell", 330, 330, 110, 110, 110, 110, 110, 55, capacite_cell, capacite_base),
            new Perso ("Freezer", 330, 330, 90, 120, 120, 120, 100, 60, capacite_freezer, capacite_base),
            new Perso ("Broly", 390, 390, 130, 130, 100, 90, 80, 45, capacite_broly, capacite_base),
    };

    Perso* choix_perso1 = nullptr;
    Perso* choix_perso2 = nullptr;

    // choix des persos pour les deux joueurs
    for (int i = 1; i <=2; ++i) {

        int choix_perso = NULL;
        int compteur = 0;
        while (choix_perso < 1 || choix_perso > personnages.size()) {
            compteur ++;
            if (compteur > 1) { cout << "Choix non valide reessayer avec un nombre compris entre 1 et " << personnages.size() << endl; } // affiche un message d'erreur sauf au premier tour
            for (int j = 0; j < personnages.size(); ++j) {
                cout << j + 1 << " - " << personnages[j]->getNom() << endl; // affiche la liste des personnages disponibles
            }
            cout <<"Joueur " << i <<" Choisissez votre personnage : ";
            cin >> choix_perso; // demande a choisir un personnage
        }

        // récupérer le perso choisi en le selectionnant dans le vecteur
        Perso* perso_choisi = personnages[choix_perso - 1];

        // afficher le perso choisi
        cout << "Joueur " << i <<" Vous avez choisi " << perso_choisi->getNom() << endl;
        perso_choisi->afficherInfo();

        if (i == 1) {
            choix_perso1 = perso_choisi;
        } else {
            choix_perso2 = perso_choisi;
        }
    }

    Combat JcJ(choix_perso1, choix_perso2);
    JcJ.combat_start();

    return 0;
}
