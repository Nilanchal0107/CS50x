# 📚 CS50x – Week 4: Memory
### Harvard University's Introduction to Pointers, Memory Management, and File I/O

> *"This is week 4, the week in which we take off the proverbial training wheels... and reveal to you all the more what's going on underneath the hood of a computer."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%204-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/4/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=db0H0U13YsA)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 4](https://www.youtube.com/watch?v=db0H0U13YsA) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/4](https://cs50.harvard.edu/x/2026/notes/4/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 4 | [cs50.harvard.edu/x/2026/psets/4](https://cs50.harvard.edu/x/2026/psets/4/) |

---

## 📋 Table of Contents

1. [Pixels and Images](#-pixels-and-images)
2. [RGB and Color Representation](#-rgb-and-color-representation)
3. [Hexadecimal — Base 16](#-hexadecimal--base-16)
4. [Why Hexadecimal?](#-why-hexadecimal)
5. [Memory Addresses](#-memory-addresses)
6. [Pointers — What They Are](#-pointers--what-they-are)
7. [Pointer Syntax — & and *](#-pointer-syntax----and-)
8. [Pointer Size and NULL](#-pointer-size-and-null)
9. [Strings are Pointers](#-strings-are-pointers)
10. [Pointer Arithmetic](#-pointer-arithmetic)
11. [Comparing Strings Correctly](#-comparing-strings-correctly)
12. [Copying Strings — The Problem](#-copying-strings--the-problem)
13. [malloc — Dynamic Memory Allocation](#-malloc--dynamic-memory-allocation)
14. [strcpy — Copying Strings Properly](#-strcpy--copying-strings-properly)
15. [NULL Checks and Error Handling](#-null-checks-and-error-handling)
16. [free — Returning Memory](#-free--returning-memory)
17. [Memory Leaks](#-memory-leaks)
18. [Valgrind — Detecting Memory Errors](#-valgrind--detecting-memory-errors)
19. [Garbage Values](#-garbage-values)
20. [scanf and Stack Buffers](#-scanf-and-stack-buffers)
21. [Buffer Overflow](#-buffer-overflow)
22. [File I/O — Introduction](#-file-io--introduction)
23. [fopen and fclose](#-fopen-and-fclose)
24. [fprintf — Writing to Files](#-fprintf--writing-to-files)
25. [Append Mode vs Write Mode](#-append-mode-vs-write-mode)
26. [fread and fwrite](#-fread-and-fwrite)
27. [Implementing a Copy Program](#-implementing-a-copy-program)
28. [BMP Files and Image Filters](#-bmp-files-and-image-filters)
29. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🖼️ Pixels and Images

Every image on a screen is made up of tiny dots called **pixels**. Each pixel has a color, and together they create the appearance of photos, graphics, and animations.

- A pixel grid has a finite width × height — this is called **resolution**
- Zooming in on any digital image will eventually reveal individual colored dots
- A **1-bit image** uses 0 for black and 1 for white
- Modern images use **24 bits per color** (8 bits each for red, green, and blue), giving access to millions of colors

```
Low resolution pixel art (Post-it note cat demo):
■ ■ □ □ □ ■ ■
■ □ ■ □ ■ □ ■
■ □ □ □ □ □ ■   ← Each square = 1 pixel with a color value
□ ■ □ □ □ ■ □
□ □ ■ ■ ■ □ □
```

This is fundamentally how computers store every image — including photographs.

---

## 🎨 RGB and Color Representation

Colors in a computer are represented using **RGB** — red, green, and blue. Each channel gets a value from 0 to 255.

| Color | Red | Green | Blue | Hex |
|-------|-----|-------|------|-----|
| Black | 0 | 0 | 0 | `#000000` |
| White | 255 | 255 | 255 | `#FFFFFF` |
| Red | 255 | 0 | 0 | `#FF0000` |
| Green | 0 | 255 | 0 | `#00FF00` |
| Blue | 0 | 0 | 255 | `#0000FF` |

Each channel uses **8 bits** (1 byte), so a full color pixel requires 3 bytes. This is why images are measured in megabytes — millions of pixels, 3 bytes each.

---

## 🔢 Hexadecimal — Base 16

**Hexadecimal** (hex) is a base-16 number system. Instead of just digits 0–9, it adds letters A–F:

```
Decimal:     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
Hexadecimal: 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
```

### Counting in Hex
```
00, 01, 02 ... 09, 0A, 0B, 0C, 0D, 0E, 0F, 10, 11 ... FF
```

- `FF` in hex = 255 in decimal (16×15 + 1×15 = 255)
- To avoid ambiguity with decimal, hex values are prefixed with `0x`: `0x10` = 16, not 10

### Column Values
```
Hex:     1    6
        16¹  16⁰
       = 16 + 6 = 22 in decimal
```

---

## 🤔 Why Hexadecimal?

One hex digit represents exactly **4 bits**:

```
F  =  15  =  1111 in binary  (4 bits)
F  =  15  =  1111 in binary  (4 bits)

FF = 11111111 = 255           (8 bits = 1 byte)
```

This makes hex a compact, human-readable shorthand for binary data. Two hex digits = exactly 1 byte. This is why colors, memory addresses, and file contents are all expressed in hex.

---

## 🧭 Memory Addresses

Every variable stored in memory lives at a specific **address** — a number identifying its location.

```c
int n = 50;
printf("%p\n", &n);  // prints something like: 0x7fffd3c34ecc
```

- `%p` is the format code for printing a **pointer** (memory address)
- `&n` means "the address of n"
- Addresses are shown in hexadecimal notation

```
Memory layout (simplified):

Address:   0x0   0x1   0x2   0x3   ...  0x7fffd3c34ecc
Content:   ??    ??    ??    ??    ...  [ 50 (4 bytes) ]
```

An integer uses 4 bytes, so `n = 50` occupies addresses like `0x...ecc` through `0x...ecf`.

---

## 🔗 Pointers — What They Are

A **pointer** is a variable that stores a **memory address** — it "points to" another variable's location in memory.

```
n = 50             (an integer living at address 0x123)
p = 0x123          (a pointer storing the address of n)

         p ──────►  [ 50 ]
                   address 0x123
```

### Why Pointers?
- Allow functions to modify variables they didn't create
- Enable dynamic memory allocation
- Are required for File I/O in C
- Allow efficient passing of large data without copying

---

## ✍️ Pointer Syntax — `&` and `*`

### `&` — Address-of Operator
Gets the memory address of a variable:
```c
int n = 50;
printf("%p\n", &n);  // prints address of n
```

### `*` — Pointer Declaration and Dereference
When declaring: means "this variable stores an address of [type]":
```c
int *p = &n;   // p stores the address of an integer
```

When using: means "go to the address and get the value there" (dereference):
```c
printf("%i\n", *p);  // prints 50 — the value at the address stored in p
```

### Summary
```c
int n = 50;        // integer variable
int *p = &n;       // p stores the address of n

printf("%i\n", n);   // 50      — the value of n
printf("%p\n", &n);  // 0x123   — the address of n
printf("%p\n", p);   // 0x123   — p holds the same address
printf("%i\n", *p);  // 50      — dereferencing p gives the value at that address
```

### Style Note
The star belongs with the type conceptually, though all three forms compile:
```c
int* p;   // star next to type (recommended in CS50)
int *p;   // star next to name (also common)
int * p;  // star in the middle (also valid)
```

---

## 📏 Pointer Size and NULL

### How Big Is a Pointer?
On modern 64-bit systems, all pointers are **8 bytes** (64 bits) regardless of what they point to:

```c
int n = 50;
int *p = &n;

printf("%zu\n", sizeof(n));  // 4  — int is 4 bytes
printf("%zu\n", sizeof(p));  // 8  — pointer is 8 bytes on 64-bit systems
```

### NULL
`NULL` is the special memory address `0x0` — a location where nothing should ever live. It's used as a sentinel value meaning "no valid address":

```c
int *p = NULL;   // p points to nothing — a safe initial value

if (p == NULL)
    // pointer is unset — don't dereference it!
```

**Never dereference a NULL pointer** — it will crash your program (segmentation fault).

---

## 🔤 Strings are Pointers

All this time, a **string** has secretly been a `char *` — a pointer to the first character in a sequence. The CS50 `string` type was just a friendly alias.

```c
// These are equivalent:
string s = "HI!";   // CS50 library alias
char *s = "HI!";    // what's actually happening
```

Memory layout for `"HI!"`:

```
Address:  0x123  0x124  0x125  0x126
Content:    H      I      !     \0    ← null terminator ends the string

s = 0x123   (s stores the address of the first character)
```

The null terminator `\0` is how C knows where the string ends. Functions like `printf` and `strlen` walk forward from the pointer until they find `\0`.

---

## 🧮 Pointer Arithmetic

Since strings are pointers, you can do arithmetic on them to navigate characters:

```c
char *s = "HI!";

printf("%c\n", *s);      // H   — dereference: value at s
printf("%c\n", *(s+1));  // I   — value one byte ahead
printf("%c\n", *(s+2));  // !   — value two bytes ahead
```

Array bracket notation `s[i]` is just **syntactic sugar** for `*(s + i)`:
```c
s[0]  ==  *(s + 0)  ==  'H'
s[1]  ==  *(s + 1)  ==  'I'
s[2]  ==  *(s + 2)  ==  '!'
```

The two forms are completely interchangeable.

---

## ⚖️ Comparing Strings Correctly

A common mistake: using `==` to compare strings compares their **addresses**, not their contents.

```c
// ❌ WRONG — compares memory addresses, not values
char *s = get_string("s: ");
char *t = get_string("t: ");

if (s == t)  // almost always false! s and t point to different locations
    printf("same\n");

// ✅ CORRECT — use strcmp to compare contents
if (strcmp(s, t) == 0)
    printf("same\n");
```

`strcmp` walks both strings character by character:
- Returns `0` if equal
- Returns negative if `s` comes before `t` alphabetically
- Returns positive if `s` comes after `t`

---

## 📋 Copying Strings — The Problem

Similarly, you cannot copy a string with `=`. This only copies the **address**, not the data:

```c
// ❌ WRONG — t and s now point to the SAME string
char *s = get_string("s: ");
char *t = s;

t[0] = toupper(t[0]);  // also capitalizes s! They share the same memory.
```

```
Before:  s ──►  [ h | i | ! | \0 ]
         t ──►  (same location)

After capitalize t[0]:
         s ──►  [ H | i | ! | \0 ]   ← s was also changed!
         t ──►  (same location)
```

To truly copy a string, you need to **allocate new memory** and copy each character.

---

## 🏗️ malloc — Dynamic Memory Allocation

`malloc` (memory allocate) requests a chunk of heap memory at runtime and returns its address:

```c
#include <stdlib.h>

// Allocate space for 4 characters (3 letters + null terminator)
char *t = malloc(strlen(s) + 1);

if (t == NULL)
    return 1;  // malloc failed — out of memory
```

### The Heap vs The Stack

```
Memory Layout:

┌─────────────────┐  high addresses
│      Stack      │  ← local variables, function calls (automatic)
│       ↓         │
│                 │
│       ↑         │
│      Heap       │  ← malloc memory (manual management)
├─────────────────┤
│  Global data    │
├─────────────────┤
│  Program code   │
└─────────────────┘  low addresses (address 0x0 = NULL, never used)
```

- **Stack**: managed automatically — variables disappear when function returns
- **Heap**: managed manually — memory persists until you explicitly `free` it

### Allocating for 3 Integers
```c
// sizeof makes code portable across systems
int *x = malloc(3 * sizeof(int));

x[0] = 72;   // ✅ index 0, not 1
x[1] = 73;   // ✅ index 1
x[2] = 33;   // ✅ index 2
```

---

## 📝 strcpy — Copying Strings Properly

After allocating new memory, copy string contents using a loop or `strcpy`:

### Manual Loop
```c
char *t = malloc(strlen(s) + 1);

// Copy each character including null terminator
for (int i = 0, n = strlen(s); i <= n; i++)
    t[i] = s[i];
```

### Using strcpy (cleaner)
```c
#include <string.h>

char *t = malloc(strlen(s) + 1);
strcpy(t, s);   // destination first, then source
```

After copying:
```
s ──►  [ h | i | ! | \0 ]   (original, unchanged)
t ──►  [ H | i | ! | \0 ]   (independent copy, can modify freely)
```

---

## 🛡️ NULL Checks and Error Handling

Many C functions signal failure by returning `NULL`. Always check:

```c
// get_string can return NULL if memory is exhausted
char *s = get_string("Input: ");
if (s == NULL)
    return 1;

// malloc returns NULL if allocation fails
char *t = malloc(strlen(s) + 1);
if (t == NULL)
    return 1;

// Only capitalize if string is non-empty
if (strlen(s) > 0)
    t[0] = toupper(t[0]);
```

This was always true since week 1 — CS50 just handled it behind the scenes.

---

## 🗑️ free — Returning Memory

Every block of memory you `malloc` must eventually be `free`d — otherwise the program permanently holds memory it no longer needs.

```c
char *t = malloc(strlen(s) + 1);
strcpy(t, s);
t[0] = toupper(t[0]);

// ... use t ...

free(t);   // return the memory to the OS
```

**Rule of thumb:** If you `malloc`'d it, you must `free` it.

CS50's `get_string` handles its own cleanup — you do not `free` strings from `get_string`.

---

## 💧 Memory Leaks

A **memory leak** occurs when a program allocates memory with `malloc` but never calls `free`. The OS thinks the memory is in use even when it's no longer needed.

```c
// ❌ MEMORY LEAK — never freed
for (int i = 0; i < 1000000; i++)
{
    char *s = malloc(100);
    // use s...
    // forgot to free(s)!
}
```

In long-running programs (servers, apps), memory leaks cause:
- Increasing RAM usage over time
- Slowing performance
- Eventually, crashes

This is why apps sometimes get "slower and slower" the longer they run.

---

## 🔬 Valgrind — Detecting Memory Errors

**Valgrind** is a tool that monitors memory usage and reports errors:

```bash
valgrind ./memory
```

Valgrind detects:
- **Memory leaks** — malloc without free
- **Invalid reads/writes** — accessing memory you don't own
- **Use of uninitialized values** — reading garbage values

### Example Errors Valgrind Catches

```c
// memory.c — deliberately buggy program
int *x = malloc(3 * sizeof(int));
x[1] = 72;   // ← wrong index (should be 0)
x[2] = 73;   // ← wrong index (should be 1)
x[3] = 33;   // ← off by one! writing past allocated memory
// forgot to call free(x)
```

Valgrind output will flag:
- Invalid write at line 3 (writing to x[3] which wasn't allocated)
- Memory leak: 12 bytes never freed

---

## 🗑️ Garbage Values

Memory on the heap (and stack) is **not zeroed out** when allocated. It contains whatever bytes were left from previous use — called **garbage values**.

```c
int *x = malloc(sizeof(int));
// x points to some location with unknown contents like: 0xAB34FF12
// DO NOT read x before writing to it!
*x = 50;   // now safe to use
```

```
Before malloc:  [ ?? | ?? | ?? | ?? ]   ← garbage
After malloc:   [ 50 | ?? | ?? | ?? ]   ← only first byte set
```

Always initialize memory before reading from it.

---

## 📡 scanf and Stack Buffers

`scanf` is C's standard function for reading user input. It requires a pointer to where the input should be stored:

```c
// Reading an integer (& gives scanf the address to write to)
int n;
scanf("%i", &n);

// Reading a string (s is already a pointer — no & needed)
char s[4];         // stack-allocated buffer for up to 3 chars + \0
scanf("%s", s);
```

### The Danger of Uninitialized Pointers
```c
// ❌ WRONG — s is an uninitialized pointer (garbage address)
char *s;
scanf("%s", s);    // writing to a random memory location — undefined behavior!

// ✅ CORRECT — allocate actual memory first
char s[100];       // stack buffer
scanf("%s", s);
```

---

## 💥 Buffer Overflow

A **buffer overflow** occurs when more data is written into a buffer than it can hold, overwriting adjacent memory.

```c
char s[4];         // space for only 3 chars + \0
scanf("%s", s);    // if user types "hello", writes 6 bytes into a 4-byte buffer!
```

Buffer overflows can:
- Crash the program (segmentation fault)
- Corrupt other variables
- Be exploited for security attacks (overwriting return addresses)

This is exactly why `get_string` from the CS50 library is safer — it dynamically grows to fit whatever the user types, allocating more memory as needed with repeated `malloc` calls.

---

## 📁 File I/O — Introduction

All the programs written so far stored data only in **RAM** — lost when the program exits. **File I/O** (input/output) lets programs read and write data that **persists on disk**.

```
RAM (volatile):           Disk (persistent):
┌──────────────┐          ┌──────────────────┐
│ Variables    │          │ Files (.txt,     │
│ Arrays       │  ──────► │  .csv, .bmp,     │
│ Structs      │  fwrite  │  .jpg, etc.)     │
└──────────────┘          └──────────────────┘
  Gone on exit               Survives reboots
```

Key file functions (all in `stdio.h`):

| Function | Purpose |
|----------|---------|
| `fopen`  | Open (or create) a file |
| `fclose` | Close and save a file |
| `fprintf`| Write formatted text to a file |
| `fscanf` | Read formatted text from a file |
| `fread`  | Read raw bytes from a file |
| `fwrite` | Write raw bytes to a file |

---

## 📂 fopen and fclose

```c
FILE *file = fopen("phonebook.csv", "w");

if (file == NULL)
    return 1;   // file couldn't be opened — check always!

// ... write to file ...

fclose(file);   // save and close the file
```

### File Modes
| Mode | Meaning |
|------|---------|
| `"r"` | Read — file must exist |
| `"w"` | Write — creates or **overwrites** file from the start |
| `"a"` | Append — creates or adds to end of existing file |
| `"rb"`, `"wb"` | Read/write in binary mode (for images, etc.) |

`FILE *` is a pointer to a struct that represents the open file. Always check for `NULL` — `fopen` returns `NULL` if it fails.

---

## ✍️ fprintf — Writing to Files

`fprintf` works exactly like `printf` but takes a file pointer as the first argument:

```c
FILE *file = fopen("phonebook.csv", "a");
if (file == NULL) return 1;

char *name = get_string("Name: ");
char *number = get_string("Number: ");

fprintf(file, "%s,%s\n", name, number);   // write to file
fclose(file);
```

Output in `phonebook.csv`:
```
David,617-495-1000
Kelly,617-495-1000
```

This is a **CSV** (comma-separated values) file — a lightweight spreadsheet format readable by Excel, Google Sheets, and similar tools.

---

## ➕ Append Mode vs Write Mode

```c
// "w" — OVERWRITES the file every time the program runs
FILE *file = fopen("phonebook.csv", "w");

// "a" — APPENDS to the file, preserving existing content
FILE *file = fopen("phonebook.csv", "a");
```

Use `"a"` when you want to add new entries without losing previous ones.

---

## 📖 fread and fwrite

For reading/writing **raw bytes** (images, binary data):

```c
// Read: destination, size of each element, number of elements, source file
fread(&buffer, sizeof(buffer), 1, file);

// Write: source, size of each element, number of elements, destination file
fwrite(&buffer, sizeof(buffer), 1, file);
```

These work byte-by-byte, making them ideal for image manipulation.

---

## 🖨️ Implementing a Copy Program

Using `fread` and `fwrite`, you can implement the Unix `cp` command:

```c
#include <stdio.h>

typedef unsigned char byte;   // byte = 8 bits, no negative values

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");  // open source for reading (binary)
    FILE *dst = fopen(argv[2], "wb"); // open destination for writing (binary)

    if (src == NULL || dst == NULL)
        return 1;

    byte b;
    while (fread(&b, sizeof(b), 1, src) != 0)  // read one byte at a time
    {
        fwrite(&b, sizeof(b), 1, dst);          // write that byte to destination
    }

    fclose(dst);
    fclose(src);
    return 0;
}
```

Usage:
```bash
./cp phonebook.csv copy.csv
```

This copies a file **byte by byte** — like a streaming video player buffering one chunk at a time.

### Why `unsigned char`?
- A regular `char` can be negative (signed), which could confuse raw byte values
- `unsigned char` ensures bytes are interpreted as values 0–255, never negative

---

## 🖼️ BMP Files and Image Filters

**BMP** (bitmap) files store images as a grid of pixels, each with RGB values:

```
BMP File Structure:
┌──────────────────┐
│   File Header    │  ← metadata: file size, type
├──────────────────┤
│   DIB Header     │  ← image width, height, color depth
├──────────────────┤
│  Pixel Array     │  ← rows of pixels, left to right, top to bottom
│  R G B R G B ... │  ← 3 bytes per pixel
└──────────────────┘
```

By reading and modifying these bytes, you can implement image filters:

| Filter | How It Works |
|--------|-------------|
| **Grayscale** | Set R, G, B of each pixel to their average |
| **Sepia** | Apply mathematical formula to shift RGB toward warm brown tones |
| **Reflect** | Swap pixels horizontally (mirror the row) |
| **Blur** | Replace each pixel with the average color of its neighbors |
| **Edge detect** | Apply a Sobel kernel to find sharp color transitions |

This is the same principle behind Instagram filters and Photoshop effects — just math on bytes.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Pixel** | A single colored dot; images are grids of pixels |
| **RGB** | Colors stored as 3 bytes: red, green, blue (0–255 each) |
| **Hexadecimal** | Base-16 number system; `0x` prefix; 2 hex digits = 1 byte |
| **Memory address** | Every variable lives at a numbered location in RAM |
| **`&` operator** | Gets the address of a variable |
| **`*` in declaration** | Declares a pointer (stores an address) |
| **`*` in use** | Dereferences a pointer (gets the value at that address) |
| **Pointer** | A variable that stores a memory address |
| **`%p`** | Format code for printing memory addresses |
| **String = `char *`** | Strings are pointers to the first character; ended by `\0` |
| **Pointer arithmetic** | `s[i]` and `*(s+i)` are identical |
| **`==` on strings** | Compares addresses, not content — use `strcmp` instead |
| **`malloc`** | Allocates memory on the heap; returns `NULL` on failure |
| **`free`** | Returns heap memory to the OS; must be called for every `malloc` |
| **Memory leak** | Allocated memory never freed; causes growing RAM usage |
| **Garbage value** | Uninitialized memory contains random leftover bytes |
| **`NULL`** | Special address `0x0`; used as "no valid address" sentinel |
| **Valgrind** | Tool that detects memory leaks and invalid memory access |
| **Buffer overflow** | Writing more data into a buffer than it can hold |
| **Stack** | Automatic memory for local variables; freed when function returns |
| **Heap** | Manual memory from `malloc`; persists until `free`d |
| **`fopen`** | Opens a file; returns `FILE *` or `NULL` on failure |
| **`fclose`** | Closes and saves a file |
| **`fprintf`** | Like `printf` but writes to a file |
| **`"w"` mode** | Overwrites file from the beginning |
| **`"a"` mode** | Appends to the end of an existing file |
| **`fread` / `fwrite`** | Read/write raw bytes; used for binary files like images |
| **CSV** | Comma-separated values; lightweight spreadsheet format |
| **BMP** | Bitmap image file; stores pixels as raw RGB bytes |
| **`unsigned char`** | 8-bit type used to represent a single byte (values 0–255) |
| **`sizeof`** | Returns the size of a type in bytes; improves portability |

---

## 🗂️ Problem Set 4

Apply memory management, pointers, and file I/O to manipulate real-world image files:
[cs50.harvard.edu/x/2026/psets/4](https://cs50.harvard.edu/x/2026/psets/4/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 3 – Algorithms](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%203%20-%20Algorithms) |
| ➡️ Next | [Week 5 – Data Structures](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%205%20-%20Data%20Structures) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 4 - Memory`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%204%20-%20Memory)
