#include <stdio.h>

#define ROWS 9
#define COLS 9

// Définition de la classe Board
typedef struct {
    int grid[ROWS][COLS];
    int casetrouver[95][2];

} Board;





void setzero(Board *board, int x, int y, int n) {
    board->casetrouver[n][0] = x;
    board->casetrouver[n][1] = y;
    board->casetrouver[n][3] = board->grid[x][y];

    board->grid[x][y] = 0;

    if(board->casetrouver[n][3] >board->grid[x][y]){
    printf("%d plus grand que %d",board->casetrouver[n][3],board->casetrouver[n-1][3]);
        }
    else if(board->casetrouver[n][3] < board->grid[x][y]){
        printf("%d plus petit que %d",board->casetrouver[n][3],board->casetrouver[n-1][3]);


    }

    //printf("votre %d coup est %d ",n,board->casetrouver[n][3]);

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
            {5, 9, 3, 1, 8, 4, 7, 6, 2},
            {4, 2, 9, 1, 5, 7, 8, 3, 6},
            {6, 7, 1, 4, 9, 2, 8, 5, 3},
            {2, 5, 7, 3, 1, 9, 4, 8, 6},
            {3, 1, 6, 5, 2, 8, 9, 7, 4},
            {8, 4, 2, 6, 7, 1, 3, 9, 5},
            {9, 8, 4, 2, 3, 6, 1, 5, 7},
            {7, 6, 5, 8, 4, 3, 2, 1, 9},
            {1, 3, 8, 9, 6, 0, 4, 2, 7}
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

int verifierordrecroissant(Board*board,int n){
    return 0;


}

void haut(Board *board, int n) {
    verifierordrecroissant(board,n);
    board->casetrouver[n][0]=board->casetrouver[n-1][0]-1;
    board->casetrouver[n][1]=board->casetrouver[n-1][1];
}

void gauche(Board *board, int n) {
    verifierordrecroissant(board,n);
    board->casetrouver[n][0] = board->casetrouver[n-1][0];
    board->casetrouver[n][1] = board->casetrouver[n-1][1]-1;
}

void droite(Board *board, int n) {
    verifierordrecroissant(board,n);
    board->casetrouver[n][0] = board->casetrouver[n-1][0];
    board->casetrouver[n][1] = board->casetrouver[n-1][1] + 1;
}

void bas(Board *board, int n) {
    verifierordrecroissant(board,n);
    board->casetrouver[n][0] = board->casetrouver[n-1][0]+1;
    board->casetrouver[n][1] = board->casetrouver[n-1][1];
}

void demandeDeplacement(Board *board, int n) {
    char direction;
    scanf("%c", &direction);
    switch(direction) {
        case 'z':
            haut(board, n);
            break;
        case 'q':
            gauche(board, n);
            break;
        case 's':
            bas(board, n);
            break;
        case 'd':
            droite(board, n);
            break;
        case'e':
            for(int i =0; i<n;i++){
                printf("%d \n",board->casetrouver[i][3]);
            }

        default:
            printf("Mauvaise entree, veuillez entrer z, q, s ou d.\n");
            demandeDeplacement(board, n);
            break;


    }
}



int move(Board *board, int n) {
    n++;

    //bas(board,n);
    //haut(board,n);
    //gauche(board,n);
    //droite(board,n);
    demandeDeplacement(board,n);
    int x=board->casetrouver[n][0];
    int y=board->casetrouver[n][1];

    setzero(board,x,y,n);

    return n;
}



int main() {
    int n=0;
    char direction;
    printf("Bienvenue au jeu Cardinal!\n");

    Board board;
    init_board(&board);

    init_level1(&board);

    printf("\nManche 1\n");
    printboard(board.grid);


    while(1){
        n=move(board.grid,n);
        printboard(board.grid);
        printf("\nManche 1\n");
        printf("tableau a l'indice %d ",board.grid[n][3]);

        printf("Les deplacements :\n pour aller en haut -> z \n pour aller en bas -> s \n pour aller a gauche -> q \n pour aller a droite -> d\n");
        printf("Votre choix ? : ");

    }





    return 0;
}
