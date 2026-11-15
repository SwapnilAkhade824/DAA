# DAA Lab Assignment 2 — Quick Sort (Fixed Pivot)

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 24/08/2026

## Problem Statement

Given $A = [24, 9, 29, 14, 19, 27]$, sort using **Quick Sort** with the **last element as pivot**:
- Show the array after each partition and mark the pivot's final position.
- Count the number of swaps.
- Run the same code on the already-sorted input $[9, 14, 19, 24, 27, 29]$ and count comparisons.
- Explain why the sorted input is the worst case, and give best/average/worst time complexity and space complexity.

## Observed Results

| Input Case | Array | Sorted Array | Total Comparisons | Total Swaps |
|---|---|---|---|---|
| **Original Input** | `[24, 9, 29, 14, 19, 27]` | `[9, 14, 19, 24, 27, 29]` | `9` | `6` |
| **Already Sorted Input** | `[9, 14, 19, 24, 27, 29]` | `[9, 14, 19, 24, 27, 29]` | `15` | `0` |

See [quick_sort.cpp](quick_sort.cpp) and [output.txt](output.txt) for the complete partition trace.

### Why Sorted Input Is the Worst Case

When the array is already sorted and the **last element** is always chosen as the pivot, the pivot is the largest element in the subarray. Every partition splits an array of size $n$ into subarrays of size $(n - 1)$ and $0$, resulting in $n - 1$ recursive levels and $\frac{n(n-1)}{2} = \frac{6 \times 5}{2} = 15$ comparisons.

## Complexity Analysis

| Metric | Complexity |
|---|---|
| **Best Case Time** | $O(n \log n)$ |
| **Average Case Time** | $O(n \log n)$ |
| **Worst Case Time** | $O(n^2)$ |
| **Average Space (Stack)** | $O(\log n)$ |
| **Worst Space (Stack)** | $O(n)$ |
