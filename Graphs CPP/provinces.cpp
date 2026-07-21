//Problem-No of provinces
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int findProvinces(vector<vector<int>>&adj){


    int v=adj.size(); //refers to the starting node

    vector<vector<int>>adjls(v); //what we're trying to build

    //to convert adjacency matrix into a list
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1 && i!=j){
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }

vector<int>visited(v,0);

int components=0;

for(int i=0;i<v;i++){
    if(!visited[i]){
        components++;
        dfs(i,adjls,visited);
    }

}

return components;

}

void dfs(int node,vector<vector<int>>&adjls,vector<int>&visited){

    visited[node]=1;

    for(auto it:adjls[node]){
        if(!visited[it]){
            dfs(it,adjls,visited);
        }
    }

}