#include "../main.h"
#include <stdio.h>

void deplacementHaut(Board *board, int x, int y) {
    if (memoire[indice][2] < board->GRID[x - 1][y]) {
        indice++;
        memoire[indice][0] = x - 1;
        memoire[indice][1] = y;
        memoire[indice][2] = board->GRID[x - 1][y];
        board->GRID[x][y] = 0;
    }
}

void deplacementRevenir(Board *board) {
    int x = memoire[indice][0];
    int y = memoire[indice][1];

    if (indice > 0) {
        board->GRID[x][y] = memoire[indice][2];
        indice--;
    } else {
        printf("Impossible de revenir en arrière.\n");
    }
}

void deplacementBas(Board *board, int x, int y) {
    if (memoire[indice][2] < board->GRID[x + 1][y]) {
        indice++;
        memoire[indice][0] = x + 1;
        memoire[indice][1] = y;
        memoire[indice][2] = board->GRID[x + 1][y];
        board->GRID[x][y] = 0;
    }
}

void deplacementGauche(Board *board, int x, int y) {
    if (memoire[indice][2] < board->GRID[x][y - 1]) {
        indice++;
        memoire[indice][0] = x;
        memoire[indice][1] = y - 1;
        memoire[indice][2] = board->GRID[x][y - 1];
        board->GRID[x][y] = 0;
    }
}

void deplacementDroite(Board *board, int x, int y) {
    if (memoire[indice][2] < board->GRID[x][y + 1]) {
        indice++;
        memoire[indice][0] = x;
        memoire[indice][1] = y + 1;
        memoire[indice][2] = board->GRID[x][y + 1];
        board->GRID[x][y] = 0;
    }
}

void demandeDeplacement(Board *board) {
    char direction = 'z';
    int n = board->N;
    n = n - 1;
    int x = memoire[indice][0];
    int y = memoire[indice][1];

    scanf("%s", &direction);

    board->N++;

    if (direction == 'z') {
        deplacementHaut(board, x, y);
    } else if (direction == 'r') {
        deplacementRevenir(board);
    } else if (direction == 's') {
        deplacementBas(board, x, y);
    } else if (direction == 'q') {
        deplacementGauche(board, x, y);
    } else if (direction== 'd'){
        deplacementDroite(board,x,y);
    }}