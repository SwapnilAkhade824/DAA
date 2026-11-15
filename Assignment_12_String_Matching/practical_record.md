# DAA Lab Assignment 12 — String Matching Algorithm

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 02/11/2026

## Aim

To design and implement the **Naive String Matching** algorithm in C++ to identify all occurrences of a given pattern in a text.

## Problem Statement

Given a text string `AABAACAADAABAABA` ($n = 16$) and a pattern string `AABA` ($m = 4$), find all starting indices where the pattern occurs in the text.

## Algorithm Steps

1. Start from the first character of the text (`i = 0`).
2. Compare the pattern with the substring of length $m$ starting at `i`.
3. If all $m$ characters match, record the starting index `i`.
4. Shift the pattern by one position (`i + 1`) and repeat until `i = n - m`.

## Observed Dry-Run Table

| Position | Substring | Result |
|---|---|---|
| 0 | `AABA` | **Match** |
| 1 | `ABAA` | No match |
| 2 | `BAAC` | No match |
| 3 | `AACA` | No match |
| 4 | `ACAA` | No match |
| 5 | `CAAD` | No match |
| 6 | `AADA` | No match |
| 7 | `ADAA` | No match |
| 8 | `DAAB` | No match |
| 9 | `AABA` | **Match** |
| 10 | `ABAA` | No match |
| 11 | `BAAB` | No match |
| 12 | `AABA` | **Match** |

**Final Result:** Pattern found at indices `0`, `9`, and `12`.

See [naive_string_matching.cpp](naive_string_matching.cpp) and [output.txt](output.txt).

## Complexity Analysis

Let $n$ = length of text, $m$ = length of pattern.

| Case | Complexity |
|---|---|
| **Best Case Time** | $O(n)$ |
| **Average Case Time** | $O(n \times m)$ |
| **Worst Case Time** | $O(n \times m)$ |
| **Space Complexity** | $O(1)$ |
