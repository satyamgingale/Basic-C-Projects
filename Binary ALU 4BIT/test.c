#include <stdio.h>

/*=========================================
          INITIALISING FUNCTIONS
=========================================*/

/*------*/
void Length_Validation_TN(int x, int *n, int *length_valid_x, int w, int *nn, int *length_valid_w);
void BITS_Validation_TN(int x, int *n, int *bits_valid_x, int w, int *nn, int *bits_valid_w);
void Length_Validation_ON(int x, int *n, int *length_valid_x);
void BITS_Validation_ON(int x, int *n, int *bits_valid_x);
/*------*/
void AND_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
void OR_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
void NOT_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
void XOR_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
/*------*/
void Auto_Tester(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int Snl, int *Com_val, int Quotient[8], int Remainder[8], int ww);
void shifter(int Accumulator[8], int Operand_1[8], int Operand_2[8], int S_val,  int Sn, int Snl);
void Comparator(int Accumulator[8], int Operand_1[8], int Operand_2[8], int *Com_val);
/*------*/
void HALF_ADDER(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
void FULL_ADDER(int Accumulator[8], int Operand_1[8], int Operand_2[8]);
void Ripple_Carry_Adder(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val);
/*------*/
void ADD(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val);
void SUB(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val);
void MUL(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int Snl);
void DIV(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int *Com_val, int Quotient[8], int Remainder[8], int ww);

/*=========================================
                MAIN
=========================================*/

int main(){
    int screen_running, z, y, x, xx, t, ww, w, v, r, a, nn, n, valid, length_valid_x, bits_valid_x, length_valid_w, bits_valid_w, Sn, RCA_val, S_val, Snl, Com_val;
    int A[4], B[4], Accumulator[8], D[4], Operand_1[8], Operand_2[8], Remainder [8],  Quotient[8];
    screen_running = 1;
    while (screen_running) {
        printf("\n \n \n \n 1. Continue \n 2. Exit");
        printf("\n -->  ");
        scanf("%d", &z);
        if (z == 1){
            printf("\n 1. ADD \n 2. SUBTRACT \n 3. MULTIPLY \n 4. DIVIDE \n 5. TESTER \n 6. Auto Tester \n 7. EXIT \n");
            printf("-->  ");
            scanf("%d", &y);
            for (a = 0; a < 8; a++) {
                Operand_1[a] = 0;
                Operand_2[a] = 0;
                Accumulator[a] = 0;
                Remainder[a] = 0;
                Quotient[a] = 0;
            }
            if(y <= 4 && y >= 1){
                valid = 0;
                while(valid == 0){
                    printf("\n Enter the first number: ");
                    scanf("%d", &x);
                    printf("\n Enter the second number: ");
                    scanf("%d", &w);

                        Length_Validation_TN(x, &n, &length_valid_x, w, &nn, &length_valid_w);
                        BITS_Validation_TN(x, &n, &bits_valid_x, w, &nn, &bits_valid_w);

                    if(length_valid_x == 1 && bits_valid_x == 1 && length_valid_w == 1 && bits_valid_w == 1) {
                        valid = 1;
                    } else {
                        printf("\n Please re-enter the numbers with valid length and binary format.\n");
                        printf("\n Format Maximum 4 Digits and Binary Numbers (0 or 1) Only.\n");
                        valid = 0;
                    }
                }
                xx = x;
                ww = w;
                for(r = 0; r < 4; r++){
                    v = x % 10;
                    A[r] = v;
                    x = x / 10;
                    Operand_1[r] = A[r];
                                                            /* Creates a Binary Number into Bits And Stores them iNto an Array */
                    v = w % 10;
                    B[r] = v;
                    w = w / 10;
                    Operand_2[r] = B[r];
                } 

                switch (y){
                    case 1:
                        ADD(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val);
                        printf("\n ADD Operation Output: %d ", Accumulator[4]);
                        for(a = 3; a >= 0; a--) {
                            printf("%d", Accumulator[a]);
                        }
                        break;
                    case 2:
                        SUB(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val);
                        printf("\n SUB Operation Output: %d ", Accumulator[4]);
                        for (a = 3; a >= 0; a--) {
                            printf("%d", Accumulator[a]);
                        }
                        break;
                    case 3:
                        MUL(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val, Snl);
                        printf("\n MUL Operation Output: %d ", Accumulator[7]);
                        for (a = 6; a >= 0; a--) {
                            printf("%d", Accumulator[a]);
                        }
                        break;
                    case 4:
                        DIV(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val, &Com_val, Quotient, Remainder, ww);
                        printf("\n DIV Operation Output... ");
                        printf("\n Quotient : ");
                        for (a = 7; a >= 0; a--) {
                            printf("%d", Quotient[a]);
                        }
                        printf("\n Remainder : ");
                        for (a = 7; a >= 0; a--) {
                            printf("%d", Remainder[a]);
                        }
                        break;
                }
                /* These Will be developed further*/
            }
            else if (y == 5){
                printf("\n 1. AND \n 2. OR \n 3. NOT \n 4. XOR \n 5. HALF ADDER \n 6. FULL ADDER \n 7. RIPPLE CARRY ADDER \n 8. BACK \n");
                printf("-->  ");
                scanf("%d", &t);
                if (t >= 1 && t <= 7) {
                    if (t == 3) {
                        valid = 0;
                        while(valid == 0){
                            printf("\n Enter the first number: ");
                            scanf("%d", &x);
                                Length_Validation_ON(x, &n, &length_valid_x);
                                BITS_Validation_ON(x, &n, &bits_valid_x);
                            if(length_valid_x == 1 && bits_valid_x == 1) {
                                valid = 1;
                            } else {
                                printf("\n Please re-enter the numbers with valid length and binary format.\n");
                                printf("\n Format Maximum 4 Digits and Binary Numbers (0 or 1) Only.\n");
                                valid = 0;
                            }
                        }

                        for(r = 0; r < 4; r++){
                            v = x % 10;
                            A[r] = v;                            /* Creates a Binary Number into Bits And Stores them iNto an Array */
                            x = x / 10;
                            Operand_1[r] = A[r];
                        }
                    }
                    else {
                        valid = 0;
                        while(valid == 0){
                            printf("\n Enter the first number: ");
                            scanf("%d", &x);
                            printf("\n Enter the second number: ");
                            scanf("%d", &w);
                            Length_Validation_TN(x, &n, &length_valid_x, w, &nn, &length_valid_w);
                            BITS_Validation_TN(x, &n, &bits_valid_x, w, &nn, &bits_valid_w);
                            if(length_valid_x == 1 && bits_valid_x == 1 && length_valid_w == 1 && bits_valid_w == 1) {
                                valid = 1;
                            } else {
                                printf("\n Please re-enter the numbers with valid length and binary format.\n");
                                printf("\n Format Maximum 4 Digits and Binary Numbers (0 or 1) Only.\n");
                                valid = 0;
                            }
                        }

                        for(r = 0; r < 4; r++){
                            v = x % 10;
                            A[r] = v;
                            x = x / 10;
                            Operand_1[r] = A[r];
                                                                    /* Creates a Binary Number into Bits And Stores them iNto an Array */
                            
                            v = w % 10;
                            B[r] = v;
                            w = w / 10;
                            Operand_2[r] = B[r];
                        }
                    }

                    switch (t) {
                        case 1:
                            AND_Gate(Accumulator, Operand_1, Operand_2);
                            printf("\n AND Gate Output: %d ", Accumulator[4]);
                            for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }
                            break;
                        case 2:
                            OR_Gate(Accumulator, Operand_1, Operand_2);
                            printf("\n OR Gate Output: %d ", Accumulator[4]);
                            for (a = 3; a >= 0; a--) {
                               printf("%d", Accumulator[a]);
                            }
                            break;
                        case 3:
                            NOT_Gate(Accumulator, Operand_1, Operand_2);
                            printf("\n NOT Gate Output: %d ", Accumulator[4]);
                            for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }
                            break;
                        case 4:
                            XOR_Gate(Accumulator, Operand_1, Operand_2);
                            printf("\n XOR Gate Output: %d ", Accumulator[4]);
                            for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }
                            break;
                        case 5:
                            HALF_ADDER(Accumulator, Operand_1, Operand_2);
                            printf("\n HALF ADDER Output: %d %d", Accumulator[1], Accumulator[0]);
                            /*for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }*/
                            break;
                        case 6:
                            FULL_ADDER(Accumulator, Operand_1, Operand_2);
                            printf("\n FULL ADDER Output: %d %d ", Accumulator[1], Accumulator[0]);
                            /*for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }*/
                            break;
                        case 7:
                            Ripple_Carry_Adder(Accumulator, Operand_1, Operand_2, Sn, RCA_val);
                            printf("\n RIPPLE CARRY ADDER Output: %d ", Accumulator[4]);
                            for (a = 3; a >= 0; a--) {
                                printf("%d", Accumulator[a]);
                            }
                            break;
                    } 
                }
                else if (t == 8){
                    /* Need to Developed */
                }
                else {
                    printf("\n Enter a Valid Input");
                }
            }
            else if (y == 6){
                printf("\n Entering Auto Tester ");
                Auto_Tester(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val, Snl, &Com_val, Quotient, Remainder, ww);
            }
            else if (y == 7){
                printf("\n Thank You For Using the Program");
                screen_running = 0;
            }
            else{
                printf("\n Enter a valid Input");
            }
        }
        else if (z == 2){
            printf("\n Thank You For Using the Program");
            screen_running = 0;
        }
        else{
            printf("\n Enter a valid Input");
        }
    }
}



/*=========================================
            VALIDATION FUNCTIONS
=========================================*/

/***********~~ Two Number ~~***********/

void Length_Validation_TN(int x, int *n, int *length_valid_x, int w, int *nn, int *length_valid_w){
	int s, q, u;
/* First Number*/
		printf("\n Validating Input Length Of First Number...");
        	*length_valid_x = 0;
			s = x;
			q = 0;
            if (s == 0) {
            q = 1;  
            }
            else {
                while (s != 0) {
                    s = s / 10;
                    q = q + 1;
                }
            }
            *n = q;
            if (q > 4 || q < 1) {
                printf("\n Invalid Input. Please enter a number with a maximum of 4 digits. And Minimum 1 Digit.");
                printf("\n BITS : %d \n Validation: UnSuccessfull", q);
            }
            else {
                printf("\n Successful Input Length Validation Of First Number...");
                *length_valid_x = 1;
            }
/* Second Number*/
		printf("\n Validating Input Length Of Second Number...");
        	*length_valid_w = 0;
			u = w;
			q = 0;
            if (u == 0) {
                q = 1;
            }
            else {
                while (u != 0) {
                    u = u / 10;
                    q = q + 1;
		        }   
            }
		
		*nn = q;
		if (q > 4 || q < 1) {
			printf("\n Invalid Input. Please enter a number with a maximum of 4 digits. And Minimum 1 Digit.");
			printf("\n BITS : %d \n Validation: UnSuccessfull", q);
		}
		else {
			printf("\n Successful Input Length Validation Of Second Number... \n \n");
			*length_valid_w = 1;
		}
}

void BITS_Validation_TN(int x, int *n, int *bits_valid_x, int w, int *nn, int *bits_valid_w){
	int q, s, v, u;
	printf("\n \n BITs Validation...");
    /* First Number */
        printf("\n \n First Number");
        *bits_valid_x = 0;
        s = x;
        q = 0;
        while(q < *n){
            q = q + 1;
            v = s % 10;
            if (v == 0 || v == 1) {
                printf("\n Round %d: Successfull", q);
                s = s / 10;
                *bits_valid_x = 1;
            }
            else {
                printf("\n Round %d: UnSuccessfull", q);
                printf("\n Invalid Input. Please enter a binary number 0 or 1.");
                break;
            }
        }
    /* Second Number */
        printf("\n \n Second Number");
        *bits_valid_w = 0;
        u = w;
        q = 0;
        while(q < *nn){
            q = q + 1;
            v = u % 10;
            if(v == 0 || v == 1){
                printf("\n Round %d: Successfull", q);
                u = u / 10;
                *bits_valid_w = 1;
            }
            else{
                printf("\n Round %d: UnSuccessfull", q);
                printf("\n Invalid Input. Please enter a binary number 0 or 1.");
                break;
            }
        }
}

/***********~~ One Number ~~***********/

void Length_Validation_ON(int x, int *n, int *length_valid_x){
	int s, q;
/* First Number*/
		printf("\n Validating Input Length Of First Number...");
        	*length_valid_x = 0;
			s = x;
			q = 0;
        if(s == 0){
            q = 1;
        }
        else {
            while (s != 0) {
			s = s / 10;
			q = q + 1;
		    }
        }
		*n = q;
		if (q > 4 || q < 1) {
			printf("\n Invalid Input. Please enter a number with a maximum of 4 digits. And Minimum 1 Digit.");
			printf("\n BITS : %d \n Validation: UnSuccessfull", q);
		}
		else {
			printf("\n Successful Input Length Validation Of First Number...");
			*length_valid_x = 1;
		}
}

void BITS_Validation_ON(int x, int *n, int *bits_valid_x){
	int q, s, v;
	printf("\n \n \n BITs Validation...");
    /* First Number */
        printf("\n \n First Number");
        *bits_valid_x = 0;
        s = x;
        q = 0;
        while(q < *n){
            q = q + 1;
            v = s % 10;
            if (v == 0 || v == 1) {
                printf("\n Round %d: Successfull", q);
                s = s / 10;
                *bits_valid_x = 1;
            }
            else {
                printf("\n Round %d: UnSuccessfull", q);
                printf("\n Invalid Input. Please enter a binary number 0 or 1.");
                break;
            }
        }
}

/*=========================================
                  HELPERS
=========================================*/
void Auto_Tester(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int Snl, int *Com_val, int Quotient[8], int Remainder[8], int ww){
    int Temp_Accumulator, Temp_Operand_1, Temp_Operand_2, Accumulator_Dec, Quotient_Dec, Remainder_Dec, Temp_Quotient, Temp_Remainder;
    int a, r, v, xx, q, w, i;
    Accumulator_Dec = 0;
    for (a = 0; a < 4; a++) {
        if (a == 0) {
            printf("\n Do you wish to continue to Testing od Add (1. Yes  2. No)...");
            scanf("%d", &q);
            if (q == 1) {
                for (Temp_Operand_1 = 0; Temp_Operand_1 < 16; Temp_Operand_1++) {
                    for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Operand_1[i]=0;
                            Operand_2[i]=0;
                            Quotient[i]=0;
                            Remainder[i]=0;
                        }
                    xx = Temp_Operand_1;
                    for(r = 0; r < 8; r++){
                        v = xx %  2;
                        Operand_1[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                        xx = xx / 2;
                    }
                    for (Temp_Operand_2 = 0; Temp_Operand_2 < 16; Temp_Operand_2++) {
                        for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Operand_2[i]=0;
                            Accumulator_Dec = 0;
                        }
                        ww = Temp_Operand_2;
                        w = Temp_Operand_2;
                        for(r = 0; r < 8; r++){
                            v = w %  2;
                            Operand_2[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                            w = w /  2;
                        }
                        Temp_Accumulator = Temp_Operand_1 + Temp_Operand_2;
                        ADD(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val);
                        for(i = 7; i >= 0; i--)
                        {
                            Accumulator_Dec <<= 1;
                            Accumulator_Dec |= Accumulator[i];
                        }
                        if (Temp_Accumulator == Accumulator_Dec) {
                            printf("\n Passed : Round %d of Round %d", Temp_Operand_2, Temp_Operand_1);
                        }
                        else {
                            printf("\n Failed... \n Operand_1 = %d \n Operand_2 = %d \n Accumulator = %d \n Expected = %d", Temp_Operand_1, Temp_Operand_2, Accumulator_Dec, Temp_Accumulator);
                            return;
                        }
                    }
                }
            }
            else{
                break;
            }
        }
        else if (a == 1) {
            printf("\n Do you wish to continue to Testing of Sub (1. Yes  2. No)...");
            scanf("%d", &q);
            if (q == 1) {
                for (Temp_Operand_1 = 0; Temp_Operand_1 < 16; Temp_Operand_1++) {
                        for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Operand_1[i]=0;
                            Operand_2[i]=0;
                            Quotient[i]=0;
                            Remainder[i]=0;
                        }
                    xx = Temp_Operand_1;
                    for(r = 0; r < 8; r++){
                        v = xx % 2;
                        Operand_1[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                        xx = xx / 2;
                    }
                    for (Temp_Operand_2 = 0; Temp_Operand_2 < 16; Temp_Operand_2++) {
                        for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Operand_2[i]=0;
                            Accumulator_Dec = 0;
                            Temp_Accumulator = 0;
                        }
                        ww = Temp_Operand_2;
                        w = Temp_Operand_2;
                        for(r = 0; r < 8; r++){
                            v = w % 2;
                            Operand_2[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                            w = w / 2;
                        }
                        signed char Temp_Accumulator = Temp_Operand_1 - Temp_Operand_2;
                        SUB(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val);
                        
                        for(i = 7; i >= 0; i--)
                        {
                            Accumulator_Dec <<= 1;
                            Accumulator_Dec |= Accumulator[i];
                        }
                        if ((signed char)Temp_Accumulator == (signed char)Accumulator_Dec) {
                            printf("\n Passed : Round %d of Round %d", Temp_Operand_2, Temp_Operand_1);
                        }
                        else {
                            printf("\n Failed... \n Operand_1 = %d \n Operand_2 = %d \n Accumulator = %d \n Expected = %d", Temp_Operand_1, Temp_Operand_2, Accumulator_Dec, Temp_Accumulator);
                            return;
                        }
                    }
                }
            }
            else{
                break;
            }
        }
        else if (a == 2) {
            printf("\n Do you wish to continue to Testing of MUl (1. Yes  2. No)...");
            scanf("%d", &q);
            if (q == 1) {
                for (Temp_Operand_1 = 0; Temp_Operand_1 < 16; Temp_Operand_1++) {
                    for(i=0;i<8;i++){
                        Accumulator[i]=0;
                        Operand_1[i]=0;
                        Operand_2[i]=0;
                        Quotient[i]=0;
                        Remainder[i]=0;
                    }
                    xx = Temp_Operand_1;
                    for(r = 0; r < 8; r++){
                        v = xx % 2;
                        Operand_1[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                        xx = xx / 2;
                    }
                    for (Temp_Operand_2 = 0; Temp_Operand_2 < 16; Temp_Operand_2++) {
                        for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Operand_2[i]=0;
                            Accumulator_Dec = 0;
                            Temp_Accumulator = 0;
                        }
                        ww = Temp_Operand_2;
                        w = Temp_Operand_2;
                        for(r = 0; r < 8; r++){
                            v = w % 2;
                            Operand_2[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                            w = w / 2;
                        }
                        Temp_Accumulator = Temp_Operand_1 * Temp_Operand_2;
                        MUL(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val, Snl);
                        for(i = 7; i >= 0; i--)
                        {
                            Accumulator_Dec <<= 1;
                            Accumulator_Dec |= Accumulator[i];
                        }
                        if (Temp_Accumulator == Accumulator_Dec) {
                            printf("\n Passed : Round %d of Round %d", Temp_Operand_2, Temp_Operand_1);
                        }
                        else {
                            printf("\n Failed... \n Operand_1 = %d \n Operand_2 = %d \n Accumulator = %d \n Expected = %d", Temp_Operand_1, Temp_Operand_2, Accumulator_Dec, Temp_Accumulator);
                            return;
                        }
                    }
                }
            }
            else{
                break;
            }
        }
        else if (a == 3) {
            printf("\n Do you wish to continue to Testing of Div (1. Yes  2. No)...");
            scanf("%d", &q);
            if (q == 1) {
                for (Temp_Operand_1 = 0; Temp_Operand_1 < 16; Temp_Operand_1++) {
                    for(i=0;i<8;i++){
                        Accumulator[i]=0;
                        Operand_1[i]=0;
                        Operand_2[i]=0;
                        Quotient[i]=0;
                        Remainder[i]=0;
                    }
                    xx = Temp_Operand_1;
                    for(r = 0; r < 8; r++){
                        v = xx % 2;
                        Operand_1[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                        xx = xx / 2;
                    }
                    for (Temp_Operand_2 = 0; Temp_Operand_2 < 16; Temp_Operand_2++) {
                        for(i=0;i<8;i++){
                            Accumulator[i]=0;
                            Quotient[i]=0;
                            Remainder[i]=0;
                            Operand_2[i]=0;
                            Accumulator_Dec = 0;
                            Temp_Accumulator = 0;
                            Remainder_Dec = 0;
                            Quotient_Dec = 0;
                            Temp_Quotient = 0;
                            Temp_Remainder = 0;
                        }
                        ww = Temp_Operand_2;
                        w =Temp_Operand_2;
                        for(r = 0; r < 8; r++){
                            v = w % 2;
                            Operand_2[r] = v;                           /* Convert Temp_Operand_1 into Bit array*/
                            w = w / 2;
                        }
                        if(ww==0){
                            continue;
                        }
                        Temp_Quotient = Temp_Operand_1 / Temp_Operand_2;
                        Temp_Remainder = Temp_Operand_1 % Temp_Operand_2;
                        DIV(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val, Com_val, Quotient, Remainder, ww);
                        for(i = 7; i >= 0; i--)
                        {
                            Remainder_Dec <<= 1;
                            Remainder_Dec |= Remainder[i];
                        }
                        for(i = 7; i >= 0; i--)
                        {
                            Quotient_Dec <<= 1;
                            Quotient_Dec |= Quotient[i];
                        }
                        if (Temp_Quotient == Quotient_Dec && Temp_Remainder == Remainder_Dec) {
                            printf("\n Passed : Round %d of Round %d", Temp_Operand_2, Temp_Operand_1);
                        }
                        else {
                            printf("\n Failed... \n Operand_1 = %d \n Operand_2 = %d \n Actual Qoutient = %d \n Expected = %d \n Actual Remainder = %d \n Expected = %d", Temp_Operand_1, Temp_Operand_2, Quotient_Dec, Temp_Quotient, Remainder_Dec, Temp_Remainder);
                            return;
                        }
                    }
                }
            }
            else{
                break;
            }
        }
    }
}
void shifter(int Accumulator[8], int Operand_1[8], int Operand_2[8], int S_val,  int Sn, int Snl){
    int a , b;
	int Shifted_1[8], Shifted_2[8];
    switch (S_val){
        case 1:/* Shifting Right to left for Operand_1*/
				for (a = 0; a < 8; a++){
					Shifted_1[a] = 0;
				}
                for (a = 0; a < Snl; a++) { 
                    b = a + Sn;
                    if (b < 8) {
                        Shifted_1[b] = Operand_1[a];
                    }  
                }
				for (a = 0; a < 8; a++){
					Operand_1[a] = Shifted_1[a];
				}
            break;
        case 2:/* Shifting Right to left for Operand_2*/
				for (a = 0; a < 8; a++){
					Shifted_2[a] = 0;
				}
                for (a = 0; a < Snl; a++) {
                    b = a + Sn;
                    if (b < 8) {
                        Shifted_2[b] = Operand_2[a];         
                    }
                }
				for (a = 0; a < 8; a++){
					Operand_2[a] = Shifted_2[a];
				}
            break;
    
    /*      case 3: Shifting Left to Right for Operand_1
                for (a = 0, b = d; a < Sn; a++) {
                    Operand_1[b] = Operand_1[a];
                    a = c;
                    d = c + Sn;
                }
            break;
        case 4: Shifting Left to Right for Operand_2
                for (a = 0, b = d; a < Sn; a++) {
                    Operand_2[b] = Operand_2[a];
                    a = c;
                    d = c + Sn;
                }
            break;*/
    }
}

void Comparator(int Accumulator[8], int Operand_1[8], int Operand_2[8], int *Com_val){
    int a;
    for (a = 7; a >= 0; a--) {
        if(Operand_1[a] == Operand_2[a]){
			*Com_val = 0; /*which means Operand_1 = Operand_2*/
        }
        else if (Operand_1[a] == 1 && Operand_2[a] == 0) {
			*Com_val = 1;  /*which means Operand_1 > Operand_2*/
			break;
        }		
        else if (Operand_1[a] == 0 && Operand_2[a] == 1) {
			*Com_val = 2;  /*which means Operand_2 > Operand_1*/
			break;
        }
    }
}


/*=========================================
              LOGIC GATES
=========================================*/

void AND_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a;
    for(a = 0; a < 4; a++){
        Accumulator[a] = Operand_1[a] && Operand_2[a];
    }
    Accumulator[4] = 0;
}

void OR_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a;
    for(a = 0; a < 4; a++){
        Accumulator[a] = Operand_1[a] || Operand_2[a];
    }
    Accumulator[4] = 0;
}

void NOT_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a;
    for(a = 0; a < 4; a++){
        Accumulator[a] = !Operand_1[a];
    }
    Accumulator[4] = 0;
}

void XOR_Gate(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a;
    for(a = 0; a < 4; a++){
        Accumulator[a] = ((!Operand_1[a]) && Operand_2[a]) || ((!Operand_2[a]) && Operand_1[a]);
    }
    Accumulator[4] = 0;
}

/*=========================================
                  ADDERS
=========================================*/


void HALF_ADDER(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a;
    int D[4];
    for(a = 0; a < 1; a++){
        Accumulator[a] = ((!Operand_1[a]) && Operand_2[a]) || ((!Operand_2[a]) && Operand_1[a]); // Sum (XOR)
        D[a] = Operand_1[a] && Operand_2[a]; // Carry (AND)
        printf("\n Half Adder Output:  Carry = %d, Sum = %d", D[a], Accumulator[a]);
    }
}

void FULL_ADDER(int Accumulator[8], int Operand_1[8], int Operand_2[8]){
    int a, Cr1, Cr2, Cin, Cout;
    int D[4];
	Cin = 0;
    for(a = 0; a < 1; a++){
	    D[a] = ((!Operand_1[a]) && Operand_2[a]) || ((!Operand_2[a]) && Operand_1[a]);               /* Sum (XOR) */
        Cr1 = Operand_1[a] && Operand_2[a];				                             /* Cr1 : Carry generated directly by A and B. */
	    Cr2 = Cin && D[a];                                           /* Cr2 : Carry generated when the previous carry (Cin) is added to (A XOR B).*/
	    D[a] = ((!Cin) && D[a]) || ((!D[a]) && Cin);				 /* Sum with Carry (OR)*/
	    Cout = Cr1 || Cr2;                                           /* Either of these carries can become the Carry Out, so they are ORed together. */
	    Cin = Cout;                                                  /* Carry In for next iteration */
	    Accumulator[a] = D[a];                                                 /* Saves the Output*/
    }
    Accumulator[1] = Cout;
}
    
void Ripple_Carry_Adder(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val){
    int a, Cr1, Cr2, Cin, Cout, FinalCarry;
    int D[8], Internal_Accumulator[8];
    Cin = 0;
    for(a = 0; a < 8; a++){
	   D[a] = ((!Operand_1[a]) && Operand_2[a]) || ((!Operand_2[a]) && Operand_1[a]);                        /* Sum (XOR) */
	   Cr2 = Cin && D[a];                                                    /* Cr2 : Carry generated when the previous carry (Cin) is added to (A XOR B).*/
	   D[a] = ((!Cin) && D[a]) || ((!D[a]) && Cin);				             /* Sum with Carry (OR)*/
	   Cr1 = Operand_1[a] &&  Operand_2[a];			                                       	 /* Cr1 : Carry generated directly by A and B. */
	   Cout = Cr1 || Cr2;                                                    /* Either of these carries can become the Carry Out, so they are ORed together. */
	   Cin = Cout;                                                           /* Carry In for next iteration */                                                        
	   Internal_Accumulator[a] = D[a];                                                          /* Saves the Output*/
    }
    FinalCarry = Cout;                                                           /* Saves Final Carry Out after the last iteration */
    switch(RCA_val){
        case 1:
            for(a = 0; a < 8; a++){
                Accumulator[a] = Internal_Accumulator[a];
            }
            /* Accumulator[7] = Internal_Accumulator[7];   */                /* To Make it Into 8 bit Change the Accumulator[4] and Internal to 7*/
            break;
        case 2:
            for(a = 0; a < 8; a++){
                Accumulator[a] = Internal_Accumulator[a];
            }
            /* Accumulator[7] = Internal_Accumulator[7];   */             /* To Make it Into 8 bit Change the Accumulator[4] and Internal to 7*/
            break;
        case 3:
            for(a = 0; a < 8; a++){
                Accumulator[a] = Internal_Accumulator[a];
            }
            break;
        case 4:
            break;
    }
}


/*=========================================
             ARITHMETIC UNIT
=========================================*/

void ADD(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val){
    RCA_val = 1;
    Ripple_Carry_Adder(Accumulator, Operand_1, Operand_2, Sn, RCA_val);
}


void SUB(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val){
	int a;
	int A[8], B[8];
    RCA_val = 2;
    for(a = 0; a < 8; a++){
      A[a] = Operand_1[a];
    }
    for(a = 0; a < 8; a++){
      B[a] = Operand_2[a];
    }
	for(a = 0; a < 8; a++){
		Operand_2[a] = !Operand_2[a];                      /*3. Invert B (~B)*/
	}
    for(a=0 ;a<8; a++){
        Operand_1[a] = 0;                             /* Replace A with 0001.*/
    }
    Operand_1[0] = 1;
	Ripple_Carry_Adder(Accumulator, Operand_1, Operand_2, Sn,  RCA_val);     /*5. Use the Ripple Carry Adder to calculate:         ~B + 0001      (This produces the 2's complement of B.)*/
	for(a = 0; a < 8; a++){
        Operand_2[a] = Accumulator[a];                        /* 6. Store the result back into B.*/
	}
	for(a = 0; a < 8; a++){
        Operand_1[a] = A[a];                       /*7. Restore the original value of A from AT.*/
	}
	Ripple_Carry_Adder(Accumulator, Operand_1, Operand_2, Sn, RCA_val);     /* 8. Use the Ripple Carry Adder again to calculate:    A + (-B) */
    for(a = 0; a < 8; a++){
            Operand_2[a] = B[a];                       /* 9. Restore the original value of B from BT.*/
        } 
    
}

void MUL(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int Snl){
    RCA_val = 3;
    int a, b, c;
    int D[8], A[8], B[8];
    Sn = 0;
    Snl = 4;
    for(a = 0; a < 8; a++){
        A[a] = Operand_1[a];
    }
    for(a = 0; a < 8; a++){
        B[a] = Operand_2[a];
    }
    for(b = 0; b < 4; b++){
        for(a = 0; a < 8; a++){
            D[a] = A[a] && B[b];                          /* Multiplication Of Four Bit to One Bit */
        }
        for(a = 0; a < 8; a++){
            Operand_1[a] = D[a];
	    }
        if (Sn == 0){
            for(a = 0; a < 8; a++){
                Operand_2[a] = 0;
            }
        }
        else{
            S_val = 1;
            shifter(Accumulator, Operand_1, Operand_2, S_val, Sn, Snl);
        }
        Ripple_Carry_Adder(Accumulator, Operand_1, Operand_2, Sn, RCA_val);
        for(a = 0; a < 8; a++){
            Operand_2[a] = Accumulator[a];
        }
        Sn = Sn + 1;
    }
    for(a = 0; a < 8; a++){
        Accumulator[a] = Operand_2[a];
    }
    for(a = 0; a < 8; a++){
        Operand_1[a] = A[a];
    }
    for(a = 0; a < 8; a++){
        Operand_2[a] = B[a];
    }
}

void DIV(int Accumulator[8], int Operand_1[8], int Operand_2[8], int Sn, int RCA_val, int S_val, int *Com_val, int Quotient[8], int Remainder [8], int ww){
    int wlc, r, a;
    int A[8], B[8];
	RCA_val = 4;
	r = 0;
	wlc = 1;
    for(a = 0; a < 8; a++){
        A[a] = Operand_1[a];
    }
    for(a = 0; a < 8; a++){
        B[a] = Operand_2[a];
    }
    if (ww == 0) {
        printf("\n Cant Divide a number by zero... \n Re-Enter the Second Number... ");
    }
    else {
        while(wlc != 2){
            Comparator(Accumulator, Operand_1, Operand_2, Com_val);
            if (*Com_val == 0 || *Com_val == 1){
                SUB(Accumulator, Operand_1, Operand_2, Sn, RCA_val, S_val);
                for(a = 0; a < 8; a++){
                    Operand_1[a] = Accumulator[a];
                }
                r = r + 1;
            }
            else if (*Com_val == 2){
                wlc = 2;
            }
        }
        for (a = 0 ; r != 0; a++){
            Quotient[a] = r % 2;
            r = r / 2;
        }
        for(a = 0; a < 8; a++){
            Remainder[a] = Operand_1[a];
        }
    }
     for(a = 0; a < 8; a++){
        Remainder[a] = Remainder[a];
    }
    for(a = 0; a < 8; a++){
        Quotient[a] = Quotient[a];
    }
     for(a = 0; a < 8; a++){
        Operand_1[a] = A[a];
    }
    for(a = 0; a < 8; a++){
        Operand_2[a] = B[a];
    }
}