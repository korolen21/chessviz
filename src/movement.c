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

int Check(char** chess, char oper, char color, int x1, int y1, int x2, int y2)
{
    if ((oper != '-') && (oper != 'x')) {
        return -1;
    }
    if (((x1 < 0) || (x1 > 7)) || ((y1 < 0) || (y1 > 7))
        || ((x2 < 0) || (x2 > 7)) || ((y2 < 0) || (y2 > 7))) {
        return -1;
    }
    if ((oper == '-') && (chess[x2][y2] != ' ')) {
        return -1;
    }
    if (color == 'w') {
        if (chess[x1][y1] > 'Z') {
            return -1;
        }
        if ((oper == 'x') && ((chess[x2][y2] < 'a') || chess[x2][y2] == ' ')) {
            return -1;
        }
    } else {
        if (chess[x1][y1] < 'a') {
            return -1;
        }
        if ((oper == 'x') && ((chess[x2][y2] > 'Z') || chess[x2][y2] == ' ')) {
            return -1;
        }
    }
    if ((chess[x1][y1] == 'P') || (chess[x1][y1] == 'p')) {
        if (StepPawn(chess, oper, color, x1, y1, x2, y2) == -1) {
            return -1;
        }
    } else {
        return -1;
    }
    return 0;
}
int Translate(char temp)
{
    for (int i = 0; i < 8; i++) {
        if (temp == 'a' + i) {
            return i;
        }
    }
    return -1;
}
