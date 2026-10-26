#include <stdio.h>
#include <math.h>

int main() {
    char C;

    printf("Welcome to the Interest Calculator!\n");
    printf("Select Simple Interest (S/s) or Compound Interest Calculator (C/c): ");
    scanf(" %c", &C);

    switch (C) {
        case 'S':
        case 's':
        {
            float  P, T, R, x, y, z;
            char B;

            printf("Enter B/b for Borrowed or I/i for Invested\n");
            scanf(" %c", &B);

            printf("Enter the Principal amount: ");
            scanf("%f", &P);
            printf("Enter the interest rate in ( %% ): ");
            scanf("%f", &R);
            printf("Enter the time in years: ");
            scanf("%f", &T);

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
            break;
        }
    

        case 'C':
        case 'c':
        {
            float A, P, R, N, T;
            char B;
            printf("Enter B/b for Borrowed or I/i for Invested\n");
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
                    printf("The interest to be paid is: %.2f\n", A - P);
                    printf("The total amount to be paid is: %.2f\n", A);

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
                    printf("The interest earned is: %.2f\n", A - P);
                    printf("The total amount after interest is: %.2f\n", A);

                    break;

                default:
                    printf("Invalid option selected.\n");
            }
            break;
        }
        default:
            printf("Invalid option selected.\n");
    }

}
