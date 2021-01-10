#include <stdio.h>

#define IMIN 33   // first tracked character decimal code
#define IMAX 126  // last tracked character decimal code
#define LENGTH IMAX-IMIN+1
#define HISTMAX 50  // max number of characters in histogram row

// print a histogram of character frequencies
int main(void)
{
    int c, i, j;
    float ncmax;
    long nc[LENGTH];
    for (i = 0; i < LENGTH; i++)
        nc[i] = 0;

    // calculating characters
    while ((c = getchar()) != EOF)
        if ((c >= IMIN) && (c <= IMAX))
            nc[c-IMIN]++;

    // finding largest number of characters 
    ncmax = 0.0;
    for (i = 0; i < LENGTH; i++)
        if (nc[i] > ncmax)
            ncmax = nc[i];

    // adjusting character counts
    for (i = 0; i < LENGTH; i++)
        nc[i] *= HISTMAX/ncmax;

    // displaying histogram
    for (i = 0; i < LENGTH; i++)
    {
        printf(" %c | ", i + IMIN);
        for (j = 0; j < nc[i]; j++)
            putchar('#');
        putchar('\n');
    }
    
    return 0;
}
