#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "csvrnf.h"
#include "sortlagos.h"
#include "time.h"

void in_sort(Database *a){
    //clock_t toc = clock();
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
    //print(a->size,a);
    //clock_t tic = clock();
    //printf("function time %f \n", ((double)(tic - toc)/CLOCKS_PER_SEC));
}

void qu_sort(Database *a,int low, int high){
    if (low < high){
        int pivot = partition(a, low, high);
        qu_sort(a, low, pivot-1);
        qu_sort(a,pivot,high);
    }
}

int partition(Database *a,int low, int high){
    if (a->dates[low] == 20191106){
        int test = 0;
    }
    float pivot = a->readings[low][0];
    int j;
    int i = low+1;
    for (j = low+1; j < high; j++){
        if (a->readings[j][0] <= pivot){
            swap(a,j,i);
            i++;
        }
    }
    swap(a,i-1,low);
    return i;
}

void swap (Database *a,int i, int j){
    int date = a->dates[i];
    a->dates[i] = a->dates[j];
    a->dates[j] = date;
    float temp;
    for (int k=0; k<7; k++){
        temp = a->readings[i][k];
        a->readings[i][k] = a->readings[j][k];
        a->readings[j][k] = temp;
    }
}


