/* Exercise 2-7. Write a function `invert(x,p,n)` that returns `x` with
 * the `n` bits that begin at position `p` inverted (i.e., 1 changed into
 * 0 and vice versa), leaving the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
void test_invert(unsigned x, int p, int n, unsigned ans);

int main(void)
{
    test_invert(0, 3, 3, 14);
    putchar('\n');
    test_invert(1, 7, 1, 129);
    putchar('\n');
    test_invert(693, 7, 4, 581);
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask;
    mask = (~(~0<<n)) << (p-n+1);
    return x&(~mask) | (~x)&mask;
}

void test_invert(unsigned x, int p, int n, unsigned ans)
{
    printf("invert(%u,%d,%d) = %u\n", x, p, n, invert(x,p,n));
    printf("correct answer: %u\n", ans);
}
