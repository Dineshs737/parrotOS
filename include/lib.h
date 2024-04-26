#define _LIB_H_

// #ifndef _LIB_H_
#include<stdio.h>
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode* next; //self refraceal

};

typedef struct lnode node;

node* head =NULL;

void insertAtBeginning(int val);

void  display() ;

void  instertPosition(int pos,int val);

void  DeletedPosition(int pos);