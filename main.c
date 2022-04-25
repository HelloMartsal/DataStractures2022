#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "csvrnf.h"


int main (){
    Database oceans;
    oceans.dates = (int*) malloc(sizeof(int));
    oceans.readings = (float**)malloc(sizeof(float*));
    oceans.readings[0] = (float*) malloc(sizeof(float) * 7);
    csvr(oceans);
    printf ("hello world");
    return 0;
}