#include <stdio.h>
#include "othellolib.h"

int main(void){
    int i, j, x, y, reverse;
    int passturn = 0;   //パスカウント
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
        if(t == 82){    //82ターン目になったら自動でぬけだす
            break;
        }
        printboard(board);
        //両者連続してパスすると終了する
        if(passturn == 2){
            break;
        }
/*配列の先頭、打つ場所の番号（配列変換済み）、ターン数を渡す
それぞれの方向に端っこまで検証する、ターン数で白か黒か決める */
        x = 0;
        y = 0;
        printf("%dターン目  ", t);
        if(t % 2 == 1){
            printf("○のターンです\n");
        } else {
            printf("●のターンです\n");
        }
        printf("縦の座標を入力してね(psを入力でパス)");
        y = imput();
        while(y == 0){
            printf("フォーマットが違います。もう一度入力してね");
            y = imput();
        }
        y--;//配列用の変換
        //yにpsを入力したら通常入力できない200が来る
        if(y == 200){
            t++;
            passturn++;
            continue;
        }
        printf("横の座標を入力してね(psを入力でパス)");
        x = imput();
        while(x == 0){
            printf("フォーマットが違います。もう一度入力してね");
            x = imput();
        }
        x--;//配列用の変換
        //xにpsを入力した場合200がくる
        if(x == 200){
            t++;
            passturn++;
            continue;
        }
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
        //石をカウントする
        if(t % 2 == 1){
            blackstone++;   //自分がおいた分のカウント
            blackstone += reverse;
            whitestone -= reverse;
        }
        if(t % 2 == 0){
            whitestone++;   //自分がおいた分のカウント
            blackstone -= reverse;
            whitestone += reverse;
        }
        t++; //正しく打てたらターンを増やす
        passturn = 0;   //パスカウントのリセット
    }
    printf("○は%2d個、●は%2d個\n", blackstone, whitestone);
    if(blackstone > whitestone){
        printf("○の勝ち！\n");
    } else if (whitestone > blackstone){
        printf("●の勝ち！\n");
    } else {
        printf("引き分け！\n");
    }

    return 0;
}