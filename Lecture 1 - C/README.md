# 📚 CS50x – Week 1: C

> **Harvard's CS50x** | Introduction to Programming in C

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%201-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/1/)

---

## 🔗 Resources

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 1](https://www.youtube.com/watch?v=SlqjA04_dpk) |
| 📝 Lecture Notes | [cs50.harvard.edu/x/2026/notes/1](https://cs50.harvard.edu/x/2026/notes/1/) |
| 📖 Manual Pages | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 Duck (AI) | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |

---

## 🧠 Key Concepts Covered

### Source Code → Machine Code
- **Source code** is human-readable code written by programmers
- **Machine code** is binary (0s and 1s) understood by computers
- A **compiler** translates source code into machine code
- CS50 uses `make` as a build tool (wraps the `clang` compiler)

### First C Program
```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

**Compiling & Running:**
```bash
make hello        # compile
./hello           # run
```

---

## 🏗️ C Fundamentals

### Data Types
| Type | Description | Size |
|------|-------------|------|
| `bool` | Boolean (`true`/`false`) | 1 bit |
| `char` | Single character | 8 bits |
| `int` | Integer | 32 bits |
| `long` | Large integer | 64 bits |
| `float` | Decimal number | 32 bits |
| `double` | High-precision decimal | 64 bits |
| `string` | Text *(CS50 library)* | — |

### Format Placeholders (printf)
| Placeholder | Type |
|-------------|------|
| `%c` | char |
| `%f` | float / double |
| `%i` | int |
| `%li` | long |
| `%s` | string |

### CS50 Library Functions (`#include <cs50.h>`)
```c
get_char()      // get a single character
get_double()    // get a double
get_float()     // get a float
get_int()       // get an integer
get_long()      // get a long
get_string()    // get a string
```

---

## 🔀 Conditionals

```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

### Operators
| Operator | Meaning |
|----------|---------|
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal |
| `>=` | Greater than or equal |
| `==` | Equal to |
| `!=` | Not equal to |
| `&&` | Logical AND |
| `\|\|` | Logical OR |

---

## 🔁 Loops

### While Loop
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

### For Loop
```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```

### Do-While Loop *(use when you need at least one execution)*
```c
int n;
do
{
    n = get_int("Enter a positive number: ");
}
while (n < 0);
```

---

## 🧩 Variables & Operators

```c
int counter = 0;   // declare and initialize

counter = counter + 1;  // increment (verbose)
counter += 1;           // increment (shorthand)
counter++;              // increment by 1 (shortest)
counter--;              // decrement by 1
```

### Constants
```c
const int SIZE = 3;   // value cannot be changed
```

---

## 📐 Custom Functions

```c
// Prototype (declare before main)
void meow(int n);

int main(void)
{
    meow(3);
}

// Definition
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

---

## ⚡ Escape Sequences

| Sequence | Effect |
|----------|--------|
| `\n` | New line |
| `\t` | Tab |
| `\\` | Backslash |
| `\"` | Double quote |
| `\'` | Single quote |

---

## 🖥️ Linux Terminal Commands

```bash
ls              # list files
mkdir folder    # create directory
cd folder       # change directory
cd ..           # go up one level
cd              # go to home directory
mv src dest     # move or rename file
cp src dest     # copy file
rm file         # remove file
rmdir folder    # remove directory
clear           # clear terminal (Ctrl+L)
```

---

## ⚠️ Common Pitfalls & Limitations

### Integer Overflow
When a value exceeds the maximum storable in the allocated bits, it wraps around (e.g., a 32-bit int overflows at ~2 billion).
```c
// Use long (64-bit) for larger numbers
long big = 10000000000;
```

### Floating Point Imprecision
Floats can't represent every real number precisely — there are infinite real numbers but only finite bits.
```c
float x = 1.0 / 3.0;
// Result: 0.33333334... (not perfectly 0.333...)
```

### Truncation
Integer division discards the decimal:
```c
int result = 1 / 3;  // result = 0, not 0.333
```

---

## 🗂️ Code Quality Axes

| Axis | Description |
|------|-------------|
| ✅ **Correctness** | Does the code do what it's supposed to? |
| 🎨 **Design** | Is it efficient and well-structured? |
| 💅 **Style** | Is it readable and consistently formatted? |

### CS50 Tools
- **`check50`** – automated correctness testing
- **`style50`** – style checker
- **Design50** – AI-powered design feedback (built into VS Code)

---

## 📁 Problem Set 1

Problems can be found at: [cs50.harvard.edu/x/2026/psets/1](https://cs50.harvard.edu/x/2026/psets/1/)

---

## 🔙 Back to Main Repo

[![Repo](https://img.shields.io/badge/GitHub-Nilanchal0107%2FCS50x-black?style=flat-square&logo=github)](https://github.com/Nilanchal0107/CS50x)
