#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int V = 4;
const vector<string> VERTEX_NAMES = {"A", "B", "C", "D"};
const vector<string> COLOR_NAMES = {"None", "Red", "Green", "Blue"};

void indent(int d) {
    for (int i = 0; i < d; i++)
        cout << "    ";
}

void printAdjacencyMatrix(const int graph[V][V]) {
    cout << "Adjacency Matrix:\n";
    cout << "    ";
    for (int j = 0; j < V; j++)
        cout << setw(3) << VERTEX_NAMES[j];
    cout << "\n";
    cout << "   " << string(V * 3 + 1, '-') << "\n";

    for (int i = 0; i < V; i++) {
        cout << " " << VERTEX_NAMES[i] << " |";
        for (int j = 0; j < V; j++) {
            cout << setw(3) << graph[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

// Check if assigning color c to vertex v is valid
bool isSafe(int v, const int graph[V][V], const vector<int>& color, int c, int depth) {
    for (int u = 0; u < V; u++) {
        if (graph[v][u] == 1 && color[u] == c) {
            indent(depth);
            cout << "  Conflict: " << VERTEX_NAMES[v]
                 << " is adjacent to " << VERTEX_NAMES[u]
                 << " (already " << COLOR_NAMES[c] << ")\n";
            return false;
        }
    }
    return true;
}

// Backtracking function to solve m-coloring problem
bool graphColoringUtil(const int graph[V][V], int m, vector<int>& color, int v, int depth) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        indent(depth);
        cout << "Try " << VERTEX_NAMES[v] << " = " << COLOR_NAMES[c] << "\n";

        if (isSafe(v, graph, color, c, depth)) {
            color[v] = c;
            indent(depth);
            cout << "  Valid -> Assign " << VERTEX_NAMES[v]
                 << " = " << COLOR_NAMES[c] << "\n";

            if (graphColoringUtil(graph, m, color, v + 1, depth + 1))
                return true;

            // Backtrack
            indent(depth);
            cout << "  Backtrack: Unassign " << VERTEX_NAMES[v]
                 << " (" << COLOR_NAMES[c] << ")\n";
            color[v] = 0;
        }
    }

    indent(depth);
    cout << "No valid color for " << VERTEX_NAMES[v] << " -> Backtracking\n";
    return false;
}

int main() {
    // Vertices: A(0), B(1), C(2), D(3)
    // Edges: A-B, A-C, B-C, B-D, C-D
    int graph[V][V] = {
        {0, 1, 1, 0}, // A
        {1, 0, 1, 1}, // B
        {1, 1, 0, 1}, // C
        {0, 1, 1, 0}  // D
    };

    vector<int> color(V, 0);

    cout << "========================================\n";
    cout << "   GRAPH COLORING USING BACKTRACKING\n";
    cout << "========================================\n\n";

    cout << "Vertices: A, B, C, D\n";
    cout << "Edges   : A-B, A-C, B-C, B-D, C-D\n\n";

    printAdjacencyMatrix(graph);

    // Case 1: 2 colors (Red, Green)
    int m2 = 2;
    fill(color.begin(), color.end(), 0);
    cout << "========================================\n";
    cout << "CASE 1: USING 2 COLORS (Red, Green)\n";
    cout << "========================================\n\n";

    bool possible2 = graphColoringUtil(graph, m2, color, 0, 0);

    cout << "\nResult (m = 2): ";
    if (possible2) {
        cout << "Solution exists:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << VERTEX_NAMES[i]
                 << " -> " << COLOR_NAMES[color[i]] << "\n";
        }
    } else {
        cout << "No solution exists using 2 colors (Red, Green).\n";
        cout << "Reason: The graph contains odd cycles (triangles A-B-C and B-C-D),\n";
        cout << "so at least 3 colors are required.\n";
    }

    // Case 2: 3 colors (Red, Green, Blue) - Successful coloring
    int m3 = 3;
    fill(color.begin(), color.end(), 0);
    cout << "\n========================================\n";
    cout << "CASE 2: USING 3 COLORS (Red, Green, Blue)\n";
    cout << "========================================\n\n";

    bool possible3 = graphColoringUtil(graph, m3, color, 0, 0);

    cout << "\nResult (m = 3): ";
    if (possible3) {
        cout << "Solution found using 3 colors:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << VERTEX_NAMES[i]
                 << " -> " << COLOR_NAMES[color[i]] << "\n";
        }
    } else {
        cout << "No solution exists using 3 colors.\n";
    }

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";
    cout << "Time Complexity  = O(m^V) worst case\n";
    cout << "Space Complexity = O(V^2) adjacency matrix + O(V) recursion stack\n";

    return 0;
}
