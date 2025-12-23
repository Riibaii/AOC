#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 10000

typedef struct point {
    int x;
    int y;
} Point;

int main(int argc, char * argv[]) {
    FILE * fp;
    fp = fopen(argv[1],  "r");

    if (fp != NULL) {
        printf("%s\topened\n", argv[1]);
    }
    else {
        printf("cannot open file!\n");
        return -1;
    }

    char line[MAXLINE];
    fgets(line, MAXLINE, fp);

    Point a[MAXLINE];
    int i, j;
    for (i=0; line[i]!='\n'; i++) { 
        a[i].x=0; a[i].y=0; 
    }

    int p1 = 1;
    int x=0, y=0;
    int new;
    for (i=0; line[i]!='\n'; i++) {
        new = 1;
        if (line[i] == '>') x++;
        if (line[i] == '<') x--;
        if (line[i] == 'v') y++;
        if (line[i] == '^') y--;
        for (j=0; j<=p1; j++)
            if (a[j].x==x && a[j].y==y)
                new = 0;
        if (new) {
            a[p1].x = x;
            a[p1].y = y;
            p1++;
        }
    }

    printf("P1:\t%d\n", p1);
    fclose(fp);
}
