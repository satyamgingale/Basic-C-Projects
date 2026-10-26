#include <stdio.h>

int main() {

    int a;
    char z;

    printf("\n Welcome to Odd/Even Finder. (Like you dont know But still trying to make a program...sighhh...)");
    printf("\n Are ready to go on a journey where you discover something you already know (Y/N): ");
    scanf(" %c", &z);
        if (z == 'Y' || z == 'y'){
            while ( z == 'Y' || z == 'y') 
                {
                printf("Enter a number: "); 
                scanf("%d", &a);

                    if (a % 2 == 0) {
                        printf("The number is even.\n");
                    } 
                    else {
                        printf("The number is odd.\n");
                    }
                
                printf("Do you wish to continue the program? (Y/N): ");
                scanf(" %c", &z);
                }
            } 
        else {
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
        }
    printf("\nHope you discovered something good...  Something you already know!\n");
    printf("Thank you for using the program. Goodbye!\n");    
    return 0;
}