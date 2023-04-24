#include <iostream>
#include <windows.h>

using namespace std;

char board[8][8] =
        {
                {' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n'},
                {'n', ' ', 'n', ' ', 'n', ' ', 'n', ' '},
                {' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
        };

char turn = 'N';
bool leap;
bool game_running = true;
int row1, row2, column1, column2;
int black_piece = 12;
int white_piece = 12;

void display_board();
void input();
bool check_move();
void move();
void do_leap();
void king();
void game_over();

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "---Jeu de Dames---\n";
    cout << "Joueur 1 [n]\n";
    cout << "Joueur 2 [b]\n\n";
    cout << "Une lettre capitale représente un pion roi\n";
    cout << "Veuillez redimensionner votre fenêtre de ligne de commande afin que cette ligne tienne à l'écran:\n";
    cout << "_____________________________________________________________________________________\n\n";
    cout << "Appuyez sur entrée pour commencer...";
    cin.get(); // On attend que le joueur appuie sur entrée pour continuer

    // La boucle qui fait tourner le jeu
    while (game_running)
    {
        display_board();

        if (turn == 'N')
        {
            cout << "--Joueur 1 [N]--\n";
        }
        else if (turn == 'B')
        {
            cout << "--Joueur 2 [B]--\n";
        }

        input();
        move();
        king();
        game_over();
    }

    // Determiner le gagnant à la fin
    if (turn == 'N')
    {
        cout << endl << endl << "Joueur 2 [Blanc] gagne!\n";
    }
    else if (turn == 'B')
    {
        cout << endl << endl << "Joueur 1 [Noir] gagne!\n";
    }

    cout << "GAME OVER!\n";
}

// Afficher le damier
void display_board()
{
    cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << "  _________________________________________________________________________________\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "0 |    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    "  << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "1 |    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    "  << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "2 |    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    "  << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "3 |    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    "  << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "4 |    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    "  << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "5 |    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    "  << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "6 |    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    "  << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "7 |    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    "  << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
}

// Prendre la réponse de l'utilisateur
void input()
{
    cout << "Nombre de pion blancs: " << white_piece << ", Nombre de pions noirs: " << black_piece << endl;
    cout << "Déplacer une pièce\n";
    cout << "Ligne: ";
    cin >> row1;
    cout << "Colonne: ";
    cin >> column1;

    while (row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)
    {
        cout << "Entrée incorrecte. Entrez des nombres entre 0 et 7.\n";
        cout << "Déplacer une pièce\n";
        cout << "Ligne: ";
        cin >> row1;
        cout << "Colonne: ";
        cin >> column1;
    }

    cout << "Vers la case\n";
    cout << "Ligne: ";
    cin >> row2;
    cout << "Colonne: ";
    cin >> column2;

    while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
    {
        cout << "Entrée incorrecte. Entrez des nombres entre 0 et 7.\n";
        cout << "Vers la case\n";
        cout << "Ligne: ";
        cin >> row2;
        cout << "Colonne: ";
        cin >> column2;
    }

    while (check_move() == false)
    {
        cout << "MOUVEMENT INTERDIT!\n";
        input();
    }
}

// Verifier si le mouvement est valide
bool check_move()
{
    // Vérifier si une pièce autre que le roi recule
    if (board[row1][column1] != 'N' && board[row1][column1] != 'B')
    {
        if ((turn == 'N' && row2 < row1) || (turn == 'B' && row2 > row1))
        {
            cout << "Impossible de reculer.\n";
            leap = false;
            return false;
        }
    }

    // Vérifie si l'emplacement vers lequel la pièce se déplace est déjà pris
    if (board[row2][column2] != ' ')
    {
        cout << "Case de destination déjà occupée.\n";
        leap = false;
        return false;
    }

    // Vérifier si l'emplacement entré par l'utilisateur contient une pièce à déplacer
    if (board[row1][column1] == ' ')
    {
        cout << "Il n'y a pas de pion à l'emplacement de départ.\n";
        leap = false;
        return false;
    }

    // Vérifier si la pièce ne se déplace pas en diagonale
    if (column1 == column2 || row1 == row2)
    {
        cout << "Les pions ne peuvent se déplacer qu'en diagonale.\n";
        leap = false;
        return false;
    }

    // Vérifier si la pièce se déplace de plus d'une colonne et d'une seule ligne
    if (board[row1][column1] != 'N' && board[row1][column1] != 'B')
    {
        if ((column2 > column1 + 1 || column2 < column1 - 1) && (row2 == row1 +1 || row2 == row1 - 1)) {
            cout << "Les pions ne peuvent pas se deplacer de plus d'une colonne/ligne.\n";
            leap = false;
            return false;
        }
    }

    // Vérifier si la pièce saute
    if (row2 > row1 + 1 || row2 < row1 - 1)
    {
        // Vérifier si la pièce saute trop loin
        if (row2 > row1 + 2 || row2 < row1 - 2)
        {
            cout << "Le pion est sauté trop loin.\n";
            leap = false;
            return false;
        }

        // Vérifier si la pièce ne se déplace pas d'exactement 2 colonnes
        if (board[row1][column1] != 'N' && board[row1][column1] != 'B') {
            if (column2 != column1 + 2 && column2 != column1 - 2) {
                cout << "Le pion ne peut pas se deplacer de deux colones.\n";
                leap = false;
                return false;
            }
        }

        // Vérifier si la pièce saute par-dessus une autre pièce de l'autre joueur
        char otherPlayer;
        if (toupper(board[row1][column1]) == 'B') {
            otherPlayer = 'N';
        } else {
            otherPlayer = 'B';
        }

        if (row2 > row1 && column2 > column1)
        {
            if (toupper(board[row2 - 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 > row1 && column2 < column1)
        {
            if (toupper(board[row2 - 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 > column1)
        {
            if (toupper(board[row2 + 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 < column1)
        {
            if (toupper(board[row2 + 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        leap = true;
        return true;
    }
    leap = false;
    return true;
}

// Executer un mouvement
void move()
{
    bool king_piece = false;

    if (board[row1][column1] == 'N' || board[row1][column1] == 'B')
    {
        king_piece = true;
    }

    board[row1][column1] = ' ';

    if (turn == 'N')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'n';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'N';
        }

        turn = 'B';
    }
    else if (turn == 'B')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'b';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'B';
        }

        turn = 'N';
    }

    if (leap == true)
     {
        // Déterminer la couleur de la pièce mangée
        int mid_row = (row1 + row2) / 2;
        int mid_col = (column1 + column2) / 2;
        char jumped_piece = board[mid_row][mid_col];
        // Enlever la pièce mangée et mettre à jour le compteur correspondant
        if (jumped_piece == 'n'){
            black_piece--;
        }
        else if (jumped_piece == 'b'){
            white_piece--;
        }
        board[mid_row][mid_col] = ' ';

        do_leap();
    }
}

// Effectue un saut par-dessus un pion
void do_leap()
{
    char answer;

    // Supprime le pion du damier après le saut
    if (row2 > row1 && column2 > column1)
    {
        board[row2 - 1][column2 - 1] = ' ';
    }
    else if (row2 > row1 && column2 < column1)
    {
        board[row2 - 1][column2 + 1] = ' ';
    }
    else if (row2 < row1 && column2 > column1)
    {
        board[row2 + 1][column2 - 1] = ' ';
    }
    else if (row2 < row1 && column2 < column1)
    {
        board[row2 + 1][column2 + 1] = ' ';
    }

    display_board(); // Affiche le tableau après les modifications

    // Demande si l'utilisateur veut sauter à nouveau
    do
    {
        cout << "Vous venez de sauter une fois. Voulez-vous essayer une seconde (o/n):";
        cin >> answer;
    }
    while (answer != 'O' && answer != 'o' && answer != 'N' && answer != 'n');

    if (answer == 'o' || answer == 'O')
    {
        row1 = row2;
        column1 = column2;
        cout << "Saut de pion: ligne: " << row1 << ", colonne: " << column1 << endl;
        cout << "Vers la case\n";
        cout << "Ligne: ";
        cin >> row2;
        cout << "Colonne: ";
        cin >> column2;

        while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
        {
            cout << "Entrée incorrecte. Entrez des nombres entre 0 et 7.\n";
            cout << "Vers la case\n";
            cout << "Ligne: ";
            cin >> row2;
            cout << "Colonne: ";
            cin >> column2;
        }

        if (turn == 'N')
        {
            turn = 'B';
        }
        else if (turn == 'B')
        {
            turn = 'N';
        }

        check_move();

        if (leap == false)
        {
            cout << "MOUVEMENT INTERDIT!\n";

            if (turn == 'N')
            {
                turn = 'B';
            }
            else if (turn == 'B')
            {
                turn = 'N';
            }
        }
        else if (leap == true)
        {
            move();
        }
    }
}


// Convertire les pièces de dames basiques qui ont atteint l'autre côté du plateau en pièces de roi
void king()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == 'b')
        {
            board[0][i] = 'B';
        }

        if (board[7][i] == 'n')
        {
            board[7][i] = 'N';
        }
    }
}

// Determiner si la partie est finie
void game_over()
{
    // La partie si termine si un des deux joueurs n'a plus de pions
    if (black_piece == 0 || white_piece == 0){
        game_running = false;
    }
}