/*
In this implementation, board is a 3x3 array of characters that represents the game board. 
The initialize_board() function initializes the board to all empty spaces. The 
print_board() function prints the current state of the board to the console. The 
check_win() function checks if there is a winner, and returns the winning player's symbol 
(either 'X' or 'O') or a space if there is no winner yet.
In the main() function, the game loop starts by initializing the board and prompting the 
first player to make a move. The loop continues until there is a winner. Each iteration of the 
loop takes input from the player, updates
*/

#include <stdio.h>

char board[3][3]; // 3x3 board

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2) {
            printf("-----------\n");
        }
    }
}

char check_win() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

int main() {
    int player = 1; // player 1 starts
    int row, col;
    char winner;

    initialize_board();

    do {
        printf("Player %d, enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter column (1-3): ", player);
        scanf("%d", &col);
        row--;
        col--;

        if (board[row][col] != ' ') {
            printf("That cell is already occupied. Try again.\n");
            continue;
        }

        if (player == 1) {
            board[row][col] = 'X';
            player = 2;
        } else {
            board[row][col] = 'O';
            player = 1;
        }

        print_board();
        winner = check_win();
    } while (winner == ' ');

    if (winner == 'X') {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}