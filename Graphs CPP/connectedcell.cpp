//Problem-Connected Cell in a Grid
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//Here im not trying to count the number of connected but the find the maxsize among all the regions
int bfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&grid){

int n=grid.size();
int m=grid[0].size();
int size=0;

visited[row][col]=1;

queue<pair<int,int>>q;

q.push({row,col});


int delrow[]={-1,-1,0,+1,+1,+1,0,-1};
int delcol[]={0,+1,+1,+1,0,-1,-1,-1};

while(!q.empty()){
    row=q.front().first;
    col=q.front().second;
    q.pop();
    size++;

    for(int i=0;i<8;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
            visited[nrow][ncol]=1;
            q.push({nrow,ncol});
        }
    }
}

return size;

}

int maxRegion(vector<vector<int>>&grid){

int n=grid.size();
int m=grid[0].size();

vector<vector<int>>visited(n,vector<int>(m,0));
int maxsize=0;


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!visited[i][j]){
            int size=bfs(i,j,visited,grid);
            maxsize=max(maxsize,size);
        }
    }
}

return maxsize;


}