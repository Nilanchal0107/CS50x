# 🗄️ CS50x – Week 7: SQL
### Harvard University's Introduction to Structured Query Language, Relational Databases, and Data Management

> *"SQL is said to be a declarative programming language — a different sort of paradigm whereby when you want to solve some problem, you essentially declare what problem you want to solve, and it's up to the programming language to figure out how to get you the answer."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Language](https://img.shields.io/badge/Language-SQL-orange?style=flat-square&logo=sqlite)](https://en.wikipedia.org/wiki/SQL)
[![Lecture](https://img.shields.io/badge/Lecture-Week%207-green?style=flat-square)](https://cs50.harvard.edu/x/weeks/7/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=oqRU2So6Z2Y)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 7](https://www.youtube.com/watch?v=oqRU2So6Z2Y) |
| 📝 Official Notes | [cs50.harvard.edu/x/notes/7](https://cs50.harvard.edu/x/notes/7/) |
| 📖 CS50 Manual | [manual.cs50.io](https://manual.cs50.io/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 7 | [cs50.harvard.edu/x/2026/psets/7](https://cs50.harvard.edu/x/2026/psets/7/) |

---

## 📋 Table of Contents

1. [Flat Files and CSV](#-flat-files-and-csv)
2. [Reading CSV Data in Python](#-reading-csv-data-in-python)
3. [CSV DictReader](#-csv-dictreader)
4. [Counting with Dictionaries](#-counting-with-dictionaries)
5. [Procedural vs. Declarative Programming](#-procedural-vs-declarative-programming)
6. [Relational Databases and SQL](#-relational-databases-and-sql)
7. [CRUD Operations](#-crud-operations)
8. [SQLite3 — Getting Started](#-sqlite3--getting-started)
9. [SELECT — Reading Data](#-select--reading-data)
10. [SQL Functions and Keywords](#-sql-functions-and-keywords)
11. [WHERE, LIKE, ORDER BY, LIMIT](#-where-like-order-by-limit)
12. [GROUP BY](#-group-by)
13. [INSERT INTO](#-insert-into)
14. [DELETE](#-delete)
15. [UPDATE](#-update)
16. [DROP TABLE](#-drop-table)
17. [Data Types in SQLite](#-data-types-in-sqlite)
18. [NULL in SQL](#-null-in-sql)
19. [Constraints — NOT NULL, UNIQUE](#-constraints--not-null-unique)
20. [Primary Keys and Foreign Keys](#-primary-keys-and-foreign-keys)
21. [Relationships: 1-to-1, 1-to-Many, Many-to-Many](#-relationships-1-to-1-1-to-many-many-to-many)
22. [JOIN — Combining Tables](#-join--combining-tables)
23. [Nested Queries (Subqueries)](#-nested-queries-subqueries)
24. [Indexes — Optimizing Queries](#-indexes--optimizing-queries)
25. [B-Trees](#-b-trees)
26. [Python + SQL with CS50 Library](#-python--sql-with-cs50-library)
27. [SQL Injection Attacks](#-sql-injection-attacks)
28. [Race Conditions and Transactions](#-race-conditions-and-transactions)
29. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 📄 Flat Files and CSV

Before SQL, the simplest way to store tabular data is a **flat file database** — a plain text file where data is separated by a consistent delimiter.

```
Timestamp,Language,Problem
2024-01-01 13:30:00,Python,Hello World
2024-01-01 13:30:01,C,Mario
2024-01-01 13:30:02,Scratch,Scratch
```

Common flat file formats:

| Format | Delimiter | Extension |
|--------|-----------|-----------|
| **CSV** | Comma `,` | `.csv` |
| **TSV** | Tab `\t` | `.tsv` |
| **PSV** | Pipe `\|` | `.psv` |

**Key idea:** Use a character that is unlikely to appear in the actual data as the separator. This is how each row's columns are identified.

---

## 🐍 Reading CSV Data in Python

Python ships with a built-in `csv` library for reading and writing CSV files:

```python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)  # Skip the header row
    for row in reader:
        favorite = row[1]  # Column index 1 = Language
        print(favorite)
```

### Important Details

- `csv.reader` returns each row as a **list** — columns are accessed by numeric index (0, 1, 2 ...)
- `next(reader)` is needed to skip the header because `csv.reader` reads every row including the first
- The reader is **stateful** — like a cassette tape, it remembers its position and advances forward with each read
- Numeric indexing is **fragile**: if someone moves a column in the spreadsheet, your code breaks

---

## 📚 CSV DictReader

A more robust approach is `csv.DictReader`, which maps each row to a **dictionary** using the header row as keys:

```python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    # No need to call next(reader) — header is auto-consumed
    for row in reader:
        favorite = row["language"]  # Access by column name, not index
        print(favorite)
```

### DictReader vs. Reader

| Feature | `csv.reader` | `csv.DictReader` |
|---------|-------------|-----------------|
| Row type | `list` | `dict` |
| Column access | `row[1]` | `row["language"]` |
| Header row | Must skip manually with `next()` | Auto-consumed as keys |
| Resilience to column reordering | ❌ Breaks | ✅ Robust |

---

## 🧮 Counting with Dictionaries

To count how many people chose each language, use a Python dictionary as a counter:

```python
import csv

counts = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        favorite = row["language"]
        if favorite not in counts:
            counts[favorite] = 0
        counts[favorite] += 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
```

### Four Ways to Handle a Missing Key

```python
# Option 1: Check before incrementing
if favorite not in counts:
    counts[favorite] = 0
counts[favorite] += 1

# Option 2: Conditional increment or initialize
if favorite in counts:
    counts[favorite] += 1
else:
    counts[favorite] = 1

# Option 3: try / except
try:
    counts[favorite] += 1
except KeyError:
    counts[favorite] = 1

# Option 4: dict.get() with default
counts[favorite] = counts.get(favorite, 0) + 1
```

### Sorting a Dictionary

```python
# Sort by key (alphabetically)
for favorite in sorted(counts):
    print(favorite, counts[favorite])

# Sort by value (ascending)
for favorite in sorted(counts, key=counts.get):
    print(favorite, counts[favorite])

# Sort by value (descending)
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(favorite, counts[favorite])
```

While this works, it takes ~17 lines of code just to count and sort data. SQL will do the same in a single line.

---

## ⚖️ Procedural vs. Declarative Programming

| Paradigm | Description | Example Languages |
|----------|-------------|-------------------|
| **Procedural** | You write step-by-step instructions telling the computer *how* to solve the problem | C, Python |
| **Declarative** | You declare *what* you want; the language figures out *how* to get it | SQL |

SQL is declarative: instead of writing loops and conditionals to analyze data, you simply ask a question and the database answers it.

---

## 🗃️ Relational Databases and SQL

A **relational database** stores data in **tables** (rows and columns) and allows you to define relationships between tables.

**SQL (Structured Query Language)** is the language used to interact with relational databases. In CS50, we use **SQLite** — a lightweight, file-based version of SQL commonly used in web and mobile apps.

Other SQL databases you'll encounter in the real world:

| Product | Type | Notes |
|---------|------|-------|
| **SQLite** | File-based | Lightweight; great for local/dev use |
| **MySQL** | Open source | Very popular for web apps |
| **PostgreSQL** | Open source | Feature-rich; widely used in production |
| **Oracle** | Commercial | Large enterprise environments |
| **Microsoft SQL Server** | Commercial | Windows / Azure ecosystems |

---

## 📝 CRUD Operations

SQL databases support exactly four fundamental operations, collectively called **CRUD**:

| Operation | SQL Command | Meaning |
|-----------|-------------|---------|
| **Create** | `INSERT` | Add new rows |
| **Read** | `SELECT` | Query / retrieve data |
| **Update** | `UPDATE` | Modify existing rows |
| **Delete** | `DELETE` / `DROP` | Remove rows or entire tables |

---

## 🚀 SQLite3 — Getting Started

### Create a New Database

```bash
sqlite3 favorites.db
```

If `favorites.db` doesn't exist, SQLite creates it. If it does, it opens it.

### Import a CSV File

```sql
.mode csv
.import favorites.csv favorites
.quit
```

- `.mode csv` — tells SQLite to parse incoming data as CSV
- `.import favorites.csv favorites` — imports the CSV into a table named `favorites`
- Dot-commands (`.mode`, `.import`, `.quit`, `.schema`) are **SQLite-specific**
- Everything else (SELECT, INSERT, etc.) is standard SQL

### View the Schema

```sql
.schema
```

Output:
```sql
CREATE TABLE IF NOT EXISTS "favorites"(
  "Timestamp" TEXT,
  "language" TEXT,
  "problem" TEXT
);
```

### The Database File

The resulting `.db` file is binary — you cannot open it in a text editor. The database stores data efficiently in binary format to support fast searching and indexing.

---

## 🔍 SELECT — Reading Data

`SELECT` is the most fundamental SQL command. It **reads** data from a table.

```sql
-- Select everything from a table
SELECT * FROM favorites;

-- Select specific columns
SELECT language FROM favorites;

-- Select multiple columns
SELECT language, problem FROM favorites;
```

- `*` is a wildcard meaning "all columns"
- SQL keywords are conventionally UPPERCASED
- Table/column names stay lowercase
- Every SQL statement ends with a semicolon `;`

---

## 🛠️ SQL Functions and Keywords

SQLite comes with built-in functions, similar to spreadsheet formulas:

```sql
-- Count total rows
SELECT COUNT(*) FROM favorites;

-- Count distinct values in a column
SELECT DISTINCT language FROM favorites;

-- Count of distinct values
SELECT COUNT(DISTINCT language) FROM favorites;

-- Average, min, max
SELECT AVG(rating) FROM ratings;
SELECT MIN(rating) FROM ratings;
SELECT MAX(rating) FROM ratings;
```

Common built-in functions:

| Function | Purpose |
|----------|---------|
| `COUNT(*)` | Total number of rows |
| `COUNT(DISTINCT col)` | Number of unique values |
| `AVG(col)` | Average of numeric column |
| `MIN(col)` | Minimum value |
| `MAX(col)` | Maximum value |
| `UPPER(col)` | Convert text to uppercase |
| `LOWER(col)` | Convert text to lowercase |

---

## 🔎 WHERE, LIKE, ORDER BY, LIMIT

### WHERE — Filter Rows

```sql
-- Exact match
SELECT COUNT(*) FROM favorites WHERE language = 'C';

-- Multiple conditions with AND
SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hello World';

-- OR condition
SELECT COUNT(*) FROM favorites WHERE problem = 'Hello World' OR problem = 'Hello, It''s Me';
```

> **Escaping single quotes in SQL:** Use two consecutive single quotes `''` inside a string.
> `'Hello, It''s Me'` → represents `Hello, It's Me`

### LIKE — Pattern Matching

```sql
-- Starts with "Hello"
SELECT COUNT(*) FROM favorites WHERE problem LIKE 'Hello%';
```

- `%` — wildcard for zero or more characters (SQL equivalent of `*` in shell)
- `LIKE` is **case-insensitive** for string matching
- `=` is case-sensitive; `LIKE` is not

### ORDER BY — Sort Results

```sql
-- Ascending (default)
SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n;

-- Descending
SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC;
```

### LIMIT — Cap Results

```sql
-- Return only the top 10 rows
SELECT title FROM shows LIMIT 10;
```

### AS — Aliases

```sql
-- Rename COUNT(*) to "n" for readability
SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC;
```

---

## 📊 GROUP BY

`GROUP BY` groups rows with identical values in a column together, letting you apply aggregate functions per group:

```sql
-- Count how many people chose each language
SELECT language, COUNT(*) AS n
FROM favorites
GROUP BY language
ORDER BY n DESC;
```

Output:
```
Python | 190
C      | 58
Scratch| 24
```

This replaces ~17 lines of Python (open file → read rows → build dictionary → sort) with a **single SQL statement**.

---

## ➕ INSERT INTO

Add new rows to a table:

```sql
-- Insert a full row
INSERT INTO favorites (language, problem) VALUES ('SQL', '50-Ville');
```

- You can omit columns — they will be `NULL` by default
- Column order in `(...)` must match value order in `VALUES (...)`

---

## 🗑️ DELETE

Remove rows from a table:

```sql
-- Delete rows where timestamp is NULL
DELETE FROM favorites WHERE timestamp IS NULL;

-- ⚠️ Delete ALL rows — no WHERE means no filter!
DELETE FROM favorites;
```

> **WARNING:** `DELETE` without a `WHERE` clause is **permanent** and deletes every row in the table. Always double-check your `WHERE` clause before executing. There is no undo.

---

## ✏️ UPDATE

Modify existing rows:

```sql
-- Update a specific row
UPDATE favorites SET language = 'SQL', problem = '50-Ville' WHERE timestamp IS NULL;

-- ⚠️ Update ALL rows — dangerous without WHERE
UPDATE favorites SET language = 'SQL';
```

> **WARNING:** Like `DELETE`, `UPDATE` without a `WHERE` clause applies to every row. One of the most common destructive mistakes in production databases.

---

## 💥 DROP TABLE

Delete an entire table (structure + all data):

```sql
DROP TABLE favorites;
```

After this, `.schema` will show nothing. This is even more destructive than `DELETE` — the entire table definition is gone, not just the rows.

---

## 🧮 Data Types in SQLite

SQLite supports 5 storage types:

| Type | Description | Example |
|------|-------------|---------|
| `INTEGER` | Whole numbers | `1`, `42`, `-7` |
| `REAL` | Floating-point numbers | `3.14`, `9.8` |
| `TEXT` | Strings | `'Hello'`, `'CS50'` |
| `NUMERIC` | Dates, times, booleans, decimals | `2024-01-01` |
| `BLOB` | Binary Large Object — raw bytes | Images, files |

Other SQL databases (MySQL, PostgreSQL, Oracle) have many more specialized types.

---

## 🚫 NULL in SQL

`NULL` is not the same as `0`, `""`, or `False`. It explicitly represents the **absence of data**:

```sql
-- Check for NULL (not IS = NULL)
WHERE timestamp IS NULL
WHERE timestamp IS NOT NULL
```

- `NULL = NULL` evaluates to **false** — you must use `IS NULL`
- `NULL` is a deliberate signal: "this data was not provided"
- In spreadsheets, a blank cell is ambiguous; in SQL, `NULL` is unambiguous

---

## 🔒 Constraints — NOT NULL, UNIQUE

When creating a table, you can enforce data integrity rules:

```sql
CREATE TABLE shows (
    id   INTEGER PRIMARY KEY,
    title TEXT NOT NULL,   -- title can never be NULL
    year NUMERIC,
    episodes INTEGER
);
```

| Constraint | Meaning |
|------------|---------|
| `NOT NULL` | This column must always have a value |
| `UNIQUE` | No two rows can have the same value in this column |
| `PRIMARY KEY` | Uniquely identifies every row; implies NOT NULL + UNIQUE |

---

## 🔑 Primary Keys and Foreign Keys

### Primary Key

The **primary key** is the unique identifier for every row in a table — typically an integer ID:

```sql
CREATE TABLE shows (
    id INTEGER PRIMARY KEY,  -- unique identifier for every show
    title TEXT NOT NULL,
    year NUMERIC
);
```

### Foreign Key

A **foreign key** is that same ID appearing in another table as a cross-reference:

```sql
CREATE TABLE ratings (
    show_id INTEGER,         -- foreign key referencing shows.id
    rating REAL NOT NULL,
    votes INTEGER NOT NULL,
    FOREIGN KEY(show_id) REFERENCES shows(id)
);
```

### Naming Convention

| Appearance | Convention | Example |
|------------|------------|---------|
| In its own table | `id` | `shows.id` |
| In another table | `tablename_id` | `ratings.show_id` |

```
shows.id  ←───── primary key
    ↕
ratings.show_id ←─ foreign key (references shows.id)
```

---

## 🔗 Relationships: 1-to-1, 1-to-Many, Many-to-Many

Relational databases model three types of relationships between tables:

### 1-to-1 Relationship

Each row in Table A corresponds to **exactly one** row in Table B.

```
shows ──────── ratings
(1 show → 1 rating)
```

Enforced by adding `UNIQUE` to the foreign key column. Example: each TV show has exactly one rating entry.

### 1-to-Many Relationship

Each row in Table A corresponds to **multiple** rows in Table B.

```
shows ──────── genres
(1 show → many genres: Comedy, Drama, Sci-Fi...)
```

A show can belong to several genres, but each genre row belongs to one show.

### Many-to-Many Relationship

Rows in Table A can relate to **many** rows in Table B, and vice versa.

```
shows ──── stars ──── people
(1 show → many actors)
(1 actor → many shows)
```

Implemented with a **junction table** (here, `stars`) that holds pairs of foreign keys:

```sql
CREATE TABLE stars (
    show_id   INTEGER REFERENCES shows(id),
    person_id INTEGER REFERENCES people(id)
);
```

---

## 🔀 JOIN — Combining Tables

`JOIN` merges two tables by matching values across a shared column (primary key ↔ foreign key):

```sql
-- Join shows and ratings to get title + rating together
SELECT title, rating
FROM shows
JOIN ratings ON shows.id = ratings.show_id
WHERE rating >= 6.0
LIMIT 10;
```

### Joining Three Tables (Many-to-Many)

```sql
-- Get all shows Steve Carell starred in
SELECT title
FROM shows
JOIN stars ON shows.id = stars.show_id
JOIN people ON stars.person_id = people.id
WHERE people.name = 'Steve Carell';
```

### Visual Model

```
shows table          ratings table
┌────┬─────────┐     ┌─────────┬────────┐
│ id │ title   │     │ show_id │ rating │
├────┼─────────┤     ├─────────┼────────┤
│ 1  │ Office  │ ──► │    1    │  9.0   │
│ 2  │ Friends │ ──► │    2    │  8.9   │
└────┴─────────┘     └─────────┴────────┘

JOIN ON shows.id = ratings.show_id
         ↓
┌─────────┬────────┐
│ title   │ rating │
├─────────┼────────┤
│ Office  │  9.0   │
│ Friends │  8.9   │
└─────────┴────────┘
```

---

## 🪆 Nested Queries (Subqueries)

A **nested query** (also called a subquery) places one `SELECT` inside another, working from the inside out:

```sql
-- Step 1: Get the show ID for The Office (2005)
SELECT id FROM shows WHERE title = 'The Office' AND year = 2005;
-- → 386676

-- Step 2: Get all person IDs starring in that show
SELECT person_id FROM stars WHERE show_id = 386676;

-- Step 3: Get the names of those people
SELECT name FROM people WHERE id IN (person_id list);
```

Combined into one nested query:

```sql
SELECT name FROM people
WHERE id IN (
    SELECT person_id FROM stars
    WHERE show_id = (
        SELECT id FROM shows
        WHERE title = 'The Office' AND year = 2005
    )
);
```

### Nested Queries vs. JOINs

| Approach | Pros | Cons |
|----------|------|------|
| **Nested queries** | Easier to reason about; work outside-in logically | Can be slower for large datasets |
| **JOINs** | Often faster; more powerful for complex queries | Harder to read until you're comfortable |

> For CS50, start with nested queries — they are conceptually simpler and work perfectly for most problems.

---

## ⚡ Indexes — Optimizing Queries

By default, SQL does **linear search** — it scans every row from top to bottom. For large tables, this is slow.

An **index** pre-builds a tree structure on a column so future queries on that column use something closer to **binary search**:

```sql
-- Create an index on the title column of shows
CREATE INDEX title_index ON shows (title);
```

### Speed Comparison

```
Without index:
SELECT * FROM shows WHERE title = 'The Office';
→ 0.042 seconds  (linear search through 250,000+ rows)

With index:
→ 0.001 seconds  (42× faster — tree-based lookup)
```

### When to Create an Index

- On columns you frequently search with `WHERE`
- On foreign key columns used in `JOIN`
- On columns used in `ORDER BY` for large result sets

### Trade-offs

- Indexes take time to build (one-time cost)
- Indexes consume additional memory
- Indexes must be maintained when rows are inserted/deleted/updated
- Only create indexes on columns that are actually queried frequently

---

## 🌳 B-Trees

The data structure that powers SQL indexes is called a **B-tree** (Balanced Tree):

```
                    [M]
                   /   \
              [D–G]     [R–T]
             / | \       / \
           [D][E][G]  [R][T]
```

- Similar to binary trees but each node can have **many children** — not just 2
- More children per node → shallower tree → fewer steps to find data
- Finding a value takes O(log n) time instead of O(n) for linear search
- This is why creating an index went from 0.042 → 0.001 seconds

---

## 🐍 Python + SQL with CS50 Library

CS50's Python library lets you run SQL queries directly from Python code — the best of both worlds:

```python
from cs50 import SQL

# Open the database
db = SQL("sqlite:///favorites.db")

# Execute a query and get back results as a list of dicts
rows = db.execute(
    "SELECT language, COUNT(*) AS n FROM favorites GROUP BY language ORDER BY n DESC"
)

# Iterate over results
for row in rows:
    print(row["language"], row["n"])
```

- `db.execute()` returns a **list of dictionaries** — one dict per row
- Each dict's keys are the column names from your `SELECT` statement
- This lets you use Python for logic and SQL for data retrieval

### Interactive Example

```python
from cs50 import SQL

db = SQL("sqlite:///favorites.db")

problem = input("Problem: ")

rows = db.execute(
    "SELECT COUNT(*) AS n FROM favorites WHERE problem = ?",
    problem  # ← placeholder substitution, NOT f-string
)

print(rows[0]["n"])
```

> **Critical:** Use `?` placeholders, not f-strings, when inserting user input into SQL. More on this below.

---

## 💉 SQL Injection Attacks

A **SQL injection attack** happens when untrusted user input is blindly inserted into a SQL query, allowing an attacker to manipulate or destroy the database.

### The Vulnerable Code (❌ Never do this)

```python
# DANGEROUS — f-string directly interpolates user input
rows = db.execute(f"SELECT COUNT(*) FROM favorites WHERE problem = '{problem}'")
```

### The Attack

If a user types: `'; DROP TABLE favorites; --`

The resulting query becomes:
```sql
SELECT COUNT(*) FROM favorites WHERE problem = ''; DROP TABLE favorites; --'
```

The `--` comments out the rest of the original query. The database happily executes the `DROP TABLE`, **deleting all your data**.

### Simpler Login Bypass

Attacker enters username: `malan@harvard.edu'--`

Query becomes:
```sql
SELECT * FROM users WHERE username = 'malan@harvard.edu'--' AND password = '...'
```

Everything after `--` is commented out — the password check is **skipped entirely**.

### The Fix (✅ Always do this)

```python
# SAFE — use ? placeholder; the library handles escaping
rows = db.execute(
    "SELECT COUNT(*) FROM favorites WHERE problem = ?",
    problem
)
```

The `?` placeholder causes the library to:
1. Wrap the input in quotes
2. Escape any dangerous characters (like `'` → `''`)
3. Ensure the input is treated as **data**, never as **code**

> **Golden rule:** Never concatenate user input directly into a SQL string. Always use placeholders.

---

## 🏁 Race Conditions and Transactions

### The Problem

When multiple users interact with a database simultaneously, a **race condition** can cause data corruption.

**The Milk Analogy:** Two roommates both check the fridge, both see no milk, both go to the store, both come back with milk. Result: too much milk. Neither knew the other was already solving the problem.

### Real-World Example — Instagram Likes

```python
# Server A and Server B both run this code at the same time

# Step 1: Read current likes
rows = db.execute("SELECT likes FROM posts WHERE id = ?", post_id)
likes = rows[0]["likes"]        # Both servers read: 100 likes

# Step 2: Update
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, post_id)
# Server A writes: 101
# Server B writes: 101  ← should be 102!
```

Both servers read `100`, both add `1`, both write `101`. **One like is permanently lost.**

### The Solution — Transactions

```python
db.execute("BEGIN TRANSACTION")

rows = db.execute("SELECT likes FROM posts WHERE id = ?", post_id)
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, post_id)

db.execute("COMMIT")
```

- `BEGIN TRANSACTION` — lock the relevant rows
- `COMMIT` — finalize and save all changes atomically
- `ROLLBACK` — undo everything if something goes wrong

**Transactions guarantee** that a group of queries either all succeed together or all fail together — they will never be partially applied.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Flat file / CSV** | Data stored as plain text with comma (or other) delimiters |
| **`csv.reader`** | Reads rows as lists; numeric index access; must skip header manually |
| **`csv.DictReader`** | Reads rows as dicts; access by column name; header auto-consumed |
| **Declarative language** | You declare *what* you want; SQL figures out *how* |
| **Relational database** | Data stored in tables with defined relationships across them |
| **SQLite** | Lightweight, file-based SQL database (`*.db`) |
| **CRUD** | Create (INSERT), Read (SELECT), Update (UPDATE), Delete (DELETE) |
| **`SELECT`** | Read data; `SELECT *` = all columns |
| **`WHERE`** | Filter rows by condition |
| **`LIKE`** | Pattern matching with `%` wildcard; case-insensitive |
| **`ORDER BY`** | Sort results; add `DESC` for descending |
| **`LIMIT`** | Cap the number of returned rows |
| **`GROUP BY`** | Aggregate rows by identical values; use with `COUNT`, `AVG`, etc. |
| **`AS`** | Alias a column name in results |
| **`INSERT INTO`** | Add new rows to a table |
| **`UPDATE`** | Modify existing rows; always use `WHERE` |
| **`DELETE`** | Remove rows; always use `WHERE` |
| **`DROP TABLE`** | Permanently delete a table and all its data |
| **`NULL`** | Explicit absence of data; use `IS NULL` / `IS NOT NULL` |
| **`NOT NULL`** | Column constraint — value can never be null |
| **`UNIQUE`** | Column constraint — no duplicate values allowed |
| **Primary key** | Unique identifier for every row in a table (usually `id INTEGER`) |
| **Foreign key** | A primary key from another table, used for cross-referencing |
| **1-to-1** | One row in A maps to exactly one row in B |
| **1-to-Many** | One row in A maps to multiple rows in B |
| **Many-to-Many** | Multiple rows in A map to multiple rows in B; needs junction table |
| **`JOIN`** | Merge two tables by matching a primary key with a foreign key |
| **Nested query** | A `SELECT` inside another `SELECT`; evaluated inside-out |
| **Index** | Pre-built tree structure on a column; dramatically speeds up search |
| **B-tree** | Balanced tree used internally by SQL indexes; enables O(log n) lookup |
| **SQL injection** | Attack that inserts malicious SQL through unsanitized user input |
| **`?` placeholder** | The safe way to insert user input into SQL queries |
| **Race condition** | Two processes read/write shared data simultaneously, causing corruption |
| **Transaction** | Group of queries that either all succeed or all fail; prevents race conditions |
| **`BEGIN TRANSACTION`** | Start a transaction (lock relevant rows) |
| **`COMMIT`** | Finalize and save all changes in a transaction |
| **`ROLLBACK`** | Undo all changes in a transaction |

---

## 🗂️ Problem Set 7

Use SQL to answer questions about real-world datasets including movies, TV shows, and more:
[cs50.harvard.edu/x/2026/psets/7](https://cs50.harvard.edu/x/2026/psets/7/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 6 – Python](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%206%20-%20Python) |
| ➡️ Next | [Artificial Intelligence](https://github.com/Nilanchal0107/CS50x/tree/main/Artificial%20Intelligence) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 7 - SQL`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%207%20-%20SQL)
