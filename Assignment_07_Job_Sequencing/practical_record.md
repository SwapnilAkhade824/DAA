# DAA Lab Assignment 7 — Job Sequencing with Deadlines (Greedy Algorithm)

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 07/09/2026

## Problem Statement

A company has a set of jobs to complete. Each job takes 1 unit of time, has a deadline, and yields a profit only if finished on or before its deadline. Only one job can be processed at a time. Schedule the jobs using the **Greedy Approach** to maximize total profit.

**Input Jobs:**
- `J1` (Deadline = 2, Profit = 100)
- `J2` (Deadline = 1, Profit = 50)
- `J3` (Deadline = 2, Profit = 80)
- `J4` (Deadline = 3, Profit = 70)
- `J5` (Deadline = 1, Profit = 60)

## Observed Results

Sorted by profit descending: `J1 (100)`, `J3 (80)`, `J4 (70)`, `J5 (60)`, `J2 (50)`. Maximum deadline = `3`.

| Time Slot | Assigned Job | Deadline | Profit |
|---|---|---|---|
| Slot 1 | `J3` | 2 | `80` |
| Slot 2 | `J1` | 2 | `100` |
| Slot 3 | `J4` | 3 | `70` |

- **Selected Jobs:** `J3`, `J1`, `J4` (`J5` and `J2` rejected — no free slot)
- **Maximum Total Profit:** `250`

See [job_sequencing.cpp](job_sequencing.cpp) and [output.txt](output.txt) for the full slot-checking trace.

## Complexity Analysis

| Step / Metric | Complexity |
|---|---|
| **Sorting Jobs by Profit** | $O(n \log n)$ |
| **Finding Slots (Worst Case)** | $O(n^2)$ |
| **Overall Time Complexity** | $O(n^2)$ |
| **Auxiliary Space Complexity** | $O(n)$ |
