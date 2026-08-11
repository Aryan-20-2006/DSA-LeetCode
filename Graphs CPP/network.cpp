//Problem-Network Delay Time
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>&times, int n,int k){

//create the graph-(u,v,w)

vector<pair<int,int>>adj[n+1];

for(auto it:times){
    adj[it[0]].push_back({it[1],it[2]}); //storing the edge and the weights
}

vector<int>dist(n+1,-1); //since the nodes start from 1

dist[k]=0;//distance from the soruce


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

//push the starting node and its distance
pq.push({k,0});

while(!pq.empty()){

    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int adjnode=it.first;
        int edgeweight=it.second;

        if(dis+edgeweight<dist[adjnode]){
            dist[adjnode]=dis+edgeweight;
            pq.push({dist[adjnode],adjnode});
        }
    }
}

//return the maximum distance

int maxi=0;
for(int i=1;i<=n;i++){
    maxi=max(maxi,dist[i]);

    //if a node is unreachable
    if(dist[i]==1e9)
        return -1;
}


return maxi;


}