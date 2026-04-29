# 🤖 CS50x – Artificial Intelligence
### Harvard University's Introduction to AI, Machine Learning, and Large Language Models

> *"Among our goals for today is really to give you a better sense of not just how technologies like this duck work, but really what are the underlying principles of artificial intelligence that frankly have been with us and have been developing for decades."*
> — David J. Malan

[![CS50](https://img.shields.io/badge/CS50x-2026-red?style=flat-square&logo=harvard)](https://cs50.harvard.edu/x/)
[![Topic](https://img.shields.io/badge/Topic-Artificial%20Intelligence-purple?style=flat-square)](https://cs50.harvard.edu/x/weeks/ai/)
[![YouTube](https://img.shields.io/badge/Watch-YouTube-red?style=flat-square&logo=youtube)](https://www.youtube.com/watch?v=-9bo8HlSxwQ)

---

## 🔗 Quick Links

| Resource | Link |
|----------|------|
| 🎥 Lecture Video | [YouTube – CS50x AI](https://www.youtube.com/watch?v=-9bo8HlSxwQ) |
| 📝 Official Notes | [cs50.harvard.edu/x/notes/ai](https://cs50.harvard.edu/x/notes/ai/) |
| 🦆 CS50 AI Duck | [cs50.ai](https://cs50.ai/) |
| 💻 CS50 Codespace | [cs50.dev](https://cs50.dev/) |
| 📋 Final Project | [cs50.harvard.edu/x/project](https://cs50.harvard.edu/x/project/) |

---

## 📋 Table of Contents

1. [The Rubber Duck — A Brief History](#-the-rubber-duck--a-brief-history)
2. [Generative AI — Can You Tell the Difference?](#-generative-ai--can-you-tell-the-difference)
3. [Prompt Engineering](#-prompt-engineering)
4. [System Prompts and User Prompts](#-system-prompts-and-user-prompts)
5. [Implementing the Duck in Code](#-implementing-the-duck-in-code)
6. [AI-Assisted Coding — Copilot](#-ai-assisted-coding--copilot)
7. [What Is AI? A Brief History](#-what-is-ai-a-brief-history)
8. [Decision Trees](#-decision-trees)
9. [Minimax — AI for Games](#-minimax--ai-for-games)
10. [Machine Learning](#-machine-learning)
11. [Reinforcement Learning](#-reinforcement-learning)
12. [Explore vs. Exploit — The Epsilon Trick](#-explore-vs-exploit--the-epsilon-trick)
13. [Supervised Learning](#-supervised-learning)
14. [Deep Learning and Neural Networks](#-deep-learning-and-neural-networks)
15. [Large Language Models (LLMs)](#-large-language-models-llms)
16. [Attention and Transformers](#-attention-and-transformers)
17. [Hallucinations](#-hallucinations)
18. [Summary — Key Takeaways](#-summary--key-takeaways)

---

## 🦆 The Rubber Duck — A Brief History

In programming culture, **rubber duck debugging** is the practice of explaining your code to an inanimate object. The act of *verbalizing* your confusion often triggers the solution.

- CS50 gave every student a physical rubber duck early in the course
- CS50 later "virtualized" the duck as an AI chatbot at [cs50.ai](https://cs50.ai)
- The very first version of the duck responded with only **quacks** — and students still solved their problems, because *typing out* the confusion was enough
- Since 2023, the duck responds in English, powered by large language models (LLMs)

The CS50 duck is intentionally **less helpful** than ChatGPT — it guides students toward solutions rather than giving answers outright.

---

## 🎭 Generative AI — Can You Tell the Difference?

AI is now capable of generating **images, video, audio, and text** that are increasingly indistinguishable from human-created content.

### AI-Generated Images
- Early AI images had obvious "tells" — but this is rapidly disappearing
- Tools trained on massive datasets can synthesize realistic human faces that **do not exist** in the real world
- Studies show humans are already struggling to reliably detect AI images

### AI-Generated Text
An informal quiz comparing two essays — one by a student, one by AI — reveals a key insight:

| Sample | Author |
|--------|--------|
| *"I'd like to bring a yummy sandwich and a cold juice box... we chat and laugh and catch up on each other's day."* | 🤖 AI |
| *"My mother packs me a sandwich... My friends come and sit down with me."* | 👦 Human (4th grader) |

> **Key tell:** The AI wrote in a slightly *too polished*, adult vernacular ("catch up on each other's day") — a 4th grader wouldn't write that.

This game will soon be impossible to play. AI-generated content will become **undetectable**.

---

## 💬 Prompt Engineering

**Prompt engineering** is the skill of asking good questions of an AI — providing enough context and detail that the response has a high probability of being what you want.

It's less a form of engineering and more a form of **communication clarity**.

Two main types of prompts:

| Prompt Type | Who Writes It | Purpose |
|-------------|---------------|---------|
| **System Prompt** | Developers / Instructors | Gives the AI its personality, domain, and constraints |
| **User Prompt** | End users (students) | The actual question or task |

---

## ⚙️ System Prompts and User Prompts

CS50's duck behaves like a teaching assistant — not ChatGPT — because of its **system prompt**:

```
You are a friendly and supportive teaching assistant for CS50.
You are also a rubber duck.
Answer student questions only about CS50 and computer science.
Do not answer questions about unrelated topics.
Do not provide full answers to problem sets, as this would violate academic honesty.
Answer this question: [student's question here]
```

That's all it takes to transform a general-purpose AI into a course-specific tutor.

> The user prompt is whatever the student typed. It's simply copy-pasted after the system prompt.

---

## 🐍 Implementing the Duck in Code

Here's the Python code from CS50's Week 0, now making more sense after learning Python:

```python
from openai import OpenAI

client = OpenAI()

user_prompt = input("Prompt: ")
system_prompt = "Limit your answer to one sentence. Pretend you're a cat."

response = client.responses.create(
    input=user_prompt,
    instructions=system_prompt,
    model="gpt-5"
)

print(response.output_text)
```

- `client` — gives us access to OpenAI's API
- `user_prompt` — what the user types
- `system_prompt` — instructions from us (the developers)
- `model` — which version of the AI to use
- `response.output_text` — the AI's reply

---

## 💻 AI-Assisted Coding — Copilot

**GitHub Copilot** (from Microsoft/GitHub) is an AI coding assistant embedded directly into VS Code. It can:

- Read your existing code as context
- Understand code comments as hints
- Generate function implementations from descriptions
- Produce code that would have taken students hours in just seconds

### Example — CS50's Speller Assignment

A spell-checker in C (`dictionary.c`) had 4 blank functions students needed to implement over ~10 hours. With Copilot:

```
"Implement the check function using a hash table in C."
→ [Copilot generates the entire function in seconds]

"Implement the load function."
→ [Copilot generates it too]
```

### Example — Mario from a Prompt

```
"Please implement a program in C that prints a left-aligned pyramid
of bricks using hash symbols for bricks and use the CS50 library to
ask the user for a non-negative height as an integer."
```

Copilot generates `mario.c` from this English description — essentially the same as the problem set's instructions.

### Why Learn to Code If AI Can Do It?

> *"If you don't have an eye for what you're looking at, there's no way you're going to be able to troubleshoot an issue, explain it to someone else, or make marginal changes."*

The **muscle memory** you build learning to code manually lets you:
- Evaluate AI-generated code for correctness
- Debug issues the AI introduces
- Communicate intent clearly to the AI
- Understand the big picture while AI handles tedium

AI **amplifies** your abilities — it doesn't replace the need for foundational knowledge.

---

## 🕹️ What Is AI? A Brief History

AI has been present in everyday software for **decades** — long before ChatGPT:

| Application | How AI Is Used |
|-------------|---------------|
| **Spam filters** | Classify emails as spam/not spam using pattern recognition |
| **Handwriting recognition** | Match your handwriting to patterns seen in training data |
| **Netflix recommendations** | Predict what you'll watch based on viewing history |
| **Voice assistants** | Dynamically understand and respond to spoken language |
| **Video game opponents** | React intelligently to player actions |

Early games like **Pong** and **Breakout** already had "AI" opponents — though these were simply hardcoded decision trees.

---

## 🌳 Decision Trees

A **decision tree** is a series of yes/no questions that maps to code. It was the original form of game AI.

### Breakout Example

```
While game is ongoing:
  If ball is to the left of the paddle:
    Move paddle left
  Else if ball is to the right of the paddle:
    Move paddle right
  Else:
    Don't move paddle
```

This simple tree is sufficient to play Breakout competently. But more complex games need something smarter.

### Why Trees Break Down

- **Tic-tac-toe**: 255,168 possible games — manageable with code
- **Chess** (first 4 pairs of moves): ~85 billion possibilities — hard
- **Go** (first 4 pairs of moves): ~266 quintillion possibilities — impossible to enumerate

For games like Go or Chess, brute-force decision trees are computationally infeasible. We need a smarter approach.

---

## ♟️ Minimax — AI for Games

**Minimax** is an algorithm that assigns numeric scores to game states and works backward to choose the optimal move.

### Scoring System (Tic-Tac-Toe)

| Outcome | Score |
|---------|-------|
| O wins  | `-1`  |
| Tie     | `0`   |
| X wins  | `+1`  |

- **X** wants to **maximize** the score (aim for +1)
- **O** wants to **minimize** the score (aim for -1)

### Minimax in Pseudocode

```
If player is X:
  For each possible move:
    Calculate score for the resulting board
  Choose the move with the highest score

Else if player is O:
  For each possible move:
    Calculate score for the resulting board
  Choose the move with the lowest score
```

### Result

A player following Minimax **cannot lose** tic-tac-toe — they will always win or force a tie. If you've ever lost tic-tac-toe, you deviated from the optimal algorithm.

> The more moves remain, the larger and bushier the decision tree — which is why even Minimax can't fully solve Chess or Go without approximations.

---

## 🧠 Machine Learning

When decision trees and brute-force search become too large, we switch to **machine learning** — writing code that teaches the computer *how to learn* rather than *what to do*.

> *"Machine learning: writing code via which machines learn how to solve problems, generally by being trained on massive amounts of data and then, in new problems, looking for patterns."*

Instead of explicitly programming every rule, we:
1. Show the AI many examples (training data)
2. Let it find patterns on its own
3. Apply those patterns to new, unseen problems

---

## 🏆 Reinforcement Learning

**Reinforcement learning** is a type of machine learning modeled on how humans and animals learn through reward and punishment.

### Pancake-Flipping Robot Example

A researcher demonstrates flipping a pancake to a robot arm a few times. Then:
- When the robot flips successfully → **reward** (points / digital cookie)
- When the robot drops the pancake → **punishment** (points deducted)

After ~50 trials, the robot learns to flip reliably — without ever being *told* the rules explicitly.

### Maze Navigation Example

```
Yellow dot (player) starts at one corner
Green square (exit) is the goal
Red squares (lava) are punishments

Trial 1: Moves right → hits lava → punished → remember: don't go right
Trial 2: Moves down → hits lava → punished → remember: don't go down either
...
Trial N: Finally reaches the exit → rewarded
```

Over many trials, the AI builds a map of:
- **Red paths** — don't go here (punished)
- **Green paths** — go here (rewarded)

---

## 🎲 Explore vs. Exploit — The Epsilon Trick

A problem with pure reinforcement learning: once the AI finds *a* working path, it exploits that path forever — even if a **shorter/better** path exists.

This is called the **explore vs. exploit tradeoff**:

| Strategy | Behavior |
|----------|---------|
| **Exploit** | Always use the known best path — safe but suboptimal |
| **Explore** | Occasionally try a random move — might find something better |

### Epsilon-Greedy Algorithm

```python
epsilon = 0.1   # 10% of the time, explore randomly

if random() < epsilon:
    make a random move   # Explore
else:
    make the highest-value known move  # Exploit
```

By injecting **10% randomness**, the AI can discover shorter paths and better strategies over time.

> Analogy: If you always order the same dish at a restaurant, you'll never discover a better one on the menu.

---

## 📚 Supervised Learning

**Supervised learning** is the classic ML approach — humans label the training data:

- You mark an email as spam → Google learns what spam looks like
- Netflix sees you give a film 5 stars → it learns your preferences

```
Human labels data → Algorithm learns from labels → Makes future predictions
```

### The Scaling Problem

Manually labeling billions of emails or videos is **expensive and slow**. This is why:
- Large-scale AI moved toward **unsupervised** and **self-supervised** learning
- Modern LLMs learn from raw internet text — no human labeling required for most training

---

## 🧬 Deep Learning and Neural Networks

**Neural networks** are computational models loosely inspired by the brain's structure. They power modern AI, including the CS50 duck.

### From Biology to Math

```
Biological neuron:  receives electrical signal → passes it forward
Computational node: receives a number → applies math → outputs a number
```

A network of nodes forms a **graph**:

```
Inputs        Hidden Layers          Output
  [x] ──┐
        ├──► [●] ──► [●] ──► [●] ──► prediction
  [y] ──┘
```

### Training a Simple Neural Network (2D Example)

Given dots colored **blue** or **red** on an XY grid:
- The network tries to find a **best-fit line** (or curve) separating the two colors
- It adjusts 3 parameters: `a`, `b`, `c` in the formula `ax + by + c`
- If `ax + by + c > 0` → predict blue; else → predict red

With enough data, the network learns parameters that correctly classify new dots with high accuracy.

### Real Neural Networks

- Have **billions** of nodes and edges, not just 3
- Each edge has a learned **weight** (a number)
- The "hidden" middle layers are uninterpretable — even engineers can't say exactly what each neuron "means"
- More training data → more refined weights → better predictions

---

## 📖 Large Language Models (LLMs)

**LLMs** (like GPT, Claude, Gemini) are neural networks trained on massive amounts of text. They power the CS50 duck and every modern AI chatbot.

### The Core Idea

LLMs are trained to answer one question: **"Given everything before this point, what word comes next?"**

```
"The state's capital is ___"
```

The model has seen this sentence structure millions of times in training data. It predicts "Boston" with very high probability.

### How Text Becomes Numbers

Words are converted to **embeddings** — arrays of floating-point numbers representing their meaning in a high-dimensional space:

```
"Massachusetts" → [0.231, -0.847, 0.113, ... ]  (1,536 numbers in some models)
```

Words with similar meanings end up **close together** in this multidimensional space. This lets the model understand relationships between concepts.

---

## 🔍 Attention and Transformers

The breakthrough behind modern LLMs is called **attention** — a mechanism that lets the model weigh which words in a sentence are most relevant to each other.

### Example

```
"The Massachusetts is a state in New England... The state's capital is ___"
```

Without attention, the model struggles because "Massachusetts" and "capital" are far apart. Attention assigns **thicker connections** between related words:

```
Massachusetts ←──── thick line ────→ state
Massachusetts ←──── thick line ────→ capital
the, and, of  ←─── thin lines ─────→ (less signal)
```

**GPT** = **G**enerative **P**re-trained **T**ransformer — the "transformer" refers to this attention mechanism.

---

## 👻 Hallucinations

LLMs sometimes **make things up** — this is called a **hallucination**:

- The model generates the statistically most likely next word, which is sometimes simply **wrong**
- Could be caused by incorrect information in training data
- Could be the result of the AI's "explore" randomness picking an unlikely path
- Even CS50's duck hallucinates occasionally, despite the team's efforts to reduce it

> Hallucinations are a fundamental property of probabilistic systems — they're not bugs in the traditional sense, but a side effect of how LLMs work.

---

## 📌 Summary — Key Takeaways

| Concept | Core Idea |
|---------|-----------|
| **Rubber duck debugging** | Talking through a problem (to anything) forces clarity |
| **Generative AI** | AI that produces images, text, audio, and video |
| **System prompt** | Developer instructions that shape the AI's behavior |
| **User prompt** | The end user's actual question or request |
| **Prompt engineering** | Asking good, detailed, contextual questions of an AI |
| **Copilot** | AI tool that generates code from natural language or context |
| **Decision tree** | A flowchart of yes/no decisions mapped to code |
| **Minimax** | Algorithm that scores game outcomes and picks the best move |
| **Machine learning** | Training code to recognize patterns instead of programming rules explicitly |
| **Reinforcement learning** | Learning through reward and punishment across many trials |
| **Explore vs. exploit** | Balance between using known solutions and trying new ones |
| **Epsilon-greedy** | Inject randomness (epsilon) to occasionally explore instead of always exploiting |
| **Supervised learning** | Training ML models with human-labeled data |
| **Neural network** | Layers of mathematical nodes that learn by adjusting edge weights |
| **Deep learning** | Neural networks with many hidden layers |
| **Embedding** | Representing a word (or other data) as a vector of numbers |
| **Attention** | Mechanism that relates distant words in a sentence to each other |
| **Transformer** | The neural network architecture behind GPT, Claude, etc. |
| **LLM** | Large language model — trained to predict the next word in text |
| **Hallucination** | When an LLM generates confident but factually incorrect output |
| **Training data** | The massive datasets (text, images, etc.) used to teach AI models |
| **Parameters / weights** | The numerical values in a neural network that encode learned knowledge |

---

## 🔙 Navigation

| | Link |
|--|------|
| ⬅️ Previous | [Week 7 – SQL](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%207%20-%20SQL) |
| ➡️ Next | [Week 8 – HTML, CSS, JavaScript](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%208%20-%20HTML%2C%20CSS%2C%20JavaScript) |
| 🏠 Main Repo | [Nilanchal0107/CS50x](https://github.com/Nilanchal0107/CS50x) |

> 📁 This README belongs in: [`Lecture AI - Artificial Intelligence`](https://github.com/Nilanchal0107/CS50x/tree/main/Lecture%20AI%20-%20Artificial%20Intelligence)
