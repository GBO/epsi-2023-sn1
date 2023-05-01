#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Case {
public:
    Case(bool mine = false) : m_isMine(mine), m_isDiscovered(false), m_isFlagged(false) {}
    bool isMine() const { return m_isMine; }
    bool isDiscovered() const { return m_isDiscovered; }
    bool isFlagged() const { return m_isFlagged; }
    void setDiscovered() { m_isDiscovered = true; }
    void setFlagged() { m_isFlagged = true; }
private:
    bool m_isMine;
    bool m_isDiscovered;
    bool m_isFlagged;
};

class Demineur {
public:
    Demineur(int size, int mines) : m_size(size), m_mines(mines), m_gameOver(false), m_remaining(m_size * m_size - m_mines) {
        // initialiser la grille de cases
        for (int i = 0; i < m_size; i++) {
            vector<Case> row;
            for (int j = 0; j < m_size; j++) {
                row.push_back(Case());
            }
            m_cases.push_back(row);
        }

        // placer les mines aléatoirement
        srand(time(NULL));
        int count = 0;
        while (count < m_mines) {
            int i = rand() % m_size;
            int j = rand() % m_size;
            if (!m_cases[i][j].isMine()) {
                m_cases[i][j] = Case(true);
                count++;
            }
        }
    }

    void run() {
        while (!m_gameOver) {
            draw();
            int row, col;
            cout << "Entrez la ligne et la colonne (séparées par un espace) : ";
            cin >> row >> col;
            if (row < 0 || row >= m_size || col < 0 || col >= m_size) {
                cout << "Coordonnées invalides !" << endl;
            } else {
                int action;
                cout << "Que voulez-vous faire ? (1 = découvrir, 2 = mettre un drapeau) : ";
                cin >> action;
                if (action == 1) {
                    discover(row, col);
                } else if (action == 2) {
                    flag(row, col);
                } else {
                    cout << "Action invalide !" << endl;
                }
            }
        }
        draw();
        cout << "GAME OVER !" << endl;
    }

private:
    int m_size;
    int m_mines;
    bool m_gameOver;
    int m_remaining;
    vector<vector<Case>> m_cases;

    void draw()  {
        // dessiner la grille de cases
        cout << " ";
        for (int j = 0; j < m_size; j++) {
            cout << " " << j;
        }
        cout << endl;
        for (int i = 0; i < m_size; i++) {
            cout << i;
            for (int j = 0; j < m_size; j++) {
                cout << " ";
                if (m_cases[i][j].isFlagged()) {
                    cout << "F";
                } else if (m_cases[i][j].isDiscovered()) {
                    if (m_cases[i][j].isMine()) {
                        cout << "*";
                        m_gameOver = true;
                    } else {
                        int count = countMines(i, j);
                        cout << count;
                        if (count == 0) {
                            discoverNeighbours(i, j);
                        }
                    }
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << m_remaining << " cases restantes." << endl;
    }

    void discover(int row, int col) {
        if (m_cases[row][col].isFlagged()) {
            cout << "Cette case est marquée d'un drapeau !" << endl;
        } else if (m_cases[row][col].isDiscovered()) {
            cout << "Cette case a déjà été découverte !" << endl;
        } else if (m_cases[row][col].isMine()) {
            cout << "BOOM ! Vous avez touché une mine !" << endl;
            m_cases[row][col].setDiscovered();
            m_gameOver = true;
        } else {
            int count = countMines(row, col);
            m_cases[row][col].setDiscovered();
            m_remaining--;
            if (count == 0) {
                discoverNeighbours(row, col);
            }
            if (m_remaining == 0) {
                cout << "Félicitations ! Vous avez gagné !" << endl;
                m_gameOver = true;
            }
        }
    }

    void flag(int row, int col) {
        if (m_cases[row][col].isDiscovered()) {
            cout << "Cette case a déjà été découverte !" << endl;
        } else {
            m_cases[row][col].setFlagged();
        }
    }

    int countMines(int row, int col) const {
        int count = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i >= 0 && i < m_size && j >= 0 && j < m_size && m_cases[i][j].isMine()) {
                    count++;
                }
            }
        }
        return count;
    }

    void discoverNeighbours(int row, int col) {
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i >= 0 && i < m_size && j >= 0 && j < m_size && !m_cases[i][j].isMine() && !m_cases[i][j].isDiscovered()) {
                    discover(i, j);
                }
            }
        }
    }
};

int main() {
    int size, mines;
    cout << "Entrez la taille de la grille : ";
    cin >> size;
    cout << "Entrez le nombre de mines : ";
    cin >> mines;
    Demineur game(size, mines);
    game.run();
    return 0;
}

