#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othellolib.h"

int imput(void)
{
    char buf[3];    //少数や二桁の数字を渡しても再入力の処理をできるように[3]
    long coordinate;//文字列から変換する際longになるため
    int i, coord, j;   //intとして値を返す用
    char *s, *p;    //sは変換できない文字を受けとるポインタ、pは改行を示すポインタ
    char pass[3] = "ps";

    fgets(buf, sizeof(buf), stdin);
    coordinate = strtol(buf, &s, 10);
    coord = (int)coordinate;
    p = strchr(buf, '\n');
    //psを渡された場合パス用の値を返す
    if(p != NULL){
        *p = '\0';  //普通に入力した場合はこちらの処理
    } else {
        for(i = 0;;i++){
            if(getchar() == '\n'){  //多く入力した場合は空読みをする
                break;
            }
            if(feof(stdin)){
                break;
            }
        }
    }
    if(strcmp(buf, pass) == 0){
        return 201; //通常二桁の返り値なので201は渡せない
    }
    //1,2文字目に変換できない文字がある場合0を返す
    if(*s != '\0'){
        return 400;
    }


    return coord;
}