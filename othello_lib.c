#include "othellolib.h"
#include <stdio.h>

//おいた場所から左方向への判定
int left(int board[8][8], int y, int x, int t)
{
    int i, tmpx, count = 0;
    tmpx = x;
    tmpx--;
    if(t % 2 == 1){
        while(board[y][tmpx] == -1){
            tmpx--;
        }
        if(board[y][tmpx] == 1){
            for(i = x-1; i > tmpx; i--){
                board[y][i] *= -1;
                count++;
            }
        }
    } else if(t % 2 == 0) {
        while(board[y][tmpx] == 1){
            tmpx--;
        }
        if(board[y][tmpx] == -1){
            for(i = x-1; i > tmpx; i--){
                board[y][i] *= -1;
                count++;
            }
        }
    }
    return count;
}

//おいた場所から左上への判定
int leftup(int board[8][8], int y, int x, int t)
{
    int endx, endy, count = 0;
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
                count++;
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
                count++;
            }
        }
    }
    return count;
}

int up(int board[8][8], int y, int x, int t)
{
int i, endy, count = 0;
    endy = y-1;
    if(t % 2 == 1){
        while(board[endy][x] == -1){
            endy--;
        }
        if(board[endy][x] == 1){
            for(i = y-1; i > endy; i--){
                board[i][x] *= -1;
                count++;
            }
        }
    } else if(t % 2 == 0) {
        while(board[endy][x] == 1){
            endy--;
        }
        if(board[endy][x] == -1){
            for(i = y-1; i > endy; i--){
                board[i][x] *= -1;
                count++;
            }
        }
    }
    return count;
}

int rightup(int board[8][8], int y, int x, int t)
{
    int endx = x + 1;
    int endy = y - 1;
    int count = 0;
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
                count++;
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
                count++;
            }
        }
    }
    return count;
}

int right(int board[8][8], int y, int x, int t)
{
    int i;
    int endx = x + 1;
    int count = 0;
    if(t % 2 == 1){
        while(board[y][endx] == -1){
            endx++;
        }
        if(board[y][endx] == 1){
            for(i = x + 1; i < endx; i++){
                board[y][i] *= -1;
                count++;
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
                count++;
            }
        }
    }
    return count;
}

int rightdown(int board[8][8], int y, int x, int t)
{
    int endy = y + 1;
    int endx = x + 1;
    int count = 0;
    if(t % 2 == 1){
        while(board[endy][endx] == -1){
            endx++;
            endy++;
        }
        if(board[endy][endx] == 1){
            while(x < endx-1 && y < endy-1){
                x++;
                y++;
                board[y][x] *= -1;
                count++;
            }
        }
    }
    if(t % 2 == 0){
        while(board[endy][endx] == 1){
            endx++;
            endy++;
        }
        if(board[endy][endx] == -1){
            while(x < endx-1 && y < endy-1){
                x++;
                y++;
                board[y][x] *= -1;
                int count++;
            }
        }
    }
    return count;
}

int down(int board[8][8], int y, int x, int t)
{
    int i;
    int endy = y + 1;
    int count = 0;
    if(t % 2 == 1){
        while(board[endy][x] == -1){
            endy++;
        }
        if(board[endy][x] == 1){
            for(i = y+1; i < endy; i++){
                board[i][x] *= -1;
                count++;
            }
        }
    }
    if(t % 2 == 0){
        while(board[endy][x] == 1){
            endy++;
        }
        if(board[endy][x] == -1){
            for(i = y+1; i < endy; i++){
                board[i][x] *= -1;
                count++;
            }
        }
    }
    return count;
}

int leftdown(int board[8][8], int y, int x, int t)
{
    int endx = x - 1;
    int endy = y + 1;
    int count = 0;
    if(t % 2 == 1){
        while(board[endy][endx] == -1){
            endx--;
            endy++;
        }
        if(board[endy][endx] == 1){
            while(x > endx+1 && y < endy-1){
                x--;
                y++;
                board[y][x] *= -1;
                count++;
            }
        }
    }
    if(t % 2 == 0){
        while(board[endy][endx] == 1){
            endx--;
            endy++;
        }
        if(board[endy][endx] == -1){
            while(x > endx+1 && y < endy-1){
                x--;
                y++;
                board[y][x] *= -1;
                count++;
            }
        }
    }
    return count;
}

int judgement(int board[8][8], int y, int x, int t)
{
    int reverse = 0;
    reverse +=left(board, y, x, t);
    reverse += leftup(board, y, x, t);
    reverse += up(board, y, x, t);
    reverse += rightup(board, y, x, t);
    reverse += right(board, y, x, t);
    reverse += rightdown(board, y, x, t);
    reverse += down(board, y, x, t);
    reverse += leftdown(board, y, x, t);

    return reverse;
}