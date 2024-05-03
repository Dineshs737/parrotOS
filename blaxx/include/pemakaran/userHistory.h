#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void HistoryDatas();
void userWriteHistory(char lines[]){
    
    //Suggestion storeSuggest;
    char filename[20]="./userHistory/";
    char user_Id[6];
   // printf("Enter Suggestio ID :");
    printf("Enter user id ");
    scanf("%s",user_Id);
   // scanf("%s",storeSuggest.Suggestion_id);
    strcat(filename,user_Id);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeUserHisory.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        

        fprintf(file,"%s\n",lines);

    

       
        fclose(file);
    }

}

void adminHistory(){

    char filename[1024];
    FILE *file=NULL;
    
    if(file =fopen("./storeUserHisory.txt","r")){
        int userCount=1;
        while(fscanf(file,"%s",filename) !=EOF){
           // printf("%s\n",fileName);
           FILE * tempFile=NULL;
        char medicineInfo[1024];
        if(tempFile =fopen(filename,"r")){
        
        printf("\n======= ++++ ====== THIS is user[%d] History Start ======= ++++ ======\n",userCount);
         while(fgets(medicineInfo,sizeof(medicineInfo),tempFile)){
            printf("%s",medicineInfo);}
           



        }
        printf("\n======== ++++ ====== THIS is user[%d] History End ======= ++++ =======\n",userCount);
        
        userCount++;
    }
    }




}

void petientHistoryUsingId(char user_Id[]){
    char filename[20]="./userHistory/";
    

    strcat(filename,user_Id);
    strcat(filename,".txt");
    FILE * check=NULL;
    if(check =fopen(filename,"r")){
        char lines[2048];
        printf("\n\t\t\t== == == == == == THIS is user ID[ %s ] History Start == == == == == ==\n",user_Id);
        while(fgets(lines,sizeof(lines),check)){
            printf("\t\t\t\t\t%s",lines);
        }
         printf("\n\t\t\t== == == == == == ++++ History Have Ended  ++++ ======= ++++ ===========\n");
   } else{ printf("\n\t\tCoudnt't find the patient ID \"You shoud  Enter correct patient ID \" \n");
           HistoryDatas();}
    }
       
    


void HistoryDatas(){
    int option;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    printf("\n\t\t\t[1]. Do you want to see all  patient history\n");
    printf("\t\t\t[2]. Do need to search patient history\n");
    printf("\t\t\t[3]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\n\t\t\tEnter option :"); scanf("%d",&option);

    switch(option){
        case 1 :adminHistory(); break;
        case 2 :
            char user_Id[6];
             printf("\t\t\tEnter user id ");
             scanf("%s",user_Id);
             petientHistoryUsingId(user_Id);
             break;
        case 3 :exit(0);
    }

    
}
