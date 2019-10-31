// CS1 Notes on Strings 8/26/2019
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //library for strings

int main()
{
    int x;
    char variableName[100 + 1]; //+1 for null terminator
    //& means memory address - passing location of storage - rather than passing value
    scanf("%s", variableName);

    //Strings stop at white space, can't read _ stack smash when there's not enough room, 
    //cannot modify the value of x
    printf("The number you entered is %s\n", variableName);
    printf("The length of the string is %d\n", strlen(variableName));
    return 0;
} 