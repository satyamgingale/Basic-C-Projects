#include <stdio.h>

int main (){
    int a, b, o, y, x;
    char z, screen_running;
    screen_running = 1;

    while (screen_running){
            printf("\n Which type of Gate do you want to choose ?");
            printf("\n 1. AND Gate \n 2. OR Gate \n 3. NOT Gate \n 4. XOR Gate \n 5. NAND Gate \n 6. NOR Gate \n 7. XNOR Gate \n 8.Truth Table \n 9. EXIT");
            printf("\n Enter Your Choice: ");
            scanf("%d", &y);

            if (y >= 1 && y <= 7){
                    if(y != 3 ){
                    printf("\n Enter First Input: ");
                    scanf("%d", &a);

                    printf("\n Enter Second Input: ");
                    scanf("%d", &b);

                    if ((a == 0 || a == 1) && (b == 0 || b == 1)){

                        switch (y){
                        case 1:
                            o = a && b;
                            break;
                        case 2:
                            o = a || b;
                            break;
                        case 4:
                            o = ((!a) && b) || ((!b) && a);
                           break;
                        case 5:
                            o = !(a && b);
                            break;
                        case 6:
                            o = !(a || b);
                            break;
                        case 7:
                            o = (a && b) || ((!a) && (!b));
                            break;
                        }
                        printf(" Output : %d", o);

                    }            
                    else{
                        printf("\n Enter Valid Inputs");
                    }   
                    }
                    else{

                        printf("\n Enter Your Input: ");
                        scanf("%d", &a);
                        if ((a == 0 || a == 1)){
                            o = !a;
                            printf(" Output : %d \n", o);
                        }
                        else {
                            printf("\n Enter Valid Inputs \n");
                        }   
                    }
            }

            else if (y == 8){
                printf("\n Which type of Gate do you want to choose ?");
                printf("\n 1. AND Gate \n 2. OR Gate \n 3. NOT Gate \n 4. XOR Gate \n 5. NAND Gate \n 6. NOR Gate \n 7. XNOR Gate");
                printf("\n Enter Your Choice: ");
                scanf("%d", &x);
                if( x >= 1 && x <= 7){

                  if(x != 3){

                    printf("\n [A]   [B]   [O]");	
                        for(a = 0; a <= 1; a++){
                            for(b = 0; b <= 1; b++){
                                switch (x){
                                case 1:
                                            o = a && b; 
                                    break;
                                case 2:
                                            o = a || b; 
                                    break;
                                case 4:
                                            o = ((!a) && b) || ((!b) && a);
                                    break;
                                case 5:
                                            o = !(a && b);
                                    break;
                                case 6:
                                            o = !(a || b); 
                                    break;
                                case 7:
                                            o = (a && b) || ((!a) && (!b));
                                        break;
                                }
                                printf("\n  %d     %d     %d ", a, b, o);
                            }
                        }
                  }
                  else{
                    printf("\n [A]   [O]");
                            for(a = 0; a <= 1; a++){
                                    o = !a;
                                    printf("\n  %d     %d ", a, o);
                            }
                  }
                }
                else{
                    printf("\n Enter Valid Input");
                }

            }

            else if (y == 9){
            printf("\n Thank You for using the program \n");
            screen_running = 0;
            }

            else{
                printf("\n  Enter Valid Inputs");
            }
        }
        
}