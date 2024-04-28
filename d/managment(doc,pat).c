
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Doctor {
    int id;
    char name[100];
    char specialty[100];
};


struct Patient {
    int id;
    char name[100];
    int age;
    char ailment[100];
};


void addDoctor(struct Doctor doctors[], int *docCount);
void addPatient(struct Patient patients[], int *patCount);
void printDoctors(struct Doctor doctors[], int docCount);
void printPatients(struct Patient patients[], int patCount);

int main() {
    struct Doctor doctors[100]; 
    struct Patient patients[100]; 
    int docCount = 0, patCount = 0; 

    int choice;

    while(1) {
        printf("1. Add Doctor\n");
        printf("2. Add Patient\n");
        printf("3. Print Doctors\n");
        printf("4. Print Patients\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addDoctor(doctors, &docCount);
                break;
            case 2:
                addPatient(patients, &patCount);
                break;
            case 3:
                printDoctors(doctors, docCount);
                break;
            case 4:
                printPatients(patients, patCount);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void addDoctor(struct Doctor doctors[], int *docCount) {
    printf("Enter doctor ID: ");
    scanf("%d", &doctors[*docCount].id);
    printf("Enter doctor name: ");
    scanf("%s", doctors[*docCount].name);
    printf("Enter specialty: ");
    scanf("%s", doctors[*docCount].specialty);
    (*docCount)++;
}


void addPatient(struct Patient patients[], int *patCount) {
    printf("Enter patient ID: ");
    scanf("%d", &patients[*patCount].id);
    printf("Enter patient name: ");
    scanf("%s", patients[*patCount].name);
    printf("Enter age: ");
    scanf("%d", &patients[*patCount].age);
    printf("Enter ailment: ");
    scanf("%s", patients[*patCount].ailment);
    (*patCount)++;
}

int i;
void printDoctors(struct Doctor doctors[], int docCount) {
    printf("List of Doctors:\n");
    for( i = 0; i < docCount; i++) {
        printf("ID: %d, Name: %s, Specialty: %s\n", doctors[i].id, doctors[i].name, doctors[i].specialty);
    }
}


void printPatients(struct Patient patients[], int patCount) {
    printf("List of Patients:\n");
    for( i = 0; i < patCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Ailment: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].ailment);
    }
}





