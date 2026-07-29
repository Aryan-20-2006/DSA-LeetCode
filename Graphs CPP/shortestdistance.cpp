//Problem-Shortest path in an Undirected grah having unit distanace

#include<bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<vector<int>>&edges,int N,int M){

int src=0;
vector<int>adj[N];

//since its an undirected graph
for(auto it:edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
}

vector<int>dist(N,1e9); //initializing all the values with infinity


dist[src]=0; //from source to source distance is zero

queue<int>q; //to store the node and its distance . We're not using pair since we already have the distance array

while(!q.empty()){
    int node=q.front();
    q.pop();

    //if there is any shorter distance then update it
    for(auto it:adj[node]){
        if(dist[it]+1<dist[it]){
            dist[it]=dist[it]+1;
            q.push(it);
        }
    }
}

//if the node is unreachable i.e when the distance is infinity 
for(int i=0;i<N;i++){
    if(dist[i]==1e9){
        dist[i]=-1;
    }
}

return dist;

}