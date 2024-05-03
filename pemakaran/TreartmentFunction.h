#include"./TreartmentSource.h"
#include<stdio.h>
#include<string.h>
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