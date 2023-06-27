#include "othello.h"
#include <stdio.h>

void left(int board[8][8], int x, int y, int t)
{
    int i, tmpx;
    tmpx = x;
    tmpx--;
    if(t % 2 == 1){
        while(board[y][tmpx] == -1){
            tmpx--;
        }
        if(board[y][tmpx] == 1){
            for(i = x-1; i > tmpx; i--){
                board[y][i] *= -1;
            }
        }
    } else if(t % 2 == 0) {
        while(board[y][tmpx] == 1){
            tmpx--;
        }
        if(board[y][tmpx] == -1){
            for(i = x-1; i > tmpx; i--){
                board[y][i] *= -1;
            }
        }
    }
}