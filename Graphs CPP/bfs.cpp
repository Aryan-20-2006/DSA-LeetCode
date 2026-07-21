#include<bits/stdc++.h>
using namespace std;


//For a undirected graph-works for directed graphs as well
vector<int>bfsTraversal(int v, vector<int>adj[]){

    vector<int>vis(v,0); //creating the visited array
    vis[0]=1;
    queue<int>q;
    q.push(0);

    vector<int>bfs;//whatever node gets popped from the queue gets stored here

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){ //every index is storing the neighbor elements
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }


            //can also be written as
            // for(int i=0;i<adj[node].size();i++){
            //     int it=adj[node][i];
            //     if(!vis[it]){
            //         vis[it]=1;
            //         q.push(it);
            //     }
            }


        }
    

return bfs;
}
