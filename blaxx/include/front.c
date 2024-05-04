#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./admin.h"
#include "./patientLogin.h"
#include "./doctor_administration.h"


    /*void register_patient();
    void write_Ptient_Details();
    void  logIn();*/

    /*void LoginDoctor();
    int DoctorRegister(void);
    void write_Doctor_Details();*/

    void welcomeMessage();
    void Doctor();
    void  patient();
    //void management();

    int data;

void main(){
    welcomeMessage();
}

void welcomeMessage()

{
    do{
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t        =                  WELCOME                        =");
    printf("\n\t\t\t        =                    TO                           =");
    printf("\n\t\t\t        =                 MEDI CARE                       =");
    printf("\n\t\t\t        =           CHANNELLING & MANAGEMENT              =");
    printf("\n\t\t\t        =                   SYSTEM                         =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t        =         [ 1 ]   DOCTOR                         =");
    printf("\n\t\t\t        =         [ 2 ]   PATIENT                        =");
    printf("\n\t\t\t        =         [ 3 ]   MANAGEMENT                     =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                   ARE YOU A :");
    scanf("%d",&data);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch(data){
        case 1:
            Doctor();
            break;
        case 2:
            patient();
            break;
        case 3:
            management();
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
    }while(data!=0);
}
void Doctor(){
do{
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t        =         [ 1 ]   LOGIN                          =");
    printf("\n\t\t\t        =         [ 2 ]   REGISTER                       =");
    printf("\n\t\t\t        =         [ 3 ]   LOGOUT                         =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                   ARE YOU A :                                 ");
    scanf("%d",&data);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch(data){
        case 1:
            LoginDoctor();
            break;
        case 2:
            write_Doctor_Details();
            break;
        case 3:
            //welcomeMessage();
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
    }while(data!=0);
}

void  patient(){
do{
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\t\t\t        =         [ 1 ]   LOGIN                          =");
    printf("\n\t\t\t        =         [ 2 ]   REGISTER                       =");
    printf("\n\t\t\t        =         [ 3 ]   LOGOUT                         =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     ENTER A CHOICE :                          ");
    scanf("%d",&data);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch(data){
        case 1:
            logIn();
            break;
        case 2:
            write_Ptient_Details();
            break;
        case 3:
            welcomeMessage();
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
    }while(data!=0);
}
