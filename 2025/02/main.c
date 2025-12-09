#include <stdio.h>
#include <stdlib.h>

long pow10(int e) {
    long ret = 1;
    while (e--)
        ret *= 10;
    return ret;
}

int digit(long l) {
    int d = 1;
    while (l /= 10)
        d++;
    return d;
}

long helper(long start, long p, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum *= p;
        sum += start;
    }
    return sum;
}

/* generate instead of check */
long getStart(long left, int n) {
    int d = digit(left);
    long start;

    if ((d % n) == 0) {
        long p = pow10(digit(left) / n);
        start = left;
        for (int i = 0; i < n - 1; i++)
            start /= p;
        if (helper(start, p, n) < left)
            start++;
    } else {
        start = pow10(d / n);
    }
    return start;
}

/* faster for big numbers */
long invalidN(long left, long right, int n) {
    long sum = 0;
    int d = digit(left);
    long start = getStart(left, n);
    long p = pow10(digit(start));
    long value;
    while (1) {
        value = helper(start, p, n);
        if (value > right || digit(start) * n > digit(right)) 
            break;
        sum += value;
        start++;
    }
    return sum;
}

int isValid(long num) {
    long n, p;
    int d = digit(num);
    for (int i = 2; i <= digit(num); i++) {
        n = num;
        p = pow10(d / i);
        n %= p;
        if (helper(n, p, i) == num) {
            return 0;
        }
    }
    return 1;
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

    char range[100];
    long l, r, num;
    long sum_1 = 0;
    long sum_2 = 0;

    long tmp;
    while (1) {
        fscanf(fp, "%ld-%ld", &l, &r);
        sum_1 += invalidN(l, r, 2);
        for (num = l; num <= r; num++) {
            if (!isValid(num)) {
                sum_2 += num;
            }
        }
        if (fgetc(fp) != ',')
            break;
    }

    fclose(fp);
    printf("P1:\t%ld\n", sum_1);
    printf("P2:\t%ld\n", sum_2);
}
