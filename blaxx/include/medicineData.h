#include<string.h>
#include<stdlib.h>
#include<stdio.h>
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

void StoreMedicine();
void adminMedicine();
void edicineUpdate();


void medicineLogin(){
    int op;
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");
     printf("\n\t\t\t\t\t[1]. Add new Medicine\n");
     printf("\t\t\t\t\t[2]. Display Medicine Detail\n");
     printf("\t\t\t\t\t[3]. Update Medicine Detail\n");
     printf("\t\t\t\t\t[4]. Exit\n");
     printf("\n\t\t\t== == == == == == == == == == == == == == == == == == ==\n");

    printf("\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t\t    Eenter Your choice :");
    scanf("%d",&op);
    printf("\t\t\t _______________________________________________________\n");
   
    switch(op){
        case 1 :StoreMedicine(); break;
        case 2 :adminMedicine();break;
        case 3 :MedicineUpdate();break;
    }
}

 void StoreMedicine(){
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
  
   
    
    
medicineLogin();
}

 void adminMedicine(){
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
             medicineLogin();

    }




medicine MedicineDataSplit(char name[]){
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
    

    


void MedicineUpdate(){
   
    int option;
    char name[20];
    char filename[30]="./medicine/";
    printf("\nEnter the medicine Name :");
    scanf("%s",name);
    medicine mediUpdate = MedicineDataSplit(name);
    strcat(filename,name);
    strcat(filename,".txt");
    FILE * check=NULL;
    if(check=fopen(filename,"r")){
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
    }
    }
    medicineLogin();
    }



     


     

 

