#include <stdio.h>
// 1-9.c -- removing multiple blanks 

int main(void)
{
    int c, c_prev;
    c_prev = 'a';  // not a blank

    while ((c=getchar())!=EOF)
    {
        if (c==' ' && c_prev==' ')
            ;
        else
            putchar(c);
        c_prev = c;
    }

    return 0;
}
