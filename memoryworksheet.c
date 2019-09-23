#include <stdio.h>
#include <stdlib.h>

struct author_t
{
    char name[20]; 
    int birthYear;
    int publishings;
}

struct book_t
{
    char name[20];
    int year;
    int numAuthors;
    author_t* authors; 
}

int main ()
{

    scanf("%d", n);


    return 0;
}