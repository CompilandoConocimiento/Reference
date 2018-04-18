# Linked Lists

Here you have to your disposal all of these codes for you to use them and create something amazing, so... 
This is a general guide for all types os Linekd Lists.
All have this in common:

* Something+**LinkedList.h**: The declaration of Item and Prototypes of Functions
* Something+**LinkedList.c**: My implementation of these functions
* **Check**Something+**LinkedList.c** : A simple *complete* implementation to check that all is OK

So.. For you to excecute the code yoy have to do something like this:

```{r, engine='bash', count_lines}
gcc CheckLinkedList.c LinkedList.c && clear && ./a.out
```

* * *
## How to use it
To create over this list you have to implement some funtions that I use to create the most generic code possible:

* **Change** what an Item is to store all your data to list
* **Implement ShowItem()**: This simple should have to show an item using a pointer as input
* **Implement CreateItem()**: This simple should have to create a pointer to an item
* **Implement CompareItems()**: This should return 0 if 2 pointer to item are equal to you, else return 1 if A is big o -1 if B is Big


* * *
## Somethings to make coding a little bit easier
In orden to make this more friendly to read and code I have this redefintions:

```#define Head (*ListX)```

```#define GoNextNode CurrentNode=CurrentNode->Next```

```#define GoPrevNode CurrentNode=CurrentNode->Prev```

```#define NextNode CurrentNode->Next```

```#define PrevNode CurrentNode->Prev```


Now please, go my beloved friends
0.
