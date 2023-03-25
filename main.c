#include <stdio.h>

#define ROWS 9
#define COLS 9

// Définition de la classe Board
typedef struct {
    int grid[ROWS][COLS];
} Board;

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
}

// Déplacement du joueur sur le plateau
void move(Board *board, char direction) {
    switch(direction) {
        case 'z':
            printf("haut\n");
            break;
        case 'q':
            printf("gauche\n");
            break;
        case 's':
            printf("bas\n");
            break;
        case 'd':
            printf("droite\n");
            break;
        default:
            printf("erreur\n");
    }
}

int main() {
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

    for (int i = 0; i < 5; i++) {
        scanf(" %c", &direction);
        move(&board, direction);
    }

    return 0;
}
