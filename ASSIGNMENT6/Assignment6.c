#include <stdio.h>

char board[3][3]; 
char currentPlayer; 

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
void makeMove(int row, int col) {
    board[row][col] = currentPlayer;
}

void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';  
    } else {
        currentPlayer = 'X';  
    }
}

void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' '); // Ensure the spot is empty

    printf("Computer chose: Row %d, Column %d\n", row + 1, col + 1);
    makeMove(row, col);
}

int main() {
    int row, col;
    int gameOver = 0;

    initializeBoard();
    currentPlayer = 'X'; 

    printf("Welcome to Tic Tac Toe!\n");
    printBoard();

    while (!gameOver) {
        if (currentPlayer == 'X') {
            
            printf("Player's Turn (X)\n");
            printf("Enter row and column (1-3) for your move: ");
            scanf("%d %d", &row, &col);
            row--; col--; 

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Invalid move, try again!\n");
                continue;
            }

            makeMove(row, col);
        } else {\
            computerMove();
        }

        printBoard();

        if (checkWinner()) {
            printf("%c wins the game!\n", currentPlayer);
            gameOver = 1;
        } else if (isBoardFull()) {
            printf("It's a draw! The board is full.\n");
            gameOver = 1;
        }

        switchPlayer();
    }

    return 0;
}
