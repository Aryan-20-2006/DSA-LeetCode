//Problem-Shortest path in a DAG

#include<bits/stdc++.h>
using namespace std;



vector<int>topoSort(int node,vector<pair<int,int>>adj[],vector<int>&visited,stack<int>st){

    visited[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!visited[v]){
            topoSort(node,adj,visited,st);
        }
    }

    st.push(node);

}

vector<int>shortestPath(int N, int M, vector<vector<int>>&edges){

//create the graph-since we're storing the node and the weight

vector<pair<int,int>>adj[N];

for(int i=0;i<M;i++){
    int u=edges[i][0]; //every edge has a vector
    int v=edges[i][1];
    int w=edges[i][2];
    adj[u].push_back({v,w});
}

//Step1-Find the toposort
vector<int>visited(N,0);
stack<int>st;

for(int i=0;i<N;i++){
    if(!visited[i]){
        topoSort(i,adj,visited,st);
    }
}

//Step 2-Take the nodes out of the stack and find their distances
vector<int>dist(N,1e9);

dist[0]=0 ;//assuming this to be the source node

while(!st.empty()){
    int node=st.top();
    st.pop();

    for(auto it:adj[node]){
        int v=it.first;
        int w=it.second;

        if(dist[node]+w<dist[node]){
            dist[node]=w+dist[node];
        }

    }
}

for(int i=0;i<N;i++){
    if(dist[i]==1e9){
        dist[i]=-1;
    }
}

return dist;


}