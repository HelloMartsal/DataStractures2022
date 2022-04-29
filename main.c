#include <stdio.h>
#include <stdlib.h>
#include "csvrnf.h"
#include "sortlagos.h"
#include "time.h"


int main (){
    Database oceans;
    oceans.dates = malloc(sizeof (int));
    oceans.readings =malloc(sizeof(float*));
    Database *ocean = &oceans;
    Database insort;
    Database qusort;
    Database *insrt = &insort;
    Database *qusrt = &qusort;
    oceans.size = csvr(ocean);
    copyData(ocean,insrt);
    copyData(ocean,qusrt);
    clock_t toc = clock();
    in_sort(insrt);
    clock_t tic = clock();
    printf("function time %f \n", (double)(10000*(tic - toc))/CLOCKS_PER_SEC);
    clock_t tok = clock();
    qu_sort(qusrt,0,qusrt->size-1);
    //print(qusrt);
    clock_t tik= clock();
    printf("function time %f \n", (double)(10000*(tik - tok))/CLOCKS_PER_SEC);
    freeData(ocean);
    freeData(insrt);
    freeData(qusrt);
    return 0;
}