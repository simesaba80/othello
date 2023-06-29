#include <stdio.h>
#include "othellolib.h"

int main(void){
    int i, j, x, y;
    int t = 1;
    int board[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0 ,0 ,0, 0},
        {0, 0, 0,-1, 1 ,0 ,0, 0},
        {0, 0, 0, 1,-1 ,0 ,0, 0},
        {0, 0, 0, 0, 0 ,0 ,0, 0},
        {0, 0, 0, 0, 0 ,0 ,0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    while(1){
        printf(" |1|2|3|4|5|6|7|8|\n");
        for(i = 0; i < 8; i++){
            printf("%d|", i+1);
            for(j = 0; j < 8; j++){
                if(board[i][j] == 1){
                    printf("○|");
                }
                else if(board[i][j] == -1){
                    printf("●|");
                } else {
                    printf(" |");
                }
            }
            printf("\n");
        }
        printf("%dターン目\n", t);
        printf("縦の座標を入力してね");
        scanf("%d", &y);
        y--; //配列用に変換
        printf("横の座標を入力してね");
        scanf("%d", &x);
        x--; //配列用に変換
        //先行は○（内部的には１）
        if(board[y][x] == 0 && x < 8 && y < 8) {
            if(t % 2 == 1){
                board[y][x] = 1;
            } else {
                board[y][x] = -1;
            }
            left(board, y, x, t);
            leftup(board, y, x, t);
            up(board, y, x, t);
            rightup(board, y, x, t);
            right(board, y, x, t);
            t++; //正しく打てたらターンを増やす
      } else {
            printf("その位置は埋まっているかもしくは範囲外です\n");
        }

    }

    /*配列の先頭、打つ場所の番号（配列変換済み）、ターン数を渡す
    それぞれの方向に端っこまで検証する、ターン数で白か黒か決める */

}