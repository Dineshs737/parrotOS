#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[100];
    char specialty[50];
    char working_days[10];
    char contact[15];
    float working_hours;
} Doctor;

void doctor_record() {
    Doctor new_doctor;
    FILE *fp;
    fp = fopen("doctors.txt", "w");

    if (fp == NULL) {
        printf("File does not created.\n");
        exit(1);
    }
    
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     Enter doctor's name: ");
	scanf("%s", new_doctor.name);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
    
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t               Enter doctor's woking days: ");
  	scanf("%s", new_doctor.working_days);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
  
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t               Enter doctor's working hours: ");
   	scanf("%f", &new_doctor.working_hours);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
   

    fwrite(&new_doctor, sizeof(Doctor), 1, fp);
    fclose(fp);
    printf("Doctor recor d added successfully.\n");
   
}

void view_doctor_details() {
    FILE *fp;
    Doctor doc;

    fp = fopen("doctors.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\nDoctor Details:\n");
    while (fread(&doc, sizeof(Doctor), 1, fp) == 1) {
    	printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t            Name: %s\n", doc.name                               );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
     
       	printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t          Specialty: %s\n", doc.specialty                       );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
        printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t              Contact: %s\n", doc.contact                       );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
       	printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t              Working Day:%S",doc.working_days                  );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
        printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t          Working Hours: %.2f\n", doc.working_hours             );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\n");
    }

    fclose(fp);
}

/*int main() {
    int choice;

    do {
    	 printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =       [ 1 ]   Add Doctor Details    =");
        printf("\n\t\t\t        =       [ 2 ]   View Doctor Details   =");
        printf("\n\t\t\t        =       [ 0 ]   EXIT                  =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &choice);
        printf("\t\t\t  -----------------------------------------------------------\n");
       

        switch (choice) {
            case 1:
                doctor_record();
                break;
            case 2:
                view_doctor_details(); 
                break;
            case 3:
                printf("Thank you.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}*/

