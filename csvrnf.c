#include "csvrnf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void csvr(Database a){
    FILE* fl;
    char bit;
    fl = fopen("D:\\panepistimio\\e3\\DataStructures2022\\DataStructures2022\\ocean.csv","r");
    if (fl == NULL){
        printf("File is not accesible \n");
        return;
    }
    fscanf(fl, "%*[^\n]\n");
    int counter1 = 0; // counter for the rows
    int counter2; // counter for the columns
    int counter3; // counter for the characters
    do{
        counter2 = 0;
        for (counter2 =0; counter2 <8; counter2++){ //loop for the columns
            int size = 0;
            char* buff = (char*)malloc(sizeof(char)); //buffer
            counter3 = 0; // counter for the buff
            int flag = 0;
            while (flag == 0){
                bit = fgetc(fl);
                if (bit == ',' || bit == '\n'){
                    break;
                }
                buff[counter3] = bit;
                if (counter3 == 0){
                    size = 2;
                }else{
                    size = counter3+2;
                }
                buff =realloc(buff,sizeof(char)*size);
                counter3++;
                if (bit == EOF || bit == '\n'){
                    flag = 1;
                }
            }
            int datef;
            if (counter2 == 0){
                int size2;
                if (counter1 == 0){
                    size2 = 2;
                }else{
                    size2 = counter1+2;
                }
                datef = daternf(buff);
                a.dates[counter1] = datef;
                a.dates = realloc(a.dates,sizeof(int*)*size2);
                continue;
            }
            float test = atof(buff);
            a.readings[counter1][counter2-1] = atof(buff);
            float te = a.readings[counter1][1];
            free(buff);
        }
        counter1++;
        int size2 = counter1 + 2;
        a.readings = realloc(a.readings,sizeof(float*)*size2);
        a.readings[counter1] =(float*)malloc(sizeof(float) * 7);

    }while (bit != EOF);
    print(counter1 , a );
}
/*void csvr(Database a){
    FILE *fl;
    fl = fopen("D:\\panepistimio\\e3\\DataStructures2022\\DataStructures2022\\ocean.csv","r");
    int counter = 0;
    int counter2;
    int flag = 0;
    char bit;
    fscanf(fl, "%*[^\n]\n"); //skip the first line
    do{
        counter2 = 0;
        while(counter2<6){
            while (bit !=','){
                bit = fgetc(fl);

            }
        }
    }while (flag !=1);
}*/

int daternf(char* b){
    int date;
    char d[3];
    char m[3];
    char y[9];

    strncpy(d,b,2);
    d[2] = '\0';
    strncpy(m,b+3,2);
    m[2] = '\0';
    strncpy(y,b+6,4);
    y[8] = '\0';
    strcat(y,m);
    strcat(y,d);
    date = atoi(y);
    float test = date;
    int test2 = 1234567890;



    return date;
}

float zeromode(float c){
    int mV = 0;
    int count = 0;
    int mC = 0;
    int i,j;

}

float cellread(FILE **fl,int *flag,int d){
    char bit;
    bit = fgetc(*fl);
    *flag = 1;
    return 10.00;
}

void print(int c,Database a){
    for (int i = 0;i<=c;i++){
        for (int j = 0; j<7;j++){
            printf("%f",a.readings[i][j]);
        }
        printf("\n");
    }
}

