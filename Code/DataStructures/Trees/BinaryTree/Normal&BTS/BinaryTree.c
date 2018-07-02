
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++           BINARY TREE FUNTIONS FILE         ++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>                                                          //Library that we are going to use
#include <stdlib.h>                                                         //Library that we are going to use
#include <math.h>                                                           //Library that we are going to use
#include <string.h>                                                         //Library that we are going to use
#include "BinaryTree.h"                                                     //Our beloved Binary Tree
#include "Stack.h"                                                          //Our beloved Binary Tree
#include "Queue.h"                                                          //Our beloved Binary Tree

// ================================================
// ===      FUNTIONS FOR USING A AUX STACK      ===
// ================================================
StackItem* CreateStackItem(Node* SomeTreeNode){                             //=== IMPLEMENTATION OF CREATE ITEM ===
    StackItem *Temporal = (StackItem*) malloc(sizeof(StackItem));           //Reserve memory
    Temporal->TreeNode = SomeTreeNode;                                      //Store the pointer
    return Temporal;                                                        //You are complete, go, and protect the data
}

void ShowStackItem(StackItem *StackItemX){                                  //===  IMPLEMENTATION OF SHOW STACK ===
    ShowItem(StackItemX->TreeNode->NodeItem);                               //Call Node Tree Function
}

void ShowQueueItem(QueueItem *QueueItemX){                                  //YOU HAVE TO IMPLEMENT THIS
    ShowItem(QueueItemX->TreeNode->NodeItem);                               //Call Node Tree Function
}

QueueItem* CreateQueueItem(Node* SomeTreeNode){                             //YOU HAVE TO IMPLEMENT THIS
    QueueItem *Temporal = (QueueItem*) malloc(sizeof(QueueItem));           //Reserve memory
    Temporal->TreeNode = SomeTreeNode;                                      //Store the pointer
    return Temporal;                                                        //You are complete, go, and protect the data
}

/*==========================================================
============ FUNTIONS OF A BINARY TREE IN C    =============
==========================================================*/

// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==  BUT ESSENCIAL FOR MY IMPLEMENTATION  ==
// ===========================================
Node* CreateBinaryTree(Item *NewItem){                                      // ==== CREATE A NEW NODE OF A BINARY TREE ==
    Node *NewNode = (Node*) malloc(sizeof(Node));                           //Reserve memory for this node
    NewNode->NodeItem = NewItem;                                            //You will protect this info with your life
    NewNode->Left = NULL;                                                   //And maybe you're a leaf
    NewNode->Right = NULL;                                                  //And maybe you're a leaf
    return NewNode;                                                         //Go, go NewNode, you are complete :')
}

// ===========================================
// ==       ESSENCIAL BY DEFINITION         ==
// ===========================================
BinaryTree* InsertByLevel(int Index, Item **Data, int Size){                // ==== CREATE A TREE FROM AN ARRAY  OF ITEMS ==
    if (Index >= Size) return NULL;                                         //If you just get out of a Size get a Leaf

    BinaryTree *New = CreateBinaryTree(Data[Index]);                        //Create a New Binary Tree
    New->Left = InsertByLevel(2*Index + 1, Data, Size);                     //You know where are the next item
    New->Right = InsertByLevel(2*Index + 2, Data, Size);                    //You know where are the next item

    return New;                                                             //You are done, you are the Root
}

void EliminateTree(BinaryTree**TreeX){                                      // ==== DESTROY RECURSIBLE A TREE == 
    if (Root == NULL) return;                                               //We can't free a NULL, you know
    EliminateTree (PointerToLeftTree);                                      //Gooodbye Left subtree
    EliminateTree (PointerToRightTree);                                     //Gooodbye Left subtree
    free(TreeX);                                                            //With no sons I can not eliminate myself
}

void InsertBTS(BinaryTree **TreeX, Item *Data){                             // ==== INSERT IN A TREE LIKE IF IT WAS BTS ==
    if (Root == NULL) { Root = CreateBinaryTree(Data); return;}             //If you are leaf create it there

    int Comparator = CompareItems(Root->NodeItem, Data);                    //Now check to see where to move

    if (Comparator == 1)  InsertBTS(PointerToRightTree, Data);              //If we have to move because Data is bigger
    if (Comparator == -1) InsertBTS(PointerToLeftTree, Data);               //If we have to move because Data is smaller

    return;                                                                 //Now It's time to go back
}

BinaryTree* SearchItemBTS(BinaryTree **TreeX, Item *Data){
    if (Root == NULL) {free(Data); return NULL;}                            //NULL means fail D:

    int Comparator = CompareItems(Root->NodeItem, Data);                    //Now check to see where to move

    if (Comparator == 1) return SearchItemBTS(PointerToRightTree, Data);    //If we have to move because Data is bigger
    if (Comparator == -1) return SearchItemBTS(PointerToLeftTree, Data);    //If we have to move because Data is smaller

    free(Data);                                                             //Goodbye pointer
    return Root;                                                            //If you make this far it's mean you are correct
}

void DeleteItemBTS(BinaryTree **TreeX, Item *Data){                         // ==== DELETE IN A TREE LIKE IF IT WAS BTS ====
    if (Root == NULL) return;

    int Comparator = CompareItems(Root->NodeItem, Data);                    //Now check to see where to move

    if (Comparator == 1) return DeleteItemBTS(PointerToRightTree, Data);    //If we have to move because Data is bigger
    if (Comparator == -1) return DeleteItemBTS(PointerToLeftTree, Data);    //If we have to move because Data is smaller

    if (RightTree == NULL && LeftTree == NULL) {Root = NULL; return;}       //No sons mena nothign to preserve
    if (RightTree == NULL && LeftTree != NULL) {Root = LeftTree; return;}   //One son mean point to them
    if (RightTree != NULL && LeftTree == NULL) {Root = RightTree; return;}  //One son mean point to them

    BinaryTree *NewData = RightTree;                                         //This is maybe the new node
    while (NewData->Left != NULL) NewData = NewData->Left;                  //Get me the most right one

    Item *NewDataItem = NewData->NodeItem;
    DeleteItemBTS(TreeX, NewData->NodeItem);                                //Delete the original data with function
    Root->NodeItem = NewDataItem;
}
// ===========================================
// ==      NOT ESSENCIAL BY DEFINITION      ==
// ==       BUT JUST REALLY REALLY COOL     ==
// ===========================================
int Deepness(BinaryTree**TreeX){                                            // ==== DEEPNESS OF A TREE BY RECURSION == 
    if (Root == NULL) return 0;                                             //You know, leafs dont have leafs
    int DeepnessLeft = (Deepness(PointerToLeftTree)) + 1;                   //Calculate Left tree plues me
    int DeepnessRight = (Deepness(PointerToRightTree)) + 1;                 //Calculate Right tree plues me

    if (DeepnessLeft > DeepnessRight) return DeepnessLeft;                  //Choose it!, choose it!
    return DeepnessRight;                                                   //Default, just for the compiler
}


void ShowPreOrder(BinaryTree **TreeX){                                      // ==== SHOW PREORDER BY A BINARY TREE == 
    if(Root == NULL) {printf(" * "); return;}                               //if you are a NULL, sorry
    if (!(Root->Right) && !(Root->Left)){ShowItem(Root->NodeItem); return;} //if you are a leaf, we should stop here

    printf("< ");                                                           //Give some style
    ShowItem(Root->NodeItem);                                               //Show the current Item
    ShowPreOrder(PointerToLeftTree);                                        //Show the left subtree
    ShowPreOrder(PointerToRightTree);                                       //Show the right subtree
    printf("> ");                                                           //Give some style
}

void ShowInOrder(BinaryTree **TreeX){                                       // ==== SHOW INORDER BY A BINARY TREE == 
    if(Root == NULL) {printf(" * "); return;}                               //if you are a NULL, sorry
    if (!(Root->Right) && !(Root->Left)){ShowItem(Root->NodeItem); return;} //if you are a leaf, we should stop here

    printf("< ");                                                           //Give some style
    ShowInOrder(PointerToLeftTree);                                         //Show the left subtree
    ShowItem(Root->NodeItem);                                               //Show the current Item
    ShowInOrder(PointerToRightTree);                                        //Show the right subtree
    printf("> ");                                                           //Give some style
}

void ShowPostOrder(BinaryTree **TreeX){                                     // ==== SHOW POSTORDER BY A BINARY TREE == 
    if(Root == NULL) {printf(" * "); return;}                               //if you are a NULL, sorry
    if (!(Root->Right) && !(Root->Left)){ShowItem(Root->NodeItem); return;} //if you are a leaf, we should stop here

    printf("< ");                                                           //Give some style
    ShowPostOrder(PointerToLeftTree);                                       //Show the left subtree
    ShowPostOrder(PointerToRightTree);                                      //Show the right subtree
    ShowItem(Root->NodeItem);                                               //Show the current Item
    printf("> ");                                                           //Give some style
}

void ShowLeverOrder(BinaryTree **TreeX){                                    // ==== SHOW LEVEL ORDER OF A TREE == 
    if (Root == NULL) return;                                               //If there is nothign to show

    Queue* QueueX = CreateQueue();                                          //Create a Queue
    Enqueue(QueueX, CreateQueueItem(Root));                                 //Add to the Queue the empty root    
    int ItemInQeue = 1;                                                     //You shall have the number of items

    while(ItemInQeue > 0) {                                                 //While there are something in the Queue 
        Root = Dequeue(QueueX)->TreeNode;                                   //Fist give me the head

        ItemInQeue--;                                                       //Take notice little boy
        ShowItem(Root->NodeItem);                                           //Show the element

        if (LeftTree != NULL) {                                             //If you have a son
            Enqueue(QueueX, CreateQueueItem(Root->Left));                   //Add it
            ItemInQeue++;                                                   //Take notice little boy
        }  

        if (RightTree != NULL) {                                            //If you have a son
            Enqueue(QueueX, CreateQueueItem(Root->Right));                  //Add it!
            ItemInQeue++;                                                   //Take notice little boy
        }
    }
}


BinaryTree* CreateTreeFromInOrder(char *A, int ShowIt){                     // ==== CREATE EXPRESSION TREE FROM INORDER == 
    int i = 1, ItemsInStack = 1;                                            //HaTe that I can´t have internal int's in for's
    Node* Actual = CreateBinaryTree(NULL);                                  //Create a Empty Binary Tree
    Stack* StackX = CreateStack();                                          //Create a Stack
    Push(&StackX, CreateStackItem(Actual));                                 //Add to the Stack the empty root
    

    for (int i = 1; A[i] != '\0'; ++i){                                     //For Each Letter until the end    

        if ( A[i] == ' ' || A[i] == ')') continue;                          //Ignore this, humans have no standars

        if( A[i] == '('){                                                   //In case we have a ( : Create a New SubTree
            Node *NewNode = CreateBinaryTree(NULL);                         //I create a new subtree
            Node *ActualNode = Peek(&StackX)->TreeNode;                     //The stack top is my actual node
            if (ActualNode->Left == NULL) ActualNode->Left = NewNode;       //Add it here
            else ActualNode->Right = NewNode;                               //If not, add it here

            Push(&StackX, CreateStackItem(NewNode));                        //Now Actual Node it the one we have jsut create it
            ItemsInStack++;                                                 //Add to counter
        }
        else if (A[i]=='+'||A[i]=='-'||A[i]=='*'||A[i]=='/'||A[i]=='^'){    //If we see an Operator
            Peek(&StackX)->TreeNode->NodeItem = CreateNewItem(A[i]);        //Set Actual Node value to the Operator
        } 
        else {
            Node* NewNode = CreateBinaryTree(CreateNewItem(A[i]));          //If we see a Number or Variable
            Node *ActualNode = Peek(&StackX)->TreeNode;                     //Some temporal variable just because I have write
            if (ActualNode->Left == NULL) ActualNode->Left = NewNode;       //If you have nothing as childs, put it here
            else {                                                          //if we have to put it on a Right Node
                ActualNode->Right = NewNode;                                //Set it!
                do { 
                    ItemsInStack--;                                         //Please remove the ItemInStack
                    if (ItemsInStack == 0) break;                           //If we have no Items in Stack, go out!
                    Pop(&StackX);                                           //Remove Item from a Stack
                }
                while (Peek(&StackX)->TreeNode->NodeItem != NULL);          //If we are at a not Null Item, pop it out!
            }
        }
        if (ShowIt != 0){ printf("\n%c: ", A[i]); ShowInOrder(&Actual);}    //If you want to see step by step
    }
    return Actual;                                                          //Return the original Root
}

void PathsLeafsInternal(BinaryTree **TreeX, Stack **StackX){                // ==== SHOW PATHS OF A BINARY TREE == 
    if (Root == NULL) return;                                               //If empty, out!
    Push(StackX, CreateStackItem(Root));                                    //Add to the Stack the empty root

    if (RightTree == NULL && LeftTree == NULL){                             //If you are a Leaf    
        ShowInverseStack(StackX);                                           //Show all the info
        printf("\n\n\n");                                                   //Let a space
        Pop(StackX);                                                        //Get out!
        return;                                                             //Go out!
    }

    PathsLeafsInternal(PointerToLeftTree, StackX);                          //Calculate Left tree
    PathsLeafsInternal(PointerToRightTree, StackX);                         //Calculate Right tree

    Pop(StackX);                                                            //Get out!
}
void ShowPathsToLeafs(BinaryTree **TreeX){                                  // ==== SHOW PATHS OF A BINARY TREE == 
    Stack* StackX = CreateStack();                                          //Create a Stack
    PathsLeafsInternal(TreeX, &StackX);
}




