//Problem-Minimum Falling Path Sum
//Difficulty-Medium

//Here im assuming Im starting from (0.0) but the problems asks to start from and cell in the first row

#include<bits/stdc++.h>
using namespace std;


//Initially starting off with the recursion
// int f(int i, int j, vector<vector<int>>&matrix){

//     if(i==0 && j==0)
//         return matrix[0][0];

//     if(i<0 || j<0)
//         return INT_MAX; //return a large value here if it goes out of bounds so that it never gets counted

//     //assuming for now I go in two direction down and right, my recursion is done in the reverse order i.e up and left
//     int up=f(i-1,j,matrix)+matrix[i][j];

//     int left=f(i,j-1,matrix)+matrix[i][j];

//     return min(up,left);
// }

// int minimumPathFallingSum(vector<vector<int>>&matrix){

//     int m=matrix.size();
//     int n=matrix[0].size();
//     return f(m-1,n-1,matrix);


// }

//Memoization
// int f(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){

//     if(i==0 && j==0)
//         return matrix[0][0]; 

//     if(i<0 || j<0)
//         return INT_MAX;

//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     int up=f(i-1,j,matrix,dp) + matrix[i][j];
//     int left=f(i,j-1,matrix,dp) + matrix[i][j];

//     return dp[i][j]=min(up,left);

// }

// int minimumPathFallingSum(vector<vector<int>>&matrix){

//     int m=matrix.size();
//     int n=matrix[0].size();
//     vector<vector<int>>dp(m,vector<int>(n,0));
//     return f(m-1,n-1,matrix,dp);


// }

//Tabulation

int minimumPathFallingSum(vector<vector<int>>&matrix){


    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>>dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                dp[i][j]=matrix[i][j];
            }

            else{

                int up=matrix[i][j];
        
                if(i>0){
                    up=dp[i-1][j]+matrix[i][j];
                }

                else{ //if i<0
                    up=1e9;
                }

                int left=matrix[i][j];

                if(j>0){
                    left=dp[i][j-1]+matrix[i][j];
                }

                else{
                    left=1e9;
                }


                dp[i][j]=min(up,left);
            }
        }


    }

return dp[m-1][n-1];


}