#include <stdio.h>

#define IN  1  // inside a word
#define OUT 2  // outside a word

// print input one word per line
int main(void)
{
    int c, state;
    state = OUT;

    while ((c=getchar())!=EOF)
    {
        if (state==OUT)
        {
            putchar(c);
            if (c!=' ' && c!='\t' && c!='\n')
                state = IN;
        }
        else
        {
            if (c!=' ' && c!='\t' && c!='\n')
                putchar(c);
            else
            {
                putchar('\n');
                state = OUT;
            }
        }
    }
    
    return 0;
}
