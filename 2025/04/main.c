#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 1000
#define SIZE 140

int a[SIZE][SIZE];
int adjacent(int, int);

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
    int p1;

    int row = 0, col = 0;
    while(fgets(line, MAXLINE, fp)) {
        for (col = 0; col < SIZE; col++) {
            a[row][col] = (line[col] == '@') ? 1 : 0;
        }
        row++;
    }

    /* done reading */
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (a[row][col] && adjacent(row, col) < 4)
                p1++;
        }
    }
    printf("P1:\t%d\n", p1);

    fclose(fp);
}

int adjacent(int row, int col) {
    int ret = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                if (row+i>=0 && row+i<=SIZE-1 && col+j>=0 && col+j<=SIZE-1)
                    ret += a[row+i][col+j];
            }
        }
    }
    return ret;
}
