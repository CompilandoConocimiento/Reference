
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++           AVL TREE FUNTIONS FILE         ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                                              //Library that we are going to use
#include <stdlib.h>                                                             //Library that we are going to use
#include <math.h>                                                               //Library that we are going to use
#include <string.h>                                                             //Library that we are going to use
#include "AVLTree.h"                                                            //Our beloved Binary AVL Tree


/*==========================================================
============ FUNTIONS OF A AVL TREE TREE IN C    ===========
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
AVLTree* CreateAVLTree(Item *NewItem){                                          // ==== CREATE A NEW NODE OF A AVL TREE ==
    AVLTreeNode *NewNode = (AVLTreeNode*) malloc(sizeof(AVLTreeNode));          //Reserve memory for this node
    NewNode->NodeItem = NewItem;                                                //You will protect this info with your life
    NewNode->Height = 1;                                                        //The Height of the node
    NewNode->Left = NewNode->Right = NULL;                                      //And maybe you're a leaf
    return NewNode;                                                             //Go, go NewNode, you are complete :')
}
    
// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
AVLTree* SearchItemAVL(AVLTree *AVLTreeX, Item *Data){                          // ==== SEARCH IN A BALANCE TREE ===============
    if (AVLTreeX == NULL) {free(Data); return NULL;}                            //NULL means fail D:

    int Comparator = CompareItems(AVLTreeX->NodeItem, Data);                    //Now check to see where to move
    if (Comparator == 1) return SearchItemAVL(AVLTreeX->Left, Data);            //If we have to move because Data is bigger
    if (Comparator == -1) return SearchItemAVL(AVLTreeX->Right, Data);          //If we have to move because Data is smaller

    free(Data);                                                                 //Goodbye pointer, it means you found it!
    return AVLTreeX;                                                            //If you make this far it's mean you are correct
}

// =================================
// ==     THE BALANCE PART        ==
// =================================
int Max(int a, int b){                                                          // ==== AUXILIAR FUNCTION ===================== 
    if (a > b) return a;                                                        //How this function is not implemented yet
    return b;                                                                   //How this function is not implemented yet
}

int Deepness(AVLTree *AVLTreeX){                                                // ==== DEEPNESS OF A TREE BY RECURSION ======= 
    if (AVLTreeX == NULL) return 0;                                             //You know, leafs dont have leafs
    int DeepnessLeft = (Deepness(AVLTreeX->Left)) + 1;                          //Calculate Left tree plus me
    int DeepnessRight = (Deepness(AVLTreeX->Right)) + 1;                        //Calculate Right tree plus me

    if (DeepnessLeft > DeepnessRight) return DeepnessLeft;                      //Choose it!, choose it!
    return DeepnessRight;                                                       //Default, just for the compiler
}

int GetHeight(AVLTree *AVLTreeX){                                               // ==== SECURE WAY TO GET THE HEIGHT ========== 
    if (AVLTreeX == NULL) return 0;                                             //If we have an error
    return AVLTreeX->Height;                                                    //If not, just do nothing
}

int GetBalance(AVLTree *AVLTreeX){                                              // ==== SECURE WAY TO GET THE HEIGHT ========== 
    if (AVLTreeX == NULL) return 0;                                             //If you are nothing
    return GetHeight(AVLTreeX->Left) - GetHeight(AVLTreeX->Right);              //This is the definition
}

/*  ================   GENERAL REPRESENTATION    ==========
    ============    THIS IS WHAT IM DOING       ===========
    ==                                                   ==
    ==        Y                               X          ==
    ==       / \     Right Rotation -->      /  \        ==
    ==      X   T3   <-- Left Rotation      T1   Y       ==
    ==     / \                                  / \      ==
    ==    T1  T2                              T2  T3     ==
    =====================================================*/



/*  ================   REPRESENTATION    ==================
    ============    THIS IS WHAT IM DOING       ===========
    ==                                                   ==
    ==        Z                               Y          ==
    ==       / \     Right Rotation -->     /  \         ==
    ==      Y   T4                         X    Z        ==
    ==     / \                            / \  / \       ==
    ==    X  T3                         T1 T2 T3 T4      ==
    ==   / \                                             ==
    ==  T1  T2                                           ==
    =====================================================*/
AVLTree* RightRotate(AVLTree *Z){                                               // ==== RIGHT ROTATE  ========================= 
    AVLTree *Y  = Z->Left;                                                      //Temporal Node
    AVLTree *X  = Y->Left;                                                      //Temporal Node
    AVLTree *T3 = Y->Right;                                                     //Temporal Node

    Y->Right = Z;                                                               //Perform Rotation
    Z->Left = T3;                                                               //Perform Rotation

    Z->Height = Max(GetHeight(Z->Left), GetHeight(Z->Right))+1;                 //Update Height
    Y->Height = Max(GetHeight(Y->Left), GetHeight(Y->Right))+1;                 //Update Height
 
    return Y;                                                                   //Return the new Root
}

/*  ================   REPRESENTATION    ==================
    ============    THIS IS WHAT IM DOING       ===========
    ============   ALSO KNOW LIKE: LEFT LEFT    ===========
    ==                                                   ==
    ==         X                               Y         ==
    ==        / \     <-- Left Rotation      /  \        ==
    ==       T1  Y                         X    Z        ==
    ==          / \                       / \  / \       ==
    ==         T2  Z                    T1 T2 T3 T4      ==
    ==            / \                                    ==
    ==           T3  T4                                  ==
    =====================================================*/
AVLTree* LeftRotate(AVLTree *X){                                                // ==== LEFT ROTATE   ========================= 
    AVLTree *Y  = X->Right;                                                     //Temporal Node
    AVLTree *Z  = Y->Right;                                                     //Temporal Node
    AVLTree *T2 = Y->Left;                                                      //Temporal Node

    X->Right = T2;                                                              //Perform Rotation
    Y->Left  = X;                                                               //Perform Rotation

    X->Height = Max(GetHeight(X->Left), GetHeight(X->Right))+1;                 //Update Height
    Y->Height = Max(GetHeight(Y->Left), GetHeight(Y->Right))+1;                 //Update Height
 
    return Y;                                                                   //Return the new Root
}

/*  ================   REPRESENTATION    ==================
    ============   ALSO KNOW LIKE: RIGHT LEFT    ==========
    ==                                                   ==
    ==         X                               Y         ==
    ==        / \   Right Left Rotation -->  /  \        ==
    ==       T1  Z                         X    Z        ==
    ==          / \                       / \  / \       ==
    ==         Y   T4                   T1 T2 T3 T4      ==
    ==       / \                                         ==
    ==      T2  T3                                       ==
    =====================================================*/
AVLTree* RightLeftRotate(AVLTree *X){                                           // ==== RIGHT LEFT ROTATE   ==== ============= 
    AVLTree *Z  = X->Right;                                                     //Temporal Node
    AVLTree *Y  = Z->Left;                                                      //Temporal Node
    AVLTree *T2 = Y->Left;                                                      //Temporal Node
    AVLTree *T3 = Y->Right;                                                     //Temporal Node

    Y->Left  = X;                                                               //Perform Rotation
    Y->Right = Z;                                                               //Perform Rotation
    X->Right = T2;                                                              //Perform Rotation
    Z->Left  = T3;                                                              //Perform Rotation

    X->Height = Max(GetHeight(X->Left), GetHeight(X->Right))+1;                 //Update Height
    Z->Height = Max(GetHeight(Z->Left), GetHeight(Z->Right))+1;                 //Update Height
    Y->Height = Max(GetHeight(Y->Left), GetHeight(Y->Right))+1;                 //Update Height

    return Y;                                                                   //Return the new Root
}


/*  ================   REPRESENTATION    ==================
    ============    THIS IS WHAT IM DOING       ===========
    ============   ALSO KNOW LIKE: LEFT RIGHT    ==========
    ==                                                   ==
    ==         Z                               Y         ==
    ==        / \   Left Right Rotation -->  /  \        ==
    ==       X   T4                         X    Z       ==
    ==      / \                            / \  / \      ==
    ==     T1 Y                          T1 T2 T3 T4     ==
    ==       / \                                         ==
    ==      T2  T3                                       ==
    =====================================================*/
AVLTree* LeftRightRotate(AVLTree *Z){                                           // ==== LEFT RIGHT ROTATE   =================== 
    AVLTree *X  = Z->Left;                                                      //Temporal Node
    AVLTree *Y  = X->Right;                                                     //Temporal Node
    AVLTree *T2 = Y->Left;                                                      //Temporal Node
    AVLTree *T3 = Y->Right;                                                     //Temporal Node

    Y->Left  = X;                                                               //Perform Rotation
    Y->Right = Z;                                                               //Perform Rotation
    X->Right = T2;                                                              //Perform Rotation
    Z->Left  = T3;                                                              //Perform Rotation

    X->Height = Max(GetHeight(X->Left), GetHeight(X->Right))+1;                 //Update Height
    Z->Height = Max(GetHeight(Z->Left), GetHeight(Z->Right))+1;                 //Update Height
    Y->Height = Max(GetHeight(Y->Left), GetHeight(Y->Right))+1;                 //Update Height

    return Y;                                                                   //Return the new Root
}


void InsertInAVL(AVLTree **AVLTreeX, Item *Data){                               // ==== INSERT IN A BALANCE TREE ============== 
    if (AVLRoot == NULL) {AVLRoot = CreateAVLTree(Data); return;}               //If null tree

    int Comparator = CompareItems(AVLRoot->NodeItem, Data);                     //Now check to see where to move
    if (Comparator == 1) InsertInAVL(GoRightAVLSubTree, Data);                  //If we have to move because Data is bigger
    else if (Comparator == -1) InsertInAVL(GoLeftAVLSubTree, Data);             //If we have to move because Data is smaller
    else return;                                                                //Return all like anything


    AVLRoot->Height=1+Max(GetHeight(AVLRoot->Left),GetHeight(AVLRoot->Right));  //Update the Height   
    int Balance = GetBalance(AVLRoot);                                          //Now get me the Balance

    if (Balance > 1){                                                           //If we are not balance
        Comparator = CompareItems(AVLRoot->Left->NodeItem, Data);               //Tell me, where is the problem
        if (Comparator == -1) AVLRoot = RightRotate(AVLRoot);                   // Left Right Case
        if (Comparator ==  1) AVLRoot = LeftRightRotate(AVLRoot);               // Right Right Case
    }
    if (Balance < -1){                                                          //If we are not balance
        Comparator = CompareItems(AVLRoot->Right->NodeItem, Data);              //Tell me, where is the problem
        if (Comparator ==  1) AVLRoot = LeftRotate(AVLRoot);                    // Right Left Case
        if (Comparator == -1) AVLRoot = RightLeftRotate(AVLRoot);               // Left Left Case
    }
}

void DeleteInAVL(AVLTree **AVLTreeX, Item *Data){

    if (AVLRoot == NULL) {AVLRoot = CreateAVLTree(Data); return;}               //If null tree

    int Comparator = CompareItems(AVLRoot->NodeItem, Data);                     //Now check to see where to move
    if (Comparator == 1) DeleteInAVL(GoRightAVLSubTree, Data);                  //If we have to move because Data is bigger
    else if (Comparator == -1) DeleteInAVL(GoLeftAVLSubTree, Data);             //If we have to move because Data is smaller
    else {                                                                      //We found John Connor
        if ((AVLRoot->Left == NULL) || (AVLRoot->Right == NULL)){               //Node with only one child or no child
            AVLTree *Temporal;                                                  //Temporal is cool
            if (AVLRoot->Left != NULL) Temporal = AVLRoot->Left;                //Put me in the child
            else Temporal = AVLRoot->Right;                                     //Put me in the child
 
             if (Temporal == NULL){                                             //If you cant find a child
                Temporal = AVLRoot;                                             //Save the value
                AVLRoot = NULL;                                                 //Goodbye tree
            }                       
            else AVLRoot = Temporal;                                            //Else 1 Child: Save the info of the child
            free(Temporal);                                                     //Goodbye
        }
        else{                                                                   //Node with 2 Children: Get the inorder
            AVLTree *NewData = AVLRoot->Right;                                  //This is maybe the new node
            while (NewData->Left != NULL) NewData = NewData->Left;              //Get me the most right one

            AVLRoot->NodeItem = NewData->NodeItem;                              //Save the Data
            DeleteInAVL(GoRightAVLSubTree, NewData->NodeItem);                  //Remove the original
        }
    }
 
    if (AVLRoot == NULL) return;                                                //If the tree had only one node then return

    AVLRoot->Height=1+Max(GetHeight(AVLRoot->Left),GetHeight(AVLRoot->Right));  //Update the Height   
    int Balance = GetBalance(AVLRoot);                                          //Now get me the Balance
 
    if (Balance > 1){                                                           //If we are not balance
        if (GetBalance(AVLRoot->Left) >= 0) AVLRoot = RightRotate(AVLRoot);     //Right Case
        if (GetBalance(AVLRoot->Left) <  0) AVLRoot = LeftRightRotate(AVLRoot); //LeftRight Case
    }
    if (Balance < -1){                                                          //If we are not balance
        if (GetBalance(AVLRoot->Right) <= 0) AVLRoot = LeftRotate(AVLRoot);     //Left Case
        if (GetBalance(AVLRoot->Right) > 0) AVLRoot = RightLeftRotate(AVLRoot); //RightLeft Case
    }
}



// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
void ShowInOrder(AVLTree *AVLTreeX){                                            // ==== SHOW INORDER BY A AVL TREE == 
    if (AVLTreeX == NULL) {printf(" * "); return;}                              //If you are a NULL, sorry
    if (!(AVLTreeX->Right) && !(AVLTreeX->Left))                                //If you are a leaf
        {ShowItem(AVLTreeX->NodeItem); return;}                                 //We should stop here

    printf("< ");                                                               //Give some style
    ShowInOrder(AVLTreeX->Left);                                                //Show the left subtree
    ShowItem(AVLTreeX->NodeItem);                                               //Show the current Item
    ShowInOrder(AVLTreeX->Right);                                               //Show the right subtree
    printf("> ");                                                               //Give some style
}
