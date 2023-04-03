#include "../main.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

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
