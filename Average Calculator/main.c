#include <stdio.h>

int main() {
    int n;
    float a , b, c, s, t;
    char z;

    printf("\n Welcome to average calculator \n");
    printf("Are you ready (Y/N)? : ");
    scanf(" %c", &z);

        if (z == 'Y' || z == 'y')
            {
                while (z == 'Y' || z == 'y') 
                    {
                        printf("How many Number of average are you taking: ");
                        scanf("%d", &n);
                        for (s = 0, t = 0 ; t <= (n-1); t++) 
                            {
                                printf("Enter the Number: ");
                                scanf("%f", &a);
                                s = s + a;                           
                            }
                        b = s / n;
                        printf("Result = %f\n", b);
                        printf("\n Do you want to continue (Y/N)? : ");
                        scanf(" %c", &z);
                    }
            }
        else 
            {
            printf("\n Thanks For using the Program");
            }
}