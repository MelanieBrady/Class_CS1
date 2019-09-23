// Melanie Brady CS1 COP3502 MoWeFr 11:30-12:20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

char *readword(char word[]);

int main()
{
    int num;
    char word[SIZE];

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%s", word);
        printf("%s\n", readword(word));
    }

    return 0;
}

//remember to return pointer, always remember to use the pointer in the function [see with arrays]
//keep array[], compiler is expecting array that has already been allocated (static or dynamic), "callback", "synatic sugar"

char *readword(char word[])
{
    int ascii;
    bool curVowel = false, prevVowel = false;

    for (int i = 0; i < strlen(word); i++)
    {
        ascii = word[i];

        curVowel = (ascii == (int)'a' ||
                    ascii == (int)'e' ||
                    ascii == (int)'i' ||
                    ascii == (int)'o' ||
                    ascii == (int)'u');

        if (prevVowel)
        {
            ascii += 14;
        }
        else
        {
            ascii += 13;
        }

        prevVowel = curVowel;
        ascii = ascii > 122 ? (ascii % 123 + 97) : ascii;
        word[i] = (char)ascii;
    }
    return word;
}
