#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

/* 1-18.c -- remove trailing blanks or tabs, as well as empty lines */

int get_line(char line[], int maxline);
int is_wsp(char c);

int main(void)
{
    int len;  /* current line length */
    int i;    /* iteration number */
    char line[MAXLINE];  /* current input line */
    char c;              /* current input character */
    int is_blank;        /* flag, used for 2 purposes */

    // going through the input line by line
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        // input line is too long
        if ((len == MAXLINE-1) && (line[len-1] != '\n')
                               && (line[len-1] !=  EOF))
        {
            while ((c=getchar())!=EOF && c!='\n')
                ;  // discard remaining characters
            line[MAXLINE-2] = '\n';  // make last character newline
        } 

        // checking if the line is empty
        is_blank = 1;  // empty by default
        for (i=0; i < (len-1); i++)
            if (!is_wsp(line[i]))
            {
                is_blank = 0;
                break;
            }
        if (is_blank) // only blank characters
            continue; // move to next input line

        // printing input line
        is_blank = 0;  // is last character space or tab
        for (i=0; i < (len-1); i++)
        {
            if (!is_wsp(line[i]))
            {
                putchar(line[i]);
                is_blank = 0;
            }
            else if (!is_blank)
            {
                putchar(line[i]);
                is_blank = 1;
            }
            else
                ;
        }

        // last character is always newline
        putchar('\n');
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

/* is_wsp: return 1 if character is space or tab, 0 otherwise */
int is_wsp(char c)
{
    if (c == '\t' || c == ' ')
        return 1;
    else
        return 0;
}
