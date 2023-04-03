#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "main.h"

int memoire[89][3];
int indice=0;






void mettreToutAZero(Board *board) {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            board->GRID[i][j] = 0;
        }
    }
}

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

void printboardwithpos(Board *board, int x, int y) {
    printf("    ");
    for(int i = 0; i < X; i++) {
        printf("%d  ", i + 1);
    }
    printf("\n  +");

    for(int i = 0; i < X; i++) { // Change the loop limit to X instead of 7
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < X; i++) {
        printf("%d |", i + 1);
        for(int j = 0; j < Y; j++) {
            if (i == x && j == y) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf(" %d ", board->GRID[i][j]);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            }
            else if (board->GRID[i][j] == 0) {
                printf(" . ");
            }
            else {
                printf(" %d ", board->GRID[i][j]);
            }
        }
        printf("\n");
    }
}


void printboard(Board *board) {
    printf("    ");
    for(int i = 0; i < X; i++) {
        printf("%d  ", i + 1);
    }
    printf("\n  +");

    for(int i = 0; i < 7; i++) {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < X; i++) {
        printf("%d |", i + 1);
        for(int j = 0; j < Y; j++) {
            if (board->GRID[i][j] == 0) {
                printf(" . ");
            }
            else {
                printf(" %d ", board->GRID[i][j]);
            }
        }
        printf("\n");
    }
}

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

            {5},
            {6, },
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

void demandeDeplacement(Board *board) {
    char direction='z';
    int n=board->N;
    n=n-1;
    int x=memoire[indice][0];
    int y=memoire[indice][1];
    int value=board->CASETROUVER[n][2];
    scanf("%s",&direction);

    board->N++;

    if(direction=='z'){
        //haut
        printf("actuellement %d  et %d ",memoire[indice][2],board->GRID[x-1][y]);
        if(memoire[indice][2]<board->GRID[x-1][y]){
            printf("plus petit");
            indice++;

            memoire[indice][0]=x-1;
            memoire[indice][1]=y;
            memoire[indice][2]=board->GRID[x-1][y];
            board->GRID[x][y]=0;
        }
        else{
            printf("plus grand");
        }


    }

    if(direction=='r'){
        if (indice > 0) {
            board->GRID[x][y] = memoire[indice][2];
            indice--;
            x = memoire[indice][0];
            y = memoire[indice][1];
        } else {
            printf("Impossible de revenir en arrière.\n");
        }
    }

    if(direction=='s'){
        if (memoire[indice][2] < board->GRID[x+1][y]) {
            printf("plus petit");
            indice++;
            memoire[indice][0]=x+1;
            memoire[indice][1]=y;
            memoire[indice][2]=board->GRID[x+1][y];
            board->GRID[x][y]=0;

        } else {
            printf("%d plus ppetit que l'erreur %d",memoire[indice][2] , board->GRID[x+1][y]);
        }

    }
    if(direction == 'm'){
        mettreToutAZero(board);
    }


    if(direction=='q'){
        //gauche
        printf("actuellement %d  et %d ",memoire[indice][2],board->GRID[x][y-1]);
        if(memoire[indice][2]<board->GRID[x][y-1]){
            printf("plus petit");
            indice++;

            memoire[indice][0]=x;
            memoire[indice][1]=y-1;
            memoire[indice][2]=board->GRID[x][y-1];
            board->GRID[x][y]=0;

        }
        else{
            printf("plus grand");
        }


    }

    if (direction == 'd') {
        //droite
        printf("actuellement %d  et %d ", memoire[indice][2], board->GRID[x][y+1]);
        if (memoire[indice][2] < board->GRID[x][y+1]) {
            printf("plus petit");
            indice++;
            memoire[indice][0] = x;
            memoire[indice][1] = y+1;
            memoire[indice][2] = board->GRID[x][y+1];
            board->GRID[x][y]=0;

        } else {

            printf("plus grand");
        }


    }


    printf("la valeur n %d\n la valeur x %d\n la valeur y %d\n le chiffre  est %d\n ",indice,memoire[indice][0],indice,memoire[indice][1],indice,memoire[indice][2]);
}

//droite





int move(Board *board) {

    //bas(board,n);
    //haut(board,n);
    //gauche(board,n);
    //droite(board,n);
    demandeDeplacement(board);
}


int main() {
    int n=0;
    char direction;
    bool continuepartie = false;
    printf("Bienvenue au jeu Cardinal!\n");

    Board board;
    init_board(&board);

    printf("\nManche 1\n");
    printboard(&board);
    init_level1(&board);
    printboard(&board);

    // Boucle pour les déplacements
    while (continuepartie==false) {
        printboardwithpos(&board, memoire[indice][0], memoire[indice][1]); // Affichage de la grille avec la case actuelle en couleur
        demandeDeplacement(&board); // Demande de déplacement au joueur
        continuepartie=estPartieTerminee(&board);
    }

    // Affichage des cases visitées
    printf("indice = %d\n",indice);
    for(int i=0;i<indice;i++){
        printf("La case visitée était à la ligne %d et colonne %d, la valeur était %d\n", memoire[i][0]+1, memoire[i][1]+1, memoire[i][2]);
    }
    continuepartie=false;
    init_level2(&board);
    while (continuepartie==false) {
        printboardwithpos(&board, memoire[indice][0], memoire[indice][1]); // Affichage de la grille avec la case actuelle en couleur
        demandeDeplacement(&board); // Demande de déplacement au joueur
        continuepartie=estPartieTerminee(&board);
    }



    return 0;
}