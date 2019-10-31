//will be on the exam: 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100 + 1]; //"arup"
    char init;
    scanf("%s", str);
    scanf(" "); //removes whitespace to the next non-white space character
    scanf("%c", &init);


    strcat(str, " ");  
    char buf[2];
    buf[0] = init;
    buf[1] = '/0'; // (typically byte code is 0, but do not do this: buf [1] = 0;)
    strcat(str, init); //it is for strings, not characters white init was a character
    strcmp(a, b);
    //a should come first alphabetically
    //0 = equal
    // < 0 a should core l
    //a - b rather than a compared to be 
    
    printf("\"%s %c\"", str, init);

    return 0;
}