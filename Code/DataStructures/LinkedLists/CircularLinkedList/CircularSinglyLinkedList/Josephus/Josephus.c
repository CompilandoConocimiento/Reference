/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++     LIST IMPLEMENTATION TO CHECK EVERYTHING IS OK           ++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                              //Library that we are going to use
#include <stdlib.h>                                             //Library that we are going to use
#include <math.h>                                               //Library that we are going to use
#include <string.h>                                             //Library that we are going to use
#include <time.h>                                             //Library that we are going to use

#include "CircularSinglyLinkedList.h"                           //Our beloved List


// ================================================
// ===      FUNTIONS THAT I HAVE TO IMPLEMENT   ===
// ================================================
void ShowItem(Item *ItemX){                                     //=== IMPLEMENTATION OF SHOW ITEM ===
    if (ItemX == NULL) {printf("[ ] "); return;}                //This is how i draw a NULL
    printf("[%s] ", ItemX->nombre);                             //Is an innocent printf
}

Item* CreateItem(){                                             //=== IMPLEMENTATION OF CREATE ITEM ===
    Item *Temporal = (Item*) malloc(sizeof(Item));              //Reserve memory
    printf("Dame un nombre para el Soldado: ");                 //Simple message
    fgets(Temporal->nombre, 50, stdin);                         //Get the name
    Temporal->nombre[strlen(Temporal->nombre)-1] = '\0';        //remove space
    return Temporal;                                            //You are complete, go, and protect the data
}

int CompareItems(Item *A, Item *B){                             //=== IMPLEMENTATION OF COMPARE ITEM ===
    return 0;                                                   //Ohh the compiler :3
}



void Josepuhs(List **Soldados, int MaximoSoldados, int Salto){

    int i, j, k;

    for (i = 0; i < MaximoSoldados; ++i)
        InsertAtTail(Soldados, CreateItem());

    printf("Grupo Original\n");
    ShowList(Soldados);
    printf("\n\n");

    int pasada = 1;
    int espacios = 0;

    char *Temporal;

    printf("Pasada\t\t\tNombres");
    int tabulaciones = Longitud(Soldados);

    for (int i = 0; i < (tabulaciones-6); ++i) printf(" ");
    printf("             Sale\n");

    while ( EmptyList(Soldados) != 1){

        printf(" %i \t\t\t", pasada);
        ShowList(Soldados);

        for (int i = 1; i < Salto; ++i)
            SwipeList(Soldados);

        printf("              ");
        for (int i = 0; i < espacios; ++i)
            printf(" ");

        Temporal = PeekTop(Soldados)->nombre;
        espacios += 3 + strlen(Temporal);
        
        ShowItem(EliminateItem(Soldados, PeekTop(Soldados)));
        printf("\n");
        pasada++;
    }

    printf("\n\n\nEl que escapa es : %s\n", Temporal);
}




// ====================================================
// ===              CODIGO MAIN                     ===
// ====================================================
int main(void){
    srand(time(NULL));

    List* Soldados = CreateList();
    int MaximoSoldados;
    int Salto;

    printf("\nDame la N de Soldados: ");
    scanf("%i%*c", &MaximoSoldados);
    rand();

    Salto = rand() % MaximoSoldados;

    printf("\nEl numero de Salto sera: %i\n", Salto);

    Josepuhs(&Soldados, MaximoSoldados, Salto);

    return 0;
}
