#include <stdio.h>

int main(){
    int a, o, y, n, e, r, i, c, j, v, row;
    char z;
    

    printf("\n Welcome to Truth Table Generator");
    printf("\n Do you want to continue (Y/N): ");
    scanf(" %c", &z);

    if (z == 'Y' || z == 'y'){
        while (z == 'Y' || z == 'y'){
            printf("Which Gate's Truth Table what to Generate ?");
            printf("\n 1. AND Gate \n 2. OR Gate \n 3. NOT Gate \n 4. XOR Gate \n 5. NAND Gate \n 6. NOR Gate \n 7. XNOR Gate");
            printf("\nEnter your choice: ");        
            scanf("%d", &y);
                if(y <= 7 && y >= 1){
                    if(y != 3){
                        printf("\n How Many Inputs Do You Want In The Truth Table: ");
                        scanf("%d", &n);
                        int input[n];
                        if(n == 0){
                            printf("\n Truth Table Cant be Generated for 0");
                        }
                        else if(n != 0){
                            for(e = 0, r = 1; e <= (n - 1); e++){
                                r = r * 2; /* here r is for converting the actual number to binary for inputs*/
                            }
                            printf("\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");
                        	for(j = 0; j < n; j++){
                                if(j < 26)
                                    {
                                        printf(" %c ", 'A' + j);
                                    }
                                else
                                    {
                                        printf(" %c%c ",
                                            'A' + ((j / 26) - 1),
                                            'A' + (j % 26));
                                    }
							}
                            printf("| O \n");
                            for(row = 0; row < r; row++){
                                int temp = row;
                                for(i = n - 1; i >= 0; i--)
                                    {
                                        input[i] = temp % 2;
                                        temp = temp / 2;
                                    }
                                    switch(y){
                                        case 1:
                                                o = 1;               /* It scans if a 0 is present or not */
                                                    for(i = 0; i < n; i++) 
                                                        {
                                                            if(input[i] == 0){
                                                                o = 0;  /* No need to scan further */
                                                                break;
                                                            }
                                                        }
                                                break;
                                        case 2:
                                                o = 0;          /* It scans if a 1 is present or not */
                                                for(i = 0; i < n; i++)
                                                    {
                                                        if(input[i] == 1){
                                                            o = 1;               /* No need to scan further */
                                                            break;
                                                        }
                                                    }
                                            break;
                                        case 4:
                                                c = 0;
                                                for(i = 0; i < n; i++){         /* It counts how many 1's are present */
                                                    if(input[i] == 1){
                                                        c = c + 1;
                                                    }
                                                }
                                                if (c % 2 == 0){            /* Odd count gives 1, even count gives 0 */
                                                    o = 0;
                                                    } 
                                                else{
                                                    o = 1;
                                                    }
                                            break;
                                        case 5:                 /* First it behaves exactly like an AND Gate */
                                                o = 1;

                                                    for(i = 0; i < n; i++)
                                                    {
                                                        if(input[i] == 0)
                                                        {
                                                            o = 0;
                                                            break;
                                                        }
                                                    }

                                                o = !o;      /* Then it flips the output */
                                            break;
                                        case 6:                     /* First it behaves exactly like an OR Gate */
                                                o = 0;  
                                                for(i = 0; i < n; i++)
                                                    {
                                                        if(input[i] == 1){
                                                            o = 1;
                                                            break;
                                                        }
                                                    }
                                                o = !o;          /* Then it flips the output */
                                            break;
                                        case 7:                     /* It counts how many 1's are present */
                                                c = 0;
                                                for(i = 0; i < n; i++){
                                                    if(input[i] == 1){
                                                        c = c + 1;
                                                    }
                                                }
                                                if (c % 2 == 0){             /* Even count gives 1, odd count gives 0 */
													o = 1;
													} 
                                                else{
                                                    o = 0;
                                                    }
                                            break;    
                                    }
                                for(i = 0; i < n; i++)
                                    {
                                        printf(" %d ", input[i]);
                                    }
                                printf("| %d \n", o);
                            }

                        }
                        else{
                            printf("\n Do you really want that since even 10 is a big run.... this I request to choose less than or eqaul to 10");
                        }

                    }
                    else{
                        printf("\nYour Truth Table For NOT Gate");
                        printf("\nA | O");
                        for(a=0;a<=1;a++)
                            {
                                o = !a;
                                printf("\n%d | %d",a,o);
                            }
                    }
                }
                else{
                    printf("\n Enter a Valid Choice");
                }

            printf("\n Do you want to continue (Y/N): \n");
            scanf(" %c", &z);
        }
    }
    else{
        printf("\n Thank you for using the program.");
    }
}

