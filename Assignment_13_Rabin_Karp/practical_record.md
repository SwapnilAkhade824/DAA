# DAA Lab Assignment 13 — Rabin-Karp Algorithm

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002  
**Date:** 03/11/2026

## Problem Statement

Implement the **Rabin-Karp** string matching algorithm in C++ to find all occurrences of a given pattern in a text using a rolling hash.

### Hash & Rolling Hash Formula (from `Rabin Karp Concept.pdf`)
- **Hash Function:**
  $$h(s) = \sum_{i=0}^{m-1} \text{ASCII}(s[i])$$
- **Rolling Hash Update:**
  $$h_{\text{next}} = h_{\text{current}} - \text{ASCII}(\text{outgoing}) + \text{ASCII}(\text{incoming})$$

## Observed Results

### Test Case 1 (`ABABCA`, Pattern `ABC`)
- Pattern hash $h(\text{"ABC"}) = 65 + 66 + 67 = 198$
- Window 0 (`ABA`): hash = `196` $\neq 198$
- Window 1 (`BAB`): hash = `196 - 65 + 66 = 197` $\neq 198$
- Window 2 (`ABC`): hash = `197 - 66 + 67 = 198` $= 198 \implies$ **Pattern found at index `2`**
- Window 3 (`BCA`): hash = `198 - 65 + 65 = 198` $= 198 \implies$ **Spurious hit** (characters differ)

### Test Case 2 (`AABAACAADAABAABA`, Pattern `AABA`)
- Pattern hash $h(\text{"AABA"}) = 261$
- **Occurrences found at indices:** `0`, `9`, `12` (with spurious hits at indices `1` and `10` filtered by character verification).

See [rabin_karp.cpp](rabin_karp.cpp), [output.txt](output.txt), and [Rabin Karp Concept.pdf](Rabin%20Karp%20Concept.pdf).

## Complexity Analysis

| Metric | Complexity |
|---|---|
| **Best / Average Case Time** | $O(n + m)$ |
| **Worst Case Time** | $O(n \times m)$ (when many spurious hash collisions occur) |
| **Auxiliary Space** | $O(1)$ |
