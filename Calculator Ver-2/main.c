#include <stdio.h>

int main() {
    int e;
    float a, b, d;
    char c, z;
    printf("Welcome to the Simple Calculator Program!\n");
    printf("do you want to use the calculator? (Y/N): ");
    scanf(" %c", &z);

    if (z == 'Y' || z == 'y')
        { 
            while (z == 'Y' || z == 'y') 
                {
                    printf("Enter First Number: ");
                    scanf("%f", &a);
                    
                    printf("Available Operators: +, -, *, /, %%, ^, ! (if ! then Enter second numberas 1), r (for remainder)\n");
                    printf("Enter Operator (+, -, *, /, %%, ^, !, r): ");
                    scanf(" %c", &c);

                    printf("Enter Second Number: ");
                    scanf("%f", &b);

                    switch (c) 
                        {
                            case '+':
                                d = a + b;
                                printf("Result: %f\n", d);
                                break;
                            case '-':
                                d = a - b;
                                printf("Result: %f\n", d);
                                break;
                            case '*':
                                d = a * b;
                                printf("Result: %f\n", d);
                                break;
                            case '/':
                                if (b != 0) {
                                    d = a / b;
                                    printf("Result: %f\n", d);
                                } else {
                                    printf("Error: Division by zero is not allowed.\n");
                                }
                                break;
                            case '%':
                                    d = (a * b) / 100;
                                    printf("Result: %f\n", d);
                                break;
                            case '^':
                                {
                                    if (b != (int)b) {
                                        printf("Error: Exponent must be an integer.\n");
                                        break;
                                    }
                                    else if (b >= 1) {
                                            for(d = 1, e = 1; e <= b; e++)
                                                d = d * a; 
                                                printf("Result: %f\n", d);                
                                            break;
                                    } 
                                    else if (b == 0) {
                                                d = 1; 
                                                printf("Result: %f\n", d);
                                            break;
                                    }
                                    else if (b < 0) {
                                        if (a != 0) 
                                            {
                                                for(d = 1, e = 1; e <= -b; e++)
                                                    {d = d * a;} 
                                                    d = 1 / d;
                                                    printf("Result: %f\n", d);
                                                break;
                                            } 
                                        else 
                                            {
                                                printf("Error: Zero cannot be raised to a negative power.\n");        
                                                break;                        
                                            }
                                    }   
                                break;
                                }
                            case '!':{
                                if (a != (int)a) {
                                    printf("Error: Base must be an integer.\n");
                                    break;
                                }
                                else if (a < 0){
                                        printf("Error: Negative fractorials are not allowed.\n");
                                        break;
                                    }
                                else if (a >= 1) {
                                        for(d = a, e = a; e >= 2; e--)
                                            d = d * (e-1); 
                                            printf("Result: %f\n", d);                
                                        break;
                                    } 
                                else if (a == 0) {
                                            d = 1; 
                                            printf("Result: %f\n", d);
                                        break;
                                    }
                                    break;
                            }
                            break;
                            case 'r':{
                                if (b != (int)b || a != (int)a) {
                                    printf("\n Error: Modulus operator requires integer operands.\n");
                                }
                                else if (b == 0) {
                                    printf("\n Error: Modulus by zero is not allowed.\n");
                                }
                                else {
                                    d = (int)a % (int)b;
                                    printf("Result: %f\n", d);
                                }
                            break;
                        }
                }
            printf("Do you want another calculation? (Y/N): ");
            scanf(" %c", &z);          
        }
        }
        else
            {
                printf("\n Thanks for using the program. \n");
                return 0;
            }
}