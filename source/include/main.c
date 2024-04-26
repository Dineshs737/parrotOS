#include<stdio.h>
#include"./lib.h"

medicine *medicineInput;


int main(int argc, char const *argv[])
{
int choice,pos;

while(1){
printf("\n_____________ Medicine  List Menu ____________________\n\n");
printf("\t\t1.Insert at Beginning\n");
printf("\t\t2.display\n");
printf("\t\t3.Insert at specified position\n");
printf("\t\t4.Delete from specified position\n");
printf("\t\t5.Exit\n");

printf("______________________________________________________\n");
printf("Enter your choice:\t");
scanf("%d",&choice);

switch(choice)
{
    case 1:
    printf("\n\n##########    Enter the data    ############\n\n");
    printf("Enter medicine name :");
    scanf("%s",medicineInput->name);
    printf("Enter use of medicine :");
    scanf("%s",medicineInput->use);
    printf("Enter the experdate day / month / year :");
    scanf("%d %d %d",medicineInput->date.day,medicineInput->date.month,medicineInput->date.year);
   // insertAtBeginning(&medicineInput);
    break;
   // case 2: display();break;

    case 3: 
    printf("Enterthe pos: ");
    scanf("%d",&pos);
    printf("\n\n##########    Enter the data    ############\n\n");
    printf("Enter medicine name :");
    scanf("%s",medicineInput->name);
    printf("Enter use of medicine :");
    scanf("%s",medicineInput->use);
    printf("Enter the experdate day / month / year :");
    scanf("%d %d %d",medicineInput->date.day,medicineInput->date.month,medicineInput->date.year);
    if(pos<0){
        printf("\nInvalid position\n");
    }
    //instertPosition(pos,&medicineInput);
    break;
    case 4:
    printf("Enterthe pos: ");
    scanf("%d",&pos);
      if(pos<0){
        printf("\nInvalid position\n");
    }
     //DeletedPosition(pos);
    break;
    

}
}
    return 0;
}
