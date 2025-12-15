#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXROW 142
#define MAXCOL 141
#define MAXLINE 200

#define RAY 1
#define DOT 0
#define SPL 4

int a[MAXROW][MAXCOL];

int main(int argc, char * argv[]) {
    FILE * fp;
    fp = fopen(argv[1],  "r");

    if (fp != NULL)
        printf("%s\topened\n", argv[1]);
    else {
        printf("cannot open file!\n");
        return -1;
    }

    long p1 = 0, p2 = 0;

    int row = 0, col = 0;
    char line[MAXLINE];
    while(fgets(line, MAXLINE, fp)) {
        for (col=0; line[col]!='\n'; col++) {
            if (line[col] == '.')
                a[row][col] = DOT;
            else if (line[col] == '^')
                a[row][col] = SPL;
            else if (line[col] == 'S')
                a[row][col] = RAY;
        }        
        row++;
    }

    for (row=1; row<MAXROW; row++) {
        for (col=0; col<MAXCOL; col++) {
            if (a[row-1][col] == RAY) {
                if (a[row][col] == DOT)
                    a[row][col] = RAY;
                else if (a[row][col] == SPL) {
                    if (col-1>0)      a[row][col-1] = RAY;
                    if (col+1<MAXCOL) a[row][col+1] = RAY;
                    p1++;
                }
            }
        }
    }

    printf("P1:\t%ld\n", p1);
    printf("P2:\t%ld\n", p2);

    fclose(fp);
}
