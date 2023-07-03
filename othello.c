#include <stdio.h>
#include "othellolib.h"

int main(void){
    int i, j, x, y, reverse;
    int t = 1;
    int blackstone = 2;
    int whitestone = 2;
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
        x = 0;
        y = 0;
        printf("%dターン目\n", t);
        printf("縦の座標を入力してね");
        y = imput();
        while(y == 0){
            printf("フォーマットが違います。もう一度入力してね");
            y = imput();
        }
        y--;//配列用の変換
        printf("横の座標を入力してね");
        x = imput();
        while(x == 0){
            printf("フォーマットが違います。もう一度入力してね");
            x = imput();
        }
        x--;//配列用の変換
        //先行は○（内部的には１）
        //範囲外や埋まっている場合はcontinue文で先頭に戻る
        if(board[y][x] != 0 || x < 0 || x > 8 || y < 0 || y > 8) {
            printf("その場所は埋まっているか範囲外です\n");
            continue;
        }
        if(t % 2 == 1){
            board[y][x] = 1;
        } else {
            board[y][x] = -1;
        }
        reverse = judgement(board, y, x, t);
        if(reverse == 0){
            printf("その場所にはおけません\n");
            board[y][x] = 0;    //おけなかった場合は取り消してcontinue
            continue;
        }
        if(t % 2 == 1){
            blackstone += reverse;
            whitestone -= reverse;
        }
        if(t % 2 == 0){
            blackstone -= reverse;
            whitestone += reverse;
        }
        t++; //正しく打てたらターンを増やす
    }

    /*配列の先頭、打つ場所の番号（配列変換済み）、ターン数を渡す
    それぞれの方向に端っこまで検証する、ターン数で白か黒か決める */

}