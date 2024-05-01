#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct  DoctorSuggestionInfo{
    char Suggestion_id[6];
    char doctor_id[6];
    char Suggestion[2000];
    struct DoctorSuggestionInfo* next;

};
typedef struct DoctorSuggestionInfo Suggestion;
Suggestion *SuggestionHead=NULL;




 void insertAtBeginningSuggestion(Suggestion *suggestionInput){

    Suggestion* newSuggestion  =(Suggestion*)malloc(sizeof(Suggestion));
    if(newSuggestion ==NULL) printf("out of memory");
    printf("\n\ncreated newMedicine \n\n");
    strcpy(newSuggestion->doctor_id,suggestionInput->doctor_id);
    strcpy(newSuggestion->Suggestion,suggestionInput->Suggestion);
    


    if(SuggestionHead==NULL){
        newSuggestion->next =NULL;
       SuggestionHead =newSuggestion;
    }
    else{
        newSuggestion ->next =SuggestionHead;
        SuggestionHead=newSuggestion;

   

    }

 }

 void  instertPositionSuggestion(Suggestion *suggestionInput,int pos){
    if(pos==0){
       insertAtBeginningSuggestion(suggestionInput);
    }

        
    int i=1;
   Suggestion* newSuggestion  =(Suggestion*)malloc(sizeof(Suggestion));
    if(newSuggestion ==NULL) printf("out of memory");


    strcpy(newSuggestion->doctor_id,suggestionInput->doctor_id);
    strcpy(newSuggestion->Suggestion,suggestionInput->Suggestion);
    Suggestion *temp =SuggestionHead;
    for(i=1;i<=pos-1;i++){
        temp= temp->next;
        if(temp==NULL){
            printf("Invalid position lsat \n");
            return;
        }
    }
    
    newSuggestion->next =temp->next;
    temp->next = newSuggestion;
    

}


void fileLoadUpSuggestion(){

    printf("\n\t\tfile loanded in main function \n");
    char line[4000];
    FILE * file =NULL;
    if(file=fopen("./DoctorSuggestion.txt","r")){
        Suggestion Sugg_temp;
        int i=0;
        while(fscanf(file,"%s",line) !=EOF){
            int n=0;
        
        // printf("\n%s\n",line);
        char * data =strtok(line,",");
        
        while(data !=NULL){
            if(n==0){
                 strcpy(Sugg_temp.Suggestion,data);
            }
            else if(n==1){
               
                strcpy(Sugg_temp.doctor_id,data);
            }
    
            
            
            

            data =strtok(NULL,",");
            n++;

        }
         instertPositionSuggestion(&Sugg_temp,i);
        i++;

        }
    }
    else printf("\n=====  + ====== # Doctors didn't suggest  # =====  + ======  \n");

}

 /*void  displaySuggestion() {
    if(SuggestionHead==NULL){
        printf("\nList is empty\n");
    }
    else{
     Suggestion* temp=SuggestionHead;
     printf("\n===== + ===== + ===== + ====== + ===== + ======\n");
     while(temp!=NULL)
     {
        printf("\nDoctor ID is -->%s\n",temp->doctor_id);
        printf("\nDoctor Suggestion is -->%s\n",temp->Suggestion);
        temp = temp->next;
     }
     printf("\n===== + ===== + ===== + ====== + ===== + ======\n");
    }

 }*/

void StoreSuggestion(){
    Suggestion storeSuggest;
    char filename[20]="./Suggestion/";
    printf("Enter Suggestio ID :");
    scanf("%s",storeSuggest.Suggestion_id);
    strcat(filename,storeSuggest.Suggestion_id);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeFilenames.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"Suggestion ID is : %s\n",storeSuggest.Suggestion_id);
        fprintf(file,"Doctor ID is : %s\n","00001");
        printf("Enter the Suggestion Medicine Name :");
        scanf("%s",storeSuggest.Suggestion);
        scanf("%[^\n]",storeSuggest.Suggestion);

        fprintf(file,"Suggest medicine Name : %s\n",storeSuggest.Suggestion);

       
        fclose(file);
    }

}

 void fileLoadUpSuggestion(){
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
    