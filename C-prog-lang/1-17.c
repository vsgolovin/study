#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */
#define MINLINE 81    /* minimum input line length
                         that is to be printed */

int get_line(char line[], int maxline);

/* print all input lines that are at least MINLINE characters */
int main(void)
{
    int len;  /* current line length */
    char c, lc;
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

        // printing if line is long enough 
        if (len >= MINLINE)
        {
            printf("%s", line);
           
            // adding newline if it is not the last character 
            if (len < MAXLINE)
                lc = line[len-1];
            else
                lc = line[MAXLINE-1];
            if (lc != '\n')
                putchar('\n');
        }
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

