/* 
Assignment 4: A New Order
-Scan in "alphabet" with whitespace 26 letters
-Scan in how many names
-scan in each names
-sort each names
-output sorted names according to alphabet
*/

#include <stdio.h>
#include <stdlib.h> 

#define QTY_LETTERS 26
#define MAX_NAME_LENGTH 100

//void storeNames(int qtynames); 
//void sortNames;

int main () {
    int qtynames = 0; 

    // Best way to scan and store the alphabet array? 
    printf("What's the order? ");
    char alphabet[200];
    scanf("%[^\n]%*c", alphabet);
    // 
    // https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    // https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/
    // that's how you remove the spacing 
    //%[^\n] scans whitespace! 
    // fgets (alphabet, 100, stdin); 100 max buffer length 
    //"%s[^x]s" scans in without worry of whtiespace
    
    printf("\nPrintf String: %s", alphabet);

    //Handles looping & storing the names
    printf("How many names? ");
    scanf("%d", qtynames);
   // storeNames(qtynames);

    // for (int i = 0; i < QTY_LETTERS; i++) {
    //     printf("%c ", alphabet[i]); 
    // }

    return 0;
}

//This function handles the loop and storing names
// void storeNames(int qtynames) {
//     for (i = 0; i < qtynames; i++) {
//         //each contain a single name as a lowercase string of at most 100 lowercase letters with no whitespace
//     }
// }
