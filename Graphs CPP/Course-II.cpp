//Problem-Course Schedule II
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

vector<int>findOrder(int numCourses,vector<vector<int>>&prerequisites){

int n=numCourses;

vector<int>adj[n];

//create the directed graph
for(auto it:prerequisites){
    adj[it[1]].push_back(it[0]);
}

//find the indegree
vector<int>indegree(n,0);
for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
}

//check if the indegree is 0, push it into the queue

queue<int>q;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

vector<int>topo;
while(!q.empty()){
    int node=q.front();
    q.pop();
    topo.push_back(node);

    //if the node is already in the topological sort, then remove it from the indegree
    for(auto it:adj[node]){
        indegree[it]--;

        if(indegree[it]==0){
            q.push(it);
        }
    }

    
}

if(topo.size()==n){
    return topo;
}


return {};

}