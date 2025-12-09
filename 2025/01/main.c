#include <stdio.h>
#include <stdlib.h>

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

    int pos = 50, count = 0, rot;
    char line[100];
    while(fgets(line, 100, fp)){
        rot = helper(line);
        pos += rot;
        if (pos % 100 == 0)
            count++;
    }

    printf("%d", count);
    fclose(fp);
}
