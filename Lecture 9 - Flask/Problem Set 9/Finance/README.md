# 💰 CS50x Week 9 — C$50 Finance

![Python](https://img.shields.io/badge/Python-3.13-blue)
![Flask](https://img.shields.io/badge/Flask-Web_Framework-lightgrey)
![SQLite](https://img.shields.io/badge/SQLite-Database-orange)
![Bootstrap](https://img.shields.io/badge/Bootstrap-5.3-purple)

A full-stack web application that lets users register, log in, look up real stock prices, and simulate buying and selling shares — built with Flask, SQLite, and Jinja2 templates.

---

## 📁 Project Structure

```
finance/
├── app.py              ← All Flask routes and business logic
├── helpers.py          ← lookup(), apology(), login_required(), usd()
├── finance.db          ← SQLite database (users + transactions)
├── schema.sql          ← SQL to create the transactions table
├── requirements.txt    ← Python packages needed
├── static/
│   └── styles.css      ← Custom CSS
└── templates/
    ├── layout.html     ← Base template (navbar, flash messages)
    ├── login.html      ← Login form
    ├── register.html   ← Registration form
    ├── index.html      ← Portfolio overview (homepage)
    ├── quote.html      ← Stock symbol search form
    ├── quoted.html     ← Stock price result
    ├── buy.html        ← Buy shares form
    ├── sell.html       ← Sell shares form (dropdown)
    ├── history.html    ← All transactions ever made
    ├── addcash.html    ← Personal touch: deposit cash
    └── apology.html    ← Error page (meme-style)
```

---

## 🚀 How to Run

```bash
# 1. Navigate into the finance folder
cd finance

# 2. Create the transactions table (first time only)
sqlite3 finance.db < schema.sql

# 3. Start the Flask development server
flask run
```

---

## 🗄️ Database Schema

### `users` table (provided by CS50)
```sql
CREATE TABLE users (
    id       INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT    NOT NULL,
    hash     TEXT    NOT NULL,          -- hashed password
    cash     NUMERIC NOT NULL DEFAULT 10000.00
);
```

### `transactions` table (created by us)
```sql
CREATE TABLE transactions (
    id        INTEGER  PRIMARY KEY AUTOINCREMENT,
    user_id   INTEGER  NOT NULL,
    symbol    TEXT     NOT NULL,
    shares    INTEGER  NOT NULL,        -- positive = buy, negative = sell
    price     REAL     NOT NULL,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

**Key design decision:** We store sells as **negative shares** instead of a separate `type` column.

```
Buy  5 shares of AAPL → shares = +5
Sell 2 shares of AAPL → shares = -2
SUM(shares) = 3       → currently owns 3 shares
```

This means the history page is free — just `SELECT *` from transactions. No redundant data.

---

## 🧠 Core Concepts Explained

### 1. Flask — Web Framework

Flask is a lightweight Python web framework. It maps URLs to Python functions called **routes**.

```python
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        # handle form submission
    return render_template("buy.html")
```

- **GET** request → user visits the page → show the form
- **POST** request → user submits the form → process the data

Every route follows this pattern:

```
User visits URL → Flask calls the function → Function returns HTML
```

---

### 2. Session — Remembering Who Is Logged In

HTTP is stateless — every request is independent. Flask uses **sessions** to remember who is logged in across requests.

```python
# On login — save user's id
session["user_id"] = rows[0]["id"]

# On any other route — read who is logged in
user_id = session["user_id"]

# On logout — forget everything
session.clear()
```

Sessions are stored on the server's filesystem (not in cookies), configured via:
```python
app.config["SESSION_TYPE"] = "filesystem"
```

---

### 3. Password Hashing — Security

We never store plain passwords. We store a **hash** — a one-way scrambled version.

```python
# On register — hash before saving
generate_password_hash("abc123")
# → "pbkdf2:sha256:600000$xyz..." (long scrambled string)

# On login — compare typed password to stored hash
check_password_hash(stored_hash, typed_password)
# → True or False
```

Even if someone steals the database, they cannot reverse a hash back to the original password.

---

### 4. SQL with CS50's `db.execute()`

CS50's library wraps SQLite with a safe `execute()` method.

```python
# SELECT — returns a list of dicts
rows = db.execute("SELECT * FROM users WHERE id = ?", user_id)
cash = rows[0]["cash"]  # access like a dictionary

# INSERT — returns the new row's id
db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
           user_id, symbol, shares, price)

# UPDATE — modifies existing rows
db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", cost, user_id)
```

**Always use `?` placeholders** — never use f-strings or concatenation in SQL. This prevents SQL injection attacks:

```python
# ❌ DANGEROUS — SQL injection risk
db.execute(f"SELECT * FROM users WHERE username = '{username}'")

# ✅ SAFE — parameterised query
db.execute("SELECT * FROM users WHERE username = ?", username)
```

---

### 5. Jinja2 — Templates

Jinja2 is Flask's templating engine. It lets you embed Python logic inside HTML.

```html
<!-- Loop through a list -->
{% for stock in portfolio %}
<tr>
    <td>{{ stock.symbol }}</td>
    <td>{{ stock.price | usd }}</td>   <!-- | usd formats as $123.45 -->
</tr>
{% endfor %}

<!-- Conditional -->
{% if tx.shares > 0 %}
    Buy
{% else %}
    Sell
{% endif %}

<!-- Template inheritance — extend layout.html -->
{% extends "layout.html" %}
{% block main %}
    <!-- your page content here -->
{% endblock %}
```

`| usd` is a custom Jinja **filter** registered in `app.py`:
```python
app.jinja_env.filters["usd"] = usd
# Now {{ 1234.56 | usd }} → "$1,234.56"
```

---

### 6. `lookup()` — Stock API

The `lookup()` function in `helpers.py` calls the CS50 Finance API and returns:

```python
lookup("AAPL")
# → {"name": "Apple Inc.", "price": 189.50, "symbol": "AAPL"}
# → None if symbol doesn't exist
```

Always check for `None`:
```python
quote = lookup(symbol)
if not quote:
    return apology("invalid symbol", 400)
```

---

### 7. `@login_required` Decorator

This decorator protects routes from unauthenticated access. If a user tries to visit `/buy` without being logged in, they're redirected to `/login`.

```python
@app.route("/buy", methods=["GET", "POST"])
@login_required   # ← this runs first, before buy()
def buy():
    ...
```

Defined in `helpers.py` — it checks if `session["user_id"]` exists.

---

### 8. Flash Messages

Flask's `flash()` sends a one-time message that appears on the next page.

```python
# In app.py — send a message
flash("Bought 5 share(s) of AAPL!")
return redirect("/")
```

```html
<!-- In layout.html — display it -->
{% if get_flashed_messages() %}
    <div class="alert alert-primary">
        {{ get_flashed_messages() | join(" ") }}
    </div>
{% endif %}
```

The message disappears after being shown once.

---

### 9. Form Validation — Client vs Server

HTML gives us basic client-side validation:
```html
<input type="number" min="1" name="shares">
```

But savvy users can bypass this. We always validate **server-side** too:

```python
try:
    shares = int(shares)   # rejects "abc" and "1.5"
    if shares <= 0:        # rejects 0 and negatives
        raise ValueError
except (ValueError, TypeError):
    return apology("shares must be a positive integer", 400)
```

---

### 10. Portfolio Calculation (index route)

```python
# Get all current holdings using SUM
holdings = db.execute("""
    SELECT symbol, SUM(shares) AS total_shares
    FROM transactions
    WHERE user_id = ?
    GROUP BY symbol
    HAVING total_shares > 0
""", user_id)

# For each holding, look up live price
for h in holdings:
    quote = lookup(h["symbol"])
    value = h["total_shares"] * quote["price"]
    stock_total += value

grand_total = stock_total + cash
```

`GROUP BY symbol` groups all transactions for the same stock together.
`SUM(shares)` adds +5 and -2 to get 3 (current holdings).
`HAVING total_shares > 0` hides stocks that have been fully sold.

---

## 📋 Routes Summary

| Route | Method | Description |
|---|---|---|
| `/` | GET | Portfolio overview |
| `/register` | GET, POST | Create new account |
| `/login` | GET, POST | Log in |
| `/logout` | GET | Log out |
| `/quote` | GET, POST | Look up stock price |
| `/buy` | GET, POST | Buy shares |
| `/sell` | GET, POST | Sell shares |
| `/history` | GET | All transactions |
| `/addcash` | GET, POST | Add cash (personal touch) |

---

## ✅ Personal Touch

**Add Cash** — Users can deposit additional cash into their account via `/addcash`. This updates the `cash` column in the `users` table directly.

---

## 🧪 Testing Checklist

- [ ] Register a new user
- [ ] Log in and verify $10,000 starting cash
- [ ] Look up a valid stock symbol (e.g. `AAPL`)
- [ ] Look up an invalid symbol — should show apology
- [ ] Buy shares and verify portfolio updates
- [ ] Buy more shares of the same stock — verify totals add up
- [ ] Try to buy more than you can afford — should show apology
- [ ] Sell shares and verify cash increases
- [ ] Try to sell more shares than you own — should show apology
- [ ] Check history shows all transactions correctly
- [ ] Add cash via personal touch feature
- [ ] Try typing letters in the shares field — should show apology
- [ ] Try typing a negative number in shares — should show apology
