/* Exercise 2-6. Write a function `setbits(x,p,n,y) that returns `x` with
 * the `n` bits that begin at position `p` set to the rightmost `n` bits
 * of `y`, leaving the other bits unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void test_setbits(unsigned x, int p, int n, unsigned y, unsigned ans);

int main(void)
{
    test_setbits(0, 5, 2, ~1, 48);
    putchar('\n');
    test_setbits(179, 3, 4, 76, 188);
    putchar('\n');
    test_setbits(27, 8, 6, 184, 187);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask, x1, y1;
    mask = (~(~0<<n)) << (p-n+1);
    x1 = x & ~mask;
    y1 = y & mask;
    x = x1 | y1;
    return x;
}

void test_setbits(unsigned x, int p, int n, unsigned y, unsigned ans)
{
    printf("setbits(%u,%d,%d,%u) = %u\n", x, p, n, y, setbits(x,p,n,y));
    printf("correct answer: %u\n", ans);
}

