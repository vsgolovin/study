#include <stdio.h>
// 1-10.c -- replaces tabs by \t, backspaces by \b and backslashes by \\

int main(void)
{
    int c;

    while ((c=getchar())!=EOF)
    {
        if (c=='\t')
            printf("\\t");
        else if (c=='\b')
            printf("\\b");
        else if (c=='\\')
            printf("\\\\");
        else
            putchar(c);
    }

    return 0;
}
