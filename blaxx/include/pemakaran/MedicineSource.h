#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicineData{

char name[200];
char use[200];
char date[10];
long int stock;
double price;
struct  medicineData* next;

};typedef struct medicineData medicine;