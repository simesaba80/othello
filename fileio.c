#include <stdio.h>
#include <stdlib.h>

int imput(void)
{
    char buf[2];
    int coordinate;
    fgets(buf, sizeof(buf), stdin);
    (long)coordinate = strtol(buf, NULL, 10);

    return coordinate;
}