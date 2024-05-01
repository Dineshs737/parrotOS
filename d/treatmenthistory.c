#include <stdio.h>
#include <string.h>

#define MAX_DOCTORS 50
#define MAX_PATIENTS 100
#define MAX_RECORDS 500


struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};


struct Patient {
    int id;
    char name[50];
    int age;
    char gender;
};

struct TreatmentRecord {
    int record_id;
    int patient_id;
    int doctor_id;
    char diagnosis[100];
    char prescription[100];
} ;
typedef struct TreatmentRecord Treartment;

struct Doctor doctors[MAX_DOCTORS];
struct Patient patients[MAX_PATIENTS];
struct TreatmentRecord records[MAX_RECORDS];

int doctorCount = 0;
int patientCount = 0;
int recordCount = 0;


void addDoctor() {
    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);
    printf("Enter Doctor Name: ");
    scanf("%s", doctors[doctorCount].name);
    printf("Enter Doctor Specialization: ");
    scanf("%s", doctors[doctorCount].specialization);
    doctorCount++;
}


void addPatient() {
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    printf("Enter Patient Name: ");
    scanf("%s", patients[patientCount].name);
    printf("Enter Patient Age: ");
    scanf("%d", &patients[patientCount].age);
    printf("Enter Patient Gender (M/F): ");
    scanf(" %c", &patients[patientCount].gender);
    patientCount++;
}


void addTreatmentRecord() {
    printf("Enter Record ID: ");
    scanf("%d", &records[recordCount].record_id);
    printf("Enter Patient ID: ");
    scanf("%d", &records[recordCount].patient_id);
    printf("Enter Doctor ID: ");
    scanf("%d", &records[recordCount].doctor_id);
    printf("Enter Diagnosis: ");
    scanf("%s", records[recordCount].diagnosis);
    printf("Enter Prescription: ");
    scanf("%s", records[recordCount].prescription);
    recordCount++;
}


void displayDoctors() {
    printf("\nDoctors Details\n");
    int i;
    for (i = 0; i < doctorCount; i++) {
        printf("ID: %d, Name: %s, Specialization: %s\n", doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
}


void displayPatients() {
    printf("\nPatients Details\n");
    int i;
    for ( i = 0; i < patientCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %c\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender);
    }
}


void displayRecords() {
    printf("\nTreatment Records\n");
    int i;
    for (i = 0; i < recordCount; i++) {
        printf("Record ID: %d\n Patient ID: %d\nDoctor ID: %d\n Diagnosis: %s\n Prescription: %s\n", 
               records[i].record_id, records[i].patient_id, records[i].doctor_id, records[i].diagnosis, records[i].prescription);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Doctor Details\n");
        printf("2. Add Patient Details\n");
        printf("3. Add Treatment Record\n");
        printf("4. Display Doctor Deatils\n");
        printf("5. Display Patients Details\n");
        printf("6. Display Treatment Records\n");
        printf("7. Ending the session \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addDoctor();
                break;
            case 2:
                addPatient();
                break;
            case 3:
                addTreatmentRecord();
                break;
            case 4:
                displayDoctors();
                break;
            case 5:
                displayPatients();
                break;
            case 6:
                displayRecords();
                break;
            case 7:
                printf("Thank you\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

