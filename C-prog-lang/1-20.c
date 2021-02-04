/* Exercise 1-20. Write a program `detab` that replaces tabs in the input
 * with the proper number of blanks to space the next tab stop. Assume
 * the fixed set of tab stops, say every n columns. Should `n` be a
 * variable or a symbolic parameter? */

#include <stdio.h>

#define MAXLINE 1024  // maximum input line length
#define COL_WIDTH 10  // column width for aligning tabs

int get_line(char s[], int maxline);
void detab(char from[], char to[], int cw);

int main(void)
{
    int len, i, j;
    char line_in[MAXLINE];
    char line_out[MAXLINE];

    while ((len = get_line(line_in, MAXLINE)) > 0)
    {
        detab(line_in, line_out, COL_WIDTH);
        printf("%s", line_out);
    } 

    return 0;
}

// get_line: read a line into s, return length
int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// detab: replace tabs with blanks so that text is in cw-wide columns
void detab(char from[], char to[], int cw)
{
    int i, j;

    for (i=0, j=0; from[i]!='\0'; i++)
    {
        if (from[i]=='\t')
        {
            to[j++] = ' ';
            while (j%cw != 0)
                to[j++] = ' ';
        }
        else
            to[j++] = from[i];
    }
    to[j] = '\0';
}
