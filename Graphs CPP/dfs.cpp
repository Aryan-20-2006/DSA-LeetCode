#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>&visited, vector<int>&ls){


    visited[node]=1;
    ls.push_back(node);

    //traverse all its neighbors
    for(auto it:adj[node]){
        if(!visited[it]){ //if the neighbor has not been visited
            dfs(it,adj,visited,ls);
        }
    }

}


//function to return a list containing dfs traversal
// vector<int>dfsTraversal(int v, vector<int>adj[]){
//     vector<int>vis(v,0); //creating the visited array
//     int start=0;
//     vector<int>ls; //stores the df
//     dfs(start,adj,visited,ls);
// }