#include "board.h"
#include "movement.h"
#include <stdio.h>

int main()
{
    char color = 'w';
    int exit = 0;
    char** chess = NULL;
    chess = FillChess(chess);
    while (1) {
        PrintChess(chess);
        printf("\nfor exit enter 1\n");
        scanf("%d", &exit);
        if (exit == 1) {
            break;
        }
        if (color == 'w') {
            printf("\nwhite:\n");
            chess = EnterCoordinate(chess, color);
            color = 'b';
        } else {
            printf("\nblack:\n");
            chess = EnterCoordinate(chess, color);
            color = 'w';
        }
    }
    chess = FreeChess(chess);
    return 0;
}
