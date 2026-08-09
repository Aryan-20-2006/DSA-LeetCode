//Problem-Path with minimum effort
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>&heights){

int n=heights.size();
int m=heights[0].size();

//create the distance array
vector<vector<int>>dist(n,vector<int>(m,1e9));

//the source is mentioned in the question
dist[0][0]=0;

//using a priority queue since we want minimum of all the path efforts(which is max)
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

//here we are pushing the {diff,{row,col}}
pq.push({0,{0,0}});

int delrow[]={-1,0,+1,0};
int delcol[]={0,+1,0,-1};



while(!pq.empty()){
    int diff=pq.top().first;
    int row=pq.top().second.first;
    int col=pq.top().second.second;
    pq.pop();

    //if you're at the destination
    if(row==n-1 && col==m-1){
        return diff;
    }

   
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){ //first check if its valid then we'll check if the difference is minimum
            int neweffort=max(abs(heights[row][col]-heights[nrow][ncol]),diff); //difference between the current row,col to the new row, new col we are at
            
            if(neweffort<dist[nrow][ncol]){
                dist[nrow][ncol]=neweffort;
                pq.push({neweffort,{nrow,ncol}});
            }
        }
    }

}

return 0; //unreachable


}