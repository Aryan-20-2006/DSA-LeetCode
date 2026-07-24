//Problem-Number of Enclaves
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col,vector<vector<int>>&grid,vector<vector<int>>&visited){

    visited[row][col]=1;

    int n=grid.size();
    int m=grid[0].size();

    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];


        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,visited);
        }
    }

}

int numberofEnclaves(vector<vector<int>>&grid){

    int m=grid.size();
    int n=grid[0].size();

    int count=0; 

    vector<vector<int>>visited(m,vector<int>(n,0));

    //traverse the first and the last row
    for(int j=0;j<n;j++){
        //first row
        if(!visited[0][j] && grid[0][j]==1){
            dfs(0,j,grid,visited);
        }

        //last row
        if(!visited[m-1][j] && grid[n-1][j]==1){
            dfs(m-1,j,grid,visited);

        }
    }

    //traversing the first and last column
    for(int i=0;i<m;i++){
        //first column
        if(!visited[i][0] && grid[i][0]==1){
    
            dfs(i,0,grid,visited);

        }

        //last column
        if(!visited[i][n-1] && grid[i][n-1]==1){
            dfs(i,0,grid,visited);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && grid[i][j]==1){
                count++;
            }
        }
    }

return count;


}