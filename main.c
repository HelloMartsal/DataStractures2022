#include <stdio.h>
#include <stdlib.h>
#include "csvrnf.h"
#include "sortlagos.h"


int main (){
    Database oceans;
    oceans.dates = malloc(sizeof (int));
    oceans.readings =malloc(sizeof(float*));
    Database *ocean = &oceans;
    Database insort;
    Database *insrt = &insort;
    oceans.size = csvr(ocean);
    copyData(ocean,insrt);
    for (int i = 0; i<20; i++){
        printf("test\n");
    }
    in_sort(insrt);
    freeData(oceans.size, ocean);
    freeData(insort.size, insrt);
    return 0;
}