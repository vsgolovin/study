/* Exercise 2-8. Write a function `rightrot(x,n)` that returns the value
 * of the integer `x` rotated to the right by `n` positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);
void test_rightrot(unsigned x, int n, unsigned ans);

// correct answers correspond to 32-bit integers
int main(void)
{
    test_rightrot(2, 2, 2147483648);
    putchar('\n');
    test_rightrot(3042675091, 12, 2570802616);
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int s;  // size of x in bits
    unsigned last_bits;  // n last bits of x

    s = sizeof(n)*8;
    last_bits = x & ~(~0<<n);
    return (x >> n) | (last_bits<<(s-n));
}

void test_rightrot(unsigned x, int n, unsigned ans)
{
    printf("rightrot(%u,%d) = %u\n", x, n, rightrot(x,n));
    printf("correct answer: %u\n", ans);
}

