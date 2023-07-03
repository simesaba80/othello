#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othellolib.h"

int imput(void)
{
    char buf[2];
    long coordinate;
    int coord;
    char *p;

    fgets(buf, 2, stdin);
    coordinate = strtol(buf, NULL, 10);
    coord = (int)coordinate;
    p = strchr(buf, '\n');
    if(p != NULL){
        *p = '\0';
    } else {
        for(;;){
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