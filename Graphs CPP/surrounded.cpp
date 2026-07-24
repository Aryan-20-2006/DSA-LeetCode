//Problem-Surrounded Regions
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col,vector<vector<char>>&mat,vector<vector<int>>&visited){

    visited[row][col]=1;

    int n=mat.size();
    int m=mat[0].size();

    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];


        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
            dfs(nrow,ncol,mat,visited);
        }
    }

}

vector<vector<char>>fill(vector<vector<char>>&mat){

int n=mat.size();
int m=mat[0].size();

vector<vector<int>>visited(n,vector<int>(m,0));

//traverse the first and last row . First and last column


//Traverse the first row and last row . To do that you need to go to every column
for(int j=0;j<m;j++){

    //first row
    if(!visited[0][j] && mat[0][j]=='0'){
        dfs(0,j,mat,visited);
    }

    //last row
    if(!visited[n-1][j] && mat[n-1][j]=='0'){
        dfs(n-1,j,mat,visited);
    }
}

//Traversing the first and the last column, so we have to go every row
for(int i=0;i<n;i++){

    //first column
    if(!visited[i][0] && mat[i][0]=='O'){
        dfs(i,0,mat,visited);
    }

    //last column
    if(!visited[i][n-1] && mat[i][n-1]=='O'){
        dfs(i,n-1,mat,visited);
    }
}

//Traverse the board and flip every O to X
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(visited[i][j]==0 && mat[i][j]=='O'){
            mat[i][j]='X';
        }
    }
}

return mat;


}