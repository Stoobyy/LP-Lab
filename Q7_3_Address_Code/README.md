# Q7: Three Address Code Generator

## Question
Write a C program to generate Three Address Code for a given arithmetic expression.

## How It Works

The program reads arithmetic expressions and converts them into **Three Address Code (TAC)** — an intermediate representation used in compilers.

### Algorithm

1. **First pass** — scan for `*` and `/` (higher precedence), generate temp variables
2. **Second pass** — scan for `+` and `-` (lower precedence), generate temp variables
3. **Final assignment** — assign the last temp to the result variable

### Example Breakdown

For `a=a+b*c`:

| Step | Operation | TAC |
|------|-----------|-----|
| 1 | `b * c` | `t1 = b * c` |
| 2 | `a + t1` | `t2 = a + t1` |
| 3 | Assign | `a = t2` |

## How to Compile & Run

```bash
gcc program.c -o program
./program
```

> **Note:** Type expressions and press Enter. Press `Ctrl+Z` (Windows) or `Ctrl+D` (Linux) to stop.

## Sample Input

```
a=a+b*c
x=a-b/c+d
```

## Sample Output

```
Enter expressions (Ctrl+D to stop):

Input: a=a+b*c
Three Address Code:
t1 = b * c
t2 = a + 1
a = t2

Input: x=a-b/c+d
Three Address Code:
t1 = b / c
t2 = a - 1
t3 = 1 + d
x = t3
```
