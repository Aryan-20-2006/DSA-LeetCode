//Problem-Triangle
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// int f(int i, int j,vector<vector<int>>&triangle){

//     int n=triangle.size();


//     //base case 
//     if(i==n-1)
//         return triangle[n-1][j];

//     int down=triangle[i][j]+f(i+1,j,triangle);
//     int diagonal=triangle[i][j]+f(i+1,j+1,triangle);

//     return min(down,diagonal);
// }

//Memoization

// int f(int i, int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){

//     int n=triangle.size();
//     //base case 
//     if(i==n-1)
//         return triangle[n-1][j];

//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     int down=triangle[i][j]+f(i+1,j,triangle,dp);
//     int diagonal=triangle[i][j]+f(i+1,j+1,triangle,dp);

//     return dp[i][j]=min(down,diagonal);
// }

//Tabulation
// int minTriangleSum(vector<vector<int>>&triangle){

//     //since my base case starts from n-1, so it can be any of the columns

//     int n=triangle.size();

//     vector<vector<int>>dp(n,vector<int>(n,0));

//     //writing our base case
//     for(int j=0;j<n;j++){
//         dp[n-1][j]=triangle[n-1][j];
//     }

//     //since (n-1)th row is already used, start from the n-2th row
//     for(int i=n-2;i>=0;i--){
//         for(int j=i;j>=0;j--){

//             int down=triangle[i][j]+dp[i+1][j];
//             int diagonal=triangle[i][j]+dp[i+1][j+1];

//             dp[i][j]=min(down,diagonal);

//         }
//     }

// return dp[0][0]; //this is the recursion which we call to get our answer

// }


//Space optimization
int minTriangleSum(vector<vector<int>>&triangle){

    int n=triangle.size();
    vector<int>prev(n);
    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int j=0;j<n;j++){
        prev[j]=triangle[n-1][j]; //this is the same as writing dp[n-1][j]=triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){

        vector<int>curr(n);

        for(int j=i;j>=0;j--){

            int down=triangle[i][j] + prev[j];
            int diagonal=triangle[i][j] + prev[j+1];

            curr[j]=min(down,diagonal);

        }

        prev[i]=curr[i];
    }

return prev[0];


}