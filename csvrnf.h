#include <stdio.h>

struct database{     //This struct is our database
    int* dates;
    float** readings;
    int size;

};
typedef struct database Database;
extern int csvr(Database *); //This is the csv reader.It creates an array and places the formatted data in it
extern int daternf (char*); //this function creates an integer out of the date that we can then sort and index easily
extern void zeromode (int, Database *); // This function finds the mode of the columns and inputs it in the cell with 0s in them
extern void print(int , Database*);
extern void freeData(int , Database*); //This function frees the memory of the database
extern void copyData(Database *,Database *); //Copies data from one struct to another
//TODO BGALE TO INT GIATI TO SIZE EINAI MESA STO STRUCT


