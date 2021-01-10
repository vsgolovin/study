#include <stdio.h>

/* printing the value of `getchar() != EOF` */
int main(void)
{
    int c, i;

    while(1)
    {
        c = getchar();
        i = (c != EOF);
        printf("%d", i);
        if (c == '\n')
            putchar(c);
        if (c == EOF)
            break;
    }

    putchar('\n');
    return 0;
}
