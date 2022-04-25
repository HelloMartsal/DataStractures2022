#include <stdio.h>

struct database{
    int* dates;
    float** readings;

};
typedef struct database Database;
extern void csvr(Database); //This is the csv reader. It creates an array and places the formatted data in it
extern int daternf (char*); // This function read and formats the date
extern float zeromode (float); // THis function finds the mode of the columns
extern float cellread(FILE**,int*,int); //read all thhe characters in a cell
extern void print(int , Database);



