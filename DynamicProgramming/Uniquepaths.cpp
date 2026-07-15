//Problem-Grid Unique Paths
//Diffculty-Medium

#include<bits/stdc++.h>
using namespace std;

//Memoization

// int f(int i, int j, vector<vector<int>>&dp){

//     //base case
//     dp[0][0]=1;

//     //checking boundary conditions
//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     int up=f(i-1,j,dp);
//     int left=f(i,j-1,dp);

//     return dp[i][j]=up+left;
// }


// int uniquePaths(int m, int n){

//     vector<vector<int>>dp(m,vector<int>(m,-1));
//     return f(m-1,n-1,dp);

// }

//Tabulation-Base case to recursion

int uniquePaths(int m,int n){

    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }

            else{

            
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
}

return dp[m-1][n-1];

}

int main(){

    int m=3;
    int n=7;
    cout<<uniquePaths(m,n)<<" ";
    return 0;
}