#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0
#define TRUE (1==1)
#define FALSE (!TRUE)

#define ADD_STR "ADD"
#define END_STR "END"

#define DEFAULT_CAP 5

void checkIfSymptomExists();
void addStudenttoSymptom();
void update();
void query(); 
// #define Max_Cap

    // Uppercase for structs, but variables be lower case 

typedef struct Name
{
    char *name; // just a string
} Name;

typedef struct ArrayList
{
    Name *argh; //array of names //arr = argh
    int size, cap; //how many names you have in your array & caps is total max
} ArrayList;

typedef struct FullList
{
    ArrayList *aol; //array of (array)lists
    int size, cap;
} FullList;


int main () {

    Name *names = malloc(10*sizeof(Name)); // initialize pointer array
    //malloc to bigger than 1 it becomes an array
    for (int i = 0; i < 10; i++) {
        names[i].name = "Matthews";
        printf("%s\n", names[i].name);
    }

    ArrayList *arrayList = malloc(1*sizeof(ArrayList)); 

    arrayList->argh = names; //you could do this

    // arrayList->argh = malloc(10*sizeof(Name));
    // //arrayList is pointing to argh & argh is struct Name  
    //arrayList->argh think of it like a variable

    // for(int i = 0; i < 10; i++) {
    //     arrayList->argh[i] = "Matthews";
    //     printf("%s", arraylist->argh[i]);
    // }

    FullList *fullList = malloc(1*sizeof(FullList));
    fullList->aol = arrayList; 

    for (int i = 0; i < 10; i++) {
    printf("%s\n", fullList->aol->argh[i]);
    }


    // myName->str = "Matthew"; 
    // printf("%s\n", myName->str); 

}