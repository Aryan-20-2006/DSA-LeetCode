//Problem-Flood Fill
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//using dfs
// void dfs(int row, int col,vector<vector<int>>&ans,vector<vector<int>>&image, int newColor, int delrow[], int delcol[],int iniColor){

//     //whenever we entered the new cell, color it with the new color
//     ans[row][col]=newColor;

//     int m=image.size();
//     int n=image[0].size();

//     //checking for neighbors-since you go can go up,down,left and right-4 neighbors
//     for(int i=0;i<4;i++){
//         int nrow=row+delrow[i];
//         int ncol=col+delcol[i];

//         //checking if its valid
//         if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
//             dfs(nrow,ncol,ans,image,newColor,delrow,delcol,iniColor);
//         }

//     }
// }

// vector<vector<int>>floodFill(vector<vector<int>>&image, int sr, int sc, int newColor){

//     int iniColor=image[sr][sc]; //this is the cell having the initial color

//     //create a copy of the image
//     vector<vector<int>>ans=image;

//     //directions
//     int delrow[]={-1,0,+1,0};
//     int delcol[]={0,+1,0,-1};

//     dfs(sr,sc,ans,image,newColor,delrow,delcol,iniColor);

//     return ans;
// }

//using bfs

void bfs(int row,int col,vector<vector<int>>&image,int delRow[], int delCol[],int iniColor,int newColor){

    int m=image.size();
    int n=image[0].size();

    queue<pair<int,int>>q;
    
    image[row][col]=newColor;

    q.push({row,col});

    while(!q.empty()){

        row=q.front().first;
        col=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==iniColor && image[nrow][ncol]!=newColor){
                image[nrow][ncol]=newColor;
                q.push({nrow,ncol});
            }
        }


    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){

    int iniColor=image[sr][sc];

    //directions
    int delRow[]={-1,0,+1,0};
    int delCol[]={0,+1,0,-1};

    if(iniColor==newColor){ //this would never be true, so we just return the image since this gets handled while checking the neighbors
        return image;
    }

    bfs(sr,sc,image,delRow,delCol,iniColor,newColor);

    return image;


}

