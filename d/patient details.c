#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    char address[200];
    char contact[15];
    char appointment_date[10];
    char bloodgroup[5];
} Patient;


void patient_record() {
    Patient new_patient;
    FILE *fp = fopen("patients.dat", "ab+"); 
    if (fp == NULL) {
        printf("File does not supported.\n");
        exit(1);
    }

    printf("Enter patient's name: ");
    scanf("%s", new_patient.name); 
    printf("Enter patient's age: ");
    scanf("%d", &new_patient.age);
    printf("Enter patient's address: ");
    scanf("%s", new_patient.address);
    printf("Enter patient's contact number: ");
    scanf("%s", new_patient.contact);
    printf("Enter patient's blood group: ");
    scanf("%s", new_patient.bloodgroup); 
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", new_patient.appointment_date);
     

    fwrite(&new_patient, sizeof(Patient), 1, fp);
    fclose(fp); 
    printf("Patient record added successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\nMedical and Channeling Center \n");
        printf("1. Add Patient Details\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                patient_record();
                break;
            case 2:
                printf("Thank you.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

