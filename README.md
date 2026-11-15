# DAA Lab Assignments

Design and Analysis of Algorithms (DAA) Lab Assignments — organized by assignment with source code (`.cpp`), program output (`output.txt`), and original lab PDFs.

## Repository Structure

| # | Topic | Folder | Source | Output | Record |
|---|-------|--------|--------|--------|--------|
| 1 | Merge Sort (Trace & Analysis) | `Assignment_01_Merge_Sort` | [merge_sort.cpp](Assignment_01_Merge_Sort/merge_sort.cpp) | [output.txt](Assignment_01_Merge_Sort/output.txt) | [practical_record.md](Assignment_01_Merge_Sort/practical_record.md) |
| 2 | Quick Sort (Fixed Pivot) | `Assignment_02_Quick_Sort` | [quick_sort.cpp](Assignment_02_Quick_Sort/quick_sort.cpp) | [output.txt](Assignment_02_Quick_Sort/output.txt) | [practical_record.md](Assignment_02_Quick_Sort/practical_record.md) |
| 3 | Binary Search (Iterative & Recursive) | `Assignment_03_Binary_Search` | [binary_search.cpp](Assignment_03_Binary_Search/binary_search.cpp) | [output.txt](Assignment_03_Binary_Search/output.txt) | [practical_record.md](Assignment_03_Binary_Search/practical_record.md) |
| 4 | Max–Min using Divide and Conquer | `Assignment_04_Max_Min` | [max_min.cpp](Assignment_04_Max_Min/max_min.cpp) | [output.txt](Assignment_04_Max_Min/output.txt) | [practical_record.md](Assignment_04_Max_Min/practical_record.md) |
| 5 | Strassen's 2×2 Matrix Multiplication | `Assignment_05_Strassen_Matrix_Multiplication` | [strassen_matrix_multiplication.cpp](Assignment_05_Strassen_Matrix_Multiplication/strassen_matrix_multiplication.cpp) | [output.txt](Assignment_05_Strassen_Matrix_Multiplication/output.txt) | [practical_record.md](Assignment_05_Strassen_Matrix_Multiplication/practical_record.md) |
| 6 | Fractional Knapsack (Greedy) | `Assignment_06_Fractional_Knapsack` | [fractional_knapsack.cpp](Assignment_06_Fractional_Knapsack/fractional_knapsack.cpp) | [output.txt](Assignment_06_Fractional_Knapsack/output.txt) | [practical_record.md](Assignment_06_Fractional_Knapsack/practical_record.md) |
| 7 | Job Sequencing with Deadlines (Greedy) | `Assignment_07_Job_Sequencing` | [job_sequencing.cpp](Assignment_07_Job_Sequencing/job_sequencing.cpp) | [output.txt](Assignment_07_Job_Sequencing/output.txt) | [practical_record.md](Assignment_07_Job_Sequencing/practical_record.md) |
| 8 | Median of Two Sorted Arrays | `Assignment_08_Median_Two_Sorted_Arrays` | [median_two_sorted_arrays.cpp](Assignment_08_Median_Two_Sorted_Arrays/median_two_sorted_arrays.cpp) | [output.txt](Assignment_08_Median_Two_Sorted_Arrays/output.txt) | [practical_record.md](Assignment_08_Median_Two_Sorted_Arrays/practical_record.md) |
| 9 | 0/1 Knapsack (Dynamic Programming) | `Assignment_09_01_Knapsack` | [knapsack_01.cpp](Assignment_09_01_Knapsack/knapsack_01.cpp) | [output.txt](Assignment_09_01_Knapsack/output.txt) | [practical_record.md](Assignment_09_01_Knapsack/practical_record.md) |
| 10 | Randomized Quick Sort vs Ordinary Quick Sort | `Assignment_10_Randomized_Quick_Sort` | [randomized_quick_sort.cpp](Assignment_10_Randomized_Quick_Sort/randomized_quick_sort.cpp) | [output.txt](Assignment_10_Randomized_Quick_Sort/output.txt) | [practical_record.md](Assignment_10_Randomized_Quick_Sort/practical_record.md) |
| 11 | Graph Coloring (Backtracking) | `Assignment_11_Graph_Coloring` | [graph_coloring.cpp](Assignment_11_Graph_Coloring/graph_coloring.cpp) | [output.txt](Assignment_11_Graph_Coloring/output.txt) | [practical_record.md](Assignment_11_Graph_Coloring/practical_record.md) |
| 12 | String Matching (Naive) | `Assignment_12_String_Matching` | [naive_string_matching.cpp](Assignment_12_String_Matching/naive_string_matching.cpp) | [output.txt](Assignment_12_String_Matching/output.txt) | [practical_record.md](Assignment_12_String_Matching/practical_record.md) |
| 13 | Rabin-Karp Pattern Searching | `Assignment_13_Rabin_Karp` | [rabin_karp.cpp](Assignment_13_Rabin_Karp/rabin_karp.cpp) | [output.txt](Assignment_13_Rabin_Karp/output.txt) | [practical_record.md](Assignment_13_Rabin_Karp/practical_record.md) |
| 14 | Sum of Subsets (Branch and Bound) | `Assignment_14_Sum_of_Subsets` | [sum_of_subsets.cpp](Assignment_14_Sum_of_Subsets/sum_of_subsets.cpp) | [output.txt](Assignment_14_Sum_of_Subsets/output.txt) | [practical_record.md](Assignment_14_Sum_of_Subsets/practical_record.md) |

## Build & Run

```powershell
g++ -std=c++17 <folder>/<file>.cpp -o main.exe
.\main.exe
```

For Assignment 9 (interactive input):

```powershell
Get-Content Assignment_09_01_Knapsack/input.txt | .\main.exe
```
