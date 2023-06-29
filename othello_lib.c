#include "othellolib.h"
#include <stdio.h>

//おいた場所から左方向への判定
void left(int board[8][8], int y, int x, int t)
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

//おいた場所から左上への判定
void leftup(int board[8][8], int y, int x, int t)
{
    int endx, endy;
    endx = x-1;
    endy = y-1;
    if(t % 2 == 1){
        while(board[endy][endx] == -1){
            endx--;
            endy--;
        }
        if(board[endy][endx] == 1){
            while(x > endx+1 && y > endy+1){
                x--;
                y--;
                board[y][x] *= -1;
            }
        }
    }
    if(t % 2 == 0){
        while(board[endy][endx] == 1){
            endx--;
            endy--;
        }
        if(board[endy][endx] == -1){
            while(x > endx+1 && y > endy+1){
                x--;
                y--;
                board[y][x] *= -1;
            }
        }
    }
}

void up(int board[8][8], int y, int x, int t)
{
int i, endy;
    endy = y-1;
    if(t % 2 == 1){
        while(board[endy][x] == -1){
            endy--;
        }
        if(board[endy][x] == 1){
            for(i = y-1; i > endy; i--){
                board[i][x] *= -1;
            }
        }
    } else if(t % 2 == 0) {
        while(board[endy][x] == 1){
            endy--;
        }
        if(board[endy][x] == -1){
            for(i = y-1; i > endy; i--){
                board[i][x] *= -1;
            }
        }
    }
}

void rightup(int board[8][8], int y, int x, int t)
{
    int endx = x + 1;
    int endy = y - 1;
    if(t % 2 == 1){
        while(board[endy][endx] == -1){
            endx++;
            endy--;
        }
        if(board[endy][endx] == 1){
            while(x < endx-1 && y > endy+1){
                x++;
                y--;
                board[y][x] *= -1;
            }
        }
    }
    if(t % 2 == 0){
        while(board[endy][endx] == 1){
            endx++;
            endy--;
        }
        if(board[endy][endx] == -1){
            while(x < endx-1 && y > endy+1){
                x++;
                y--;
                board[y][x] *= -1;
            }
        }
    }
}

void right(int board[8][8], int y, int x, int t)
{
    int i;
    int endx = x + 1;
    if(t % 2 == 1){
        while(board[y][endx] == -1){
            endx++;
        }
        if(board[y][endx] == 1){
            for(i = x + 1; i < endx; i++){
                board[y][i] *= -1;
            }
        }
    }
    if(t % 2 == 0){
        while(board[y][endx] == 1){
            endx++;
        }
        if(board[y][endx] == -1){
            for(i = x + 1; i < endx; i++){
                board[y][i] *= -1;
            }
        }
    }
}