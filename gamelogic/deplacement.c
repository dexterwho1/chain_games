#include "../main.h"
#include <stdio.h>
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
        if(memoire[indice][2]<=board->GRID[x-1][y]){
            printf("plus petit");
            indice++;

            memoire[indice][0]=x-1;
            memoire[indice][1]=y;
            memoire[indice][2]=board->GRID[x-1][y];
            board->GRID[x][y]=-2;
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
        if (memoire[indice][2] <= board->GRID[x+1][y]) {
            printf("plus petit");
            indice++;
            memoire[indice][0]=x+1;
            memoire[indice][1]=y;
            memoire[indice][2]=board->GRID[x+1][y];
            board->GRID[x][y]=-2;

        } else {
            printf("%d plus ppetit que l'erreur %d",memoire[indice][2] , board->GRID[x+1][y]);
        }

    }



    if(direction=='q'){
        //gauche
        printf("actuellement %d  et %d ",memoire[indice][2],board->GRID[x][y-1]);
        if(memoire[indice][2]<=board->GRID[x][y-1]){
            printf("plus petit");
            indice++;

            memoire[indice][0]=x;
            memoire[indice][1]=y-1;
            memoire[indice][2]=board->GRID[x][y-1];
            board->GRID[x][y]=-2;

        }
        else{
            printf("plus grand");
        }


    }

    if (direction == 'd') {
        //droite
        printf("actuellement %d  et %d ", memoire[indice][2], board->GRID[x][y+1]);
        if (memoire[indice][2] <= board->GRID[x][y+1]) {
            printf("plus petit");
            indice++;
            memoire[indice][0] = x;
            memoire[indice][1] = y+1;
            memoire[indice][2] = board->GRID[x][y+1];
            board->GRID[x][y]=-2;

        } else {

            printf("plus grand");
        }


    }


    printf("la valeur n %d\n la valeur x %d\n la valeur y %d\n le chiffre  est %d\n ",indice,memoire[indice][0],indice,memoire[indice][1],indice,memoire[indice][2]);
}



//
// Created by Ecole on 03/04/2023.
//