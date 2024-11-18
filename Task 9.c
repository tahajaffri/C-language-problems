#include <stdio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    int i,j;
    for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY, char move) {
    int newX = *playerX;
    int newY = *playerY;

    if (move == 'W') newX--;
    else if (move == 'S') newX++;
    else if (move == 'A') newY--;
    else if (move == 'D') newY++;

    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        printf("Invalid move! Out of bounds.\n");
    } else if (grid[newX][newY] == 'X') {
        printf("You hit an obstacle!\n");
    } else {
        if (grid[newX][newY] == 'I') {
            printf("You collected an item!\n");
        }
        grid[*playerX][*playerY] = ' ';
        *playerX = newX;
        *playerY = newY;
        grid[newX][newY] = 'P';
    }
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerX = 4;
    int playerY = 4;
    char move;

    while (1) {
        displayGrid(grid);
        printf("Move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        if (move == 'Q') {
            printf("Exiting the game!\nThank you for playing!");
            break;
        }

        movePlayer(grid, &playerX, &playerY, move);
    }

    return 0;
}

