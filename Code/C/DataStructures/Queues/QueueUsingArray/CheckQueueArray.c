/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++    STACK IMPLEMENTATION TO CHECK EVERYTHING IS OK           ++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "QueueArray.h"                                         //Our beloved Queue

// ================================================
// ===      FUNTIONS THAT I HAVE TO IMPLEMENT   ===
// ================================================
void ShowItem(Item *ItemX){                                     //=== IMPLEMENTATION OF SHOW ITEM ===
    if (ItemX == NULL) {printf("[ ] "); return;}                //This is how i draw a NULL
    printf("[%i] ", ItemX->number);                             //Is an innocent printf
}

Item* CreateItem(){                                             //=== IMPLEMENTATION OF CREATE ITEM ===
    Item *Temporal = (Item*) malloc(sizeof(Item));              //Reserve memory
    printf("Give me a number: ");                               //Simple message
    scanf("%i%*c", &Temporal->number);                          //Give me data!, I need data :3
    return Temporal;                                            //You are complete, go, and protect the data
}



// ===========================================================
// =======     MAIN: WHERE EVERYTHING MAKE SENSE      ========
// ===========================================================
int main(void){
    Queue QueueX;
    CreateQueue(&QueueX);
    int menu;

    printf("\n======= WELCOME TO STACK BY SOYOSCARRH ====");    //Some credit :p    
    do{
        printf("\n============ Menu ===========\n");
        printf("Essencials:   1) Push\t2)Pop\n");
        printf("Cool:         3)Peek Top\t4) Show Stack\n");

        printf("* Your election Sir/Miss: ");
        scanf("%i%*c", &menu);
        
        switch(menu){

            case 1:
                Enqueue(&QueueX, CreateItem());
            break;

            case 2:
                ShowItem(Dequeue(&QueueX));
            break;

            case 3:
                ShowItem(Peek(&QueueX));
            break;

            case 4:
                ShowQueue(QueueX);
            break;
        }
        printf("\n\n");
    }
    while(menu != 0);

    return 0;
}









