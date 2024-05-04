#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char patientName[100];
    char doctorName[100];
    char date[11];
    char time[6];
} Appointment;
void record_appointment() {
    Appointment newAppointment;
    FILE *fp1;
    fp1 = fopen("Appointment.txt", "a");

    if (fp1 == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                      Enter appointment ID:        ");
        scanf("%d", &newAppointment.id);
	printf("\n\t\t\t  ---------------------------------------------------------\n");

    
    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                      Enter doctor name:");
    scanf("%s", newAppointment.doctorName);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
    
    
     printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                    Enter patient name:");
     scanf("%s", newAppointment.patientName);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
   
    
     printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     Enter date (YYYY-MM-DD): ");
     scanf("%s", newAppointment.date);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
   
    
     printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                     Enter time (HH:MM): ");
     scanf("%s", newAppointment.time);
	printf("\n\t\t\t  ---------------------------------------------------------\n");
   

    fwrite(&newAppointment, sizeof(Appointment), 1, fp1);
    fclose(fp1);
    printf("Appointment record added successfully.\n");
}

void view_appointment_details() {
    FILE *fp1;
    Appointment app;

    fp1 = fopen("Appointment.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\nAppointment Details:\n");
    while (fread(&app, sizeof(Appointment), 1, fp1) == 1) {
    	
    	printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t              Doctor Name: %s\n", app.doctorName                );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
    
       	printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t              Appointment ID: %d\n", app.id                     );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
        printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t              Patient Name: %s\n", app.patientName              );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
        
        printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t                   Date: %s\n", app.date                        );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
        
        printf("\n\t\t\t  ---------------------------------------------------------\n");
   		printf("\t\t\t                   Time: %s\n", app.time                        );
		printf("\n\t\t\t  ---------------------------------------------------------\n");
       
        printf("\n");
    }

    fclose(fp1);
}

/*int main() {
    int choice;

    do {
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =       [ 1 ]   Add New Appointment        =");
        printf("\n\t\t\t        =       [ 2 ]   View Appointment Details   =");
        printf("\n\t\t\t        =       [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOICE : ");
        scanf("%d", &choice);
        printf("\t\t\t  -----------------------------------------------------------\n");


        switch (choice) {
            case 1:
                record_appointment();
                break;
            case 2:
                view_appointment_details();
                break;
            case 0:
                printf("Thank you.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}*/

