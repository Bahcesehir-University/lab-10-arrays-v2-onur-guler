# CMP1001 – Lab: Arrays in C++

> **Course:** CMP1001 – Introduction to Programming (C++)  
> **Duration:** 60 minutes  
> **Topic:** One-Dimensional Arrays — Declaration, Traversal, Statistics, Search, Sort

---

## 1. Objective

By the end of this lab you will be able to:

- Declare, initialize, and access one-dimensional arrays in C++
- Traverse arrays with `for`-loops to read and print elements
- Compute basic statistics (sum, average, minimum, maximum) without library functions
- Implement linear search and return the index of a target value
- Sort an array using the bubble-sort algorithm
- Reverse an array **in-place** using a single temporary variable
- Remove duplicate values from an array without using STL containers

---

## 2. Prerequisites

Before attending this lab you should be comfortable with:

| Concept | Example |
|---------|---------|
| Variables and data types | `int x = 5;` |
| `cout` / `cin` | `cout << x;` / `cin >> x;` |
| `for` and `while` loops | `for (int i = 0; i < 10; i++)` |
| `if` / `else` conditions | `if (x > 0)` |
| Calling functions | `myFunction(a, b);` |

---

## 3. What You Will Learn

```
Section 1  — Warm-up              (5–10 min)   loop review, arithmetic sum
Section 2  — Core Concepts        (10–15 min)  array syntax, init, access, update
Section 3  — Guided Exercises     (25–30 min)  fill from input, stats, search,
                                               char count, bubble sort
Section 4  — Challenges           (10 min)     reverse in-place, remove duplicates
```

---

## 4. Repository Structure

```
.
├── MainProgram.cpp               ← Student file (TODOs to complete)
├── MainProgram_teacher.cpp       ← Reference solution  [instructor only]
├── Makefile                      ← Build all targets
├── catch_amalgamated.hpp         ← Catch2 test framework header
├── catch_amalgamated.cpp         ← Catch2 test framework source
├── tests/
│   ├── test_section1_warmup.cpp          (10 pts)
│   ├── test_section2_concepts.cpp        (10 pts)
│   ├── test_exercise3B_statistics.cpp    (15 pts)
│   ├── test_exercise3C_search.cpp        (15 pts)
│   ├── test_exercise3E_sort.cpp          (20 pts)
│   └── test_section4_challenges.cpp      (30 pts)
└── README.md
```

> **Students receive:** `MainProgram.cpp`, `Makefile`, `catch_amalgamated.*`, `tests/`, `README.md`  
> **Instructors retain:** `MainProgram_teacher.cpp`

---

## 5. How to Compile & Run

### Build the lab program

```bash
make lab
./lab
```

### Build and run ALL tests at once

```bash
make run_tests
```

### Build and run a single test suite

```bash
make run_s1    # Section 1  — warm-up
make run_s2    # Section 2  — concepts
make run_3b    # Exercise 3-B — statistics
make run_3c    # Exercise 3-C — linear search
make run_3e    # Exercise 3-E — bubble sort
make run_ch    # Section 4  — challenges
```

### Manual compilation (without Make)

```bash
# Compile Catch2 once
g++ -std=c++17 -c catch_amalgamated.cpp -o catch_amalgamated.o

# Compile main lab
g++ -std=c++17 MainProgram.cpp -o lab && ./lab

# Compile a test suite
g++ -std=c++17 tests/test_exercise3C_search.cpp catch_amalgamated.o -o t && ./t -s
```

> **Minimum compiler:** GCC 7 / Clang 5 with `-std=c++17`

---

## 6. Lab Structure — Section-by-Section Guide

### Section 1 — Warm-up *(5–10 min)*

| Exercise | Task |
|----------|------|
| 1-A | Print the integers 1–10 on one line |
| 1-B | Read 5 integers from the user and print their sum |

**Goal:** shake off the rust; confirm your loop syntax is solid.

---

### Section 2 — Core Concepts *(10–15 min)*

Read the **given example** (do not modify it), then complete three TODOs:

| TODO | Task |
|------|------|
| 2-A | Declare and initialize a `temps[7]` array |
| 2-B | Print all seven temperatures with a loop |
| 2-C | Update `temps[3]` to 35 and print it |

**Key rule:** array indices run from `0` to `SIZE − 1`.

---

### Section 3 — Guided Exercises *(25–30 min)*

| Exercise | Task | Key skill |
|----------|------|-----------|
| 3-A | Fill an array from user input (1–20 grades) | `cin` + validation loop |
| 3-B | Compute sum, average, min, max | Loop + accumulator |
| 3-C | Linear search — return index or -1 | Function + early return |
| 3-D | Count occurrences of `'a'`/`'A'` in a `char` array | Char comparison |
| 3-E | Bubble sort ascending | Two nested loops + swap |

---

### Section 4 — Challenges *(10 min)*

| Challenge | Task | Constraint |
|-----------|------|------------|
| A | Reverse array in-place | One temp variable, one loop, no second array |
| B | Remove duplicates into new array | No STL; first-occurrence wins |

*Partial credit is available — even a well-described attempt earns points.*

---

## 7. Submission Instructions

1. Complete `MainProgram.cpp`.  Do **not** rename it.
2. Do **not** delete the `// TODO:` comments — leave them above your code.
3. Your file **must compile** without errors:
   ```bash
   g++ -std=c++17 MainProgram.cpp -o lab
   ```
4. Submit via **GitHub Classroom**:
   ```bash
   git add MainProgram.cpp
   git commit -m "Lab submission — Arrays"
   git push
   ```
5. Deadline: as announced on the course portal.

> ⚠️ **Do not commit** `MainProgram_teacher.cpp` or any auto-generated binaries.

---

## 8. Grading Criteria

| Component | Points | How it is graded |
|-----------|-------:|-----------------|
| Section 1 — Warm-up | 10 | Catch2 `test_section1_warmup` |
| Section 2 — Concepts | 10 | Catch2 `test_section2_concepts` |
| Exercise 3-B — Statistics | 15 | Catch2 `test_exercise3B_statistics` |
| Exercise 3-C — Search | 15 | Catch2 `test_exercise3C_search` |
| Exercise 3-E — Bubble Sort | 20 | Catch2 `test_exercise3E_sort` |
| Challenges A & B | 30 | Catch2 `test_section4_challenges` |
| **Total** | **100** | |

**Partial credit** is awarded per `SECTION` block within each test case.  
You can earn points in any section independently.

---

## 9. Estimated Time Breakdown

| Activity | Time |
|----------|-----:|
| Read instructions & setup | 5 min |
| Section 1 — Warm-up | 8 min |
| Section 2 — Core Concepts | 12 min |
| Exercise 3-A (fill array) | 5 min |
| Exercise 3-B (statistics) | 6 min |
| Exercise 3-C (linear search) | 5 min |
| Exercise 3-D (char count) | 4 min |
| Exercise 3-E (bubble sort) | 8 min |
| Section 4 — Challenges | 7 min |
| **Total** | **60 min** |

---

## 10. Tips for Students

- **Compile early and often.** Even an empty function body compiles.  
  Fix errors one at a time — read the *first* error message, not the last.

- **Index carefully.** The most common array bug is going one step too far.  
  If your array has `n` elements, valid indices are `0` through `n-1`.

- **Start the loop variable at the right place.**  
  For min/max, initialise with `arr[0]` and start the loop at `i = 1`.

- **Test with simple data first.**  
  Before the lab data, try your bubble sort on `{3, 1, 2}` — easy to check by hand.

- **The swap idiom:**
  ```cpp
  int tmp = arr[i];
  arr[i]  = arr[j];
  arr[j]  = tmp;
  ```
  You will use this in both bubble sort and the reverse challenge.

- **For the challenges:** think about *when* to stop the loop.  
  Reversing only needs to reach the *midpoint* — going past it undoes your work.

- **Run the tests as you go:**
  ```bash
  make run_3b   # check your statistics code right after 3-B
  ```

---

## 11. Academic Integrity

All submitted code must be your own.  
You may discuss concepts with classmates but **may not share code**.  
Use of AI code generators is **not permitted** for this lab.

---

*CMP1001 · Introduction to Programming (C++) · Lab — Arrays*
