#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othellolib.h"

int imput(void)
{
    char buf[2];
    long coordinate;
    int coord;
    fgets(buf, 2, stdin);
    coordinate = strtol(buf, NULL, 10);
    coord = (int)coordinate;

    return coord;
}