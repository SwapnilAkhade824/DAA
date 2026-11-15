# DAA Lab Assignment 3 — Binary Search

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 24/08/2026

## Problem Statement

Given the sorted array $A = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]$:
- Search for key `23` and list `low`, `mid`, `high` at every step.
- Search for key `40` and do the same.
- Count comparisons in each case.
- State the recurrence, time complexity, and space complexity for both the **iterative** and **recursive** versions.

## Observed Results

| Method | Key | Result | Comparisons |
|---|---|---|---|
| **Iterative Binary Search** | `23` | Found at index `5` | `3` |
| **Iterative Binary Search** | `40` | Not Found | `4` |
| **Recursive Binary Search** | `23` | Found at index `5` | `3` |
| **Recursive Binary Search** | `40` | Not Found | `4` |

See [binary_search.cpp](binary_search.cpp) and [output.txt](output.txt) for the step-by-step `low`, `mid`, `high` trace.

## Recurrence & Complexity Analysis

- **Recurrence:** $T(n) = T\left(\frac{n}{2}\right) + 1 \implies O(\log n)$

| Version | Time Complexity | Space Complexity |
|---|---|---|
| **Iterative Binary Search** | $O(\log n)$ | $O(1)$ |
| **Recursive Binary Search** | $O(\log n)$ | $O(\log n)$ (recursion stack) |
