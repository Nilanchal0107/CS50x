# 📚 CS50x – Week 0: Scratch
### Harvard University's Introduction to Computer Science

> *"This is CS50 — Harvard University's introduction to the intellectual enterprises of Computer Science and the arts of programming."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-Scratch-orange?style=flat-square)](https://scratch.mit.edu/)
[![Lecture](https://img.shields.io/badge/Lecture-Week%200-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/0/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=UuIEbpQms8o)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 0](https://www.youtube.com/watch?v=UuIEbpQms8o) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/0](https://cs50.harvard.edu/x/2026/notes/0/) |
| 🐱 Scratch Editor | [scratch.mit.edu](https://scratch.mit.edu/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 0 | [cs50.harvard.edu/x/2026/psets/0](https://cs50.harvard.edu/x/2026/psets/0/) |

---

## 📋 Table of Contents

1. [What is CS50?](#-what-is-cs50)
2. [The Role of AI in Programming](#-the-role-of-ai-in-programming)
3. [What is Computer Science?](#-what-is-computer-science)
4. [Problem Solving Model](#-problem-solving-model)
5. [Number Systems](#-number-systems)
6. [Binary & Bits](#-binary--bits)
7. [Representing Text — ASCII](#-representing-text--ascii)
8. [Unicode & Emoji](#-unicode--emoji)
9. [Representing Colors — RGB](#-representing-colors--rgb)
10. [Representing Images, Video & Sound](#-representing-images-video--sound)
11. [Algorithms](#-algorithms)
12. [Algorithm Efficiency](#-algorithm-efficiency)
13. [Pseudocode](#-pseudocode)
14. [Core Programming Concepts](#-core-programming-concepts)
15. [Abstraction](#-abstraction)
16. [Scratch — The Language](#-scratch--the-language)
17. [Scratch Interface](#-scratch-interface)
18. [Functions in Scratch](#-functions-in-scratch)
19. [Variables in Scratch](#-variables-in-scratch)
20. [Conditionals in Scratch](#-conditionals-in-scratch)
21. [Loops in Scratch](#-loops-in-scratch)
22. [Custom Functions (Making a Block)](#-custom-functions-making-a-block)
23. [Return Values vs Side Effects](#-return-values-vs-side-effects)
24. [Building a Real Scratch Project](#-building-a-real-scratch-project)
25. [Code Quality](#-code-quality)
26. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🏫 What is CS50?

CS50 is **Harvard University's introduction to the intellectual enterprises of Computer Science and the arts of programming**. It is one of the most popular courses in the world, available both on campus and free online through edX.

**CS50 is NOT just about learning to program.** The deeper goal is to teach you:
- How to **think like a computer scientist**
- How to take a problem, break it down, and produce a correct solution
- How to **teach yourself** new technologies and languages
- How to be the "pilot" — in control of tools like AI, not just a passenger

By the end of CS50, you will have worked with:

| Language | Purpose |
|----------|---------|
| **Scratch** | Visual programming, core concepts |
| **C** | Low-level programming, memory, systems |
| **Python** | High-level, modern scripting |
| **SQL** | Databases |
| **HTML/CSS/JavaScript** | Web development |

> 💡 *"The overarching goal is to teach you how to think — how to take input and produce correct output, and how to master tools."*

---

## 🤖 The Role of AI in Programming

AI is changing programming — and that's exciting, not scary.

In a live demo at the start of lecture, David built a working chatbot in ~10 lines of Python using OpenAI's API:

```python
from openai import OpenAI

client = OpenAI()

system_prompt = "Limit your answer to one sentence. Pretend you're a cat."
user_prompt = input("Prompt: ")

response = client.chat.completions.create(
    model="gpt-4",
    messages=[
        {"role": "system", "content": system_prompt},
        {"role": "user",   "content": user_prompt}
    ]
)

print(response.choices[0].message.content)
```

**Key ideas demonstrated:**
- **Libraries** — using code others wrote (`openai`) to stand on their shoulders
- **API** (Application Programming Interface) — a service that lets your code talk to someone else's software
- **Variables** — `user_prompt` stores what the human typed
- **System prompts** — instructions that shape AI behavior without the user seeing them
- **Abstraction** — you don't need to know how the AI works internally; you just use it

> 💡 AI is increasingly powerful, but you still need to understand fundamentals to direct it effectively, catch its mistakes, and build things it can't do alone.

### CS50's AI Duck 🦆
CS50 provides its own AI assistant at [cs50.ai](https://cs50.ai), modeled after the programmer tradition of **rubber duck debugging** — talking through your problem out loud (or to a duck) until the solution clicks. The CS50 duck is designed to guide you toward answers without just giving them away.

> ⚠️ In CS50, you may only use **CS50's own AI tools** (not ChatGPT, Gemini, Claude, etc.) for help with problem sets.

---

## 💻 What is Computer Science?

Computer Science is fundamentally the study of **information**:
- How do you **represent** it?
- How do you **process** it?
- How do you use it to **solve problems**?

A closely related concept is **computational thinking** — applying ideas from CS to real-world problems, not just inside a computer.

At its core, CS is about **problem solving**:

```
Input  →  [ Algorithm ]  →  Output
```

The input is the problem. The output is the solution. The algorithm in the middle is the secret sauce — the step-by-step instructions that transform one into the other.

---

## 🧩 Problem Solving Model

Every problem in CS (and life) can be framed as:

```
┌─────────┐     ┌─────────────────┐     ┌──────────┐
│  INPUT  │────▶│   ALGORITHM     │────▶│  OUTPUT  │
│(problem)│     │(step-by-step    │     │(solution)│
│         │     │ instructions)   │     │          │
└─────────┘     └─────────────────┘     └──────────┘
```

But for computers to work with this model, inputs and outputs must be **represented in a standardized way** that machines understand — which is why everything ultimately comes down to zeros and ones.

---

## 🔢 Number Systems

### Base 10 — Decimal (Human World)
The system we use every day. 10 possible digits: `0 1 2 3 4 5 6 7 8 9`

The number **123** in decimal means:
```
  100 × 1  +  10 × 2  +  1 × 3  =  123
  (10²)       (10¹)      (10⁰)
```

### Base 1 — Unary
Count by using single marks (like fingers). Representing 5 means five marks. Simple but very inefficient — you need 255 marks to represent 255.

### Base 2 — Binary (Computer World)
Only 2 possible digits: `0` and `1`. This maps perfectly to electricity: **off = 0, on = 1**.

The number **7** in binary:
```
  4 × 1  +  2 × 1  +  1 × 1  =  7
  (2²)      (2¹)      (2⁰)
  Binary: 111
```

### Why Binary?
Electricity is simple — it's either flowing or it's not. Distinguishing between just two states (on/off) is far easier to build in hardware than distinguishing 10 levels. This is why every computer, phone, and device on earth is ultimately binary underneath.

---

## 💡 Binary & Bits

### Terminology

| Term | Definition |
|------|-----------|
| **Bit** | A single binary digit: `0` or `1` |
| **Byte** | 8 bits grouped together |
| **Kilobyte (KB)** | ~1,000 bytes (2¹⁰ = 1,024) |
| **Megabyte (MB)** | ~1,000,000 bytes |
| **Gigabyte (GB)** | ~1,000,000,000 bytes |
| **Terabyte (TB)** | ~1,000,000,000,000 bytes |

### How to Read a Byte
Each position in a byte represents a power of 2, from right to left:

```
Bit Position:  128   64   32   16    8    4    2    1
               (2⁷) (2⁶) (2⁵) (2⁴) (2³) (2²) (2¹) (2⁰)
```

**Example — the number 65:**
```
Bit Position:  128   64   32   16    8    4    2    1
Bit Value:      0     1    0    0    0    0    0    1
Calculation:         64                            1   = 65
```

### Counting Range
| Bits | Max Value | Total Possibilities |
|------|-----------|-------------------|
| 1 | 1 | 2 |
| 3 | 7 | 8 |
| 8 (1 byte) | 255 | 256 |
| 32 | ~4 billion | ~4.3 billion |
| 64 | ~18 quintillion | ~18.4 quintillion |

> 💡 With 8 bits, you can represent values **0–255** (256 total patterns). This is why the number **256** appears so often in computing.

### Inside the Hardware
Computers store bits using tiny electronic switches called **transistors**. When a transistor allows electricity to flow, it's a `1`. When it blocks it, it's a `0`. Modern chips contain **billions** of these transistors, allowing them to store and process enormous amounts of information.

---

## 🔤 Representing Text — ASCII

If computers only speak binary/numbers, how do they store letters?

Simple: we **assign a number to every character** and agree on a global standard.

**ASCII** (American Standard Code for Information Interchange) is that standard — a mapping of numbers to characters created by a group of Americans decades ago.

### ASCII Table (Partial)

| Decimal | Binary | Character |
|---------|--------|-----------|
| 65 | 01000001 | A |
| 66 | 01000010 | B |
| 67 | 01000011 | C |
| 90 | 01011010 | Z |
| 97 | 01100001 | a |
| 98 | 01100010 | b |
| 33 | 00100001 | ! |
| 72 | 01001000 | H |
| 73 | 01001001 | I |

### Decoding a Message
If you receive the bytes `72 73 33`:
```
72 → H
73 → I
33 → !
= "HI!"
```

### Uppercase ↔ Lowercase Trick
Lowercase letters are always exactly **32 more** than their uppercase equivalents:
```
'A' = 65     'a' = 97     (difference = 32)
'B' = 66     'b' = 98     (difference = 32)
```
To convert uppercase `A` to lowercase `a`, a computer just flips the **32s bit** from 0 to 1. One single bit change!

### ASCII Limitation
ASCII was designed by Americans for the English alphabet. With only 7–8 bits (256 values max), there's no room for accented characters, Asian scripts, Arabic, emoji, and thousands of other symbols used by the rest of the world.

---

## 🌍 Unicode & Emoji

**Unicode** is the modern solution — a superset of ASCII that uses up to **32 bits per character**, giving room for over **4 billion** possible characters.

This is enough space for:
- All human languages (past, present, future)
- Mathematical symbols
- Ancient scripts
- Emoji 😂

### How Emoji Work
Emoji are just **Unicode characters with a very colorful font**. The character itself is a number (e.g., 😂 = `U+1F602` = 4,036,991,106 in decimal). Different companies (Apple, Google, Samsung) each have their own graphical **font** that renders that number differently, which is why the same emoji can look slightly different across platforms — but the underlying number is identical.

```
Number: 4,036,991,106
Apple renders as:  😂 (yellow, stylized)
Google renders as: 😂 (slightly different shade)
Telegram renders as: 😂 (animated)
```

---

## 🎨 Representing Colors — RGB

Colors are represented as combinations of three values: **Red, Green, Blue** — each between 0 (none) and 255 (max).

```
Color = (R, G, B)
```

### Examples

| R | G | B | Color |
|---|---|---|-------|
| 0 | 0 | 0 | ⬛ Black (no light) |
| 255 | 255 | 255 | ⬜ White (full light) |
| 255 | 0 | 0 | 🔴 Pure Red |
| 0 | 255 | 0 | 🟢 Pure Green |
| 0 | 0 | 255 | 🔵 Pure Blue |
| 72 | 23 | 33 | 🟡 Dark Yellow |

The RGB system comes from old **three-lens projectors** that combined beams of red, green, and blue light to produce any color on a screen.

> 💡 In web development, you'll often see colors written in **hex** (base 16), like `#FF0000` for red. This is just another way to write the same RGB values.

---

## 🖼️ Representing Images, Video & Sound

### Images
An image is a **grid of pixels** (dots). Each pixel stores one color = 3 bytes (R, G, B) = 24 bits.

```
A 1000×1000 pixel image:
= 1,000,000 pixels
× 3 bytes per pixel
= 3,000,000 bytes
≈ 3 MB
```

This is why high-resolution photos are measured in megabytes.

### Video
A video is just a **rapid sequence of images** — typically 24–30 frames per second. This tricks the human eye into perceiving smooth motion (the same principle as old flip books or film reels).

```
1 second of HD video:
= 30 frames/second
× 3 MB per frame (approx.)
= ~90 MB/second (before compression)
```

This is why video files are so large, and why video compression (H.264, HEVC, etc.) is so important.

### Sound
Sound can be represented using numbers encoding:
- **Frequency** — the pitch of the note (how high or low)
- **Duration** — how long the note lasts
- **Amplitude** — how loud the note is (volume)

Three numbers per "note" is a simplified model. Real audio formats (MP3, WAV, AAC) use sophisticated techniques to represent thousands of samples per second.

---

## ⚡ Algorithms

An **algorithm** is a precise, step-by-step set of instructions for solving a problem. Algorithms are the heart of computer science.

### Phone Book Example
Given a phone book of 1,000 pages, find "John Harvard":

**Algorithm 1 — Linear Search (one page at a time)**
```
1. Open to page 1
2. If John Harvard is here → call him, done
3. Otherwise, turn to the next page
4. Go back to step 2
```
- Worst case: **1,000 steps**
- Correct? ✅ Yes

**Algorithm 2 — Skip Two Pages at a Time**
```
1. Open to page 1
2. If John Harvard is here → call him, done
3. Otherwise, turn 2 pages forward
4. If you went past the J section → go back one page
5. Go back to step 2
```
- Worst case: **~500 steps** (plus a small fix)
- Correct? ✅ Yes (with the fix)
- Faster? ✅ Twice as fast

**Algorithm 3 — Binary Search (divide and conquer)**
```
1. Open to the middle of the phone book
2. If John Harvard is on this page → call him, done
3. If John Harvard comes earlier in the alphabet → tear off the right half
4. If John Harvard comes later → tear off the left half
5. Go back to step 1 with the remaining half
6. If no pages remain → John Harvard is not in the book
```
- Worst case: **~10 steps** for a 1,000-page book!
- Correct? ✅ Yes
- Faster? ✅ Enormously faster

---

## 📊 Algorithm Efficiency

We measure algorithm efficiency by how **running time grows** as the input size (n) grows:

```
    Time
      │
  n   │  ╱  ← Algorithm 1: O(n) — linear
      │ ╱
 n/2  │╱   ← Algorithm 2: O(n/2) — still linear, just faster slope
      │
log n │‾‾‾ ← Algorithm 3: O(log n) — logarithmic (barely grows!)
      │
      └──────────────────── Input Size (n)
```

### Why Logarithmic is So Powerful
If a phone book **doubles** in size from 1,000 to 2,000 pages:
- Algorithm 1 takes **twice as long** (1,000 → 2,000 steps)
- Algorithm 2 takes **twice as long** (500 → 1,000 steps)
- Algorithm 3 takes only **one extra step** (10 → 11 steps)

This is the power of **divide and conquer** — taking huge bytes out of the problem at each step.

> 💡 This efficiency concept is called **Big O notation** (O(n), O(log n), O(n²), etc.) and is one of the most important ideas in computer science.

---

## 📝 Pseudocode

**Pseudocode** is a way of writing out an algorithm in plain English — precise enough to be unambiguous, but not tied to any specific programming language.

### Example — Binary Search in Pseudocode
```
1   Pick up phone book
2   Open to middle of phone book
3   Look at page
4   If person is on page
5       Call person
6   Else if person is earlier in book
7       Open to middle of left half of book
8       Go back to line 3
9   Else if person is later in book
10      Open to middle of right half of book
11      Go back to line 3
12  Else
13      Quit
```

### Key Ideas This Pseudocode Introduces

| Line(s) | Concept | Explanation |
|---------|---------|-------------|
| 1, 2, 3, 5 | **Functions** | Actions like "pick up", "open to", "look at", "call" |
| 4, 6, 9, 12 | **Conditionals** | Forks in the road: "if", "else if", "else" |
| 4, 6, 9 | **Boolean Expressions** | Yes/no questions: "is person on page?" |
| 8, 11 | **Loops** | "Go back to line 3" — repeating instructions |
| 12–13 | **Edge Cases** | What if the person isn't in the book at all? |

> ⚠️ The `else` on line 12 is critical. Without it, if John Harvard isn't in the book, the algorithm never terminates — it's an **infinite loop**. Every real-world bug where an app freezes or crashes often traces back to a missing case like this.

---

## 🏗️ Core Programming Concepts

These concepts appear in **every programming language** — Scratch, C, Python, JavaScript, and more:

### Functions
A **function** is a named action or verb that performs a specific piece of work.
```
say "Hello, world!"    ← 'say' is the function
                          "Hello, world!" is its input (argument)
```

### Arguments / Parameters
An **argument** (or parameter) is an **input** passed to a function to influence what it does.
```
say "Hello"     ← argument is "Hello"
say "Goodbye"   ← same function, different argument, different behavior
```

### Return Values
A **return value** is something a function hands back to the code — something only the program can see and use.
```
answer = ask "What's your name?"
↑                ↑
stored here      return value from this function
```

### Side Effects
A **side effect** is something visible or audible that happens as a result of calling a function — like a speech bubble appearing or a sound playing.
```
say "Hello"     → speech bubble appears on screen ← side effect
```

### Variables
A **variable** is a named container that stores a value. Like X or Y in math, but can hold text, numbers, or anything.
```
name = "David"     ← variable 'name' holds the value "David"
score = 0          ← variable 'score' holds the value 0
```

### Conditionals
A **conditional** is a fork in the road — the program asks a question and goes one way or another.
```
if touching mouse pointer?
    play sound meow
```

### Boolean Expressions
A **boolean expression** is a question with only two possible answers: **true** or **false** (yes/no, 1/0).
```
Is x < y?           ← boolean expression (true or false)
Is touching wall?   ← boolean expression (true or false)
```

### Loops
A **loop** causes instructions to repeat again and again.
```
repeat 3 times:
    play sound meow    ← runs exactly 3 times
```

---

## 🔼 Abstraction

**Abstraction** is one of the most powerful ideas in computer science. It means:

> **Hiding complexity behind a simpler interface so you don't need to think about it.**

### Layers of Abstraction in Computing
```
You (writing Python or Scratch)
        ↑
Python / Scratch (someone else built these)
        ↑
C (someone translated Python into this)
        ↑
Machine Code (zeros and ones)
        ↑
Transistors (actual hardware, electricity)
```

At each level, someone solved hard problems so the people above them don't have to. You use `print("Hello")` in Python without knowing how the screen's pixels are lit up. OpenAI's API lets you build a chatbot without understanding neural network math.

> 💡 CS50 itself is built on this principle — you'll use CS50's library functions as training wheels in early weeks, then remove them and build from scratch (no pun intended) later.

---

## 🐱 Scratch — The Language

**Scratch** is a visual, drag-and-drop programming language developed ~20 years ago at **MIT's Media Lab**. It represents all the same concepts as C and Python but with colorful, interlocking puzzle pieces instead of text.

### Why Start with Scratch?
- Forces you to focus on **ideas and logic**, not syntax
- All concepts (functions, loops, conditionals, variables) map 1:1 to real languages
- Visual and immediate — you see results instantly
- Gives you a mental model to fall back on when C's curly braces feel overwhelming

### Scratch vs. C vs. Python
The **same** "say hello world" program:

| Language | Code |
|----------|------|
| **Scratch** | `when 🚩 clicked` → `say [Hello, world!]` |
| **C** | `printf("Hello, world!\n");` |
| **Python** | `print("Hello, world!")` |

Same idea. Different syntax.

---

## 🖥️ Scratch Interface

```
┌─────────────────────────────────────────────────────────┐
│  BLOCKS PALETTE   │  SCRIPTING AREA    │    STAGE        │
│  (puzzle pieces)  │  (build here)      │  (cat lives     │
│                   │                    │   here)         │
│  Events           │                    │                 │
│  Control          │                    │  ┌───────────┐  │
│  Motion           │                    │  │           │  │
│  Looks            │                    │  │  🐱 Sprite│  │
│  Sound            │                    │  │           │  │
│  Sensing          │                    │  └───────────┘  │
│  Operators        │                    │  [🚩] [🛑]     │
│  Variables        │                    │                 │
└─────────────────────────────────────────────────────────┘
```

### Key Terms
| Term | Meaning |
|------|---------|
| **Sprite** | A character or object you can program (default is a cat) |
| **Stage** | The 2D world where sprites live (-240 to 240 on X, -180 to 180 on Y) |
| **Costume** | A different visual appearance for a sprite (used for animation) |
| **Script** | A connected stack of puzzle pieces = one program |
| **Green Flag 🚩** | Starts the program |
| **Stop Sign 🛑** | Stops the program |

---

## 🔧 Functions in Scratch

Scratch functions are called **blocks** and are color-coded by category:

| Color | Category | Examples |
|-------|----------|---------|
| 🟡 Yellow | **Events** | `when 🚩 clicked`, `when key pressed` |
| 🟠 Orange | **Control** | `repeat`, `forever`, `if/else`, `wait` |
| 🔵 Blue | **Motion** | `move 10 steps`, `go to x: y:` |
| 🟣 Purple | **Looks** | `say`, `switch costume` |
| 🟢 Green | **Sound** | `play sound`, `stop all sounds` |
| 🔵 Light Blue | **Sensing** | `touching mouse pointer?`, `ask and wait` |
| 🟢 Dark Green | **Operators** | `join`, `+`, `-`, `<`, `>` |
| 🟠 Dark | **Variables** | `set score to 0`, `change score by 1` |

### Hello World
```scratch
when 🚩 clicked
say [Hello, world!]
```

### Playing a Sound
```scratch
when 🚩 clicked
play sound [Meow] until done
```

---

## 📦 Variables in Scratch

Variables store values that can change over time.

### Creating & Using Variables
```scratch
when 🚩 clicked
set [score] to [0]         ← initialize variable to 0
change [score] by [1]      ← increment by 1
say (score)                ← display current value
```

### The `answer` Variable
When you use the **ask** block, Scratch automatically stores the user's response in a special variable called `answer`:
```scratch
when 🚩 clicked
ask [What's your name?] and wait
say (join [Hello, ] (answer))    ← joins "Hello, " + the user's name
```

---

## 🔀 Conditionals in Scratch

Conditionals let the program make decisions.

### Simple If
```scratch
if <touching [mouse-pointer]?>
    play sound [Meow] until done
```

### If / Else
```scratch
if <touching [Oscar]?>
    change [score] by [1]
    go to x: (pick random (-240) to (0)) y: (180)
else
    change y by (-1)
```

### Nested Conditionals
```scratch
if <key [up arrow] pressed?>
    change y by [1]
else if <key [down arrow] pressed?>
    change y by [-1]
else if <key [right arrow] pressed?>
    change x by [1]
else if <key [left arrow] pressed?>
    change x by [-1]
```

---

## 🔁 Loops in Scratch

### Repeat Loop (fixed number of times)
```scratch
repeat (3)
    play sound [Meow] until done
    wait (1) seconds
```

### Forever Loop (runs until stopped)
```scratch
forever
    if <touching [mouse-pointer]?>
        play sound [Meow] until done
```

### The Problem with Copy-Paste
❌ **Bad design:**
```scratch
play sound [Meow] until done
wait (2) seconds
play sound [Meow] until done
wait (2) seconds
play sound [Meow] until done
wait (2) seconds
```
If you want to change the wait time, you must change it in **3 places**. If you had 100 repetitions, this becomes unmanageable.

✅ **Good design:**
```scratch
repeat (3)
    play sound [Meow] until done
    wait (2) seconds
```
Change the wait time once, change it everywhere.

---

## 🧱 Custom Functions (Making a Block)

You can invent your own puzzle pieces — just like MIT invented all the built-in ones.

### Version 1 — No Input
```scratch
define meow
    play sound [Meow] until done
    wait (1) seconds

when 🚩 clicked
repeat (3)
    meow               ← using our custom block
```

### Version 2 — With Input (Argument)
```scratch
define meow (n times)
    repeat (n)
        play sound [Meow] until done
        wait (1) seconds

when 🚩 clicked
meow (3)               ← meow exactly 3 times
```

Now if you want the cat to meow 5 times instead of 3, you change just **one number**. The implementation details of "meowing" are **abstracted away** — out of sight, out of mind.

---

## ↩️ Return Values vs Side Effects

| | Return Value | Side Effect |
|--|-------------|------------|
| **What it is** | Data handed back to the program | Something visible/audible that happens |
| **Who sees it** | Only the code | The human |
| **Example** | `answer` from the ask block | Speech bubble from `say` block |
| **Analogy** | A function handing you a receipt | A function ringing a bell |

```scratch
ask [What's your name?] and wait   ← side effect: text box appears
                                      return value: user's typed name stored in 'answer'

say [Hello, world!]                 ← side effect: speech bubble appears
                                      no meaningful return value
```

---

## 🎮 Building a Real Scratch Project

### Approach: Baby Steps
When building something complex, don't try to do everything at once. Build incrementally:

1. **Start simple** — get one thing working (e.g., just display the sprite)
2. **Add movement** — make the sprite move
3. **Add interaction** — respond to keyboard/mouse
4. **Add logic** — scoring, collision detection
5. **Add polish** — sound, animation, multiple sprites

### Example: Oscar Time (CS50's Classic Demo)
Breaking down a full game into building blocks:

| Feature | How It's Built |
|---------|---------------|
| Animated trash can | Multiple **costumes** on a sprite, switched based on mouse proximity |
| Falling trash | Forever loop: change Y by -1 each frame |
| Random starting position | `go to x: (pick random 0 to 240) y: (180)` |
| "Collecting" trash | If touching Oscar → teleport back to top (same sprite reused!) |
| Score tracking | Variable `score`, incremented on collection |
| Music & timing | `wait (n) seconds` blocks carefully timed to match the song |

### IB's Hardest Game (Student Demo)
A student built a Harvard vs. Yale/MIT chase game using:
- **Motion** — arrow keys changing X and Y by pixels
- **Sensing** — touching wall detection → bounce back
- **Conditionals** — if touching left wall, move right; if touching right wall, move left
- **Loops** — forever running, always checking
- **Multiple sprites** — Harvard crest, Yale sprite (autonomous), MIT sprite (homing)
- **Point-towards** — MIT sprite always points toward Harvard and moves toward it

---

## 🏆 Code Quality

CS50 evaluates code on three axes — and so does the real world:

### ✅ Correctness
> Does the program do exactly what it's supposed to?

In CS50, `check50` tests your code automatically. But correctness alone isn't enough.

### 🎨 Design
> Is the program efficient? Is it well-structured? Does it avoid unnecessary repetition?

Design is more subjective — it's the difference between code that *works* and code that's *good*. Bad design examples:
- Asking unnecessary boolean questions (already know the answer)
- Copy-pasting code instead of using a loop or function
- Hard-coding values that should be in variables

### 💅 Style
> Is the code readable? Well-named variables? Proper indentation? Comments?

Style matters to **other humans** reading your code. It has no effect on the computer, but it has a huge effect on collaboration and maintainability.

### CS50 Tools

| Tool | Purpose |
|------|---------|
| `check50` | Automated correctness testing |
| `style50` | Checks formatting and style |
| **Design50** | AI-powered design feedback in VS Code |
| **CS50 Duck** | AI tutor for debugging and understanding |

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Binary** | Computers only use 0s and 1s; everything is electricity on or off |
| **Bits & Bytes** | 1 bit = one 0 or 1; 1 byte = 8 bits; 256 possible values per byte |
| **ASCII** | Numbers mapped to characters; 65=A, 66=B, 97=a, etc. |
| **Unicode** | Superset of ASCII supporting all languages + emoji (up to 32 bits) |
| **RGB** | Colors = (Red, Green, Blue) each 0–255; images = grids of colored pixels |
| **Algorithm** | Step-by-step instructions to solve a problem |
| **Efficiency** | O(n) linear vs O(log n) logarithmic — binary search is dramatically faster |
| **Pseudocode** | Human-readable algorithm description; not real code but captures logic |
| **Function** | A named action that performs work; takes inputs, may return outputs |
| **Variable** | A named container that stores a value |
| **Conditional** | A fork in the road based on a true/false question |
| **Loop** | Repeat instructions a fixed or indefinite number of times |
| **Abstraction** | Hide complexity; build on others' work without knowing every detail |
| **Scratch** | Visual language using drag-and-drop blocks; same ideas as C and Python |
| **Design** | Correct code isn't enough — it should also be well-designed and readable |

---

## 🗂️ Problem Set 0

Create your own interactive Scratch project that demonstrates at least:
- ✅ One **function** (custom or built-in)
- ✅ One **conditional** (if/else)
- ✅ One **loop** (repeat or forever)
- ✅ One **variable**

Details: [cs50.harvard.edu/x/2026/psets/0](https://cs50.harvard.edu/x/2026/psets/0/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | *(This is Week 0 — the beginning!)* |
| ➡️ Next | [Week 1 – C](Lecture%201%20-%20C) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |
