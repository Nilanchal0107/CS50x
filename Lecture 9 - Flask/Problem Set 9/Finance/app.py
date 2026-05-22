import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# ─────────────────────────────────────────────────────────────
# REGISTER
# ─────────────────────────────────────────────────────────────
@app.route("/register", methods=["GET", "POST"])
def register():
    """
    GET -> show register.html form
    POST -> validate inputs -> insert user -> log them in -> redirect to /
    """

    # User reached route via POST
    if request.method == "POST":

        # Get form data
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        if not password:
            return apology("must provide password", 400)

        # Ensure confirmation password was submitted
        if not confirmation:
            return apology("must confirm password", 400)

        # Ensure passwords match
        if password != confirmation:
            return apology("passwords must match", 400)

        # Hash password for security
        hash_password = generate_password_hash(password)

        # Insert new user into database
        try:
            user_id = db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)",
                username,
                hash_password
            )

        except ValueError:
            # db.execute raises ValueError if UNIQUE constraint is violated (i.e., username already taken)
            return apology("username already exists", 400)

        # Log the new user in immediately by saving their id in the session
        session["user_id"] = user_id
        flash("Registered successfully! Welcome.")

        # Redirect user to homepage
        return redirect("/")

    # User reached route via GET
    else:
        return render_template("register.html")

# ─────────────────────────────────────────────────────────────
# LOGIN
# ─────────────────────────────────────────────────────────────
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    session.clear() # forget any previous session

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?",
            request.form.get("username")
        )

        # check_password_hash compares the typed password against the stored hash
        # len(rows) != 1 means username not found
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Save user's id in session - this is how we know who is logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

# ─────────────────────────────────────────────────────────────
# LOGOUT
# ─────────────────────────────────────────────────────────────
@app.route("/logout")
def logout():
    """Clear session -> user is now logged out"""
    session.clear()
    return redirect("/")

#─────────────────────────────────────────────────────────────
# INDEX — Portfolio Overview
# ────────────────────────────────────────────────────────────
@app.route("/")
@login_required  # redirects to /login if not logged in
def index():
    """
    Display portfolio table:
        symbol | company | shares | price | total value
    Plus cash balance and grand total at the bottom.
    """

    # Get current logged-in user's ID from session
    user_id = session["user_id"]

    # Get all stocks owned by the user
    # SUM(shares) adds bought and sold shares together
    # HAVING total_shares > 0 ensures only currently owned stocks are shown

    holdings = db.execute("""
        SELECT symbol, SUM(shares) as total_shares
        FROM transactions
        WHERE user_id = ?
        GROUP BY symbol
        HAVING total_shares > 0
    """, user_id)

    # Get user's current cash balance
    cash = db.execute(
        "SELECT cash FROM users WHERE id = ?", user_id
    )[0]["cash"]

    portfolio = []
    stock_total = 0.0

    for h in holdings:
        # lookup() calls the CS50 finance API and returns:
        # { "name": "Apple.Inc.", "price": 189.50, "symbol": "AAPL" }

        quote = lookup(h["symbol"])
        if not quote:
            return apology("could not fetch stock data")

        value = h["total_shares"] * quote["price"]
        stock_total += value

        portfolio.append({
            "symbol": h["symbol"],
            "name": quote["name"],
            "shares": h["total_shares"],
            "price": quote["price"],
            "total": value
        })

    grand_total = stock_total + cash

    return render_template(
        "index.html",
        portfolio=portfolio,
        cash=cash,
        grand_total=grand_total
    )

# ─────────────────────────────────────────────────────────────
# QUOTE
# ─────────────────────────────────────────────────────────────
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """
    GET -> show quote.html (search form)
    POST -> call lookup(symbol) -> show quoted.html with live price
    """

    if request.method == "POST":
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("must provide symbol", 400)

        # Call the stock API
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)

        # quote = {"name": "...", "price": 123.45, "symbol": "AAPL"}
        return render_template("quoted.html", quote=quote)

    return render_template("quote.html")

# ─────────────────────────────────────────────────────────────
# BUY
# ─────────────────────────────────────────────────────────────
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """
    GET -> show buy.html form
    POST -> validate -> check user has enough cash -> record transaction -> update cash
    """
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Validate symbol
        if not symbol:
            return apology("must provide symbol", 400)
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol", 400)

        # Validate shares - must be a positive integer
        # int() raises ValueError if user types "abc" or "1.5"
        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except (ValueError, TypeError):
            return apology("shares must be a positive integer", 400)

        user_id = session["user_id"]
        cost = shares * quote["price"]

        # Check user can afford it
        cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        if cash < cost:
            return apology("cannot afford", 400)

        # Record the purchase in transactions table
        # Positive shares = buy
        db.execute("""
                    INSERT INTO transactions (user_id, symbol, shares, price)
                    VALUES (?, ?, ?, ?)
                   """, user_id, quote["symbol"], shares, quote["price"])

        # Subtract cost from user's cash
        # "cash - ?" is safe SQL parameterisation (no injection risk)

        db.execute(
            "UPDATE users SET cash = cash - ? WHERE id = ?",
            cost, user_id
        )

        flash(f"Bought { shares } share(s) of {quote['symbol']}!")
        return redirect("/")

    return render_template("buy.html")

# ─────────────────────────────────────────────────────────────
# SELL
# ─────────────────────────────────────────────────────────────
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """
    GET -> show sell.html with dropdown of stocks the user owns
    POST -> validate -> check ownership -> record negative transaction -> add proceeds to cash
    """
    user_id = session["user_id"]

    # Fetch holdings for the dropdown menu (needed on both GET and POST)
    holdings = db.execute(
        """
        SELECT symbol,
        SUM(shares) AS total_shares
        FROM transactions
        WHERE user_id = ?
        GROUP BY symbol
        HAVING total_shares > 0
        """, user_id)

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return apology("must select a symbol", 400)

        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except (ValueError, TypeError):
            return apology("shares must be a positive integer", 400)

        # Check user owns enough shares of this stock
        owned = next(
            (h for h in holdings if h["symbol"] == symbol), None
        )
        if not owned or owned["total_shares"] < shares:
            return apology("not enough shares", 400)

        quote = lookup(symbol)
        if not quote:
            return apology("could not fetch stock data", 400)

        proceeds = shares * quote["price"]

        # Record the sale as NEGATIVE shares
        # This is the key design choice - one table handles both buys and sells
        db.execute(
            """
            INSERT INTO transactions (user_id, symbol, shares, price)
            VALUES (?, ?, ?, ?)
            """, user_id, symbol, -shares, quote["price"])

        # Add sale proceeds to cash
        db.execute(
            "UPDATE users SET cash = cash + ? WHERE id = ?",
            proceeds, user_id
        )

        flash(f"Sold {shares} share(s) off {symbol}!")
        return redirect("/")

    return render_template("sell.html", holdings=holdings)

# ─────────────────────────────────────────────────────────────
# HISTORY
# ─────────────────────────────────────────────────────────────
@app.route("/history")
@login_required
def history():
    """
    Show every transaction ever made by the user.
    Positive shares = Buy, Negative shares = Sell.
    Ordered newest first.
    """

    transactions = db.execute(
        """
        SELECT symbol, shares, price, timestamp
        FROM transactions
        WHERE user_id = ?
        ORDER BY timestamp DESC
        """, session["user_id"])

    return render_template("/history.html", transactions=transactions)

# ─────────────────────────────────────────────────────────────
# PERSONAL TOUCH — Add Cash
# ─────────────────────────────────────────────────────────────
@app.route("/addcash", methods=["GET", "POST"])
@login_required
def addcash():
    """Let user deposit additional cash into their account"""
    if request.method == "POST":
        amount = request.form.get("amount")

        try:
            amount = float(amount)
            if amount <= 0:
                raise ValueError
        except (ValueError, TypeError):
            return apology("enter a valid positive amount", 400)

        db.execute(
            "UPDATE users SET cash = cash + ? WHERE id = ?",
            amount, session["user_id"]
        )

        flash(f"Added {usd(amount)} to your account!")
        return redirect("/")

    return render_template("addcash.html")

