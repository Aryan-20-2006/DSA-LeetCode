//Problem-Roads and Libraries
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//find all the connected components and their sizes
int dfsSize(int n,vector<vector<int>>&adj, vector<bool>&visited){

    visited[n]=true; //we are checking if we have seen this node in some component

    int size=1; //to find the size of each connected component. It is set to size 1 initally since that node is part of the component itself

    for(auto it:adj[n]){
        if(!visited[n]){
            size+=dfsSize(n,adj,visited); //it adds the entire count that the recursive call found

        }
    }

    return size; //this returns the size of each connected component

}

//Add the cost comparison logic
long roadsAndLibraries(int n,int c_lib,int c_road,vector<vector<int>>&cities){


long totalcost=0; //to find the total minimum cost

vector<vector<int>>adj(n);

//create the graph
for(auto &it:cities){
    adj[it[1]].push_back(it[0]);
    adj[it[0]].push_back(it[1]);
}

vector<bool>visited(n,false);

//traverse all the nodes
for(int i=0;i<n;i++){
    if(!visited[i]){
        long k=dfsSize(n,adj,visited); //the k here is the size of the entire connected component
        if(c_road>=c_lib){ //since we want minimum library cost, if road cost is more then roads are not worth it
            totalcost+=(long)k*c_lib;
        }

        else{
            totalcost+=c_lib+(long)(k-1)*c_road; //k-1 is the minimum number of edges to connect the cities together. If you have k nodes then k-1 edges
        }
    }
}

return totalcost;

}






// int sizeofconnected(int n,vector<vector<int>>&cities){

//     vector<vector<int>>adj(n);
//     vector<int>ls; //creating adjacency list

//     for(auto &it:cities){
//         adj[it[1]].push_back(it[0]);
//         adj[it[0]].push_back(it[1]);
//     }

//     vector<int>visited(n,0);

//     int count=0;

//     //traverse all the nodes in the graph
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             dfs(i,adj,visited,ls);
//             count++;
//         }
//     }

//     return count;


// }

