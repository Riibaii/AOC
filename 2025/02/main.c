#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digit(long l) {
    int d = 1;
    while (l /= 10)
        d++;
    return d;
}

long invalid(long left, long right) {
    /*  smallest first;
        bigger and bigger until r */
    long sum = 0;
    int d = digit(left);
    long start_half;

    if ((d % 2) == 0) {
        start_half = left / pow(10, d/2); 
        if (start_half + start_half * pow(10, digit(start_half)) < left)
            start_half++;
    } else {
        start_half = pow(10, d/2);
    }

    long value;
    while (1) {
        value = start_half + start_half * pow(10, digit(start_half));
        if (value > right)
            break;
        sum += value;
        start_half++;
        printf("\t%ld\n", value);
    }
    return sum;
}

int main (int argc, char * argv[]) {
    FILE * fp;
    fp = fopen(argv[1],  "r");

    if (fp != NULL) {
        printf("%s\topened\n", argv[1]);
    } 
    else {
        printf("cannot open file!\n");
        return -1;
    }
/*  invalid ID:
        1. in range
        2. digit repeat twice
    input:
        eg: 11-22,95-115,998-1012 */

    char range[100];
    long l, r;
    long sum = 0;

    while (1) {
        fscanf(fp, "%ld-%ld", &l, &r);
        sum += invalid(l, r);
        if (fgetc(fp) != ',')
            break;
    }

    fclose(fp);
    printf("%ld\n", sum);
    return sum;
}
