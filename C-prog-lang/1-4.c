#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = -20, 0, ,,,, 140 */
int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -20;  // lower limit of temperature scale
    upper = 140;  // upper limit
    step = 10;    // step size

    printf("Celsius\tFahrenheit\n");  // header
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = 1.8*celsius + 32.0;
        printf("%7.1f\t%10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}

