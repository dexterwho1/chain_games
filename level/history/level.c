#include "../../main.h"


void init_level1(Board*board){
    int level[X][Y] = {

            {9},
            {9 },
            {9},
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

void init_level2(Board* board) {
    int level[X][Y] = {
            {-4},
            {2},
            {3},
    };

    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = level[i][j];
            // Trouver les coordonnées du point ayant la valeur -9
            if (level[i][j] == -4) {
                memoire[indice][0] = i;
                memoire[indice][1] = j;
                memoire[indice][2] = 1;
                board->GRID[i][j] =-4;

            }
        }
    }

    board->GRID[0][2] = 0;
    board->CASETROUVER[board->N][0] = 0;
    board->CASETROUVER[board->N][1] = 2;
    board->CASETROUVER[board->N][2] = 0;
}

void init_level3(Board*board){
    int choisit=2;
    int level[X][Y] = {

            {8, -4, 8},
            {8, 8, 8},
            {8, 8, 8},
            {8, 8, -8},
    };

    if(choisit==1) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                board->GRID[i][j] = level[i][j];
                // Trouver les coordonnées du point ayant la valeur -9
                if (level[i][j] == -4) {
                    memoire[indice][0] = i;
                    memoire[indice][1] = j;
                    memoire[indice][2] = 1;
                    board->GRID[i][j] = -4;

                }
            }
        }
    }

    else if(choisit==2) {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                board->GRID[i][j] = level[i][j];
                // Trouver les coordonnées du point ayant la valeur -9
                if (level[i][j] == -8) {
                    memoire[indice][0] = i;
                    memoire[indice][1] = j;
                    memoire[indice][2] = 1;
                    board->GRID[i][j] = -8;

                }
            }
        }
    }


}

void init_level4(Board*board){
    int level[X][Y] = {

            {7,3,3,3,3},
            {0,0,0,0,2},
            {0,0,0,0,1},
    };
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = level[i][j];
        }
    }
    memoire[indice][0] = 2;
    memoire[indice][1] = 4;
    memoire[indice][2] = 1;

}

void init_level5(Board*board){
    int level[X][Y] = {

            {1, 2, 3},
            {9, 8, 4},
            {9, 8, 5},
    };
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = level[i][j];
        }
    }
    memoire[indice][0] = 0;
    memoire[indice][1] = 0;
    memoire[indice][2] = 1;

}