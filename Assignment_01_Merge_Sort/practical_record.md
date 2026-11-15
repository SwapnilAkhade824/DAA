# DAA Lab Assignment 1 — Merge Sort

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 24/08/2026

## Problem Statement

Given $A = [38, 27, 43, 3, 9, 82, 10]$, sort it using **Merge Sort**:
- Show every split and every merge step.
- Count the total number of comparisons made during merging.
- State the recurrence and solve it.
- Give the time complexity for best/average/worst case and the space complexity.

## Observed Results

- **Original Array:** `[38, 27, 43, 3, 9, 82, 10]`
- **Sorted Array:** `[3, 9, 10, 27, 38, 43, 82]`
- **Total Comparisons:** `14`

See [merge_sort.cpp](merge_sort.cpp) and [output.txt](output.txt) for the full indented divide-and-merge trace.

## Recurrence & Complexity Analysis

- **Recurrence:**
  $$T(n) = 2T\left(\frac{n}{2}\right) + n = O(n \log n)$$
  (By Master Theorem: $a = 2, b = 2, f(n) = n \implies n^{\log_2 2} = n \implies \Theta(n \log n)$.)

| Metric | Complexity |
|---|---|
| **Best Case Time** | $O(n \log n)$ |
| **Average Case Time** | $O(n \log n)$ |
| **Worst Case Time** | $O(n \log n)$ |
| **Auxiliary Space** | $O(n)$ (temporary merge array) |
| **Recursion Stack Space** | $O(\log n)$ |
