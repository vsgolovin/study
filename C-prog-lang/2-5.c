/* Exercise 2-5. Write the function `any(s1,s2)`, which returns the first
 * location in a string `s1` where any character from the string `s2`
 * occurs, or `-1` if `s1` contains no character from `s2`.
 */

#include <stdio.h>

int any(char s1[], char s2[]);
void test(char s1[], char s2[]);

int main(void)
{
    char s1[27] = "In short, I like the stock";
    char s2[2] = "i";
    char s3[2] = "I";
    char s4[5] = "k   ";
    char s5[5] = "long";
    char s6[6] = "short";
    char s7[4] = "xyz";
    char s8[5] = "xyzc";
    char s9[1] = "";

    printf("    012345678901234567890123456\n");
    printf("s1  %s\n\n", s1);
    test(s1, s2);
    test(s1, s3);
    test(s1, s4);
    test(s1, s5);
    test(s1, s6);
    test(s1, s7);
    test(s1, s8);
    test(s1, s9);

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i=0; s1[i]!='\0'; i++)
        for (j=0; s2[j]!='\0'; j++)
            if (s1[i]==s2[j])
                return i;
    return -1;
}

void test(char s1[], char s2[])
{
    printf("s2=\"%s\", any(s1,s2)=%d\n", s2, any(s1,s2));
}

