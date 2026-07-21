//Problem-To find the number of Connected Components

#include<bits/stdc++.h>
using namespace std;

//Using dfs
// int find(int v,vector<vector<int>>&edges){


//     vector<vector<int>>adj(v);
//     vector<int>ls;

//     //creating an adjacency list
//     for(auto &e:edges){
//         adj[e[0]].push_back(e[1]);
//         adj[e[1]].push_back(e[0]); //for an undirected graph
//     }

//     //to keep track of visited nodes
//     vector<int>visited(v,0);

//     int components=0;

//     //Traverse all the nodes in the graph

//     for(int i=0;i<v;i++){
//         if(!visited[i]){
//             components++;
//             dfs(i,adj,visited,ls);
//         }
//     }


//     return components;
  
// }

// void dfs(int node, vector<vector<int>>&adj, vector<int>&visited, vector<int>&ls){

//     visited[node]=1;

//     for(auto it:adj[node]){
//         if(!visited[it]){
//             dfs(it,adj,visited,ls);
//         }
//     }



// }

//Using bfs

void bfs(int start,vector<vector<int>>&adj,vector<int>&visited){

    //No matter what you pass in the start, it starts from node 0
    visited[start]=1;
    queue<int>q;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }

}

int find(int v, vector<vector<int>>&edges){


    vector<vector<int>>adj(v);

    for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int>visited(v,0);

    int components=0;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            components++;
            bfs(i,adj,visited);
        }
    }

return components;


}

