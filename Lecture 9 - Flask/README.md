# 🐍 CS50x – Week 9: Flask
### Harvard University's Introduction to Web Applications, Server-Side Programming, and Full-Stack Development

> *"This week is the most representative of what you'll be doing after the class if you so choose to program in the future. The goal is to really synthesize the past 10 weeks of class, drawing upon the building blocks that are hopefully now in your toolbox."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Python](https://img.shields.io/badge/Language-Python-blue?style=flat-square&logo=python)](https://www.python.org/)
[![Flask](https://img.shields.io/badge/Framework-Flask-black?style=flat-square&logo=flask)](https://flask.palletsprojects.com/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=am7POvSZ4GE)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 9](https://www.youtube.com/watch?v=am7POvSZ4GE) |
| 📝 Official Notes | [cs50.harvard.edu/x/notes/9](https://cs50.harvard.edu/x/notes/9/) |
| 📖 Flask Docs | [flask.palletsprojects.com](https://flask.palletsprojects.com/) |
| 🏗️ Jinja2 Docs | [jinja.palletsprojects.com](https://jinja.palletsprojects.com/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 9 | [cs50.harvard.edu/x/2026/psets/9](https://cs50.harvard.edu/x/2026/psets/9/) |

---

## 📋 Table of Contents

1. [From Static to Dynamic — Why Flask?](#-from-static-to-dynamic--why-flask)
2. [Routes vs. File Paths](#-routes-vs-file-paths)
3. [Flask — Getting Started](#-flask--getting-started)
4. [Project Structure](#-project-structure)
5. [Your First Flask App](#-your-first-flask-app)
6. [Returning HTML from Flask](#-returning-html-from-flask)
7. [render_template — Using HTML Files](#-render_template--using-html-files)
8. [Jinja2 — Templating Language](#-jinja2--templating-language)
9. [HTTP Parameters with request.args](#-http-parameters-with-requestargs)
10. [Multiple Routes](#-multiple-routes)
11. [GET vs. POST in Flask](#-get-vs-post-in-flask)
12. [Template Inheritance — layout.html](#-template-inheritance--layouthtml)
13. [Jinja2 Conditionals and Loops](#-jinja2-conditionals-and-loops)
14. [Building a Registration Form](#-building-a-registration-form)
15. [Server-Side Validation](#-server-side-validation)
16. [Storing Data — From Memory to Database](#-storing-data--from-memory-to-database)
17. [SQL in Flask with CS50 Library](#-sql-in-flask-with-cs50-library)
18. [redirect() — Sending Users Elsewhere](#-redirect--sending-users-elsewhere)
19. [Static Files — Images, CSS, JS](#-static-files--images-css-js)
20. [HTML Select Menus and Radio Buttons](#-html-select-menus-and-radio-buttons)
21. [Checkboxes — Multiple Selections](#-checkboxes--multiple-selections)
22. [Custom Error Pages](#-custom-error-pages)
23. [Cookies and Sessions](#-cookies-and-sessions)
24. [Implementing Login / Logout](#-implementing-login--logout)
25. [Shopping Cart with Sessions](#-shopping-cart-with-sessions)
26. [APIs and JSON](#-apis-and-json)
27. [MVC — Model View Controller](#-mvc--model-view-controller)
28. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🔄 From Static to Dynamic — Why Flask?

Last week, you ran `http-server` to serve **static** files — HTML, CSS, images that just sit on disk and never change. This works fine for simple pages, but real web apps need to:

- **Accept user input** (forms, searches, logins)
- **Query a database** to get or store data
- **Generate different HTML** depending on who is asking and what they asked for
- **Maintain state** across multiple page visits (sessions, shopping carts)

Writing all this from scratch in Python would require thousands of lines of low-level networking code. Instead, we use a **framework** — a library with conventions — that handles the commodity stuff so you can focus on your actual problem.

> **Framework vs. Library:** A library is code you call. A framework is code that calls *you* — you follow its conventions and it handles the underlying plumbing.

---

## 🗺️ Routes vs. File Paths

Last week, URLs mapped directly to files:

```
example.com/index.html   → serves index.html
example.com/about.html   → serves about.html
```

With Flask, URLs map to **routes** — named paths you define in Python code:

```
example.com/             → runs your index() function
example.com/search       → runs your search() function
example.com/register     → runs your register() function
```

The route is not a file — it's a label for a piece of logic. Query parameters still use `?key=value`:

```
example.com/search?q=cats
```

---

## 🚀 Flask — Getting Started

### Installation

```bash
pip install flask
```

### Running a Flask App

```bash
flask run
```

Flask defaults to **port 5000** (vs. `http-server`'s port 8080). It looks for `app.py` in the current directory.

### requirements.txt

A plain text file listing all the libraries your project needs (one per line):

```
flask
flask-session
cs50
```

Install everything at once:

```bash
pip install -r requirements.txt
```

---

## 🗂️ Project Structure

A standard Flask project looks like this:

```
my_project/
├── app.py              ← your Python logic (the controller)
├── requirements.txt    ← library dependencies
├── static/             ← unchanging files (images, CSS, JS)
│   └── cat.jpeg
└── templates/          ← HTML blueprints (Jinja2 templates)
    ├── layout.html
    ├── index.html
    └── greet.html
```

- `app.py` — all your Python/Flask code
- `templates/` — Flask knows to look here automatically; **do not** include the folder name in `render_template()`
- `static/` — images, CSS, JS files that do not change; reference them with `/static/filename` in HTML

---

## 🏗️ Your First Flask App

**app.py:**

```python
from flask import Flask

app = Flask(__name__)  # turn this file into a Flask app

@app.route("/")        # associate this function with the "/" route
def index():
    return "Hello, world!"
```

### Key Concepts

| Syntax | Meaning |
|--------|---------|
| `from flask import Flask` | Import the Flask class |
| `app = Flask(__name__)` | Create the Flask application object; `__name__` = current file |
| `@app.route("/")` | A **decorator** — tells Flask: "call the next function when `/` is visited" |
| `def index():` | The function name can be anything (by convention matches the route) |
| `return "Hello, world!"` | Whatever you return is sent to the browser |

> **Decorator:** A special Python syntax (`@something`) placed above a function that modifies its behavior. `@app.route("/")` tells Flask to associate the `/` URL with whatever function follows.

---

## 📄 Returning HTML from Flask

You can return raw HTML strings, but it's messy:

```python
@app.route("/")
def index():
    return '<!DOCTYPE html><html lang="en"><head><title>Hello</title></head><body>Hello, world!</body></html>'
```

This works but becomes unmanageable quickly. The solution is **render_template**.

---

## 📐 render_template — Using HTML Files

Store your HTML in the `templates/` folder and render it from Python:

**templates/index.html:**
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Hello</title>
    </head>
    <body>
        Hello, world!
    </body>
</html>
```

**app.py:**
```python
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")  # Flask looks in templates/ automatically
```

---

## 🔧 Jinja2 — Templating Language

Flask uses **Jinja2** — a templating engine that lets you embed variables and logic inside HTML files.

### Variable Interpolation

```html
<!-- templates/greet.html -->
<body>
    Hello, {{ name }}!
</body>
```

```python
# app.py
return render_template("greet.html", name="David")
```

Output: `Hello, David!`

### Jinja2 vs. Other Interpolation Syntax

| Language | Syntax | Example |
|----------|--------|---------|
| Python f-string | `f"Hello, {name}"` | `f"Hello, {name}"` |
| C printf | `%s` | `printf("Hello, %s", name)` |
| Jinja2 (Flask) | `{{ variable }}` | `Hello, {{ name }}` |
| Jinja2 tags | `{% tag %}` | `{% if name %}` |

The `{{ }}` double curly braces tell Jinja2: "substitute the value of this variable here."
The `{% %}` curly-brace-percent tells Jinja2: "this is a control structure (if, for, block)."

---

## 🔍 HTTP Parameters with request.args

Flask gives you a global `request` object that contains everything about the incoming HTTP request.

For **GET** requests, parameters come from the URL (`?name=David`):

```python
from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    # request.args is a dict of URL parameters
    name = request.args.get("name", "world")  # default = "world"
    return render_template("index.html", name=name)
```

| Method | Meaning |
|--------|---------|
| `request.args.get("key")` | Get a URL parameter; returns `None` if missing |
| `request.args.get("key", "default")` | Get a URL parameter with a fallback default |
| `"key" in request.args` | Check if a parameter exists |

> **request.args vs. request.args.get():** Using `request.args["name"]` raises a `KeyError` if `name` is absent. Always use `.get()` with a default to avoid crashes.

---

## 🔀 Multiple Routes

Every `@app.route()` creates a new URL endpoint:

```python
@app.route("/")
def index():
    return render_template("index.html")  # show the form

@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)  # show the greeting
```

**templates/index.html** — the form:
```html
<form action="/greet" method="get">
    <input type="text" name="name" placeholder="Name" autofocus autocomplete="off">
    <button type="submit">Greet</button>
</form>
```

When the form is submitted, the browser goes to `/greet?name=David` and Flask calls `greet()`.

---

## 📤 GET vs. POST in Flask

### GET
- Parameters visible in the URL: `/greet?name=David`
- Bookmarkable, shareable, cacheable
- Use for searches, navigation, anything low-stakes

### POST
- Parameters hidden inside the request body — not in the URL
- Better for passwords, personal info, form submissions that change data
- Use `request.form` instead of `request.args`

```python
# In the HTML form
# <form action="/greet" method="post">

@app.route("/greet", methods=["POST"])  # must explicitly allow POST
def greet():
    name = request.form.get("name", "world")  # request.form for POST
    return render_template("greet.html", name=name)
```

### Key Difference

| | GET | POST |
|--|-----|------|
| Where data lives | URL (`?key=value`) | Request body |
| Visible in browser | ✅ Yes | ❌ No |
| Flask accessor | `request.args` | `request.form` |
| Appropriate for | Searches, navigation | Logins, form submissions |

---

## 🧩 Template Inheritance — layout.html

Repeating the same HTML boilerplate (`<!DOCTYPE>`, `<head>`, `<body>`) in every template is bad design. **Template inheritance** solves this.

**templates/layout.html** — the blueprint:
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>My App</title>
        <meta name="viewport" content="initial-scale=1, width=device-width">
    </head>
    <body>
        {% block body %}{% endblock %}
    </body>
</html>
```

**templates/index.html** — extends the blueprint:
```html
{% extends "layout.html" %}

{% block body %}
    <form action="/" method="post">
        <input name="name" type="text" placeholder="Name">
        <button type="submit">Greet</button>
    </form>
{% endblock %}
```

**templates/greet.html** — also extends:
```html
{% extends "layout.html" %}

{% block body %}
    Hello, {{ name }}!
{% endblock %}
```

### How It Works

1. `{% extends "layout.html" %}` — "use layout.html as my blueprint"
2. `{% block body %}` — "here is what goes into the `body` block"
3. Flask merges them: layout.html + block content = complete HTML page

> **Result:** The boilerplate lives in one place. Each template only defines what's unique about that page. Adding a 4th route only requires one new template, not a full copy of the HTML structure.

---

## 🔁 Jinja2 Conditionals and Loops

Jinja2 supports Python-like logic inside templates:

### Conditionals

```html
{% if name %}
    Hello, {{ name }}!
{% else %}
    Hello, world!
{% endif %}
```

### Loops

```html
<ul>
{% for sport in sports %}
    <li>{{ sport }}</li>
{% endfor %}
</ul>
```

### Loop to Generate Form Options

```html
<select name="sport">
    <option value="" selected>Sport</option>
{% for sport in sports %}
    <option value="{{ sport }}">{{ sport }}</option>
{% endfor %}
</select>
```

Pass the list from Python:
```python
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)
```

---

## 📝 Building a Registration Form

**templates/index.html:**
```html
{% extends "layout.html" %}

{% block body %}
    <h1>Register</h1>
    <form action="/register" method="post">
        <input name="name" type="text" placeholder="Name"
               autofocus autocomplete="off">
        <select name="sport">
            <option value="" selected>Sport</option>
            {% for sport in sports %}
                <option value="{{ sport }}">{{ sport }}</option>
            {% endfor %}
        </select>
        <button type="submit">Register</button>
    </form>
{% endblock %}
```

**app.py:**
```python
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    # ... validation and storage
```

---

## 🛡️ Server-Side Validation

**Never trust user input.** HTML validation (`pattern`, `required`, `type="email"`) can be disabled in seconds using browser developer tools. Always validate on the server too.

```python
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")

    if not name:
        return render_template("error.html", message="Missing name")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:                  # ← server-side check
        return render_template("error.html", message="Invalid sport")

    # ... registration logic
```

### Why `sport not in SPORTS`?

A user can open developer tools and add a new `<option value="volleyball">Volleyball</option>` to your HTML, then submit volleyball as their sport. Your `SPORTS` list only lives server-side — it cannot be tampered with. Always check against that authoritative list.

### Global Constants

```python
# All caps signals: this is a global constant — do not modify at runtime
SPORTS = ["Basketball", "Soccer", "Ultimate Frisbee"]
```

Python has no true `const` keyword, but ALL_CAPS is the community convention for values that should not change.

---

## 💾 Storing Data — From Memory to Database

### Approach 1 — Python Dictionary (Volatile ❌)

```python
# Stored in RAM — lost when server restarts
registrants = {}

@app.route("/register", methods=["POST"])
def register():
    registrants[name] = sport   # gone after ctrl+C
```

**Problem:** Every time the Flask server stops (crashes, updates, restarts), all data is gone.

### Approach 2 — SQLite Database (Persistent ✅)

```python
from cs50 import SQL

db = SQL("sqlite:///froshims.db")  # opens/creates froshims.db

@app.route("/register", methods=["POST"])
def register():
    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)
```

The database file persists on disk — restarting Flask does not erase it.

---

## 🗄️ SQL in Flask with CS50 Library

```python
from cs50 import SQL

db = SQL("sqlite:///froshims.db")
```

### Common Operations

```python
# INSERT — add a row
db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)

# SELECT — get rows (returns list of dicts)
registrants = db.execute("SELECT * FROM registrants")

# SELECT with WHERE
rows = db.execute("SELECT * FROM registrants WHERE name = ?", name)

# DELETE
db.execute("DELETE FROM registrants WHERE id = ?", id)
```

### Key Rule — Always Use `?` Placeholders

```python
# ❌ NEVER — SQL injection vulnerability
db.execute(f"SELECT * FROM users WHERE name = '{name}'")

# ✅ ALWAYS — library sanitizes the input
db.execute("SELECT * FROM users WHERE name = ?", name)
```

The `?` placeholder causes the library to escape any dangerous characters (apostrophes, semicolons) so user input cannot be interpreted as SQL code.

---

## 🔀 redirect() — Sending Users Elsewhere

After a successful form submission, instead of showing a success page, redirect the user to another route:

```python
from flask import Flask, redirect, render_template, request

@app.route("/register", methods=["POST"])
def register():
    # ... validation and database insert

    return redirect("/registrants")  # send user to a different route
```

This triggers the browser to make a new GET request to `/registrants`, which in turn renders the registrants list. The URL in the browser bar updates to `/registrants`.

> **Why redirect after POST?** If the user reloads the page after a POST, the browser will resubmit the form — potentially inserting duplicate data. Redirecting to a GET route prevents this (the "Post/Redirect/Get" pattern).

---

## 📁 Static Files — Images, CSS, JS

Any file that doesn't change (images, CSS, JavaScript) belongs in the `static/` folder:

```
my_project/
├── static/
│   ├── cat.jpeg
│   ├── styles.css
│   └── script.js
```

Reference them in HTML with `/static/filename`:

```html
<img src="/static/cat.jpeg" alt="Grumpy cat">
<link href="/static/styles.css" rel="stylesheet">
<script src="/static/script.js"></script>
```

> **Why `static/`?** Flask routes all requests starting with `/static/` directly to this folder, bypassing your Python logic entirely. This makes serving images and CSS fast and simple.

---

## 🎛️ HTML Select Menus and Radio Buttons

### Select Menu (Drop-down)

```html
<select name="sport">
    <option value="" selected>Sport</option>  <!-- default blank -->
    <option value="Basketball">Basketball</option>
    <option value="Soccer">Soccer</option>
</select>
```

Or dynamically with Jinja2:
```html
<select name="sport">
    <option value="" selected>Sport</option>
    {% for sport in sports %}
        <option value="{{ sport }}">{{ sport }}</option>
    {% endfor %}
</select>
```

### Radio Buttons (Mutually Exclusive)

```html
{% for sport in sports %}
    <input type="radio" name="sport" value="{{ sport }}"> {{ sport }}
{% endfor %}
```

Same `name` attribute on all radio inputs → browser enforces mutual exclusivity (only one can be selected).

**Both give the same data server-side:** `request.form.get("sport")` works for either.

---

## ☑️ Checkboxes — Multiple Selections

```html
{% for sport in sports %}
    <input type="checkbox" name="sport" value="{{ sport }}"> {{ sport }}
{% endfor %}
```

On the server, use `getlist()` instead of `get()` to receive all checked values:

```python
sports = request.form.getlist("sport")  # returns a list: ["Basketball", "Soccer"]
```

Validate and insert each sport individually:

```python
for sport in sports:
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

for sport in sports:
    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)
```

| Method | Returns | Use when |
|--------|---------|----------|
| `request.form.get("sport")` | Single string | Radio buttons / select menus |
| `request.form.getlist("sport")` | List of strings | Checkboxes |

---

## ⚠️ Custom Error Pages

Instead of a generic "you are not registered," give users specific, helpful error messages:

**templates/error.html:**
```html
{% extends "layout.html" %}

{% block body %}
    <h1>Error</h1>
    <p>{{ message }}</p>
{% endblock %}
```

**app.py:**
```python
if not name:
    return render_template("error.html", message="Missing name")
if not sport:
    return render_template("error.html", message="Missing sport")
if sport not in SPORTS:
    return render_template("error.html", message="Invalid sport")
```

---

## 🍪 Cookies and Sessions

### The Problem — HTTP is Stateless

HTTP doesn't remember you between requests. Every request is treated as brand new. But Gmail remembers you're logged in. How?

### Cookies

A **cookie** is a small key-value pair that a server plants in your browser. The browser sends it back automatically with every future request to that server — like a hand stamp at a club.

```
Server → Browser:   Set-Cookie: session=abc123
Browser → Server:   Cookie: session=abc123  (on every future request)
```

Cookies enable the **illusion of a persistent connection** even though HTTP is stateless.

### Sessions in Flask

Flask wraps cookies into a higher-level concept called a **session** — a per-user dictionary you can read and write from Python:

```python
from flask import session
from flask_session import Session

# Required configuration
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)
```

```python
# Store a value (like logging a user in)
session["name"] = "David"

# Read a value
name = session.get("name")     # returns None if not set

# Delete everything (like logging out)
session.clear()
```

Flask creates a **separate copy of `session`** for every user. You write to it like a normal Python dict; Flask handles the cookie plumbing automatically.

### Cookie Best Practices

- ❌ **Never** store passwords or sensitive data directly in a cookie
- ✅ Store only a random session ID in the cookie; keep the actual data server-side
- ✅ Use HTTPS so cookies can't be intercepted in transit
- ✅ Use `session.clear()` on logout to invalidate the session

---

## 🔐 Implementing Login / Logout

**app.py:**
```python
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    name = session.get("name")
    return render_template("index.html", name=name)

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")  # store name in session
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
    session.clear()   # wipe the session → user is now logged out
    return redirect("/")
```

**templates/index.html:**
```html
{% extends "layout.html" %}

{% block body %}
    {% if name %}
        You are logged in as {{ name }}. <a href="/logout">Log out</a>
    {% else %}
        You are not logged in. <a href="/login">Log in</a>
    {% endif %}
{% endblock %}
```

**templates/login.html:**
```html
{% extends "layout.html" %}

{% block body %}
    <form action="/login" method="post">
        <input name="name" type="text" placeholder="Name" autofocus>
        <button type="submit">Log In</button>
    </form>
{% endblock %}
```

---

## 🛒 Shopping Cart with Sessions

Sessions are perfect for per-user shopping carts:

```python
@app.route("/cart", methods=["GET", "POST"])
def cart():
    if "cart" not in session:
        session["cart"] = []           # initialize empty cart

    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id) # add book ID to cart
        return redirect("/cart")

    # GET — show the cart
    books = db.execute(
        "SELECT * FROM books WHERE id IN (?)",
        session["cart"]
    )
    return render_template("cart.html", books=books)
```

**Key idea:** `session["cart"]` is a list that persists across page loads for each specific user, implemented under the hood with cookies.

---

## 🌐 APIs and JSON

Instead of returning a full HTML page, a route can return raw **JSON data** — making it an API endpoint that any front-end (your own JavaScript, a mobile app, a third-party service) can call.

### What is JSON?

**JavaScript Object Notation** — a text format for structured data:

```json
[
    {"id": 1, "title": "The Hitchhiker's Guide to the Galaxy"},
    {"id": 2, "title": "The Restaurant at the End of the Universe"}
]
```

- `[...]` = list / array
- `{...}` = dict / object
- Looks like Python, but it's language-neutral

### Returning JSON from Flask

```python
from flask import jsonify

@app.route("/search")
def search():
    q = request.args.get("q", "")
    shows = db.execute(
        "SELECT * FROM shows WHERE title LIKE ?",
        "%" + q + "%"
    )
    return jsonify(shows)  # converts Python list of dicts → JSON response
```

Any caller (browser, mobile app, JavaScript) can now fetch `/search?q=office` and get structured data back, not HTML.

### Dynamic Search with JavaScript + Flask API

```javascript
// Client-side JS listens for keystrokes
document.querySelector("input").addEventListener("keyup", async function() {
    let response = await fetch("/search?q=" + this.value);
    let shows = await response.json();
    // dynamically update the page with the results
});
```

The browser sends a GET request to `/search?q=<typed text>` every keystroke; Flask returns JSON; JavaScript updates the page — no full page reload needed.

---

## 🏗️ MVC — Model View Controller

The architecture you've been building follows the **MVC paradigm**, a standard way of thinking about web application structure:

```
┌──────────┐     requests      ┌────────────┐     queries    ┌────────┐
│          │ ────────────────► │            │ ─────────────► │        │
│   User   │                  │ Controller │                 │ Model  │
│          │ ◄──────────────── │  (app.py)  │ ◄───────────── │ (.db)  │
└──────────┘     responses     └────────────┘     results    └────────┘
                                     │
                              renders│
                                     ▼
                              ┌────────────┐
                              │    View    │
                              │(templates/)│
                              └────────────┘
```

| Layer | What it is | In Flask |
|-------|-----------|----------|
| **Model** | Persistent data storage | `froshims.db`, SQLite tables |
| **View** | What the user sees | `templates/` — Jinja2 HTML files |
| **Controller** | Business logic | `app.py` — routes, functions, conditionals |

The lines between layers aren't perfectly clean (Jinja2 templates have loops/conditionals), but MVC is a useful mental model for organizing your thinking when building any web app.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Flask** | Python micro-framework for building web applications |
| **Framework** | A library + set of conventions you follow to use it |
| **`flask run`** | Start the Flask development server (port 5000 by default) |
| **`app.py`** | Default filename Flask looks for; contains your route logic |
| **`requirements.txt`** | Lists all library dependencies; install with `pip install -r requirements.txt` |
| **Route** | A URL pattern mapped to a Python function with `@app.route()` |
| **Decorator** | `@app.route("/")` — tells Flask which URL triggers the next function |
| **`render_template()`** | Renders an HTML file from the `templates/` folder |
| **Jinja2** | Templating engine Flask uses; `{{ var }}` for values, `{% %}` for logic |
| **`{{ variable }}`** | Jinja2 variable interpolation — substitutes value into HTML |
| **`{% if %}` / `{% endif %}`** | Jinja2 conditional block |
| **`{% for %}` / `{% endfor %}`** | Jinja2 loop |
| **`{% block body %}` / `{% endblock %}`** | Jinja2 block — placeholder for child template content |
| **`{% extends "layout.html" %}`** | Inherit from a parent template |
| **`layout.html`** | Reusable HTML blueprint — write boilerplate once |
| **Template inheritance** | Factor out repeated HTML; each child only defines what's unique |
| **`request`** | Flask global — contains all info about the incoming HTTP request |
| **`request.args`** | Dict of GET URL parameters (`?key=value`) |
| **`request.form`** | Dict of POST body parameters |
| **`request.form.get("key", default)`** | Safely get a form value with a fallback |
| **`request.form.getlist("key")`** | Get multiple values for one key (e.g. checkboxes) |
| **`request.method`** | `"GET"` or `"POST"` — which verb was used |
| **`methods=["GET", "POST"]`** | Allow multiple HTTP verbs on one route |
| **GET** | URL-visible parameters; use for searches and navigation |
| **POST** | Hidden parameters; use for form submissions that change data |
| **`redirect("/route")`** | Tell browser to make a new GET request to another URL |
| **Post/Redirect/Get** | Pattern to prevent duplicate form submissions on page reload |
| **Global constant** | `SPORTS = [...]` in ALL_CAPS — server-side authoritative list |
| **Server-side validation** | Always validate data in Python; never rely on HTML-only validation |
| **SQL injection** | Attack using malicious user input; prevented with `?` placeholders |
| **`static/` folder** | Unchanging files (images, CSS, JS); reference as `/static/filename` |
| **`<select>` menu** | HTML drop-down; options generated dynamically with Jinja2 loop |
| **Radio buttons** | Mutually exclusive; same `name` → browser enforces one-choice-only |
| **Checkboxes** | Multiple selections; use `request.form.getlist()` server-side |
| **Cookie** | Key-value pair planted by server in browser; sent back automatically |
| **Session** | Per-user Python dictionary backed by cookies; Flask manages it |
| **`session["key"] = value`** | Store data in the user's session |
| **`session.get("key")`** | Read from session; returns `None` if missing |
| **`session.clear()`** | Wipe session — logs the user out |
| **Flask-Session** | Extension storing session data server-side as files |
| **Stateless HTTP** | HTTP has no memory; cookies create the illusion of persistence |
| **API** | Route that returns data (JSON) instead of a full HTML page |
| **JSON** | JavaScript Object Notation — universal data format for APIs |
| **`jsonify()`** | Flask function converting Python list/dict → JSON HTTP response |
| **MVC** | Model-View-Controller — standard web app architecture pattern |
| **Model** | Persistent data storage (SQLite `.db` file) |
| **View** | What users see (`templates/` HTML files) |
| **Controller** | Business logic (`app.py` Python code) |

---

## 🗂️ Problem Set 9

Build your own full-stack web application using Flask, SQL, HTML, CSS, and JavaScript:
[cs50.harvard.edu/x/2026/psets/9](https://cs50.harvard.edu/x/2026/psets/9/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 8 – HTML, CSS, JavaScript](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%208%20-%20HTML%20CSS%20And%20JavaScript) |
| ➡️ Next | [Week 10 – Final](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%2010%20-%20Final) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 9 - Flask`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%209%20-%20Flask)
