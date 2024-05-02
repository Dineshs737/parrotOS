struct TreatmentRecord {
    char record_id[6];
    char patient_id[6];
    char doctor_id[6];
    char diagnosis[100];
    char prescription[100];
    struct TreatmentRecord *next;
} ;
typedef struct TreatmentRecord Treartment;