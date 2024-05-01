#include<string.h>
#include<stdlib.h>
// #include<string.h>

void medicalData();

struct DateInfo{
int day;
int month;
int year;
struct DateInfo* DatePtr;
};

typedef struct DateInfo Date;
struct medicineData{

char name[30];
char use[200];
Date date;
int stock;
struct  medicineData* next;

};typedef struct medicineData medicine;

medicine *head=NULL;


void insertAtBeginning(medicine mediData);