/* Dynamic Memory Review
 malloc, calloc, realloc, freE

 Types of Error: 
 -OoB - Out of Bounds 
    int array [10]; 
        err [100]; or err[10] (not enough room for null), err [-1]; (undefined behavior); 

-Dereference bad memory: 
    pasing a char into 
    reference implies using an &, going from an address to a value, 
    deref -> *x; x[0]; //both are dereferencing
    *(x+1) same as x[1];
    *(x+i) same as x[i];

    int x; 
    *(x) //undefined behavior

- Use after free
    most dangerous of the bugs, least obvious
    null pointer 
    have something point to null, then have something reference the terminator, then it just dies

- Double free 
    free it twice 

-Free static memory 
    static int x[10]
    int *x only free
    x = int* calloc(#values, sizeof(int))
         cast - optional           full with 0


https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

What discussed dynamic memory function 
returns memory initialized byte-wise with zeros?

calloc - initialized with byte zeros
realloc - initialized with previous memory

What does the calloc return when allocation of memory fails? 
NULL Pointer
