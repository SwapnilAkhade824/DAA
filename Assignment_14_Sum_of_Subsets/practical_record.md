# DAA Lab Assignment 14 — Sum of Subsets Using Branch and Bound

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 05/11/2026

## Aim

To design and implement the **Sum of Subsets** problem using the **Branch and Bound** approach in C++.

## Problem Statement

Given a set of positive integers `{5, 10, 12, 13, 15, 18}` and a target sum `30`, find all subsets whose elements add up to the target sum using Branch and Bound.

## Bounding & Pruning Rules

1. **Solution Found:** If `currentSum == target`, record the subset.
2. **Upper Bound Prune:** If `currentSum > target`, prune the branch (positive integers cannot decrease the sum).
3. **Lower Bound Prune:** If `currentSum + remainingSum < target`, prune the branch (even taking all remaining elements cannot reach the target).

## Observed Results

- **Input Set:** `{ 5, 10, 12, 13, 15, 18 }`, **Target Sum:** `30`
- **Subsets Found:**
  - `{ 5 10 15 }`
  - `{ 5 12 13 }`
  - `{ 12 18 }`
- **Nodes Explored:** `87`
- **Branches Pruned:** `41`

See [sum_of_subsets.cpp](sum_of_subsets.cpp), [input.txt](input.txt), and [output.txt](output.txt).

## Complexity Analysis

| Case | Complexity |
|---|---|
| **Worst-case Time** | $O(2^n)$ (when pruning is ineffective and the full state-space tree is explored) |
| **Worst-case Space** | $O(n)$ (maximum recursion depth is $n$) |
