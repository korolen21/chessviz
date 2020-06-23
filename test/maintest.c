#define CTEST_MAIN

#include "../src/board.h"
#include <ctest.h>

char move[10], board[9][9], boardtemp[9][9];
int n = 9;
CTEST(WhitePawn, CorrectMove1)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '2';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '4';
    int result = WhPesh(board, n,move);
    ASSERT_EQUAL(2, result);
}
CTEST(WhitePawn, IncorrectMove1)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '2';
    move[2] = '-';
    move[3] = 'd';
    move[4] = '3';
    int result = WhPesh(board, n,move);
    ASSERT_EQUAL(1, result);
}
CTEST(WhitePawn, IncorrectMove2)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '2';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '5';
    int result = WhPesh(board, n,move);
    ASSERT_EQUAL(1, result);
}
CTEST(BlackPawn, CorrectMove1)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '7';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '6';
    int result = BlPesh(board, n,move);
    ASSERT_EQUAL(2, result);
}
CTEST(BlackPawn, IncorrectMove1)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '7';
    move[2] = '-';
    move[3] = 'd';
    move[4] = '6';
    int result = BlPesh(board, n,move);
    ASSERT_EQUAL(1, result);
}
CTEST(BlackPawn, IncorrectMove2)
{
    startboard(board, n);
    move[0] = 'e';
    move[1] = '7';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '4';
    int result = BlPesh(board, n,move);
    ASSERT_EQUAL(1, result);
}
CTEST(Queue, HaveNoDiff)
{
    startboard(board, n);
    startboard(boardtemp, n);
    int result = Queue(3, board, boardtemp,move, n);
    ASSERT_EQUAL(3, result);
}
CTEST(Queue, HaveDiff)
{
    startboard(board, n);
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 9; j++) {
            boardtemp[i][j] = board[i][j];
        }
    }
    move[0] = 'e';
    move[1] = '7';
    move[2] = '-';
    move[3] = 'e';
    move[4] = '4';
    board[6][2] = ' ';
    board[5][2] = 'P';
    int result = Queue(3, board, boardtemp,move, n);
    ASSERT_EQUAL(4, result);
}
CTEST(startboard, AccuracyofFilling)
{
    int result;
    startboard(board, n);

    if (board[0][0] == '8' && board[0][1] == 'r' && board[0][2] == 'n'
        && board[0][3] == 'b' && board[0][4] == 'q' && board[0][5] == 'k'
        && board[0][6] == 'b' && board[0][7] == 'n' && board[0][8] == 'r'
        && board[1][0] == '7' && board[1][1] == 'p' && board[1][2] == 'p'
        && board[1][3] == 'p' && board[1][4] == 'p' && board[1][5] == 'p'
        && board[1][6] == 'p' && board[1][7] == 'p' && board[1][8] == 'p'
        && board[2][0] == '6' && board[3][0] == '5' && board[4][0] == '4'
        && board[5][0] == '3' && board[6][0] == '2' && board[6][1] == 'P'
        && board[6][2] == 'P' && board[6][3] == 'P' && board[6][4] == 'P'
        && board[6][5] == 'P' && board[6][6] == 'P' && board[6][7] == 'P'
        && board[6][8] == 'P' && board[7][0] == '1' && board[7][1] == 'R'
        && board[7][2] == 'N' && board[7][3] == 'B' && board[7][4] == 'Q'
        && board[7][5] == 'K' && board[7][6] == 'B' && board[7][7] == 'N'
        && board[7][8] == 'R' && board[8][1] == 'a' && board[8][2] == 'b'
        && board[8][3] == 'c' && board[8][4] == 'd' && board[8][5] == 'e'
        && board[8][6] == 'f' && board[8][7] == 'g' && board[8][8] == 'h')
        result = 0;
    ASSERT_EQUAL(0, result);
}
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
