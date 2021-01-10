#include <stdio.h>
#define MAXLINE 75  /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
    int len;  /* current line length */
    int max;  /* maximum length seen so far */
    char c;
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    // going through the input line by line
    max = 0;  // current longest line length
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

        // input line is the longest so far
        if (len > max)
        {
            max = len;
            copy(longest, line);  // first MAXLINE chars or less
        }
    }
    
    // printing the longest line
    if (max > 0)  // there was a line
    {
        printf("Longest line:\n%s", longest);

        // adding newline if it is not the last character 
        if (max < MAXLINE)
            c = longest[max-1];
        else
            c = longest[MAXLINE-1];
        if (c != '\n')
            putchar('\n');

        printf("(%d characters)\n", max);
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

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

