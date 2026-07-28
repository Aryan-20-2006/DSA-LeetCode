#include<bits/stdc++.h>
using namespace std;

//using dfs
// void dfs(int node,vector<int>&visited,stack<int>&st,vector<int>adj[]){

// visited[node]=1;

// for(auto it:adj[node]){
//     if(!visited[it]){
//         dfs(it,visited,st,adj);
//     }

//     st.push(node);
// }

// }

// vector<int>topoSort(int V, vector<int>adj[]){

// vector<int>visited(V,0);
// stack<int>st;

// for(int i=0;i<V;i++){
//     if(!visited[i]){
//         dfs(i,visited,st,adj);
//     }
// }

// vector<int>ans;
// while(!st.empty()){
//     ans.push_back(st.top());
//     st.pop();
// }

// return ans;

// }

//using bfs-Kahn's algorithm
vector<int> topSort(int V,vector<int>adj[]){


    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[V]){
            indegree[it]++;
        }
    }

    //checking which node has an indegree of zero
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>topo; //to store the answer
    while(!q.empty()){
        int node=q.front(); //getting the first node
        q.pop();
        topo.push_back(node);

        //if the node is there in the topo sort, remove it from the indegree
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){ 
                q.push(it);
            }
        }


    }


return topo;


}