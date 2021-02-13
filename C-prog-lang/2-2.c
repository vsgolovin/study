/* Exercise 2-2. Write a loop equivalent to the `for` loop above without
 * using && or ||. */

#include <stdio.h>
#define MAXLINE 1024

int get_line(char line[], int maxline);

int main(void)
{
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0)
        printf("%s", line);

    return 0;
}

// get_line: read a line into s, return length 
int get_line(char s[], int lim)
{
    int c, i;

    /* original for loop
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    */
    
    // replacement
    for (i=0; i<lim-1; ++i)
    {
        if ((c=getchar())==EOF)
            break;
        else if (c=='\n')
            break;
        s[i] = c;
    }
    
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
