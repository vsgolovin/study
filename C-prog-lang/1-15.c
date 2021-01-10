#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float f2c(float fahr);

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
int main(void)
{
    float fahr, celsius;

    printf("Fahrenheit\tCelsius\n");  // header
    fahr = LOWER;
    while (fahr <= UPPER)
    {
        celsius = f2c(fahr);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    return 0;
}

/* f2c: convert temerature from Fahrenheit te Celsius */
float f2c(float fahr)
{
    float celsius;
    celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}

