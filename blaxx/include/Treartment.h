#include<stdio.h>
#include<string.h>
#include<time.h>


struct TreatmentRecord {
    char record_id[400];
    char patient_id[100];
    char doctor_id[100];
    char diagnosis[100];
    char prescription[100];
    struct TreatmentRecord *next;
} ;
typedef struct TreatmentRecord Treartment;

char* generate_Tid() {
    static char id_string[20];
    static char id_r[21]="T";
    time_t t;
    srand((unsigned) time(&t));
    int id = rand();
    sprintf(id_string, "%5d", id);
    strcat(id_r,id_string);
    return id_r;
}

 //====+====+ copy the code from  lib.h =====+=====+=====

void StoreTreartment(char d_name[] ,char p_name[]){
    Treartment newTreartment;
    char filename[60]="./Treartment/";
    int choice;
    int counter =1;
    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    
    
    char* id =  generate_Tid();
    strcpy(newTreartment.record_id,id);
    strcat(filename,id);
    strcat(filename,".txt");
    strcpy(newTreartment.doctor_id,d_name);
    strcpy(newTreartment.patient_id,p_name);
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeTreartment.txt","a")){
       // printf("hello");
        fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"%s\n",newTreartment.record_id);
        fprintf(file,"%s\n",newTreartment.doctor_id);
        fprintf(file,"%s\n",newTreartment.patient_id);
        printf("Enter the Enter Diagnosis :");
        scanf("%s",newTreartment.diagnosis);
        //scanf("%[^\n]",newTreartment.diagnosis);
        //scanf("%[^\n]",storeTreat.diagnosis);
        fprintf(file,"%s\n",newTreartment.diagnosis);
        printf("Enter the Enter Prescription :");
        scanf("%s",newTreartment.prescription);
        //scanf("%[^\n]",newTreartment.prescription);

        fprintf(file,"%s\n",newTreartment.prescription);

       
        fclose(file);
    }

    }

 

void adminTreartment(){

FILE *f =NULL;
   f=fopen("storeTreartment.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
   }
  
   Treartment tempTreartment;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t             ALL Treartment History                       \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
         int lineCounter=1;
        char TreartmentInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            printf("%s\n",line);
            
           while(fgets(TreartmentInfo,sizeof(TreartmentInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempTreartment.record_id,TreartmentInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempTreartment.doctor_id,TreartmentInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempTreartment.patient_id,TreartmentInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempTreartment.diagnosis,TreartmentInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempTreartment.prescription,TreartmentInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;

                
                }
                 fclose(file);
                printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tTreartment ID : %s\n",tempTreartment.record_id);
                printf("\t\t\t\t\tDoctor ID : %s\n",tempTreartment.doctor_id);
                printf("\t\t\t\t\tPatient ID : %s\n",tempTreartment.patient_id);
                printf("\t\t\t\t\tDiagnosis : %s\n",tempTreartment.diagnosis);
                printf("\t\t\t\t\tprescription : %s\n",tempTreartment.prescription);
                

            }
            

         
        }
         fclose(f); 
           printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");



}

void DoctorTreartment(char d_name[]){

    FILE *f =NULL;
   ;
   if(f=fopen("storeTreartment.txt","r")){
        
   
   //int lineCounter=1;
   Treartment tempTreartment;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              MY Treartment History                       \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
        int lineCounter=1;
        char TreartmentInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            
            while(fgets(TreartmentInfo,sizeof(TreartmentInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempTreartment.record_id,TreartmentInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempTreartment.doctor_id,TreartmentInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempTreartment.patient_id,TreartmentInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempTreartment.diagnosis,TreartmentInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempTreartment.prescription,TreartmentInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;

                
                }
                //printf("%s\n",tempTreartment.patient_id);
                //printf("%s\n",p_name);
                if(strcmp(d_name,tempTreartment.doctor_id)){

                printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tTreartment ID : %s\n",tempTreartment.record_id);
               // printf("\t\t\t\t\tDoctor ID : %s\n",tempTreartment.doctor_id);
                printf("\t\t\t\t\tPatient ID : %s\n",tempTreartment.patient_id);
                printf("\t\t\t\t\tDiagnosis : %s\n",tempTreartment.diagnosis);
                printf("\t\t\t\t\tprescription : %s\n",tempTreartment.prescription);
                }
                //printf("hello");

                } fclose(file);
                
               
                
            }
            
            }printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");

            }
            

           
        
           



 

// }


void patientTreartment(char p_name[]){

 FILE *f =NULL;
   f=fopen("storeTreartment.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
   }
   //int lineCounter=1;
   Treartment tempTreartment;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t             MY Treartment History                       \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
        int lineCounter=1;
        char TreartmentInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            
            while(fgets(TreartmentInfo,sizeof(TreartmentInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempTreartment.record_id,TreartmentInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempTreartment.doctor_id,TreartmentInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempTreartment.patient_id,TreartmentInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempTreartment.diagnosis,TreartmentInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempTreartment.prescription,TreartmentInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;

                
                }
               
                if(strcmp(p_name,tempTreartment.doctor_id)){
                printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
               // printf("\n\t\t\t\t\tTreartment ID : %s\n",tempTreartment.record_id);
                 printf("\t\t\t\t\tDoctor ID : %s\n",tempTreartment.doctor_id);
               // printf("\t\t\t\t\tPatient ID : %s\n",tempTreartment.patient_id);
                printf("\t\t\t\t\tDiagnosis : %s\n",tempTreartment.diagnosis);
                printf("\t\t\t\t\tprescription : %s\n",tempTreartment.prescription);
                }
               // printf("hello");

                }
                
               
                 fclose(file);
            }
            

           
        
           printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");


}

 






    