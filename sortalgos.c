#include <stdio.h>
#include "csvrnf.h"
#include <stdio.h>
#include <stdlib.h>
#include "sortlagos.h"
#include "time.h"

void in_sort(Database *a){
    clock_t toc = clock();
    int i,j,l,d,p;
    float k;
    float buff[5];
    for (i=1; i<a->size-1; i++){
        k = a->readings[i][0];
        d = a->dates[i];
        for (p =0; p<5; p++){
            buff[p] = a->readings[i][p+1];
        }
        j = i-1;
        while (j>= 0 && a->readings[j][0] > k){
            a->dates[j+1] = a->dates[j];
            for (l=0; l<7; l++){
                a->readings[j+1][l] = a->readings[j][l];
            }
            j--;
        }
        a->dates[j+1] = d;
        for (p =0; p<5; p++){
            a->readings[j+1][p+1] = buff[p];
        }
        a->readings[j+1][0] = k;
    }
    print(a->size,a);
    clock_t tic = clock();
    printf("function time %f \n", (double)(tic - toc)/CLOCKS_PER_SEC);
}

