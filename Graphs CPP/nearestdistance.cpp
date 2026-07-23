//Problem-Distance of nearest cell having one
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//distance is calculated as |i1-i2|+|j1-j2|



// vector<vector<int>>nearest(vector<vector<int>>&grid){



//     int m=grid.size();
//     int n=grid[0].size();

//     //we need a visited and a distance matrix
//     vector<vector<int>>visited(m,vector<int>(n,0)); //instead of using a visited matrix, we can use the distance matrix and initialize it with -1 to indicate it has not been visited

//     vector<vector<int>>dist(m,vector<int>(n,0));

//     queue<pair<pair<int,int>,int>>q; //stores the {(row,col),steps}

//     int delrow[]={-1,0,+1,0};
//     int delcol[]={0,+1,0,-1};

//     //find all the ones first
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]==1){ //depending on the question ,here they're asking distance to the nearest 1. It can also be distance to the nearest 0
//                 q.push({{i,j},0}); //because 1 is at a nearest distance of itself which is 0
//                 visited[i][j]=1;
//             }

//             else{
//                 visited[i][j]=0;
//             }
//         }
//     }

//     while(!q.empty()){
//         int row=q.front().first.first;
//         int col=q.front().first.second;
//         int steps=q.front().second;

//         q.pop();

//         //store the answer
//         dist[row][col]=steps;

//         //traversing the neighbors

//         for(int i=0;i<4;i++){
//             int nrow=row+delrow[i];
//             int ncol=col+delcol[i];

//             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0){
//                 visited[nrow][ncol]=1;
//                 q.push({{nrow,ncol},steps+1});
//             }
//         }
//     }

// return dist;

// }


//Using only the distance matrix
vector<vector<int>>nearest(vector<vector<int>>&grid){



    int m=grid.size();
    int n=grid[0].size();

    //we need a visited and a distance matrix
    // vector<vector<int>>visited(m,vector<int>(n,0)); //instead of using a visited matrix, we can use the distance matrix and initialize it with -1 to indicate it has not been visited

    vector<vector<int>>dist(m,vector<int>(n,-1));

    queue<pair<pair<int,int>,int>>q; //stores the {(row,col),steps}

    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};

    //find all the ones first
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){ //depending on the question ,here they're asking distance to the nearest 1. It can also be distance to the nearest 0
                q.push({{i,j},0}); //because 1 is at a nearest distance of itself which is 0
                dist[i][j]=1;
            }

            else{
                dist[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;

        q.pop();

        //store the answer
        dist[row][col]=steps;

        //traversing the neighbors

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && dist[nrow][ncol]==-1){
                dist[nrow][ncol]=steps+1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }

return dist;

}

