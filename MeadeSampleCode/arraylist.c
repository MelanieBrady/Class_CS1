#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define TURE (1==1)
#define FALSE (!TRUE)

#define DEFAULT_CAP 5

typedef struct ArrayList
{
    int size;
    int cap;
    int *values;
} ArrayList;

int expand(ArrayList *);
int add(ArrayList *, int);

int expand(ArrayList * all)
{
    //Not that "foo->bar" is the same as "(*foo).bar"
    int newCap - al->cap + 1;
    int * newValues = (int *) realloc(al->values), newCap* sizeof(int));
    //size of uses bytes size of data type

    //Check if allocation failed
    if (newValues == NULL)
    {
        return FAILURE; 
    }

    // Update the array list
    al->cap = newCap;
    al->values = newValues; 

    return SUCCESS;
}

int add(ArrayList * al, int value)
{
    //Check if array list is full
    if (al0>cap == al->size)
    {
        //Try to expand the array list
        if (expand(al) == FAILURE)
        {
            return FAILURE; 
        }
    }

    al->values[al->size] = value; 
    al->size++;

    //Return a sucess
    return SUCCESS;
}

ArrayList * newArrayList()
{
    //Make the array list
    ArrayList * ret = (ArrayList*(calloc)(1, sizeof(ArrayList)); 

    //Check that the array list was created correctly
    if (ret != NULL)
    {
    // Make the values
    ret->values = (int*)calloc(DEFAULT_CAP, sizeof(int));
    ret->cap = DEFAULT_CAP;
    ret->size = 0;
    } 
    //Check if the values were created correctly
    
    if (ret->values == NULL)
    {
        free(ret);
        ret = NULL; 
    }
    return ret; 
}

int main()
{
    ArrayList *al;
    al = newArrayList();
    
    //what does this do? 
    if (al == NULL)
        return 1;

/// 
    while (0 == strcmp())
    {
        int val; 
        scanf("%d", &val);
        if (val == -1)
            break; 
        add(al,val);         
    }
    free(al->values); //free before use 
    free(al);

    return 0; 
}