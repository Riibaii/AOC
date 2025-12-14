#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 10000
#define MAXROW  5

long getnumber(char [MAXROW][MAXLINE], int);

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

    char line[MAXROW][MAXLINE];
    while(fgets(line[row++], MAXLINE, fp))
        ;
    long val, buf;
    for (col=0; col<strlen(line[MAXROW-1]); col++) {
        if (line[MAXROW-1][col] == '+') {
            for (int i=0; i<MAXROW-1; i++)
                p1 += atol(line[i]+col);
            while ((val = getnumber(line, col))) {
                p2 += val;
                col++;
            }
        }
        else if (line[MAXROW-1][col] == '*') {
            buf = 1;
            for (int i=0; i<MAXROW-1; i++)
                buf *= atol(line[i]+col);
            p1 += buf;
            buf = 1;
            while ((val = getnumber(line, col))) {
                buf *= val;
                col++;
            }
            p2 += buf;
        }
    }
    printf("P1:\t%ld\n", p1);
    printf("P2:\t%ld\n", p2);

    fclose(fp);
}

long getnumber(char line[MAXROW][MAXLINE], int col) {
    char buf[MAXROW];
    int i;
    for (i=0; i<MAXROW; i++)
        buf[i] = isdigit(line[i][col]) ? line[i][col] : ' ';
    buf[i] = '\0';
    return atol(buf);
}
