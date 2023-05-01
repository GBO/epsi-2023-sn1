#pragma once

#include <iostream>
#include <string>
#include <array>
#include <sstream>

using namespace std;

//On affiche le tableau vide
void printBoard(string board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "" << endl;
    }
}


bool checkDiagonal(string board[3][3], string symbol) {
    //On vérifie si chaque symbole dans la diagonale est similaire
    for (int i = 0; i < 3; i++) {
        //première possibilité de diagonale du haut à gauche vers le bas à droite
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        //deuxième possibilité de diagonale du haut à droite au bas à gauche
        if (board[0][2] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[2][0]) {
            return true;
        }
    }
    return false;
}

// Verticale
bool checkVertical(string board[3][3], string symbol) {
    //vérifier si toutes les valeurs de la colonne ont le même symbole
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    return false;
}

//Horizontal
bool checkHorizontal(string board[3][3], string symbol) {
    //vérifier si toutes les valeurs d'une ligne ont le même symbole
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    return false;
}
//On regarde si l'emplacement est déjà occupé
bool checkLocation(string board[3][3], int& desired_location, int& row, int& col) {
    //On initialise la variable
    int location_on_board;
    //Verifie emplacement
    //Passe en revue chaque emplacement du tableau pour voir si la valeur est égale à l'entrée de l'utilisateur
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //conversion int en string
            istringstream(board[i][j]) >> location_on_board;
            //si la valeur est égale à l'entrée de l'utilisateur, la ligne et la colonne sont enregistrées
            if (location_on_board == desired_location) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

//suit les scores du joueur X et du joueur O
//Regarde qui a gagné la partie
bool checkGameWon(string board[3][3], string symbol, int& score_x, int& score_o) {

    //On vérifie si ça gagne verticalement
    //adding score count to the winner (either Player X or Player O)
    if (checkVertical(board, symbol)) {
        if (symbol == "X") {
            score_x++;
        }
        else {
            score_o++;
        }
        printBoard(board);
        cout << symbol << " est le vainqueur ! " << endl;
        return true;
    }
        //On vérifie si ça gagne horizontalement
        //adding score count to the winner (either Player X or Player O)
    else if (checkHorizontal(board, symbol)) {
        if (symbol == "X") {
            score_x++;
        }
        else {
            score_o++;
        }
        printBoard(board);
        cout << symbol << " est le vainqueur ! " << endl;
        return true;
    }
        //On vérifie si ça gagne diagonalement
        //adding score count to the winner (either Player X or Player O)
    else if (checkDiagonal(board, symbol)) {
        if (symbol == "X") {
            score_x++;
        }
        else {
            score_o++;
        }
        cout << symbol << " est le vainqueur ! " << endl;
        return true;
    }
    return false;
}
//Vérifie si égalité et met à jour le score
bool checkGameTie(string board[3][3], string symbol, int counter, bool winner_determined, int& number_of_ties) {
    if (counter == 15 && !winner_determined) {
        number_of_ties++;
        return true;
    }
    return false;
}
// Mise à jour de la grille au fur et à mesure du jeu
void updateBoard(bool& continue_game, int& player_counter, int& score_x, int& score_o, int& counter, int& number_of_ties) {

    string board[3][3] = { {"1", "2", "3"},
                           {"4", "5", "6"},
                           {"7", "8", "9"}};
    int desired_location;
    int row, col;
    string location_on_board;
    string symbol;
    bool valid_location = false;
    bool winner_determined = false, invalid_input = true, tie = false;
    char play_again = 'n';

    for (int i = 0; i < 9 && !winner_determined; i++) {

        printBoard(board);
        //Détermine si l'emplacement souhaité est valable
        while (!valid_location) {
            cout << "Entrez le chiffre de l'emplacement souhaite (1-9): ";
            cin >> desired_location;
            if (desired_location >= 1 && desired_location <= 9 && checkLocation(board, desired_location, row, col)) {
                valid_location = true;
            }
            else {
                cout << "Emplacement deja selectionne.. ";
            }
        }

        // Si le compteur de parties est pair, le premier joueur sera le joueur X, sinon le premier joueur sera le joueur O

        if (player_counter % 2 == 0 && counter % 2 == 0) {
            board[row][col] = "X";
            symbol = "X";
        }
        else if (player_counter % 2 == 0 && counter % 2 == 1) {
            board[row][col] = "O";
            symbol = "O";
        }
        else if (player_counter % 2 == 1 && counter % 2 == 0) {
            board[row][col] = "O";
            symbol = "O";
        }
        else {
            board[row][col] = "X";
            symbol = "X";
        }
        //Détermine s'il y a un gagnant
        winner_determined = checkGameWon(board, symbol, score_x, score_o);

        //Détermine s'il y a une égalité
        tie = checkGameTie(board, symbol, counter, winner_determined, number_of_ties);

        //Option si gagnant et donc fin de manche
        if (winner_determined) {
            while (invalid_input) {
                cout << "Would you like to play again? (Y/N)" << endl;
                cin >> play_again;


                if (play_again == 'Y' || play_again == 'y') {
                    continue_game = true;
                    invalid_input = false;
                }

                else if (play_again == 'N' || play_again == 'n') {
                    continue_game = false;
                    invalid_input = false;
                    cout << "Nombre de victoires du joueur X : " << score_x << endl;
                    cout << "Nombre de victoires du joueur O : " << score_x << endl;
                    cout << "Nombre d'egalites : " << number_of_ties << endl;
                    cout << "Le jeu est terminé ! Merci d'avoir joué !" << endl;
                    exit(0);
                }
            }
        }
        //Si le score final est nul
        if (tie) {
            printBoard(board);
            while (invalid_input) {
                cout << "Il y a match nul ! Voulez-vous jouer à nouveau ? (Y/N)" << endl;
                cin >> play_again;

                if (play_again == 'Y' || play_again == 'y') {
                    continue_game = true;
                    invalid_input = false;
                }

                else if (play_again == 'N' || play_again == 'n') {
                    continue_game = false;
                    invalid_input = false;

                    cout << "Nombre de victoires du joueur X : " << score_x << endl;
                    cout << "Nombre de victoires du joueur O : " << score_o << endl;
                    cout << "Nombre d'egalites : " << number_of_ties << endl;
                    cout << "Le jeu est terminé ! Merci d'avoir joué ! " << endl;
                    exit(0);
                }
            }
        }
        //updates variables
        counter++;
        valid_location = false;
        invalid_input = true;
    }

    //reset variables
    player_counter++;
    counter = 0;
}

void startMorpion() {

    bool continue_game = true;
    int score_x = 0, score_o = 0;
    int counter = 0, player_counter = 0;
    int number_of_ties = 0;


    while (continue_game) {
        updateBoard(continue_game, player_counter, score_x, score_o, counter, number_of_ties);
    }
}