//
// Created by Ecole on 03/04/2023.
//
#include "../main.h"
void playLevel(Board *board) {
    bool continuepartie = false;
    while (continuepartie == false) {
        printboardwithpos(board, memoire[indice][0], memoire[indice][1]);
        demandeDeplacement(board);
        continuepartie = estPartieTerminee(board);
    }
}

void afficherCasesVisitees() {
    printf("indice = %d\n", indice);
    for (int i = 0; i < indice; i++) {
        printf("La case visitée était à la ligne %d et colonne %d, la valeur était %d\n", memoire[i][0] + 1, memoire[i][1] + 1, memoire[i][2]);
    }
}