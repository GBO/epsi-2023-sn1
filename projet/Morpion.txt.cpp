#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Morpion {
private:
    vector<vector<char>> grille;
    int taille;
    vector<string> joueurs;
    vector<char> symboles;
    int joueurActuel = 0;
    int pointsPourGagner;

public:
    Morpion(int t, int p) {
    taille = t;
    pointsPourGagner = p;
    grille = vector<vector<char>>(taille, vector<char>(taille, '-'));
    }
    
    

    void ajouterJoueur(string nom) {
        joueurs.push_back(nom);
        symboles.push_back(toupper(nom[0]));
    }

    void setPointsPourGagner(int p) {
        pointsPourGagner = p;
    }

    void afficherGrille() {
        cout << "Morpion" << endl;
        for(int i = 0; i < taille; i++) {
         for(int j = 0; j < taille; j++) {
                cout << grille[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool finDePartie() {
        // ligne
        for(int i = 0; i < taille; i++) {
            int count = 0;
            for(int j = 0; j < taille; j++) {
                if(grille[i][j] == symboles[joueurActuel]) {
                    count++;
                }
            }
            if(count == pointsPourGagner) {
                return true;
            }
        }
        // colonne
        for(int j = 0; j < taille; j++) {
            int count = 0;
            for(int i = 0; i < taille; i++) {
                if(grille[i][j] == symboles[joueurActuel]) {
                    count++;
                }
            }
            if(count == pointsPourGagner) {
                return true;
            }
        }
        // diagonale
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < taille; i++) {
            if(grille[i][i] == symboles[joueurActuel]) {
                count1++;
            }
            if(grille[i][taille-i-1] == symboles[joueurActuel]) {
                count2++;
            }
        }
        if(count1 == pointsPourGagner || count2 == pointsPourGagner) {
            return true;
        }
        return false;
    }

    void jouer() {
        int ligne, colonne;
        while(!finDePartie()) {
            afficherGrille();
            cout << "Joueur " << joueurs[joueurActuel] << ", entrez d'abord la colonne puis la ligne pour jouer (séparées par un espace) : ";
            cin >> ligne >> colonne;
            ligne--;
            colonne--;
            if(ligne >= 0 && ligne < taille && colonne >= 0 && colonne < taille && grille[ligne][colonne] == '-') {
                grille[ligne][colonne] = symboles[joueurActuel];
                if(finDePartie()) {
                    cout << "Bravo, joueur " << joueurs[joueurActuel] << " a gagné !" << endl;
                    afficherGrille();
                    return;
                }
                joueurActuel = (joueurActuel + 1) % joueurs.size();
            } else {
                cout << "Mouvement invalide, veuillez réessayer." << endl;
            }
        }
        cout << "Match nul !" << endl;
        afficherGrille();
        }
    };


int main() {
    int taille, pointsPourGagner, nbJoueurs;
    cout << "Bienvenue au Morpion !" << endl;
    cout << "Entrez la taille de la grille : ";
    cin >> taille;
    cout << "Entrez le nombre de points nécessaires pour gagner : ";
    cin >> pointsPourGagner;
    cout << "Entrez le nombre de joueurs : ";
    cin >> nbJoueurs;
    Morpion morpion(taille, pointsPourGagner);

    for(int i = 0; i < nbJoueurs; i++) {
        string nom;
        cout << "Entrez le nom du joueur " << i+1 << " : ";
        cin >> nom;
        morpion.ajouterJoueur(nom);
    }

    morpion.jouer();

    return 0;
}