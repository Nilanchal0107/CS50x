# 📚 CS50x – Week 3: Algorithms
### Harvard University's Introduction to Searching, Sorting, and Recursion

> *"The smarter you are with your design, the more efficient your algorithms are going to be."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%203-green?style=flat-square)](https://cs50.harvard.edu/x/2026/weeks/3/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=6Svu_ae5ebk)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 3](https://www.youtube.com/watch?v=6Svu_ae5ebk) |
| 📝 Official Notes | [cs50.harvard.edu/x/2026/notes/3](https://cs50.harvard.edu/x/2026/notes/3/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 3 | [cs50.harvard.edu/x/2026/psets/3](https://cs50.harvard.edu/x/2026/psets/3/) |

---

## 📋 Table of Contents

1. [What is an Algorithm?](#-what-is-an-algorithm)
2. [The Attendance Demo — Three Algorithms](#-the-attendance-demo--three-algorithms)
3. [Arrays as Closed Lockers](#-arrays-as-closed-lockers)
4. [Linear Search](#-linear-search)
5. [Binary Search](#-binary-search)
6. [When NOT to Use Binary Search](#-when-not-to-use-binary-search)
7. [Running Time — Big O Notation](#-running-time--big-o-notation)
8. [Common Big O Running Times](#-common-big-o-running-times)
9. [Omega Notation — Lower Bounds](#-omega-notation--lower-bounds)
10. [Theta Notation](#-theta-notation)
11. [Asymptotic Notation Summary](#-asymptotic-notation-summary)
12. [Implementing Linear Search in C (Integers)](#-implementing-linear-search-in-c-integers)
13. [Implementing Linear Search in C (Strings)](#-implementing-linear-search-in-c-strings)
14. [strcmp — Comparing Strings](#-strcmp--comparing-strings)
15. [Building a Phone Book in C](#-building-a-phone-book-in-c)
16. [The Problem with Parallel Arrays](#-the-problem-with-parallel-arrays)
17. [Data Structures — typedef struct](#-data-structures--typedef-struct)
18. [Dot Notation — Accessing Struct Fields](#-dot-notation--accessing-struct-fields)
19. [Phone Book with Structs](#-phone-book-with-structs)
20. [Sorting — The Problem](#-sorting--the-problem)
21. [Selection Sort](#-selection-sort)
22. [Selection Sort — Pseudocode](#-selection-sort--pseudocode)
23. [Selection Sort — Running Time Analysis](#-selection-sort--running-time-analysis)
24. [Bubble Sort](#-bubble-sort)
25. [Bubble Sort — Pseudocode](#-bubble-sort--pseudocode)
26. [Bubble Sort — Running Time Analysis](#-bubble-sort--running-time-analysis)
27. [Optimizing Bubble Sort — Early Exit](#-optimizing-bubble-sort--early-exit)
28. [Recursion — What It Is](#-recursion--what-it-is)
29. [Base Cases and Recursive Cases](#-base-cases-and-recursive-cases)
30. [Recursion — Searching a Phone Book](#-recursion--searching-a-phone-book)
31. [Recursion — Mario's Pyramid](#-recursion--marios-pyramid)
32. [Iterative vs Recursive Draw Function](#-iterative-vs-recursive-draw-function)
33. [Stack Overflow — The Danger of Recursion](#-stack-overflow--the-danger-of-recursion)
34. [Merge Sort](#-merge-sort)
35. [Merge Sort — How Merging Works](#-merge-sort--how-merging-works)
36. [Merge Sort — Pseudocode](#-merge-sort--pseudocode)
37. [Merge Sort — Running Time Analysis](#-merge-sort--running-time-analysis)
38. [Sorting Algorithms Compared](#-sorting-algorithms-compared)
39. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🧠 What is an Algorithm?

An **algorithm** is a set of step-by-step instructions for solving a problem.

In the real world:
- **Sorting** means putting data in order (smallest to largest, alphabetically, etc.)
- **Searching** means finding a specific piece of data among a larger collection

The key insight of Week 3 is that there are often **many different algorithms** for solving the same problem — some much faster than others — and choosing the right one is a core skill in computer science.

---

## 🙋 The Attendance Demo — Three Algorithms

Week 3 opens with a live classroom demo to illustrate different algorithm efficiencies:

### Algorithm 1: Count One at a Time
Count people by going 1, 2, 3, 4, 5... one person at a time.

**Characteristic:** For every additional person in the room, one more step is needed. This is **linear** — a straight line on a graph.

### Algorithm 2: Count by Twos
Go 2, 4, 6, 8, 10... two at a time.

**Characteristic:** Still linear, but twice as fast. The graph is still a straight line, just with a steeper slope. It takes the same shape — both grow linearly with the number of people.

### Algorithm 3: Divide and Conquer (Everyone Pairs Up)
Everyone starts with the number 1 and repeatedly pairs up, adding their numbers together. Half the people sit down each round.

**Characteristic:** If you double the room size, you only need **one more step**. This grows **logarithmically** — the curve flattens dramatically as the room gets larger. This was the same idea as the phone book in Week 0.

### Why This Matters
```
Algorithm 1:  O(n)       ← linear, slow
Algorithm 2:  O(n/2)     ← still linear, just faster slope
Algorithm 3:  O(log n)   ← logarithmic, dramatically faster for large n
```

As problems get bigger — millions, billions of items — the difference between linear and logarithmic is the difference between possible and impossible.

---

## 🚪 Arrays as Closed Lockers

A crucial mental model for understanding search algorithms:

**A computer cannot see an entire array at once.** Just like a hallway of closed lockers, the computer must go to each location, open it, look at the value, then close it before moving on.

```
┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐ ┌───┐
│ ? │ │ ? │ │ ? │ │ ? │ │ ? │ │ ? │ │ ? │
└───┘ └───┘ └───┘ └───┘ └───┘ └───┘ └───┘
  0     1     2     3     4     5     6
```

- Each box can only be viewed **one at a time**
- Viewing a value requires going to that specific location
- The computer cannot have a "bird's eye view" and see all values simultaneously
- This is why algorithms that minimize the number of locations visited are valuable
- Locations are 0-indexed: 7 lockers = locations 0 through 6

---

## 🔍 Linear Search

**Linear search** checks each element one at a time, from left to right, until the target is found or all elements have been checked.

### Pseudocode
```
For each door from left to right:
    If 50 is behind the door:
        Return true
Return false
```

### More Formal Pseudocode
```
For i from 0 to n-1:
    If 50 is behind doors[i]:
        Return true
Return false
```

### Key Design Point — The Dangling Return False
```c
// ❌ WRONG — else immediately returns false if first door isn't 50
for (int i = 0; i < n; i++)
{
    if (doors[i] == 50)
        return true;
    else
        return false;   // ← exits after just 1 check!
}

// ✅ CORRECT — only return false after checking ALL doors
for (int i = 0; i < n; i++)
{
    if (doors[i] == 50)
        return true;
}
return false;           // ← only reached if 50 was never found
```

When you `return` inside a function, execution **stops immediately**. An `else return false` after checking just the first door would wrongly declare the number absent after a single check.

### Running Time
| Bound | Notation | Reason |
|-------|----------|--------|
| Upper (worst case) | O(n) | Number might be at the very end |
| Lower (best case) | Ω(1) | Number might be at the very beginning |

---

## 🎯 Binary Search

**Binary search** finds a target in a **sorted** array by repeatedly halving the search space.

### Strategy
1. Look at the **middle** element
2. If it's the target → done!
3. If target < middle → search the **left half**
4. If target > middle → search the **right half**
5. Repeat until found or no elements remain

### How to Find the Middle
If there are 7 doors (indices 0–6): `7 / 2 = 3.5` → round down → **index 3** is the middle.

### Pseudocode
```
If no doors left:
    Return false
If 50 is behind doors[middle]:
    Return true
Else if 50 < doors[middle]:
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]:
    Search doors[middle + 1] through doors[n - 1]
```

### Why `middle - 1` and `middle + 1`?
You already checked the middle door. Including it again in the next search wastes a step — that's why you search *up to but not including* the middle in each half.

### Requirement: Data Must Be Sorted
Binary search makes decisions based on whether the target is less than or greater than the middle value. On an **unsorted array**, these comparisons are meaningless — the algorithm will make wrong turns and likely miss the target entirely.

### Running Time
| Bound | Notation | Reason |
|-------|----------|--------|
| Upper (worst case) | O(log n) | Halves the problem with every step |
| Lower (best case) | Ω(1) | Target could be exactly in the middle |

---

## ⚠️ When NOT to Use Binary Search

Binary search requires sorted data. Sorting takes time. So the decision of whether to sort + binary search vs. just linear search depends on context:

**Use linear search when:**
- You only need to search the data **once** — sorting first would cost more time than it saves
- Data is unsorted and sorting it would take longer than a single linear scan

**Use binary search when:**
- You need to search the same data **many times** — the sorting cost is *amortized* (spread) across many fast searches
- Data arrives already sorted (e.g., a dictionary, alphabetical list)

Google sorts and indexes data because billions of people search it repeatedly — the upfront sort cost is justified many times over.

---

## 📊 Running Time — Big O Notation

**Big O notation** describes how the running time of an algorithm grows as the input size `n` grows. It focuses on the **upper bound** — how bad can it get?

### The Core Idea
Computer scientists don't care about exact step counts. They care about **the shape of growth** as `n` gets large. Lower-order terms and constant multipliers are dropped:

| Exact Formula | Big O Simplified | Why |
|---------------|-----------------|-----|
| n steps | O(n) | dominant term is n |
| n/2 steps | O(n) | same linear shape, constant doesn't matter |
| log₂(n) steps | O(log n) | base of logarithm doesn't matter |
| n² - 2n + 1 | O(n²) | n² dominates as n grows large |

### Why Ignore Lower-Order Terms?
Imagine zooming out on a graph until the x-axis goes from 0 to a billion. At that scale:
- `n` and `n/2` look practically the same (both straight lines)
- `n²` is visually incomparable to either
- `log n` barely grows at all

The dominant term tells you everything that matters at scale.

### Big O Graph (Conceptual)
```
Steps
│        /  ← O(n²)
│      /
│    /
│  / _______ ← O(n)
│ /
│/__________ ← O(log n)
└─────────────── n (problem size)
```

---

## 📋 Common Big O Running Times

From fastest to slowest:

| Notation | Name | Description |
|----------|------|-------------|
| O(1) | Constant | Same number of steps regardless of input size |
| O(log n) | Logarithmic | Halves the problem each step (binary search) |
| O(n) | Linear | One step per element (linear search) |
| O(n log n) | Linearithmic | Slightly worse than linear (merge sort) |
| O(n²) | Quadratic | Nested loops; each element compared to all others |

> 💡 As `n` gets very large: O(1) < O(log n) < O(n) < O(n log n) < O(n²)

---

## 🔽 Omega Notation — Lower Bounds

**Big Omega (Ω)** is the opposite of Big O — it describes the **lower bound** (best case) of an algorithm's running time.

| Algorithm | Ω (Best Case) | Reason |
|-----------|---------------|--------|
| Linear Search | Ω(1) | Target could be the very first element |
| Binary Search | Ω(1) | Target could be exactly in the middle |
| Selection Sort | Ω(n²) | Always scans the whole unsorted portion |
| Bubble Sort | Ω(n) | One pass to confirm already sorted (with optimization) |
| Merge Sort | Ω(n log n) | Always divides and merges |

Together, Big O and Omega give you the **range** of performance — from best case to worst case.

---

## 🎯 Theta Notation

**Big Theta (Θ)** is used when an algorithm's Big O and Omega are **the same value**. It expresses both the upper and lower bounds in a single notation, meaning the algorithm always performs at that level regardless of input.

```
If Big O = Ω, then we can say Θ
```

| Algorithm | Θ notation | Meaning |
|-----------|-----------|---------|
| Selection Sort | Θ(n²) | Always n² steps — even if sorted |
| Merge Sort | Θ(n log n) | Always n log n steps |
| Linear Search | ✗ — cannot use Θ | O(n) but Ω(1) |
| Binary Search | ✗ — cannot use Θ | O(log n) but Ω(1) |

> 💡 Theta is the most precise notation. If you can say Θ, that tells a colleague both bounds at once.

---

## 📐 Asymptotic Notation Summary

All three notations (O, Ω, Θ) are examples of **asymptotic notation** — they describe behavior as `n` approaches infinity (grows without bound).

| Symbol | Name | Describes | Analogy |
|--------|------|-----------|---------|
| O | Big O | Upper bound (worst case) | "At most this slow" |
| Ω | Big Omega | Lower bound (best case) | "At least this fast" |
| Θ | Big Theta | Tight bound (both) | "Exactly this fast, always" |

---

## 💻 Implementing Linear Search in C (Integers)

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize array of integers (no need to specify size — compiler counts)
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Ask the user what to search for
    int n = get_int("Number: ");

    // Linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;   // success
        }
    }

    printf("Not found\n");
    return 1;   // error — not found
}
```

### Notes
- The array is initialized with `{}` curly brace syntax — the compiler counts the 7 elements automatically
- `return 0` inside the loop stops execution immediately upon finding the number
- `return 1` at the end is only reached if the number was never found
- Comparing integers with `==` works perfectly fine in C

---

## 💻 Implementing Linear Search in C (Strings)

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>   // needed for strcmp

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)   // 0 means equal
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
```

### Why Can't You Use `==` for Strings?
`==` on strings compares **memory addresses**, not the characters themselves. Since two different string variables live at different locations in memory, `==` would always return false even if the words are identical.

To compare strings character-by-character, you must use `strcmp` from `string.h`.

---

## 🔤 strcmp — Comparing Strings

`strcmp` (string compare) is a function in `string.h` that compares two strings **character by character** using their ASCII values.

```c
#include <string.h>
int result = strcmp(string1, string2);
```

### Return Values
| Return Value | Meaning |
|--------------|---------|
| `0` | Strings are **equal** |
| `< 0` (negative) | `string1` comes **before** `string2` alphabetically (ASCIIbetically) |
| `> 0` (positive) | `string1` comes **after** `string2` alphabetically |

### Why Return Three Values?
`strcmp` returns more than just true/false because the same function can be used not just for **equality** (is this the one I want?) but also for **ordering** (which comes first alphabetically?). This is useful for sorting strings.

```c
// Check equality only
if (strcmp(a, b) == 0)
    printf("Same!\n");

// Check ordering
if (strcmp(a, b) < 0)
    printf("a comes before b\n");
else if (strcmp(a, b) > 0)
    printf("b comes before a\n");
```

> ⚠️ Don't forget `#include <string.h>` — without it, the compiler won't know what `strcmp` is.

---

## 📞 Building a Phone Book in C

Combining two arrays — one for names, one for numbers — to simulate a phone book:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[]   = {"Kelly", "David", "John Harvard"};
    string numbers[] = {"+1-617-495-1000",
                        "+1-617-495-1000",
                        "+1-949-468-2750"};

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
```

### Why Are Phone Numbers Stored as Strings (Not Integers)?
Phone numbers contain non-digit characters like `+`, `-`, and `(`. These cannot be stored in an `int` or `long`. Additionally, a leading zero (common in some countries for local calls) has no mathematical meaning in an integer and would be silently dropped. Storing phone numbers as strings preserves them exactly as written.

---

## ❌ The Problem with Parallel Arrays

The phone book above uses two **parallel arrays** — `names[i]` and `numbers[i]` are paired based solely on their shared index `i`.

### What's Wrong With This?

- You are **trusting yourself** to keep both arrays perfectly synchronized — same length, same order
- If you accidentally swap two entries in one array but not the other, you'll get wrong numbers silently
- As the dataset grows (30 people, 300, 3 million), this "honor system" approach becomes a maintenance nightmare
- There is no programmatic guarantee that `names[i]` and `numbers[i]` belong together

What we really want is a way to say: *"These two pieces of data belong to the same person."* C gives us a mechanism for this — custom data types called **structs**.

---

## 🏗️ Data Structures — typedef struct

A **struct** (structure) is a custom data type that lets you bundle related data of different types together under one name.

### Syntax
```c
typedef struct
{
    string name;
    string number;
}
person;
```

This tells C: *"Create a new data type called `person`. Every `person` has a `string` called `name` and a `string` called `number`."*

### Breakdown
| Part | Meaning |
|------|---------|
| `typedef` | Define a new type name |
| `struct` | A data structure containing multiple fields |
| `{ ... }` | The fields (members) inside the struct |
| `string name;` | A field called `name` of type `string` |
| `string number;` | A field called `number` of type `string` |
| `person` | The name of this new data type |

### Where to Put It
Place `typedef struct` **above `main`** (and above any function that uses it) so that both `main` and any helper functions can access the type:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // now "person" is a usable type
}
```

### Using Your New Type
```c
person p;                          // declare a variable of type person
p.name = "David";                  // assign a value to the name field
p.number = "+1-617-495-1000";      // assign a value to the number field
printf("%s\n", p.name);            // access the name field
```

---

## 🔵 Dot Notation — Accessing Struct Fields

Use a **dot** `.` to access a field inside a struct:

```c
variable_name.field_name
```

```c
person p;
p.name = "Kelly";          // set the name field
p.number = "+1 617";       // set the number field

printf("%s\n", p.name);    // print the name field → Kelly
printf("%s\n", p.number);  // print the number field
```

This is analogous to how you might say "the person's name" or "the person's number" in English — the dot connects the container to the specific piece of data inside it.

---

## 📒 Phone Book with Structs

Rewriting the phone book using a `person` struct to eliminate parallel arrays:

```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[3];

    people[0].name   = "Kelly";
    people[0].number = "+1-617-495-1000";

    people[1].name   = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name   = "John Harvard";
    people[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
```

### What Changed and Why It's Better
| Old Approach | New Approach |
|--------------|-------------|
| `names[i]` and `numbers[i]` linked only by shared index | `people[i].name` and `people[i].number` are physically inside the same object |
| Programmer must manually keep two arrays in sync | Impossible for name and number to get out of sync — they're one unit |
| Bad design at scale | Good design at any scale |

> 💡 This concept — grouping related data together — is called **encapsulation**. The curly braces of the struct "hug" the related fields together, both in the code and in the computer's memory.

---

## 🔀 Sorting — The Problem

Searching efficiently with binary search requires **sorted data**. So the question becomes: how do we sort data efficiently?

**Input:** an unsorted array of numbers (e.g., `7 2 5 4 1 6 0 3`)
**Output:** a sorted array (e.g., `0 1 2 3 4 5 6 7`)

We'll explore three sorting algorithms:
1. **Selection Sort** — find the minimum each pass
2. **Bubble Sort** — compare adjacent pairs repeatedly
3. **Merge Sort** — divide, sort recursively, then merge

---

## 🎯 Selection Sort

**Selection sort** works by repeatedly finding the **smallest remaining element** and moving it to its correct position.

### The Idea
On each pass through the array:
1. Find the **smallest element** in the unsorted portion
2. **Swap** it with the first element of the unsorted portion
3. The sorted portion grows by one; the unsorted portion shrinks by one
4. Repeat until fully sorted

### Visualization
```
Start:   7  2  5  4  1  6  0  3
Pass 1:  [0] 2  5  4  1  6  7  3   ← 0 was smallest; swapped with 7
Pass 2:  [0  1] 5  4  2  6  7  3   ← 1 was smallest; swapped with 2
Pass 3:  [0  1  2] 4  5  6  7  3   ← 2 was smallest; swapped with 5
Pass 4:  [0  1  2  3] 5  6  7  4   ← 3 was smallest; swapped with 4
Pass 5:  [0  1  2  3  4] 6  7  5   ← 4 was smallest; swapped with 5
Pass 6:  [0  1  2  3  4  5] 7  6   ← 5 was smallest; swapped with 6
Pass 7:  [0  1  2  3  4  5  6] 7   ← 6 was smallest; swapped with 7
Done:    [0  1  2  3  4  5  6  7]

[ ] = sorted portion
```

---

## 📝 Selection Sort — Pseudocode

```
For i from 0 to n-1:
    Find the smallest number between numbers[i] and numbers[n-1]
    Swap that smallest number with numbers[i]
```

### How It Maps to the Demo
- `i = 0` → scan positions 0 through n-1; find the global minimum; swap with position 0
- `i = 1` → scan positions 1 through n-1; find the next minimum; swap with position 1
- `i = 2` → scan positions 2 through n-1; and so on...

The left boundary of the scan advances each pass; the right boundary stays at `n-1`.

---

## ⏱️ Selection Sort — Running Time Analysis

### Step Count
| Pass | Comparisons Made |
|------|-----------------|
| 1st | n - 1 |
| 2nd | n - 2 |
| 3rd | n - 3 |
| ... | ... |
| Last | 1 |

**Total comparisons:** (n-1) + (n-2) + ... + 1 = **n(n-1)/2**

Expanding: `n²/2 - n/2`

Applying Big O (drop lower-order terms and constants): **O(n²)**

### Critical Flaw
Even if the array is **already sorted**, selection sort makes no allowance for this. It still scans the full unsorted portion on every pass, doing the same n² comparisons for zero benefit.

| Notation | Value | Reason |
|----------|-------|--------|
| O (worst case) | O(n²) | Always scans everything |
| Ω (best case) | Ω(n²) | No early exit — same work regardless |
| **Θ (tight bound)** | **Θ(n²)** | Upper and lower bounds are the same |

> ⚠️ Selection sort is in Θ(n²) — always slow, no exceptions.

---

## 🫧 Bubble Sort

**Bubble sort** repeatedly compares **adjacent pairs** of elements and swaps them if they're out of order. With each full pass, the largest unsorted element "bubbles" to its correct position at the end.

### The Idea
Walk through the array from left to right. Whenever two neighboring elements are in the wrong order, swap them. After each full pass, the largest remaining unsorted element has settled at the end. Repeat until no swaps are needed.

### Visualization
```
Start:   7  2  5  4  1  6  0  3

Pass 1 (comparing pairs):
  7,2 → swap  →  2  7  5  4  1  6  0  3
  7,5 → swap  →  2  5  7  4  1  6  0  3
  7,4 → swap  →  2  5  4  7  1  6  0  3
  7,1 → swap  →  2  5  4  1  7  6  0  3
  7,6 → swap  →  2  5  4  1  6  7  0  3
  7,0 → swap  →  2  5  4  1  6  0  7  3
  7,3 → swap  →  2  5  4  1  6  0  3  [7]   ← 7 is now in place

Pass 2: same process, now [6] settles at position 6
...
(continues until all are sorted)
```

---

## 📝 Bubble Sort — Pseudocode

```
Repeat n-1 times:
    For i from 0 to n-2:
        If numbers[i] and numbers[i+1] are out of order:
            Swap them
```

### Why `n-2` Instead of `n-1`?
The inner loop compares `numbers[i]` and `numbers[i+1]`. If `i` went up to `n-1` (the last element), then `i+1` would be `n` — **beyond the array's boundary**. That's an out-of-bounds access, which is a serious bug in C. The loop stops at `n-2` so the right-hand comparison always points at a valid element.

### Why `n-1` Outer Passes?
With `n` elements, you get the last element "for free" — once the other `n-1` elements are in place, the remaining one must be correct. So you only need `n-1` passes.

---

## ⏱️ Bubble Sort — Running Time Analysis

| Component | Steps |
|-----------|-------|
| Outer loop | n - 1 times |
| Inner loop | n - 1 steps each time |
| **Total** | (n-1) × (n-1) = n² - 2n + 1 |

Big O: drop lower-order terms → **O(n²)** — same as selection sort in the worst case.

| Notation | Value | Reason |
|----------|-------|--------|
| O (worst case) | O(n²) | n passes × n comparisons each |
| Ω (best case, basic) | Ω(n²) | Still repeats n times even if already sorted |

---

## ✅ Optimizing Bubble Sort — Early Exit

Unlike selection sort, bubble sort can be improved with a simple optimization: **stop early if no swaps were made** during a full pass.

If you walk through the entire array and make zero swaps, the array is already sorted — no point doing any more passes.

### Optimized Pseudocode
```
Repeat n-1 times:
    For i from 0 to n-2:
        If numbers[i] and numbers[i+1] are out of order:
            Swap them
    If no swaps were made this pass:
        Quit   ← EARLY EXIT
```

### Impact on Lower Bound
With this optimization, if the array is already sorted, bubble sort only needs **one pass** to confirm it (seeing 0 swaps), then quits.

That one pass looks at n elements: **Ω(n)**

| Notation | Optimized Value | Reason |
|----------|----------------|--------|
| O (worst case) | O(n²) | Still n² in worst case |
| **Ω (best case)** | **Ω(n)** | Only one pass needed if already sorted |

Since O ≠ Ω, we cannot use Θ notation for optimized bubble sort.

---

## 🔄 Recursion — What It Is

**Recursion** is a programming technique where a function **calls itself** in its own definition to solve a problem by breaking it into smaller instances of the same problem.

### Mathematical Definition
A recursive function is one defined in terms of itself:
```
f(n) = f(something smaller)
```

### In Code
```c
void countdown(int n)
{
    if (n == 0)
    {
        printf("Blastoff!\n");
        return;                   // ← base case: stop here
    }
    printf("%i\n", n);
    countdown(n - 1);             // ← recursive case: call yourself with smaller input
}
```

### Why It Doesn't Loop Forever
The key: each recursive call is given a **smaller version of the problem**. Eventually you reach the smallest possible problem (the base case), at which point you stop calling yourself and begin returning.

```
countdown(3)
  → prints 3
  → calls countdown(2)
      → prints 2
      → calls countdown(1)
          → prints 1
          → calls countdown(0)
              → prints "Blastoff!"
              → returns   (base case hit)
          → returns
      → returns
  → returns
```

If you called yourself with the **same** or a **larger** input, you'd get an infinite loop (and eventually crash).

---

## 🔑 Base Cases and Recursive Cases

Every recursive function must have both:

### Base Case
A condition that is answered **immediately** without any further recursion. It's the "stopping condition."

```c
if (n <= 0)
{
    return;   // ← base case: nothing to do
}
```

### Recursive Case
The part that **calls itself** with a smaller version of the problem:

```c
draw(n - 1);   // ← recursive case: solve a smaller version first
```

### The Template
```c
void solve(int n)
{
    // Base case — simplest possible input
    if (n <= 0)
    {
        return;
    }

    // Recursive case — break the problem down
    solve(n - 1);

    // Do some work at this level
    do_something(n);
}
```

---

## 📖 Recursion — Searching a Phone Book

Binary search is inherently recursive. The pseudocode from earlier can be rewritten to make this explicit:

### Procedural (Loop-Based) Version
```
Pick up phone book
Open to the middle
Look at names
If John Harvard is found → call him
Else if John Harvard is earlier in book → open to middle of left half → go back
Else if John Harvard is later in book → open to middle of right half → go back
```

### Recursive Version
```
If no pages left:
    Return false
If John Harvard is at middle page:
    Return true
Else if John Harvard is earlier:
    Search left half of book    ← recursive call on smaller problem
Else:
    Search right half of book   ← recursive call on smaller problem
```

The phrases "search left half" and "search right half" are recursive calls — they invoke the same algorithm with a smaller subset of the data. They work because each call receives half the pages of the previous call, and eventually you either find the name or run out of pages (base case).

---

## 🧱 Recursion — Mario's Pyramid

A pyramid of height 4 can be defined recursively:

```
Pyramid of height 4 = Pyramid of height 3 + one more row
Pyramid of height 3 = Pyramid of height 2 + one more row
Pyramid of height 2 = Pyramid of height 1 + one more row
Pyramid of height 1 = a single brick   ← base case
```

This maps naturally to a recursive function in C.

> 💡 Google "recursion" — it asks "Did you mean: recursion?" If you click it, you get the same page again. Classic computer science humor.

---

## 🔁 Iterative vs Recursive Draw Function

### Iterative Version (Using Loops)
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)         // for each row
    {
        for (int j = 0; j < i + 1; j++) // print that row's bricks
        {
            printf("#");
        }
        printf("\n");
    }
}
```

Output for height 4:
```
#
##
###
####
```

### Recursive Version
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // Base case — nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Recursive case — draw a pyramid of height n-1 first
    draw(n - 1);

    // Then add the current row (n bricks)
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
```

### How the Recursive Version Works
```
draw(4)
  → draw(3)
      → draw(2)
          → draw(1)
              → draw(0) → returns (base case)
              → prints "#\n"
          → prints "##\n"
      → prints "###\n"
  → prints "####\n"
```

Each call to `draw` first recursively builds the smaller pyramid above, then adds its own row at the bottom. This is how the rows end up in the right order (smallest at top, largest at bottom).

### Key Differences
| Approach | Mechanism | Code Style |
|----------|-----------|------------|
| Iterative | Loops | Explicit, step-by-step |
| Recursive | Function calls itself | Elegant, self-referential |
| Both produce identical output | | |

---

## 💥 Stack Overflow — The Danger of Recursion

If you pass a very large number to the recursive draw function:

```bash
./recursion
Height: 000000000000
```

You may see a **Segmentation fault** or similar crash. This is a **stack overflow**.

### Why It Happens
Each function call uses a small amount of memory in a region called the **stack**. Each recursive call to `draw` adds another frame to the stack. If you recurse thousands of times, you exhaust the stack's memory.

### Contrast with the Iterative Version
The iterative version with nested loops uses only a fixed, constant amount of memory regardless of input — it doesn't add new stack frames.

### The Trade-Off
| Version | Memory Usage | Code Elegance |
|---------|-------------|---------------|
| Iterative | O(1) — constant | More verbose |
| Recursive | O(n) — grows with depth | More elegant |

Recursion is powerful and elegant, but comes with a memory cost. For very deep recursions (very large inputs), the iterative version is safer.

---

## 🔀 Merge Sort

**Merge sort** is a recursive sorting algorithm that is dramatically faster than selection sort and bubble sort. It works by dividing the array in half, sorting each half, then merging them back together.

### The Key Insight — Merging Two Sorted Lists is Easy
If you have two **already-sorted** lists, you can combine them into one sorted list efficiently:
- Point to the beginning of both lists simultaneously
- Always take whichever pointer is pointing to the smaller value
- Move that pointer forward
- Repeat until both lists are exhausted

At no point do you go back. Each element is touched exactly once → **N steps total** to merge.

### Merging Example
```
Left (sorted):   1  3  4  6
Right (sorted):  0  2  5  7

Step 1: left=1, right=0 → take 0  → result: 0
Step 2: left=1, right=2 → take 1  → result: 0 1
Step 3: left=3, right=2 → take 2  → result: 0 1 2
Step 4: left=3, right=5 → take 3  → result: 0 1 2 3
Step 5: left=4, right=5 → take 4  → result: 0 1 2 3 4
Step 6: left=6, right=5 → take 5  → result: 0 1 2 3 4 5
Step 7: left=6, right=7 → take 6  → result: 0 1 2 3 4 5 6
Step 8: left=done, right=7 → take 7 → result: 0 1 2 3 4 5 6 7
```

8 elements, 8 steps — exactly N steps. And crucially, no element is compared more than once.

---

## 📝 Merge Sort — Pseudocode

```
If only 1 number:
    Quit (already sorted — base case)

Sort the left half of the numbers
Sort the right half of the numbers
Merge the sorted halves
```

The magic: "Sort the left half" and "Sort the right half" are **recursive calls** to the same algorithm. Each call receives half the data, until you reach lists of size 1 (trivially sorted).

### Full Trace for 8 Numbers (6 3 4 1 5 2 7 0)
```
Level 0 (original):  6  3  4  1  5  2  7  0
Level 1 (split):     6  3  4  1  |  5  2  7  0
Level 2 (split):     6  3  |  4  1  |  5  2  |  7  0
Level 3 (split):     6|3  |  4|1  |  5|2  |  7|0   ← all single elements
Level 3 (merge):     3  6  |  1  4  |  2  5  |  0  7
Level 2 (merge):     1  3  4  6  |  0  2  5  7
Level 1 (merge):     0  1  2  3  4  5  6  7   ← done!
```

3 levels of splitting + 3 levels of merging = the log₂(8) = 3 "rounds"

---

## ⏱️ Merge Sort — Running Time Analysis

### The Math
- For `n = 8` elements, there are **3 levels** of work (log₂(8) = 3)
- On each level, **n total elements** are touched during merging
- Total work = **n × log n**

### General Formula
```
Total steps = (number of levels) × (steps per level)
            = log n              × n
            = n log n
```

### Running Time
| Notation | Value | Reason |
|----------|-------|--------|
| O (worst case) | O(n log n) | Always divides and merges |
| Ω (best case) | Ω(n log n) | Same process regardless of input order |
| **Θ (tight bound)** | **Θ(n log n)** | Upper and lower bounds are equal |

### Trade-Off
Merge sort uses **twice as much memory** as the other algorithms. When merging two halves, you need extra space to hold the merged result while building it. The sorted output is written to a temporary region before being placed back.

---

## 📊 Sorting Algorithms Compared

| Algorithm | O (Worst) | Ω (Best) | Θ (Tight) | Space | Notes |
|-----------|-----------|----------|-----------|-------|-------|
| Selection Sort | O(n²) | Ω(n²) | Θ(n²) | O(1) | Always scans full unsorted portion |
| Bubble Sort (basic) | O(n²) | Ω(n²) | Θ(n²) | O(1) | No early exit |
| Bubble Sort (optimized) | O(n²) | Ω(n) | — | O(1) | Stops if no swaps made |
| Merge Sort | O(n log n) | Ω(n log n) | Θ(n log n) | O(n) | Needs extra memory |

### The Key Comparison
```
n² vs n log n for large n:

n = 1,000:
  n²      = 1,000,000 steps
  n log n = ~10,000 steps   ← 100x faster!

n = 1,000,000:
  n²      = 1,000,000,000,000 steps
  n log n = ~20,000,000 steps   ← 50,000x faster!
```

Merge sort's advantage over selection/bubble sort becomes **more dramatic** the larger the dataset.

### Visual Summary
```
Steps
│                          /  O(n²) — selection/bubble sort
│                        /
│                      /
│     O(n log n) ____/        ← merge sort
│    O(n) ______/
│   O(log n) /
│  O(1) ────
└─────────────────────── n
```

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Algorithm** | Step-by-step instructions for solving a problem |
| **Linear search** | Check each element left to right; O(n) worst, Ω(1) best |
| **Binary search** | Check middle, eliminate half; O(log n) worst, Ω(1) best — requires sorted data |
| **Sorted requirement** | Binary search only works correctly on sorted data |
| **Big O (O)** | Upper bound — worst case running time |
| **Omega (Ω)** | Lower bound — best case running time |
| **Theta (Θ)** | Tight bound — when O and Ω are equal |
| **O(1)** | Constant time — same steps regardless of input size |
| **O(log n)** | Logarithmic — problem halved each step |
| **O(n)** | Linear — one step per element |
| **O(n log n)** | Linearithmic — slightly worse than linear (merge sort) |
| **O(n²)** | Quadratic — nested loops over the data |
| **Parallel arrays** | Bad design — two arrays linked only by shared index; fragile |
| **typedef struct** | Defines a custom data type bundling related fields together |
| **Dot notation** | `person.name` accesses the `name` field of a `person` struct |
| **Encapsulation** | Keeping related data together in one struct; reduces errors |
| **strcmp** | Compares two strings; returns 0 if equal, neg if s1 < s2, pos if s1 > s2 |
| **Selection sort** | Find the minimum each pass; swap into place; Θ(n²) always |
| **Bubble sort** | Compare adjacent pairs; swap if out of order; O(n²), Ω(n) optimized |
| **Bubble sort optimization** | If no swaps in a full pass, the array is sorted — quit early |
| **Recursion** | A function that calls itself with a smaller version of the problem |
| **Base case** | The simplest input — answered immediately, no recursion needed |
| **Recursive case** | The general input — calls itself with a smaller problem |
| **Stack overflow** | Crash caused by too many nested recursive calls exhausting memory |
| **Merge sort** | Divide in half, sort each half recursively, merge; Θ(n log n) |
| **Merging** | Combining two sorted lists into one takes O(n) steps |
| **Merge sort trade-off** | Faster time (n log n vs n²) but uses twice the memory |
| **n log n vs n²** | At large scales, merge sort can be thousands of times faster |

---

## 🗂️ Problem Set 3

Apply searching, sorting, and algorithmic thinking to real problems:
[cs50.harvard.edu/x/2026/psets/3](https://cs50.harvard.edu/x/2026/psets/3/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 2 – Arrays](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%202%20-%20Arrays) |
| ➡️ Next | Week 4 – Memory *(coming soon)* |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 3 - Algorithms`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%203%20-%20Algorithms)
