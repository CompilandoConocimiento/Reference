/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++           BINARY TREE FUNTIONS FILE         ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                                          //Library that we are going to use
#include <stdlib.h>                                                         //Library that we are going to use
#include <math.h>                                                           //Library that we are going to use
#include <string.h>                                                         //Library that we are going to use

#include "BinaryTree.h"                                                     //Our beloved Binary Tree
#include "Stack.h"                                                          //Our beloved Binary Tree

// ================================================
// ===      FUNTIONS THAT I HAVE TO IMPLEMENT   ===
// ================================================
void ShowItem(Item *ItemX){                                                 //=== IMPLEMENTATION OF SHOW ITEM ===
    if (ItemX == NULL) {printf("[ ] "); return;}                           //This is how i draw a NULL
    printf("[%c] ", ItemX->Symbol);                                        //Is an innocent printf
}

Item* CreateItem(){                                                         //=== IMPLEMENTATION OF CREATE ITEM ===
    Item *Temporal = (Item*) malloc(sizeof(Item));                          //Reserve memory
    printf("Give me a Char: ");                                             //Simple message
    scanf("%c%*c", &Temporal->Symbol);                                      //Give me data!, I need data :3
    return Temporal;                                                        //You are complete, go, and protect the data
}

Item* CreateNewItem(char Data){                                             //=== IMPLEMENTATION OF CREATE ITEM ===
    Item *Temporal = (Item*) malloc(sizeof(Item));                          //Reserve memory
    Temporal->Symbol = Data;                                                //Just Give the number
    return Temporal;                                                        //You are complete, go, and protect the data
}

int CompareItems(Item *DataLeft, Item *DataRight){                          //=== COMPARE FOR BIGGER -1:LEFT, 1:Right ======
    if (DataLeft == NULL) return 1;                                         //If there was nothing in here
    if (DataRight == NULL) return -1;                                       //If there was nothing in here

    if ( (int)DataLeft->Symbol == (int)DataRight->Symbol ) return 0;        //Change
    if ( (int)DataLeft->Symbol < (int)DataRight->Symbol ) return 1;         //Change

    return -1;                                                              //Change (compiler)
}

// ================================================
// ============         MAIN     ==================
// ================================================
int main(){
    BinaryTree *TreeX = NULL;                                               //Our test Tree
    int i;                                                                  //Some counter

    printf("\n======= WELCOME TO BINARY TREE BY SOYOSCARRH ====\n\n\n");    //Some credit :p 

    /*
    //CREATE BY INORDER EXPRESSION
    char *a = "((1+(8*(1+2))-3)";                                              //Create a new Expression
    TreeX = CreateTreeFromInOrder(a, 1);                                    //Now create from Inorder and send 1 to show it
    printf("\n\n");                                                         //Now some space
    ShowInOrder(&TreeX);                                                    //Now show result
    printf("\n\n");                                                         //Now some space
    */

    /*
    //CREATE BY LEVEL
    Item* Data[10];                                                         //For do that we Need an Array of Items 
    for (i = 0; i < 10; ++i) Data[i] = CreateNewItem((i+'0'));              //So we create it
    TreeX = InsertByLevel(0, Data, 10);                                     //Now we create it sending 0, Data and Size
    ShowInOrder(&TreeX);                                                    //Show the actual tree
   

    //SHOW DEEPNESS
    int TreeDeepness = Deepness(&TreeX);                                    //Get the Deepness
    printf("\n\nDeepness :%i\n\n\n", TreeDeepness);                         //Show the deepness 

    //SHOW PATHS TO LEAFS 
    ShowPathsToLeafs(&TreeX);                                               //Show all the leafs
    */


    ///*
    //WORK IN A BTS
    char CharItem;          
    printf("Add elements to a BTS, we will stop when we see ' '\n");        //Menu

    while (1) {                                                             //Infinite bucle                                               
        scanf("%c%*c", &CharItem);                                          //Add a new item 
        if (CharItem == ' ') break;                                         //Selection
        InsertBTS(&TreeX, CreateNewItem(CharItem));                         //Insert 
    }


    printf("Showing Inorder: \n");                                          //Just showing
    ShowInOrder(&TreeX);                                                    //Just showing

    printf("\n\nShowing LeverOrder:\n");                                    //Just showing
    ShowLeverOrder(&TreeX);                                                 //Just showing


    printf("\n\n\n\n");                                                     //Just showing

    //*/

    
    
              


    return 0;
}



    








