#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "billing.c"

void patient_page();
void register_patient();
void patient_page();
void logIn();
void write_Ptient_Details()
;

// globabal variables
char username[255];
int l_r_status;
int value;

void logIn()
{
    char name[255];
    char userID[255];
    char Password[255];
    char pass[20];
    char namefile[20];

    char PassWordFromUser[255];

    char AccountCreateOption[2];

    int value;
    char user[255];

    strcpy(username, "");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                    ENTER YOUR USERNAME : ");
    scanf("%s", name);
    printf("\t\t\t  -----------------------------------------------------------\n");

    //printf("\n\n\n%s", username);

    FILE *file;
    char username[20] = "Patient_";
    strcat(username, name);
    strcat(username, ".txt");

    file = fopen(username, "r");
    printf("\n\n\n%s", username);

    if (file)
    {
        // display detail
        //fgets(Password, 255, file);

        fscanf(file, "%s  %[^\n]s", namefile, pass); //Reading from file
        //debug code

        printf("\n%s",name);
        printf("\n%s",pass);


        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t                     HELLO %s      ", namefile);
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                     PASSWORD: ");
        scanf("%s", PassWordFromUser);
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        value = strcmp(pass, PassWordFromUser);
        if (value == 0)
        {
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                YOU HAVE SUCCESSFULLY LOGGED-IN               ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            patient_page();
            // l_r_status = 1;
        }
        else
        {

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         PASSWORD WRONG                      ");
            printf("\n\t\t\t                            TRY AGAIN                        ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                     PASSWORD: ");
            scanf("%s", PassWordFromUser);
            printf("\t\t\t  ---------------------------------------------------------\n");

           value = strcmp(pass, PassWordFromUser);
        if (value == 0)
            {
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                YOU HAVE SUCCESSFULLY LOGGED-IN               ");
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                patient_page();
                // Write_Logs(T_username, "user - login");
                // l_r_status = 1;
            }
            else
            {
                // l_r_status = 0;
            }
        }
    }

    else
    {

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                   THERE'RE NO EXITING USERS                  ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t              DO YOU WANT TO CREATE AN ACCOUNT: [Y]");
        scanf("%s", AccountCreateOption);
        printf("\t\t\t  -----------------------------------------------------------\n");

        int vallue;
        value = strcmp(AccountCreateOption, "Y");
        vallue = strcmp(AccountCreateOption, "y");
        if (value == 0 || vallue == 0)
        {
            write_Ptient_Details();
        }
        else
        {
            // exit status for OS that an error occured
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            exit(0);
        }
    }
    fclose(file);

    // return l_r_status;

    // Features_Services(T_username);
}

void register_patient()
{

    char name[200];
    char pasword[200];
    char repassword[200];
    char user_name[200];
    // char T_username[255];
    int value;
    char load[255] = "";
    char initial[255] = "";

    strcpy(username, " ");
    // strcat(initial,"Patient_");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\tENTER YOUR NAME FOR [USERNAME](Don't use space) : ");
    scanf("%s", name);
    strcat(username, "Patient_");
    strcat(username, name);
    printf("\t\t\t  -----------------------------------------------------------\n");
    
    

    FILE *file;
    char username[20] = "Patient_";
    strcat(username, name);
    strcat(username, ".txt");

    file = fopen(username, "w");
    printf("\n\n\n%s", username);

    if (!file) // Changed the if method
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                FAILED TO CREATE FILE               ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        // exit status for OS that an error occured
        exit(0);
    }

    char id[255] = "1";
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                    ENTER YOUR PASSWORD : ");
    scanf(" %s", pasword);
    printf("\t\t\t  -----------------------------------------------------------\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                    RE-ENTER YOUR PASSWORD : ");
    scanf(" %s", repassword);
    printf("\t\t\t  -----------------------------------------------------------\n");

    value = strcmp(pasword, repassword);
    if (value == 0)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t  REGISTERED SUCCESFULLY, NOW YOU CAN LOG IN");
        printf("\t\t\t\t\t\t\t  \n-----------------------------------------------------------\n");
        fprintf(file, "%s %s\n", name, pasword);
        fclose(file);
        logIn();
    }
    else
    {

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t              PASSWORD DOESN'T MATCH              ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                    ENTER YOUR PASSWORD : ");
        scanf("%s", pasword);
        printf("\t\t\t  -----------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                    RE-ENTER YOUR PASSWORD : ");
        scanf("%s", repassword);
        printf("\t\t\t  -----------------------------------------------------------\n");

        logIn();

        value = strcmp(pasword, repassword);
        if (value == 0)
        {

            fprintf(file, "%s %s\n", name, pasword); // Changed your file writing method
            fclose(file);
        }
        else
        {
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t              PASSWORD DOESN'T MATCH              ");
            printf("\n\t\t\t                TRY AGAIN LATER              ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
        }
    }

    // close connection
    fclose(file);
}

void write_Ptient_Details()
{
    char addres[300];
    char mobile[10];
    char filename[20];

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t          ENTER YOUR NAME(Don't use space) : ");
    scanf("%s", filename);
    printf("\t\t\t  -----------------------------------------------------------\n");

    FILE *file_read_user_name;
    file_read_user_name = fopen(filename, "r");

    if (file_read_user_name != NULL)
    {
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                YOUR NAME ALREADY EXICTS               ");
        printf("\n\t\t\t             PLEASE CHOOSE ANOTHER ONE               ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        fclose(file_read_user_name);
        logIn();
    }

    if (file_read_user_name == NULL)
    {
        FILE *file_read_user_name;
        file_read_user_name = fopen(filename, "w");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                    ENTER YOUR ADRESS : ");
        scanf(" %s", addres);
        printf("\t\t\t  -----------------------------------------------------------\n");

        printf("\n\t\t\t------------------------------------------------------------\n");
        printf("\t\t\t                    ENTER YOUR Mobile No : ");
        scanf(" %s", mobile);
        printf("\t\t\t  -----------------------------------------------------------\n");

        fprintf(file_read_user_name, "%s \n %s", filename, mobile);
        fprintf(file_read_user_name, "\n%s", addres);
        fclose(file_read_user_name);

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                Your Records are stored successfully..              ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        register_patient();
    }
}

void patient_page()
{
    int option;
    do
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   DOCTOR DETAILS                  =");
        printf("\n\t\t\t        =         [ 2 ]   CHANNEL A DOCTOR                =");
        printf("\n\t\t\t        =         [ 3 ]   CALCULATE BILL                  =");
        printf("\n\t\t\t        =         [ 4 ]   TREATMENT HISTORY               =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &option);
        printf("\t\t\t  ---------------------------------------------------------\n");

        switch (option)
        {
        case 1:
            // TrainPriceCalculation();
            break;
        case 2:
            // TrainReservation();
            break;
        case 3:
            // Parcel();
            break;
        case 4:
            // main();
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
    } while (option != 0);
}


void main(){
    logIn();
    
}
