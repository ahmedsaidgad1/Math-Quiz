# 🧮 Math Quiz Game (C++)

A console-based math quiz game built in C++ that tests arithmetic skills with customizable difficulty levels and operation types.

## 📸 Preview

```
Enter number of Questions? 3
Enter Questions level [1]Easy, [2]Med, [3]Hard, [4]Mix: 1
Enter operation type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix: 1

==================== Question [1] ======================
7 + 4 = 11
Correct Answer :-)

==================== Question [2] ======================
3 + 9 = 10
Wrong Answer :-(
The correct answer is: 12

===============================================
                 GAME OVER
===============================================
 Number of Questions: 3
 Questions Level    : Easy
 Operation Type     : +
 Correct Answers    : 2
 Wrong Answers      : 1
 Final Result       : PASS :)
===============================================
```

## ✨ Features

- **4 Difficulty Levels** — Easy, Medium, Hard, or Mixed
- **5 Operation Types** — Addition, Subtraction, Multiplication, Division, or Mixed
- **Smart Division** — Division questions always produce whole-number answers
- **Instant Feedback** — Shows whether your answer is correct after each question
- **Final Summary** — Displays score and Pass/Fail result at the end

## 🛠️ How to Build & Run

### Requirements
- C++ compiler (g++ / MSVC / Clang)

### Compile
```bash
g++ -o math_quiz main.cpp
```

### Run
```bash
./math_quiz
```

## 🗂️ Project Structure

```
math-quiz-cpp/
│
├── main.cpp       # Full source code
└── README.md
```

## 🧠 How It Works

| Level  | Number Range |
|--------|-------------|
| Easy   | 1 – 10      |
| Medium | 10 – 50     |
| Hard   | 50 – 100    |
| Mix    | Random level per question |

> Division questions are specially generated to guarantee integer results.

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
