# DAA Lab Assignment 8 — Median of Two Sorted Arrays

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 18/09/2026

## Problem Statement

Given two sorted arrays of equal size $n = 5$:
- $A = [1, 3, 8, 9, 15]$
- $B = [7, 11, 18, 19, 21]$

Find the median of the combined set using:
1. **Merging Method:** $O(m + n)$
2. **Divide & Conquer Method:** $O(\log n)$

Compare both approaches' time and space complexity.

## Observed Results

- **Merged Array:** `[1, 3, 7, 8, 9, 11, 15, 18, 19, 21]`
- **Middle Elements:** `9` and `11`
- **Median (Merging Method):** `10.00`
- **Median (Divide & Conquer Method):** `10.00`

See [median_two_sorted_arrays.cpp](median_two_sorted_arrays.cpp) and [output.txt](output.txt) for the full trace of both methods.

## Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| **Merging Method** | $O(m + n)$ | $O(m + n)$ (auxiliary merged array) |
| **Divide & Conquer Method** | $O(\log n)$ | $O(\log n)$ (recursion stack) |
