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

char name[30];
char use[200];
char date[10];
long int stock;
double price;
struct  medicineData* next;

};typedef struct medicineData medicine;


 void StoreMedicine(){
    medicine storeMedicine;
    char filename[20]="./medicine/";
    char choice;
    int counter =1;
    while(1){
    printf("Enter Medicine Name :");
    scanf("%s",storeMedicine.name);
    strcat(filename,storeMedicine.name);
    strcat(filename,".txt");
    FILE *storefilename=NULL;
    if(storefilename =fopen("./storeMedicineFilenames.txt","a")){fprintf(storefilename,"%s\n",filename); fclose(storefilename);}

    FILE *file =NULL;
    if(file=fopen(filename,"a")){
        fprintf(file,"Medicine:%s\n",storeMedicine.name);
        printf("Enter use of medicine  :");
        scanf("%s",storeMedicine.use);
       
        scanf("%[^\n]",storeMedicine.use);
         fprintf(file,"use:%s\n",storeMedicine.name);

        printf("Enter use of Experdate day :");
        scanf("%s",storeMedicine.date);
        scanf("%[^\n]",storeMedicine.date);
        fprintf(file,"Experdate:%s\n",storeMedicine.date);

        printf("Enter stock count of the medicine :");
        scanf("%d",&storeMedicine.stock);

        fprintf(file,"Stock:%d\n",storeMedicine.stock);

        printf("Enter price of the medicine :");
        scanf("%lf",&storeMedicine.price);
        fprintf(file,"price:%lf\n",storeMedicine.price);

       
        fclose(file);
    }
    printf("Do you want to add another medicine Detail ?y ?n :");
    scanf("%c",&choice);
    scanf("%c",&choice);
    if(choice=='n'||choice=='N') break;
    else if(choice!='Y' || choice !='y'||choice !='n' || choice !='N'){
        printf("\n!!!!!======= You shoud Enter Y OR N Try again ========!!!!!\n");
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

    while(fgets(medicineInfo,sizeof(medicineInfo),tempFile)){

                if(lineCounter==1){
                int n=0;
                char * datas=strtok(medicineInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempMedicine.name,datas);
            } datas =strtok(NULL,":");
            n++; }

                }

                 //strcpy(tempMedicine.name,medicineInfo);
                if(lineCounter==2) 
                {
                int n=0;
                char * datas=strtok(medicineInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempMedicine.use,datas);
            } datas =strtok(NULL,":");
               n++; 
            }}
                
                
                //strcpy(tempMedicine.use,medicineInfo);
                if(lineCounter==3){
                    
                int n=0;
                char * datas=strtok(medicineInfo,":");
        
                while(datas !=NULL){
                if(n==1){
                strcpy(tempMedicine.date,datas);
            } datas =strtok(NULL,":");
               n++; 
            }
                }

                //strcpy( tempMedicine.date,medicineInfo);
                if(lineCounter==4) {
                     // printf("%s",medicineInfo);
                    int n=0;
                char * datas=strtok(medicineInfo,":");
           
                while(datas !=NULL){
                if(n==1){
                //strcpy(tempMedicine.stock,datas);
                tempMedicine.stock = atoi(datas);
               //printf("%s",datas);
            } datas =strtok(NULL,":");
               n++; 
            }

                }
                if(lineCounter==5){

                    int n=0;
                char * datas=strtok(medicineInfo,":");
           
                while(datas !=NULL){
                if(n==1){
                //strcpy(tempMedicine.stock,datas);
                tempMedicine.price = atof(datas);
               //printf("%s",datas);
            } datas =strtok(NULL,":");
               n++; 
                }
                
                
                //tempMedicine.stock;

                lineCounter++;
                }
           

            fclose(tempFile);
        
        
       


    }
    // printf("%s",tempMedicine.name);
    // printf("\n%s",tempMedicine.use);
    // printf("\n%s",tempMedicine.date);
    // printf("%d",tempMedicine.stock);
    return(tempMedicine);

    


    }
}
void MedicineUpdate(){
    int option;
    char name[20];
    char filename[30]="./medicine/";
    printf("\nEnter the medicine Name :");
    scanf("%s",name);
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
  //  char changeData[50]; int stockData;
    medicine mediUpdate = MedicineDataSplit(name);
    double stock; //char changeData[40];
   //medicine tmp =mediUpdate;
    FILE *file =NULL;
    switch(option){
        
        case 1:
         printf("Enter stock count :");
        scanf("%s",stock); //mediUpdate.stock =sprintf
      // mediUpdate.stock =atoi(stock);
      mediUpdate.stock =stock;
       
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
        scanf("%lf",&mediUpdate.price);



    }

         if(file=fopen(filename,"w")){

        fprintf(file,"Medicine:%s",mediUpdate.name);
         fprintf(file,"use:%s",mediUpdate.use);
         fprintf(file,"Experdate:%s\n",mediUpdate.date);
         fprintf(file,"Stock:%d\n",mediUpdate.stock);
         fprintf(file,"price:%lf\n",mediUpdate.price);

// printf("%s",mediUpdate.name);
  //  printf("\n%s",mediUpdate.use);
 //   printf("\n%s",mediUpdate.date);
   // printf("%d",mediUpdate.stock);
   printf("\nMedicine  updated \n");
    }

    }else{
        printf("\nDidn't add the medicine name\n");
    }
   
    




}
    
     

 

