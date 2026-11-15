# DAA Lab Assignment 5 — Strassen's 2×2 Matrix Multiplication

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 24/08/2026

## Problem Statement

Multiply $A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$ and $B = \begin{bmatrix} 5 & 6 \\ 7 & 8 \end{bmatrix}$ using **Strassen's algorithm**:
- Compute all seven products $M_1$–$M_7$ and show how $C$ is assembled.
- Count multiplications (`7` vs the standard `8`).
- State Strassen's recurrence and its solved time complexity.

## Observed Results

- **Intermediate Products:**
  - $M_1 = (1 + 4)(5 + 8) = 65$
  - $M_2 = (3 + 4) \times 5 = 35$
  - $M_3 = 1 \times (6 - 8) = -2$
  - $M_4 = 4 \times (7 - 5) = 8$
  - $M_5 = (1 + 2) \times 8 = 24$
  - $M_6 = (3 - 1)(5 + 6) = 22$
  - $M_7 = (2 - 4)(7 + 8) = -30$
- **Result Matrix $C = A \times B$:**
  $$C = \begin{bmatrix} 19 & 22 \\ 43 & 50 \end{bmatrix}$$
- **Multiplications Used:** `7` (Standard: `8`, Saved: `1`)

See [strassen_matrix_multiplication.cpp](strassen_matrix_multiplication.cpp) and [output.txt](output.txt) for step-by-step calculations.

## Recurrence & Complexity Analysis

- **Recurrence:**
  $$T(n) = 7T\left(\frac{n}{2}\right) + O(n^2)$$

| Metric | Complexity |
|---|---|
| **Time Complexity** | $O(n^{\log_2 7}) \approx O(n^{2.81})$ |
| **Space Complexity** | $O(n^2)$ |
