#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTY_LETTERS 26
#define MAX_NAMES 100000
#define MAX_NAME_LENGTH 100

char alphabet[QTY_LETTERS];
char namesList[MAX_NAMES][MAX_NAME_LENGTH + 1], helper[MAX_NAMES][MAX_NAME_LENGTH + 1];
int qtynames, newPriority[QTY_LETTERS];

void createNewOrder();
void getNames();
void outputNames();
void mergeSortNames(int low, int high);
void mergeNames(int low, int middle, int high);
int compareLetters(char *wordLeft, char *wordRight);

int main()
{
  createNewOrder();
  getNames();
  mergeSortNames(0, qtynames - 1);
  outputNames();

  return 0;
}

//Scans in new alphabet & creates a new "ASCII"ish table
void createNewOrder()
{
  int priority = 0;

  //Input new alphabet
  for (int i = 0; i < QTY_LETTERS; i++)
  {
    scanf(" %c", &alphabet[i]);
  }

  //Create new priority scheme for each letter
  for (int i = 0; i < QTY_LETTERS; i++)
  {
    int index = alphabet[i] - 'a';
    newPriority[index] = priority;
    priority++;
  }
}

//Loops to input each name per qtynames
void getNames()
{
  qtynames = 0;
  scanf("%d", &qtynames);

  for (int i = 0; i < qtynames; i++)
  {
    scanf("%s", namesList[i]);
  }
}

//Compares letter by letter to determine if it's in order with new alphabet
int compareLetters(char *wordLeft, char *wordRight)
{
  int letter = 0, value = 0;
  int wordLeftLen = strlen(wordLeft);
  int wordRightLen = strlen(wordRight);

  int shortestWordLen = (wordLeftLen < wordRightLen) ? wordLeftLen : wordRightLen;

  //While both letters aren't null
  while (wordLeft[letter] != '\0' && wordRight[letter] != '\0')
  {
    //Calculate the value at each letter
    value = newPriority[wordLeft[letter] - 'a'] - newPriority[wordRight[letter] - 'a'];

    //If it's not the same letter, just return the difference
    if (value != 0)
    {
      return value;
    }
    else //Otherwise keep looking at each letter
    {
      letter++;

      //If we made it to the last letter of the shortestWord,
      //then we can assume it's a substring or exactly the same, return the length difference
      if (letter == shortestWordLen)
      {
        return wordLeftLen - wordRightLen;
      }
    }
  }
}

//Recursively call mergeSortNames until single partitioned
void mergeSortNames(int low, int high)
{
  if (low < high)
  {
    int middle = low + (high - low) / 2;
    mergeSortNames(low, middle);      //sort left half
    mergeSortNames(middle + 1, high); //sort right half
    mergeNames(low, middle, high);    //merge all together
  }
}

void mergeNames(int low, int middle, int high)
{
  int helperLeft = low;
  int helperRight = middle + 1;
  int curIndex = low;

  //copy it over to the helper array
  for (int i = low; i <= high; i++)
  {
    strncpy(helper[i], namesList[i], MAX_NAME_LENGTH + 1);
  }

  while (helperLeft <= middle && helperRight <= high)
  {
    if (compareLetters(helper[helperLeft], helper[helperRight]) <= 0)
    {
      //Check if the words are already in lexographical order
      strncpy(namesList[curIndex], helper[helperLeft], MAX_NAME_LENGTH + 1);
      helperLeft++;
    }
    else
    {
      //It's not, so put the "smaller" valued word into current index
      strncpy(namesList[curIndex], helper[helperRight], MAX_NAME_LENGTH + 1);
      helperRight++;
    }
    curIndex++; //Increase namesList[]'s current index
  }

  //So let's make sure we get the remaining uncopied parts
  int remaining = middle - helperLeft;
  for (int i = 0; i <= remaining; i++)
  {
    strncpy(namesList[curIndex + i], helper[helperLeft + i], MAX_NAME_LENGTH + 1);
  }
}

void outputNames()
{
  //Yes, I have a problem. I really like modular programming.
  for (int i = 0; i < qtynames; i++)
  {
    printf("%s\n", namesList[i]);
  }
}