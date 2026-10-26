#include <stdio.h>

int main() {
    float a, b, c, x, y, z;
    char C, F, K;

    printf("Select the Unit of Temperature (C/F/K): ");
    scanf("%c", &C);

    switch(C)
    {
        case 'C':
        case 'c':
            printf("Enter the Temperature in Celsius: ");
            scanf("%f", &a);
            b = (a * 9 / 5) + 32;
            printf("Temperature in Fahrenheit: %.2f\n", b);
            x = a + 273.15;
            printf("Temperature in Kelvin: %.2f\n", x);
            break;
        case 'F':
        case 'f':
            printf("Enter the Temperature in Fahrenheit: ");
            scanf("%f", &c);
            a = (c - 32) * 5 / 9;
            printf("Temperature in Celsius: %.2f\n", a);
            x = a + 273.15;
            printf("Temperature in Kelvin: %.2f\n", x);
            break;
        case 'K':
        case 'k':
            printf("Enter the Temperature in Kelvin: ");
            scanf("%f", &c);
            a = c - 273.15;
            b = (a * 9 / 5) + 32;
            printf("Temperature in Fahrenheit: %.2f\n", b);
            x = c;
            printf("Temperature in Celsius: %.2f\n", a);
            break;
        default:
            printf("Invalid Input!\n");
    }

    return 0;
}