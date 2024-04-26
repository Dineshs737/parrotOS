
#include"../include/lib.h"
// #include "lib.h"
void hello()
{
    printf("hello I am Dinesh\n");
}
void insertAtBeginning(int val)
{
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL) printf("out of memory"); return;

    newNode ->data =val;

    if(head==NULL){
        newNode->next =NULL;
        head =newNode;
    }
    else{
        newNode ->next =head;
        head =newNode;


    }
    printf("inserted %d At Beginning ",val);
}

void  display() {
    if(head==NULL){
        printf("\nList is empty\n");
    }
     node* temp=head;
     printf("Elements in the list are :");
     while(temp!=NULL)
     {
        printf("%d",temp->data);
        temp = temp->next;
     }
}

void  instertPosition(int pos,int val){
    int i=1;
    node* newNode =(node*)malloc(sizeof(node));
    if(newNode==NULL) printf("out of memory"); return;

    newNode->data =val; 
    node *temp =head;
    for(i=1;i<=pos-1;i++){
        temp= temp->next;
        if(temp==NULL){
            printf("Invalid position lsat \n");
            return;
        }
    }
    
    newNode->next =temp->next;
    temp->next = newNode;

}

void  DeletedPosition(int pos){
    int i;
    node *temp=head;
    node* prev;
if(head==NULL){
    printf("\nList is empty\n");
    return;
}
if(pos==0)
{
    head = head ->next;
     printf("Deleted %d",temp->data);
     free(temp);

}
for(i=0;i<pos;i++){
    prev=temp;
    prev = temp->next;
      if(temp==NULL){
            printf("Invalid position lsat \n");
            return;
        }
       
}
 prev->next = temp->next;
 printf("Deleted %d",temp->data);
 free(temp);


}