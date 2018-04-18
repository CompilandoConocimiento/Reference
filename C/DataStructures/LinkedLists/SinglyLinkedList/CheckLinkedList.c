/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++     LIST IMPLEMENTATION TO CHECK EVERYTHING IS OK           ++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "LinkedList.h"                                         //Our beloved List


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

int CompareItems(Item *A, Item *B){                             //=== IMPLEMENTATION OF COMPARE ITEM ===
    if (A == NULL && B == NULL) return 0;                       //If you sent me no data :(
    if (A == NULL && B != NULL) return -1;                      //everything is bigger than NUll
    if (A != NULL && B == NULL) return 1;                       //everything is bigger than NUll
    if (A->number > B->number)  return 1;                       //If A wins
    if (A->number < B->number)  return -1;                      //If B wins
    if (A->number == B->number) return 0;                       //If ALL wins
    return 0;                                                   //Ohh the compiler :3
}



// ====================================================
// ===              CODIGO MAIN                     ===
// ====================================================
int main(void){
    List* ListX = CreateList();
    int Position;
    int menu;

    printf("\n======= WELCOME TO LISTS BY SOYOSCARRH ====");    //Some credit :p    
    do{
        printf("\n============ Menu ===========\n");
        printf("Add:      1)Head\t2)Tail\t3)Position\t4)Sorted\n");
        printf("Remove:   5)Head\t6)Tail\t7)Position\t8)Item\n");
        printf("Peek:     9)Head\t10)Tail\t11)Position\t12)Item\n");
        printf("Cool:     13)Show List\t14)Reverse\n");

        printf("* Your election Sir/Miss: ");
        scanf("%i%*c", &menu);

        switch(menu){

            case 1:
                InsertAtHead(&ListX, CreateItem());
            break;

            case 2:
                InsertAtTail(&ListX, CreateItem());
            break;

            case 3:
                printf("Give me Position: ");
                scanf("%i%*c", &Position);
                Insert(&ListX, CreateItem(), Position);
            break;

            case 4:
                InsertSort(&ListX, CreateItem());
            break;

            case 5:
                ShowItem(EliminateAtHead(&ListX));
            break;

            case 6:
                ShowItem(EliminateAtTail(&ListX));
            break;

            case 7:
                printf("Give me Position: ");
                scanf("%i%*c", &Position);
                ShowItem(Eliminate(&ListX, Position));
            break;

            case 8:
                ShowItem(EliminateItem(&ListX, CreateItem()));
            break;

            case 9:
                ShowItem(PeekAtHead(&ListX));
            break;

            case 10:
                ShowItem(PeekAtTail(&ListX));
            break;

            case 11:
                printf("Give me Position: ");
                scanf("%i%*c", &Position);
                ShowItem(Peek(&ListX, Position));
            break;

            case 12:
                ShowItem(PeekItem(&ListX, CreateItem()));
            break;

            case 13:
                ShowList(&ListX);
            break;

            case 14:
                Reverse(&ListX);
            break;

        }
        printf("\n\n");

    }
    while(menu != 0);
    return 0;
}
