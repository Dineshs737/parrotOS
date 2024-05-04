#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include"working_hours.h"
int days=30;


//functions 
void working_hours();
int work_hours();
int working_updates();
void payment_detail();



void working_hours()
 {
   
   int choice;

   
        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =       [ 1 ]   Total Work Hours & payment  =");
        printf("\n\t\t\t        =       [ 2 ]   Appoinment details          =");
        printf("\n\t\t\t        =       [ 0 ]   EXIT                        =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
        scanf("%d", &choice);
        printf("\t\t\t  -----------------------------------------------------------\n");

        switch (choice)
        {
         case 1:
            work_hours();
            break;

         case 2:
             printf("add appoinment file datails");
            break;
            
         case 0:
             printf("\n\t\t\t  ---------------------------------------------------------\n");
             printf("\t\t\t                         EXITING SERVICES                    ");
             printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;

         default:
             printf("\n\t\t\t  ---------------------------------------------------------\n");
             printf("\t\t\t                         WRONG INPUT                    ");
             printf("\t\t\t                         TRY AGAIN                      ");
             printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;
        }
 }

 

//function for choice 
 int work_hours(){
   
       int choice_2;

        printf("\n\n\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =         [ 1 ]   Total Working Hours       =");
        printf("\n\t\t\t        =         [ 2 ]   Total Payments            =");
        printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

        printf("\n\t\t\t  ----------------------------------------------------------\n");
        printf("\t\t\t             whats is the service are you expect : ");
        scanf("%d", &choice_2);
        printf("\t\t\t  -----------------------------------------------------------\n");

        
        switch (choice_2)
        {
         case 1:
             working_updates();
            break;
         case 2:
             payment_detail();
             break;
        
         case 0:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         EXITING SERVICES                    ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");

            //if select exit again goto start page 
             working_hours(); 

            break;

         default:
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            printf("\t\t\t                         WRONG INPUT                    ");
            printf("\t\t\t                         TRY AGAIN                      ");
            printf("\n\t\t\t  ---------------------------------------------------------\n");
            break;
        }
 }
      
   


         // funstion for choice Total Working Hours as a chooice 2
        int working_updates()
           {     

             
               //open a new file as working.txt
               FILE *fp=NULL;

                 int workhours=0;
                 workhours = days*2;

               fp = fopen("working.txt","w");

               if(fp==NULL)
               {
                 printf("error");
               }

               // write the datas in to the file
                fprintf(fp, " %d" , workhours   );

                fclose(fp);


               // print  total hours data from file "working.txt"
                FILE *fp1;

                int wh;
                fp1 =fopen("working.txt","r");

                if(fp1==NULL)
                {
                    printf("error");
                }

                fscanf (fp1, "%d", &wh);

                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                      TOTAL WORK HOURS = %d                  ",wh);
                printf("\n\t\t\t  ---------------------------------------------------------\n");

                fclose(fp1);

           }
           
        // funstion for choice Total Payments  as a chooice 2
       void payment_detail()
           {     
               // print  total hours data from file "working.txt"
                FILE *fp2;

                int wh , payment;
              
                fp2 =fopen("working.txt","r");

                if(fp2==NULL)
                {
                    printf("error");
                }

                fscanf (fp2, " %d ", &wh);

                //1 hours payment is 200,000rs

                payment = wh*200000;

                printf("\n\t\t\t  ---------------------------------------------------------\n");
                printf("\t\t\t                      TOTAL payment = %d  RS                ",payment);
                printf("\n\t\t\t  ---------------------------------------------------------\n");

                fclose(fp2);

           }
           



