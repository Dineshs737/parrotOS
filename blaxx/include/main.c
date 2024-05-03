#include<stdio.h>
#include"./lib.h"
//#include"./pecint.h"

medicine medicineInput;


int main(int argc, char const *argv[])
{
fileLoadUp();
int choice,pos;

while(1){
printf("\n_____________ Medicine  List Menu ____________________\n\n");
printf("\t\t1.add\n");
printf("\t\t2.display\n");
printf("\t\t3.Update Medicine info\n");
printf("\t\t4.back\n");
printf("\t\t5.Exit\n");
printf("\t\trecentTreatment\n");

printf("______________________________________________________\n");
printf("Enter your choice:\t");
scanf("%d",&choice);

switch(choice)
{
    case 1:
    printf("\n\n##########    Enter the data    ############\n\n");
    printf("Enter medicine name :");
    scanf("%s",medicineInput.name);
    printf("Enter use of medicine :");
    scanf("%s",medicineInput.use);
    printf("Enter the experdate day / month / year :");
    scanf("%s",medicineInput.date);

    printf("Enter number of stock available :");
    scanf("%d",&medicineInput.stock);

    storeDataFromFile(&medicineInput);
    break;
    case 2: display();break;

    case 3:
    printf(" Enter medicine name  :");
    scanf("%s",medicineInput.name);
    upadate(medicineInput.name);
     //DeletedPosition(pos);
    break;

    //case 4: main();
   // break;

   case 5 :exit(0);
   break;

  // case 6:writeRcentTreatment();

   break;

  // default:{printf("\ninvalid input tryagin\n");}

    

}
}
    return 0;
}
