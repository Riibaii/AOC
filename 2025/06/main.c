#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 10000
#define MAXROW  5
#define MAXCOL  2000

long a[MAXROW][MAXCOL];

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

    char line[MAXROW][MAXLINE];
    long p1 = 0, p2 = 0;

    int row = 0, col = 0;
    long val;

    char *token, *ptr;
    while(fgets(line[row], MAXLINE, fp)) {
        col = 0;
        token = strtok_r(line[row], " ", &ptr);
        while (token != NULL) {
            a[row][col++] = (row==MAXROW-1) ? \
                            token[0] : atoi(token);
            token = strtok_r(NULL, " ", &ptr);
        }
        a[row][col] = -1;
        row++;
    }

    for (col=0; col<MAXCOL; col++) {
        if (a[0][col] < 0) break;
        if (a[4][col] == '+') {
            p1 += a[0][col] + a[1][col] + a[2][col] + a[3][col];
        }
        else {
            p1 += a[0][col] * a[1][col] * a[2][col] * a[3][col];
        }
    } 
    printf("0%s\n4%s\n", line[0], line[4]);

    printf("P1:\t%ld\n", p1);
    printf("P2:\t%ld\n", p2);

    fclose(fp);
}
