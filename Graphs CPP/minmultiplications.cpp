//Problem-Minimum multiplications to reach the end
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;







int minimumMultiplications(vector<int>&arr,int start,int end){

    //{steps,num}
    queue<pair<int,int>>q;
    vector<int>dist(100000,1e9); //all my nodes lie within this range
    q.push({0,start});
    dist[start]=0;
    int mod=100000;

    while(!q.empty()){
        int steps=q.front().first;
        int node=q.front().second;
        q.pop();

        for(auto it:arr){
            //the new node we are getting on multiplying
            int num=(it*node)%mod;
            if(steps+1<dist[num]){
                dist[num]=steps+1;

                //if I get the resulting number
                if(num==end){
                    return steps+1;
                }
                q.push({steps+1,dist[num]});
            }
        }
    }


return -1;



}


