# ED2 — Sorting — List 03

Practice exercises for **Data Structures II** — Sorting algorithms (Bubble Sort, Selection Sort, Insertion Sort) and their variations.

> Instituto Federal do Triângulo Mineiro — Campus Patrocínio
> Course: Technology in Systems Analysis and Development — 4th Term
> Instructor: Júnio Moreira
> Date: 08/26/2026 · **Due: 09/09/2026**

---

## 📁 Project Structure

```
ed2-sorting-list03-cpp/
└── src/
    ├── Exer01_BubbleSortCountSwaps.cpp
    ├── Exer02_SelectionSortKSmallest.cpp
    ├── Exer03_InsertionSortKSortedCountComparisons.cpp
    ├── Exer04_BubbleSortParitySort.cpp
    └── Exer05_InsertionSortCountInversions.cpp
├── .gitignore
├── CMakeLists.txt
├── main.cpp
└── README.md
```

Each `.cpp` file is **standalone** (has its own `main()`) and is compiled as an independent executable. All of them follow the same three-block pattern:

| Block | Responsibility |
|---|---|
| **Pure logic** | Implements the algorithm itself, using STL (`vector`, `string`, etc). Does not perform `cin`/`cout`. |
| `onlineJudge()` | Adapter: reads input with `cin`, calls the pure logic, prints with `cout`. |
| `runExer...()` | Runs the examples from the statement locally and compares against the expected output (`[PASSED]` / `[FAILED]`). |

---

## 📝 Exercises

| # | File | Problem | Technique | Complexity |
|---|---|---|---|---|
| 1 | `Exer01_BubbleSortCountSwaps.cpp` | Sort array ascending and count total swaps | Bubble Sort (instrumented) | O(n²) |
| 2 | `Exer02_SelectionSortKSmallest.cpp` | Select the k smallest elements via k iterations of the outer loop | Selection Sort (partial simulation) | O(k·n) |
| 3 | `Exer03_InsertionSortKSortedCountComparisons.cpp` | Sort a k-sorted array and count comparisons in the `while` loop | Insertion Sort (k-sorted, instrumented) | O(n·k) |
| 4 | `Exer04_BubbleSortParitySort.cpp` | Even numbers ascending before odd numbers descending | Bubble Sort (custom comparator) | O(n²) |
| 5 | `Exer05_InsertionSortCountInversions.cpp` | Count inversions via Insertion Sort shifts | Insertion Sort (inversion counting) | O(n²) |

<details>
<summary><strong>Details for each exercise (input, output, and example)</strong></summary>

### 1. Counting Swaps in Bubble Sort
**Input:** N (1 ≤ N ≤ 10⁴) and an array `A` of N integers.
**Output:** first line with the array sorted ascending; second line with the **total number of swaps** performed during the entire traditional Bubble Sort process.

```
Input            Output
5                1 2 3 4 5
4 3 2 1 5        6
```

### 2. Selecting the k Smallest Elements via Selection Sort
**Input:** N, k (1 ≤ k ≤ N) and an array `A`.
**Output:** the **k smallest elements**, in ascending order, after running **strictly the first k iterations** of Selection Sort's outer loop (relies on the invariant that after k iterations, the k smallest elements are already placed at indices 0..k-1).

```
Input                Output
6 3                  10 13 14
29 10 14 37 13 42
```

### 3. Sorting a Nearly-Sorted (k-Sorted) Array with Insertion Sort
**Input:** N, k (0 ≤ k ≤ N, the maximum distance of any element from its final position) and the k-sorted array `A`.
**Output:** first line with the fully sorted ascending array; second line with the **total number of comparisons** performed in Insertion Sort's inner `while` loop.

```
Input                Output
6 2                  1 2 3 4 5 6
3 2 1 5 4 6          8
```

### 4. Two-Phase Parity Sort with Bubble Sort
**Input:** N and an array `A`.
**Output:** a single line with the array reorganized according to the composite criterion: (1) even numbers before odd numbers; (2) even numbers in **ascending** order among themselves; (3) odd numbers in **descending** order among themselves. **Must adapt Bubble Sort's comparison logic**, not use `sort` with a ready-made comparator.

```
Input                    Output
8                        2 4 6 8 9 5 3 1
5 2 9 8 1 6 3 4
```

### 5. Counting Inversions via Insertion Sort Simulation
**Input:** N and an array `A` of **distinct** positive integers.
**Output:** a single integer with the total number of inversions (pairs i < j where A[i] > A[j]), equivalent to the total number of right shifts performed by Insertion Sort.

```
Input            Output
5                3
2 4 1 3 5
```

</details>

---

## 🚀 Running in CLion

1. Open the project and reload CMake (**Reload CMake Project**, the sync icon that appears when you edit `CMakeLists.txt`).
2. In the run target selector (top of the window), choose the desired exercise.
3. Click **Run** (▶) or **Debug** (🐞).

> **Tip:** each file toggles between two modes inside `int main()`:
> - **Local test mode** (default): runs `runExer...()` with the examples from the statement.
> - **Online judge mode**: comment out the `runExer...()` call and uncomment `onlineJudge()` before submitting to the judge.

```cpp
int main() {
    runExer01BubbleSortCountSwaps();  // <- local test mode (active)
    // onlineJudge();                 // <- online judge mode (commented)
    return 0;
}
```

---

## 💻 Running from the Terminal (without CLion)

If you prefer to compile manually with `g++`:

```bash
g++ -std=c++17 -Wall -Wextra -o exer01 src/Exer01_BubbleSortCountSwaps.cpp
./exer01
```

To test online judge mode from the terminal, redirect an input file:

```bash
echo "5
4 3 2 1 5" | ./exer01
```

---

## ⚠️ Watch Out For

- **Question 1** requires the traditional Bubble Sort — count **only** the swaps between adjacent elements, don't confuse this with the number of comparisons.
- **Question 2** asks for the state after **exactly k iterations** of Selection Sort's outer loop — don't run the full algorithm, just return the k elements already placed.
- **Question 3** requires counting **comparisons** (not shifts) made inside Insertion Sort's `while` loop; the k-sorted property is just efficiency context and doesn't need to be explicitly validated.
- **Question 4** requires adapting Bubble Sort's comparison logic for the composite parity criterion (even ascending < odd descending) — implement the comparison manually, don't split into two lists sorted with `sort`.
- **Question 5** counts inversions via Insertion Sort simulation — the array has **distinct** elements, which simplifies the comparison logic (no ties).

---

## ✅ Prerequisites

- C++17-compliant compiler or newer (GCC, Clang, or MSVC)
- CMake ≥ 3.20
- CLion (recommended) or any IDE/editor of your choice

---

## 📚 Reference

Original exercise list: *Practice Exercises — Data Structures II* (08/26/2026 · due 09/09/2026).
