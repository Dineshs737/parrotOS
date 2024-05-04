#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void HistoryDatas();
void Doctorpatient();
void Historypatient();
void petientWriteHistory(char [],char []);
void DoctorWriteHistory(char [],char []);
void PetientAllHistory();
void Historypatient();
void Doctorpatient();


void AdminHistory(){ //admin Medcine menu
    int op;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
     printf("\n\t\t\t\t\t[1]. Show patient History\n");
     printf("\t\t\t\t\t[2]. Show Doctor History\n");
     printf("\t\t\t\t\t[3]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t\t    Eenter Your choice :");
    scanf("%d",&op);
    printf("\t\t\t _______________________________________________________\n");
   
    switch(op){
        case 1 :Historypatient(); break;
        case 2 :Doctorpatient();break;
        case 3 :exit(0);
    }
}




void petientWriteHistory(char lines[],char Name[]){//petient history write function
    
    //Suggestion storeSuggest;
    char filename[20]="./PetientHistory/";
    
   // printf("Enter Suggestio ID :");
  
   // scanf("%s",storeSuggest.Suggestion_id);
    strcat(filename,Name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storePetientHisory.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        

        fprintf(file,"%s\n",lines);

    

       
        fclose(file);
    }

}

void DoctorWriteHistory(char lines[],char Name[]){//petient history write function
    
    //Suggestion storeSuggest;
    char filename[20]="./DoctorHistory/";
    
   // printf("Enter Suggestio ID :");
  
   // scanf("%s",storeSuggest.Suggestion_id);
    strcat(filename,Name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeDoctorHisory.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        

        fprintf(file,"%s\n",lines);

    

       
        fclose(file);
    }

}


void PetientAllHistory(){

    char filename[1024];
    FILE *file=NULL;
    
    if(file =fopen("./storePetientHisory.txt","r")){
        int userCount=1;
        while(fscanf(file,"%s",filename) !=EOF){
           // printf("%s\n",fileName);
           FILE * tempFile=NULL;
        char medicineInfo[1024];
        if(tempFile =fopen(filename,"r")){
        
        printf("\n\t\t\t\t== == ==  == == == THIS is user[%d] History Start == == == == == ==\n",userCount);
         while(fgets(medicineInfo,sizeof(medicineInfo),tempFile)){
            printf("\t\t\t\t\t\t\t%s",medicineInfo);}
           



        }
        printf("\n\t\t\t\t== == ==  == == == THIS is user[%d] History End == == == == == ==\n",userCount);
        
        userCount++;
    }
    }else{
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\t\t\t\t         Didn't find user history\n");
    printf("\n\t\t\t_______________________________________________________\n");

    }


 Historypatient();
}

void DoctortAllHistory(){

    char filename[1024];
    FILE *file=NULL;
    
    if(file =fopen("./storeDoctorHisory.txt","r")){
        int userCount=1;
        while(fscanf(file,"%s",filename) !=EOF){
           // printf("%s\n",fileName);
           FILE * tempFile=NULL;
        char medicineInfo[1024];
        if(tempFile =fopen(filename,"r")){
        
        printf("\n== == == == == == THIS is Doctor [%d] History Start == == == == == ==\n",userCount);
         while(fgets(medicineInfo,sizeof(medicineInfo),tempFile)){
            printf("%s",medicineInfo);}
           



        }
        printf("\n== == == == == == THIS is Doctor [%d] History Ended == == == == == ==\n",userCount);
        
        userCount++;
    }//if(fscanf(file,"%s",filename) ==EOF );
    }else{
    printf("\n\t\t\t_______________________________________________________\n");
    printf("\t\t\t\t      Didn't find user history\n");
    printf("\n\t\t\t_______________________________________________________\n");
    }


Doctorpatient();
}

void petientHistoryUsingId(char user_Id[]){
    char filename[20]="./userHistory/";
    

    strcat(filename,user_Id);
    strcat(filename,".txt");
    FILE * check=NULL;
    if(check =fopen(filename,"r")){
        char lines[2048];
        printf("\n\t\t\t== == == == == == THIS is Pertient Name [ %s ] History Start == == == == == ==\n",user_Id);
        while(fgets(lines,sizeof(lines),check)){
            printf("\t\t\t\t\t%s",lines);
        }
         printf("\n\t\t\t== == == == == ==  History Have Ended  == == == == == ==\n");
   } else{ 
    printf("\n\t\t\t___________________________________________________________________________\n");
    printf("\n\t\tCoudnt't find the patient Name \"You shoud  Enter correct patient Name \" \n");
    printf("\n\t\t\t___________________________________________________________________________\n");
        }
          Historypatient();
    }
       
    

void DoctorHistoryUsingId(char user_Id[]){
    char filename[20]="./DoctorHistory/";
    

    strcat(filename,user_Id);
    strcat(filename,".txt");
    FILE * check=NULL;
    if(check =fopen(filename,"r")){
        char lines[2048];
        printf("\n\t\t\t== == == == == == THIS is  Doctor Name [ %s ] History Start == == == == == ==\n",user_Id);
        while(fgets(lines,sizeof(lines),check)){
            printf("\t\t\t\t\t%s",lines);
        }
         printf("\n\t\t\t== == == == == ==  History Have Ended   == == == == == ==\n");
   } else{
     printf("\n\t\t\t___________________________________________________________________________\n");
     printf("\n\t\tCoudnt't find the Doctor Name \"You shoud  Enter correct Doctor Name \" \n");
     printf("\n\t\t\t___________________________________________________________________________\n");
          }
           Doctorpatient();
    }
       


void Historypatient(){
    int option;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    printf("\n\t\t\t[1]. Do you want to see all  patient history\n");
    printf("\t\t\t[2]. Do need to search patient history\n");
    printf("\t\t\t[3]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\n\t\t\tEnter option :"); scanf("%d",&option);

    switch(option){
        case 1 :PetientAllHistory(); break;
        case 2 :
            char user_Id[6];
             printf("\t\t\tEnter patient Name :");
             scanf("%s",user_Id);
             petientHistoryUsingId(user_Id);
             break;
        case 3 :AdminHistory();
    }

    
}



void Doctorpatient(){
    int option;
    printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    printf("\n\t\t\t[1]. Do you want to see all Doctor history\n");
    printf("\t\t\t[2]. Do need to search Doctor history\n");
    printf("\t\t\t[3]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\n\t\t\tEnter option :"); scanf("%d",&option);

    switch(option){
        case 1 : DoctortAllHistory(); break;
        case 2 :
            char user_Id[6];
             printf("\t\t\tEnter Enter Doctor Name ");
             scanf("%s",user_Id);
             DoctorHistoryUsingId(user_Id);
             break;
        case 3 :AdminHistory();
    }

    
}
