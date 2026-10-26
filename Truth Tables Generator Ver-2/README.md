# THis Version is copy of Ver-1 but with n number of input, with this you can generate a truth table for even 20, 30, ..... etc.

# Truth Table Generator (C Language)

## Project Objective

Create a Truth Table Generator in C that can generate truth tables for multiple logic gates with a user-defined number of inputs.

Supported gates:

* AND
* OR
* NOT
* XOR
* NAND
* NOR
* XNOR

---

# Project Flow

The program works in the following order:

1. Welcome the user.
2. Ask if the user wants to continue.
3. Ask which logic gate to generate.
4. Ask for the number of inputs.
5. Calculate the number of rows using 2^n.
6. Generate input labels (A, B, C, D...).
7. Convert each row number into binary.
8. Store the binary values inside an array.
9. Calculate the gate output.
10. Print the truth table.
11. Ask if the user wants to continue again.

---

# Concepts Learned

## 1. While Loop

### Definition

Repeats a block of code as long as a condition remains true.

### Example

```c
while(condition)
{
    // code
}
```

### Used For

Allowing the user to repeatedly use the program.

---

## 2. For Loop

### Definition

Runs a block of code a fixed number of times.

### Example

```c
for(i = 0; i < n; i++)
{
    // code
}
```

### Used For

* Calculating 2^n
* Generating rows
* Filling arrays
* Printing arrays
* Counting values

---

## 3. Nested Loops

### Definition

A loop inside another loop.

### Example

```c
for(row = 0; row < rows; row++)
{
    for(i = 0; i < n; i++)
    {
        // code
    }
}
```

### Used For

* Creating each row
* Processing every input inside a row

---

## 4. Arrays

### Definition

A collection of variables of the same data type stored together.

### Example

```c
int input[10];
```

### Used For

Storing the binary inputs of a row.

Example:

```text
input[0] = 1
input[1] = 0
input[2] = 1
input[3] = 1
```

---

## 5. Binary Conversion

### Idea

Every row number was converted to binary.

Algorithm:

```text
Take row

↓

Use % 2

↓

Store remainder

↓

Use / 2

↓

Repeat until complete
```

Example:

```text
13

↓

1101
```

---

## 6. Switch Statement

### Definition

Executes different code blocks depending on the user's choice.

### Example

```c
switch(choice)
{
    case 1:
        break;

    case 2:
        break;
}
```

### Used For

Selecting logic gates.

---

## 7. Break Statement

### Definition

Immediately exits a loop.

### Example

```c
if(input[i] == 0)
{
    break;
}
```

### Used For

AND, OR, NAND and NOR gates.

---

## 8. ASCII Characters

### Definition

Characters are stored internally as numbers.

Examples:

```text
'A' = 65

'B' = 66

'C' = 67
```

### Used For

Automatically generating:

```text
A B C D E ...
```

---

## 9. Logical NOT Operator

### Definition

Flips a logical value.

Examples:

```text
!0 = 1

!1 = 0
```

### Used For

* NOT
* NAND
* NOR
* XNOR

---

# Gate Logic Discovered

## AND

```text
Start with 1

↓

Look for 0

↓

If found

↓

Output = 0
```

---

## OR

```text
Start with 0

↓

Look for 1

↓

If found

↓

Output = 1
```

---

## XOR

```text
Count number of 1s

↓

Odd = 1

↓

Even = 0
```

---

## NAND

```text
AND

↓

Flip output
```

---

## NOR

```text
OR

↓

Flip output
```

---

## XNOR

```text
XOR

↓

Flip output
```

---

# Important Formulas

## Number of rows

```text
2^n
```

Where:

```text
n = number of inputs
```

Examples:

```text
n = 2

↓

4 rows

n = 3

↓

8 rows

n = 4

↓

16 rows
```

---

# Problem Solving Lessons Learned

1. Avoid hard-coding.

2. Break large problems into smaller steps.

3. Separate calculation and printing.

4. Reuse existing logic instead of creating new algorithms.

5. Use arrays when the number of values changes.

6. Think about program flow before writing code.

---

# Biggest Takeaway

7 logic gates do not require 7 separate algorithms.

Only 3 base algorithms are needed:

* AND
* OR
* XOR

Then:

```text
NAND = AND + flip

NOR = OR + flip

XNOR = XOR + flip
```

---

# Project Difficulty

⭐⭐⭐☆☆ (3/5)

Topics used:

* Variables
* If/Else
* While Loop
* For Loop
* Nested Loops
* Arrays
* Switch
* Break
* Binary Conversion
* ASCII Characters
* Logic Gates
* Algorithm Design

---

# Author Notes

This was my first algorithm-heavy C project.

The main lesson was:

"Do not hard-code solutions. Build a system that works for any number of inputs."
