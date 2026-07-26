//Problem-Number of Islands
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>>&grid,vector<vector<int>>&visited){

int n=grid.size();
int m=grid[0].size();

visited[row][col]=1;

queue<pair<int,int>>q; //stores the row and the column;



//push the starting node
q.push({row,col});

//this is for all the 8 directions
int delrow[]={-1,-1,0,+1,+1,+1,0,-1};
int delcol[]={0,+1,+1,+1,0,-1,-1,-1};

while(!q.empty()){
    row=q.front().first;
    col=q.front().second;
    q.pop();

    //checking for all the 8 directions
    for(int i=0;i<8;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
            visited[nrow][ncol]=1;
            q.push({nrow,ncol});
        }


    }
}

}

int numIslands(vector<vector<char>>&grid){

int n=grid.size();
int m=grid[0].size();

vector<vector<int>>visited(n,vector<int>(m,0));

int count=0; //since im counting the islands

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!visited[i][j] && grid[i][j]=='1'){
            bfs(i,j,grid,visited);
            count++;
        }
    }
}

return count;

}