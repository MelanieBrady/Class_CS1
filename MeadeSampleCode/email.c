// Melanie Brady 08/30/2019 COP 3502C
// So, this is the email2 example posted! I am uploading this so I can recieve financial aid. I will resubmit my code later. Thank you.  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 100

void readAndFix();
void transform(char * word);
int main()
{
   int numEmails, i;
   
   // Read in the number of emails
   scanf("%d", &numEmails);
   
   // Handle each email by looping
   for (i = 0; i < numEmails; i++)
   {
      // Read in email and fix it
      readAndFix();
   }
   
   // Return 0 to signify successful execution
   return 0;
}

void readAndFix()
{
   int numWords, i;
   char theWord[WORD_SIZE + 1]; // Plus one for null terminator
   
   // Read number of words
   scanf("%d", &numWords);
   
   // Handle each word
   for (i = 0; i < numWords; i++)
   {
      // Read, modify, and print the word
      scanf("%s", theWord);
      transform(theWord);
      printf("%s ", theWord);
   }
   
   // Put each email on their own line
   printf("\n");
}

void transform(char * word)
{
   int i;
   int numericValue;
   
   // Loop through each letter
   for (i = 0; i < strlen(word); i++)
   {
      // Check if lower case
      if (word[i] <= 'z' && word[i] >= 'a')
      {
         numericValue = word[i] - 'a';
         word[i] = numericValue + 'A';
      }
      
      // Check if upper case
      else if (word[i] <= 'Z' && word[i] >= 'A')
      {
         numericValue = word[i] - 'A';
         word[i] = numericValue + 'a';
      }
   }
}