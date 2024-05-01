#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct petientInfo{
    char name[30];
    char id[6];
    int Nic_No;
    char address[100];
    char BloodGroup[3];


    struct petientInfo* pectentPtr;

};

typedef struct petientInfo Petient;

struct doctorInfo{
    char name[30];
    char id[6];
    char spealist[60];
    char address[100];

};



typedef struct doctorInfo Doctor;

typedef struct {
    int id;
    int doctor_ID;
    char patientName[100];
    char date[11]; 
    char time[6]; 
} Appointment;


struct TreatmentRecord {
    char record_id[6];
    char patient_id[6];
    char doctor_id[6];
    char diagnosis[100];
    char prescription[100];
    struct TreatmentRecord *next;
} ;
typedef struct TreatmentRecord Treartment;
Treartment *head=NULL;
int count =0;
 

 //====+====+ copy the code from  lib.h =====+=====+=====





 void insertAtBeginning(Treartment *treartmentInput){

    
    Treartment* newTreatment =(Treartment*)malloc(sizeof(Treartment));
    if(newTreatment==NULL) printf("out of memory");
    printf("\n\ncreated newMedicine \n\n");
   /*strcpy(newTreatment->record_id , treartmentInput->record_id);
    strcpy(newTreatment->doctor_id , treartmentInput->doctor_id);
    strcpy(newTreatment->patient_id, treartmentInput->patient_id);*/
    // newTreatment->record_id = treartmentInput->record_id;
    // newTreatment->doctor_id = treartmentInput->doctor_id;
    // newTreatment->patient_id = treartmentInput->patient_id;

    strcpy(newTreatment->diagnosis, treartmentInput->diagnosis);
    strcpy(newTreatment->prescription, treartmentInput->prescription);
   


    if(head==NULL){
      newTreatment->next =NULL;
        head =newTreatment;
    }
    else{
        newTreatment ->next =head;
        head =newTreatment;

   

    }



 }

 void  instertPosition(Treartment *treartmentInput,int pos){

    printf("\nRecord ID: %s\n", treartmentInput->record_id);
       
    //printf("%d",pos);
    count +=(pos+1);
    if(pos==0){
        insertAtBeginning(treartmentInput);
    }

        
    int i=1;
   Treartment* newTreatment =(Treartment*)malloc(sizeof(Treartment));
    if(newTreatment==NULL) printf("out of memory");



    strcpy(newTreatment->diagnosis, treartmentInput->diagnosis);
    strcpy(newTreatment->prescription, treartmentInput->prescription);
    Treartment *temp =head;
    for(i=1;i<=pos-1;i++){
        temp= temp->next;
        if(temp==NULL){
            printf("Invalid position lsat \n");
            return;
        }
    }
    
    newTreatment->next =temp->next;
    temp->next = newTreatment;
       
}


void StoreTreartment(){
    Treartment storeTreat;
    char filename[20]="./Treartment/";
    printf("Enter Suggestio ID :");
    scanf("%s",storeTreat.record_id);
    strcat(filename,storeTreat.record_id);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeTreartment.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"Suggestion ID is : %s\n",storeTreat.record_id);
        fprintf(file,"Doctor ID is : %s\n","00001");
        fprintf(file,"Pecint ID is : %s\n","00000");
        printf("Enter the Enter Diagnosis :");
        scanf("%s",storeTreat.diagnosis);
        scanf("%[^\n]",storeTreat.diagnosis);
        scanf("%[^\n]",storeTreat.diagnosis);
        fprintf(file,"prescription : %s\n",storeTreat.diagnosis);
        printf("Enter the Enter Prescription :");
        scanf("%s",storeTreat.prescription);
        scanf("%[^\n]",storeTreat.prescription);

        fprintf(file,"prescription : %s\n",storeTreat.prescription);

       
        fclose(file);
    }

}

 void fileLoadUpTreartment(){
   FILE *f =NULL;
   f=fopen("./storeTreartment.txt","r");
   if(f==NULL){
        printf("\n!!!!!!!! ========= Didn't add medicine ========= !!!!!!!!!\n");
   }
   
    char line[1024];
    while(fscanf(f,"%s",line)!=EOF){
        char TreartmentInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){

            while(fgets(TreartmentInfo,sizeof(TreartmentInfo),file)){
                printf("%s",TreartmentInfo);
                printf("\n");
            }
            printf("\n");

            fclose(file);
        }


    }
   }
    