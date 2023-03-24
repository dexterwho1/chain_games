#include <stdio.h>

int liste[9][9];

int move(int liste[9][9], char move)
    {
        switch(move){
            case 'z':
                printf("haut");
                break;
            case 'q':
                printf("gauche");
                break;
            case 's':
                printf("bas");
                break;
            case 'd':
                printf("droite");
                break;
            default:
                printf("erreur");
        }

    }

int level1(int liste[9][9]){
    int level[9][9] = {
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
    for(int i=0; i<9;i++){
        for(int j=0; j<9;j++){
            liste[i][j] = level[i][j];

        }
    }
    liste[8][5]=0;
}
int initboard(int liste[9][9]){
    for(int i=0; i<9;i++){
        for(int y=0; y<9;y++){
            liste[i][y]=1;
        }
    }
}


void printboard(int liste[9][9]){
    printf("    ");

    for(int i=0; i<9;i++){
        printf("%d  ",i+1);
    }
    printf("\n  +");

    for(int i=0; i<7;i++){
        printf("---+");
    }
    printf("\n");

    for(int i=0;i<9;i++){
        printf( "%d |", i+1);
        for(int j=0; j<9;j++){
            if (liste[i][j]==0){
                printf(" . ");
            }
            else{
                printf(" %d ", liste[i][j]);
            }

        }
        printf("\n");

    }
}
int main() {
    int liste[9][9];
    char deplacement='0';
    printf("Welcolme to cardinal game!\n");
    initboard(liste);
    printboard(liste);
    printf("\n manche 0\n");
    level1(liste);
    printboard(liste);
    printf("\n manche 1\n");
    printf("Les deplacements :\n pour aller en haut -> z \n pour aller en bas -> s \n pour aller a gauche -> q \n pour aller a droite -> d");
    printf("\n votre choix ? : ");
    for(int i=0; i<5;i++){
        scanf("%s",&deplacement);
        move(liste,deplacement);
    }

    return 0;
}
