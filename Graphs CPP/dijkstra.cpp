//Problem-To find the shortest distance of all vertices from the source vertex S

#include<bits/stdc++.h>
using namespace std;

// vector<int> dijkstra(int V,vector<vector<int>>adj[], int S){

// //declare a min heap
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

// //create the distance array
// vector<int>dist(V);

// for(int i=0;i<V;i++){
//     dist[i]=1e9; //marked every distance initially as infinite
// }

// dist[S]=0; //distance from source to source will be zero
// pq.push({0,S}); //priority queue will have {dist,source}


// while(!pq.empty()){
//     int dis=pq.top().first;
//     int node=pq.top().second;

//     //traverse the adjacent nodes
//     for(auto it:adj[node]){ //it is storing two elements since it is not an integer
//         int edgeWeight=it[1];
//         int adjnode=it[0];

//         if(dis+edgeWeight<dist[adjnode]){
//             dist[adjnode]=dis+edgeWeight;
//             pq.push({dist[adjnode],adjnode});
//         }
//     }
// }


// return dist ;


// }

vector<int>dijkstra(int V, vector<vector<int>>&edges, int S){

    vector<pair<int,int>>adj[V+1]; //since its a weighted graph and im stroing dist and weight

    for(auto &it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>dist(V+1);

    vector<int>parent(V+1); //to store where a node is coming from 

    //all the parents have to be marked with themselves
    for(int i=1;i<=V;i++){
        parent[i]=i;
    }

    for(int i=1;i<=V;i++){
        dist[i]=1e9 ;//initialize all the distances to infinity
    }

    dist[S]=0; //distance from source to itself is zero

    pq.push({0,S});

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
                parent[adjnode]=node;
            }

        }
    }

    vector<int>arr;
    int node=V;

    while(parent[node]!=node){
        arr.push_back(node);
        node=parent[node]; //goes back to where it came from
    }

    arr.push_back(S); //because once it reaches the starting node it comes from nowhere so you have to push it manually

    //checking if a node is unreachable
    for(int i=1;i<=V;i++){
        return {-1};
    }

    reverse(arr.begin(),arr.end());
    return arr;
}