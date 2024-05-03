#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
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



void StoreSuggestion(char d_name[]){
    Suggestion newSuggestion;
    char filename[60];
    int choice;
    int counter =1;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    while(1){
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

    if(choice==2){ break;

     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
    
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





void  adminSuggestion(){
FILE *f =NULL;
   f=fopen("./storeSuggestion.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
   }
   //int lineCounter=1;
   Suggestion tempSuggestio;
    char line[1024];
            printf("\n\t\t\t_______________________________________________________\n");
            printf("\t\t\t              Treartment History                       \n");
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

void DoctorSuggestion(char d_name[]){
FILE *f =NULL;
   f=fopen("./storeSuggestion.txt","r");
   if(f==NULL){
        printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
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
 }