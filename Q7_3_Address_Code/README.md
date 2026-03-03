# Q7: Three Address Code Generator

## Question
Write a C program to generate Three Address Code for a given arithmetic expression.

## How It Works

The program reads arithmetic expressions and converts them into **Three Address Code (TAC)** — an intermediate representation used in compilers.

### Algorithm

1. **First pass** — scan for `*` and `/` (higher precedence), generate temp variables
2. **Second pass** — scan for `+` and `-` (lower precedence), generate temp variables
3. **Final assignment** — assign the last temp to the result variable

## Versions

### `program.c` — Simple Expressions
Works correctly for expressions with one level of operator precedence (e.g., `a=b+c*d`). May produce incorrect chaining for complex expressions with multiple operators at the same precedence level.

### `fixed/program.c` — Complex Expressions
Uses a **token-based approach** to correctly handle complex expressions with multiple operators (e.g., `a=b*c+d*e-f`). Operands and operators are stored in arrays, and results are properly propagated after each operation.

## How to Compile & Run

```bash
gcc program.c -o a.exe
./a.exe
```

For the fixed version:
```bash
cd fixed
gcc program.c -o a.exe
./a.exe
```

## Sample Output

### Simple (`program.c`)

```
Enter expression:
a=b+c*d

Input: a=b+c*d
Three Address Code:
t1 = c * d
t2 = b + t1
a = t2
```

### Fixed (`fixed/program.c`)

```
Enter expression:
a=b*c+d*e-f

Input: a=b*c+d*e-f
Three Address Code:
t1 = b * c
t2 = d * e
t3 = t1 + t2
t4 = t3 - f
a = t4
```
