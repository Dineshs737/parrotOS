#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


    void register_patient();
    void write_Ptient_Details();
    void  logIn();

    void patient_page();
    void doctor_page();
    void management_page();


    void patient_administrate();
    void doctor_administrate();
    void management_administrate();

        


void doctor_administrate()
{
    int get;//variable get user input
     printf("********************************************************\n*----------------------Welcome-------------------------*\n*------------------Medi Care Centre--------------------*\n********************************************************\n1.Log in\n2.Register\nExite\n\n");
    printf("Select an option: ");
    scanf("%d",&get);

    switch(get){
        case 1:
            //logIn();
            break;
        case 2:
            //Register();
            break;
        case 3:
            //management();
            break;
        default:
            printf("Invalid Option. Try again..."); 
    }
}


void patient_administrate(){
    int option;//vriable for take the user iput value
    do
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   LOGIN                     =");
        printf("\n\t\t\t        =         [ 2 ]   REGISTER                  =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &option);
        printf("\t\t\t  ---------------------------------------------------------\n");

     
        switch(option){
            case 1:
                logIn();
                break;
            case 2:
                register_patient();
                break;
             case 0:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            exit(0);
            break;

            default:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         WRONG INPUT                    ");
            printf("\n\t\t\t                         TRY AGAIN                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;    
        }
    }while (option != 0);       


}


void management_administrate(){
    int get;//variable get user input
     printf("********************************************************\n*----------------------Welcome-------------------------*\n*------------------Medi Care Centre--------------------*\n********************************************************\n1.Log in\n2.Register\nExite\n\n");
    printf("Select an option: ");
    scanf("%d",&get);
    
    switch(get){
        case 1:
            //logIn();
            break;
        case 2:
            //Register();
            break;
        case 3:
            //management();
            break;
        default:
            printf("Invalid Option. Try again..."); 
    }
}



