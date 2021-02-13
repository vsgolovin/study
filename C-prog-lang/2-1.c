/* Exercise 2-1. Write a program to determine the ranges of `char`, `short`,
 * `int`, and `long` variables, both `signed` and `unsigned`, by printing
 * appropriate values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various
 * floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    char c;
    short si;
    int i;
    long li;

    printf("Calculated min and max values:\n");
    // char
    c = 1;
    while (c>=0)
        c *= 2;
    printf("char: %d / ", c);
    c--;
    printf("%d\n", c);
    
    // short
    si = 1;
    while (si>=0)
        si *= 2;
    printf("short: %hd / ", si);
    si--;
    printf("%hd\n", si);

    // int
    i = 1;
    while (i>=0)
        i *= 2;
    printf("int: %d / ", i);
    i--;
    printf("%d\n", i);

    // long
    li = 1;
    while (li>=0)
        li *= 2;
    printf("long: %ld / ", li);
    li--;
    printf("%ld\n", li);

    // displaying values from limits.h
    printf("\nMin and max values from limits.h:\n");
    printf("char: %d / %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d / %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d / %d\n", INT_MIN, INT_MAX);
    printf("long: %ld / %ld\n", LONG_MIN, LONG_MAX);

    // not repeating all this for every unsigned type
    unsigned int ui;
    ui = 1;
    while (ui!=0)  // assuming min value is 0
        ui *= 2;
    ui--;
    printf("\nLargest unsigned int values:\n");
    printf("Calculated: %u\n", ui);
    printf("From limits.h: %u\n", UINT_MAX);

    // finding float epsilon
    float f, df;
    f = 1.0; 
    df = 1e-1;
    while ((f+df)!=f)
        df /= 10;
    printf("\nFloat epsilon -- minimum number x, such that");
    printf(" 1.0+x != 1.0\n");
    printf("Estimated by calculation: %e\n", df*10);
    printf("From float.h: %e\n", FLT_EPSILON);

    return 0;
}
