// Melanie Brady - CS1 - MoWeFr 11:30a - 12:20p - Moore Time

#include <stdio.h>
#include <limits.h> //Imported for INT_MAX
#include <math.h>   //Imported for sqrt & pow

#define ACCURACY 1e-10 //Calculate twice the requested accuracy

double calculateYears(int students, double component, double yearsWait);
double compareYears(int students, double component, double least, double most, double prevYears);

int main()
{
    int loop, students;
    double component;

    scanf("%d", &loop);

    for (int i = 0; i < loop; i++) //Loops over requested amount, scans in user input, prints out calculation! 
    {
        scanf("%d", &students);
        scanf("%lf", &component);

        //Prints out result of binary search in compareYears
        //I'm using INT_MAX will allow for greater accuracy/efficiency than students or iteration technique for initial max
        printf("\n%.6lf\n", compareYears(students, component, 0.0, INT_MAX, INT_MAX));
    }
}

// Calculates total years = k / (H ^ (sqrt(n))) + n
// Total Years = (students / (component ^ (sqrt(yearsWait))) + yearsWait
double calculateYears(int students, double component, double yearsWait)
{
    return (((double)students / (pow(component, (sqrt(yearsWait))))) + yearsWait);
}

// Binary search through all potiential yearsWait
double compareYears(int students, double component, double least, double most, double prevYear)
{
    //Divides all yearsWait in half
    double middle = least + (most - least) / 2;

    //Plugs in middle yearsWait and calculates total years
    double currentYear = calculateYears(students, component, middle);

    //Divides "left" & "right" half of yearsWait
    double middleLeast = least + (middle - least) / 2;
    double middleMost = middle + (most - middle) / 2;

    //Checks if the prevYear & currentYear are right within accuracy range, then prints optimum year! 
    if (fabs(prevYear - currentYear) < ACCURACY) //remember fabs is for floats types
    {
        return currentYear; //yayyyyy! 
    }

    //Plugs in middleLeast's value of yearsWait, plugs in middleMost's value of yearsWait, then compares their totalYears:
    //If middleLeast's totalYears is less than, middleMost's totalYears, then focus on "left", "least" half
    if (calculateYears(students, component, middleLeast) < calculateYears(students, component, middleMost))
    {
        return compareYears(students, component, least, middle, currentYear);
    }
    else //If not, then the value must be on the "right", "most" half
    {
        return compareYears(students, component, middle, most, currentYear);
    }
}
