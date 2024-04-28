#include <stdio.h>

#define MAX_MEDICINE 100
#define MAX_DOCTORS 10


typedef struct {
    char name[50];
    float price;
    int quantity;
} Medicine;


typedef struct {
    char name[50];
    float fee;
} Doctor;

int i;
float calculateMedicineCost(Medicine meds[], int numMeds) {
    float totalCost = 0.0;
    for ( i = 0; i < numMeds; i++) {
        totalCost += meds[i].price * meds[i].quantity;
    }
    return totalCost;
}


float calculateDoctorFee(Doctor doctors[], int numDoctors) {
    float totalFee = 0.0;
    for ( i = 0; i < numDoctors; i++) {
        totalFee += doctors[i].fee;
    }
    return totalFee;
}

int main() {
    Medicine medicines[MAX_MEDICINE];
    Doctor doctors[MAX_DOCTORS];
    int numMedicines, numDoctors;

    printf("Enter the number of medicines: ");
    scanf("%d", &numMedicines);

    
    for ( i = 0; i < numMedicines; i++) {
        printf("Enter name of medicine %d: ", i + 1);
        scanf("%s", medicines[i].name);
        printf("Enter price of medicine %d: ", i + 1);
        scanf("%f", &medicines[i].price);
        printf("Enter quantity of medicine %d: ", i + 1);
        scanf("%d", &medicines[i].quantity);
    }

    printf("Enter the number of doctors: ");
    scanf("%d", &numDoctors);

    for ( i = 0; i < numDoctors; i++) {
        printf("Enter name of doctor %d: ", i + 1);
        scanf("%s", doctors[i].name);
        printf("Enter fee of doctor %d: ", i + 1);
        scanf("%f", &doctors[i].fee);
    }

    
    float totalMedicineCost = calculateMedicineCost(medicines, numMedicines);
    float totalDoctorFee = calculateDoctorFee(doctors, numDoctors);
    float totalCost = totalMedicineCost + totalDoctorFee;

    printf("\nTotal Medicine Cost: Rs.%f\n", totalMedicineCost);
    printf("Total Doctor Fee: Rs.%f\n", totalDoctorFee);
    printf("Total Cost: Rs.%f\n", totalCost);

    return 0;
}

