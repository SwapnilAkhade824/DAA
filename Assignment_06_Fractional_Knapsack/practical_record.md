# DAA Lab Assignment 6 — Fractional Knapsack (Greedy Approach)

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 05/09/2026

## Problem Statement

A delivery vehicle has a knapsack with a maximum capacity of **50 kg**. There are 3 items available:

| Item | Value | Weight (kg) |
|---|---|---|
| Item 1 | 60 | 10 |
| Item 2 | 100 | 20 |
| Item 3 | 120 | 30 |

Solve using the **Greedy Approach**:
1. Calculate the value-to-weight ratio for each item.
2. Sort items in descending order of value-to-weight ratio.
3. Greedily select items (or a fraction if an item cannot fit completely).
4. Display the maximum value and compute the time complexity.

## Observed Results

| Item | Value | Weight (kg) | Ratio (Value/Weight) | Action Taken | Value Added |
|---|---|---|---|---|---|
| Item 1 | 60 | 10 | `6.00` | Complete item (`10 kg`) | `60.00` |
| Item 2 | 100 | 20 | `5.00` | Complete item (`20 kg`) | `100.00` |
| Item 3 | 120 | 30 | `4.00` | Fraction `0.67` (`20 kg`) | `80.00` |

- **Maximum Value:** `240.00`
- **Remaining Capacity:** `0 kg`

See [fractional_knapsack.cpp](fractional_knapsack.cpp) and [output.txt](output.txt) for the complete trace.

## Complexity Analysis

| Step / Metric | Complexity |
|---|---|
| **Ratio Calculation** | $O(n)$ |
| **Sorting by Ratio** | $O(n \log n)$ |
| **Greedy Selection** | $O(n)$ |
| **Overall Time Complexity** | $O(n \log n)$ |
| **Auxiliary Space Complexity** | $O(n)$ |
