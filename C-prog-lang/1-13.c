#include <stdio.h>

#define IN  1  // inside a word
#define OUT 2  // outside a word
#define MAXLENGTH 12  // largest tracked word length

// count words of different lengths and print a histogram
int main(void)
{
    int c, i, j, state;
    int nwords[MAXLENGTH];  // for counting words
    state = OUT;
    for (i = 0; i < MAXLENGTH; i++)
        nwords[i] = 0; 

    // counting words of different lengths
    i = 0;  // current word length
    while ((c=getchar())!=EOF)
    {
        if (c != ' ' && c != '\n' && c != '\t')
        {
            i++;
            if (state == OUT)
                state = IN;
        }
        else if (state == IN)
        {
            if (i <= MAXLENGTH)
                nwords[i-1]++;  // number of words with length i
            else
                nwords[MAXLENGTH-1]++;
            i = 0;
            state = OUT;
        }
    }

    // displaying histogram
    for (i = 0; i < MAXLENGTH; i++)
    {
        if (i != (MAXLENGTH-1))
            printf("%2d  | ", i+1);
        else
            printf("%2d+ | ", i+1);
        for (j = 0; j < nwords[i]; j++)
            putchar('#');
        putchar('\n');
    }
    
    return 0;
}
