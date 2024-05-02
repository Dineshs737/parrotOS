#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char admin[]="adMin21";


void 
     int admin_options;

    printf("\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =         [ 1 ]   VIEW RESERVATION HISTORY  =");
    printf("\n\t\t\t        =         [ 2 ]   VIEW LOGS                 =");
    printf("\n\t\t\t        =         [ 3 ]   VIEW BUGS                 =");
    printf("\n\t\t\t        =         [ 4 ]   VIEW SUPPORTS             =");
    printf("\n\t\t\t        =         [ 0 ]   EXIT                      =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

    printf("\n\t\t\t  ---------------------------------------------------------\n");
    printf("\t\t\t                PLEASE, MAKE A CHOISE : ");
    scanf("%d", &admin_options);
    printf("\n\t\t\t  ---------------------------------------------------------\n");

    switch (admin_options)
    {
    case 1:
        view_admin_trainreservation();
        break;
    case 2:
        view_admin_logs_history();
        break;
    case 3:
        view_admin_bugs();
        break;
    case 4:
        view_admin_supports();
        break;
    case 0:

        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         EXITING SERVICES                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        exit(0);
        break;

    default:
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        printf("\t\t\t                         WRONG INPUT                    ");
        printf("\t\t\t                         TRY AGAIN                    ");
        printf("\n\t\t\t  ---------------------------------------------------------\n");
        break;
    }
}



}
