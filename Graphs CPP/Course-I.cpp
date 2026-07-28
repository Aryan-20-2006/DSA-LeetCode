//Problem-Course Schedule I
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//whenever one tak has to be done before the other, we always use Topo sort
bool canFinish(int numCourses,vector<vector<int>>&prerequisites){

int n=numCourses;//the nodes

vector<int>adj[n];

//creating the directed graph
for(auto it:prerequisites){
    adj[it[1]].push_back(it[0]);//since in the question they have given the pair [0,1]
}

vector<int>indegree(n,0);
for(int i=0;i<n;i++){
    for(auto it:adj[i]){
        indegree[it]++;
    }
}

queue<int>q;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}

vector<int>topo;

while(!q.empty()){

    int node=q.front(); //to get the first node
    q.pop();
    topo.push_back(node);

    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0){
            q.push(it);
        }
    }
}

//this means all the nodes have been visited and there is no cycle
if(topo.size()==n){ //another of doing this is by using a count anc checking if it equals to n after doing count++;
    return true;
}

return false;

}