#include <stdio.h>
#include <math.h>

int main() {
    float A, P, R, N, T;
    char B;

    printf("Select B/b for Borrowed and I/i for invested: ");
    scanf(" %c", &B);

    switch (B) {
        case 'B':
        case 'b':
            printf("Enter the principal amount: ");
            scanf("%f", &P);
            printf("Enter the rate of interest: ");
            scanf("%f", &R);
            printf("Enter the time in years: ");
            scanf("%f", &T);
            printf("Enter Number of times interest is compounded per year: ");
            scanf("%f", &N);

            A = P * pow(1 + (R / (100 * N)), N * T);
            printf("The total amount to be paid is: %.2f\n", A);
            printf("The interest to be paid is: %.2f\n", A - P);
            break;

        case 'I':
        case 'i':
            printf("Enter the principal amount: ");
            scanf("%f", &P);
            printf("Enter the rate of interest: ");
            scanf("%f", &R);
            printf("Enter the time in years: ");
            scanf("%f", &T);
            printf("Enter Number of times interest is compounded per year: ");
            scanf("%f", &N);

            A = P * pow(1 + (R / (100 * N)), N * T);
            printf("The total amount after interest is: %.2f\n", A);
            printf("The interest earned is: %.2f\n", A - P);
            break;

        default:
            printf("Invalid option selected.\n");
    }

}