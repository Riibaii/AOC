#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXROW  1000

int slack(int x, int y, int z) {
    if      (x>=y && x>=z) return y*z;
    else if (y>=x && y>=z) return x*z;
    else                   return y*x;
}

int ribbon(int x, int y, int z) {
    int ret = 0;
    if      (x>=y && x>=z) ret += 2*(y+z);
    else if (y>=x && y>=z) ret += 2*(x+z);
    else                   ret += 2*(y+x);

    return ret + x*y*z;
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

    int p1 = 0, p2 = 0;
    int x, y, z;
    while (fgets(line, MAXLINE, fp)) {
        sscanf(line, "%dx%dx%d", &x, &y, &z);
        p1 += 2 * (x * y + y * z + z * x) + slack(x, y, z);
        p2 += ribbon(x, y, z);
    }

    printf("P1:\t%d\n", p1);
    printf("P2:\t%d\n", p2);
    fclose(fp);
}
