/*
    INSTITUTO POLITÉCNICO NACIONAL
    ESCUELA SUPERIOR DE CÓMPUTO
    ESTRUCTURAS DE DATOS
    GRUPO: 1CV8
    ALUMNOS:
         Jose Manuel Ramirez Vivez
         Oscar Andrés Rosas

    PROFESOR: BENJAMÍN LUNA BENOSO
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    ARCHIVO DE IMPLEMENTACION REGISTRO DE TEMPERATURA
    FECHA: 23 DE ABRIL
*/


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++     LIST IMPLEMENTATION TO CHECK EVERYTHING IS OK           ++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use

#include "DoublyLinkedList.h"                                   //Our beloved List


// ================================================
// ===      FUNTIONS THAT I HAVE TO IMPLEMENT   ===
// ================================================
void ShowFecha(Fecha *F){                                       //=== IMPLEMENTATION OF SHOW ITEM ===
    if (F->hora < 10) printf("(0%i", F->hora);
    else printf("(%i", F->hora);

    if (F->minuto < 10) printf(":0%i - ", F->minuto);
    else printf(":%i - ", F->minuto);    

    if (F->dia < 10) printf("0%i/", F->dia);
    else printf("%i/", F->dia);

    if (F->mes < 10) printf("0%i/", F->mes);
    else printf("%i/", F->mes);

    printf("%i)", F->año);
}

void ShowItem(Item *ItemX){                                     //=== IMPLEMENTATION OF SHOW ITEM ===
    if (ItemX == NULL) {printf("[ ] \n"); return;}              //This is how i draw a NULL
    ShowFecha(ItemX->FechaDelItem);                             //Muestra la fecha
    printf(" Temperatura : %i \n", ItemX->Temperatura);         //Is an innocent printf
}

Item* CreateItem(){                                             //=== IMPLEMENTATION OF CREATE ITEM ===
    Item *Temporal = (Item*) malloc(sizeof(Item));              //Reserve memory
    Fecha *FechaTemp = (Fecha*) malloc(sizeof(Fecha));          //Reserve memory

    printf("La temperatura fue: ");                             //Simple message
    scanf("%i%*c", &Temporal->Temperatura);                     //Give me data!, I need data :3
    
    printf("Dame una hora:\n"); scanf("%i%*c", &FechaTemp->hora);  //Give me data!, I need data :3
    printf("Dame un minuto:\n"); scanf("%i%*c", &FechaTemp->minuto);  //Give me data!, I need data :3
    printf("Dame un dia:\n"); scanf("%i%*c", &FechaTemp->dia);  //Give me data!, I need data :3
    printf("Dame un mes:\n"); scanf("%i%*c", &FechaTemp->mes);  //Give me data!, I need data :3
    printf("Dame un año:\n"); scanf("%i%*c", &FechaTemp->año);  //Give me data!, I need data :3

    if (FechaTemp->minuto < 0 ) FechaTemp->minuto *= -1;
    if (FechaTemp->hora < 0 ) FechaTemp->hora *= -1;
    if (FechaTemp->dia < 0 ) FechaTemp->dia *= -1;
    if (FechaTemp->mes < 0 ) FechaTemp->mes *= -1;
    if (FechaTemp->año < 0 ) FechaTemp->año *= -1;
    
    if (FechaTemp->hora > 23) FechaTemp->hora = 23;             //Errors :D
    if (FechaTemp->minuto > 59) FechaTemp->minuto = 59;         //Errors :D
    if (FechaTemp->dia > 31) FechaTemp->dia = 31;               //Errors :D
    if (FechaTemp->mes > 12) FechaTemp->mes = 12;               //Errors :D
    if (FechaTemp->año < 100) {                                 //Errors :D
        if (FechaTemp->año < 18) FechaTemp->año += 2000;        //Errors :D
        else FechaTemp->año += 1900;                            //Errors :D
    } 

    Temporal->FechaDelItem = FechaTemp;                         //Add to memory
    return Temporal;                                            //You are complete, go, and protect the data
}

int CompareItems(Item *C, Item *D){                             //=== IMPLEMENTATION OF COMPARE ITEM ===
    Fecha *A = C->FechaDelItem , *B = D->FechaDelItem;          //This is the important part
    if (A == NULL && B == NULL) return 0;                       //If you sent me no data :(
    if (A == NULL && B != NULL) return -1;                      //everything is bigger than NUll
    if (A != NULL && B == NULL) return 1;                       //everything is bigger than NUll

    if (A->año != B->año){
        if (A->año > B->año) return 1;
        if (A->año < B->año) return -1;
    }

    if (A->mes != B->mes){
        if (A->mes > B->mes) return 1;
        if (A->mes < B->mes) return -1;
    }

    if (A->dia != B->dia){
        if (A->dia > B->dia) return 1;
        if (A->dia < B->dia) return -1;
    }

    if (A->hora != B->hora){
        if (A->hora > B->hora) return 1;
        if (A->hora < B->hora) return -1;
    }

    if (A->minuto != B->minuto){
        if (A->minuto > B->minuto) return 1;
        if (A->minuto < B->minuto) return -1;
    }

    return 0;                                                   //Ohh the compiler :3
}

int CompareItemsTemperatura(Item *C, Item *D){                  //=== IMPLEMENTATION OF COMPARE ITEM ===
    if (C == NULL && D == NULL) return 0;                       //If you sent me no data :(
    if (C == NULL && D != NULL) return -1;                      //everything is bigger than NUll
    if (C != NULL && D == NULL) return 1;                       //everything is bigger than NUll
    int A = C->Temperatura , B = D->Temperatura;                //This is the important part
    if (A != B){        
        if (A > B) return 1;
        if (A < B) return -1;
    }
    return 0;                                                   //Ohh the compiler :3
}


void NuevoInsertSort(List **ListX, Item *ItemX){                // ==== INSERT IN ORDER OF THE LIST =====
    if (ItemX == NULL) return;                                  //very funny :/ 
    if (Head == NULL) {InsertAtHead(ListX, ItemX); return;}     //Upps, special case

    if (CompareItemsTemperatura(ItemX,(Head->NodeItem)) < 1)               //Special case where it dont work
        {InsertAtHead(ListX, ItemX); return;}                   //So call something that do it

    if(Head->Next == NULL){InsertAtTail(ListX, ItemX); return;} //If you didnt fall in the last if 

    Node *CurrentNode = Head;                                   //Make it a counter
    while (CompareItemsTemperatura(ItemX,(NextNode->NodeItem)) == 1){      //While we didn't have found the pointer
        GoNextNode;                                             //Go next node please
        if (NextNode == NULL) break;                            //If we are at the end the list 
    }

    Node *NewNode = CreateNode(ItemX);                          //Create a new node
    NewNode->Next = NextNode;                                   //I point to the list (all of after)
    NewNode->Prev = CurrentNode;                                //I point to the list (all of before)
    if (NextNode != NULL)NextNode->Prev = NewNode;              //The list (future) now point at me (if it can :D)
    NextNode = NewNode;                                         //The list now point at me (past)
}




void ReordenaLista(List **ListX){
    if (Head == NULL) {ShowItem(NULL); return;}                 //Funny, very funny
    Node *CurrentNode = Head;                                   //Lets make a pointer to travel to the list
    
    List* NuevoLista = CreateList();

    for (; NextNode != NULL; GoNextNode){                       //Using a cool for loop, See List.h to know how to
        NuevoInsertSort(&NuevoLista, CurrentNode->NodeItem);
    }

    NuevoInsertSort(&NuevoLista, CurrentNode->NodeItem);

    ShowList(&NuevoLista);
}


void Limites(List **ListX, int modo){
    if (Head == NULL) {ShowItem(NULL); return;}                 //Funny, very funny

    int dia, mes, año;
    printf("Dame un dia:\n"); scanf("%i%*c", &dia);             //Give me data!, I need data :3
    printf("Dame un mes:\n"); scanf("%i%*c", &mes);             //Give me data!, I need data :3
    printf("Dame un año:\n"); scanf("%i%*c", &año);             //Give me data!, I need data :3

    if (dia < 0) dia *= -1;
    if (mes < 0) mes *= -1;
    if (año < 0) año *= -1;


    if (dia > 31) dia = 31;                                     //Errors :D
    if (mes > 12) mes = 12;                                     //Errors :D
    if (año < 100) {                                            //Errors :D
        if (año < 18) año += 2000;                              //Errors :D
        else año += 1900;                                       //Errors :D
    } 


    Node *CurrentNode = Head;                                   //Lets make a pointer to travel to the list
    List* NuevoLista = CreateList();

    for (; NextNode != NULL; GoNextNode){                       //Using a cool for loop, See List.h to know how to

        if(CurrentNode->NodeItem->FechaDelItem->dia == dia)
            if(CurrentNode->NodeItem->FechaDelItem->mes == mes)
                if(CurrentNode->NodeItem->FechaDelItem->año == año)
                    NuevoInsertSort(&NuevoLista, CurrentNode->NodeItem);
    }

    if(CurrentNode->NodeItem->FechaDelItem->dia == dia)
        if(CurrentNode->NodeItem->FechaDelItem->mes == mes)
            if(CurrentNode->NodeItem->FechaDelItem->año == año)
                NuevoInsertSort(&NuevoLista, CurrentNode->NodeItem);



    if (modo == 1){
        ShowItem(NuevoLista->NodeItem);
    }

    if (modo == -1){
        Node *Actual = NuevoLista;
        for (; Actual->Next != NULL; Actual = Actual->Next){
        }

        ShowItem(Actual->NodeItem);
    }
}




// ====================================================
// ===              CODIGO MAIN                     ===
// ====================================================
int main(void){
    List* ListX = CreateList();
    int Position;
    int menu;
 
    do{
        printf("\n============ Menu ===========\n");
        printf("Añade:    1)Ordenado\n");
        printf("Remove:   2)Cabeza\t3)Cola\t4)Posicion\t5)Un Fecha Especial\n");
        printf("Cool:     6)Muestra Registros\t0)Salir\n");
        printf("Cool:     7)Muestra por Temperatura\n");
        printf("Cool:     8)Temperatura mas alta\n");
        printf("Cool:     9)Temperatura mas baja\n");

        printf("* Tu eleccion: ");
        scanf("%i%*c", &menu);

        switch(menu){

            case 1:
                InsertSort(&ListX, CreateItem());
            break;

            case 2:
                ShowItem(EliminateAtHead(&ListX));
            break;

            case 3:
                ShowItem(EliminateAtTail(&ListX));
            break;

            case 4:
                printf("Dame una posicion: ");
                scanf("%i%*c", &Position);
                ShowItem(Eliminate(&ListX, Position));
            break;

            case 5:
                ShowItem(EliminateItem(&ListX, CreateItem()));
            break;

            case 6:
                ShowList(&ListX);
            break;

            case 7:
                ReordenaLista(&ListX);
            break;

            case 8:
                Limites(&ListX, -1);
            break;

            case 9:
                Limites(&ListX, 1);
            break;

        }
        printf("\n\n");

    }
    while(menu != 0);
    return 0;
}
