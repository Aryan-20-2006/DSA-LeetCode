//Problem-Shortest Reach in a graph
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:

    int n;
    vector<vector<int>>adj; //it is a class member variable which belongs to the graph object
    
    Graph(int nodes){
        
        n=nodes;

        //since the nodes are from 1 to n
        //Adjacency needs to have one empty slot per node 
        //before the adj is an empty vector<vector<int>> so it has 0 elements
        adj.resize(n+1); //it makes sure it has n+1 elements 
        //nodes are starting from 1 to n
        //Eg:- n=4 , then n+1=5 indices from 0 1 2 3 4 


    }

    void add_edge(int u, int v){
        adj[v].push_back(u);
        adj[u].push_back(v);


    }

    vector<int>shortest_reach(int start){

        //distance matrix-nodes start from 1 to n, so n+1
        vector<int>dist(n+1,-1); //assigning it to -1 because later if you find a disconnected node, then distance would be -1

        dist[start]=0;

        queue<int>q; //to store the distance

        while(!q.empty()){
            int node=q.front();
            q.pop();

            //Every node you visit for the first time, bfs visits nodes in strictly increasing order so we dont use the concept of shortest distance
            for(auto it:adj[node]){
                if(dist[it]==-1){ //if it is not visited
                    dist[it]=dist[node]+6; //in the problem , edge weights are given as 6
                    q.push(it);
                }
            }
        }

        return dist;


    }

};