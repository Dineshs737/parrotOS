#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option;//gloabal variable

void patient_page();
void doctor_page();
void management_page();


void main(){

}


void doctor_page(){
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   VIEW APPOINTMENTS                  =");
        printf("\n\t\t\t        =         [ 2 ]   VIEW MEDICINE STOCK AND UBDATE     =");
        printf("\n\t\t\t        =         [ 3 ]   WORKING HOURS AND PAYMENTS         =");
        printf("\n\t\t\t        =         [ 4 ]   TREATMENT HISTORY                  =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                               =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &option);
        printf("\t\t\t  ---------------------------------------------------------\n");

}

void management_page(){
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   VIEW DOCTORS DETAILS               =");
        printf("\n\t\t\t        =         [ 2 ]   VIEW PATIENT DETAILS               =");
        printf("\n\t\t\t        =         [ 3 ]   WORKING HOURS AND PAYMENTS         =");
        printf("\n\t\t\t        =         [ 4 ]   TREATMENT HISTORY                  =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                               =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &option);
        printf("\t\t\t  ---------------------------------------------------------\n");

}