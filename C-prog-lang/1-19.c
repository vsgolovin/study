#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

int get_line(char line[], int maxline);
void reverse(char s[]);

/* reverse all input one line at a time */
int main(void)
{
    int len;  /* current line length */
    char c;
    char line[MAXLINE];     /* current input line */

    // going through the input line by line
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        // input line is too long
        if ((len == MAXLINE-1) && (line[len-1] != '\n')
                               && (line[len-1] !=  EOF))
        {
            while ((c=getchar())!=EOF && c!='\n')
                len++;
            if (c == '\n')
                len++;
        }

        // printing reversed line
        reverse(line);
        printf("%s", line);
    }

   return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c=='\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverse: reverse line stored into s */
void reverse(char s[])
{
    int i, j;  // indices for iterating over s
    char c;    // buffer

    // finding the length of s
    for (j=0; s[j] != '\0'; j++)
        ;
    j--;  // moving from '\0' to last character
    if (s[j]=='\n')
        j--;  // keeping newline at the end

    // swapping first and last element
    if (j > 0)
    {
        for (i=0; i<j; i++, j--)
        {
            c = s[j];
            s[j] = s[i];
            s[i] = c;
        }
    }
}

