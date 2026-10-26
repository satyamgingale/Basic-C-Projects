#include <stdio.h>

int main() {
    float  P, T, R, x, y, z;
    char B;

    printf("Enter B/b for Borrowed or I/i for Invested\n");
    scanf(" %c", &B);

    printf("Enter the Principal amount\n");
    scanf("%f", &P);

    printf("Enter the time in years\n");
    scanf("%f", &T);

    printf("Enter the interest rate in ( %% )\n");
    scanf("%f", &R);

    switch(B){
        case 'B':
        case 'b':
            x = P * R * T / 100;
            printf("Interest: %f", x);
            z = P + x;
            printf("\nTotal Amount to be Paid: %f", z);
            break;
        case 'I':
        case 'i':
            y = P * R * T / 100;
            printf("Interest: %f", y);
            z = P + y;
            printf("\nTotal Amount after Investment: %f", z);
            break;
        default:
            printf("Invalid input");
    }

}