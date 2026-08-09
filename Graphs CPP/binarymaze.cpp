//Problem-Shortest distance in a binary maze
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>&grid,pair<int,int>source,pair<int,int>destination){

int n=grid.size();
int m=grid[0].size();


queue<pair<int,pair<int,int>>>q; //stores ({dist},{row,col})

//2D distance array
vector<vector<int>>dist(n,vector<int>(m,1e9)); //initializing all the distances to infinity

//distance from source to source is zero
dist[source.first][source.second]=0;

//push the distance of the starting row and col
q.push({0,{source.first,source.second}});

//assuming I can go in 4 directions
int delrow[]={-1,0,+1,0};
int delcol[]={0,+1,0,-1};

while(!q.empty()){

    int dis=q.front().first;
    int row=q.front().second.first;
    int col=q.front().second.second;
    q.pop();

    //traverse the neighbors

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dis+1<dist[nrow][ncol]){ //here I can go to cells marked 1
            dist[nrow][ncol]=dis+1;

            //what if the newrow and newcol are equal to the desitnation
            if(nrow==destination.first && ncol==destination.second){
                return dis+1;
            }
            q.push({dis+1,{nrow,ncol}});
        }
    }

}

return -1;

}