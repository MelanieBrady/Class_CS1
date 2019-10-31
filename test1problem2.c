#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeSort(int start, int end, int *numBox)
{
    int mid = (start + end) / 2; //this mid vs ()
    // mid = low + (high - end) / 2

    //Re-adjust pointers 
    //frontPter= low to start looking for lower range
    //Mid+1 look at upper range 
    //K index for temp array, mergedPter = 0; 
    int frontPtr = start;   // low 
    int backPtr = mid + 1;  //pointer to the middle - not sure if back
    int mergedPtr = 0;      //merged pointer? why start zero

    printf("frontPtr: %d backPtr: %d mergedPtr: %d\n", frontPtr, backPtr, mergedPtr); 

    //New temp array to create the shuffled values
    int vals[end - start + 1];

    if (start == end) {
        // printf("Start equals end");
            return;
        }
    //printf("%d %d\n", start, end);
    mergeSort(start, mid, numBox);
    mergeSort(mid + 1, end, numBox);

    //Checks if both start and end are the same? idk how this works 
    
    //while mergedptr (which should be assigned to zero initially)
    //WAIT! END AND START ARE DIFFERENT THEN THEIR POINTERS AHHHHH
    

    while (mergedPtr <= end - start)
    {
        //So if Front is not s has made it to the frontPtr has made it to backPtr
        //Or backPtr is not the end & 
        //If numBox[frontPtr ]> numBox[backPtr]
        // if the number at the first arrayptr is greater than the number at the

        //if low is equal to mid + 1 || mid + 1 is not at the end & num[lowi] > num[mid+1]
            //then place it in mergedptr index, then countone! i didn't know you can do that! 
            //I think the issue is in here V but I don't know how/why 
        if (frontPtr == mid + 1 || (backPtr != end + 1 && numBox[frontPtr] > numBox[backPtr]))
            vals[mergedPtr++] = numBox[backPtr++];
        
        else //if not ^ then still increment mergedPtr index+ still,  
            vals[mergedPtr++] = numBox[frontPtr++];
    }

    // changed i to start 
    //Inserts back into the new array 
    for (int i = start; i <= end; i++)
        numBox[i] = vals[i - start]; // - start
}

int main () {
    int numBox[] = {4, 8, 13, 7, 32, 1, 1};
    int n = 7;
    mergeSort(0, n, numBox);

    for(int i = 0; i <  n; i++) {
        printf("%d ", numBox[i]);
    }
    printf("\n");
    //passing in start is low, end is high, 
    //What is the end and start you pass through to the function? 
    //mergeSort(start, end, *numBox)
    

    // what happens with redundancy? 
}
