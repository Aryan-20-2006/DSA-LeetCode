//Problem-Alien Dictionary
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//topo sort
vector<int>topoSort(int V, vector<int>adj[]){

    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[V]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>result;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        result.push_back(node);

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }

    }

    if(result.size()==V){
        return result;
    }

    return result;

}

string findOrder(string dict[],int n,int k){

    //Note-here k refers to the vertices and n refers to the number of words in the dictionary

    //Cases when this fails-1.If everything is matching and if the larger string is before the shorter string 
    //2.When there is a cycle

    vector<int>adj[k];//here k refers to how many alphabets i.e no of vertices

    for(int i=0;i<n-1;i++){ //why n-1?-because when we're taking pairs and we are at the end we dont take the last, instead it would be the second last
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size()); //since we're comparing two pairs, if one string is big and the other string is small, we end up comparing up to the smallest length
        //I have to check if the character at the pointer is equal or not. If not, create an edge
        
        bool found=false; //to check for a differing character
        
        for(int ptr=0;ptr<len;ptr){
            if(s1[ptr]!=s2[ptr]){
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');//create an edge from s1[ptr]->s2[ptr]
                found=true;
                break;
            }

        }

        //if the first string is larger than the second, order is not possible
        if(!found && s1.size()>s2.size()){
            return " ";
        }

    }

    vector<int>topo=topoSort(k,adj);

    //if a cycle exists
    if(topo.size()!=k)
        return " ";

    string ans; //since we have to return a string
    for(auto it:topo){
        ans+=char(it+'a'); //since earlier we stored it in the form of indices, now we're converting it back
    }

return ans;

}