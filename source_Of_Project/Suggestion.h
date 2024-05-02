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
    