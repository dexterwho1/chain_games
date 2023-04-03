#include "../../main.h"


void init_level1(Board*board){
    int level[X][Y] = {

            {9},
            {7, },
            {1},
    };
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = level[i][j];
        }
    }
    memoire[indice][0] = 2;
    memoire[indice][1] = 0;
    memoire[indice][2] = 0;
    board->GRID[0][2] = 0;
    board->CASETROUVER[board->N][0] = 0;
    board->CASETROUVER[board->N][1] = 2;
    board->CASETROUVER[board->N][2] = 0;


}

void init_level2(Board*board){
    int level[X][Y] = {

            {6},
            {5, },
            {1},
    };
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = level[i][j];
        }
    }
    memoire[indice][0] = 2;
    memoire[indice][1] = 0;
    memoire[indice][2] = 0;
    board->GRID[0][2] = 0;
    board->CASETROUVER[board->N][0] = 0;
    board->CASETROUVER[board->N][1] = 2;
    board->CASETROUVER[board->N][2] = 0;


}