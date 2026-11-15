# DAA Lab Assignment 4 — Max–Min using Divide and Conquer

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 24/08/2026

## Problem Statement

Given $A = [70, 250, 50, 80, 140, 12, 14]$, find the **maximum** and **minimum** using the divide-and-conquer pair method:
- Show the recursion.
- Count the exact number of comparisons and compare it against the straightforward scan, which uses $2(n - 1)$.
- State the recurrence and the time and space complexity.

## Observed Results

- **Array:** `[70, 250, 50, 80, 140, 12, 14]` ($n = 7$)
- **Maximum:** `250`
- **Minimum:** `12`
- **Divide & Conquer Comparisons:** `9`
- **Straightforward Scan Comparisons:** $2(n - 1) = 12$
- **Comparisons Saved:** `3`

See [max_min.cpp](max_min.cpp) and [output.txt](output.txt) for the full recursion tree trace.

## Recurrence & Complexity Analysis

- **Recurrence:**
  $$T(n) = 2T\left(\frac{n}{2}\right) + 2 \implies \approx \frac{3n}{2} - 2 \text{ comparisons}$$

| Metric | Complexity |
|---|---|
| **Time Complexity** | $O(n)$ |
| **Space Complexity (Recursion Stack)** | $O(\log n)$ |
