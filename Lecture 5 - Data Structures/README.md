# 🏗️ CS50x – Week 5: Data Structures
### Harvard University's Introduction to Linked Lists, Trees, Hash Tables, and Tries

> *"This is our last week on C — and among the goals is to demonstrate that there are a bunch of ways in which we can implement data types. Using data structures, you can implement stacks and queues and dictionaries and all of these other things."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Lecture](https://img.shields.io/badge/Lecture-Week%205-green?style=flat-square)](https://cs50.harvard.edu/x/weeks/5/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=PmAI76OGE_E)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 5](https://www.youtube.com/watch?v=PmAI76OGE_E) |
| 📝 Official Notes | [cs50.harvard.edu/x/notes/5](https://cs50.harvard.edu/x/notes/5/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 5 | [cs50.harvard.edu/x/2026/psets/5](https://cs50.harvard.edu/x/2026/psets/5/) |

---

## 📋 Table of Contents

1. [Abstract Data Types](#-abstract-data-types)
2. [Queues — FIFO](#-queues--fifo)
3. [Stacks — LIFO](#-stacks--lifo)
4. [Dictionaries](#-dictionaries)
5. [Arrays — Revisited](#-arrays--revisited)
6. [Dynamic Memory with malloc and realloc](#-dynamic-memory-with-malloc-and-realloc)
7. [Linked Lists — The Concept](#-linked-lists--the-concept)
8. [Linked Lists — The Node Structure](#-linked-lists--the-node-structure)
9. [Linked Lists — Building in Code](#-linked-lists--building-in-code)
10. [The Arrow Operator `->`](#-the-arrow-operator--)
11. [Traversing a Linked List](#-traversing-a-linked-list)
12. [Prepend vs. Append vs. Sorted Insert](#-prepend-vs-append-vs-sorted-insert)
13. [Freeing a Linked List](#-freeing-a-linked-list)
14. [Linked List — Running Times](#-linked-list--running-times)
15. [Doubly Linked Lists](#-doubly-linked-lists)
16. [Trees](#-trees)
17. [Binary Search Trees](#-binary-search-trees)
18. [BST — Search in Code (Recursion)](#-bst--search-in-code-recursion)
19. [BST — Running Times and Trade-offs](#-bst--running-times-and-trade-offs)
20. [Hash Tables](#-hash-tables)
21. [Hash Functions](#-hash-functions)
22. [Collisions and Chaining](#-collisions-and-chaining)
23. [Hash Table — Running Times](#-hash-table--running-times)
24. [Tries](#-tries)
25. [Tries — Running Times and Trade-offs](#-tries--running-times-and-trade-offs)
26. [Big O Summary — All Data Structures](#-big-o-summary--all-data-structures)
27. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🧩 Abstract Data Types

An **abstract data type (ADT)** defines a data structure by its *behavior* (what operations it supports) rather than its *implementation* (how it is built in memory). The same ADT can be implemented in multiple ways, each with different trade-offs for speed and memory.

Key ADTs introduced this week:

| ADT | Core Property | Real-World Analogy |
|-----|--------------|-------------------|
| **Queue** | First In, First Out (FIFO) | A checkout line at a store |
| **Stack** | Last In, First Out (LIFO) | A pile of trays in a cafeteria |
| **Dictionary** | Key-value pairs | A phone book or English dictionary |

---

## 🚶 Queues — FIFO

A **queue** is a data structure where the first element added is the first element removed — just like a real-world line.

```
Enqueue → [A] [B] [C] → Dequeue
           ↑ back    ↑ front
```

**Operations:**

| Operation | Meaning |
|-----------|---------|
| `enqueue` | Add to the back of the queue (get in line) |
| `dequeue` | Remove from the front of the queue (leave the front) |

**Property:** FIFO — First In, First Out. Ensures fairness.

**Array-based implementation in C:**

```c
typedef struct
{
    person people[CAPACITY];   // fixed-size array
    int size;                  // current number of elements
}
queue;
```

**Limitation:** Capacity must be decided at compile time. A 51st person cannot join if capacity is 50.

---

## 📚 Stacks — LIFO

A **stack** is a data structure where the last element added is the first element removed — like a box of clothes or a pile of cafeteria trays.

```
push → [C]  ← top
       [B]
       [A]  ← bottom
       ↓ pop (removes C first)
```

**Operations:**

| Operation | Meaning |
|-----------|---------|
| `push` | Add to the top of the stack |
| `pop` | Remove from the top of the stack |

**Property:** LIFO — Last In, First Out.

**Real-world examples:** Your email inbox (newest email on top), browser history, undo/redo in text editors.

**Array-based implementation:**

```c
typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;
```

**Limitation:** Same as the queue — fixed size at compile time.

---

## 📖 Dictionaries

A **dictionary** is an ADT that stores **key-value pairs** — associating one piece of data with another.

```
Key        → Value
"Mario"    → "617-555-0100"
"Luigi"    → "617-555-0101"
"Toad"     → "617-555-0102"
```

Real-world equivalents: a phone book (name → number), an English dictionary (word → definition), Python's `dict`.

Dictionaries can be implemented many ways — arrays, linked lists, hash tables, tries — each with different speed and memory trade-offs.

---

## 🔢 Arrays — Revisited

An **array** stores values **contiguously** (back-to-back) in memory.

```
Memory:  [ 1 ][ 2 ][ 3 ]
Address:  100  104  108    (4 bytes apart for int)
```

**Upsides:**
- Fast random access: `list[i]` is just pointer arithmetic
- Enables binary search → O(log n)

**Downside:**
- Size must be decided at compile time
- Resizing requires copying all elements to a new location

```c
// Static array — fixed size forever
int list[3];
list[0] = 1;
list[1] = 2;
list[2] = 3;
```

---

## 🧠 Dynamic Memory with malloc and realloc

To resize an array at runtime, allocate memory dynamically:

```c
#include <stdlib.h>

// Allocate space for 3 ints
int *list = malloc(3 * sizeof(int));
if (list == NULL) return 1;   // always check for NULL

list[0] = 1;
list[1] = 2;
list[2] = 3;

// Want space for 4 ints now — use a temp variable!
int *tmp = realloc(list, 4 * sizeof(int));
if (tmp == NULL)
{
    free(list);   // free original before aborting
    return 1;
}

list = tmp;       // point list at the new (larger) memory
list[3] = 4;

free(list);       // always free when done
return 0;
```

### realloc vs. malloc

| Function | What it does |
|----------|-------------|
| `malloc(n)` | Allocate n bytes; contents are uninitialized |
| `realloc(ptr, n)` | Try to grow/shrink the block at `ptr` to n bytes; copies old data automatically |

### Rules of Dynamic Memory

1. **Always check if malloc/realloc returned NULL** — it means out of memory
2. **Always use a temp variable with realloc** — if it fails, you still have your original pointer
3. **Always free memory you no longer need** — prevents memory leaks
4. **Every malloc should have a matching free**

---

## 🔗 Linked Lists — The Concept

Instead of storing values contiguously, a **linked list** stores each value anywhere in memory and uses **pointers** to connect them:

```
list → [ 1 | •──→ ][ 2 | •──→ ][ 3 | NULL ]
         node 1       node 2       node 3
```

- Each **node** contains: the actual data + a pointer to the next node
- The last node's pointer is `NULL` (end of list)
- One pointer called `list` points to the first node

**Upsides over arrays:**
- Grow and shrink dynamically — no copying needed
- Use memory wherever it's available, even if fragmented

**Downsides:**
- Uses more memory (extra pointer per node)
- No random access — must traverse from the beginning
- Cannot use binary search

---

## 🏗️ Linked Lists — The Node Structure

```c
typedef struct node
{
    int number;           // the data
    struct node *next;    // pointer to the next node
}
node;
```

**Why `struct node` on line 1?** Because C reads top-to-bottom. The word `node` isn't fully defined until the closing `}`. Using `struct node *next` inside the definition works because `struct node` has already been seen.

**Memory layout of one node:**

```
┌─────────────┬─────────────────────┐
│   number    │        next         │
│  (4 bytes)  │     (8 bytes)       │
└─────────────┴─────────────────────┘
         Total: ~12 bytes per node
```

---

## 🔨 Linked Lists — Building in Code

```c
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *list = NULL;   // empty list

    // Build list with 3 user-entered values
    for (int i = 0; i < 3; i++)
    {
        int n = get_int("Number: ");

        // Allocate a new node
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL) return 1;

        // Populate the node
        tmp->number = n;
        tmp->next = NULL;

        // Prepend to existing list
        tmp->next = list;
        list = tmp;
    }
}
```

### Prepending Step-by-Step

Starting with `list = NULL`:

```
Step 1: Insert 1
  tmp → [ 1 | NULL ]
  tmp->next = list  →  tmp → [ 1 | NULL ]
  list = tmp        →  list → [ 1 | NULL ]

Step 2: Insert 2
  tmp → [ 2 | NULL ]
  tmp->next = list  →  tmp → [ 2 | •──→ ][ 1 | NULL ]
  list = tmp        →  list → [ 2 | •──→ ][ 1 | NULL ]

Step 3: Insert 3
  list → [ 3 | •──→ ][ 2 | •──→ ][ 1 | NULL ]
```

> **Note:** Prepending is fast (O(1)) but produces a reversed list.

---

## ➡️ The Arrow Operator `->`

The `->` operator combines **dereferencing** a pointer and **accessing a field** in one step:

```c
// These two lines are equivalent:
(*tmp).number = n;   // dereference then access field (ugly)
tmp->number = n;     // same thing, much cleaner (use this)
```

```c
// Example usage:
tmp->number = 5;          // set the number field
tmp->next = NULL;         // set the next pointer
printf("%i", tmp->number); // read the number field
```

The arrow `->` visually matches the arrows we draw in memory diagrams. Use it any time you have a pointer to a struct.

---

## 🔍 Traversing a Linked List

To visit every node, use a temporary pointer that advances through the list:

### While Loop Version

```c
node *ptr = list;         // start at the beginning
while (ptr != NULL)
{
    printf("%i\n", ptr->number);  // print current node's value
    ptr = ptr->next;              // advance to next node
}
```

### For Loop Version (equivalent)

```c
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
    printf("%i\n", ptr->number);
}
```

### Memory Diagram

```
ptr → [ 3 | •──→ ][ 2 | •──→ ][ 1 | NULL ]

Iteration 1: print 3, ptr = ptr->next
Iteration 2: print 2, ptr = ptr->next
Iteration 3: print 1, ptr = ptr->next
Iteration 4: ptr == NULL → stop
```

> **Never advance the `list` pointer itself** — you'll lose track of the beginning of the list (memory leak!). Always use a separate traversal variable.

---

## 🔀 Prepend vs. Append vs. Sorted Insert

| Method | Running Time | Result |
|--------|-------------|--------|
| **Prepend** (insert at front) | O(1) | Reversed order |
| **Append** (insert at back) | O(n) | Same order as inserted |
| **Sorted insert** (insert in order) | O(n) | Sorted order |

### Sorted Insert — Four Scenarios

When inserting into a sorted linked list, you must handle:

1. **Empty list** — just make it the first node
2. **Belongs at the beginning** — prepend it
3. **Belongs at the end** — append it
4. **Belongs in the middle** — stitch it between two existing nodes

```c
// Scenario 2: new node belongs at the beginning
if (n->number < list->number)
{
    n->next = list;
    list = n;
}
```

```c
// Scenario 3 & 4: traverse to find the right position
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
    if (ptr->next == NULL)           // end of list → append
    {
        ptr->next = n;
        break;
    }
    if (n->number < ptr->next->number)  // middle → stitch in
    {
        n->next = ptr->next;
        ptr->next = n;
        break;
    }
}
```

> **Order of pointer operations matters.** Always update the new node's `next` pointer *before* updating the existing node's pointer. Otherwise you'll orphan part of the list.

---

## 🗑️ Freeing a Linked List

You cannot free the whole list with one call to `free()`. You must free each node individually, but carefully — you need to save the next pointer before freeing the current node:

```c
// Free every node in the list
node *ptr = list;
while (ptr != NULL)
{
    node *next = ptr->next;  // save next BEFORE freeing current
    free(ptr);               // free the current node
    ptr = next;              // advance to saved next
}
```

If you did `free(ptr); ptr = ptr->next;` — that's undefined behavior because you're reading from freed memory.

---

## ⏱️ Linked List — Running Times

| Operation | Running Time | Reason |
|-----------|-------------|--------|
| **Insert** (prepend) | O(1) | Always inserts at front — constant steps |
| **Insert** (sorted/append) | O(n) | Must traverse to find the right position |
| **Search** | O(n) | Must start at head; no random access |
| **Delete** | O(n) | Must traverse to find the node |
| **Traverse/Print** | O(n) | Must visit every node |

**The fundamental trade-off:**

| | Arrays | Linked Lists |
|--|--------|-------------|
| Memory | Contiguous (efficient) | Scattered + extra pointers (wasteful) |
| Resize | Copy everything (slow) | Just add a node (fast) |
| Search | O(log n) with binary search | O(n) — no binary search possible |
| Access by index | O(1) | O(n) |

---

## ↔️ Doubly Linked Lists

A **doubly linked list** adds a second pointer per node pointing to the *previous* node, enabling traversal in both directions:

```c
typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;   // ← new
}
node;
```

```
NULL ←─[ 1 ]⟷[ 2 ]⟷[ 3 ]─→ NULL
```

**Advantage:** Easier to delete a node or insert in the middle — no need to track the previous node separately with a second traversal pointer.

**Disadvantage:** Uses even more memory (3 things per node instead of 2).

---

## 🌳 Trees

A **tree** is a two-dimensional data structure where each node can have multiple children. Unlike a linked list (one dimension), a tree adds a second dimension — depth.

**Vocabulary:**

| Term | Meaning |
|------|---------|
| **Root** | The topmost node (no parent) |
| **Child** | A node pointed to by another node |
| **Parent** | A node that points to children |
| **Leaf** | A node with no children (at the edge) |
| **Subtree** | A node and all its descendants |
| **Height** | Number of levels from root to deepest leaf |

```
         [ 4 ]         ← root
        /     \
     [ 2 ]   [ 6 ]     ← internal nodes
     /   \   /   \
   [ 1 ][ 3 ][ 5 ][ 7 ] ← leaves
```

---

## 🔍 Binary Search Trees

A **binary search tree (BST)** is a tree with a special ordering property:

> For every node: **left child < node < right child**

This property holds **recursively** — it applies to every node and every subtree within the tree.

**Searching:** Start at the root. If the target is smaller, go left. If larger, go right. Repeat until found or hit `NULL`.

```
Search for 5 in:
         [ 4 ]
        /     \
     [ 2 ]   [ 6 ]
             /
           [ 5 ]

Step 1: 5 > 4 → go right to [ 6 ]
Step 2: 5 < 6 → go left  to [ 5 ]
Step 3: 5 == 5 → found! (3 steps, log₂(7) ≈ 3)
```

**Node structure:**

```c
typedef struct node
{
    int number;
    struct node *left;    // pointer to left subtree
    struct node *right;   // pointer to right subtree
}
node;
```

---

## 🔁 BST — Search in Code (Recursion)

The recursive property of BSTs maps beautifully to recursive code:

```c
bool search(int number, node *tree)
{
    // Base case: empty tree or reached a NULL child
    if (tree == NULL)
        return false;

    // Recurse left if target is smaller
    if (number < tree->number)
        return search(number, tree->left);

    // Recurse right if target is larger
    if (number > tree->number)
        return search(number, tree->right);

    // Found it
    return true;
}
```

**Why recursion fits here:** A BST is a *recursive data structure* — what is true of the root (left < root < right) is also true of every subtree. This means you can call the same `search` function on any subtree.

Condensed version:

```c
bool search(int number, node *tree)
{
    if (tree == NULL)              return false;
    if (number < tree->number)     return search(number, tree->left);
    if (number > tree->number)     return search(number, tree->right);
    return true;
}
```

---

## ⚖️ BST — Running Times and Trade-offs

| Operation | Running Time | Condition |
|-----------|-------------|-----------|
| **Search** | O(log n) | Tree is balanced |
| **Insert** | O(log n) | Tree is balanced |
| **Delete** | O(log n) | Tree is balanced |
| **All operations** | O(n) | Worst case — tree degenerates into a linked list |

### The Degenerate Tree Problem

If values are inserted in sorted order (1, 2, 3, 4, 5, ...), a naive BST becomes a linked list:

```
[ 1 ]
    \
   [ 2 ]
       \
      [ 3 ]     ← O(n) to search, not O(log n)
          \
         [ 4 ]
```

**Solution:** Self-balancing BSTs (AVL trees, Red-Black trees) automatically rebalance after each insertion, maintaining O(log n) height. These are covered in higher-level courses.

### Space Trade-off

| Structure | Memory per element |
|-----------|-------------------|
| Array | 4 bytes (int only) |
| Linked list | 12 bytes (int + 1 pointer) |
| BST node | 20 bytes (int + 2 pointers) |

You spend ~3× more memory than an array to gain dynamic growth without losing binary search.

---

## #️⃣ Hash Tables

A **hash table** is an array of linked lists — an amalgam of the two data structures, taking the fast lookup of arrays and the dynamic sizing of linked lists.

```
Index │ Linked List
──────┼──────────────────────────────
  0   │ NULL
  1   │ NULL
  ...
  11  │ Luigi → Lara → NULL
  12  │ Mario → Moe → NULL
  ...
  25  │ Zelda → NULL
```

**Idea:** Use a **hash function** to convert a key (like a name) into an array index (a bucket number). Store the value in that bucket. If two keys hash to the same bucket, chain them in a linked list.

**Structure:**

```c
typedef struct node
{
    char name[50];
    struct node *next;
}
node;

node *table[26];   // array of 26 linked list heads
```

---

## 🔨 Hash Functions

A **hash function** maps an input (any key) to a number (bucket index). A good hash function:

- Is **deterministic** — same input always gives same output
- Is **fast** to compute
- Distributes keys **uniformly** across buckets (minimizes collisions)

**Simple example — hash on first letter:**

```c
#include <ctype.h>

unsigned int hash(const char *name)
{
    return toupper(name[0]) - 'A';   // 'A'→0, 'B'→1, ..., 'Z'→25
}
```

- `const` — the function promises not to modify the string
- `unsigned int` — hash values are always non-negative
- `toupper` — ensures case-insensitivity

**Better hash functions** look at more characters (e.g. first 3 letters), use multiplication and modulo, or incorporate every character — reducing collisions at the cost of more computation.

---

## 💥 Collisions and Chaining

A **collision** occurs when two different keys hash to the same bucket.

**Example:** Both "Mario" and "Moe" start with M → both hash to bucket 12.

**Solution — Separate Chaining:** Use a linked list at each bucket. When a collision occurs, prepend the new node to that bucket's chain.

```
bucket 12 → [ Mario | •──→ ][ Moe | NULL ]
```

```c
// Insert "Moe" into hash table
unsigned int index = hash("Moe");    // returns 12
node *n = malloc(sizeof(node));
strcpy(n->name, "Moe");
n->next = table[index];              // point to existing chain
table[index] = n;                    // update bucket head
```

**Searching with chaining:**

```c
node *ptr = table[hash("Mario")];    // jump to bucket
while (ptr != NULL)
{
    if (strcmp(ptr->name, "Mario") == 0) return true;
    ptr = ptr->next;
}
return false;
```

---

## ⏱️ Hash Table — Running Times

| Operation | Average Case | Worst Case |
|-----------|-------------|------------|
| **Insert** | O(1) | O(n) |
| **Search** | O(1) or O(n/k) | O(n) |
| **Delete** | O(1) or O(n/k) | O(n) |

Where `k` = number of buckets.

**Average case reasoning:** If n elements are spread uniformly across k buckets, each chain has n/k elements. For large k, n/k approaches a constant → effectively O(1).

**Worst case:** All elements hash to the same bucket → one giant linked list → O(n).

**The big insight:** Even though n/k < n, it's still O(n) asymptotically (constants don't change Big O). But in practice, a well-designed hash table with enough buckets is effectively constant time.

**Improving performance:**
- Use more buckets → shorter chains → faster lookups (but more memory)
- Use a better hash function → fewer collisions

---

## 🌲 Tries

A **trie** (short for *retrieval*, pronounced "try") is a tree made of arrays — each node is an array of pointers indexed by character.

**Key idea:** Instead of storing a word explicitly, you spell it out by following pointers one character at a time.

```
root
├── [T] → node
│         ├── [O] → node
│         │         ├── [A] → node
│         │         │         └── [D] → ✓ (Toad)
│         │         └── [M] → ✓ (Tom)
│         └── [O] shared... → [D] → [E] → [T] → [T] → ✓ (Todettt)
└── [M] → node
          └── [A] → node
                    └── [R] → node
                              └── [I] → node
                                        └── [O] → ✓ (Mario)
```

**Node structure:**

```c
typedef struct node
{
    struct node *children[26];  // one pointer per letter A-Z
    bool is_word;               // true if a word ends here
}
node;
```

**Searching:**

```c
node *ptr = root;
for (int i = 0; name[i] != '\0'; i++)
{
    int index = toupper(name[i]) - 'A';
    if (ptr->children[index] == NULL) return false;  // not found
    ptr = ptr->children[index];
}
return ptr->is_word;   // found — but is it a complete word?
```

**Inserting "Toad":** Hash T→index 19, O→14, A→0, D→3 — allocate nodes as needed, set `is_word = true` at the last node.

---

## ⚖️ Tries — Running Times and Trade-offs

| Operation | Running Time |
|-----------|-------------|
| **Search** | O(k) where k = length of the key |
| **Insert** | O(k) |
| **Delete** | O(k) |

Since names have a practical maximum length (no one's name is 1000 characters), k is effectively a constant → **O(1) in practice**.

**Pros:**
- True constant-time lookups regardless of data set size
- Naturally sorted (alphabetical traversal)
- No collisions

**Cons:**
- Massive memory usage — every node has 26 pointers (×8 bytes each = 208 bytes per node)
- Most pointers in every node are `NULL` — huge waste
- Much more complex to implement

### Memory Comparison

| Structure | Memory per element (approx.) |
|-----------|------------------------------|
| Array | 4 bytes |
| Linked list | 12 bytes |
| BST node | 20 bytes |
| Trie node | 26 × 8 = 208 bytes + bool |

---

## 📊 Big O Summary — All Data Structures

| Data Structure | Insert | Search | Delete | Space |
|---------------|--------|--------|--------|-------|
| **Array** (static) | O(n) | O(log n)* | O(n) | O(n) |
| **Linked list** | O(1)† | O(n) | O(n) | O(n) |
| **BST** (balanced) | O(log n) | O(log n) | O(log n) | O(n) |
| **BST** (unbalanced) | O(n) | O(n) | O(n) | O(n) |
| **Hash table** | O(1)‡ | O(1)‡ | O(1)‡ | O(n) |
| **Trie** | O(k) | O(k) | O(k) | O(n × k × 26) |

*Binary search only possible if array is sorted  
†Prepend only; sorted insert is O(n)  
‡Average case with a good hash function and low collision rate

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Abstract data type** | Defined by behavior (operations), not implementation |
| **Queue** | FIFO — first in, first out; operations: enqueue / dequeue |
| **Stack** | LIFO — last in, first out; operations: push / pop |
| **Dictionary** | Key-value pairs; abstract concept implemented many ways |
| **Static array** | Fixed size at compile time; contiguous memory; fast random access |
| **Dynamic array** | `malloc` / `realloc`; can grow; copying required |
| **malloc** | Allocate heap memory; always check for NULL |
| **realloc** | Grow/shrink existing allocation; copies old data automatically |
| **free** | Return allocated memory; every malloc needs a free |
| **Memory leak** | Allocated memory that is never freed; program slows over time |
| **Linked list** | Nodes scattered in memory, connected by pointers |
| **Node** | A struct with data + pointer(s) to adjacent nodes |
| **`struct node *next`** | Pointer to the next node in a linked list |
| **`->`** | Arrow operator: dereference a pointer and access a field |
| **Prepend** | Insert at front of list — O(1) |
| **Append** | Insert at back of list — O(n) |
| **Sorted insert** | Maintain order during insertion — O(n) |
| **Pointer order** | Update new node's next BEFORE updating existing node's pointer |
| **Freeing a list** | Save `ptr->next` before calling `free(ptr)` |
| **Singly linked list** | One `next` pointer per node |
| **Doubly linked list** | Both `next` and `prev` pointers per node |
| **Tree** | 2-dimensional hierarchical structure; nodes have children |
| **Root** | Topmost node of a tree |
| **Leaf** | Node with no children |
| **BST** | Binary search tree — left < node < right, recursively |
| **BST search** | Start at root; go left if smaller, right if larger |
| **Recursive data structure** | A BST is defined in terms of itself (subtrees are also BSTs) |
| **Balanced BST** | Height is O(log n); all operations are O(log n) |
| **Degenerate BST** | Sorted insertion creates a linked list — O(n) operations |
| **Self-balancing BST** | AVL / Red-Black trees — automatically rebalance on insert/delete |
| **Hash function** | Maps a key to a bucket index (0 through k-1) |
| **Hash table** | Array of linked lists — fast average lookup with dynamic chaining |
| **Collision** | Two keys hash to the same bucket |
| **Separate chaining** | Handle collisions by using a linked list at each bucket |
| **Uniform distribution** | Ideal hash function distributes keys evenly across all buckets |
| **Trie** | Tree of arrays; each level represents one character of the key |
| **O(k) lookup** | Trie search time depends only on key length, not data set size |
| **Time-space trade-off** | Faster structures typically use more memory |
| **const** | Tells the compiler (and programmer) a value should not be modified |
| **unsigned int** | Integer that is always ≥ 0; appropriate for array indices |

---

## 🗂️ Problem Set 5

Implement your own spell-checker using a hash table to store 100,000+ English words and check documents against them:
[cs50.harvard.edu/x/2026/psets/5](https://cs50.harvard.edu/x/2026/psets/5/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 4 – Memory](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%204%20-%20Memory) |
| ➡️ Next | [Week 6 – Python](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%206%20-%20Python) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 5 - Data Structures`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%205%20-%20Data%20Structures)
