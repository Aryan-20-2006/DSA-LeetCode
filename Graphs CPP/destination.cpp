//Problem-No of ways to arrive at a destination
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int mod=1e9;

    public:

int countPaths(int n, vector<vector<int>>&roads){

//roads[i]=[i,vi,timei]
//create the graph

vector<pair<int,int>>adj[n];

for(auto it:roads){
    adj[it[0]].push_back({it[1],it[2]});
    adj[it[1]].push_back({it[0],it[2]}); //undirected graph
}

//I need a distance as well as ways array to count the no of ways I have reached a node

vector<int>dist(n,1e9);

vector<int>ways(n,0); 

dist[0]=0;

ways[0]=1; //since only one to start from the source

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

//{dist,node}
pq.push({0,0});

while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it:adj[node]){
        int adjnode=it.first;
        int edgeweight=it.second;

        //looking for a shorter distance and if you coming to this node for the first time, then its one way
        if(dis+edgeweight<dist[adjnode]){
            dist[adjnode]=dis+edgeweight;
            ways[adjnode]=ways[node];
            pq.push({adjnode,dist[adjnode]});
        }

        //if I have visited the node with the same distance again
        if(dis+edgeweight==dist[adjnode]){
            ways[adjnode]=(ways[node]+ways[adjnode])%mod;
        }
    }
}

return ways[n-1]%mod; //for the destination node , how many ways can i reach using the shortest path

}

};