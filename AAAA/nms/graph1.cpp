#include <bits/stdc++.h>
using namespace std;
//adjancy listtt 
    unordered_map<int,list<int>>adj;
     void addedge(int u,int v,bool direction){
        //direction=0->undirected
        //direction =1->directed


        //create an edge from u to v
        adj[u].push_back(v);
        if(direction==0)
        adj[v].push_back(u);

     }

     void printadj(){


        for(auto i:adj){
            cout<<i.first<<"->",
            for(auto j:i.second){
                cout<<j<<",";
            }
        }
     }

     int main(){

        int n;
        cout<<"enter the number of the nodes"<<end;
        cin>>n;
        int m;
        cout<<"enter the number of edges"<<endl;
        cin>>m;

        graph g;
      
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                //creating an undirected graph
                g.addedge(u,v,0);

            }
            //print the graph
            g.printadj();

            return 0;

        }


     
