#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[100];
    char specialty[50];
    char available_days[10];
    char contact[15];
} Doctor;


void doctor_record() {
    Doctor new_doctor;
    FILE *fp = fopen("doctors.dat", "ab+"); 

    if (fp == NULL) {
        printf("File does not created.\n");
        exit(1);
    }

    printf("Enter doctor's name: ");
    scanf("%s", new_doctor.name);
    printf("Enter doctor's specialty: ");
    scanf("%s", new_doctor.specialty);
    printf("Enter doctor's available days (e.g. Mon,Tue): ");
    scanf("%s", new_doctor.available_days);
    printf("Enter doctor's contact number: ");
    scanf("%s", new_doctor.contact);

    fwrite(&new_doctor, sizeof(Doctor), 1, fp); 
    fclose(fp); 
    printf("Doctor record added successfully.\n");
}


int main() {
    int choice;

    do {
        printf("\nMedical and Channeling Center \n");
        printf("1. Add Doctor Details\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                doctor_record();
                break;
            case 2:
                printf("Thank you.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}


