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
    char record_id[300];
    char patient_id[50];
    char doctor_id[50];
    char diagnosis[100];
    char prescription[100];
    struct TreatmentRecord *next;
} ;
typedef struct TreatmentRecord Treartment;
Treartment *head=NULL;
int count =0;
 

 //====+====+ copy the code from  lib.h =====+=====+=====

void StoreTreartment(char p_name[],char d_name[]){
    Treartment storeTreat;
    char filename[256]="./Treartment/";
    
    strcat(filename,p_name);
    strcat(filename,d_name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeTreartment.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
       
        strcat(storeTreat.record_id,p_name);
        strcat(storeTreat.record_id,d_name);
          fprintf(file,"TreartmentID is:%s\n",storeTreat.record_id);
          strcpy(storeTreat.doctor_id,d_name);
          fprintf(file,"DoctorID is:%s\n",storeTreat.doctor_id);
        strcpy(storeTreat.patient_id,p_name);
        
       fprintf(file,"PecintID is:%s\n",storeTreat.patient_id);
        
        
       
        printf("Enter the Enter Diagnosis:");
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
    

    void petientHistoryUsingName(char user_Id[]){
    char filename[20]="./Treartment/";
    

    strcat(filename,user_Id);
    strcat(filename,".txt");
    FILE * check=NULL;
    if(check =fopen(filename,"r")){
        char lines[2048];
        printf("\n\t\t\t======= ++++ ====== Your Treartment History ======= ++++ ======\n");
        while(fgets(lines,sizeof(lines),check)){
            printf("\t\t\t\t\t%s",lines);
        }
         printf("\n\t\t\t=========== ++++ ====== ++++ /t  ++++ ======= ++++ ===========\n");
   } 
   else{
    printf("\n \t\t=========== ++++ ========== You didm't go to TreartMent =========== ++++ ============\n");
   }
    }



// //////////////////////////////////////////////////////////////

Treartment TreartmentDataSplit(){
  Treartment  tempTreartment;
  // medicine * tempMedicinePtr =&tempMedicine;
    char filename[20]="./Treartment/";
    /*printf("Enter the medicine Name :");*/
    
    FILE *f=NULL;
    if(f=fopen("./storeTreartment.txt","r")){

    char line[1024];
    while(fscanf(f,"%s",line)!=EOF){
    char line[1024];

    
   
    FILE * tempFile=NULL;
    char TreartmentInfo[1024];
    if(tempFile =fopen(line,"r")){
    int lineCounter=1;

    while(fgets(TreartmentInfo,sizeof(TreartmentInfo),tempFile)){

                if(lineCounter==1){
                int n=0;
                char * datas=strtok(TreartmentInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempTreartment.record_id,datas);
            } datas =strtok(NULL,":");
            n++; }

                }

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
                int n=0;
                char * datas=strtok(TreartmentInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempTreartment.doctor_id,datas);
            } datas =strtok(NULL,":");
               n++; 
            }}
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
                int n=0;
                char * datas=strtok(TreartmentInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempTreartment.patient_id,datas);
            } datas =strtok(NULL,":");
               n++; 
            }
                }

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                     // printf("%s",medicineInfo);
                    int n=0;
                char * datas=strtok(TreartmentInfo,":");
           
                while(datas !=NULL){
                if(n==1){
                strcpy(tempTreartment.diagnosis,datas);
               // tempMedicine.stock = atoi(datas);
               //printf("%s",datas);
            } datas =strtok(NULL,":");
               n++; 
            }

                }
                if(lineCounter==5){

                    int n=0;
                char * datas=strtok(TreartmentInfo,":");
           
                while(datas !=NULL){
                if(n==1){
                strcpy(tempTreartment.prescription,datas);
              
            } datas =strtok(NULL,":");
               n++; 
                }
                
                
                //tempMedicine.stock;

                lineCounter++;
                }
           
    }
            fclose(tempFile);
        
    }
       
    return(tempTreartment);

    }
    // printf("%s",tempMedicine.name);
    // printf("\n%s",tempMedicine.use);
    // printf("\n%s",tempMedicine.date);
    // printf("%d",tempMedicine.stock);
    

    


    }
}
void dispalyPatien(char user_id[]){
    Treartment temp = TreartmentDataSplit();
}