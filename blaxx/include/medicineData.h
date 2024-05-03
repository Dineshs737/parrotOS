#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#include"./Suggestion.h"
#include<time.h>
void medicalData();
// #include<ma
void MedicineUpdate();

struct DateInfo{
int day;
int month;
int year;

struct DateInfo* DatePtr;
};

typedef struct DateInfo Date;
struct medicineData{

char name[200];
char use[200];
char date[100];
char stock[128];
char price[200];
struct  medicineData* next;

};typedef struct medicineData medicine;

struct  DoctorSuggestionInfo{
    char Suggestion_id[100];
    char doctor_id[100];
    char Suggestion[2000];
    struct DoctorSuggestionInfo* next;

};

typedef struct DoctorSuggestionInfo Suggestion;
char* generate_id() {
    static char id_string[300];
    static char id_r[300]="R";
    time_t t;
    srand((unsigned) time(&t));
    int id = rand()-1;
    sprintf(id_string, "%d", id);
    strcat(id_r,id_string);
    return id_r;
}


void StoreMedicine();
void adminMedicine();
void MedicineUpdate();
void StoreSuggestion(char []);
void DoctorSuggestion(char []);
void  adminSuggestion();
void DoctorMedicine();


void AdminMedicineLogin(){ //admin Medcine menu
    int op;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
     printf("\n\t\t\t\t\t[1]. Show Doctor Suggestion\n");
     printf("\t\t\t\t\t[2]. Add new Medicine\n");
     printf("\t\t\t\t\t[3]. Display Medicine Detail\n");
     printf("\t\t\t\t\t[4]. Update Medicine Detail\n");
     printf("\t\t\t\t\t[5]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t\t    Eenter Your choice :");
    scanf("%d",&op);
    printf("\t\t\t _______________________________________________________\n");
   
    switch(op){
        case 1 :adminSuggestion(); break;
        case 2 :StoreMedicine();break;
        case 3 :adminMedicine();break;
       case 4 :MedicineUpdate();break;
        case 5 :exit(0);
    }
}

void MedicineDoctor(){ //doctor medicine menu

    int op;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
     printf("\n\t\t\t\t\t[1]. Create Suggestion\n");
     printf("\t\t\t\t\t[2]. Display Your Suggestion\n");
     printf("\t\t\t\t\t[3]. Display Medicine Detail\n");
     //printf("\t\t\t\t\t[4]. Update Medicine Detail\n");
     printf("\t\t\t\t\t[4]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t\t    Eenter Your choice :");
    scanf("%d",&op);
    printf("\t\t\t _______________________________________________________\n");
   
    switch(op){
        case 1 :StoreSuggestion("dinesh"); break;
       case 2 :DoctorSuggestion("dinsh");break;
       case 3 :DoctorMedicine();break;
        
        case 4 :exit(0);
    }


}


 void StoreMedicine(){ /// store medicine info
    medicine storeMedicine;
    char filename[20];
    int choice;
    int counter =1;
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\n\t\t\t                Create Medicine Detail               \n");
    printf("\n\t\t\t_______________________________________________________\n");
    while(1){
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    strcpy(filename,"./medicine/");
    printf("\n\n\t\t\t\t\tEnter Medicine Name :");
    scanf("%s",storeMedicine.name);
    printf("\n\t\t\t_______________________________________________________\n");
    strcat(filename,storeMedicine.name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeMedicineFilenames.txt","a")){
        fprintf(storefilename,"%s\n",filename); fclose(storefilename);
        
        }

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"%s\n",storeMedicine.name);
        printf("\t\t\t\t\tEnter use of medicine :");
        scanf("%s",storeMedicine.use);
        printf("\n\t\t\t_______________________________________________________\n");
       
        scanf("%[^\n]",storeMedicine.use);
         fprintf(file,"%s\n",storeMedicine.use);

        printf("\t\t\t\t\tEnter use of Experdate day :");
        scanf("%s",storeMedicine.date);
        printf("\n\t\t\t_______________________________________________________\n");
        scanf("%[^\n]",storeMedicine.date);
        fprintf(file,"%s\n",storeMedicine.date);

        printf("\t\t\t\t\tEnter stock count of the medicine :");
        scanf("%s",storeMedicine.stock);
        printf("\n\t\t\t_______________________________________________________\n");

        fprintf(file,"%s\n",storeMedicine.stock);

        printf("\t\t\t\t\tEnter price of the medicine :");
        scanf("%s",&storeMedicine.price);
        printf("\n\t\t\t_______________________________________________________\n");
        fprintf(file,"%s\n",storeMedicine.price);

       
        fclose(file);
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\n\t\t\t                Successfully Crated                    \n");
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    printf("\n\n\t\t\t\t[1]. Do you want to add another medicine\n");
    printf("\t\t\t\t[2]. Exit\n");
    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    printf("\n\t\t\t________________________________________________________\n");
    printf("\n\t\t\t\t\tChoice the options :");
    scanf("%d",&choice);
    
    printf("\n\t\t\t________________________________________________________\n");

    if(choice==2){ break;

    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    
    }
    if(choice>2 || choice <1){ 
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\n\t\t\t        You should Enter correct option                \n");
    printf("\n\t\t\t_______________________________________________________\n");
     
    }
    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    
    }
    }
  
   
    
    
AdminMedicineLogin();
}

 void adminMedicine(){// display medicine for admin
   FILE *f =NULL;
   f=fopen("storeMedicineFilenames.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
   }
  
   medicine tempMedicine;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information  start \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
         int lineCounter=1;
        char medicineInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            
            while(fgets(medicineInfo,sizeof(medicineInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempMedicine.name,medicineInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempMedicine.use,medicineInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempMedicine.date,medicineInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempMedicine.stock,medicineInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempMedicine.price,medicineInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;

                
                }
              printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tMedicine : %s\n",tempMedicine.name);
                printf("\t\t\t\t\tuse : %s\n",tempMedicine.use);
                printf("\t\t\t\t\tExpire Date : %s\n",tempMedicine.date);
                printf("\t\t\t\t\tStocks count : %s\n",tempMedicine.stock);
                printf("\t\t\t\t\tprice : %s\n",tempMedicine.price);

            }
            

            fclose(file);
        }
           printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");
           AdminMedicineLogin();

    }

void DoctorMedicine(){// display medicine for admin
   FILE *f =NULL;
   f=fopen("storeMedicineFilenames.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
   }
  
   medicine tempMedicine;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information  start \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
         int lineCounter=1;
        char medicineInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            
            while(fgets(medicineInfo,sizeof(medicineInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempMedicine.name,medicineInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempMedicine.use,medicineInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempMedicine.date,medicineInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempMedicine.stock,medicineInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempMedicine.price,medicineInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;

                
                }
              printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tMedicine : %s\n",tempMedicine.name);
                printf("\t\t\t\t\tuse : %s\n",tempMedicine.use);
                printf("\t\t\t\t\tExpire Date : %s\n",tempMedicine.date);
                printf("\t\t\t\t\tStocks count : %s\n",tempMedicine.stock);
                printf("\t\t\t\t\tprice : %s\n",tempMedicine.price);

            }
            

            fclose(file);
        }
           printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");
           MedicineDoctor();

    }



medicine MedicineDataSplit(char name[]){ //split medicine datas
   medicine tempMedicine;
  // medicine * tempMedicinePtr =&tempMedicine;
    char filename[20]="./medicine/";
    /*printf("Enter the medicine Name :");*/
    strcat(filename,name);
    strcat(filename,".txt");
    FILE * tempFile=NULL;
    char medicineInfo[1024];
    if(tempFile =fopen(filename,"r")){
    int lineCounter=1;

    while(fscanf(tempFile,"%s",medicineInfo) !=EOF){

                if(lineCounter==1){
               
                //strcpy(tempMedicine.name,medicineInfo);
                printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempMedicine.use,medicineInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempMedicine.date,medicineInfo);
            } 
                

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                    
               
                strcpy(tempMedicine.stock,medicineInfo);
                

                }
                if(lineCounter==5){
                strcpy(tempMedicine.price,medicineInfo);}
            
                
                //tempMedicine.stock;

                lineCounter++;
                }
           

           
        
        
       
    // printf("\n%s",tempMedicine.name);
    // printf("%s\n",tempMedicine.use);
    // printf("%s\n",tempMedicine.date);
    // printf("%s\n",tempMedicine.stock);
    // printf("%s\n",tempMedicine.price);
    return(tempMedicine);
    }
     fclose(tempFile);
}
    

    


void MedicineUpdate(){ //update medicien data
   
    int option;
    char name[20];
    char filename[30]="./medicine/";
    printf("\nEnter the medicine Name :");
    scanf("%s",name);
    medicine mediUpdate = MedicineDataSplit(name);
    strcat(filename,name);
    strcat(filename,".txt");
    
    if(strcmp(filename,name)){
   // printf("\n[1] .Change use of the medicine\n");
    printf("[1] .Change Stock count of the medicine\n");
    printf("[2] .Change Expire Date of The Medicine\n");
    printf("[3] .Change use of the medicine\n");
    printf("[4] .Change Price of the Medicine\n");

   
    do{
        printf("\nEnter the option :");
        scanf("%d",&option);
        if(option<0 || option >3){ printf("\nYou shoud Enter currect option\n");}
    }while(0>option && option>3);
 
   
  
    medicine tmp =mediUpdate;
    FILE *file =NULL;
    switch(option){
        
        case 1:
         printf("Enter stock count :");
        scanf("%s",mediUpdate.stock); //mediUpdate.stock =sprintf
         break;
        case 2:
        printf("\nEnter the  Expire Date :");
        scanf("%s",mediUpdate.date);
         break;
        case 3 :
        printf("\nEnter use of medicine :");
        scanf("%s",mediUpdate.use);
        //printf("%d",stock);
        break;
        case 4 :printf("Enter New price :");
        scanf("%s",mediUpdate.price);



    }

        if(remove(filename)==0){/*printf("hello");*/}
         if(file=fopen(filename,"w")){
         fprintf(file,"%s\n",name);
         fprintf(file,"%s\n",mediUpdate.use);
         fprintf(file,"%s\n",mediUpdate.date);
         fprintf(file,"%s\n",mediUpdate.stock);
         fprintf(file,"%s\n",mediUpdate.price);



         
     fclose(file);   
      AdminMedicineLogin();
    }
    }else{
         printf("\n\t\t________________________________________________________\n");
         printf("\t\t\t\tcan not Find the Medicine Name");
          printf("\n\t\t________________________________________________________\n");
        AdminMedicineLogin();
    }
   
    }

   
    
    



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void StoreSuggestion(char d_name[]){//store doctor Suggestion
    Suggestion newSuggestion;
    char filename[60];
    int choice;
    
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    while(1){
    int counter =1;
    strcpy(filename,"./Suggestion/");
    char* id = generate_id();
    strcpy(newSuggestion.Suggestion_id,id);
    strcat(filename,id);
    strcat(filename,".txt");
    strcpy(newSuggestion.doctor_id,d_name);
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeSuggestion.txt","a")){
        fprintf(storefilename,"%s\n",filename); fclose(storefilename);
        
        }

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
            fprintf(file,"%s\n",newSuggestion.Suggestion_id);
            fprintf(file,"%s\n",newSuggestion.doctor_id);
             printf("\t\t\tEnter Doctor medicine  Suggestion:");
            scanf("%s",newSuggestion.Suggestion);
             fprintf(file,"%s\n",newSuggestion.Suggestion);
        
       
        fclose(file);


    printf("\n\n\t\t\t[1]. Do you want to add another Suggestion\n");
    printf("\t\t\t[2]. Exit\n");

    printf("\n\t\t________________________________________________________\n");
    printf("\n\t\t\tChoice the options :");
    scanf("%d",&choice);
    printf("\n\t\t________________________________________________________\n");

    if(choice==2){ 
         MedicineDoctor(); 
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
     //MedicineDoctor();
   
    
    }
    if(choice>2 || choice <1){ 
    printf("\n\t\t\t________________________________________________________\n");
    printf("\n\t\t\t             You should Enter correct option            \n");
    printf("\n\t\t\t________________________________________________________\n");
     
    }
   printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    
    }

    }
  
   
    
  

}





void  adminSuggestion(){            //show Doctor Suggestion
FILE *f =NULL;
   f=fopen("./storeSuggestion.txt","r");
   if(f==NULL){
    printf("\n\t\t\t___________________________________________________________________________\n");
    printf("\n\t\t                   Doctor Didn't Suggest Medicine                           \n");
    printf("\n\t\t\t___________________________________________________________________________\n");
   }
   //int lineCounter=1;
   Suggestion tempSuggestio;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t               Doctor Suggestion                      \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
        int lineCounter=1;
        char SuggestionInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
            
            while(fgets(SuggestionInfo,sizeof(SuggestionInfo),file)){
               
            

               if(lineCounter==1){
                strcpy(tempSuggestio.Suggestion_id,SuggestionInfo);
                //printf("%s\n",medicineInfo);

               }

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempSuggestio.doctor_id,SuggestionInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempSuggestio.Suggestion,SuggestionInfo);
            } 
                

            

                lineCounter++;

                
                }
                fclose(file);

                printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tSuggestion ID : %s\n",tempSuggestio.Suggestion_id);
                printf("\t\t\t\t\tDoctor ID : %s\n",tempSuggestio.doctor_id);
                printf("\t\t\t\t\tSuggestion : %s\n",tempSuggestio.Suggestion);
                
                
          
            }
            

          
        
            printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Medicine Information Ended \n");
            printf("\t\t\t_______________________________________________________\n");
   
}}

void DoctorSuggestion(char d_name[]){ // show doctor Suggestions to doctor
FILE *f =NULL;
   f=fopen("./storeSuggestion.txt","r");
   if(f==NULL){
    printf("\n\t\t\t___________________________________________________________________________\n");
    printf("\n\t\t                    I Didn't Suggest Medicine                                 \n");
    printf("\n\t\t\t___________________________________________________________________________\n");
   }
   //int lineCounter=1;
   Suggestion tempSuggestio;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t                My Medicine Suggestions                   \n");
            printf("\t\t\t_______________________________________________________\n");
    while(fscanf(f,"%s",line)!=EOF){
        int lineCounter=1;
        char SuggestionInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){
           // printf("%s\n","hello");
        
            
           while(fgets(SuggestionInfo,sizeof(SuggestionInfo),file)){
               if(lineCounter==1){
               
                strcpy(tempSuggestio.Suggestion_id,SuggestionInfo);
                //printf("%s\n",medicineInfo);

                    } 

                

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
               
                strcpy(tempSuggestio.doctor_id,SuggestionInfo);
            }
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
               
                strcpy(tempSuggestio.Suggestion,SuggestionInfo);
            } 
                

            

                lineCounter++;

                
                } fclose(file);
                if(strcmp(d_name,tempSuggestio.doctor_id)){
                printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
                printf("\n\t\t\t\t\tSuggestion ID : %s\n",tempSuggestio.Suggestion_id);
               // printf("\t\t\t\t\tDoctor ID : %s\n",tempSuggestio.doctor_id);
                printf("\t\t\t\t\tSuggestion : %s\n",tempSuggestio.Suggestion);
                
                }
                

            }
            

           
        }
            printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t                  Suggestions  Ended                    \n");
            printf("\t\t\t_______________________________________________________\n");
           MedicineDoctor();
 }