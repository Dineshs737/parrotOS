
#include<stdio.h>

int sum(int * ,int *);

int main(int argc , char *argv[])
{
    int num1,num2;
    printf("Enter number :");
    scanf("%d",&num1);

    printf("Enter number :");
    scanf("%d",&num2);

    printf("%d",sum(&num1,&num2));


}

int sum(int* n1 , int* n2){
    return (*n1)+(*n2);
}