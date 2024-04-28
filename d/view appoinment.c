#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date dob;
    char gender[10];
    char address[100];
    char contact[15];
} Patient;

typedef struct {
    char name[50];
    char specialization[50];
} Doctor;

typedef struct {
    Patient patient;
    Doctor doctor;
    Date date;
    char diagnosis[100];
} Appointment;

// Function prototypes
void addPatient(Patient *patients, int *numPatients);
void scheduleAppointment(Appointment *appointments, int *numAppointments, Patient *patients, Doctor *doctors, int numPatients, int numDoctors);
void viewPatientHistory(Appointment *appointments, int numAppointments);

int main() {
    Patient patients[100];
    Doctor doctors[10]; // Assuming there are 10 doctors in the center
    Appointment appointments[100];
    int numPatients = 0;
    int numDoctors = 0;
    int numAppointments = 0;

    int choice;
    do {
        printf("\nMedical and Channeling Center\n");
        printf("1. Add Patient\n");
        printf("2. Schedule Appointment\n");
        printf("3. View Patient History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &numPatients);
                break;
            case 2:
                scheduleAppointment(appointments, &numAppointments, patients, doctors, numPatients, numDoctors);
                break;
            case 3:
                viewPatientHistory(appointments, numAppointments);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addPatient(Patient *patients, int *numPatients) {
    if (*numPatients >= 100) {
        printf("Patient database is full. Cannot add more patients.\n");
        return;
    }

    printf("Enter patient details:\n");
    printf("Name: ");
    scanf(" %[^\n]", patients[*numPatients].name);
    printf("Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &patients[*numPatients].dob.day, &patients[*numPatients].dob.month, &patients[*numPatients].dob.year);
    printf("Gender: ");
    scanf(" %[^\n]", patients[*numPatients].gender);
    printf("Address: ");
    scanf(" %[^\n]", patients[*numPatients].address);
    printf("Contact Number: ");
    scanf(" %[^\n]", patients[*numPatients].contact);

    (*numPatients)++;
    printf("Patient added successfully.\n");
}

void scheduleAppointment(Appointment *appointments, int *numAppointments, Patient *patients, Doctor *doctors, int numPatients, int numDoctors) {
    if (*numAppointments >= 100) {
        printf("Appointment database is full. Cannot schedule more appointments.\n");
        return;
    }

    printf("Enter appointment details:\n");
    printf("Patient Name: ");
    char patientName[50];
    scanf(" %[^\n]", patientName);

    // Search for patient
    int patientIndex = -1;
    int i;
    for ( i = 0; i < numPatients; i++) {
        if (strcmp(patients[i].name, patientName) == 0) {
            patientIndex = i;
            break;
        }
    }

    if (patientIndex == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("Doctor Name: ");
    char doctorName[50];
    scanf(" %[^\n]", doctorName);

    // Search for doctor
    int doctorIndex = -1;
    
    for ( i = 0; i < numDoctors; i++) {
        if (strcmp(doctors[i].name, doctorName) == 0) {
            doctorIndex = i;
            break;
        }
    }

    if (doctorIndex == -1) {
        printf("Doctor not found.\n");
        return;
    }

    printf("Appointment Date (DD MM YYYY): ");
    scanf("%d %d %d", &appointments[*numAppointments].date.day, &appointments[*numAppointments].date.month, &appointments[*numAppointments].date.year);
    printf("Diagnosis (if known): ");
    scanf(" %[^\n]", appointments[*numAppointments].diagnosis);

    // Assign patient and doctor to appointment
    strcpy(appointments[*numAppointments].patient.name, patients[patientIndex].name);
    strcpy(appointments[*numAppointments].doctor.name, doctors[doctorIndex].name);

    (*numAppointments)++;
    printf("Appointment scheduled successfully.\n");
}

void viewPatientHistory(Appointment *appointments, int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled yet.\n");
        return;
    }

    printf("Patient History:\n");
    int i;
    for (i = 0; i < numAppointments; i++) {
        printf("Appointment %d:\n", i+1);
        printf("Date: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
        printf("Doctor: %s\n", appointments[i].doctor.name);
        printf("Diagnosis: %s\n", appointments[i].diagnosis);
        printf("\n");
    }
}

