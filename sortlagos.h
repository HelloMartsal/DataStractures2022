#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

extern void in_sort(Database *); //Insertion Sort function
void qusorttimeprint(Database *, int, int); //wrapper for qu_sort so we can print the array and find the cpu time
int partition(Database *, int, int); //finds the partion position
extern void qu_sort(Database *, int, int); // Bubble Sort function
void swap(Database *, int, int); // swaps the elements

