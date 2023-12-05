#include <bits/stdc++.h>
using namespace std;

// Function to create an adjacency list representation of the graph
void prepareadjlist(unordered_map<int, list<int>>& adjlist, vector<pair<int, int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first; // Extracting the first node of the edge
        int v = edges[i].second; // Extracting the second node of the edge

        // Adding edges to the adjacency list (undirected graph)
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

// Breadth-First Search (BFS) algorithm
void bfs(unordered_map<int, list<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q; // Queue for BFS traversal
    q.push(node); // Push the starting node into the queue

    visited[node] = true; // Mark the starting node as visited

    while (!q.empty()) { // While there are nodes in the queue
        int frontnode = q.front(); // Get the front node from the queue
        q.pop(); // Remove the front node from the queue

        ans.push_back(frontnode); // Add the front node to the result vector

        // Traverse all adjacent nodes of the current node
        for (auto i : adjlist[frontnode]) {
            if (!visited[i]) {
                q.push(i); // Push unvisited adjacent nodes into the queue
                visited[i] = true; // Mark them as visited
            }
        }
    }
}

// Function to perform BFS traversal on the graph
vector<int> BFS(int vertex, vector<pair<int, int>> edge) {
    unordered_map<int, list<int>> adjlist; // Adjacency list representation of the graph
    vector<int> ans; // Vector to store the BFS traversal result
    unordered_map<int, bool> visited; // Map to keep track of visited nodes

    prepareadjlist(adjlist, edge); // Create the adjacency list representation

    // Iterate through all nodes and perform BFS if not visited before
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjlist, visited, ans, i); // Call BFS for unvisited nodes
        }
    }

    return ans; // Return the BFS traversal result
}

// Main function
int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}}; // Edges of the graph

    vector<int> result = BFS(V, edges); // Perform BFS traversal

    // Output the BFS traversal result
    cout << "BFS Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
