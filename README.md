# Learning C Programming

A collection of small command-line programs I built while learning C. These projects focus on writing functions, handling input, working with control flow, and using structs and arrays.

## Projects

| Project | What it does | Source |
| --- | --- | --- |
| Age Calculator | Estimates age from a birth year using the current calendar year. Exact age depends on whether the birthday has passed. | [`age_calculator.c`](age_calculator.c) |
| Simple Calculator | Performs addition, subtraction, multiplication, and division, with invalid-input and division-by-zero checks. | [`simple_calculator.c`](simple_calculator.c) |
| First-Year Study Organizer | Stores up to 20 courses, lists grades and credit values, and estimates a grade-based score. | [`organizer.c`](organizer.c) |
| Number Guessing Game | Generates a number from 1 to 100 and gives feedback for up to 10 guesses, with an option to replay. | [`number_guesser.c`](number_guesser.c) |

> **Note on the Study Organizer:** Its displayed “GPA” uses a simple approximation (weighted average percentage divided by 25). It is **not** an official university GPA conversion.

## Run a project

You need a C compiler such as GCC or Clang. From the repository directory, compile and run any project, for example:

```sh
cc -std=c11 -Wall -Wextra -pedantic simple_calculator.c -o simple_calculator
./simple_calculator
```

To try a different program, replace `simple_calculator` with `age_calculator`, `organizer`, or `number_guesser` in both commands. On Windows, the executable may have an `.exe` suffix.

### Example: Simple Calculator

```text
Enter first number: 12
Enter operation (+, -, *, /): /
Enter second number: 4
Answer: 3.00
```

## Skills practised

- C syntax, functions, and control flow
- Reading and validating console input
- Arrays, strings, and `struct` values
- Basic arithmetic, loops, and random numbers
- Compiling and running command-line programs

These are foundational learning exercises, not production applications. I'm continuing to build more substantial software projects as I develop my skills.
