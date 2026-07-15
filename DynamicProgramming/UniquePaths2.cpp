//Problem-Unique Paths 2
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// int f(int i,int j,vector<vector<int>>&matrix, vector<vector<int>>&dp){

//     //checking for obstacles
//     if(i>0 && j>0 && matrix[i][j]==1)
//         return 0;
    
//     if(i==0 && j==0)
//         return 1;

//     if(dp[i][j]==-1)
//         return dp[i][j];

//     if(i<0 || j<0)
//         return 0;

//     int up=f(i-1,j,matrix,dp);
//     int left=f(i,j-1,matrix,dp);

//     return dp[i][j]=up+left;

// }

//Tabulation-Base case to recursion

int uniquePathswithobstacles(vector<vector<int>>&matrix){

    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>>dp(m,vector<int>(n,0));
    
    //base case 
    if(matrix[0][0]==1){
        return 0;
    }

    //if either i or j are 0
    dp[0][0]=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(matrix[i][j]==1){
                dp[i][j]=0;
                continue;
            }

            if(i==0 && j==0){
                continue; //we have already filled it
            }

            
                int up=0;
                int left=0;

                if(i>0){
                    up=dp[i-1][j];
                   
                }

                if(j>0){
                    left=dp[i][j-1];
                }

                dp[i][j]=up+left;
        }
    }

return dp[m-1][n-1];

}

int main(){

    vector<vector<int>>matrix={{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathswithobstacles(matrix)<<" ";
    return 0;

}