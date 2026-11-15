# DAA Lab Assignment 11 — Graph Coloring (Backtracking)

**Name:** Swapnil Santosh Akhade  
**PRN:** 202401110002

## 1. Aim

To implement the **Graph Coloring Problem** using the **Backtracking** approach in C++.

## 2. Problem Statement

Write a C++ program to color a graph consisting of four vertices (`A`, `B`, `C`, and `D`) using **two colors** (`Red` and `Green`) such that no two adjacent vertices share the same color.

## 3. Graph & Adjacency Matrix

- **Vertices:** `A`, `B`, `C`, `D`
- **Edges:** `A–B`, `A–C`, `B–C`, `B–D`, `C–D`

```
    A
   / \
  B---C
   \ /
    D
```

**Adjacency Matrix** (`1` = connected, `0` = unconnected):

|   | A | B | C | D |
|---|---|---|---|---|
| **A** | 0 | 1 | 1 | 0 |
| **B** | 1 | 0 | 1 | 1 |
| **C** | 1 | 1 | 0 | 1 |
| **D** | 0 | 1 | 1 | 0 |

## 4. Observed Results

- **Case 1 (`m = 2`: Red, Green):** Starting with `A = Red` forces `B = Green`, leaving `C` adjacent to both `Red` (`A`) and `Green` (`B`). Backtracking to `A = Green` forces `B = Red`, again leaving `C` with no valid color. **Result:** `No solution exists using 2 colors (Red, Green).`
- **Case 2 (`m = 3`: Red, Green, Blue):** A valid coloring is found:
  - `Vertex A -> Red`
  - `Vertex B -> Green`
  - `Vertex C -> Blue`
  - `Vertex D -> Red`

See [graph_coloring.cpp](graph_coloring.cpp) and [output.txt](output.txt) for the full backtracking trace.

## 5. Complexity Analysis

| Metric | Complexity |
|---|---|
| **Time Complexity (Worst Case)** | $O(m^V)$ (here $m = 2, V = 4$) |
| **Space Complexity** | $O(V^2)$ for adjacency matrix + $O(V)$ for recursion stack |

## 6. Conclusion

Backtracking solves the graph coloring problem by assigning colors vertex by vertex and immediately undoing (backtracking from) any assignment when a vertex has no valid color that avoids conflicts with its already-colored neighbors. Exhaustively exploring all valid partial assignments confirms that the given graph **cannot be colored using two colors** because it contains odd cycles (the triangles `A–B–C` and `B–C–D`), which require at least three colors.
