# 🌐 CS50x – Week 8: HTML, CSS, JavaScript
### Harvard University's Introduction to the Web, Markup Languages, Styling, and Client-Side Programming

> *"Today and really for the rest of the semester we now transition to using all of the building blocks that we've been accumulating over the past few weeks, but to redeploy them in the context of web apps."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![HTML](https://img.shields.io/badge/Language-HTML5-orange?style=flat-square&logo=html5)](https://developer.mozilla.org/en-US/docs/Web/HTML)
[![CSS](https://img.shields.io/badge/Language-CSS3-blue?style=flat-square&logo=css3)](https://developer.mozilla.org/en-US/docs/Web/CSS)
[![JavaScript](https://img.shields.io/badge/Language-JavaScript-yellow?style=flat-square&logo=javascript)](https://developer.mozilla.org/en-US/docs/Web/JavaScript)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=yYst7puZXjw)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x Week 8](https://www.youtube.com/watch?v=yYst7puZXjw) |
| 📝 Official Notes | [cs50.harvard.edu/x/notes/8](https://cs50.harvard.edu/x/notes/8/) |
| 📖 MDN Web Docs | [developer.mozilla.org](https://developer.mozilla.org/) |
| 🅱️ Bootstrap Docs | [getbootstrap.com](https://getbootstrap.com/) |
| ✅ HTML Validator | [validator.w3.org](https://validator.w3.org/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Problem Set 8 | [cs50.harvard.edu/x/2026/psets/8](https://cs50.harvard.edu/x/2026/psets/8/) |

---

## 📋 Table of Contents

1. [How the Internet Works](#-how-the-internet-works)
2. [IP — Internet Protocol](#-ip--internet-protocol)
3. [TCP — Transmission Control Protocol](#-tcp--transmission-control-protocol)
4. [DNS — Domain Name System](#-dns--domain-name-system)
5. [DHCP — Dynamic Host Configuration Protocol](#-dhcp--dynamic-host-configuration-protocol)
6. [HTTP — HyperText Transfer Protocol](#-http--hypertext-transfer-protocol)
7. [URLs — Anatomy of a Web Address](#-urls--anatomy-of-a-web-address)
8. [HTTP Status Codes](#-http-status-codes)
9. [HTTP Verbs — GET and POST](#-http-verbs--get-and-post)
10. [Browser Developer Tools](#-browser-developer-tools)
11. [HTML — HyperText Markup Language](#-html--hypertext-markup-language)
12. [HTML Tags and Attributes](#-html-tags-and-attributes)
13. [The DOM — Document Object Model](#-the-dom--document-object-model)
14. [Common HTML Tags](#-common-html-tags)
15. [HTML Forms](#-html-forms)
16. [HTTP Parameters in URLs](#-http-parameters-in-urls)
17. [Regular Expressions](#-regular-expressions)
18. [CSS — Cascading Style Sheets](#-css--cascading-style-sheets)
19. [CSS Selectors](#-css-selectors)
20. [CSS Properties](#-css-properties)
21. [CSS Classes and IDs](#-css-classes-and-ids)
22. [External CSS Files](#-external-css-files)
23. [Bootstrap — CSS Framework](#-bootstrap--css-framework)
24. [JavaScript — Basics](#-javascript--basics)
25. [The DOM in JavaScript](#-the-dom-in-javascript)
26. [Events and Event Listeners](#-events-and-event-listeners)
27. [Manipulating CSS with JavaScript](#-manipulating-css-with-javascript)
28. [JavaScript — Practical Examples](#-javascript--practical-examples)
29. [Geolocation API](#-geolocation-api)
30. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🌍 How the Internet Works

The **internet** is a global network of interconnected computers, routers, servers, and devices. It evolved from ARPANET (1969), a U.S. Department of Defense project linking a handful of supercomputers, into the planet-spanning infrastructure we use today.

**Routers** are computers whose sole job is to route data. When you send data from point A to point B, it hops through many routers. The path is not necessarily the shortest — it could be the least congested, least expensive, or just however that network is configured.

Data travels in **packets** — small chunks of information, like envelopes — each labeled with a source and destination address. A large file is split into many packets that may travel different routes and are reassembled at the destination.

```
[Your laptop] ──► [Home Router] ──► [ISP Router] ──► [Internet backbone]
                                                             │
                                                             ▼
                                                    [Destination Server]
```

---

## 📬 IP — Internet Protocol

**IP (Internet Protocol)** gives every device on the internet a unique numeric address, called an **IP address**.

### IPv4

The current dominant standard uses **32-bit** addresses written in dotted decimal notation:

```
192.168.1.1
```

Each of the 4 numbers is 8 bits (0–255), giving **2³² ≈ 4 billion** possible addresses. With billions of devices in the world, we are running out.

### IPv6

The successor uses **128-bit** addresses — astronomically more combinations — but the transition from IPv4 is still ongoing after ~30 years.

### What's in a Packet? (IP Datagram)

```
┌──────────────────────────────────────┐
│  Source IP Address      (e.g. 5.6.7.8)  │
│  Destination IP Address (e.g. 1.2.3.4)  │
│  ... (other metadata fields)            │
│  DATA (the actual content)              │
└──────────────────────────────────────┘
```

IP only ensures addressability. It does not guarantee delivery or order.

---

## 📦 TCP — Transmission Control Protocol

**TCP (Transmission Control Protocol)** solves two problems IP doesn't:

1. **Multiplexing** — How does a single server distinguish between email, web traffic, and video calls all arriving at the same IP?
2. **Reliable delivery** — How does a recipient know if a packet was lost in transit?

### Port Numbers

TCP adds **port numbers** to packets — standardized numbers that identify *which service* is being requested:

| Port | Service |
|------|---------|
| `80` | HTTP (unencrypted web) |
| `443` | HTTPS (encrypted web) |
| `25` | SMTP (email) |
| `8080` | Common developer web server |

When you visit `https://harvard.edu`, your browser sends a packet to port **443** at Harvard's IP. Harvard's server sees port 443 and knows: "this is a web request."

### Sequence Numbers

Large files are split into numbered packets:

```
Packet 1 of 4 ──►
Packet 2 of 4 ──►   ──► reassemble in order
Packet 3 of 4 ──►
Packet 4 of 4 ──►
```

If only 3 of 4 packets arrive, the recipient asks the sender to resend the missing one. This is how TCP **guarantees delivery**.

---

## 🗺️ DNS — Domain Name System

**DNS (Domain Name System)** translates human-readable domain names into IP addresses.

```
"google.com"  ──DNS lookup──►  142.250.80.46
```

Without DNS, you'd have to type `142.250.80.46` into your browser instead of `google.com`.

### How DNS Works (Hierarchically)

```
Your device
    │
    ▼  (asks first)
Local DNS (home router / campus / ISP)
    │  (if unknown, escalates to)
    ▼
Root DNS servers  (know all .com, .edu, .org, etc.)
    │
    ▼
Authoritative DNS server (knows the specific domain)
```

Results are **cached** at each level so the same query isn't repeated every time.

### Fully Qualified Domain Names (FQDNs)

```
https://  www  .  harvard  .  edu
  ↑        ↑         ↑         ↑
scheme  hostname  domain    TLD
```

Common TLDs: `.com`, `.org`, `.edu`, `.gov`, `.net`, `.io`, `.tv`, and hundreds more.

---

## ⚙️ DHCP — Dynamic Host Configuration Protocol

**DHCP** automatically configures every device when it joins a network. It assigns:

- Your device's IP address
- Your local router's IP address
- Your DNS server's IP address

Before DHCP, network admins had to **manually type** IP addresses into every device. Now it happens silently when you connect to Wi-Fi.

---

## 🔁 HTTP — HyperText Transfer Protocol

**HTTP** is the protocol that governs how web browsers request pages and servers respond. It defines what goes *inside* the packets for web communication.

### A Request (Browser → Server)

```
GET / HTTP/2
Host: www.harvard.edu
```

- `GET` — the verb (what action to perform)
- `/` — the path being requested (root = default page)
- `HTTP/2` — protocol version
- `Host` — which domain (useful when one server hosts many sites)

### A Response (Server → Browser)

```
HTTP/2 200 OK
Content-Type: text/html
...
```

- `200` — status code meaning "all is well"
- `Content-Type` — tells the browser what kind of content is coming

### Inspecting HTTP Headers with curl

```bash
curl -I https://www.harvard.edu
```

The `-I` flag fetches only headers (not the page content), letting you see exactly what the server responds with.

---

## 🔗 URLs — Anatomy of a Web Address

```
https://www.example.com/folder/file.html
  ↑        ↑    ↑   ↑        ↑
scheme  host  domain TLD    path
```

| Component | Example | Meaning |
|-----------|---------|---------|
| **Scheme** | `https` | Protocol in use |
| **Hostname** | `www` | Specific server name |
| **Domain** | `example` | The registered name |
| **TLD** | `.com` | Top-level domain |
| **Path** | `/folder/file.html` | Location on the server |

> Visiting `https://harvard.edu/` is equivalent to requesting `index.html` from the root — the browser defaults to the index file if no file is specified.

---

## 🚦 HTTP Status Codes

The server's response always includes a 3-digit **status code**:

| Code | Meaning | Notes |
|------|---------|-------|
| `200` | OK | Request succeeded |
| `301` | Moved Permanently | Go to a new URL (redirect) |
| `302` | Found | Temporary redirect |
| `400` | Bad Request | Client sent something wrong |
| `403` | Forbidden | Server refuses access |
| `404` | Not Found | File/page does not exist |
| `418` | I'm a Teapot | April Fool's joke from 1998 (not real) |
| `500` | Internal Server Error | Bug or crash on the server |

### Real-World Example — The Safety School Trick

```bash
curl -I http://safetyschool.org
```

Returns `301 Moved Permanently` → Location: `http://www.yale.edu`

Someone has been paying to rent `safetyschool.org` for ~20 years just to redirect visitors to Yale. It's all just an HTTP `301` redirect.

---

## 📤 HTTP Verbs — GET and POST

| Verb | Usage | Data Location |
|------|-------|---------------|
| `GET` | Retrieve data (search, navigate) | Appended to URL as `?key=value` |
| `POST` | Submit data (login, forms) | Hidden in the request body |

The verb `GET` is what your browser uses for almost every page you visit. `POST` is used for forms like logins and sign-ups where data shouldn't appear in the URL.

---

## 🔧 Browser Developer Tools

Every modern browser has built-in **developer tools** (right-click → Inspect, or F12):

| Tab | What it shows |
|-----|---------------|
| **Elements** | The HTML structure (DOM) of the page |
| **Console** | JavaScript errors and output |
| **Network** | Every HTTP request/response the browser made |
| **Sources** | JavaScript files loaded by the page |
| **Styles** | CSS rules applied to selected elements |

### Tips

- Hover over elements in the Elements tab to highlight them on the page
- You can **edit HTML and CSS live** — changes are temporary (reload to reset)
- Check the Network tab to see status codes, headers, and timing for every request
- Use Incognito mode + "Disable cache" + "Preserve log" for clean test sessions

---

## 🧱 HTML — HyperText Markup Language

**HTML** is not a programming language — it's a **markup language**. It describes the *structure* and *content* of a web page.

Every modern HTML file begins with:

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

- `<!DOCTYPE html>` — declares this is HTML5
- `<html lang="en">` — root element; `lang` is an attribute
- `<head>` — metadata (title, links, scripts) — not visible on the page
- `<title>` — text shown in the browser tab
- `<body>` — visible content of the page

The browser reads this file **top to bottom, left to right** and builds a tree in memory.

---

## 🏷️ HTML Tags and Attributes

### Elements, Tags, and Attributes

```html
<p class="intro">Hello, world!</p>
↑                              ↑
open tag                   close tag
     ↑
   attribute (key="value")
```

- **Element** = open tag + content + close tag
- **Tag** = `<tagname>` or `</tagname>`
- **Attribute** = key-value pair inside the opening tag (e.g. `class="intro"`, `lang="en"`)

### Self-Closing Tags (Void Elements)

Some tags have no content and don't need a closing tag:

```html
<img src="photo.png" alt="A photo">
<input type="text">
<br>
```

---

## 🌳 The DOM — Document Object Model

When a browser reads HTML, it builds a **tree** in memory called the DOM:

```
Document
    └── html
         ├── head
         │    └── title
         │         └── "Hello"
         └── body
              └── "Hello, world!"
```

- Every tag becomes a **node** in this tree
- JavaScript can read, add, remove, or modify any node at any time
- This is what makes web pages **dynamic and interactive**

---

## 📄 Common HTML Tags

### Text Structure

| Tag | Purpose | Example |
|-----|---------|---------|
| `<h1>` – `<h6>` | Headings (biggest to smallest) | `<h1>Title</h1>` |
| `<p>` | Paragraph | `<p>Some text.</p>` |
| `<br>` | Line break (void) | `Hello<br>World` |
| `<strong>` | Bold (semantic importance) | `<strong>Warning</strong>` |
| `<em>` | Italic (emphasis) | `<em>Note</em>` |

### Layout / Semantic

| Tag | Purpose |
|-----|---------|
| `<div>` | Generic block container (division) |
| `<header>` | Page header — highest SEO priority |
| `<main>` | Primary content |
| `<footer>` | Page footer — lower SEO priority |
| `<section>` | Thematic section of content |
| `<nav>` | Navigation links |

### Lists

```html
<!-- Unordered (bulleted) -->
<ul>
    <li>Python</li>
    <li>C</li>
</ul>

<!-- Ordered (numbered) -->
<ol>
    <li>First</li>
    <li>Second</li>
</ol>
```

### Table

```html
<table>
    <thead>
        <tr>
            <th>Name</th>
            <th>Score</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Alice</td>
            <td>95</td>
        </tr>
    </tbody>
</table>
```

### Media

```html
<!-- Image -->
<img src="photo.png" alt="Description of image">

<!-- Video -->
<video controls muted>
    <source src="video.mp4" type="video/mp4">
</video>
```

### Links (Anchors)

```html
<a href="https://www.harvard.edu">Visit Harvard</a>
```

- `href` — destination URL
- Text between tags — what the user sees and clicks

> ⚠️ **Phishing Warning:** The displayed text and `href` can be completely different. `<a href="https://evil.com">PayPal Login</a>` looks like PayPal but goes elsewhere. Always check the URL in the browser's bottom bar before clicking.

### HTML Entities

Special characters that can't be typed directly:

| Entity | Character | Meaning |
|--------|-----------|---------|
| `&copy;` or `&#169;` | © | Copyright |
| `&amp;` | & | Ampersand |
| `&lt;` | < | Less than |
| `&gt;` | > | Greater than |

---

## 📋 HTML Forms

Forms allow users to submit data to a server:

```html
<form action="https://www.google.com/search" method="get">
    <input
        type="search"
        name="q"
        placeholder="Query"
        autocomplete="off"
        autofocus>
    <input type="submit" value="Google Search">
</form>
```

### Form Attributes

| Attribute | Meaning |
|-----------|---------|
| `action` | URL where form data is sent |
| `method` | HTTP verb — `get` or `post` |

### Input Types

| Type | Renders as |
|------|-----------|
| `text` | Plain text box |
| `search` | Search box (adds clear × button) |
| `email` | Email field (basic validation) |
| `password` | Masked text |
| `submit` | Submit button |
| `checkbox` | Checkbox |
| `radio` | Radio button |

### Useful Input Attributes

| Attribute | Effect |
|-----------|--------|
| `name` | Key used in the HTTP request |
| `placeholder` | Gray hint text |
| `autofocus` | Cursor starts here automatically |
| `autocomplete="off"` | Disables browser autocomplete |
| `required` | Form cannot be submitted if empty |
| `pattern` | Regular expression the value must match |

> ⚠️ **Security note:** HTML validation (like `pattern` or `type="email"`) can be trivially bypassed by editing the page in developer tools. **Never rely on front-end validation alone** — always validate on the server too.

---

## 🔗 HTTP Parameters in URLs

When a form uses `method="get"`, its data is appended to the URL:

```
https://www.google.com/search?q=cats
                              ↑ ↑  ↑
                        path  ? key=value
```

- `?` separates the path from the parameters
- `key=value` is one parameter
- `&` separates multiple parameters: `?q=cats&lang=en`

These are called **HTTP (query) parameters**. You can manually type them in any browser URL bar.

---

## 🔍 Regular Expressions

**Regular expressions (regex)** are patterns used to validate or match text. They work in HTML, Python, JavaScript, and most other languages.

### Common Syntax

| Pattern | Meaning |
|---------|---------|
| `.` | Any single character |
| `*` | 0 or more of the preceding |
| `+` | 1 or more of the preceding |
| `?` | 0 or 1 of the preceding |
| `{n}` | Exactly n times |
| `{n,m}` | Between n and m times |
| `[abc]` | Any of: a, b, or c |
| `[0-9]` | Any digit 0–9 |
| `\d` | Any digit (shorthand) |
| `\D` | Any non-digit |
| `\.` | Literal period (escaped) |

### Email Pattern Example

```html
<input type="text" pattern=".+@.+\.edu" placeholder="Email">
```

This requires: `<anything>@<anything>.edu`

The built-in `type="email"` uses a much more complex regex automatically:

```
^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}...
```

---

## 🎨 CSS — Cascading Style Sheets

**CSS** controls the visual presentation of HTML — colors, fonts, spacing, layout. HTML is the skeleton; CSS is the skin.

The **cascading** in CSS means styles flow *down* from parent elements to their children, allowing you to set a style once on a container and have it apply to everything inside.

### Three Ways to Add CSS

```html
<!-- 1. Inline style attribute (avoid — mixes content and style) -->
<p style="color: red; text-align: center;">Hello</p>

<!-- 2. Style tag in the <head> -->
<head>
    <style>
        p { color: red; }
    </style>
</head>

<!-- 3. External file (preferred) -->
<head>
    <link href="styles.css" rel="stylesheet">
</head>
```

External files are the **best practice** — they separate presentation from content and are reusable across multiple pages.

---

## 🎯 CSS Selectors

A **selector** tells the browser *which elements* to apply styles to:

```css
/* Type selector — targets all <p> tags */
p {
    color: red;
}

/* Class selector — targets elements with class="intro" */
.intro {
    font-size: large;
}

/* ID selector — targets the element with id="title" */
#title {
    text-align: center;
}

/* Pseudo-class — applies only on hover */
a:hover {
    text-decoration: underline;
}
```

| Selector Type | Syntax | Scope |
|---------------|--------|-------|
| **Type** | `p`, `h1`, `body` | All matching tags |
| **Class** | `.classname` | All elements with that class |
| **ID** | `#idname` | One unique element |
| **Pseudo-class** | `a:hover` | State-based (hover, focus, etc.) |

---

## 🖌️ CSS Properties

CSS properties are key-value pairs separated by `:` and terminated with `;`:

```css
selector {
    property: value;
    property: value;
}
```

### Common Properties

| Property | Example | Effect |
|----------|---------|--------|
| `color` | `color: red;` | Text color |
| `background-color` | `background-color: #ff0000;` | Background fill |
| `font-size` | `font-size: large;` | Text size |
| `font-family` | `font-family: Arial;` | Typeface |
| `text-align` | `text-align: center;` | Horizontal alignment |
| `text-decoration` | `text-decoration: none;` | Underline, overline, etc. |
| `margin` | `margin: 20px;` | Space outside the element |
| `padding` | `padding: 10px;` | Space inside the element |
| `border` | `border: 1px solid black;` | Box border |
| `visibility` | `visibility: hidden;` | Show/hide without removing |
| `display` | `display: none;` | Completely remove from layout |

### Colors

```css
/* Named color */
color: red;

/* Hexadecimal RGB */
color: #ff0000;   /* max red, no green, no blue */
color: #00ff00;   /* max green */
color: #0000ff;   /* max blue */

/* RGB function */
color: rgb(255, 0, 0);
```

---

## 🔖 CSS Classes and IDs

### Classes — Reusable Styles

```css
/* styles.css */
.centered  { text-align: center; }
.large     { font-size: large; }
.medium    { font-size: medium; }
.small     { font-size: small; }
```

```html
<!-- Apply multiple classes with space-separated values -->
<header class="centered large">John Harvard</header>
<main   class="centered medium">Welcome to my homepage.</main>
<footer class="centered small">&copy; John Harvard</footer>
```

### IDs — Unique Identifiers

```css
#harvard {
    color: crimson;
}
```

```html
<a id="harvard" href="https://www.harvard.edu">Harvard</a>
```

- A **class** can be applied to many elements — use for reusable styles
- An **ID** should be used once per page — use for unique elements
- In CSS: class = `.classname`, ID = `#idname`

---

## 📁 External CSS Files

Separating CSS from HTML is best practice:

```
project/
├── index.html
└── styles.css
```

```html
<!-- In index.html <head> -->
<link href="styles.css" rel="stylesheet">
```

```css
/* styles.css */
body { text-align: center; }
header { font-size: large; }
main   { font-size: medium; }
footer { font-size: small; }
```

Benefits: one CSS file can style many HTML pages; changes propagate everywhere at once.

---

## 🅱️ Bootstrap — CSS Framework

**Bootstrap** is an open-source CSS (and JavaScript) framework by Twitter. It provides pre-built classes you can apply directly to your HTML for polished, responsive designs — without writing all the CSS yourself.

### Adding Bootstrap

```html
<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css"
          rel="stylesheet">
</head>
```

This one line (copied from Bootstrap's documentation) gives you access to hundreds of pre-designed CSS classes.

### Example — Styled Table

```html
<table class="table table-striped">
    <thead>...</thead>
    <tbody>...</tbody>
</table>
```

`table` and `table-striped` are Bootstrap classes that produce a clean, alternating-row-color table — like what you'd see in Gmail or Google Sheets.

### Bootstrap JavaScript Features

Bootstrap also provides JavaScript-powered components like responsive navigation bars (hamburger menus), modals, dropdowns, and carousels — all documented with copy-paste examples at [getbootstrap.com](https://getbootstrap.com/).

---

## ⚡ JavaScript — Basics

**JavaScript** is the only actual programming language of the three introduced today. It runs in the browser (client-side) and can dynamically change HTML and CSS at runtime.

### Syntax Comparison

| Concept | Python | C | JavaScript |
|---------|--------|---|------------|
| Variable | `x = 0` | `int x = 0;` | `let x = 0;` |
| Increment | `x += 1` | `x++;` | `x++;` or `x += 1` |
| If | `if x > 0:` | `if (x > 0) {` | `if (x > 0) {` |
| If-else | `elif` | `else if` | `else if` |
| For loop | `for i in range(3):` | `for (int i=0; i<3; i++)` | `for (let i=0; i<3; i++)` |
| While | `while True:` | `while (true) {` | `while (true) {` |

Key differences from Python:
- Curly braces `{}` for code blocks (like C)
- Semicolons at end of statements (optional but conventional)
- `let` instead of explicit types for variables
- `else if` instead of `elif`
- `++` increment operator (like C)

### Adding JavaScript to a Page

```html
<!-- Option 1: Inline <script> tag at bottom of <body> -->
<body>
    <!-- ...all your HTML... -->
    <script>
        // JavaScript here
    </script>
</body>

<!-- Option 2: External .js file -->
<script src="script.js"></script>

<!-- Option 3: Listen for DOM to load (can go in <head>) -->
<script>
    document.addEventListener('DOMContentLoaded', function() {
        // Safe to access DOM here
    });
</script>
```

> **Why put `<script>` at the bottom?** JavaScript that references HTML elements will fail if those elements don't exist yet. Placing `<script>` just before `</body>` ensures all HTML is built before the script runs.

---

## 🌳 The DOM in JavaScript

JavaScript interacts with the page through the **DOM** (Document Object Model) — the tree of nodes in the browser's memory.

### Selecting Elements

```javascript
// Select by CSS selector (most flexible)
document.querySelector('#name')        // by ID
document.querySelector('.intro')       // by class
document.querySelector('p')            // by tag
document.querySelector('input[type="text"]')  // by attribute

// Select all matching elements
document.querySelectorAll('li')        // returns a list
```

### Reading and Changing Content

```javascript
let name = document.querySelector('#name').value;   // text box value
let heading = document.querySelector('h1').innerHTML;  // inner HTML

// Change text content
document.querySelector('h1').innerHTML = 'Hello, World!';

// Change CSS dynamically
document.querySelector('body').style.backgroundColor = 'red';
// Note: CSS 'background-color' → JS 'backgroundColor' (camelCase)
```

### camelCase in JavaScript

CSS properties with hyphens become camelCase in JavaScript:

| CSS | JavaScript |
|-----|-----------|
| `background-color` | `backgroundColor` |
| `font-size` | `fontSize` |
| `text-align` | `textAlign` |
| `text-decoration` | `textDecoration` |

---

## 👂 Events and Event Listeners

JavaScript is **event-driven** — you write code that *listens* for things to happen, then *responds*:

```javascript
document.querySelector('form').addEventListener('submit', function(event) {
    event.preventDefault();     // stop default form submission
    let name = document.querySelector('#name').value;
    alert('Hello, ' + name + '!');
});
```

### Common Events

| Event | Trigger |
|-------|---------|
| `click` | User clicks an element |
| `submit` | Form is submitted |
| `keyup` | A keyboard key is released |
| `keydown` | A keyboard key is pressed |
| `change` | Input value changes |
| `mouseover` | Mouse hovers over element |
| `DOMContentLoaded` | Full DOM tree is built |

### Template Literals (JS F-strings)

```javascript
// Old way (concatenation)
alert('Hello, ' + name + '!');

// Modern way (template literal with backticks)
alert(`Hello, ${name}!`);
```

Template literals use **backticks** `` ` `` and `${variable}` for interpolation — JavaScript's equivalent of Python's f-strings.

---

## 🎨 Manipulating CSS with JavaScript

You can change any CSS property from JavaScript at runtime:

```javascript
let body = document.querySelector('body');

document.querySelector('#red').addEventListener('click', function() {
    body.style.backgroundColor = 'red';
});

document.querySelector('#green').addEventListener('click', function() {
    body.style.backgroundColor = 'green';
});

document.querySelector('#blue').addEventListener('click', function() {
    body.style.backgroundColor = 'blue';
});
```

### Toggling Visibility (The Blink Effect)

```javascript
function blink() {
    let body = document.querySelector('body');
    body.style.visibility = (body.style.visibility === 'hidden') ? 'visible' : 'hidden';
}

window.setInterval(blink, 500);  // call blink() every 500ms
```

- `window.setInterval(fn, ms)` — call a function repeatedly every `ms` milliseconds
- CSS: opposite of `visible` is `hidden` (not `invisible`)

---

## 💡 JavaScript — Practical Examples

### Hello on Submit

```javascript
document.addEventListener('DOMContentLoaded', function() {
    document.querySelector('form').addEventListener('submit', function(event) {
        event.preventDefault();
        let name = document.querySelector('#name').value;
        alert(`Hello, ${name}!`);
    });
});
```

### Dynamic Content on Keyup

```javascript
document.querySelector('input').addEventListener('keyup', function() {
    let name = document.querySelector('p');
    if (this.value) {
        name.innerHTML = `Hello, ${this.value}!`;
    } else {
        name.innerHTML = 'Hello, whoever you are!';
    }
});
```

### Autocomplete from a Word List

```javascript
document.querySelector('input').addEventListener('keyup', function() {
    let html = '';
    if (this.value) {
        for (let word of words) {           // 'words' is a large JS array
            if (word.startsWith(this.value)) {
                html += `<li>${word}</li>`;
            }
        }
    }
    document.querySelector('ul').innerHTML = html;
});
```

This is the core of how autocomplete works on any website — listening for keystrokes and dynamically rebuilding a list of matching results.

---

## 📍 Geolocation API

Browsers expose a **`navigator.geolocation`** API that (with user permission) returns the device's GPS coordinates:

```javascript
navigator.geolocation.getCurrentPosition(function(position) {
    document.write(position.coords.latitude + ', ' + position.coords.longitude);
});
```

The callback is **asynchronous** — it fires when the browser has determined the location (which may take a moment). This is the same API used by Google Maps, Uber, and any location-aware web app.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Internet** | Global network of routers and devices passing packets |
| **Packet** | Small unit of data — like an envelope — sent across the internet |
| **Router** | Computer that routes packets toward their destination |
| **IP** | Protocol giving every device a unique address (32-bit IPv4, 128-bit IPv6) |
| **IP address** | Numeric address in dotted notation e.g. `192.168.1.1` |
| **TCP** | Protocol ensuring reliable delivery and multiplexing via port numbers |
| **Port number** | Identifies which service a packet is for (80=HTTP, 443=HTTPS) |
| **DNS** | Translates domain names (`google.com`) to IP addresses |
| **DHCP** | Auto-assigns IP address and network config when a device connects |
| **HTTP** | Protocol governing web requests and responses |
| **HTTPS** | Encrypted version of HTTP (port 443) |
| **GET** | HTTP verb for retrieving data; parameters visible in URL |
| **POST** | HTTP verb for submitting data; parameters hidden in request body |
| **Status code** | 3-digit server response: 200=OK, 301=redirect, 404=not found, 500=error |
| **URL** | `scheme://hostname.domain.tld/path?key=value` |
| **Query parameter** | `?key=value` appended to a URL to pass data |
| **curl** | Command-line tool to make HTTP requests and inspect headers |
| **Developer tools** | Browser panel for inspecting HTML, CSS, network, and JS |
| **HTML** | Markup language describing structure and content of web pages |
| **Element** | An HTML node: open tag + content + close tag |
| **Tag** | `<tagname>` or `</tagname>` |
| **Attribute** | Key-value pair inside an opening tag: `class="intro"` |
| **Void element** | Self-closing tag with no content: `<img>`, `<input>`, `<br>` |
| **DOM** | Tree of nodes built in browser memory from HTML |
| **Semantic HTML** | Tags like `<header>`, `<main>`, `<footer>` that convey meaning to search engines |
| **Phishing** | Trick where `<a href="evil.com">PayPal</a>` looks safe but isn't |
| **CSS** | Language that styles HTML — colors, fonts, layout |
| **Cascading** | Styles flow down from parent elements to children |
| **Selector** | Which elements CSS rules apply to |
| **Type selector** | `p {}` targets all `<p>` tags |
| **Class selector** | `.name {}` targets elements with `class="name"` |
| **ID selector** | `#name {}` targets the element with `id="name"` |
| **Pseudo-class** | `a:hover {}` applies on hover/focus/etc. |
| **CSS property** | A key-value pair: `color: red;` |
| **camelCase** | CSS `background-color` becomes JS `backgroundColor` |
| **Bootstrap** | CSS/JS framework with pre-built classes for polished UIs |
| **JavaScript** | The only real programming language of the three; runs in the browser |
| **`let`** | Declares a variable in JavaScript |
| **`document`** | Global JS object representing the whole DOM |
| **`querySelector`** | Selects a DOM element using CSS selector syntax |
| **Event** | Something that happens: click, keyup, submit, DOMContentLoaded |
| **Event listener** | Code that waits for an event and runs a function when it fires |
| **Template literal** | `` `Hello, ${name}!` `` — JS equivalent of Python's f-string |
| **`innerHTML`** | Gets or sets the HTML content inside an element |
| **`setInterval`** | Calls a function repeatedly every N milliseconds |
| **Autocomplete** | Listen for keyup → filter a word list → rebuild a `<ul>` dynamically |
| **Geolocation API** | `navigator.geolocation.getCurrentPosition()` — returns GPS coords |
| **Regular expression** | Pattern for matching/validating text: `.+@.+\.edu` |
| **Front-end** | What the user sees (HTML, CSS, JS in the browser) |
| **Back-end** | Server-side logic and data (Python, SQL, etc.) |

---

## 🗂️ Problem Set 8

Build interactive web pages using HTML, CSS, and JavaScript:
[cs50.harvard.edu/x/2026/psets/8](https://cs50.harvard.edu/x/2026/psets/8/)

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 7 – SQL](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%207%20-%20SQL) |
| ➡️ Next | [Week 9 – Flask](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%209%20-%20Flask) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture 8 - HTML, CSS, JavaScript`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%208%20-%20HTML%2C%20CSS%2C%20JavaScript)
