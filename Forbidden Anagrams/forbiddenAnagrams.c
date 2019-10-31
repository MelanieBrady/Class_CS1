/* Melanie Brady - COP 3502C - MoWeFr 11:30a 
Assignment 3: Forbidden Anagrams
-Scan in phrase
-Scan and store BadWords ("bad substrings")
-Create all permutations without repetition
-Increment count of good words
-Print out total of good words */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 12

// Globals so I don't have to pass them function to function
char *phrase, **badWords;
int safeWords, numBadWords;

void storeBadWords(int numBadWords);
void permutations(char *phrase, int left, int right);
int compareLetters(char *phrase, int left, int current);
void swapLetters(char *phrase, int i, int j);

int main()
{
    safeWords = 0;

    //Statically allocating tempPhrase as a "buffer"
    char tempPhrase[MAX_STRING + 1];
    scanf("%s", tempPhrase);

    //Dynamically allocating phrase from tempPhrase, then copying over
    //Using a buffer because it's less intensive then malloc then reallocing several times
    int phraseSize = strlen(tempPhrase);
    phrase = (char *)malloc((phraseSize + 1) * (sizeof(char *)));
    strncpy(phrase, tempPhrase, phraseSize + 1);

    //Scan then function call to store bad substrings
    scanf("%d", &numBadWords);
    storeBadWords(numBadWords);

    //Creates and calculates all of the good permutations
    permutations(phrase, 0, phraseSize - 1);
    printf("%d", safeWords);

    //Free for every malloc! :D
    for (int i = 0; i < numBadWords; i++) {
        free(badWords[i]);
    }
    free(badWords);
    free(phrase);

    return 0;
}


//Allocates and stores each bad word.
void storeBadWords(int numBadWords)
{
    badWords = (char **)malloc((numBadWords) * (sizeof(char *)));
    char buffer[MAX_STRING + 1];

    //Puts each word into a buffer, mallocs exact room for word at each index, then copies over to badWords
    for (int i = 0; i < numBadWords; i++)
    {
        scanf("%s", buffer);
        int bufferLength = strlen(buffer);
        badWords[i] = (char *)malloc((bufferLength + 1)*sizeof(char *));
        strncpy(badWords[i], buffer, bufferLength + 1);
    }
    return;
}

void permutations(char *phrase, int left, int right)
{
    int naughtyWord = 1;

    //Base case so check if the badword is a substring of the permutation
    if (left >= right)
    {
        for (int i = 0; i < numBadWords; i++)
        {
            //strstr returns the substring if it is a part of the permutation.
            //If it's not, then it returns a NULL pointer.
            if (strstr(phrase, badWords[i]) != NULL)
            {
                naughtyWord = 0;
            }
        }

        //If it left the for loop unchanged, then no bad words were used for this permutation! YAY!
        if (naughtyWord == 1)
        {
            safeWords++;
        }
        
        return;
    }

    for (int i = left; i <= right; i++)
    {
        //If different letters then recursively create the permutations
        if (compareLetters(phrase, left, i))
        {
            swapLetters(phrase, left, i);
            permutations(phrase, left + 1, right);
            swapLetters(phrase, left, i);
        }
    }
}

//Prevents redundancies. Checks "a" == "a" so it's not double counted
int compareLetters(char *phrase, int left, int current)
{
    for (int i = left; i < current; i++)
    {
        // Same so it would be redundant - Don't do it!
        if (phrase[i] == phrase[current])
        {
            return 0;
        }
    }
    //Otherwise different, so continue!
    return 1;
}

//Swaps the letters based on given indecies
void swapLetters(char *phrase, int i, int j)
{
    char temp = phrase[i];
    phrase[i] = phrase[j];
    phrase[j] = temp;
}
