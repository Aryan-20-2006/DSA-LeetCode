//Problem-Find the nearest clone
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int src,int n,vector<vector<int>>&adj){

//create the distance array
vector<int>dist(n+1,1e9);


dist[src]=0; //distance from starting node to itself is zero

queue<int>q; 

q.push({src}); //pushing the starting node into the queue

while(!q.empty()){
    int node=q.front();
    q.pop();

    for(auto it:adj[node]){
        if(dist[node]+1<dist[it]){
            dist[it]=dist[node]+1;
            q.push({it});
        }
    }
    
}

return dist;

}

int findShortest(int n,vector<int>graph_from,vector<int>graph_to,vector<long>ids,int val){

//build the graph
vector<vector<int>>adj(n+1); //since the nodes start from 1 using 1 based indexing

for(int i=0;i<graph_from.size();i++){ //Note:-here graph_from.size() are the edges you are looping over
    adj[graph_from[i]].push_back(graph_to[i]);
    adj[graph_to[i]].push_back(graph_from[i]);
}

//Step 1:Grouping the nodes by color
unordered_map<int,vector<int>>colorGroups; //key is the color, value is the list of node ids that have that color

for(int i=0;i<n;i++){
    colorGroups[ids[i]].push_back(i+1); //using 1 based indexing so i+1
}

//Step 2:Checking what to compute per color group
int mini=INT_MAX;

vector<int>group=colorGroups[val];

//if no pairs of the same color exist, return a -1
if(group.size()<=1)
    return -1;

for(int i=0;i<group.size();i++){
    int u=group[i]; //node you are starting from

    vector<int>dist=bfs(u,n,adj); //distance from u to all the other nodes

    for(int j=i+1;j<group.size();j++){ //starting at j=i+1 to avoid computing the same pair again
        int v=group[j];
        mini=min(mini,dist[v]);
    }
}


return mini;

}