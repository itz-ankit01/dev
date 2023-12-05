#include <bits/stdc++.h>
using namespace std;
void createadj(  unordered_map<int,list<int>> &adj,vector<pair<int,int>>&edges){


    for(int i=0;i<edges.size();i++){
       int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    
    }
}
void bfs(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans,int i){

    queue<int>q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int frontnode=i;
        q.pop();
        ans.push_back(frontnode);
        for(j:adj[frontnode]){
            if(![visited[j]]){
                visited[j]=true;
               q.push(i);
            }
        }

    }


}



void BFS(int vertex,vector<pair<int,int>>&edges)
{
    unordered_map<int,list<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;
    createadj(adj,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
}


int main(){

int v=5;
 vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}}; // Edges of the graph

 vector<int>result=BFS(v,edges);
}