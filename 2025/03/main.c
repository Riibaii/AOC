#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/*
    1. largest index not ending
    2. largest index after that */

int joltage(char * line) {
    int maxL = 0; 
    int indexL = 0;
    int len = strlen(line);
    int i, c;

    for (i = 0; i < len - 1; i++) {
        if ((c = (line[i] - '0')) > maxL) {
            maxL = c;
            indexL = i;
        }
    }

    int maxR = 0;
    for (i = indexL + 1; i < len; i++){
        if ((c = (line[i] - '0')) > maxR)
            maxR = c;
    }
    return 10 * maxL + maxR;
}

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
    int sum1 = 0;
    int v, count = 0;
    while(fgets(line, MAXLINE, fp)) {
        line[strlen(line) - 1] = '\0'; // remove '\n'
        v = joltage(line);
        count++; //test
        sum1 += v; //test
    }

    printf("P1:\t%d\n", sum1);
    fclose(fp);
}
