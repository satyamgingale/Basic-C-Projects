#include <stdio.h>

int main(){
    int a, b, y, s, n, d, p, *bi;
    char z;
    /* float ; */

    printf("\n Welcome To Binary Converter.");
    printf("\n Do you want to continue (Y/N): ");
    scanf(" %c", &z);
        if ( z == 'Y' || z == 'y') 
        {
            while ( z == 'Y' || z == 'y')
            {
                printf("\n If you want to convert Binary to Decimal (Press 1)");
                printf("\n If you want to convert Decimal to Binary (Press 2)");
                printf("\n Enter your choice: ");
                scanf("%d", &y);
                
                    switch (y)
                        {
                            /*
                            else if (b >= 1) {
                                            for(d = 1, e = 1; e <= b; e++)
                                                d = d * a; 
                                                printf("Result: %f\n", d);                
                                            break;
                                    }
                            */
                            case 1: {
                                printf("\n Enter the Binary Number : ");
                                scanf("%d", &a);
                                for (n = 0, d = 1; a != 0; n++)
                                    {
                                        b = a % 10;
                                        a = a / 10;
                                            if (n == 0){
                                                s = b;
                                            }
                                            else {
                                                d = d * 2;
                                                s = s + ( b * d );
                                            }
                                    }
                                    printf("\n Your number in Decimal: %d", s);
                                }
                            break;

                            case 2:{
                                printf("\n Enter Your Decimal Number : ");
                                scanf("%d", &a);
                                printf("\n Before starting the calculation wait until the program is done. then the Binary Number will be from Down to Up. \n");
                                for (bi = 0, p = 1;a != 0;)
                                    {
                                        b = a % 2;
                                        bi = bi + (b * p);
                                        p = p * 10;
                                        a = a / 2;
                                        printf("%d\n", b);
                                    }
                                    printf("The Final Answer : %d\n", bi);
                            break;
                            }
                        }

                printf("\n Do you want to continue (Y/N): ");
                scanf(" %c", &z);
            }
        }
        else
        {
            printf("\n Thank you for using the calculator");
        }
}