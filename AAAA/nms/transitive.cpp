#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transitiveClosure(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<vector<int>> closure = graph;

    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    return closure;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    vector<vector<int>> result = transitiveClosure(graph);

    cout << "Transitive Closure:" << endl;
    printMatrix(result);

    return 0;
}
