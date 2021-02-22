/* Exercise 2-4. Write an alternative version of `squeeze(s1,s2)` that
 * deletes each character in `s1` that matches any character in the
 * *string* `s2`. */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[27] = "fchbaeljcalo,ikb awoagcrld";
    char s2[9] = "abcfgijk";
    printf("Initial string: %s\n", s1);
    printf("To remove: %s\n", s2);
    squeeze(s1, s2);
    printf("Result: %s\n", s1);
    return 0;
}

// squeeze -- remove all characters in s2 from s1
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    i = j = 0;

    for (i=0; s1[i]!='\0'; i++)
    {
        for (k=0; s2[k]!='\0'; k++)
        {
            if (s1[i]==s2[k])
                break;
        }
        if (s2[k]=='\0')  // s1[i] not in s2
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
