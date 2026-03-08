# 📚 CS50x – Week 2: Arrays
### Harvard University's Introduction to Arrays, Strings, and Debugging in C

> *"Strings are arrays. That's today's punchline."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%202-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/2/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=h5Gc1n8ZuU8)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 2](https://www.youtube.com/watch?v=h5Gc1n8ZuU8) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/2](https://cs50.harvard.edu/x/2026/notes/2/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 2 | [cs50.harvard.edu/x/2026/psets/2](https://cs50.harvard.edu/x/2026/psets/2/) |

---

## 📋 Table of Contents

1. [Real-World Problem: Reading Levels](#-real-world-problem-reading-levels)
2. [Real-World Problem: Cryptography](#-real-world-problem-cryptography)
3. [Types of Bugs](#-types-of-bugs)
4. [A Brief History of Bugs — Grace Hopper](#-a-brief-history-of-bugs--grace-hopper)
5. [Debugging Technique 1 — printf](#-debugging-technique-1--printf)
6. [Debugging Technique 2 — debug50](#-debugging-technique-2--debug50)
7. [How to Use debug50 Step by Step](#-how-to-use-debug50-step-by-step)
8. [Breakpoints Explained](#-breakpoints-explained)
9. [Debugging Technique 3 — Rubber Duck Debugging](#-debugging-technique-3--rubber-duck-debugging)
10. [Under the Hood — What Compiling Really Means](#-under-the-hood--what-compiling-really-means)
11. [Step 1 — Preprocessing](#-step-1--preprocessing)
12. [Step 2 — Compiling (Source → Assembly)](#-step-2--compiling-source--assembly)
13. [Step 3 — Assembling (Assembly → Machine Code)](#-step-3--assembling-assembly--machine-code)
14. [Step 4 — Linking](#-step-4--linking)
15. [make vs clang](#-make-vs-clang)
16. [Command Line Arguments to clang](#-command-line-arguments-to-clang)
17. [Can You Reverse-Engineer (Decompile) Code?](#-can-you-reverse-engineer-decompile-code)
18. [Memory — RAM and Bytes](#-memory--ram-and-bytes)
19. [Data Types and Memory Sizes](#-data-types-and-memory-sizes)
20. [The Problem with Three Separate Variables](#-the-problem-with-three-separate-variables)
21. [Arrays — What They Are](#-arrays--what-they-are)
22. [Creating and Using Arrays](#-creating-and-using-arrays)
23. [Looping Over Arrays](#-looping-over-arrays)
24. [Magic Numbers and Constants](#-magic-numbers-and-constants)
25. [Passing Arrays to Functions](#-passing-arrays-to-functions)
26. [Arrays Cannot Self-Report Their Length](#-arrays-cannot-self-report-their-length)
27. [Chars and ASCII Values](#-chars-and-ascii-values)
28. [What is a String? (Under the Hood)](#-what-is-a-string-under-the-hood)
29. [The Null Terminator \0](#-the-null-terminator-0)
30. [Strings Are Arrays of Characters](#-strings-are-arrays-of-characters)
31. [Arrays of Strings](#-arrays-of-strings)
32. [The String Length Problem — strlen](#-the-string-length-problem--strlen)
33. [The string.h Library](#-the-stringh-library)
34. [Performance — Don't Call strlen in a Loop](#-performance--dont-call-strlen-in-a-loop)
35. [Uppercasing Strings — Manual Approach](#-uppercasing-strings--manual-approach)
36. [The ctype.h Library](#-the-ctypeh-library)
37. [Command Line Arguments — argc and argv](#-command-line-arguments--argc-and-argv)
38. [Exit Status — Return Values from main](#-exit-status--return-values-from-main)
39. [Cryptography — The Caesar Cipher](#-cryptography--the-caesar-cipher)
40. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 📖 Real-World Problem: Reading Levels

Week 2 opens with a live demonstration that grounds the entire lecture in a **real-world problem**: computing reading levels from text.

Three students read different passages aloud:

| Passage | Text | Grade Level |
|---------|------|-------------|
| Dr. Seuss | *"1 fish, 2 fish, red fish, blue fish."* | Kindergarten (Before Grade 1) |
| Dr. Seuss | *"Congratulations! Today is your day. You're off to great places, you're off and away."* | Grade 3 |
| George Orwell | *"It was a bright cold day in April, and the clocks were striking 13. Winston Smith…"* | Grade 10 |

What makes these different? Short phrases with simple words score at a lower level. Long sentences with complex, multi-syllable vocabulary score higher.

### The Goal
Build a program that can **analyze a body of text** and determine its reading grade level using a mathematical formula (like the Coleman-Liau index). To do that, we need to **break text into individual characters** — which means we need to understand how strings are stored in memory.

---

## 🔐 Real-World Problem: Cryptography

The second real-world problem introduced this week is **cryptography** — the art of scrambling information so that only the intended recipient can read it.

### Why It Matters
Every time you:
- Send a text message 💬
- Check out with a credit card 💳
- Log in to a website 🔑

…your data is being **encrypted** to protect it from interception.

### The Core Idea
```
┌─────────────┐    key + cipher    ┌──────────────┐
│  Plaintext  │  ──────────────▶  │  Ciphertext  │
│  "HI!"      │                   │  "IJ!"       │
└─────────────┘                   └──────────────┘
```

To send a message securely, both sender and receiver **agree on a secret key** in advance. The sender encrypts with the key. The receiver decrypts with the same key. We'll explore this concretely at the end of today with the **Caesar Cipher**.

---

## 🐛 Types of Bugs

There are two fundamentally different types of errors in software:

### 1. Syntax Errors (Compile-Time Errors)
A **syntax error** breaks the rules of the C language. The compiler catches it and **refuses to compile** your code. Nothing will run until you fix it.

```c
printf("hello, world\n")    // ❌ missing semicolon → syntax error
printf("hello, world\n");   // ✅ correct
```

Common examples:
- Missing `#include <stdio.h>`
- Missing semicolon `;`
- Typo in type: `studio.h` instead of `stdio.h`
- Forgetting to declare the type of a variable
- Forgetting `#include <cs50.h>` when using `string` or `get_string`

### 2. Logic Errors (Run-Time Errors)
A **logic error** compiles fine but produces **wrong output** because your logic is incorrect. The compiler has no idea what you're trying to accomplish — it only knows the rules of C.

```c
// ❌ Logic error: loop goes 0, 1, 2, 3 = 4 iterations, not 3
for (int i = 0; i <= 3; i++)
{
    printf("#\n");
}
```

Output: `####` (4 bricks) instead of the intended `###` (3 bricks). No error message appears — you have to use your human intellect (or debugging tools) to spot the problem.

| Error Type | When Caught | Error Message? | Example |
|------------|------------|----------------|---------|
| Syntax | At compile time | Yes | Missing semicolon |
| Logic | At run time | No | Wrong loop condition |

---

## 🦗 A Brief History of Bugs — Grace Hopper

The word **"bug"** in computing was popularized by **Rear Admiral Dr. Grace Hopper**, one of the most important figures in computing history.

- Hopper was one of the original programmers of the **Harvard Mark I**, one of the earliest mainframe computers (you can still see part of it at Harvard's Science and Engineering Complex)
- While working on its successor, the **Harvard Mark II**, her team discovered that a **real moth** had gotten trapped inside the computer's circuitry and was causing errors
- They taped the moth into their logbook with the note: *"First actual case of bug being found"*

Ever since, the terms **"bug"** and **"debugging"** have been used to describe errors and the process of finding and fixing them in software.

---

## 🖨️ Debugging Technique 1 — printf

The simplest debugging tool in C is one you already know: **`printf`**.

### Strategy
Temporarily insert `printf` statements to print out the values of variables at different points in execution. This lets you "peek inside" the program and observe what's actually happening.

### Example
```c
// Loop with a bug — prints 4 bricks instead of 3
for (int i = 0; i <= 3; i++)
{
    printf("i is %i\n", i);   // ← temporary debug line
    printf("#\n");
}
```

Output:
```
i is 0
#
i is 1
#
i is 2
#
i is 3      ← 3 is ≤ 3, so it runs a 4th time!
#
```

This shows clearly that the loop runs when `i = 3`, which you didn't want. The fix: change `<=` to `<`.

After fixing the bug, **delete** the temporary `printf` lines — they're scaffolding, not permanent code.

### When printf Becomes Tedious
For simple programs, `printf` is quick and effective. But as programs grow, you spend more time adding/removing printfs and recompiling than actually debugging. For larger codebases you need a more powerful tool.

---

## 🔬 Debugging Technique 2 — debug50

**`debug50`** is CS50's command that launches an industry-standard **debugger** — software that lets you **pause your program's execution** at any point and walk through it line by line.

### Command
```bash
debug50 ./buggy
```

### What a Debugger Can Do
- **Pause** execution at any line (called a "breakpoint")
- **Step over** a line — execute it and pause on the next
- **Step into** a function — go inside the function call, line by line
- **Inspect variables** — see the current value of every variable in memory in real time
- **Continue** — resume normal execution until the next breakpoint

---

## 🚦 How to Use debug50 Step by Step

### Step 1 — Compile your program normally
```bash
make buggy
```

### Step 2 — Set a breakpoint
In VS Code, hover over the space to the **left of a line number**. A faint red dot appears. **Click it** to set a breakpoint (it turns solid red). Set a breakpoint at the first line of `main`.

```
  ●  8  |    int h = get_int("Height: ");
         ↑
     Click here to set breakpoint
```

### Step 3 — Run the debugger
```bash
debug50 ./buggy
```

### Step 4 — Use the control buttons

| Button | Name | What It Does |
|--------|------|--------------|
| ▶ | Continue | Resume execution until the next breakpoint |
| ↷ | Step Over | Execute the current line; pause on the next |
| ↓ | Step Into | Go inside the function called on this line |
| ↑ | Step Out | Run to the end of the current function, then pause |
| ⏹ | Stop | Kill the debugger |

### Step 5 — Inspect variables
In the **left panel**, you'll see all current variable values update in real time as you step through your code.

### Example Walkthrough
```
Breakpoint set at line 8.
Run debug50 → execution pauses at line 8.

Variables panel: h = 32764  ← garbage value (not yet set)

Step Over → "Height: " prompt appears
Type 3, press Enter.
Variables panel: h = 3  ✅

Step Into print_column →
  i = garbage value (not initialized yet)

Step Over → i = 0
Step Over → first # printed
Step Over → i = 1
Step Over → second # printed
Step Over → i = 2
Step Over → third # printed
Step Over → i = 3  ← but 3 ≤ 3 is TRUE!
Step Over → fourth # printed  ← BUG FOUND!
```

**Conclusion:** `i <= 3` should be `i < 3`.

---

## 🔴 Breakpoints Explained

A **breakpoint** is a marker that tells the debugger: *"When execution reaches this line, pause and let me take control."*

### Setting Breakpoints
Click to the **left of any line number** in VS Code. A solid red dot ● means the breakpoint is active.

### Where to Set Them
- At the **beginning of `main`** to step through everything
- At the **start of a specific function** you suspect is buggy
- Right **before a loop** you want to watch unfold

### Garbage Values
When the debugger shows a huge, random-looking number (like `32764`) in a variable **before** it's been initialized, that's a **garbage value**. RAM is always in use — the bytes your variable will occupy may have held something else previously. Until your code writes a value there, whatever bits were already present compose that garbage value.

> ⚠️ C does not automatically zero out memory for you. You're responsible for initializing variables before using them. This is one of C's most common sources of bugs.

---

## 🦆 Debugging Technique 3 — Rubber Duck Debugging

**Rubber duck debugging** is a real technique, popularized in the book *The Pragmatic Programmer*. Explain your code out loud to an inanimate object (like a rubber duck on your desk).

### Why It Works
When you verbalize your problem, you're forced to:
1. Articulate what you **think** the code is doing
2. Articulate what it's **actually** doing
3. Hear, in your own voice, where those two things diverge

Often the answer becomes obvious the moment you say the problem out loud — without any help from a TA or another human.

### Good vs. Bad Use of CS50's AI Duck
| ✅ Good Use | ❌ Bad Use |
|------------|-----------|
| "What does this error message mean?" | Copy-paste your whole code and ask "fix it" |
| "Why might a for loop iterate one too many times?" | Using the duck before even trying yourself |
| "Can you explain what a null terminator is?" | Letting the AI write your code for you |

The goal is to develop **your own** mental models and problem-solving skills.

---

## ⚙️ Under the Hood — What Compiling Really Means

`make` is not the compiler — it's a **build automation tool**. The actual compiler is called **`clang`** (C Language). And "compiling" is actually **4 separate steps** happening in sequence:

```
Source Code (.c)
      │
      ▼  Step 1: Preprocessing
Pre-processed Code
      │
      ▼  Step 2: Compiling (technically)
Assembly Code (.s)
      │
      ▼  Step 3: Assembling
Machine Code (.o object files)
      │
      ▼  Step 4: Linking
Executable Program (e.g., ./hello)
```

---

## 🔄 Step 1 — Preprocessing

The **preprocessor** handles all lines starting with `#` — specifically `#include` directives.

When it sees `#include <stdio.h>`, it finds that file on the server's hard drive and **copies and pastes its contents** into your code at that location. This is where `printf`'s prototype comes from.

```c
// Your code:
#include <stdio.h>
#include <cs50.h>

// After preprocessing (conceptually):
int printf(const char *format, ...);   // from stdio.h
string get_string(string prompt);      // from cs50.h
// ... and many more prototypes
```

This is why you've been able to call `printf` without ever defining it — `#include <stdio.h>` pulls in the declaration automatically.

> 💡 A very common typo: `studio.h` ← WRONG. It's `stdio.h` — standard **I/O**, not studio.

---

## 💻 Step 2 — Compiling (Source → Assembly)

Compiling (in the narrow technical sense) takes pre-processed C code and converts it into **assembly code** — a very low-level language that directly maps to CPU instructions.

```asm
main:
    push    rbp
    mov     rbp, rsp
    call    get_string
    call    printf
    xor     eax, eax
    ret
```

This is CPU-specific. Different processors (Intel, AMD, Apple Silicon, ARM) use different assembly instruction sets — which is why a Mac binary won't run on a PC and vice versa.

> 💡 `a.out` stands for **"assembler output"** — the historical default filename when compiling C.

---

## 🔩 Step 3 — Assembling (Assembly → Machine Code)

**Assembling** converts assembly code into **machine code** — actual zeros and ones. This produces **object files** (`.o` files):

```
hello.c → hello.o   ← your code, as machine code
```

But `hello.o` is incomplete — it calls `printf` and `get_string`, which are defined elsewhere.

---

## 🔗 Step 4 — Linking

**Linking** combines all the separate object files into one complete executable:

```
hello.o  +  cs50.o  +  stdio.o  →  ./hello
(your code)  (CS50 lib)  (std lib)    (final program)
```

### Why `-lcs50` Was Needed
When you ran `clang hello.c` without `-lcs50`, the error was:
```
Linker command failed: undefined reference to 'get_string'
```
The linker couldn't find the machine code for `get_string` because you didn't tell it where to look. `-lcs50` says: "Go find and link in the CS50 library."

### Summary

| Step | Input | Output |
|------|-------|--------|
| Preprocessing | `.c` source | Pre-processed `.c` |
| Compiling | Pre-processed `.c` | `.s` assembly |
| Assembling | `.s` assembly | `.o` object (machine code) |
| Linking | `.o` files | Executable (`./hello`) |

---

## 🛠️ make vs clang

`make hello` is shorthand for this longer command:

```bash
clang -o hello hello.c -lcs50
```

| Part | Meaning |
|------|---------|
| `clang` | The actual C compiler |
| `-o hello` | Name the output `hello` (not the default `a.out`) |
| `hello.c` | The source file |
| `-lcs50` | Link in the CS50 library |

`make` just memorizes this for you. Nothing magical — pure convenience.

---

## 🔍 Command Line Arguments to clang

```bash
clang hello.c              # → creates a.out
clang -o hello hello.c     # → creates hello
clang -o hello hello.c -lcs50  # → links CS50 too
```

**Command line arguments** are all the words you type after a program's name at the terminal. `make`, `cd`, `code` all accept them. You can write programs that accept them too — more on this later in this README.

---

## 🔍 Can You Reverse-Engineer (Decompile) Code?

After compiling, you have a file of zeros and ones. Could someone take your compiled program and reconstruct your source code?

**Technically, sort of — but practically, not fully:**
- A disassembler can convert machine code back to assembly
- But variable names, comments, and code style are gone forever
- You can't tell if the original used a `while` loop or a `for` loop — they produce the same machine code
- It would likely take longer to reverse-engineer Microsoft Word than to just rewrite it from scratch

**JavaScript is an exception:** browsers receive and execute JavaScript **source code directly**, so any website's JS is always viewable (`View Source` in your browser).

---

## 💾 Memory — RAM and Bytes

All variables live in **RAM** (Random Access Memory). Think of it as a giant grid of bytes, each with its own address:

```
Address  Value
┌──────┬─────┐
│  0   │  ?  │
│  1   │  ?  │
│  2   │  ?  │
│  3   │  ?  │
│ ...  │ ... │
│  1B  │  ?  │  ← last byte in 1 GB of RAM
└──────┴─────┘
```

When you declare `int x = 5;`, the compiler picks some location in this grid (say bytes 4–7) and stores the value 5 there as 32 bits. Multi-byte types are always stored **contiguously** (back-to-back).

---

## 📊 Data Types and Memory Sizes

| Type | Bytes | Bits | Notes |
|------|-------|------|-------|
| `bool` | 1 byte | 8 bits | true/false (only uses 1 bit; rest is wasted) |
| `char` | 1 byte | 8 bits | ASCII characters 0–127 |
| `int` | 4 bytes | 32 bits | ~ −2 billion to +2 billion |
| `long` | 8 bytes | 64 bits | ~ ±9 quintillion |
| `float` | 4 bytes | 32 bits | ~7 significant digits |
| `double` | 8 bytes | 64 bits | ~15 significant digits |
| `string` | varies | varies | Length of text + 1 extra byte for `\0` |

> 💡 `"hi"` uses 3 bytes (h + i + null terminator). `"hello"` uses 6 bytes. Every string needs one extra byte for the null terminator.

---

## ❌ The Problem with Three Separate Variables

```c
int score1 = 72;
int score2 = 73;
int score3 = 33;
```

This works for 3 scores. But what about 30? 300? You'd need 300 variables, 300 `get_int` calls, and 300 lines of addition. Clearly that's not the right approach. There must be a better way — and there is.

---

## 🗂️ Arrays — What They Are

An **array** is a chunk of **contiguous memory** storing multiple values of the **same type**, all under a **single variable name**.

```
scores[0]  scores[1]  scores[2]
┌──────────┬──────────┬──────────┐
│    72    │    73    │    33    │
└──────────┴──────────┴──────────┘
   4 bytes    4 bytes    4 bytes
   ◄──────── 12 bytes total ──────►
```

Key properties:
- All values must be the **same type**
- Values are stored **back-to-back in memory** (contiguous)
- Individual values accessed using **square bracket notation** with a **0-based index**
- First element is always `[0]`, not `[1]`

---

## 🔧 Creating and Using Arrays

### Declaration Syntax
```c
type name[size];
```

```c
int scores[3];       // array of 3 integers
float prices[10];    // array of 10 floats
char letters[26];    // array of 26 characters
```

### Assigning Values
```c
scores[0] = 72;
scores[1] = 73;
scores[2] = 33;
```

### Inline Initialization
```c
int scores[] = {72, 73, 33};     // compiler figures out size = 3
int scores[3] = {72, 73, 33};    // explicit size also fine
```

### Accessing Values
```c
printf("%i\n", scores[0]);   // 72
printf("%i\n", scores[1]);   // 73
printf("%i\n", scores[2]);   // 33
```

### Computing an Average
```c
float average = (scores[0] + scores[1] + scores[2]) / 3.0;
```

> ⚠️ Divide by `3.0` (float), not `3` (integer), to avoid truncation. `178 / 3` = `59`, not `59.33`.

---

## 🔁 Looping Over Arrays

The real power of arrays comes from combining them with **loops**. Let `i` serve as both the loop counter and the array index:

```c
const int N = 3;
int scores[N];

// Get scores dynamically
for (int i = 0; i < N; i++)
{
    scores[i] = get_int("Score: ");
}

// Print all scores
for (int i = 0; i < N; i++)
{
    printf("Score %i: %i\n", i + 1, scores[i]);
}
```

**How it works:** When `i = 0` → accesses `scores[0]`. When `i = 1` → `scores[1]`. When `i = 2` → `scores[2]`. When `i = 3` → `3 < 3` is false, loop ends.

---

## 🔢 Magic Numbers and Constants

A **magic number** is a hard-coded value that appears in multiple places without explanation — bad design because you might update one instance but forget another.

```c
// ❌ Bad: "3" in two places — easy to forget to update one
int scores[3];
for (int i = 0; i < 3; i++) { ... }

// ✅ Good: change N in one place
const int N = 3;
int scores[N];
for (int i = 0; i < N; i++) { ... }
```

By convention, constants are written in **`ALL_CAPS`** to distinguish them visually from regular variables:
```c
const int N = 3;
const float PI = 3.14159;
const int MAX_SIZE = 100;
```

---

## 📬 Passing Arrays to Functions

```c
float average(int length, int numbers[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return (float) sum / length;
}
```

### Calling It
```c
const int N = 3;
int scores[N];
// ... fill scores ...
float avg = average(N, scores);
printf("Average: %.2f\n", avg);
```

### Syntax Notes
| Part | Meaning |
|------|---------|
| `int numbers[]` | Takes an array of integers — empty brackets, no size needed |
| `int length` | Must pass length separately — arrays can't self-report |
| `return (float) sum / length` | Cast to float before dividing to avoid truncation |

---

## ⚠️ Arrays Cannot Self-Report Their Length

In Python: `len(my_list)`. In Java: `myArray.length`. In C: **you cannot ask an array its own length**. You must pass it separately every time.

```c
// ❌ No way to know the length here in C
void print_array(int numbers[])
{
    for (int i = 0; i < ???; i++) { ... }
}

// ✅ Must pass length explicitly
void print_array(int length, int numbers[])
{
    for (int i = 0; i < length; i++) { ... }
}
```

This is a known limitation of C — a design decision from the 1970s when saving every byte of memory mattered.

---

## 🔤 Chars and ASCII Values

A `char` in C is stored as an **integer** using the ASCII standard. The same byte can be printed as a character or as a number:

```c
char c1 = 'H';   // stores the integer 72
char c2 = 'I';   // stores the integer 73
char c3 = '!';   // stores the integer 33

printf("%c %c %c\n", c1, c2, c3);   // H I !
printf("%i %i %i\n", c1, c2, c3);   // 72 73 33
```

### Key ASCII Values

| Character | Value | Notes |
|-----------|-------|-------|
| `'A'`–`'Z'` | 65–90 | Uppercase letters |
| `'a'`–`'z'` | 97–122 | Lowercase letters |
| `'0'`–`'9'` | 48–57 | Digit characters |
| `' '` | 32 | Space |
| `'\0'` | 0 | Null terminator |

### The Magic Distance: 32
Every lowercase letter is exactly **32 more** than its uppercase equivalent:
```
'a' (97) - 'A' (65) = 32
'z' (122) - 'Z' (90) = 32
```

To convert lowercase to uppercase: **subtract 32**. (A library function exists for this — more on that below.)

> ⚠️ Single quotes `'A'` are for **chars**. Double quotes `"hello"` are for **strings**. Never mix them.

---

## 🔍 What is a String? (Under the Hood)

`string` is a CS50 training wheel. What's actually happening in memory is this:

**A string is just an array of characters (`char`).**

```c
string s = "HI!";
```

In memory:
```
s[0]  s[1]  s[2]  s[3]
┌─────┬─────┬─────┬─────┐
│  H  │  I  │  !  │  \0 │
│  72 │  73 │  33 │   0 │
└─────┴─────┴─────┴─────┘
```

You can access individual characters using square brackets:
```c
printf("%c\n", s[0]);   // H
printf("%c\n", s[1]);   // I
printf("%c\n", s[2]);   // !
printf("%i\n", s[0]);   // 72
printf("%i\n", s[1]);   // 73
```

---

## 🛑 The Null Terminator `\0`

Every string in C ends with a special character called the **null terminator**, written as `\0`.

- It's a byte where **all 8 bits are 0** (the integer zero, not the character `'0'`)
- Added **automatically** by the compiler whenever you use double quotes
- It marks where the string ends so functions like `printf` know when to stop

### Why It's Necessary
`printf("%s", s)` is essentially this loop internally:
```c
while (s[i] != '\0')
{
    print s[i];
    i++;
}
```
Without `\0`, printf would keep reading bytes past the end of the string until something bad happened.

### Memory Size = Length + 1
```c
string s = "HI!";   // 3 chars + 1 null = 4 bytes total
string t = "BYE";   // 3 chars + 1 null = 4 bytes total
```

### `\0` vs `\n` vs `'0'` vs `0`
| Notation | What It Is | ASCII Value |
|----------|-----------|-------------|
| `\0` | Null terminator — end of string | 0 |
| `\n` | Newline | 10 |
| `'0'` | The digit zero as a character | 48 |
| `0` | The integer zero | 0 (4 bytes) |

---

## 🔗 Strings Are Arrays of Characters

Two strings in memory look like this:

```c
string s = "HI!";
string t = "BYE";
```

```
s[0] s[1] s[2] s[3]   t[0] t[1] t[2] t[3]
┌────┬────┬────┬────┐  ┌────┬────┬────┬────┐
│ H  │ I  │ !  │ \0 │  │ B  │ Y  │ E  │ \0 │
└────┴────┴────┴────┘  └────┴────┴────┴────┘
```

You can loop through each character, do arithmetic on character values, check their types — all using the same array techniques from earlier.

---

## 📚 Arrays of Strings

You can make an **array of strings** — each element is a string (which is itself an array of chars):

```c
string words[2];
words[0] = "HI!";
words[1] = "BYE";

printf("%s\n", words[0]);   // HI!
printf("%s\n", words[1]);   // BYE
```

Access individual characters using **double square brackets**:
```c
printf("%c\n", words[0][0]);   // H (word 0, char 0)
printf("%c\n", words[0][1]);   // I (word 0, char 1)
printf("%c\n", words[1][0]);   // B (word 1, char 0)
```

---

## 📏 The String Length Problem — strlen

A classic task: count the characters in a string.

### Manual Implementation
Walk through the string until you hit `\0`:

```c
int n = 0;
while (name[n] != '\0')
{
    n++;
}
// n is now the length of the string
```

**Trace for "David":**
- `name[0]` = `'D'` ≠ `'\0'` → n = 1
- `name[1]` = `'a'` ≠ `'\0'` → n = 2
- `name[2]` = `'v'` ≠ `'\0'` → n = 3
- `name[3]` = `'i'` ≠ `'\0'` → n = 4
- `name[4]` = `'d'` ≠ `'\0'` → n = 5
- `name[5]` = `'\0'` → stop! Length = 5

> 💡 The null terminator is NOT counted. `strlen("David")` = 5, not 6.

---

## 📖 The string.h Library

Don't write your own strlen — someone did it decades ago and packaged it in **`string.h`**:

```c
#include <string.h>
```

### Key Functions

| Function | What It Does | Example |
|----------|-------------|---------|
| `strlen(s)` | Returns the length of string `s` | `strlen("hello")` → `5` |
| `strcmp(s, t)` | Compares two strings (0 if equal) | `strcmp("hi", "hi")` → `0` |
| `strcpy(dest, src)` | Copies a string | `strcpy(dest, "hello")` |
| `strcat(s1, s2)` | Concatenates two strings | `strcat("hi", " there")` |

### Usage
```c
#include <string.h>

string name = get_string("Name: ");
printf("Length: %i\n", strlen(name));  // no variable needed!
```

---

## ⚡ Performance — Don't Call strlen in a Loop

A very common mistake: calling `strlen` inside a loop's condition.

```c
// ❌ Bad — strlen runs on EVERY iteration
for (int i = 0; i < strlen(s); i++)
{
    printf("%c\n", s[i]);
}
```

If `s` is 1000 characters long, this calls `strlen` 1000 times — walking through 1000 characters each time. That's 1,000,000 operations instead of 1000.

```c
// ✅ Good — calculate once, reuse the result
int n = strlen(s);
for (int i = 0; i < n; i++)
{
    printf("%c\n", s[i]);
}

// ✅ Also good — initialize both variables before the loop
for (int i = 0, n = strlen(s); i < n; i++)
{
    printf("%c\n", s[i]);
}
```

> 💡 The length of `s` doesn't change during the loop. Computing it once and storing it in `n` is always the right approach.

---

## 🔠 Uppercasing Strings — Manual Approach

Using ASCII arithmetic, we can convert lowercase to uppercase by **subtracting 32**:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')   // is it lowercase?
        {
            printf("%c", s[i] - 32);       // make uppercase
        }
        else
        {
            printf("%c", s[i]);            // print unchanged
        }
    }
    printf("\n");
}
```

Input: `david` → Output: `DAVID`

### Why Does Subtracting 32 Work?
```
'a' = 97 = 'A' (65) + 32   → 'a' - 32 = 'A'
'b' = 98 = 'B' (66) + 32   → 'b' - 32 = 'B'
'z' = 122 = 'Z' (90) + 32  → 'z' - 32 = 'Z'
```

Every lowercase letter's ASCII value is exactly 32 more than its uppercase version.

---

## 🔡 The ctype.h Library

Writing `s[i] >= 'a' && s[i] <= 'z'` works but is verbose. **`ctype.h`** provides clean functions for this:

```c
#include <ctype.h>
```

### Key Functions

| Function | What It Does |
|----------|-------------|
| `islower(c)` | Is `c` a lowercase letter? |
| `isupper(c)` | Is `c` an uppercase letter? |
| `isalpha(c)` | Is `c` any letter (a-z or A-Z)? |
| `isdigit(c)` | Is `c` a digit (0-9)? |
| `isspace(c)` | Is `c` a space, tab, or newline? |
| `toupper(c)` | Returns the uppercase version of `c` |
| `tolower(c)` | Returns the lowercase version of `c` |

### Cleaner Version
```c
for (int i = 0, n = strlen(s); i < n; i++)
{
    if (islower(s[i]))
    {
        printf("%c", toupper(s[i]));
    }
    else
    {
        printf("%c", s[i]);
    }
}
```

### Cleanest Version
`toupper` is smart: if passed an already-uppercase or non-letter character, it returns it unchanged. So the `if/else` is unnecessary:

```c
for (int i = 0, n = strlen(s); i < n; i++)
{
    printf("%c", toupper(s[i]));   // handles all cases automatically
}
```

> 💡 `ctype.h` is part of the C standard library. Unlike `cs50.h`, it requires no special linker flags — just `#include <ctype.h>`.

---

## 💻 Command Line Arguments — argc and argv

Up until now, every program has used `int main(void)` — meaning it takes no arguments from the command line. But many real programs do:

```bash
make hello       ← "hello" is a command line argument to make
cd week2         ← "week2" is an argument to cd
clang -o hello hello.c  ← "-o", "hello", "hello.c" are arguments to clang
```

### The Other Signature for main
```c
int main(int argc, string argv[])
```

| Parameter | Type | Meaning |
|-----------|------|---------|
| `argc` | `int` | **Argument count** — total words typed at the prompt (including the program name itself) |
| `argv` | `string[]` | **Argument vector** — array of all those words as strings |

### Example
If the user runs:
```bash
./greet David
```
Then:
- `argc` = `2`
- `argv[0]` = `"./greet"` (always the program name)
- `argv[1]` = `"David"`

### Simple Greeter Using Command Line Arguments
```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
```

```bash
./greet David       → hello, David
./greet             → hello, world  (argc is 1, not 2)
./greet David Malan → hello, world  (argc is 3, not 2)
```

### argv[0] Is Always the Program Name
Regardless of what arguments are typed, `argv[0]` always contains the name of the program itself. Useful for self-referential messages like usage instructions.

### Always Guard Against Missing Arguments
```c
if (argc != 2)
{
    printf("Usage: ./program <argument>\n");
    return 1;
}
// Safe to use argv[1] here
```

> ⚠️ Accessing `argv[1]` when `argc` is only `1` is a bug — you'd be reading memory you don't own. Always check `argc` first.

---

## 🚦 Exit Status — Return Values from main

`int main(...)` — the `int` means `main` returns an integer. This is the **exit status**: a numeric code that tells the operating system whether your program succeeded or failed.

### Convention
| Return Value | Meaning |
|--------------|---------|
| `return 0` | **Success** |
| `return 1` | **Error** (first possible error) |
| `return 2`, `3`, etc. | Specific error types defined by the programmer |

### Example
```c
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n");
        return 1;   // signal error
    }
    printf("hello, %s\n", argv[1]);
    return 0;       // signal success
}
```

### Checking Exit Status in the Terminal
```bash
./status David
echo $?         # prints 0 (success)

./status
echo $?         # prints 1 (error)
```

`$?` in the terminal always holds the exit status of the last-run command.

### Real-World Exit Codes

| Context | Code | Meaning |
|---------|------|---------|
| Unix program | 0 | Success |
| Unix program | 1 | General error |
| HTTP | 200 | OK |
| HTTP | 404 | Not Found |
| HTTP | 500 | Internal Server Error |

> 💡 This is partly how `check50` evaluates your programs — it checks the exit status and compares actual output to expected output.

---

## 🔐 Cryptography — The Caesar Cipher

The **Caesar Cipher** is one of the oldest and simplest encryption algorithms. Julius Caesar reportedly used it to communicate secretly with his generals.

### The Idea
Shift every letter in the message by a fixed number (the **key**):

| Key | A becomes | B becomes | Z becomes |
|-----|-----------|-----------|-----------|
| 1 | B | C | A |
| 13 | N | O | M |
| 26 | A | B | Z (useless — same as original) |

### Encrypting with Key = 1
| Plaintext | H | I | ! |
|-----------|---|---|---|
| ASCII | 72 | 73 | 33 |
| + key (1) | 73 | 74 | 33 |
| **Ciphertext** | **I** | **J** | **!** |

Punctuation and spaces are not encrypted (only letters shift).

### Decrypting
Reverse the process — subtract the key:
```
Ciphertext "IJ!" with key 1:
I (73) - 1 = H (72)
J (74) - 1 = I (73)
! → unchanged
→ Plaintext: "HI!"
```

### ROT-13 (Key = 13)
ROT-13 has a special property: encrypting twice gives you back the original (since 13 + 13 = 26 = full alphabet). It's used online to hide spoilers.

```
H (72 + 13 = 85) → U
I (73 + 13 = 86) → V
→ "HI" becomes "UV"
```

### Why Caesar Is Weak
An attacker only needs to try **25 keys** (1 through 25). A computer does this in microseconds — this cipher provides basically no security today.

### The General Model for Cryptography
```
┌──────────┐    encrypt(key)    ┌──────────────┐
│ Plaintext│  ───────────────▶ │  Ciphertext  │
│  "HI!"   │                   │   "IJ!"      │
└──────────┘                   └──────────────┘
                                       │
                                 decrypt(key)
                                       ▼
                                ┌──────────┐
                                │ Plaintext│
                                │  "HI!"   │
                                └──────────┘
```

Both parties **agree on a key in advance** — this shared secret is what makes the encryption reversible by the intended recipient only.

> 💡 In Week 2's problem set, you'll implement the Caesar Cipher in C using `argc`, `argv`, character arithmetic, and modular wrapping at the end of the alphabet.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Syntax error** | Breaks C grammar; compiler catches it; code won't compile |
| **Logic error** | Code compiles but produces wrong output |
| **printf debugging** | Temporary `printf` to print variable values mid-execution |
| **debug50** | Debugger: pause execution and step through code line by line |
| **Breakpoint** | Red dot that tells the debugger where to pause |
| **Garbage value** | Random leftover bits in uninitialized memory |
| **Rubber duck debugging** | Talk through your problem out loud to find the bug yourself |
| **Grace Hopper** | Popularized "bug" after finding a real moth in Harvard Mark II |
| **4 steps of compilation** | Preprocessing → Compiling → Assembling → Linking |
| **Preprocessing** | `#include` lines replaced with actual header file contents |
| **Compiling (narrow)** | C code → assembly code (CPU-specific) |
| **Assembling** | Assembly code → zeros and ones (object file) |
| **Linking** | Combines your object file with library files into one executable |
| **clang** | The actual C compiler (`make` is just a shortcut) |
| **`-lcs50`** | Flag telling the linker to include the CS50 library |
| **Array** | Contiguous memory holding multiple values of the same type |
| **0-based indexing** | First element is `[0]`, not `[1]` |
| **`int scores[3]`** | Declares an array of 3 integers |
| **Magic numbers** | Hard-coded values in multiple places — bad design |
| **`const int N = 3`** | A constant; ALL_CAPS by convention |
| **Passing arrays** | Must pass both the array AND its length |
| **No self-length** | Arrays in C cannot report their own length |
| **char** | Single character stored as a 1-byte integer (ASCII) |
| **String** | An array of `char`, automatically null-terminated with `\0` |
| **Null terminator `\0`** | 8 zero bits marking the end of every string |
| **`strlen`** | `string.h` function returning string length (excludes `\0`) |
| **strlen in loop** | Anti-pattern — compute once and store in a variable |
| **`string.h`** | Library: `strlen`, `strcmp`, `strcpy`, `strcat` |
| **`ctype.h`** | Library: `islower`, `isupper`, `toupper`, `tolower`, `isdigit` |
| **`toupper(c)`** | Converts to uppercase; passes non-letters through unchanged |
| **argc** | Count of words typed at prompt (includes program name) |
| **argv** | Array of those words as strings |
| **`argv[0]`** | Always the program's own name |
| **Exit status** | Integer returned by `main`; 0 = success, non-zero = error |
| **Caesar Cipher** | Shift each letter by a fixed key; decrypt by shifting back |

---

## 🗂️ Problem Set 2

Implement programs using arrays, strings, command line arguments, and cryptography:
[cs50.harvard.edu/x/2026/psets/2](https://cs50.harvard.edu/x/2026/psets/2/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 1 – C](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%201%20-%20C) |
| ➡️ Next | [Week 3 – Algorithms](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%203%20-%20Algorithms) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 2 - Arrays`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%202%20-%20Arrays)
