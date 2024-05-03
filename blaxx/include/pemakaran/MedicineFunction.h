#include"./MedicineSource.h"
//#include<stdio.h>
//#include<string.h>

void StoreMedicine(){
    
    
    
    medicine storeMedicine;
    char filename[20];
    int choice;
    int counter =1;
    printf("\n\t\t========= +++ ========= +++ ========= +++ ========= +++ =========\n");
    while(1){
    strcpy(filename,"./medicine/");
    printf("\n\n\t\t\tEnter Medicine Name :");
    scanf("%s",storeMedicine.name);
    strcat(filename,storeMedicine.name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeMedicineFilenames.txt","a")){
        fprintf(storefilename,"%s\n",filename); fclose(storefilename);
        
        }

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"Medicine:%s\n",storeMedicine.name);
        printf("\t\t\tEnter use of medicine  :");
        scanf("%s",storeMedicine.use);
       
        scanf("%[^\n]",storeMedicine.use);
         fprintf(file,"use:%s\n",storeMedicine.use);

        printf("\t\t\tEnter use of Experdate day :");
        scanf("%s",storeMedicine.date);
        scanf("%[^\n]",storeMedicine.date);
        fprintf(file,"Experdate:%s\n",storeMedicine.date);

        printf("\t\t\tEnter stock count of the medicine :");
        scanf("%d",&storeMedicine.stock);

        fprintf(file,"Stock:%d\n",storeMedicine.stock);

        printf("\t\t\tEnter price of the medicine :");
        scanf("%lf",&storeMedicine.price);
        fprintf(file,"price:%lf\n",storeMedicine.price);

       
        fclose(file);


    printf("\n\n\t\t\t[1]. Do you want to add another medicine\n");
    printf("\t\t\t[2]. Exit\n");

    printf("\n\t\t________________________________________________________\n");
    printf("\n\t\t\tChoice the options :");
    scanf("%d",&choice);
    printf("\n\t\t________________________________________________________\n");

    if(choice==2){ break;

    printf("\n\t\t========= +++ ========= +++ ========= +++ ========= +++ =========\n");
    
    }
    if(choice>2 || choice <1){ 
    printf("\n\t\t\t _________ You should Enter correct option ____________\n");
    printf("\n\t\t\t________________________________________________________\n");
     
    }
    printf("\n\t\t========= +++ ========= +++ ========= +++ ========= +++ =========\n");
    
    }
    }
  
   
    
    

}

 void fileLoadUpMedicine(){
   FILE *f =NULL;
   f=fopen("storeMedicineFilenames.txt","r");
   if(f==NULL){
        printf("\n!!!!!!!! ========= Didn't add medicine ========= !!!!!!!!!\n");
   }
   
    char line[1024];
    while(fscanf(f,"%s",line)!=EOF){
        char medicineInfo[1024];
        FILE*file=NULL;
        if(file =fopen(line,"r")){

            while(fgets(medicineInfo,sizeof(medicineInfo),file)){
                printf("%s",medicineInfo);
                printf("\n");
            }
            printf("\n");

            fclose(file);
        }


    }
   }