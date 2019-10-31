/*CS1 - Practice Test 1 - Problem 8: You are building a pyramid of wooden blocks.  
The cross section of each layer is a square of wooden blocks. 
The length of each layer is one less than the previous layer (with the base layer as the only exception). 
You are given the length of the base of the pyramids in block length. 
Your objective is to write a recursive program that determines how many blocks are in the entire pyramid.
As an example the result of blockCount(3) returns 14, and blockCount(1) returns 1. */

#include <stdio.h>
#include <stdlib.h>

int blockCount(int baseLength);

int main () {
    int baseLength;
    scanf("%d", &baseLength);

    printf("\nTotal Blocks: %d ", blockCount(baseLength));

    return 0; 
}

int blockCount(int baseLength) {
    if (baseLength == 0) {
        return baseLength;
    }
   // printf("\nBlockCount: %d", baseLength);
    return blockCount(baseLength - 1) + baseLength*baseLength;      
}