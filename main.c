#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "main.h"
#include "level/history/level.c"
#include "gamelogic/deplacement.c"
#include "gamelogic/statesofgame.c"
#include "console/display.c"
#include "console/start.c"
int memoire[89][3];
int indice=0;



int main() {
    int n = 0;
    char direction;
    printf("Bienvenue au jeu Cardinal!\n");

    Board board;
    init_board(&board);

    printf("\nManche 1\n");
    printboard(&board);
    init_level1(&board);
    printboard(&board);

    playLevel(&board);


    init_level2(&board);
    playLevel(&board);

    return 0;
}
