#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#include"./MedicineFunction.h"
//#include"./userHistory.h"
//#include "Treartment.h"
#include "medicineData.h"
//#include "userHistory.h"

char password[]="adMin21";
char user_Name[]="M_Admin";
int admin_options;

void show_management_option();
void management();


void management(){
    char get_input[255];
    char get_password[255];
 

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                ENTER THE USER NAME:  ");
    scanf("%s", get_input);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    if(strcmp(user_Name,get_input)==0){

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                ENTER THE PASSWORD:  ");
        scanf("%d", password);
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        if(strcmp(password,get_password)==0){
            show_management_option();
        }
        else{

                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                         WRONG PASSWORD                    ");
                printf("\t\t\t                         TRY AGAIN....                    ");
                printf("\n\t\t\t  ---------------------------------------------------------\n");

                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                ENTER THE PASSWORD:  ");
                scanf("%s", password);
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                show_management_option();
            }
    }
    else{
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG USER NAME                    ");
        printf("\t\t\t                         TRY AGAIN....                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                ENTER THE USER NAME:  ");
        scanf("%s", password);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
    }
}


void show_management_option(){
                printf("\n\n\n");
                printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
                printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
                printf("\n\t\t\t        =         [ 1 ]   VIEW MEDICINE STOCK AND UBDATE=");
                printf("\n\t\t\t        =         [ 2 ]   LOGS                          =");
                printf("\n\t\t\t        =         [ 3 ]   ALL TREATMENT HISTORY          =");
                printf("\n\t\t\t        =         [ 4 ]   LOG OUT                       =");
                printf("\n\t\t\t        =         [ 0 ]   EXIT                          =");
                printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
                scanf("%d", &admin_options);
                printf("\n\t\t\t  ---------------------------------------------------------\n");

                switch (admin_options)
                {
                
                case 1:
                    AdminMedicineLogin();
                    break;
                case 2:
                    //StoreMedicine();
                    //AdminHistory();
                   // AdminMedicineLogin();
                  // AdminHistory();
                    break;
                case 3:
                   // adminTreartment();
                    break;
                case 4:
                    //AdminHistory();
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
                    printf("\t\t\t                         TRY AGAIN                    ");
                    printf("\n\t\t\t  ---------------------------------------------------------\n");
                    break;
                }
}
            
                
            
            

    


