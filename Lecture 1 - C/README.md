# 📚 CS50x – Week 1: C
### Harvard University's Introduction to Programming in C

> *"A lot of today's ideas are exactly the same as last week's ideas. It's just that the syntax is going to change."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%201-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/1/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=SlqjA04_dpk)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 1](https://www.youtube.com/watch?v=SlqjA04_dpk) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/1](https://cs50.harvard.edu/x/2026/notes/1/) |
| 📖 CS50 Manual Pages | [manual.cs50.io](https://manual.cs50.io/) |
| 📖 Standard C Manual | [manual.cs50.io/3/printf](https://manual.cs50.io/3/printf) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 1 | [cs50.harvard.edu/x/2026/psets/1](https://cs50.harvard.edu/x/2026/psets/1/) |

---

## 📋 Table of Contents

1. [From Scratch to C](#-from-scratch-to-c)
2. [Source Code vs Machine Code](#-source-code-vs-machine-code)
3. [Compilers](#-compilers)
4. [Visual Studio Code (VS Code)](#-visual-studio-code-vs-code)
5. [GUI vs CLI](#-gui-vs-cli)
6. [Your First C Program](#-your-first-c-program)
7. [Compiling and Running](#-compiling-and-running)
8. [Anatomy of a C Program](#-anatomy-of-a-c-program)
9. [Header Files & Libraries](#-header-files--libraries)
10. [The CS50 Library](#-the-cs50-library)
11. [printf & Format Placeholders](#-printf--format-placeholders)
12. [Escape Sequences](#-escape-sequences)
13. [Variables & Data Types](#-variables--data-types)
14. [Getting User Input](#-getting-user-input)
15. [Operators](#-operators)
16. [Conditionals in C](#-conditionals-in-c)
17. [Boolean Expressions & Logical Operators](#-boolean-expressions--logical-operators)
18. [Loops in C](#-loops-in-c)
19. [While Loop](#-while-loop)
20. [For Loop](#-for-loop)
21. [Do-While Loop](#-do-while-loop)
22. [Infinite Loops & Control Flow](#-infinite-loops--control-flow)
23. [Scope of Variables](#-scope-of-variables)
24. [Custom Functions in C](#-custom-functions-in-c)
25. [Function Prototypes](#-function-prototypes)
26. [Linux Terminal Commands](#-linux-terminal-commands)
27. [Nested Loops — 2D Grids](#-nested-loops--2d-grids)
28. [Constants](#-constants)
29. [Arithmetic Operators](#-arithmetic-operators)
30. [Integer Overflow](#-integer-overflow)
31. [Floating Point Imprecision](#-floating-point-imprecision)
32. [Truncation](#-truncation)
33. [Real-World Bugs from These Issues](#-real-world-bugs-from-these-issues)
34. [Code Quality in C](#-code-quality-in-c)
35. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🔄 From Scratch to C

Week 0 used **Scratch** — a visual, drag-and-drop language — to build a mental model of programming. Every concept from Scratch maps directly to C. Only the **syntax** (the way you write it) changes.

| Scratch Concept | C Equivalent |
|-----------------|-------------|
| Purple `say` block | `printf("hello, world\n");` |
| Yellow `when 🚩 clicked` | `int main(void) { ... }` |
| Orange `if` block | `if (condition) { ... }` |
| Orange `repeat` block | `for (int i = 0; i < n; i++) { ... }` |
| Blue `ask and wait` | `get_string("What's your name? ")` |
| Variable block | `int score = 0;` |
| Custom block `define meow` | `void meow(int n) { ... }` |

> 💡 The ideas are identical. C just looks scarier because of its syntax — but muscle memory comes with practice.

---

## 💾 Source Code vs Machine Code

### Source Code
**Source code** is what YOU write — human-readable text in a programming language like C.

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

Humans can read this (with some training). Computers cannot.

### Machine Code
**Machine code** is what the COMPUTER understands — raw binary zeros and ones.

```
01001000 01100101 01101100 01101100 01101111 ...
```

No human wants to write this. But it's the only thing CPUs actually execute.

### The Gap
```
Source Code  →  [ ??? ]  →  Machine Code
(human-readable)              (computer-readable)
```

We need something to bridge this gap — a **compiler**.

---

## ⚙️ Compilers

A **compiler** is a program that translates source code into machine code.

```
┌─────────────┐          ┌──────────┐          ┌──────────────┐
│ Source Code │  ──────▶ │ COMPILER │  ──────▶ │ Machine Code │
│  (hello.c)  │          │  (make)  │          │   (hello)    │
└─────────────┘          └──────────┘          └──────────────┘
```

- **Input:** Source code (e.g., `hello.c`)
- **Output:** Machine code (e.g., `hello` — an executable file)
- **Tool we use:** `make` (which internally calls `clang`, a popular C compiler)

A compiler does two important jobs:
1. **Translates** source code to machine code
2. **Finds mistakes** in your code and tries to point them out with error messages

> 💡 `make` is technically a build automation tool. The actual compiler underneath is `clang`. CS50 uses `make` as a simplification — we'll learn what's really happening next week.

---

## 🖥️ Visual Studio Code (VS Code)

**Visual Studio Code** (VS Code) is the code editor used in CS50. It's one of the most popular editors in the real world, used by professional developers everywhere.

CS50 provides a **cloud-based version** at [cs50.dev](https://cs50.dev) so everything is pre-installed and pre-configured — no setup required. By the end of the course, you can install it locally on your own Mac or PC.

### VS Code Layout

```
┌──────────────────────────────────────────────────────────────┐
│ ACTIVITY BAR │    CODE TABS (top right)                      │
│   (left)     │  ┌────────────────────────────────────────┐   │
│              │  │  hello.c                               │   │
│ FILE         │  │                                        │   │
│ EXPLORER     │  │  #include <stdio.h>                    │   │
│   (left)     │  │                                        │   │
│              │  │  int main(void)                        │   │
│              │  │  {                                     │   │
│              │  │      printf("hello, world\n");         │   │
│              │  │  }                                     │   │
│              │  └────────────────────────────────────────┘   │
│              │  ┌────────────────────────────────────────┐   │
│              │  │  TERMINAL WINDOW (bottom right)        │   │
│              │  │  $ make hello                          │   │
│              │  │  $ ./hello                             │   │
│              │  │  hello, world                          │   │
│              │  └────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────┘
```

### Key Features
| Feature | Description |
|---------|-------------|
| **Syntax Highlighting** | VS Code colors different parts of your code automatically to make it readable |
| **Tabs** | Multiple files open at once, like browser tabs |
| **Terminal Window** | Built-in command line at the bottom — where you compile and run code |
| **File Explorer** | Shows all your files and folders on the left |
| **Auto-complete** | Suggests completions as you type (use `Tab` to accept) |

---

## 🖱️ GUI vs CLI

### GUI — Graphical User Interface
An interface with icons, buttons, windows, and a mouse. Examples: Windows Explorer, macOS Finder, VS Code's file explorer panel.

### CLI — Command Line Interface
An interface where you type commands as text. Examples: the Terminal window in VS Code, macOS Terminal, Linux shell.

```
$ make hello        ← you type commands here
$ ./hello
hello, world
$
```

The `$` symbol is called the **command prompt**. It means "type your command here." It has nothing to do with money — it's just a convention. Some systems use `>` or `%` instead.

> 💡 Most professional programmers spend the majority of their time in the CLI. It feels like a step backward at first, but it's ultimately far more powerful and efficient than a GUI for coding tasks.

---

## 👋 Your First C Program

```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

This is the canonical "Hello, World" program — traditionally the first program anyone writes in a new language.

### What Each Part Does
| Part | Purpose |
|------|---------|
| `#include <stdio.h>` | Imports the standard I/O library (needed for `printf`) |
| `int main(void)` | The main function — every C program starts here |
| `{` and `}` | Curly braces define the body of the function |
| `printf(...)` | Prints text to the screen |
| `"hello, world\n"` | The text to print (`\n` = new line) |
| `;` | Semicolon ends every statement (like a period ends a sentence) |

---

## 🔨 Compiling and Running

### Step 1 — Create the file
```bash
code hello.c
```
This opens a new tab in VS Code called `hello.c`.

### Step 2 — Write your code
Type your C code in the editor.

### Step 3 — Compile
```bash
make hello
```
- No output = success ✅
- Output with errors = something is wrong ❌

This creates a new file called `hello` (the compiled machine code).

### Step 4 — Run
```bash
./hello
```
Output:
```
hello, world
```

The `./` means "look in the current folder and run the program called `hello`."

### The Full Cycle
```
Write code  →  make hello  →  ./hello  →  See output
    ↑                                          │
    └──────────── fix bugs & repeat ───────────┘
```

> ⚠️ Every time you change your source code, you **must recompile** with `make` before running. Running the old compiled version won't show your changes.

---

## 🔬 Anatomy of a C Program

```c
#include <cs50.h>       // ← Header file (library import)
#include <stdio.h>      // ← Another header file

int main(void)          // ← Main function signature
{                       // ← Opening curly brace
    string name = get_string("What's your name? ");  // ← Variable + function call
    printf("hello, %s\n", name);                     // ← printf with placeholder
}                       // ← Closing curly brace
```

### Rules Every C Program Must Follow
1. Every program must have a `main` function — execution starts there
2. Every statement ends with a **semicolon** `;`
3. Strings (text) are surrounded by **double quotes** `"like this"`
4. Single characters use **single quotes** `'A'`
5. Code inside a function goes between **curly braces** `{ }`
6. Indent by **4 spaces** inside every set of curly braces (style convention)

---

## 📚 Header Files & Libraries

C comes with hundreds of pre-written functions. To use them, you need to include the **header file** that defines them.

```c
#include <stdio.h>     // Standard Input/Output — printf, scanf, etc.
#include <cs50.h>      // CS50 library — get_string, get_int, etc.
#include <string.h>    // String functions — strlen, strcmp, etc.
#include <math.h>      // Math functions — sqrt, pow, etc.
```

### What is a Header File?
A header file (ending in `.h`) contains **declarations** of functions — it tells the compiler "this function exists and here's what it looks like." The actual implementation is in a separate compiled library file.

### What is a Library?
A **library** is code someone else wrote that you can use. Instead of re-implementing `printf` yourself (which involves talking to the operating system, managing output buffers, etc.), you simply `#include <stdio.h>` and use it.

> 💡 This is **abstraction** in action. You don't need to know how `printf` works internally — you just know what it does and how to call it.

### Where to Look Things Up
| Resource | URL |
|----------|-----|
| CS50 Manual (simplified) | [manual.cs50.io](https://manual.cs50.io/) |
| Specific function (e.g., printf) | [manual.cs50.io/3/printf](https://manual.cs50.io/3/printf) |
| CS50 Library | [manual.cs50.io/#cs50](https://manual.cs50.io/#cs50) |

> ⚠️ A very common typo: `studio.h` ← **WRONG**. It's `stdio.h` (standard I/O, not studio).

---

## 🏫 The CS50 Library

CS50 provides its own library (`cs50.h`) as **training wheels** for the first few weeks. Certain things in C (like getting user input safely) are surprisingly hard to do correctly from scratch. CS50's library handles this for you.

```c
#include <cs50.h>
```

### CS50 Input Functions

| Function | Returns | Example |
|----------|---------|---------|
| `get_string("Prompt: ")` | `string` | A name, sentence, or any text |
| `get_int("Prompt: ")` | `int` | A whole number like 42 |
| `get_long("Prompt: ")` | `long` | A large whole number |
| `get_float("Prompt: ")` | `float` | A decimal like 3.14 |
| `get_double("Prompt: ")` | `double` | A high-precision decimal |
| `get_char("Prompt: ")` | `char` | A single character like 'Y' |

### Built-in Error Checking
CS50's functions automatically **re-prompt** if the user gives invalid input:
```
$ ./program
Enter a number: dog       ← not a number!
Enter a number: cat       ← still not a number!
Enter a number: 42        ← accepted ✅
```

> 💡 `get_string` in CS50 is a `string` type — which is CS50's own simplified type. In standard C, strings are character arrays (`char *`), which we'll explore later in the course.

---

## 🖨️ printf & Format Placeholders

`printf` (print formatted) outputs text to the screen. It's more powerful than Scratch's `say` because you can embed **variable values** using placeholders.

### Basic Usage
```c
printf("hello, world\n");
```

### With a Placeholder
```c
string name = get_string("What's your name? ");
printf("hello, %s\n", name);
// Output: hello, David
```

### Format Placeholders

| Placeholder | Data Type | Example |
|-------------|-----------|---------|
| `%s` | string | `"hello, %s"` → `hello, David` |
| `%c` | char (single character) | `"Grade: %c"` → `Grade: A` |
| `%i` | int (integer) | `"Score: %i"` → `Score: 42` |
| `%f` | float / double | `"Price: %f"` → `Price: 3.140000` |
| `%li` | long integer | `"Big: %li"` → `Big: 1234567890` |

### Multiple Placeholders
```c
int x = 1;
int y = 2;
printf("x is %i, y is %i\n", x, y);
// Output: x is 1, y is 2
```

### Controlling Decimal Places
```c
printf("%.2f\n", 3.14159);   // Output: 3.14
printf("%.50f\n", 1.0 / 3);  // Shows imprecision!
```

> 💡 The comma **inside** quotes (e.g., `"hello, %s"`) is just English punctuation. The comma **outside** quotes separates arguments to `printf`. These are two different things happening in the same line.

---

## 🔤 Escape Sequences

Escape sequences are special character combinations starting with `\` that represent characters you can't easily type directly.

| Sequence | Effect | Common Use |
|----------|--------|-----------|
| `\n` | New line (moves cursor to next line) | End of every `printf` |
| `\t` | Tab (horizontal indent) | Formatting output |
| `\\` | Literal backslash `\` | Printing file paths |
| `\"` | Literal double quote `"` | Printing quotes inside strings |
| `\'` | Literal single quote `'` | Printing apostrophes |
| `\r` | Carriage return (cursor to start of line) | Old typewriter behavior |

### Why `\n` Matters
```c
printf("hello, world");    // Output: hello, world$  ← prompt on same line (ugly)
printf("hello, world\n");  // Output: hello, world   ← prompt on new line (clean)
                           //         $
```

### Why `\"` Exists
```c
// This would confuse the compiler — where does the string end?
printf("She said "hello" to me");   // ❌ WRONG

// Escape the inner quotes
printf("She said \"hello\" to me"); // ✅ CORRECT
```

### Why Not Just Press Enter?
```c
printf("hello,
world\n");   // ❌ WRONG — C is line-based, don't split statements across lines
```

C (like most languages) is **line-based** — you start and finish a thought on one line. Use `\n` inside the string to get a new line in the *output*.

---

## 📦 Variables & Data Types

### Declaring a Variable
In C, you must always tell the compiler **what type** of data a variable will hold:

```c
type variable_name = initial_value;
```

```c
int score = 0;              // integer, starts at 0
string name = "Alice";      // text (CS50 type)
float temperature = 98.6;   // decimal number
char grade = 'A';           // single character
bool passing = true;        // true or false
```

### Data Types in C

| Type | Description | Size | Range |
|------|-------------|------|-------|
| `bool` | Boolean: `true` or `false` | 1 bit | true / false |
| `char` | Single character | 8 bits (1 byte) | 0–127 (ASCII) |
| `int` | Whole number | 32 bits (4 bytes) | ~ -2 billion to +2 billion |
| `long` | Large whole number | 64 bits (8 bytes) | ~ ±9 quintillion |
| `float` | Decimal number | 32 bits (4 bytes) | ~7 significant digits |
| `double` | High-precision decimal | 64 bits (8 bytes) | ~15 significant digits |
| `string` | Text *(CS50 only)* | varies | any text |

### Naming Rules
- Use **lowercase** for variable names (`score`, not `Score`)
- **No spaces** in names (`first_name`, not `first name`)
- Use **descriptive names** (`counter` not `c`, `number_of_students` not `n`)
- Names may contain letters, digits, and underscores, but must start with a letter

### Incrementing & Decrementing

```c
counter = counter + 1;  // verbose: add 1
counter += 1;           // shorthand: add 1
counter++;              // shortest: add exactly 1

counter = counter - 1;  // verbose: subtract 1
counter -= 1;           // shorthand: subtract 1
counter--;              // shortest: subtract exactly 1

counter += 5;           // add 5 (no shorthand for this)
counter *= 2;           // multiply by 2
```

---

## 🎤 Getting User Input

### Getting a String
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
```

```
What's your name? David
hello, David
```

### Getting an Integer
```c
int age = get_int("How old are you? ");
printf("You are %i years old.\n", age);
```

### Getting a Character
```c
char answer = get_char("Do you agree? ");
if (answer == 'Y' || answer == 'y')
{
    printf("Agreed!\n");
}
```

### Assignment vs. Declaration
```c
string name = get_string("Name: ");   // ← DECLARES and assigns (line 1 usage)
name = get_string("Name again: ");    // ← Just assigns (variable already exists)
```
- First time using a variable: specify the **type** (creates it in memory)
- Subsequent uses: just use the **name** (it already exists)

---

## ➕ Operators

### Arithmetic Operators
| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` | Addition | `3 + 2` | `5` |
| `-` | Subtraction | `5 - 3` | `2` |
| `*` | Multiplication | `4 * 3` | `12` |
| `/` | Division | `10 / 3` | `3` (integer!) |
| `%` | Modulo (remainder) | `10 % 3` | `1` |

### Comparison Operators
| Operator | Meaning | Example |
|----------|---------|---------|
| `<` | Less than | `x < y` |
| `>` | Greater than | `x > y` |
| `<=` | Less than or equal to | `x <= y` |
| `>=` | Greater than or equal to | `x >= y` |
| `==` | Equal to (two equals signs!) | `x == y` |
| `!=` | Not equal to | `x != y` |

### Assignment Operator
```c
int x = 5;    // = means ASSIGN (copy right side into left side)
```

> ⚠️ **Critical difference:**
> - `=` is **assignment** — puts a value into a variable
> - `==` is **equality check** — asks "are these two things equal?"
>
> ```c
> x = 5;      // SETS x to 5
> x == 5;     // ASKS: is x equal to 5? (true or false)
> ```
> Using `=` when you mean `==` inside an `if` is one of the most common bugs in C.

---

## 🔀 Conditionals in C

### Simple If
```c
if (x < y)
{
    printf("x is less than y\n");
}
```

### If / Else
```c
if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}
```

### If / Else If / Else
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

### Good Design: Avoid Unnecessary Questions
❌ **Bad design — asks 3 questions every time:**
```c
if (x < y)
{
    printf("x is less than y\n");
}
if (x > y)                          // ← wasteful: still checks even if first was true
{
    printf("x is greater than y\n");
}
if (x == y)                         // ← wasteful: we already know if neither above was true
{
    printf("x is equal to y\n");
}
```

✅ **Good design — uses else if to short-circuit:**
```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else                                // ← no need to ask x == y; it must be true by elimination
{
    printf("x is equal to y\n");
}
```

> 💡 With `else if`, as soon as one condition is true, the rest are **skipped**. With separate `if` statements, **all** are checked every time — which wastes CPU time and is bad design.

---

## 🔗 Boolean Expressions & Logical Operators

### Logical AND `&&`
True only if **both** conditions are true:
```c
if (answer == 'Y' && score > 0)
{
    printf("Yes and positive score!\n");
}
```

### Logical OR `||`
True if **at least one** condition is true:
```c
if (answer == 'Y' || answer == 'y')
{
    printf("Agreed!\n");
}
```

### Logical NOT `!`
Flips true to false and false to true:
```c
if (!(x == y))      // equivalent to: if (x != y)
{
    printf("Not equal\n");
}
```

### Common Mistake — Using AND When OR is Correct
```c
char c = get_char("Press Y or N: ");

// ❌ WRONG — c cannot simultaneously be both 'Y' AND 'y'
if (c == 'Y' && c == 'y')

// ✅ CORRECT — c is either 'Y' OR 'y'
if (c == 'Y' || c == 'y')
```

---

## 🔁 Loops in C

C has three types of loops, each best suited for different situations.

---

## 🔄 While Loop

Best for: repeating **while a condition is true**, when you don't know in advance how many times.

### Syntax
```c
while (condition)
{
    // code to repeat
}
```

### Counting Down from 3
```c
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i--;             // ← don't forget this or you'll loop forever!
}
```

### Counting Up from 0
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

Both print "meow" exactly 3 times.

---

## 🔂 For Loop

Best for: repeating a **known number of times**. More compact than a while loop.

### Syntax
```c
for (initialization; condition; update)
{
    // code to repeat
}
```

### Breakdown
```c
for (int i = 0; i < 3; i++)
//   ├─────────┤  ├───┤  ├──┤
//   initialize  check  update (runs after each iteration)
{
    printf("meow\n");
}
```

**Execution order:**
1. `int i = 0` — runs once at the start
2. `i < 3` — checked before every iteration
3. Body executes if condition is true
4. `i++` — runs after every iteration
5. Go back to step 2

### Conventional Style
```c
// Standard: start at 0, go up to (not through) n
for (int i = 0; i < n; i++)

// Alternative: start at 1, use <=
for (int i = 1; i <= n; i++)    // works but less conventional

// Convention in CS: 0-based indexing is standard
```

---

## 🔃 Do-While Loop

Best for: when you need to execute the body **at least once** before checking the condition — like prompting a user for input.

### Syntax
```c
do
{
    // code runs at least once
}
while (condition);   // ← semicolon here!
```

### User Input Validation
```c
int n;
do
{
    n = get_int("Enter a positive number: ");
}
while (n < 0);   // keep asking while n is negative
```

### Key Difference from While Loop
| Loop Type | When condition is checked |
|-----------|--------------------------|
| `while` | **Before** the first iteration |
| `do-while` | **After** the first iteration (body always runs at least once) |

> 💡 The do-while loop is perfect for "ask once, then keep asking if wrong." You always want to ask at least once — the question should come before the validation.

---

## ♾️ Infinite Loops & Control Flow

### Deliberate Infinite Loop
```c
while (true)
{
    printf("meow\n");
}
```
This runs forever until you kill it with **Ctrl+C** in the terminal.

### `break` — Exit a Loop Early
```c
while (true)
{
    int n = get_int("Enter a positive number: ");
    if (n >= 0)
    {
        break;   // exit the loop immediately
    }
}
```

### `continue` — Skip to the Next Iteration
```c
while (true)
{
    int n = get_int("Enter a positive number: ");
    if (n < 0)
    {
        continue;   // go back to the top of the loop
    }
    break;          // only reached if n >= 0
}
```

### Tightened Version Using Only `break`
```c
int n;
while (true)
{
    n = get_int("Enter a positive number: ");
    if (n >= 0)
    {
        break;
    }
}
// n is now guaranteed to be >= 0
```

### Stopping an Infinite Loop
If your program gets stuck in an infinite loop:
- Press **Ctrl+C** in the terminal to interrupt it
- VS Code may also warn you about high CPU usage

---

## 🔭 Scope of Variables

**Scope** refers to where in the program a variable is visible and usable.

A variable exists only within the **curly braces** `{ }` in which it was declared.

### Scope Problem
```c
while (true)
{
    int n = get_int("Number: ");   // n declared INSIDE the loop
    if (n >= 0)
    {
        break;
    }
}
printf("%i\n", n);   // ❌ ERROR: n doesn't exist out here!
```

### Fix — Declare Outside the Loop
```c
int n;                             // declared OUTSIDE — exists everywhere below
while (true)
{
    n = get_int("Number: ");       // assigned inside (no 'int' — already exists)
    if (n >= 0)
    {
        break;
    }
}
printf("%i\n", n);   // ✅ works now
```

### General Rule
```c
{
    int x = 5;    // x exists from here...
    // x is accessible here
}
// x no longer exists here ← out of scope
```

> 💡 Each function also has its own scope. Variables declared in `main` cannot be seen by other functions, and vice versa — unless explicitly passed as arguments.

---

## 🧱 Custom Functions in C

You can create your own functions in C — just like making a custom block in Scratch.

### Basic Structure
```c
return_type function_name(parameter_type parameter_name)
{
    // body of function
}
```

### Function With No Input, No Output (Side Effect Only)
```c
void meow(void)             // void = no input, void = no output
{
    printf("meow\n");
}

int main(void)
{
    meow();                 // call it
    meow();
    meow();
}
```

### Function With Input (Argument)
```c
void meow(int n)            // takes one integer argument called n
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}

int main(void)
{
    meow(3);                // meow 3 times
    meow(5);                // meow 5 times
}
```

### Function With Output (Return Value)
```c
int get_positive_int(void)  // returns an int
{
    int n;
    do
    {
        n = get_int("Enter a positive integer: ");
    }
    while (n < 0);
    return n;               // ← hand back the value
}

int main(void)
{
    int number = get_positive_int();   // receive the returned value
    printf("You entered: %i\n", number);
}
```

### Anatomy of a Function Call
```c
printf("hello, %s\n", name);
// ├────┤ ├─────────────────┤
// name   arguments (inputs)
// of
// function
```

---

## 📋 Function Prototypes

In C, the compiler reads your file **top to bottom**. If you call a function before defining it, the compiler gives an error: "undeclared function."

### The Problem
```c
int main(void)
{
    meow(3);        // ❌ ERROR: compiler hasn't seen 'meow' yet!
}

void meow(int n)    // defined down here, too late
{
    ...
}
```

### Solution 1 — Define Before main (works but clutters the top)
```c
void meow(int n) { ... }    // defined first

int main(void) { ... }       // main comes after
```

### Solution 2 — Use a Prototype (best practice)
A **prototype** is just the first line of your function followed by a semicolon. It's a **promise** to the compiler that this function will be defined somewhere later in the file.

```c
void meow(int n);   // ← prototype (promise to the compiler)
int get_positive_int(void);   // ← another prototype

int main(void)
{
    meow(3);                     // ✅ compiler knows meow exists
    int n = get_positive_int();  // ✅ compiler knows this exists too
}

void meow(int n)    // ← actual definition (can be anywhere below main)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}

int get_positive_int(void)
{
    int n;
    do { n = get_int("Number: "); } while (n < 0);
    return n;
}
```

> 💡 Prototypes are the **only acceptable time** to copy-paste in C. Copy the function signature, add a semicolon, and paste it above `main`.

---

## 🐧 Linux Terminal Commands

CS50's coding environment runs **Linux** — a popular operating system used by most servers, supercomputers, and many professional developers.

### Essential Commands

| Command | Full Name | What It Does | Example |
|---------|-----------|-------------|---------|
| `ls` | list | List files and folders in current directory | `ls` |
| `cd folder` | change directory | Move into a folder | `cd week1` |
| `cd ..` | change directory up | Go up one level | `cd ..` |
| `cd` | change directory home | Go to your home/default folder | `cd` |
| `mkdir name` | make directory | Create a new folder | `mkdir week1` |
| `rm file` | remove | Delete a file | `rm hello` |
| `rmdir folder` | remove directory | Delete an empty folder | `rmdir old` |
| `mv src dest` | move | Move OR rename a file | `mv hello.c old.c` |
| `cp src dest` | copy | Copy a file | `cp hello.c backup.c` |
| `clear` | clear | Clear the terminal screen | `clear` |
| `code file` | VS Code open | Open/create a file in VS Code | `code hello.c` |
| `make prog` | make | Compile a program | `make hello` |
| `./prog` | run | Run a compiled program | `./hello` |

### Navigation Tips
```bash
# Use Tab to autocomplete
$ cd wee[TAB]       → $ cd week1/

# Use Up/Down arrows to scroll through command history
$ [↑]               → shows previous command

# Double dot = parent folder
$ cd ..             → go up one level

# Single dot = current folder
$ ./hello           → run 'hello' in current folder
```

### File Organization Example
```bash
$ mkdir week1           # create folder for week 1
$ mv hello.c week1/     # move hello.c into it
$ cd week1              # go into the folder
$ ls                    # list: hello.c
$ make hello            # compile
$ ./hello               # run
hello, world
```

### Removing Files
```bash
$ rm hello              # remove the compiled program
remove hello? y         # confirm with 'y'
```

> ⚠️ Unlike your Mac/PC, the Linux terminal has **no Recycle Bin**. `rm` permanently deletes files. There is no undo.

---

## 🟫 Nested Loops — 2D Grids

You can put a loop inside another loop to create 2D patterns — like a grid of bricks in Super Mario Bros.

### Row of Symbols (Horizontal)
```c
for (int i = 0; i < 4; i++)
{
    printf("?");
}
printf("\n");
```
Output: `????`

### Column of Symbols (Vertical)
```c
for (int i = 0; i < 3; i++)
{
    printf("#\n");
}
```
Output:
```
#
#
#
```

### Grid (Nested Loops — 2D)
```c
int size = 3;

for (int row = 0; row < size; row++)        // outer loop: each row
{
    for (int col = 0; col < size; col++)    // inner loop: each column
    {
        printf("#");
    }
    printf("\n");   // new line after each complete row
}
```
Output:
```
###
###
###
```

### How Nested Loops Work
Think of it like a typewriter:
1. Outer loop = which **row** you're on
2. Inner loop = printing left to right across that **row**
3. After the inner loop finishes → print `\n` to go to the next row
4. Outer loop moves to the next row

### Using a Variable for Size
```c
const int SIZE = 3;   // use a constant so it's easy to change

for (int row = 0; row < SIZE; row++)
{
    for (int col = 0; col < SIZE; col++)
    {
        printf("#");
    }
    printf("\n");
}
```

---

## 🔒 Constants

A **constant** is a variable whose value **cannot change** after it's set. The compiler will prevent any accidental modification.

```c
const int SIZE = 3;       // SIZE is always 3
const float PI = 3.14159; // PI never changes
```

### Why Use Constants?
```c
// ❌ Bad: magic number appears in multiple places
for (int row = 0; row < 3; row++)
{
    for (int col = 0; col < 3; col++)  // ← change here AND above = prone to mistakes
    ...
}

// ✅ Good: change it in one place
const int SIZE = 3;
for (int row = 0; row < SIZE; row++)
{
    for (int col = 0; col < SIZE; col++)
    ...
}
```

Convention: constants are written in `ALL_CAPS` to distinguish them from regular variables.

---

## ➗ Arithmetic Operators

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` | Addition | `1 + 2` | `3` |
| `-` | Subtraction | `5 - 3` | `2` |
| `*` | Multiplication | `4 * 3` | `12` |
| `/` | Division | `10 / 4` | `2` *(integer division!)* |
| `%` | Modulo (remainder) | `10 % 3` | `1` |

### Integer Division
When both operands are integers, C **truncates** (throws away) the decimal part:
```c
int result = 10 / 3;    // result = 3 (not 3.333...)
int result = 1 / 3;     // result = 0 (not 0.333...)
```

### Float Division
When at least one operand is a float, C does real division:
```c
float result = 1.0 / 3.0;   // result = 0.333333...
float result = (float) 1 / 3;  // cast int to float first
```

### Modulo Use Case
```c
// Is x even or odd?
if (x % 2 == 0)
{
    printf("even\n");
}
else
{
    printf("odd\n");
}
```

---

## 💥 Integer Overflow

Every integer variable in C has a **maximum value** determined by the number of bits it uses. When you exceed that maximum, the value **wraps around** — this is called **integer overflow**.

### How It Happens
```
32-bit int max value: 2,147,483,647

If you add 1 to the max:
2,147,483,647 + 1 = -2,147,483,648   ← wraps to negative!
```

This is like a car odometer rolling from 99999 back to 00000.

### In Binary
With just 3 bits:
```
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
8 = ???  ← no 4th bit → wraps to 000 = 0
```

### Code Example
```c
int dollars = 1;
while (true)
{
    dollars *= 2;   // keep doubling
    printf("$%i\n", dollars);
}
// Eventually prints negative numbers!
```

### Fix — Use `long` for Larger Numbers
```c
long dollars = 1;
while (true)
{
    dollars *= 2;
    printf("$%li\n", dollars);   // %li for long
}
// Takes much longer to overflow (64-bit range)
// But still overflows eventually!
```

### Real-World Consequences
| Year | Bug | Cause |
|------|-----|-------|
| ~2015 | **Boeing 787** — risk of total electrical failure after 248 days of continuous power | 32-bit counter for time (in 1/100 second units) overflowed at 248 days |
| ~1999 | **Pac-Man kill screen** — garbled level 256 | 8-bit level counter overflowed at 256, corrupting the display |
| ~2038 | **Y2K38 problem** — computers using 32-bit Unix timestamps may roll over to 1901 | Unix time (seconds since Jan 1, 1970) overflows a 32-bit int on Jan 19, 2038 |
| 1999 | **Y2K** — 2-digit year representation caused 2000 to be read as 1900 | Only 2 digits stored for year, no room for the "20" in "2000" |

---

## 🎯 Floating Point Imprecision

Floats and doubles use a **finite number of bits** to represent decimal numbers. But there are **infinitely many** real numbers — so most can only be **approximated**.

### Example
```c
float x = 1.0 / 3.0;
printf("%.50f\n", x);
```
Output:
```
0.33333334326744079589843750000000000000000000000000
```
Not `0.3333333...` forever — just an approximation that eventually goes wrong.

### Why This Happens
Imagine trying to write 1/3 in decimal: `0.333333...` — it never ends. A float only has 32 bits (~7 significant digits), so it must stop somewhere and approximate.

### Comparison
| Type | Bits | Significant Digits | More Precise? |
|------|------|--------------------|---------------|
| `float` | 32 | ~7 | No |
| `double` | 64 | ~15 | Yes |

Using `double` instead of `float` helps — but the problem never fully disappears, because infinity can never fit in finite bits.

---

## ✂️ Truncation

When you divide two **integers** in C, the result is an integer — the decimal part is silently **thrown away** (truncated, not rounded).

```c
int x = 1;
int y = 3;
int z = x / y;         // z = 0 (not 0.333!)
printf("%i\n", z);     // prints 0
```

### Fix — Use Floats
```c
float x = 1;
float y = 3;
float z = x / y;       // z = 0.333...
printf("%f\n", z);     // prints 0.333333
```

Or cast one of them:
```c
int x = 1;
int y = 3;
float z = (float) x / y;   // z = 0.333...
```

---

## 🌍 Real-World Bugs from These Issues

### Y2K (Year 2000 Problem)
For decades, programmers stored years using only **2 digits** (e.g., `99` for 1999) to save memory. When the year 2000 arrived, computers interpreted `00` as 1900 instead of 2000. The world scrambled to patch billions of lines of code before midnight December 31, 1999.

**Lesson:** Saving a few bytes by using fewer digits can have catastrophic long-term consequences.

### Y2K38 (The 2038 Problem)
Unix-based systems (Linux, macOS, Android) track time as **seconds since January 1, 1970**. They store this in a 32-bit integer. On **January 19, 2038**, that counter overflows — and systems may roll back to December 13, 1901.

**Lesson:** Even 32-bit integers run out. Modern systems are migrating to 64-bit time values.

### Boeing 787 Electrical Failure
The 787's Generator Control Units used a 32-bit counter to track uptime in **1/100 second units**. After exactly **248.55 days** of continuous power, the counter overflowed, causing all four generators to simultaneously fail.

**Fix at the time:** Reboot the plane every 248 days. Permanent fix: software update to reset the counter.

---

## 🏆 Code Quality in C

### The Three Axes
CS50 (and the real world) evaluates code on:

| Axis | Question | Tool |
|------|----------|------|
| ✅ **Correctness** | Does the program do exactly what it should? | `check50` |
| 🎨 **Design** | Is it efficient, well-structured, non-repetitive? | `Design50` (AI feedback) |
| 💅 **Style** | Is it readable, well-indented, well-named? | `style50` |

### Comments
Comments are notes to yourself and others. They are **ignored by the compiler**.

```c
// This is a single-line comment

/* This is a
   multi-line comment */

// Get a positive integer from the user
int n;
do
{
    n = get_int("Number: ");  // keep prompting if invalid
}
while (n < 0);
```

### CS50 Style Guide Rules
- Indent by **4 spaces** (not tabs)
- Opening curly brace `{` on the **same line** as `if`/`for`/`while`/`void`
- Closing curly brace `}` on its own line
- **One blank line** between functions
- Variables named in `snake_case` (e.g., `num_students`)
- Constants in `ALL_CAPS`

### Example of Well-Styled Code
```c
#include <cs50.h>
#include <stdio.h>

// Function prototype
void meow(int n);

int main(void)
{
    // Get number of meows from user
    int count = get_int("How many meows? ");
    meow(count);
}

// Print "meow" n times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Source code** | Human-readable code you write (`.c` files) |
| **Machine code** | Binary zeros and ones the CPU executes |
| **Compiler** | Translates source → machine code; also catches syntax errors |
| **`make hello`** | Compiles `hello.c` into an executable called `hello` |
| **`./hello`** | Runs the compiled program |
| **`#include`** | Imports a library/header file |
| **`stdio.h`** | Standard library for `printf` and other I/O functions |
| **`cs50.h`** | CS50's library for `get_string`, `get_int`, etc. |
| **`printf`** | Prints formatted text; `%s`, `%i`, `%f` are placeholders |
| **`\n`** | Escape sequence for new line |
| **Data types** | `int`, `long`, `float`, `double`, `char`, `bool`, `string` |
| **`=` vs `==`** | Assignment vs. equality check — a critical distinction |
| **Conditionals** | `if`, `else if`, `else` — avoid redundant checks |
| **`&&` and `\|\|`** | Logical AND / OR for compound conditions |
| **`while` loop** | Repeat while condition is true |
| **`for` loop** | Compact loop for known number of iterations |
| **`do-while` loop** | Execute at least once, then check condition |
| **`break`** | Exit a loop immediately |
| **`continue`** | Skip to the next loop iteration |
| **Scope** | Variable only exists inside the `{ }` where it was declared |
| **Custom functions** | Define your own reusable functions with `return_type name(params)` |
| **Prototypes** | Declare a function above `main` so the compiler knows it exists |
| **Nested loops** | Loop inside a loop — used for 2D output like grids |
| **`const`** | A variable that cannot be changed after initialization |
| **Integer overflow** | When a value exceeds the max for its bit size → wraps around |
| **Float imprecision** | Floats approximate real numbers; infinite precision is impossible |
| **Truncation** | Integer division silently drops the decimal portion |
| **Linux CLI** | `ls`, `cd`, `mkdir`, `mv`, `cp`, `rm` are essential terminal commands |

---

## 🗂️ Problem Set 1

Build your first C programs! Details at:
[cs50.harvard.edu/x/2026/psets/1](https://cs50.harvard.edu/x/2026/psets/1/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 0 – Scratch](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%200%20-%20Scratch) |
| ➡️ Next | [Week 2 – Arrays](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%202%20-%20Arrays) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 1 - C`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%201%20-%20C)
