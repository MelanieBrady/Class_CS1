#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void update();
void query();
void addStudentToSymptom(int r, char *person);
void addNewSymptom(char *person, char *symptom);

//Structs I'm forced to use: 
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
    symp = calloc(1, sizeof(FullList)); 
    symp->size = 0;

    int n; //How many times to loop
    char operation[2]; // update or query 

    scanf("%d", &n);

    //Loops for specified amount of operations 
    for (int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        // If update operation, send to update function 
        if (strcmp(operation, "u") == 0)
        {
            update();
        }

        // If query operation, send to query function 
        else if ((strcmp(operation, "q")) == 0)
        {
            query();
        }

        // Rebel. Stop that. 
        else if (strcmp(operation, "q") != 0 && strcmp(operation, "u") != 0)
        {
            return 0;
        }
    }

    return 0;
}



//Checks to see if the symptom already exists, if not it adds it to the list
void update()
{
    char person[101];
    char symptom[101];
    scanf("%s%s", person, symptom); 

    // We're going through each row
    for (int r = 0; r < symp->size; r++)
    { 
        //Note in full list named symp, all symptoms will be at index 0
        //don't forget .str otherwise you're not looking at the string and that'd be silly
        if (strcmp(symptom, symp->aol[r].arr[0].str) == 0) 
        { 
            addStudentToSymptom(r, person); //send in the row that has the symptom, and the person's name 
            return;
        }
    }
    addNewSymptom(person, symptom);
}

void query()
{
    int count = 0; 
    char type[101];  // checking what type of q either students or symptoms
    char identifier[101]; //then what to update
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

                    //Realloc for room, then append it to the output string
                    output = realloc(output, (sizeof(strlen(output)) + sizeof(symp->aol[r].arr[0].str) + 1));
                   // output = realloc(output, (sizeof(output) + sizeof(symp->aol[r].arr[0].str) + 1));
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
                    output = realloc(output, (sizeof(strlen(output)) + sizeof(symp->aol[r].arr[c].str) + 1));
                    strcat(output, symp->aol[r].arr[c].str);
                    strcat(output, "\n");
                }
            }
        }
        printf("%d\n", count);
        printf("%s", output);
    }

}


//Creates a new row
void addNewSymptom(char *person, char *symptom)
{
    //Adds a new row for the symptom: 
    symp->aol = realloc(symp->aol, (symp->size + 1) * sizeof(ArrayList)); 
    symp->size += 1; //increment size each time

    //Not realloc, this is a new chunk of memory
    symp->aol[symp->size - 1].arr = malloc(2 * sizeof(Name));

    //Copying over symptom to list
    // Don't malloc from static array (sizeof(symptom)) - you'll malloc the address or only the first letter it points to
    symp->aol[symp->size - 1].arr[0].str = malloc(sizeof(strlen(symptom)));
    strcpy(symp->aol[symp->size - 1].arr[0].str, symptom);

    //Copying over person to list
    symp->aol[symp->size - 1].arr[1].str = malloc(sizeof(strlen(person)));
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
    symp->aol[r].arr[symp->aol[r].size - 1].str = malloc(sizeof(strlen(person)));
    strcpy(symp->aol[r].arr[symp->aol[r].size - 1].str, person);
}
