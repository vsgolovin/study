/* Exercise 2-3. Write a function `htoi(s)`, which converts a string of
 * hexadecimal digits (including an optional `0x` or `0X`) into its
 * equivalent integer value. The allowable digits are `0` through `9`,
 * `a` through `f`, and `A` through `F`. */

#include <stdio.h>

int htoi(char s[]);

// testing htoi
int main(void)
{
    printf("s = %s, htoi(s) = %d\n", "0xaab", htoi("0xaab"));
    printf("s = %s, htoi(s) = %d\n", "aAB", htoi("aAB"));
    printf("s = %s, htoi(s) = %d\n", "12mFC", htoi("12mFC"));
    printf("s = %s, htoi(s) = %d\n", "0", htoi("0"));
    printf("s = %s, htoi(s) = %d\n", "0X", htoi("0X"));
    printf("s = %s, htoi(s) = %d\n", "78dc", htoi("78dc"));

    return 0;
}

int htoi(char s[])
{
    int i, n;

    // skipping leading 0x or 0X
    if (s[0]=='0' && (s[1]=='x' || s[1]=='X'))
        i = 2;
    else
        i = 0;

    // calculating integer value
    n = 0;
    while (s[i]!='\0')
    {
        if (s[i]>='0' && s[i]<='9')
            n = n*16 + (s[i]-'0');
        else if (s[i]>='a' && s[i]<='f')
            n = n*16 + (s[i]-'a'+10);
        else if (s[i]>='A' && s[i]<='F')
            n = n*16 + (s[i]-'A'+10);
        else
            break;
        i++;
    }

    return n;
}

