# STACKS USINGS LINKED LISTS

Here you have to your disposal  this code that implements in C a Stack using as a base a Linked List,
So... here are some rules:

* **Stack.h**: Is the name of all the Funtions that we are going to use to control a Stack and sadly the type of item of the stack

* **Stack.c**: Is the file where I implement all the funtion that are the same not caring about what an item is, these are the same for every type of stack

* **TheOtherFile.c**: Is where first I implement the funtions that need to know what an item is , these are different for every type of stack

So.. For you to excecute the code yoy have to do something like this:

```{r, engine='bash', count_lines}
gcc CheckStack.c Stack.c && clear && ./a.out
```

* * *

## How to use it
To create over this list you have to implement some funtions that I use to create the most generic code possible:

* **Change** what an Item is to store all your data to list
* **Implement ShowItem()**: This simple should have to show an item using a pointer as input
* **Implement CreateItem()**: This simple should have to create a pointer to an item
* **Implement CompareItems()**: This should return 1 if 2 pointer to item are equal to you, else return 0


* * *

# VISUAL REPRESENTATION

We begin with Stack empty:

.....
Stack
Now, let's perform Push(Stack, X), giving:

.....
| X |  <-- Top
.....
Stack

Again, another push operation, Push(Stack, Y), giving:

.....
| Y |  <-- Top
.....
| X |
.....
Stack

Now let's remove an item, Bottom = Pop(Stack), giving:

.....              .....
| X |  <-- Top     | Y |
.....              .....
Stack              Bottom


And finally, one more addition, Push(Stack, Z), giving:

.....
| Z |  <-- Top
.....
| X |
.....
Stack


With all my love
0.



