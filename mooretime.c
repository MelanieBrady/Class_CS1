
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9
#define TRUE (1==1)

int eq(double a, double b);
double f(double wait, int num_s, double hw_f);

int main()
{
    int cases, num_s;
    double lo, hi, hw_f, m1, m2, f1, f2;
    scanf("%d", &cases);

    // Handle multiple cases
    while (cases-->0)
    {
        // Read in the case
        scanf("%d", &num_s);
        scanf("%lf", &hw_f);

        // Start the low bound as some tiny value
        lo = 0;

        // Find the appropirate upper bound
        hi = 1;
        while (f(hi * 2, num_s, hw_f) < f(hi, num_s, hw_f))
        {
            hi = 2 * hi;
        }
        hi = 2 * hi;

        // Loop until our bounds are approximately the same
        while (!eq(lo, hi))
        {
            // Compute the midpoints and evaluate the function
            double m1 = (lo + lo + hi) / 3;
            double m2 = (lo + hi + hi) / 3;
            double f1 = f(m1, num_s, hw_f);
            double f2 = f(m2, num_s, hw_f);

            // Check if the function of midpoint 1 is worse than
            // the function at midpoint 2
            if (f1 > f2)
            {
                // Midpoint 1 is worse than midpoint 2 so
                // use it bound our search
                lo = m1;
            }
            else
            {
                // Midpoint 2 is worse than midpoint 1 so
                // use it bound our search
                hi = m2;
            }
        }

        // Compute and print the answer using the lower bound
        double ans = f(lo, num_s, hw_f);
        printf("%lf\n", f1);
    }

    // Exit
    return 0;
}

// Function to compute the time need to grade based on parameters
// and a possible wait time
double f(double wait, int num_s, double hw_f)
{

    // Compute the grade rate
    double rate = pow(hw_f, pow(wait, .5));

    // Determine the total grade time based on the wait and 
    // actual grading time.
    return wait + num_s / rate;
}

// Function to determine if two values are "close" to each other
// in value
int eq(double a, double b)
{
    double diff = (a - b);
    if (diff < 0)
        diff = -diff;
    if (diff < EPS)
        return TRUE;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
        a = b;
    return (diff < a * EPS);
}


