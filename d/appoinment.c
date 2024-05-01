
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    int doctor_ID;
    char patientName[100];
    char date[11]; 
    char time[6]; 
} Appointment;


void addAppointment(Appointment appointments[], int *appointmentCount);
void viewAppointments(Appointment appointments[], int appointmentCount);

int main() {
    Appointment appointments[MAX_APPOINTMENTS]; 
    int appointmentCount = 0; 

   
    int choice;
    do {
        printf("\n--- Doctor Dashboard ---\n");
        printf("1. Add New Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                viewAppointments(appointments, appointmentCount);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}


void addAppointment(Appointment appointments[], int *appointmentCount) {
    if (*appointmentCount >= MAX_APPOINTMENTS) {
        printf("Maximum appointment limit reached.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter appointment ID: ");
    scanf("%d", &newAppointment.id);
    printf("Enter patient name: ");
    scanf("%s", newAppointment.patientName);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", newAppointment.time);

    appointments[*appointmentCount] = newAppointment;
    (*appointmentCount)++;
}


void viewAppointments(Appointment appointments[], int appointmentCount) {
    printf("\n--- Appointments ---\n");
    int i;
    for ( i = 0; i < appointmentCount; i++) {
        printf("Appointment ID: %d\n", appointments[i].id);
        printf("Patient Name: %s\n", appointments[i].patientName);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n\n", appointments[i].time);
    }
}

