# 📚 CS50x – Week 6: Python
### Harvard University's Introduction to Python Programming

> *"Today, very excitingly, all of that is truly going to go away and be distilled into a single line of code."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-Python-blue?style=flat-square&logo=python)](https://www.python.org/)
[![Lecture](https://img.shields.io/badge/Lecture-Week%206-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/6/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=Rl0ludWTLxs)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 6](https://www.youtube.com/watch?v=Rl0ludWTLxs) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/6](https://cs50.harvard.edu/x/2026/notes/6/) |
| 📖 Python Docs | [docs.python.org](https://docs.python.org/3/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 6 | [cs50.harvard.edu/x/2026/psets/6](https://cs50.harvard.edu/x/2026/psets/6/) |

---

## 📋 Table of Contents

1. [Why Python?](#-why-python)
2. [Running Python Programs](#-running-python-programs)
3. [Hello, World](#-hello-world)
4. [Python vs C — Key Differences](#-python-vs-c--key-differences)
5. [Speller in Python — The Trade-off](#-speller-in-python--the-trade-off)
6. [Image Filters in 4 Lines](#-image-filters-in-4-lines)
7. [Libraries, Modules, and Packages](#-libraries-modules-and-packages)
8. [The CS50 Library for Python](#-the-cs50-library-for-python)
9. [Getting User Input — input()](#-getting-user-input--input)
10. [Variables — No Types Required](#-variables--no-types-required)
11. [String Concatenation and F-Strings](#-string-concatenation-and-f-strings)
12. [Named Parameters](#-named-parameters)
13. [Python Data Types](#-python-data-types)
14. [Type Conversion — int(), float(), str()](#-type-conversion--int-float-str)
15. [Conditionals — if, elif, else](#-conditionals--if-elif-else)
16. [Comparing Strings with ==](#-comparing-strings-with-)
17. [Boolean Operators — and, or, not](#-boolean-operators--and-or-not)
18. [Lists](#-lists)
19. [The `in` Keyword](#-the-in-keyword)
20. [Object-Oriented Programming and Methods](#-object-oriented-programming-and-methods)
21. [String Methods](#-string-methods)
22. [Copying Strings the Easy Way](#-copying-strings-the-easy-way)
23. [Uppercasing Strings](#-uppercasing-strings)
24. [Loops — while](#-loops--while)
25. [Loops — for and range()](#-loops--for-and-range)
26. [Defining Functions with def](#-defining-functions-with-def)
27. [The main() Convention in Python](#-the-main-convention-in-python)
28. [Truncation and Floating Point](#-truncation-and-floating-point)
29. [Integer Overflow — No Longer a Problem](#-integer-overflow--no-longer-a-problem)
30. [Exceptions — try and except](#-exceptions--try-and-except)
31. [Mario — Pyramids in Python](#-mario--pyramids-in-python)
32. [Lists of Scores and Built-in Functions](#-lists-of-scores-and-built-in-functions)
33. [Dictionaries — Key-Value Pairs](#-dictionaries--key-value-pairs)
34. [Lists of Dictionaries](#-lists-of-dictionaries)
35. [Command-Line Arguments — sys.argv](#-command-line-arguments--sysargv)
36. [Exit Statuses — sys.exit()](#-exit-statuses--sysexit)
37. [CSV Files](#-csv-files)
38. [CSV DictWriter](#-csv-dictwriter)
39. [Installing Third-Party Libraries with pip](#-installing-third-party-libraries-with-pip)
40. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🐍 Why Python?

Python is a **higher-level language** than C. Decades of programming language design have allowed Python to:

- Do more for the programmer automatically (memory management, type inference, dynamic sizing)
- Require far less syntax to express the same ideas
- Ship with a huge standard library and ecosystem
- Make code readable enough to almost speak aloud

The trade-off: Python is generally **slower** than compiled C because it is **interpreted** — read and executed line by line — rather than compiled to machine code in advance. However, for most real-world tasks, Python is fast enough.

```
C workflow:          Python workflow:
hello.c             hello.py
   ↓  (clang)          ↓  (python interpreter)
hello (machine code) → runs directly
   ↓
 ./hello
```

---

## ▶️ Running Python Programs

In C you compiled first, then ran. In Python you simply run:

```bash
# C
make hello        # compile
./hello           # run

# Python
python hello.py   # run directly (no compile step)
```

Python files use the `.py` extension. The Python interpreter (`python`) reads and executes your code top to bottom.

---

## 👋 Hello, World

```python
# hello.py
print("Hello, world")
```

Compared to C:

```c
// hello.c
#include <stdio.h>

int main(void)
{
    printf("Hello, world\n");
}
```

What's gone in Python:
- No `#include`
- No `int main(void)`
- No curly braces `{}`
- No semicolons `;`
- No `\n` — a new line is added automatically
- `printf` → `print`

---

## ⚖️ Python vs C — Key Differences

| Feature | C | Python |
|---------|---|--------|
| Compilation | Required (`make` / `clang`) | Not needed (interpreted) |
| Main function | `int main(void)` required | Optional (just write code) |
| Semicolons | Required `;` | Not used |
| Curly braces | Required `{}` | Not used — indentation instead |
| Variable types | Must be declared (`int x`) | Inferred automatically (`x = 1`) |
| String format | `printf("%s\n", name)` | `print(f"Hello, {name}")` |
| New line | Explicit `\n` | Automatic |
| Increment | `i++` or `i += 1` | `i += 1` only (`++` doesn't exist) |
| Comments | `//` or `/* */` | `#` |
| `if/else if/else` | `if / else if / else` | `if / elif / else` |
| Boolean operators | `&&`, `\|\|`, `!` | `and`, `or`, `not` |
| True/False | `true` / `false` (lowercase) | `True` / `False` (capitalized) |

---

## 📖 Speller in Python — The Trade-off

The same spell-checker from Problem Set 5, reimplemented in Python in ~19 lines:

```python
# dictionary.py
words = set()

def check(word):
    return word.lower() in words

def load(dictionary):
    with open(dictionary) as file:
        words.update(file.read().splitlines())
    return True

def size():
    return len(words)

def unload():
    return True   # Python handles memory for us
```

**Results on Holmes.txt:**

| Version | Time |
|---------|------|
| C (compiled) | 1.32 seconds |
| Python (interpreted) | 1.87 seconds |

The Python version was written in minutes; the C version took days. The ~0.5 second difference is the cost of interpretation overhead. For most use cases, Python's speed is more than adequate.

---

## 🖼️ Image Filters in 4 Lines

Python's ecosystem makes complex tasks trivial. Blurring an image:

```python
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")
```

Edge detection:

```python
from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("out.bmp")
```

Four lines each, versus hundreds in C.

---

## 📦 Libraries, Modules, and Packages

In C you used `#include <library.h>`. In Python the vocabulary is different:

- A **module** = a library (a file of Python code)
- A **package** = a collection of modules
- Both are accessed with `import`

```python
# Import a specific function from a module
from cs50 import get_string

# Import a whole module and access things inside it
import sys
print(sys.argv)
```

Python's official documentation at [docs.python.org](https://docs.python.org/3/) lists all built-in functions and modules.

---

## 🏫 The CS50 Library for Python

Just like in C, the CS50 library exists in Python as a set of training wheels to ease the transition:

```python
from cs50 import get_string, get_int, get_float
```

| CS50 Function | Purpose |
|---------------|---------|
| `get_string(prompt)` | Get a string from the user |
| `get_int(prompt)` | Get an integer (re-prompts on invalid input) |
| `get_float(prompt)` | Get a float (re-prompts on invalid input) |

These training wheels can — and should — be removed quickly. Python's built-in `input()` function replaces `get_string`.

---

## ⌨️ Getting User Input — `input()`

```python
# CS50 version
from cs50 import get_string
answer = get_string("What's your name? ")

# Python native version (preferred)
answer = input("What's your name? ")
```

`input()` always returns a **string**, even if the user types a number.

---

## 📦 Variables — No Types Required

```c
// C — type required
int counter = 0;
```

```python
# Python — type inferred
counter = 0
```

Python figures out the type from context. If you assign `0`, it's an `int`. If you assign `"hello"`, it's a `str`. No declaration syntax needed.

Incrementing:
```python
counter = counter + 1   # verbose
counter += 1            # shorthand — most common
# counter++             # ❌ does NOT exist in Python
```

---

## 🔤 String Concatenation and F-Strings

Three ways to combine strings and variables in Python:

```python
name = "David"

# 1. Concatenation with +
print("Hello, " + name)

# 2. Multiple arguments to print (separated by a space by default)
print("Hello,", name)

# 3. F-string (formatted string) — most Pythonic
print(f"Hello, {name}")
```

F-strings place a variable's value directly inside `{}` within a string prefixed with `f`. This is the preferred modern Python style.

```python
# ❌ Forgot the f — prints literally: "Hello, {name}"
print("Hello, {name}")

# ✅ Correct f-string — prints: "Hello, David"
print(f"Hello, {name}")
```

---

## 🏷️ Named Parameters

Python functions can accept **named parameters**, letting you specify arguments by name rather than position:

```python
# Override the default newline at the end of print
print("Hello", end="")       # no newline
print("Hello", end="\n")     # explicit newline (the default)
print("Hello", end="!!!\n")  # custom ending

# Override the default space separator between arguments
print("Hello", "world", sep=", ")   # prints: Hello, world
```

The `print` function signature:
```python
print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)
```

- `sep` — what goes between multiple arguments (default: single space)
- `end` — what goes at the end (default: newline `\n`)

---

## 🗂️ Python Data Types

Python has fewer types than C, and you never declare them explicitly:

| Python Type | Description | Example |
|-------------|-------------|---------|
| `int` | Integer | `42` |
| `float` | Floating-point number | `3.14` |
| `str` | String (aka STR) | `"hello"` |
| `bool` | Boolean | `True`, `False` |
| `list` | Ordered, mutable sequence | `[1, 2, 3]` |
| `tuple` | Ordered, immutable sequence | `(1, 2)` |
| `dict` | Key-value pairs (hash table) | `{"name": "David"}` |
| `set` | Unique unordered values | `{"apple", "banana"}` |
| `range` | Sequence of numbers | `range(3)` → 0, 1, 2 |

**No pointers in Python.** Memory management is handled automatically — no `malloc`, no `free`, no segmentation faults.

---

## 🔄 Type Conversion — `int()`, `float()`, `str()`

Since `input()` always returns a string, you must convert when you need a number:

```python
x = input("x: ")   # returns "1" as a string
y = input("y: ")   # returns "2" as a string

# ❌ WRONG — string concatenation, not addition
print(x + y)        # prints "12"

# ✅ CORRECT — convert to int first
print(int(x) + int(y))   # prints 3
```

You can nest the conversion:
```python
x = int(input("x: "))   # convert immediately on input
y = int(input("y: "))
print(x + y)             # prints 3
```

Conversion functions:
```python
int("42")      # → 42
float("3.14")  # → 3.14
str(42)        # → "42"
```

---

## 🔀 Conditionals — `if`, `elif`, `else`

```python
# C version
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

```python
# Python version
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")
```

Key differences:
- No parentheses around the condition (optional but not idiomatic)
- No curly braces — **indentation** (4 spaces) defines code blocks
- **Colon `:` after each condition**
- `else if` → `elif`

---

## 🔍 Comparing Strings with `==`

In C, `==` compared **pointers** (memory addresses), not string content, so `strcmp` was required. In Python, `==` correctly compares **values**:

```python
s = input("s: ")
t = input("t: ")

if s == t:
    print("Same")
else:
    print("Different")
```

Python handles the character-by-character comparison internally. No `strcmp` needed.

---

## 🔁 Boolean Operators — `and`, `or`, `not`

Python replaces C's `&&`, `||`, `!` with plain English:

```c
// C
if (c == 'Y' || c == 'y')
```

```python
# Python
if s == "Y" or s == "y":
```

Also: `and` instead of `&&`, `not` instead of `!`.

---

## 📋 Lists

Python **lists** replace C arrays with a much more powerful version:

```python
# Create a list
names = ["Kelly", "David", "John Harvard"]

# Access by index (0-based, same as C)
print(names[0])   # Kelly

# Lists can hold mixed types
mixed = [1, "hello", 3.14, True]

# Empty list
scores = []

# Add to a list
scores.append(72)
scores.append(73)
scores.append(33)
```

Unlike C arrays:
- Lists can **grow and shrink** dynamically (no fixed size)
- You can ask for the length at any time with `len()`
- No manual memory management needed

---

## 🔎 The `in` Keyword

Python's `in` keyword lets you search a list without writing a loop:

```python
names = ["Kelly", "David", "John Harvard"]
name = input("Name: ")

if name in names:
    print("Found")
else:
    print("Not found")
```

Python performs linear search internally. This reads almost like English: "if name is in names."

---

## 🏛️ Object-Oriented Programming and Methods

In Python, variables are **objects** — they have not only values but built-in **methods** (functions attached to the object):

```c
// C — passing argument to a global function
toupper(c);
```

```python
# Python — calling a method on the object itself
s.upper()
```

Access methods using **dot notation**, just like struct fields in C. The difference: methods are functions, not data.

```python
s = "hello"
print(s.upper())     # "HELLO"
print(s.lower())     # "hello"
print(s.capitalize())# "Hello"
```

---

## 🔡 String Methods

Python strings come with many built-in methods. Some of the most useful:

| Method | Result | Example |
|--------|--------|---------|
| `.upper()` | All uppercase | `"hi".upper()` → `"HI"` |
| `.lower()` | All lowercase | `"HI".lower()` → `"hi"` |
| `.capitalize()` | First letter uppercased | `"hello".capitalize()` → `"Hello"` |
| `.strip()` | Remove leading/trailing whitespace | `"  hi  ".strip()` → `"hi"` |
| `.split()` | Split into a list | `"a,b,c".split(",")` → `["a","b","c"]` |
| `.isnumeric()` | Check if string is a number | `"42".isnumeric()` → `True` |

You can chain methods together:
```python
answer = input("Do you agree? ").lower()
```

Full list at [docs.python.org/3/library/stdtypes.html#string-methods](https://docs.python.org/3/library/stdtypes.html#string-methods)

---

## 📄 Copying Strings the Easy Way

In C, copying a string required `malloc`, a loop, and `strcpy`. In Python:

```python
s = input("s: ")
t = s.capitalize()   # creates an independent copy with first letter capitalized

print(f"s: {s}")
print(f"t: {t}")
```

No memory allocation needed. Python handles it all.

---

## 🔠 Uppercasing Strings

**Character by character (C-style loop in Python):**
```python
before = input("Before: ")
print("After: ", end="")
for c in before:
    print(c.upper(), end="")
print()
```

**Python idiomatic (one line):**
```python
before = input("Before: ")
after = before.upper()
print(f"After: {after}")
```

Python's `for` loop can iterate directly over each character in a string — no index variable needed.

---

## 🔁 Loops — `while`

```c
// C
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```

```python
# Python
i = 0
while i < 3:
    print("meow")
    i += 1
```

Infinite loop:
```python
# C: while (true)
# Python:
while True:        # capital T!
    print("meow")
```

Use `Ctrl+C` to interrupt an infinite loop.

---

## 🔄 Loops — `for` and `range()`

Python `for` loops are more powerful and readable than C's:

```c
// C
for (int i = 0; i < 3; i++)
    printf("meow\n");
```

```python
# Python — iterate over a list
for i in [0, 1, 2]:
    print("meow")

# Python — using range() (preferred)
for i in range(3):
    print("meow")

# If you don't need the variable, use _ by convention
for _ in range(3):
    print("meow")
```

`range(n)` generates numbers 0 through n-1 without creating the whole list in memory at once.

```python
range(3)       # 0, 1, 2
range(1, 4)    # 1, 2, 3
range(0, 10, 2)# 0, 2, 4, 6, 8  (step by 2)
```

**Multiply strings to repeat them:**
```python
print("?" * 4)        # ????
print("#" * 3 + "\n") # ###
```

**`for` loops with `else`:**
```python
for name in names:
    if name == target:
        print("Found")
        break
else:
    print("Not found")  # runs only if loop completed without break
```

---

## 🛠️ Defining Functions with `def`

```c
// C
void meow(int n)
{
    for (int i = 0; i < n; i++)
        printf("meow\n");
}
```

```python
# Python
def meow(n):
    for _ in range(n):
        print("meow")
```

- `def` replaces `void` (or any return type)
- No type declarations for parameters
- No curly braces — indentation defines the body
- Two blank lines between functions is Pythonic convention

---

## 🏠 The `main()` Convention in Python

Python has no built-in `main` function. But when you define functions, they must be defined before they're called — otherwise you get a `NameError`.

**The Pythonic solution:**

```python
def main():
    for _ in range(3):
        meow()

def meow():
    print("meow")

# Call main at the bottom — after all functions are defined
if __name__ == "__main__":
    main()
```

- Define `main()` first, then any helpers
- Define all functions before they run
- Call `main()` at the very end with the `if __name__ == "__main__":` guard

The `if __name__ == "__main__":` idiom allows your file to be imported by other scripts without automatically running `main()` — it only runs when executed directly.

---

## 🔢 Truncation and Floating Point

**Truncation is solved in Python:**
```python
x = int(input("x: "))
y = int(input("y: "))
print(x / y)   # 1 / 3 → 0.3333...  (not 0!)
```

Python automatically returns a float when dividing integers if the result isn't whole. Use `//` for integer division if you want truncation:
```python
print(1 // 3)   # 0 — integer division (truncates)
print(1 / 3)    # 0.3333... — true division
```

**Floating point imprecision still exists:**
```python
z = 1 / 3
print(f"{z:.50f}")
# 0.33333333333333331482961625624739099...
```

Computers still use finite memory (64 bits for floats), so infinite precision is still impossible. Third-party libraries like `decimal` can provide higher precision when needed.

---

## ♾️ Integer Overflow — No Longer a Problem

In C, integers had a fixed size (32 or 64 bits) and could overflow. Python integers have **no fixed limit** — they grow as large as needed:

```python
x = 2 ** 100
print(x)   # 1267650600228229401496703205376  — no overflow!
```

Python automatically allocates more memory as integers grow.

---

## ⚠️ Exceptions — `try` and `except`

In C, errors were signaled via return values (`NULL`, `-1`, `1`, etc.). Python uses **exceptions**:

```python
# ❌ This crashes if user types "cat"
n = int(input("Number: "))
```

```python
# ✅ Handle the error gracefully
try:
    n = int(input("Number: "))
    print(f"You entered: {n}")
except ValueError:
    print("Not an integer!")
```

- `try` — attempt to run this code
- `except ValueError` — if a `ValueError` occurs (like `int("cat")`), run this instead
- You can catch multiple exception types with multiple `except` clauses

Common exception types:

| Exception | Cause |
|-----------|-------|
| `ValueError` | Invalid value (e.g. `int("cat")`) |
| `TypeError` | Wrong type for operation |
| `NameError` | Variable or function used before definition |
| `ZeroDivisionError` | Division by zero |
| `FileNotFoundError` | File doesn't exist |

This is how CS50's `get_int` works under the hood — it loops until a valid integer is entered:
```python
while True:
    try:
        n = int(input("Number: "))
        break
    except ValueError:
        pass   # silently ignore invalid input and ask again
```

---

## 🧱 Mario — Pyramids in Python

**Simple column of bricks:**
```python
for _ in range(3):
    print("#")
```

**Row of question marks:**
```python
print("?" * 4)
```

**3×3 grid of bricks:**
```python
for _ in range(3):
    print("#" * 3)
```

**Getting height from user (replaces C's do-while):**
```python
while True:
    n = int(input("Height: "))
    if n > 0:
        break

for _ in range(n):
    print("#")
```

Python has no `do-while` loop. The `while True` + `break` pattern is the Pythonic equivalent.

---

## 📊 Lists of Scores and Built-in Functions

```python
# Hard-coded scores
scores = [72, 73, 33]

# Calculate average using built-in functions
average = sum(scores) / len(scores)
print(f"Average: {average}")
```

**Getting scores from user input:**
```python
scores = []

for _ in range(3):
    score = int(input("Score: "))
    scores.append(score)

print(f"Average: {sum(scores) / len(scores)}")
```

Useful built-in list functions:

| Function | Purpose |
|----------|---------|
| `len(list)` | Number of elements |
| `sum(list)` | Sum of all elements |
| `min(list)` | Smallest element |
| `max(list)` | Largest element |
| `sorted(list)` | Returns a sorted copy |

---

## 📖 Dictionaries — Key-Value Pairs

Python **dicts** are built-in hash tables — no implementation needed:

```python
# Create a dictionary with curly braces
people = {
    "Kelly": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John":  "+1-949-468-2750"
}

# Look up a value by key
name = input("Name: ")

if name in people:
    print(f"Found: {people[name]}")
else:
    print("Not found")
```

- Keys can be strings (unlike array indices which must be integers)
- `dict[key]` retrieves the value for that key
- `key in dict` checks membership — Python searches efficiently

---

## 📇 Lists of Dictionaries

Combining lists and dicts represents rows of a spreadsheet or database table:

```python
# Each dict is one "row" (person)
people = [
    {"name": "Kelly", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John",  "number": "+1-949-468-2750"}
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found: {person['number']}")
        break
else:
    print("Not found")
```

This structure — a list of dicts — is how most real-world Python code represents database rows, API responses, and spreadsheet data.

---

## 💻 Command-Line Arguments — `sys.argv`

Since Python programs don't use `int main(int argc, char *argv[])`, command-line arguments come from the `sys` module:

```python
from sys import argv

if len(argv) == 2:
    name = argv[1]
    print(f"Hello, {name}")
else:
    print("Hello, world")
```

```bash
python greet.py David    # prints: Hello, David
python greet.py          # prints: Hello, world
```

- `argv` is a list of strings
- `argv[0]` is the script name (`greet.py`)
- `argv[1]` is the first argument typed after the script name
- `len(argv)` replaces C's `argc`
- The Python interpreter itself (`python`) is not counted

---

## 🚪 Exit Statuses — `sys.exit()`

```python
import sys

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

print(f"Hello, {sys.argv[1]}")
sys.exit(0)
```

- `sys.exit(0)` — success
- `sys.exit(1)` — error (or any non-zero integer)

Accessing via `import sys` (rather than `from sys import argv`) requires `sys.argv` and `sys.exit` — prefixed with the library name.

---

## 📁 CSV Files

Python has a built-in `csv` library for reading and writing comma-separated values:

```python
import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow([name, number])
```

- `open("file.csv", "a")` — open in append mode
- `with` — automatically closes the file when done (no `fclose` needed)
- `csv.writer(file)` — creates a writer object
- `writer.writerow([...])` — writes one row as a list of values

The `with` keyword is Python's safe file-handling pattern — it closes the file even if an error occurs.

---

## 📑 CSV DictWriter

For files with a header row, use `DictWriter` to write by column name rather than position:

```python
import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file:
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
```

This is more **resilient** — if columns are reordered, the code still writes the right values to the right columns.

---

## 📦 Installing Third-Party Libraries with `pip`

Python has a package manager called `pip` for installing third-party libraries:

```bash
pip install cowsay        # install the cowsay library
pip install qrcode        # install QR code generator
pip install pyttsx3       # install text-to-speech
```

Using an installed library:

```python
import cowsay
cowsay.cow("This is CS50")
```

```python
import qrcode
image = qrcode.make("https://youtu.be/Rl0ludWTLxs")
image.save("qr.png")
```

If a library isn't installed, Python raises:
```
ModuleNotFoundError: No module named 'cowsay'
```

Fix: run `pip install cowsay` in your terminal.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Python** | Higher-level, interpreted language; less syntax, more built-in power |
| **`python file.py`** | Run a Python program — no compilation step needed |
| **No semicolons** | Statements end at the newline |
| **Indentation** | 4 spaces define code blocks (required, not optional) |
| **`print()`** | Replaces `printf`; adds `\n` automatically |
| **`input()`** | Replaces `get_string`; always returns a `str` |
| **`int()`, `float()`** | Convert strings to numbers |
| **No type declarations** | Python infers types from assigned values |
| **`f"Hello, {name}"`** | F-string: interpolates variable values inside `{}` |
| **`end=`** | Named parameter to override print's newline |
| **`sep=`** | Named parameter to override print's space separator |
| **`if / elif / else`** | Conditionals; `elif` replaces `else if` |
| **`and`, `or`, `not`** | Replace `&&`, `\|\|`, `!` |
| **`True` / `False`** | Capital T and F (unlike C's lowercase) |
| **`==` on strings** | Compares values correctly (no `strcmp` needed) |
| **`list`** | Dynamic array; use `append()` to add, `len()` for size |
| **`in` keyword** | `if x in list` — searches the list |
| **`range(n)`** | Generates 0 through n-1; memory-efficient |
| **`for x in iterable`** | Iterate over any list, string, range, etc. |
| **`while True: ... break`** | Replaces C's `do-while` loop |
| **`i += 1`** | Increment; `++` does not exist in Python |
| **`def`** | Define a function; no return type or param types needed |
| **`if __name__ == "__main__":`** | Safely call `main()` at the end of the file |
| **Methods** | Functions built into objects, called with dot notation |
| **`.upper()`, `.lower()`** | String methods to change case |
| **`dict`** | Built-in hash table; index with string keys |
| **List of dicts** | Represents rows of data (like a spreadsheet) |
| **`try` / `except`** | Handle errors without checking return values |
| **No integer overflow** | Python integers grow as large as needed |
| **`/` vs `//`** | `/` = true division; `//` = integer division (truncates) |
| **`sys.argv`** | List of command-line arguments |
| **`sys.exit()`** | Exit with a status code (0 = success) |
| **`with open(...) as f`** | Opens a file and closes it automatically |
| **`csv.writer`** | Write CSV rows as lists |
| **`csv.DictWriter`** | Write CSV rows as dicts by field name |
| **`pip install`** | Install third-party Python packages |
| **No pointers** | Python manages memory automatically |

---

## 🗂️ Problem Set 6

Re-implement your favourite C programs in Python, and explore new Python-exclusive challenges:
[cs50.harvard.edu/x/2026/psets/6](https://cs50.harvard.edu/x/2026/psets/6/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 5 – Data Structures](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%205%20-%20Data%20Structures) |
| ➡️ Next | Week 7 – SQL *(coming soon)* |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 6 - Python`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%206%20-%20Python)
