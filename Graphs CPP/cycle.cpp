//Problem-Detect cycle in an undirected graph(using bfs)
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int>adj[], int visited[]){

    visited[src]=1;

    queue<pair<int,int>>q; //we need to store the source node,parent node

    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjacentNode:adj[node]){
            if(!visited[adjacentNode]){
                visited[adjacentNode]=1;
                q.push({adjacentNode,node});
            }

            else if(parent!=adjacentNode){ //if someone is visited it did not come from parent, then its a cycle
                return true;
            }
        }
    }

    return false;


}

bool isCycle(int V,vector<int>adj[]){

    int visited[V]={0}; //or you can write vector<int>&visited(V,0)

    //since the question uses zero based indexing
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(detect(i,adj,visited)==true){
                return true;
            }
        }
    }

    //if after visiting all the nodes, it doesnt detect a cycle return false
    return false;

}