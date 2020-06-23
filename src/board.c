#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void PrintChess(char** chess)
{
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("{ %c }", chess[i][j]);
        }
        printf("\n");
    }
    printf("    a    b    c    d    e    f    g    h");
}

char** FillChess(char** chess)
{
    chess = (char**)malloc(8 * sizeof(char*));
    for (int i = 0; i < 8; i++) {
        chess[i] = (char*)malloc(8 * sizeof(char));
        for (int j = 0; j < 8; j++) {
            chess[i][j] = ' ';
        }
    }
    for (int i = 0; i < 8; i++) {
        chess[1][i] = 'p';
        chess[6][i] = 'P';
    }
    chess[0][0] = 'r';
    chess[0][1] = 'n';
    chess[0][2] = 'b';
    chess[0][3] = 'q';
    chess[0][4] = 'k';
    chess[0][5] = 'b';
    chess[0][6] = 'n';
    chess[0][7] = 'r';
    chess[7][0] = 'R';
    chess[7][1] = 'N';
    chess[7][2] = 'B';
    chess[7][3] = 'Q';
    chess[7][4] = 'K';
    chess[7][5] = 'B';
    chess[7][6] = 'N';
    chess[7][7] = 'R';
    return chess;
}

char** FreeChess(char** chess)
{
    for (int i = 0; i < 8; i++) {
        free(chess[i]);
    }
    free(chess);
    return chess;
}
