# CS50x – Lecture 0: Scratch

This folder contains notes, solutions, and source code related to **Lecture 0 of CS50x**.

Lecture 0 introduces the **fundamental concepts of computer science**, including how computers represent information, how algorithms solve problems, and how to build programs using **Scratch**, a visual programming language.

---

# Lecture Link

Official Lecture Notes
https://cs50.harvard.edu/x/notes/0/

Lecture Video
https://www.youtube.com/watch?v=UuIEbpQms8o

---

# What is Computer Science?

Computer science is fundamentally about **problem solving**.

A problem can be represented as:

Input → Algorithm → Output

* **Input** – Data given to a program
* **Algorithm** – Step-by-step instructions
* **Output** – The result of the computation

Computer science focuses on designing **efficient algorithms** to transform input into output. ([edX][1])

---

# Computational Thinking

Computational thinking involves solving problems in a structured and logical way.

Key ideas include:

* Breaking problems into smaller steps
* Designing algorithms
* Testing solutions
* Improving efficiency

---

# Representation of Information

Computers represent all information using **binary**, which consists of only two digits:

```
0 and 1
```

These binary digits are called **bits**.

---

## Bits and Bytes

* **Bit** → a single binary digit (0 or 1)
* **Byte** → 8 bits

Example:

```
00000000 = 0
00000001 = 1
00000010 = 2
00000011 = 3
```

Using multiple bits allows computers to represent larger numbers.

---

# Binary vs Decimal

Humans typically use the **decimal system (base 10)**.

Example:

```
123 = (1 × 100) + (2 × 10) + (3 × 1)
```

Computers use the **binary system (base 2)**.

Example:

```
101 = (1 × 4) + (0 × 2) + (1 × 1)
```

Binary is used because hardware can easily represent **on/off electrical states**.

---

# Representing Text

Computers represent characters using numbers.

One common encoding system is **ASCII**.

Example:

| Character | Decimal |
| --------- | ------- |
| A         | 65      |
| B         | 66      |
| C         | 67      |

So the text:

```
HI
```

is stored as:

```
72 73
```

in ASCII encoding.

---

# Unicode

ASCII supports only a limited number of characters.

To support many languages and symbols, modern systems use **Unicode**, which includes:

* international languages
* emojis
* special characters

Unicode uses more bits to represent characters.

---

# Representing Images

Images are composed of **pixels** (tiny colored dots).

Each pixel is represented using **RGB color values**:

```
Red
Green
Blue
```

Each color can range from:

```
0 → none
255 → maximum
```

Example:

```
RGB(255,0,0) → Red
RGB(0,255,0) → Green
RGB(0,0,255) → Blue
```

Combining these values allows computers to represent millions of colors.

---

# Representing Video

A video is simply:

```
many images displayed rapidly
```

Example:

```
30 frames per second
```

When shown quickly, these images appear as motion.

---

# Representing Sound

Sound can be represented digitally using numbers that represent:

* frequency (pitch)
* amplitude (volume)
* duration

These numeric values are stored as binary.

---

# Algorithms

An **algorithm** is a step-by-step method for solving a problem.

Example: Searching a phone book.

### Linear Search

Check each page sequentially.

Time complexity:

```
O(n)
```

---

### Binary Search

Divide the search space in half repeatedly.

Steps:

1. Open the phone book in the middle
2. Determine if the name is before or after
3. Repeat on the correct half

Time complexity:

```
O(log n)
```

Binary search is significantly faster for large datasets.

---

# Pseudocode

Before writing code, programmers often write **pseudocode**.

Example:

```
1. Pick up phone book
2. Open to middle
3. If name found → stop
4. If name earlier → search left half
5. If name later → search right half
```

Pseudocode helps design algorithms before implementing them in code.

---

# Scratch Programming

Scratch is a **block-based programming language** developed at MIT.

Instead of writing text code, programs are created by **dragging and connecting blocks**.

Scratch introduces fundamental programming concepts:

* Events
* Functions
* Variables
* Loops
* Conditionals
* Boolean expressions

---

# Example Scratch Program

Example program:

When green flag clicked

Say:

```
Hello, World
```

---

# Programming Concepts Introduced

### Functions

Reusable blocks of code that perform actions.

Example:

```
say
move
play sound
```

---

### Variables

Variables store values during program execution.

Example:

```
score = 0
```

---

### Conditionals

Used for decision making.

Example:

```
if touching mouse pointer
    play sound
```

---

### Loops

Loops repeat actions.

Example:

```
repeat 10 times
```

---

# Abstraction

Abstraction allows programmers to build complex programs by combining smaller components.

Example:

* Creating a custom block called `meow`
* Reusing that block multiple times

This hides lower-level details and simplifies code.

---

# Scratch Project

The assignment for Lecture 0 is to create a **Scratch project** that demonstrates the concepts learned.

The project must:

* include loops
* include conditionals
* include variables
* include interactive elements

---

# Key Takeaways

Lecture 0 introduces the foundations of computer science:

* Problem solving
* Binary representation
* Data encoding
* Algorithms
* Programming basics
* Scratch programming

These concepts form the foundation for the rest of the course.

---

# Next Lecture

Lecture 1 introduces the **C programming language**, where we begin writing real code and understanding how computers execute programs.

[1]: https://cs50.harvard.edu/x/2022/notes/0/?utm_source=chatgpt.com "Lecture 0 - CS50x 2022"
