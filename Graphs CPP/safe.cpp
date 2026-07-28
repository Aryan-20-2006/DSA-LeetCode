//Problem-Find eventual safe states
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

// bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&pathvisited,vector<int>&check){

//     visited[node]=1;
//     pathvisited[node]=1;
//     check[node]=0;


//     for(auto it:adj[node]){
//         if(!visited[it]){
//             //not explored the nighbors and checking for a cycle
//             if(dfs(it,adj,visited,pathvisited,check)==true){
//                 check[node]=0; //if there is a cycle
//                 return true;
//             }
//         }

//             //If a neighbor exists and if you can go back to it then its a cycle
//             else if(pathvisited[it]){
//                 check[node]=0; //if there is a cycle
//                 return true;
//             }
        
//     }

//     check[node]=1;//while coming back mark the safe nodes
//     pathvisited[node]=0;


// return false;


// }


// vector<int>eventualSafeNodes(int V,vector<int>adj[]){

// vector<int>visited(V,0);
// vector<int>pathvisited(V,0);
// vector<int>check(V,0); //to mark the safe nodes

// for(int i=0;i<V;i++){
//     if(!visited[i]){
//         dfs(i,adj,visited,pathvisited,check); //here we're not using a break statemnt since we're calling the dfs for every node 
//     }
// }

// vector<int>safenodes;

// for(int i=0;i<V;i++){
//     if(check[i]==1){
//         safenodes.push_back(i);
//     }
// }

// return safenodes;

// }

//We can also write this without using check
/*
vector<int>safenodes

for(int i=0;i<V;i++){
    if(pathvisited[i]==0){
        safenodes.push_back(i);
    }

}



*/

//Using topoSort

vector<int>eventualSafeNode(int V, vector<int>adj[]){

//Since terminal nodes have no outgoing edges and is in the form of outdegree. Topo sort uses indegree so we will the reverse the direction
vector<int>adjRev[V];


//from i->it to it->i
for(int i=0;i<V;i++){
    for(auto it:adj[V]){
        adjRev[it].push_back(i);
    }
}

vector<int>indegree(V,0);
for(int i=0;i<V;i++){
    for(auto it:adjRev[V]){
        indegree[it]++;
    }
}

//checking if the indegree is zero
queue<int>q;
for(int i=0;i<V;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

vector<int>safeNodes;
while(!q.empty()){
    int node=q.front();
    q.pop();
    safeNodes.push_back(node);

    //if the node is in topo sort, remove it from the indegree
    for(auto it:adjRev[V]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }

    

    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
    
}




}