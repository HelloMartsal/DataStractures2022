#include "csvrnf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int csvr(Database *a){
    FILE* fl;
    char bit;
    //fl = fopen("D:\\panepistimio\\e3\\DataStructures2022\\DataStructures2022\\cmake-build-debug\\ocean.csv","r");
    fl = fopen("/mnt/d/panepistimio/e3/DataStructures2022/DataStructures2022/ocean.csv","r"); //opens file
    if (fl == NULL){                                                                                         //checks for exceptions
        printf("File is not accesible \n");
        return -1;
    }
    fscanf(fl, "%*[^\n]\n");  //skips the first line
    int counter1 = 0; // counter for the rows
    int counter2; // counter for the columns
    int counter3; // counter for the characters
    do{
        int size3 = counter1 + 1;                                               //we increase the number of rows by one and add the necessary columns
        float **temp1;
        temp1 =realloc(a->readings,sizeof(float*)*size3);
        if(temp1 == NULL){
            printf("realloc didn't work");
            free(a->readings);
            return -1;
        }else {
            a->readings = temp1;
            a->readings[counter1] =(float*) malloc(sizeof(float)*7);
        }
        for (counter2 = 0; counter2<8; counter2++){
            int size;                           //counter for the size of the buffer array
            char* buff = NULL;//buffer
            counter3 = 0; // counter for indexing the buffer
            do{
                size = counter3+1; //increment the counter for the size of the buffer
                char *temp;
                temp =realloc(buff,sizeof(char)*size);
                if(temp == NULL){
                    printf("realloc didn't work");
                    free(buff);
                    return -1;
                }else {
                    buff = temp;
                }
                bit = fgetc(fl);
                if (bit == ',' || bit == '\n'){ //when we reach the end of a cell we add '\0' and break
                    buff[counter3] = '\0';
                    break;
                }
                buff[counter3] = bit;
                counter3++;
            }while(bit != EOF);

            int datef;
            if (counter2 == 0){  //if it's a date cell then we call daternf function
                int size2 = counter1+1;
                int *temp3;
                temp3 =realloc(a->dates,sizeof(int)*size2);
                if(temp3 == NULL){
                    printf("realloc didn't work");
                    free(a->dates);
                    return -1;
                }else {
                    a->dates = temp3;
                }
                datef = daternf(buff);
                a->dates[counter1] = datef;
                continue;
            }

            a->readings[counter1][counter2-1] = atof(buff);
            free(buff);
        }
        counter1++;

    }while (bit != EOF);
    fclose(fl);
    zeromode(counter1,a);
    print(counter1,a);
    return counter1;
}

int daternf(char* b){
    int date;
    char d[3];
    char m[3];
    char y[9];


    strncpy(m,b,2);
    m[2] = '\0';
    strncpy(d,b+3,2);
    d[2] = '\0';
    strncpy(y,b+6,4);
    y[4] = '\0';
    strcat(y,m);
    strcat(y,d);
    date = atoi(y);   //format of the data: yyyymmdd

    return date;
}
void print(int c,Database *a){ //this function is for testing
    for (int i = 0;i<c-1;i++){
        printf("%d ",a->dates[i]);
        for (int j = 0; j<7;j++){
            printf("%f ",a->readings[i][j]);
        }
        printf("\n");
    }
}

void zeromode(int n,Database *a){
    int i,j,k,mode;
    int max;
    float modef = 0;
    int indx[1405];
    int count;
    for(i=0; i<7; i++){
        count = 0;
        max = 0;
        for (j=0; j<n-1; j++){
            if (a->readings[j][i] == 0.0){
                indx[count] = j;
                count++;
                continue;
            }
            mode = 1;
            for(k=j; k<n-1; k++){
                if(a->readings[j][i] == a->readings[k][i] && j!= k){
                    mode++;
                }
            }
            if (mode > max){
                modef = a->readings[j][i];
                max = mode;
            }
        }
        int l;
        for (l=0; l<count; l++){
            a->readings[indx[l]][i] = modef;
        }
    }
}

void freeData(int c, Database *a){
    free(a->dates);
    int i;
    for (i=0; i<c; i++){
        free(a->readings[i]);
    }
    free(a->readings);
}