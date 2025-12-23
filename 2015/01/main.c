#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 10000

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
    fgets(line, MAXLINE, fp);

    for (int i=0; line[i]!='\n'; i++) {
        if (line[i]=='(')      p1++;
        else if (line[i]==')') p1--;
        if (!p2 && p1==-1) p2=i+1;
    }

    printf("P1:\t%d\n", p1);
    printf("P2:\t%d\n", p2);
    fclose(fp);
}
