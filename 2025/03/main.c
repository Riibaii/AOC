#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 1000

long joltage(char * line, int n) {
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;

    int indexL = 0;
    int maxL = 0;
    int len = strlen(line);
    int i, c;

    for (i = 0; i < len - n + 1; i++) {
        if ((c = (line[i] - '0')) > maxL) {
            maxL = c;
            indexL = i;
        }    
    }
    return maxL * pow(10, n - 1) + joltage(line + indexL + 1, n - 1);
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
    long sum1 = 0, sum2 = 0;
    while(fgets(line, MAXLINE, fp)) {
        line[strlen(line) - 1] = '\0'; // remove '\n'
        sum1 += joltage(line, 2);
        sum2 += joltage(line, 12);
    }

    printf("P1:\t%ld\n", sum1);
    printf("P2:\t%ld\n", sum2);
    fclose(fp);
}
