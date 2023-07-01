#include <stdio.h>
#include <stdlib.h>

void imput(void)
{
    char buf[2];
    FILE *fp;
    if(!(fp = fopen("buffer", "w"))){
        return 0;
    }
    fgets(buf, sizeof(buf), stdin);
    fprintf(fp, "%s", buf);
    fclose(fp);

    return 0;
}