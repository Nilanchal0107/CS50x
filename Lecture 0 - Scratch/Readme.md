# Lecture 0 – Scratch

This folder contains my work and notes for **Lecture 0 of CS50x 2026**, which introduces the fundamentals of computer science using the graphical programming language **Scratch**.

---

# Lecture Video

CS50x 2026 – Lecture 0
https://www.youtube.com/watch?v=UuIEbpQms8o

---

# Key Concepts Learned

## 1. Computational Thinking

Computer science is fundamentally about **problem solving**.

A typical problem-solving process looks like:

Input → Algorithm → Output

* **Input** – Data given to a program
* **Algorithm** – Step-by-step instructions to solve a problem
* **Output** – The final result

---

## 2. Binary Representation

Computers represent all information using **binary (0 and 1)**.

* **Bit** – A binary digit (0 or 1)
* **Byte** – 8 bits

Example:

| Decimal | Binary |
| ------- | ------ |
| 0       | 000    |
| 1       | 001    |
| 2       | 010    |
| 3       | 011    |
| 4       | 100    |

Binary works well with computers because hardware components like **transistors** can represent **ON (1)** and **OFF (0)**.

---

## 3. Representing Text (ASCII)

Characters are represented using numbers.

Example from **ASCII encoding**:

| Character | Decimal | Binary   |
| --------- | ------- | -------- |
| A         | 65      | 01000001 |
| B         | 66      | 01000010 |
| C         | 67      | 01000011 |

So when you send text like:

HI!

Computers actually transmit numbers:

72 73 33

---

## 4. Unicode

ASCII is limited to **256 characters**.

Modern computers use **Unicode**, which supports:

* many languages
* emojis
* special characters

Example:

😂 → Unicode representation stored as binary numbers.

---

## 5. Images and Colors

Images are made of **pixels**.

Each pixel stores color using **RGB values**:

Red, Green, Blue

Example:

RGB(255, 0, 0) → Red
RGB(0, 255, 0) → Green
RGB(0, 0, 255) → Blue

Each color channel typically uses **1 byte (8 bits)**.

---

## 6. Videos

A video is simply:

Many images displayed quickly.

Example:

30 frames per second → smooth motion.

---

## 7. Algorithms

An **algorithm** is a step-by-step process for solving a problem.

Example: Searching a phone book.

### Linear Search

Check every page one by one.

Time complexity:

O(n)

### Binary Search

Divide the book in half repeatedly.

Time complexity:

O(log n)

Binary search is **much faster**.

---

# Scratch Programming

Scratch is a **visual programming language** created by MIT.

Instead of typing code, programs are built using **drag-and-drop blocks**.

Scratch helps beginners learn programming concepts like:

* loops
* conditionals
* variables
* events
* functions

---

# Example Scratch Program

A simple Scratch program:

When green flag clicked
→ Say "Hello World"

Concepts used:

* Event: when green flag clicked
* Function: say block

---

# Programming Concepts Introduced

### Functions

Reusable blocks of code that perform actions.

Example:

play sound
move sprite

---

### Variables

Store values during program execution.

Example:

score = 0

---

### Conditionals

Decision making:

IF something happens
THEN do something

Example:

If touching mouse pointer → meow

---

### Loops

Repeat actions multiple times.

Example:

Repeat 10 times
→ move forward

---

# My Work

This folder contains:

* Scratch project files
* My solutions for Lecture 0 tasks
* Source code for the Scratch program

---

# What I Learned

* How computers represent data using binary
* How text, images, and videos are stored
* The importance of algorithms
* Basic programming concepts
* Building programs visually using Scratch

---

# Next Lecture

Lecture 1 introduces the **C programming language**, where we begin writing real code and understanding how computers work at a lower level.
