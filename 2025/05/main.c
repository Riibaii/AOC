#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE  1000
#define MAXCOUNT 1000

long a[MAXCOUNT];

#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))

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
    long left, right, index;
    int id = 2;
    int count = 0;
    long p1 = 0, p2 = 0;
    int i, j;
    while(fgets(line, MAXLINE, fp)) {
        if (id == 2) {
            id = sscanf(line, "%ld-%ld", &left, &right);
            a[2*count]   = left;
            a[2*count+1] = right;
            count++;
        } else {
            if (id == EOF) {
                a[2*count] = -1;
            }
            id = sscanf(line, "%ld", &index);
            for (i=0; i<count; i++) {
                if (a[2*i] <= index && index <= a[2*i+1]) {
                    p1++;
                    break;
                }
            }
        }
    }

    int i0, i1, j0, j1;
    for (i=0; i<count; i++) {
        for (j=i+1; j<count; j++) {
            i0 = 2*i;
            i1 = i0+1;
            j0 = 2*j;
            j1 = j0+1;
                /* j0 i0 (j1?i1) */
            if (a[i0]<=a[j1] && a[i0]>=a[j0]) {
                a[j1] = max(a[i1], a[j1]);
                a[i0] = -1;
                a[i1] = -1;
                break;
            }   /* (i0?j0) i1 j1*/
            else if (a[i1]<=a[j1] && a[i1]>=a[j0]) {
                a[j0] = min(a[i0], a[j0]);
                a[i1] = -1;
                a[i0] = -1;
                break;
            }   /* j0 i0 i1 j1 */
            else if (a[j0]<=a[i0] && a[i1]<=a[j1]) {
                a[i0] = -1;
                a[i1] = -1;
                break;
            }   /* i0 i1 j1 j0 */
            else if (a[i0]<=a[j0] && a[j1]<=a[i1]) {
                a[j0] = a[i0];
                a[j1] = a[i1];
                a[i0] = -1;
                a[i1] = -1;
                break;
            }
        }
    }

    for (i=0; i<count; i++) {
        if (a[2*i]>=0)
            p2 += 1 + a[2*i+1] - a[2*i];
    }

    printf("P1:\t%ld\n", p1);
    printf("P2:\t%ld\n", p2);
}
