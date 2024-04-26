
 #include<stdio.h>
#include<stdbool.h>
#include"../include/lib.h"

int main(int argc, char * argv[])
{
    int choice,val,pos;



// printf("\n_____________ Linked List Menu ____________________\n");
// printf("1.Insert at Beginning\n");
// printf("2.display\n");
// printf("3.Insert at specified position\n");
// printf("4.Delete from specified position\n");
// printf("5.Exit\n");

// printf("______________________________________________________\n");
// printf("Enter your choice:\t");

while (true)
{

printf("\n_____________ Linked List Menu ____________________\n");
printf("1.Insert at Beginning\n");
printf("2.display\n");
printf("3.Insert at specified position\n");
printf("4.Delete from specified position\n");
printf("5.Exit\n");

printf("______________________________________________________\n");
printf("Enter your choice:\t");
scanf("%d",&choice);

switch(choice)
{
    case 1:
    printf("Enter the data : ");
    scanf("%d",&val);
    insertAtBeginning(val);
    break;
    case 2: display();break;

    case 3: 
    printf("Enterthe pos: ");
    scanf("%d",&pos);
    printf("Enter the adata");
    scanf("%d",&val);
    if(pos<0){
        printf("\nInvalid position\n");
    }
    instertPosition(pos,val);
    break;
    case 4:
    printf("Enterthe pos: ");
    scanf("%d",&pos);
      if(pos<0){
        printf("\nInvalid position\n");
    }
     DeletedPosition(pos);
    break;
    

}
if(choice==5)  break;

}
    
    return 0;

}