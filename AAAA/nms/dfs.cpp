#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;

    // prepare adjlist
    for (int i = 0; i < edges.size(); i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // for all nodes call the dfs if node not visited
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> edgeList(edges, vector<int>(2));

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> edgeList[i][0] >> edgeList[i][1];
    }

   vector<vector<int>> components = depthFirstSearch(vertices, edges, edgeList);

    cout << "Connected components in the graph:" << endl;
    for (const auto& component : components) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
