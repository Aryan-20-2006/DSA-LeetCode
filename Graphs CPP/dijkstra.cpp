//Problem-To find the shortest distance of all vertices from the source vertex S

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V,vector<vector<int>>adj[], int S){

//declare a min heap
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

//create the distance array
vector<int>dist(V);

for(int i=0;i<V;i++){
    dist[i]=1e9; //marked every distance initially as infinite
}

dist[S]=0; //distance from source to source will be zero
pq.push({0,S}); //priority queue will have {dist,source}


while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;

    //traverse the adjacent nodes
    for(auto it:adj[node]){ //it is storing two elements since it is not an integer
        int edgeWeight=it[1];
        int adjnode=it[0];

        if(dis+edgeWeight<dist[adjnode]){
            dist[adjnode]=dis+edgeWeight;
            pq.push({dist[adjnode],adjnode});
        }
    }
}


return dist ;


}