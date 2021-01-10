#include <stdio.h>
// 1-8.c -- counting blanks, tabs and newlines

int main(void)
{
    int c, blnk, tabs, newl;
    blnk = tabs = newl = 0;

    while ((c=getchar())!=EOF)
    {
        if (c==' ')
            blnk++;
        else if (c=='\t')
            tabs++;
        else if (c=='\n')
            newl++;
    }

    printf("Input contains %d blanks, %d tabs and %d newlines.\n",
            blnk, tabs, newl);
    return 0;
}
