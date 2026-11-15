# DAA Lab Assignment 9 — 0/1 Knapsack (Dynamic Programming)

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 28/09/2026

## Problem Statement

Solve the **0/1 Knapsack problem** using **Dynamic Programming** for a knapsack of maximum capacity **10 kg** and **5 items**:

| Item | Weight (kg) | Profit |
|---|---|---|
| 1 | 2 | 20 |
| 2 | 3 | 30 |
| 3 | 4 | 40 |
| 4 | 5 | 50 |
| 5 | 6 | 60 |

The program constructs and displays the DP table, finds the maximum profit, and uses **backtracking** to determine the selected items.

## Observed Results

- **Maximum Profit (`DP[5][10]`):** `100`
- **Selected Items (via Backtracking):** `Item 1 -> Item 2 -> Item 4`
- **Total Weight:** `10 kg` (`2 + 3 + 5`)
- **Total Profit:** `100` (`20 + 30 + 50`)

See [knapsack_01.cpp](knapsack_01.cpp), [input.txt](input.txt), and [output.txt](output.txt) for the full DP table construction and backtracking trace.

## Complexity Analysis

| Step / Metric | Complexity |
|---|---|
| **DP Table Construction** | $O(n \times W)$ |
| **Backtracking** | $O(n)$ |
| **Overall Time Complexity** | $O(n \times W)$ |
| **Space Complexity** | $O(n \times W)$ |
