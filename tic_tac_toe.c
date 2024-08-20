//tic tac toe in C by Edgar Gerardo Martin
//07/27/2024
//semester project of C programmin, tic tac toe

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }; // we create the array 
int row, column; // we assign row and column to the array
char turn = 'x'; //we initialize the turn with x, but later we change it to '0' for player 2
int choice;
bool tie = false;

char player1[10];
char player2[10];

void tictactoe(char board[3][3]); // Here we display the game bard
void playerTurn(); // here we create the player's turns
bool gameover();// here we specify wether the player wins, looses or if is a tie


int main() {
    printf( "Player 1, please enter your name: ");
    scanf_s("%s", player1, 10);
    printf( "Player 2, please enter your name: ");
    scanf_s("%s", player2, 10);

    //this while loop will run until the game is over
    //the game is over when the function gameover() returns false
    while (true) {
        tictactoe(board);
        playerTurn();
        if (!gameover()) {
            break;
        }
    }

    if (turn == '0' && tie == false) {
        printf("Congratulations!Player %s has won the game\n", player1); 
    }
    else if (turn == 'x' && tie == false) {
        printf("Congratulations!Player %s has won the game\n", player2); 
    }
    else {
        printf("GAME DRAW!!!\n");
    }

    return 0;
}

void tictactoe(char board[3][3]) {

    //displaying the game board to the user
    printf("Player 1: %10s (X)  -  Player 2: %10s (O)\n", player1,  player2);

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);\

    printf("     |     |     \n");
}

void playerTurn() {
    bool validInput = false;

    while (!validInput) {
        if (turn == 'x') {
            printf("It's %s's turn (X): ", player1);
            scanf_s("%d", &choice);
        }
        else if (turn == '0') {
            printf("It's %s's turn (O): ", player2);
            scanf_s("%d", &choice);
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid Move! Please enter a number between 1 and 9.\n");
            continue;
        }

        switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: continue;
        }

        if (board[row][column] != 'x' && board[row][column] != '0') {
            board[row][column] = turn;
            if (turn == 'x') {
                turn = '0';
            }
            else {
                turn = 'x';
            }
            validInput = true;
        }
        else {
            printf("Invalid Move! The cell is already taken. Please choose another one.\n");
        }
    }
}

bool gameover() {
    //checking the win for Simple Rows and Simple Column
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    //checking the win for both diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'x' && board[i][j] != '0')
                return true;

    //Checking the if game already draw
    tie = true;
    return false;
}