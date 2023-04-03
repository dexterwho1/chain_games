#include "../main.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

void init_board(Board *board) {
    board->N=0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = 1;
        }
    }
}

bool estPartieTerminee(Board *board) {
    bool continuepartie= true;
    int casesNonNulles = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            if (board->GRID[i][j] > 0) {
                casesNonNulles++;
                if (casesNonNulles > 0) {
                    return continuepartie=false;
                }
            }
        }
    }

    return continuepartie;
}