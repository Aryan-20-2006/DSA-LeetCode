//Problem-Rotten Oranges
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>&grid){

    int m=grid.size();
    int n=grid[0].size();

    queue<pair<pair<int,int>,int>>q; //{{row,col},time}
    int vis[m][n];

    //Traverse the grid and get all the oranges that are rotten
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0}); //initially the rotten ornages are at time 0;
                vis[i][j]=2;//mark them as visited;
            
            }

            else{
                vis[i][j]=0; //if there are no rotten oranges
            }
        }
    }

    int t=0;
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};

    //using bfs
    while(!q.empty()){

        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        t=max(t,time);
        q.pop();


        
    //we need to make the neighboring oranges rotten
    for(int i=0;i<4;i++){ //since you can go in 4 directions
        int nrow=row+drow[i];
        int ncol=col+dcol[i];

        //boundary conditions
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
            q.push({{nrow,ncol},time+1});
            vis[nrow][ncol]=2; //marking the newly rotten oranges as 2
        }

    }

    }

    //check if all the oranges were rotten or not
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }   
        }
    }

return t;

}

// int main(){

//     vector<vector<int>>grid={{2,1,1},{1,1,0},{0,1,1}};
//     cout<<orangesRotting(grid)<<" ";
//     return 0;


// }