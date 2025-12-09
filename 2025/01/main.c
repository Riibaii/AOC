#include <stdio.h>
#include <stdlib.h>

#define SHIFT 50000
/* for neg div */

int helper(char * op) {
    int sign;
    (op[0] == 'L') ? (sign = -1) : (sign = 1);
    return sign * atoi(op + 1);
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

    int pos = 50, p1 = 0, p2 = 0, rot, buf;
    char line[100];
    while(fgets(line, 100, fp)){
        rot = helper(line);
        buf = pos;
        pos += rot;
        if (pos % 100 == 0) {
            p1++;
        }
        if (buf % 100 == 0) {
            p2 += abs(rot) / 100;
        } else if (pos % 100 == 0) {
            p2 += 1 + abs(rot) / 100;
        } else 
            p2 += abs((pos + SHIFT) / 100 - (buf + SHIFT) / 100);
    }

    printf("P1: \t%d\n", p1);
    printf("P2: \t%d\n", p2);
    fclose(fp);
}
