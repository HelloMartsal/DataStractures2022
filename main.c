#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "csvrnf.h"
#include "float.h"


int main (){
    Database oceans;
    oceans.dates = malloc(sizeof (int));
    oceans.readings =malloc(sizeof(float*));
    Database *ocean = &oceans;
    int size = csvr(ocean);
    freeData(size, ocean);
    return 0;
}