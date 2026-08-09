//Problem-Cheapest flight with at most K stops
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int CheapestFlight(int n,vector<vector<int>>&flights,int src,int dst,int k){

//create the graph-storing the nodes and the weights
vector<pair<int,int>>adj[n];

for(auto it:flights){
    adj[it[0]].push_back({it[1],it[2]});
}

//distance array
vector<int>dist(n,1e9);

dist[src]=0;

//queue({stops,{node,cost}})

queue<pair<int,pair<int,int>>>q;

q.push({0,{src,0}});

while(!q.empty()){
    int stops=q.front().first;
    int node=q.front().second.first;
    int cost=q.front().second.second;
    q.pop();

    //you can go upto k stops, if it exceeds dont go further
    if(stops>k){
        continue;
    }

    //Note-Since I used vector<pair so .first and .second are the correct way to write not it[0] and it[1]
    for(auto it:adj[node]){
        int adjnode=it.first;
        int edgeweight=it.second;

        if(cost+edgeweight<dist[adjnode]){
            dist[adjnode]=cost+edgeweight;
            q.push({stops+1,{adjnode,dist[adjnode]}});
        }
    }
}

//if you cant reach the destination
if(dist[dst]==1e9)
    return -1;

return dist[dst]; 


}