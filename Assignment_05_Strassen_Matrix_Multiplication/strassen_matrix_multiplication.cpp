#include <iostream>
using namespace std;

int main() {
    // Matrix A
    int A[2][2] = {
        {1, 2},
        {3, 4}
    };

    // Matrix B
    int B[2][2] = {
        {5, 6},
        {7, 8}
    };

    int multiplicationCount = 0;

    cout << "========================================\n";
    cout << "   STRASSEN MATRIX MULTIPLICATION 2x2\n";
    cout << "========================================\n\n";

    cout << "Matrix A:\n";
    cout << "[ " << A[0][0] << " " << A[0][1] << " ]\n";
    cout << "[ " << A[1][0] << " " << A[1][1] << " ]\n\n";

    cout << "Matrix B:\n";
    cout << "[ " << B[0][0] << " " << B[0][1] << " ]\n";
    cout << "[ " << B[1][0] << " " << B[1][1] << " ]\n\n";

    // ------------------------------------------------
    // STRASSEN'S 7 PRODUCTS
    // ------------------------------------------------

    cout << "========================================\n";
    cout << "STEP 1: CALCULATE M1 - M7\n";
    cout << "========================================\n\n";

    // M1 = (a11 + a22)(b11 + b22)
    int M1 = (A[0][0] + A[1][1]) *
             (B[0][0] + B[1][1]);
    multiplicationCount++;

    cout << "M1 = (a11 + a22)(b11 + b22)\n";
    cout << "   = (" << A[0][0] << " + " << A[1][1] << ")"
         << " * (" << B[0][0] << " + " << B[1][1] << ")\n";
    cout << "   = " << (A[0][0] + A[1][1])
         << " * " << (B[0][0] + B[1][1]) << endl;
    cout << "   = " << M1 << "\n\n";

    // M2 = (a21 + a22)b11
    int M2 = (A[1][0] + A[1][1]) *
             B[0][0];
    multiplicationCount++;

    cout << "M2 = (a21 + a22)b11\n";
    cout << "   = (" << A[1][0] << " + " << A[1][1] << ")"
         << " * " << B[0][0] << "\n";
    cout << "   = " << (A[1][0] + A[1][1])
         << " * " << B[0][0] << endl;
    cout << "   = " << M2 << "\n\n";

    // M3 = a11(b12 - b22)
    int M3 = A[0][0] *
             (B[0][1] - B[1][1]);
    multiplicationCount++;

    cout << "M3 = a11(b12 - b22)\n";
    cout << "   = " << A[0][0]
         << " * (" << B[0][1]
         << " - " << B[1][1] << ")\n";
    cout << "   = " << A[0][0]
         << " * " << (B[0][1] - B[1][1]) << endl;
    cout << "   = " << M3 << "\n\n";

    // M4 = a22(b21 - b11)
    int M4 = A[1][1] *
             (B[1][0] - B[0][0]);
    multiplicationCount++;

    cout << "M4 = a22(b21 - b11)\n";
    cout << "   = " << A[1][1]
         << " * (" << B[1][0]
         << " - " << B[0][0] << ")\n";
    cout << "   = " << A[1][1]
         << " * " << (B[1][0] - B[0][0]) << endl;
    cout << "   = " << M4 << "\n\n";

    // M5 = (a11 + a12)b22
    int M5 = (A[0][0] + A[0][1]) *
             B[1][1];
    multiplicationCount++;

    cout << "M5 = (a11 + a12)b22\n";
    cout << "   = (" << A[0][0]
         << " + " << A[0][1] << ")"
         << " * " << B[1][1] << "\n";
    cout << "   = " << (A[0][0] + A[0][1])
         << " * " << B[1][1] << endl;
    cout << "   = " << M5 << "\n\n";

    // M6 = (a21 - a11)(b11 + b12)
    int M6 = (A[1][0] - A[0][0]) *
             (B[0][0] + B[0][1]);
    multiplicationCount++;

    cout << "M6 = (a21 - a11)(b11 + b12)\n";
    cout << "   = (" << A[1][0]
         << " - " << A[0][0] << ")"
         << " * (" << B[0][0]
         << " + " << B[0][1] << ")\n";
    cout << "   = " << (A[1][0] - A[0][0])
         << " * " << (B[0][0] + B[0][1]) << endl;
    cout << "   = " << M6 << "\n\n";

    // M7 = (a12 - a22)(b21 + b22)
    int M7 = (A[0][1] - A[1][1]) *
             (B[1][0] + B[1][1]);
    multiplicationCount++;

    cout << "M7 = (a12 - a22)(b21 + b22)\n";
    cout << "   = (" << A[0][1]
         << " - " << A[1][1] << ")"
         << " * (" << B[1][0]
         << " + " << B[1][1] << ")\n";
    cout << "   = " << (A[0][1] - A[1][1])
         << " * " << (B[1][0] + B[1][1]) << endl;
    cout << "   = " << M7 << "\n\n";

    // ------------------------------------------------
    // ASSEMBLE RESULT MATRIX
    // ------------------------------------------------

    cout << "========================================\n";
    cout << "STEP 2: ASSEMBLE MATRIX C\n";
    cout << "========================================\n\n";

    // C11 = M1 + M4 - M5 + M7
    int C11 = M1 + M4 - M5 + M7;

    cout << "C11 = M1 + M4 - M5 + M7\n";
    cout << "    = " << M1 << " + " << M4
         << " - " << M5 << " + " << M7 << endl;
    cout << "    = " << C11 << "\n\n";

    // C12 = M3 + M5
    int C12 = M3 + M5;

    cout << "C12 = M3 + M5\n";
    cout << "    = " << M3 << " + " << M5 << endl;
    cout << "    = " << C12 << "\n\n";

    // C21 = M2 + M4
    int C21 = M2 + M4;

    cout << "C21 = M2 + M4\n";
    cout << "    = " << M2 << " + " << M4 << endl;
    cout << "    = " << C21 << "\n\n";

    // C22 = M1 - M2 + M3 + M6
    int C22 = M1 - M2 + M3 + M6;

    cout << "C22 = M1 - M2 + M3 + M6\n";
    cout << "    = " << M1 << " - " << M2
         << " + " << M3 << " + " << M6 << endl;
    cout << "    = " << C22 << "\n\n";

    // ------------------------------------------------
    // FINAL RESULT
    // ------------------------------------------------

    cout << "========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n\n";

    cout << "Matrix C = A x B:\n";
    cout << "[ " << C11 << " " << C12 << " ]\n";
    cout << "[ " << C21 << " " << C22 << " ]\n";

    cout << "\nTotal Matrix Multiplications using Strassen = "
         << multiplicationCount << endl;

    cout << "Standard Matrix Multiplications             = 8\n";

    cout << "Multiplications Saved = "
         << 8 - multiplicationCount << endl;

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";

    cout << "Recurrence       = T(n) = 7T(n/2) + O(n^2)\n";
    cout << "Time Complexity  = O(n^log2(7))\n";
    cout << "Approximately    = O(n^2.81)\n";
    cout << "Space Complexity = O(n^2)\n";

    return 0;
}
