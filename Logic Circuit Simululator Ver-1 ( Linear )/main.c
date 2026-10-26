#include <stdio.h>

int AND_Gate(int o);
int OR_Gate(int o);
int NOT_Gate(int o);
int XOR_Gate(int o);
int NAND_Gate(int o);
int NOR_Gate(int o);
int XNOR_Gate(int o);


int main(){
    int z, n, a, b, o, e, g, G, screen_running, valid, valid1, used_inputs;
    char *q;

    screen_running = 1;

    while (screen_running) {
        printf("\n 1. Continue \n 2. EXIT");
        printf("\n -->  ");
        scanf("%d", &z);
        if (z == 1) {
            printf("How many Input Does Your Logic Circuit Hane ( 2 - 26 ): ");
            scanf("%d", &n);

            if (n >= 2 && n <= 26) {
                valid1 = 0;
                while (valid1 == 0) {
                    printf("\n 1. AND Gate \n 2. OR Gate \n 3. NOT Gate \n 4. XOR Gate \n 5. NAND Gate \n 6. NOR Gate \n 7. XNOR Gate");
                    printf("\n Enter the Choice : ");
                    scanf("%d", &g);

                    if(g >= 1 && g <= 7){
                        if (g == 3) {
                            valid = 0;

                            while (valid == 0) {
                                printf("\n Enter Your Input: ");
                                scanf("%d", &a);

                                if ((a == 0 || a == 1)){
                                    q = "NOT";
                                    o = !a;
                                    printf("\n Circuit \n %s %d  | %d", q, a, o);
                                    used_inputs = 1;
                                    valid = 1;
                                }
                                else {
                                    printf("\n Enter Valid Inputs \n");
                                }
                            }
                            
                        }
                        else {
                            valid = 0;

                            while (valid == 0) {
                                printf("\n Enter First Input: ");
                                scanf("%d", &a);

                                printf("\n Enter Second Input: ");
                                scanf("%d", &b);

                                if ((a == 0 || a == 1) && (b == 0 || b == 1)){

                                    switch (g){
                                    case 1:
                                        o = a && b;
                                        q = "AND";
                                        break;
                                    case 2:
                                        o = a || b;
                                        q = "OR";
                                        break;
                                    case 4:
                                        o = ((!a) && b) || ((!b) && a);
                                        q = "XOR";
                                        break;
                                    case 5:
                                        o = !(a && b);
                                        q = "NAND";
                                        break;
                                    case 6:
                                        o = !(a || b);
                                        q = "NOR";
                                        break;
                                    case 7:
                                        o = (a && b) || ((!a) && (!b));
                                        q = "XNOR";
                                        break;
                                    }
                                printf("\n Circuit \n %d %s %d | %d", a, q, b, o);
                                used_inputs = 2;
                                valid = 1;
                                }
                                else{
                                    printf("\n Enter a Valid Input");
                                }
                            }
                            
                        }

                        for (e = 1; e <= ( n - used_inputs ); e++) {
                            printf("\n  \n 1. AND Gate          2. OR Gate \n 3. NOT Gate           4. XOR Gate \n 5. NAND Gate         6. NOR Gate \n 7. XNOR Gate \n");
                            printf("\n Enter Next Gate: ");
                            scanf("%d", &G);
                            if (G >= 1 && G <= 7) {
                                switch(G){
                                case 1:
                                    o = AND_Gate(o);
                                    break;
                                case 2:
                                    o = OR_Gate(o);
                                    break;
                                case 3:
                                    o = NOT_Gate(o);
                                    break;
                                case 4:
                                    o = XOR_Gate(o);
                                    break;
                                case 5:
                                    o = NAND_Gate(o);
                                    break;
                                case 6:
                                    o = NOR_Gate(o);
                                    break;
                                case 7:
                                    o = XNOR_Gate(o);
                                    break;
                                } 
                            } 
                            else {
                                printf("\n Enter a Valid Input");
                                e--;
                                continue;
                            }
                        }

                        valid1 = 1;
                    }
                    else {
                        printf("\n Enter a Valid Input");
                    }
                }

                printf("\n Final Result : %d", o);

                }
            
            else {
                printf("\n Enter a Valid Input");
                break;
            }

        }
        else if (z == 2) {
            printf("Thanks For Using The Program");
            screen_running = 0;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }

}

int AND_Gate(int o){
    int a, b, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = o && b;
            printf("\n %d AND %d | %d", a , b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}

int OR_Gate(int o){
    int b, a, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = o || b;
            printf("\n %d OR %d | %d", a, b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}

int NOT_Gate(int o){
    int a;
    a = o;
    o = !o;
    printf("\n NOT %d | %d", a, o);
    return o;
}

int XOR_Gate(int o){
    int a, b, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = ((!o) && b) || ((!b) && o);
            printf("\n %d XOR %d | %d", a, b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}

int NAND_Gate(int o){
    int a, b, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = !(o && b);
            printf("\n %d NAND %d | %d", a, b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}

int NOR_Gate(int o){
    int a, b, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = !(o || b);
            printf("\n %d NOR %d | %d", a, b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}

int XNOR_Gate(int o){
    int a, b, valid;
    valid = 0;
    while (valid == 0) {
        printf("\n Enter Next Input: ");
        scanf("%d", &b);
        if (b == 1 || b == 0) {
            a = o;
            o = (o && b) || ((!o) && (!b));
            printf("\n %d XNOR %d | %d", a, b, o);
            valid = 1;
        }
        else {
            printf("\n Enter a Valid Input");
        }
    }
    return o;
}