#include <bits/stdc++.h>

using namespace std;

void topologicalSortDFS(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(neighbor, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, visited, s, adj);

        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    // Example usage
    int v = 6, e = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological ordering: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
