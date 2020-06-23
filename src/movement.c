#include "movement.h"

#include <stdio.h>

char** EnterCoordinate(char** chess, char color)
{
    int x1, x2, y1, y2, error;
    char temp_1, temp_2, oper;
    while (1) {
        scanf("%c %d %c %c %d", &temp_1, &x1, &oper, &temp_2, &x2);
        x1--;
        x2--;
        y1 = Translate(temp_1);
        y2 = Translate(temp_2);
        error = Check(chess, oper, color, x1, y1, x2, y2);
        if (error == 0) {
            break;
        }
    }
    chess[x2][y2] = chess[x1][y1];
    chess[x1][y1] = ' ';
    return chess;
}


