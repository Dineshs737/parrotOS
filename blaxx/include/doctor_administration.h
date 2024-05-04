/* Libraries */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./working_hours.h"
#include "medicineData.h"
#include "Treartment.h"



// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Functions */
void LoginDoctor();
int DoctorRegister(void);
void doctor_page();
void write_Doctor_Details();

//void gettimes();
void getCurrentTimestamp(char* timestamp);

//void Write_Logs(char T_username[255], char action[20]);

// Global variables
char username[255];
char name[255];
char checked_mobile_No[10];
char d_name[];



int DoctorRegister(void)
{

    // integer variable
    int value;

    char create_password[255];
    char create_password_verify[255];
    char nameofuser[255];
    char user[255];

    //char T_username[255] = "";

    strcpy(username,"");

    //const char returnValue[255];

    // Get username from user and create a new file name as user's username
    // printf("Welcome to TRS-Application...!!");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t              ENTER YOUR NAME : ");
    scanf("%s", name);
    strcat(username, "Doctor_");
    strcat(username, name);
    strcat(username, ".txt");
    // printf("%s",T_username);
    printf("\t\t\t  -----------------------------------------------------------\n");

    // open file for reading
    FILE *read_file = fopen(username, "r");

    if (read_file != NULL)
    {

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                USERNAME ALREADY EXICTS               ");
        printf("\n\t\t\t             PLEASE CHOOSE ANOTHER ONE               ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        DoctorRegister();
    }
    if (read_file == NULL)
    {
        FILE *create_user = fopen(username, "w");

        if (create_user != NULL)
        {
            // printf("File created successfully!\n");
        }
        else
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
        scanf("%s", create_password);
        printf("\t\t\t  -----------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                    RE-ENTER YOUR PASSWORD : ");
        scanf("%s", create_password_verify);
        printf("\t\t\t  -----------------------------------------------------------\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t  REGISTERED SUCCESFULLY, NOW YOU CAN LOG IN                   ");
        printf("\t\t\t\t\t\t\t  \n-----------------------------------------------------------\n");

        value = strcmp(create_password, create_password_verify);
        if (value == 0)
        {

            fprintf(create_user, " %s %s\n", name, create_password);
            fclose(create_user);
            LoginDoctor();
            //l_r_status = 1;
            //Write_Logs(username, "user - register");
        }

        else
        {

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t              PASSWORD DOESN'T MATCH              ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                    ENTER YOUR PASSWORD : ");
            scanf("%s", create_password);
            printf("\t\t\t  -----------------------------------------------------------\n");

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                    RE-ENTER YOUR PASSWORD : ");
            scanf("%s", create_password_verify);
            printf("\t\t\t  -----------------------------------------------------------\n");

            value = strcmp(create_password, create_password_verify);
            if (value == 0)
            {
                fprintf(create_user, " %s %s\n",name, create_password);
                fclose(create_user);
                //l_r_status = 1;
                LoginDoctor();
                //Write_Logs(username, "user - register");
            }
            else
            {
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t              PASSWORD DOESN'T MATCH              ");
                printf("\n\t\t\t                TRY AGAIN LATER              ");
                printf("\n\t\t\t  ---------------------------------------------------------\n");
                //l_r_status = 0;
            }
        }

        // close connection
        fclose(create_user);
        fclose(read_file);
    }
    //Features_Services();
    //return l_r_status;
}

void LoginDoctor()
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
    char username[20] = "Doctor_";
    strcat(username, name);
    strcat(username, ".txt");

    file = fopen(username, "r");
    //printf("\n\n\n%s", username);

    if (file)
    {
        // display detail
        //fgets(Password, 255, file);

        fscanf(file, "%s  %[^\n]s", namefile, pass); //Reading from file
        //debug code

        //printf("\n%s",name);
        //printf("\n%s",pass);


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
            //gettimes();
            doctor_page();
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
                doctor_page();
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
            write_Doctor_Details();
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
void write_Doctor_Details(){
        char addres[300];
        char mobile[10];
        char Registration_No[255];
        char special_for[255];
        char filename[20];
        char register_No[200];
        
        

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t          ENTER YOUR NAME(Don't use space) : ");
        scanf("%s", filename);
        printf("\t\t\t  -----------------------------------------------------------\n");

        FILE *file_read_user_name;
        file_read_user_name=fopen(filename,"r");

        if(file_read_user_name!=NULL){
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                YOUR NAME ALREADY EXICTS               ");
            printf("\n\t\t\t             PLEASE CHOOSE ANOTHER ONE               ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            fclose(file_read_user_name);
            LoginDoctor();
        }

        if(file_read_user_name==NULL){
            FILE *file_read_user_name;
            file_read_user_name=fopen(filename,"w");

        
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                    ENTER YOUR ADRESS : ");
            scanf(" %s", addres);
            printf("\t\t\t  -----------------------------------------------------------\n");

            printf("\n\t\t\t------------------------------------------------------------\n");
            printf("\t\t\t                    ENTER YOUR REGISTRATION NO : ");
            scanf(" %s", Registration_No);
            printf("\t\t\t  -----------------------------------------------------------\n");

            printf("\n\t\t\t------------------------------------------------------------\n");
            printf("\t\t\t                    ARE YOU SPECIAL FOR : ");
            scanf(" %s", special_for);
            printf("\t\t\t  -----------------------------------------------------------\n");

            printf("\n\t\t\t------------------------------------------------------------\n");
            printf("\t\t\t                    ENTER YOUR Mobile No : ");
            scanf(" %s", mobile);
            printf("\t\t\t  -----------------------------------------------------------\n");

            fprintf(file_read_user_name,"Doctor Name: %s \n", filename);
            fprintf(file_read_user_name,"Doctor's Name: %s \n", addres);
            fprintf(file_read_user_name,"Doctor' Registration No: %s \n", Registration_No);
            fprintf(file_read_user_name,"Doctor special for: %s \n", special_for);
            fprintf(file_read_user_name,"Doctor's Mobile No: \n%s",  checked_mobile_No);
            fclose(file_read_user_name);

            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                Your Records are stored successfully..              ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            DoctorRegister();
        }
    }
    void doctor_page(){
    int option;

     do{
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =        [ 1 ]   VIEW APPOINTMENTS                  =");
        printf("\n\t\t\t        =        [ 2 ]   VIEW MEDICINE STOCK AND UBDATE     =");
        printf("\n\t\t\t        =        [ 3 ]   WORKING HOURS AND PAYMENTS         =");
        printf("\n\t\t\t        =        [ 4 ]   TREATMENT HISTORY                  =");
        printf("\n\t\t\t        =        [ 0 ]   EXIT                               =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &option);
        printf("\t\t\t  ---------------------------------------------------------\n");

    switch (option)
        {
        case 1:
            //TrainPriceCalculation();
            break;
        case 2:
            MedicineUpdate();
            break;
        case 3:
            working_hours();
            break;
        case 4:
           DoctorTreartment(d_name);
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

/*void getCurrentTimestamp(char* timestamp) {
    time_t now;
    struct tm* timeinfo;

    time(&now);
    timeinfo = localtime(&now);

    strftime(timestamp, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void gettimes() {
    FILE* logFile;
    char loginTime[64], logoutTime[64];
    char username[20]; // You can replace this with actual user ID

    // Open the log file in append mode
    logFile = fopen("login_log.txt", "a");
    if (logFile == NULL) {
        perror("Error opening file");
         ;
    }

    // Simulate user login (replace with actual login logic)
    getCurrentTimestamp(loginTime);
    //strcpy(username, "user123"); // Replace with actual user ID
    fprintf(logFile, "User %s logged in at %s\n", username, loginTime);

    // Simulate user logout (replace with actual logout logic)
    getCurrentTimestamp(logoutTime);
    fprintf(logFile, "User %s logged out at %s\n", username, logoutTime);

    // Close the log file
    fclose(logFile);

}*/



