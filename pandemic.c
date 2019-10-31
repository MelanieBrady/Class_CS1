// Melanie Brady - CS1 MoWeFr 11:30am - 12:20pm - Assignment 2: Pandemic Problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void update();
void query();
void addStudentToSymptom(int r, char *person);
void addNewSymptom(char *person, char *symptom);

typedef struct Name
{
    char *str; // just a string
} Name;

typedef struct ArrayList
{
    Name *arr;     //array of names
    int size, cap; //how many names you have in your array & caps is total max
} ArrayList;

typedef struct FullList
{
    ArrayList *aol; //array of (array)lists
    int size, cap;
} FullList;

FullList *symp; //pointer to the whole table

int main()
{
    //must be initialize in function
    symp = calloc(1, sizeof(FullList)); 
    symp->size = 0;

    int n;
    char operation[2];

    scanf("%d", &n);

    if (n > 100, 000 || n < 1) //Handles when n isn't within (0-100,000)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        if (strcmp(operation, "u") == 0)
        {
            update();
        }
        else if ((strcmp(operation, "q")) == 0)
        {
            query();
        }
        else if (strcmp(operation, "q") != 0 && strcmp(operation, "u") != 0)
        {
            return 0;
        }
    }

    return 0;
}

void update()
{
    char person[101];
    char symptom[101];
    scanf("%s%s", person, symptom);

    for (int r = 0; r < symp->size; r++)
    {
        if (strcmp(symptom, symp->aol[r].arr[0].str) == 0)
        {
            addStudentToSymptom(r, person);
            return;
        }
    }
    addNewSymptom(person, symptom);
}

void query()
{
    int count = 0;
    char type[101];            // seeking students or symptoms
    char identifier[101];      //synonymous with student name or symptom
    char *output = strdup(""); // Copies a pointer to a null-terminated byte

    scanf("%s%s", type, identifier);

    if (strcmp(type, "student") == 0)
    {
        for (int r = 0; r < symp->size; r++)
        {
            for (int c = 0; c < symp->aol[r].size; c++)
            {

                //Check for times where the name appeared:
                if (strcmp(identifier, symp->aol[r].arr[c].str) == 0)
                {
                    count++;

                    //Append it
                    output = realloc(output, (sizeof(output) + sizeof(symp->aol[r].arr[0].str) + 1));
                    strcat(output, symp->aol[r].arr[0].str);
                    strcat(output, "\n");
                }
            }
        }

        printf("%d\n", count);
        printf("%s", output);
    }

    else if ((strcmp(type, "symptom")) == 0)
    {
        for (int r = 0; r < symp->size; r++)
        {

            //Checking if the symptom name appeared
            if (strcmp(identifier, symp->aol[r].arr[0].str) == 0)
            {
                for (int c = 1; c < symp->aol[r].size; c++)
                {
                    count++;

                    //Append it to the ouput
                    output = realloc(output, (sizeof(output) + sizeof(symp->aol[r].arr[c].str) + 1));
                    strcat(output, symp->aol[r].arr[c].str);
                    strcat(output, "\n");
                }
            }
        }
        printf("%d\n", count);
        printf("%s", output);
    }

    else if ((strcmp(type, "student") == 0) && (strcmp(type, "symptom") != 0))
    {
        return;
    }
}

void addNewSymptom(char *person, char *symptom)
{
    //Add a new row
    symp->aol = realloc(symp->aol, (symp->size + 1) * sizeof(ArrayList)); //must allocate space for full arraylist, this means we added a row
    symp->size += 1;                                                      // don't forget to increment meeee

    //Not realloc, this is a new chunk of memory
    symp->aol[symp->size - 1].arr = malloc(2 * sizeof(Name));

    //Copying over symptom to list
    symp->aol[symp->size - 1].arr[0].str = malloc(sizeof(symptom));
    strcpy(symp->aol[symp->size - 1].arr[0].str, symptom);

    //Copying over person to list
    symp->aol[symp->size - 1].arr[1].str = malloc(sizeof(person));
    strcpy(symp->aol[symp->size - 1].arr[1].str, person);

    //set the size
    symp->aol[symp->size - 1].size = 2;
}

void addStudentToSymptom(int r, char *person)
{
    //making the row longer for the new name
    symp->aol[r].arr = realloc(symp->aol[r].arr, (symp->aol[r].size + 1) * sizeof(Name));
    symp->aol[r].size += 1;

    //Copying over person to list
    symp->aol[r].arr[symp->aol[r].size - 1].str = malloc(sizeof(person));
    strcpy(symp->aol[r].arr[symp->aol[r].size - 1].str, person);
}
