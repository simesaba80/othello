#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othellolib.h"

int imput(void)
{
    char buf[3];
    long coordinate;
    int i, coord;
    char *p;

    fgets(buf, 3, stdin);
    coordinate = strtol(buf, NULL, 10);
    coord = (int)coordinate;
    p = strchr(buf, '\n');
    if(p != NULL){
        *p = '\0';
    } else {
        for(i = 0;;i++){
            if(getchar() == '\n'){
                break;
            }
            if(feof(stdin)){
                break;
            }
        }
    }

    return coord;
}