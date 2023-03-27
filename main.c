#include <stdio.h>

#define ROWS 9
#define COLS 9

// Définition de la classe Board
typedef struct {
    int grid[ROWS][COLS];
    int casetrouver[95][3];

} Board;


void setzero(Board *board, int x, int y,int n) {
    board->casetrouver[n][0] = x;
    board->casetrouver[n][1] = y;
    board->grid[x][y] = 0;


    printf("tableau a l'indice %d est egal a [%d][%d]\n", n, board->casetrouver[n][0], board->casetrouver[n][1]);

}


// Initialisation du plateau avec la valeur 1
void init_board(Board *board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board->grid[i][j] = 1;
        }
    }
}
void printboard(Board *board) {
    printf("    ");
    for(int i = 0; i < ROWS; i++) {
        printf("%d  ", i + 1);
    }
    printf("\n  +");

    for(int i = 0; i < 7; i++) {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        printf("%d |", i + 1);
        for(int j = 0; j < COLS; j++) {
            if (board->grid[i][j] == 0) {
                printf(" . ");
            }
            else {
                printf(" %d ", board->grid[i][j]);
            }
        }
        printf("\n");
    }
}

// Initialisation du niveau 1 du jeu
void init_level1(Board *board) {

    int level[ROWS][COLS] = {
            {1, 1, 3, 1, 1, 1, 1, 1, 1},
            {1, 2, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 3, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 2, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 3, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board->grid[i][j] = level[i][j];
        }
    }

    // La position (8, 5) est libre
    board->grid[8][5] = 0;
    setzero(board, 8,5,0);

}

// Déplacement du joueur sur le plateau
// Déplacement du joueur sur le plateau
// Déplacement du joueur sur le plateau
int move(Board *board, int n) {
    printf(" numero %d",n);
    n++;

    printf("Liste de tous les casetrouver : \n");
    board->casetrouver[n][0]=4;
    board->casetrouver[n][1]=6;
    setzero(board,board->casetrouver[n][0]=4,board->casetrouver[n][1]=6,n);



    for(int i = 0; i < 8; i++) {
        printf("[%d][%d]\n", board->casetrouver[i][0], board->casetrouver[i][1]);
    }


    printf("\n");

    printf("Position actuelle : [%d][%d]\n", board->casetrouver[n][0], board->casetrouver[n][1]);



    return n;
}

int main() {
    int n=0;
    char direction;
    printf("Bienvenue au jeu Cardinal!\n");

    Board board;
    init_board(&board);

    printf("\nManche 0\n");
    printboard(board.grid);

    init_level1(&board);

    printf("\nManche 1\n");
    printboard(board.grid);
    printf("Les deplacements :\n pour aller en haut -> z \n pour aller en bas -> s \n pour aller a gauche -> q \n pour aller a droite -> d\n");
    printf("Votre choix ? : ");

    n=move(board.grid,n);
    printboard(board.grid);

    n=move(board.grid,n);
    printboard(board.grid);




    return 0;
}
