#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Find in-degrees of all nodes
    vector<int> indegrees(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegrees[j]++;
        }
    }

    // Queue to store nodes with zero in-degree
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegrees[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        // Store the node in the result
        ans.push_back(front);

        // Decrease in-degree of adjacent nodes
        for (int neighbor : adj[front]) {
            indegrees[neighbor]--;
            // If in-degree becomes zero, enqueue the node
            if (indegrees[neighbor] == 0)
                q.push(neighbor);
        }
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
