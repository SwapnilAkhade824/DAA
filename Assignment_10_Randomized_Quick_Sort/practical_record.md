# DAA Lab Assignment 10 — Randomized Quick Sort

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002

## Problem Statement

Implement **Randomized Quick Sort** (a Las Vegas algorithm that always produces the correct sorted output with random runtime) and compare it against **Ordinary Quick Sort** (always choosing the last element as pivot).

Test both algorithms on:
1. Unsorted array: `[24, 9, 29, 14, 19, 27]`
2. Sorted array: `[9, 14, 19, 24, 27, 29]`
3. Reverse-sorted array: `[29, 27, 24, 19, 14, 9]`
4. Array with duplicate elements: `[5, 2, 5, 1, 2]`

## Observed Comparison Results

| Test Case | Input | Randomized Quick Sort (Comparisons / Swaps) | Ordinary Quick Sort (Comparisons / Swaps) |
|---|---|---|---|
| Unsorted Array | `[24, 9, 29, 14, 19, 27]` | `11` / `6` | `9` / `6` |
| Sorted Array | `[9, 14, 19, 24, 27, 29]` | `9` / `4` | `15` / `0` |
| Reverse-Sorted Array | `[29, 27, 24, 19, 14, 9]` | `9` / `7` | `15` / `3` |
| Duplicate Elements | `[5, 2, 5, 1, 2]` | `8` / `5` | `6` / `4` |

### Key Observations

- On **sorted** and **reverse-sorted** inputs ($n = 6$), Ordinary Quick Sort (fixed last-element pivot) degenerates into its worst case, making $\frac{n(n-1)}{2} = 15$ comparisons because every partition produces an unbalanced split of size $(n-1)$ and $0$.
- **Randomized Quick Sort** picks a random pivot in `[low, high]`, breaking adversarial input orderings and reducing comparisons on both sorted and reverse-sorted inputs from `15` down to `9`.
- Both algorithms handle duplicate elements (`5 2 5 1 2`) correctly, producing `[1, 2, 2, 5, 5]`.

## Time & Space Complexity Comparison

| Metric | Randomized Quick Sort | Ordinary Quick Sort (Last Pivot) |
|---|---|---|
| **Algorithm Type** | Las Vegas (always correct, randomized runtime) | Deterministic |
| **Best Case Time** | $O(n \log n)$ | $O(n \log n)$ |
| **Average / Expected Time** | $O(n \log n)$ (for *every* input) | $O(n \log n)$ (assumes random input) |
| **Worst Case Time** | $O(n^2)$ (vanishingly rare, independent of input order) | $O(n^2)$ (always triggered by sorted / reverse-sorted input) |
| **Space Complexity (Recursion Stack)** | $O(\log n)$ expected, $O(n)$ worst | $O(\log n)$ average, $O(n)$ worst |
