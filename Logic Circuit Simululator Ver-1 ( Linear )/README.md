Digital Logic Circuit Simulator (Version 1)
Project Overview

This project is a Digital Logic Circuit Simulator written in C.

The program allows a user to build a simple digital circuit by selecting logic gates and providing binary inputs (0 or 1).

Instead of generating an entire truth table, this simulator behaves like a signal flowing through a circuit.

The output of one gate becomes the input of the next gate until all inputs are used.

How The Program Works

Imagine a wire carrying a signal.

Input 1 --->\
             AND ----> OR ----> NOT ----> Final Output
Input 2 --->/           ^
                        |
                    Input 3

                         ^
                     Input 4

The program works similarly.

Step 1

Ask the user:

1. Continue
2. Exit
Step 2

Ask:

How many inputs does your circuit have?

Allowed range:

2 - 26

Example:

4 inputs

means

Input A
Input B
Input C
Input D
Step 3

Ask the user to select the first gate.

1. AND
2. OR
3. NOT
4. XOR
5. NAND
6. NOR
7. XNOR
Step 4

The first gate behaves differently.

If NOT gate

NOT only requires one logical input.

Example:

Input:

1

NOT

Output:

0

So:

used_inputs = 1
Otherwise

The first gate requires:

Input A
Input B

Example:

1 AND 0

Output:

0

Now:

used_inputs = 2
Step 5

The program repeatedly asks for another gate.

Example:

Current output = 0

Select gate:

OR

Enter next input:

1

0 OR 1

Output:

1

The new output is stored inside:

o

Then:

o becomes the next logical signal.
Step 6

Repeat until all inputs are consumed.

Finally:

printf("Final Result : %d", o);

prints the answer.

Example Circuit

Suppose:

Number of inputs = 4

Circuit:

1 AND 0

Output:

0

Then:

0 OR 1

Output:

1

Then:

1 NOT

Output:

0

Final output:

0

Visualized:

1 ----\
       AND ----> OR ----> NOT ----> 0
0 ----/          ^
                 |
                 1
Logic Gates Implemented
Gate	Operation
AND	Both inputs must be 1
OR	At least one input must be 1
NOT	Flips the input
XOR	Inputs must be different
NAND	Opposite of AND
NOR	Opposite of OR
XNOR	Inputs must be same
Program Structure

Main program:

main()

Gate functions:

AND_Gate()

OR_Gate()

NOT_Gate()

XOR_Gate()

NAND_Gate()

NOR_Gate()

XNOR_Gate()

Each function:

Takes previous output.
int o
Takes a new input if required.
Performs the gate operation.
Returns the new output.
New C Concepts Learned
1. Function Prototypes

We declared functions at the top.

int AND_Gate(int o);

int OR_Gate(int o);

Purpose:

Allows main() to use functions before their actual definition.

2. Modular Programming

Instead of writing everything inside main().

We divided work into smaller functions.

Example:

AND_Gate()

OR_Gate()

NOT_Gate()

Benefits:

Cleaner code
Easier debugging
Easier upgrades
3. Passing Arguments

We pass data into functions.

o = AND_Gate(o);

Old output:

o

goes into

AND_Gate()

and returns a new value.

4. Returning Values

Functions send values back.

return o;
5. Input Validation Using While Loops

Used:

while(valid == 0)

Purpose:

Keep asking until the user enters a valid input.

Example:

while(valid == 0)
{
   scanf(...);

   if(valid_input)
   {
      valid = 1;
   }
}
6. State Variable

We used:

o

as the circuit's state.

Think of it as:

The signal currently flowing inside the circuit.

Each gate modifies this signal.

7. String Literals

Used:

char *q;

Example:

q = "AND";

q = "OR";

q = "NOT";

Printed using:

%s

Example:

printf("%d %s %d | %d", a, q, b, o);
8. Input Tracking

Used:

used_inputs

Purpose:

Track how many inputs are already consumed.

Cases:

NOT:

used_inputs = 1;

Other gates:

used_inputs = 2;

Then:

for(e=1;e<=(n-used_inputs);e++)

runs only for the remaining inputs.

Problems We Found During Development
Bug 1

Using:

for(w=0; w=1; w++)

Problem:

w=1

is assignment, not comparison.

This creates an infinite loop.

Bug 2

Input validation loop did not ask for new values.

Fixed by moving:

scanf()

inside the loop.

Bug 3

Using a single valid variable for multiple jobs.

Solution:

valid

valid1

were separated.

Bug 4

The gate selection validation loop accidentally included the entire circuit simulation block.

We moved:

for(...)

inside the correct location.

Bug 5

NOT gate consumes only one logical input.

We introduced:

used_inputs

to correctly count remaining inputs.

Version 1 Design Philosophy

This is not a real circuit builder.

It is a:

Sequential signal-flow simulator.

Signal travels like:

Input
 ↓

Gate

 ↓

Output

 ↓

Next Gate

 ↓

Output

 ↓

Final Result
Future Plans
Version 2

Version 2 will not store an entire circuit beforehand.

Instead, it will introduce:

Branches

Example:

        AND
       /
A ----
       \
        OR
Multiple Exits

Example:

          AND ---> Output 1

Inputs

          XOR ---> Output 2

This will allow one signal path to split into multiple paths.

The simulator will become much closer to a real digital circuit.

Skills Learned

✅ Variables

✅ Operators

✅ if/else

✅ while loops

✅ for loops

✅ switch-case

✅ Functions

✅ Function prototypes

✅ Return values

✅ Input validation

✅ Modular programming

✅ State management

✅ String literals

✅ Algorithm design

✅ Digital logic implementation

Project Name: Digital Logic Circuit Simulator

Language: C

Version: 1.0

Difficulty: Beginner → Intermediate

Learning Goal: Combine C programming fundamentals with Digital Electronics concepts.