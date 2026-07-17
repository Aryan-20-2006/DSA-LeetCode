#include<bits/stdc++.h>
using namespace std;

//Climbing stairs



//Recursion relation
// int f(int ind){


//     if(ind==0)
//         return 1; //one way of going to index 1

//     if(ind==1)
//         return 1;
    
//     int left=f(ind-1);
//     int right=f(ind-2);

//     return left+right;

// }

// int f(int ind,vector<int>&dp){
//     if(ind==0)
//         return 1;
//     if(ind==1)
//         return 1;

//     if(dp[ind]!=-1)
//         return dp[ind];

//     int left=f(ind-1,dp);
//     int right=f(ind-2,dp);

//     return dp[ind]=left+right;
    
// }


// int climbStairs(int ind,int n){

//     if(n==0 || n==1)
//         return 1;

//     int prev2=1;
//     int prev=2;

//     for(int i=3;i<n;i++){
//         int curr=prev2+prev;
//         prev2=prev;
//         prev=curr;
//     }


// return prev;

// }

//Frog Jump
// int f(int ind, vector<int>&heights, vector<int>&dp){

//     if(ind==0)
//         return 0; //from 0 to 0 cost is 0

//     if(dp[ind]!=-1)
//         return dp[ind];
    
//     int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
//     int right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);

//     return dp[ind]=min(left,right);

// }

//Tabulation
// int frogJump(vector<int>&heights){
//     int n=heights.size();
//     vector<int>dp(n,-1);

//     dp[0]=0;

//     for(int i=1;i<n;i++){
//         int left=dp[i-1]+abs(heights[i]-heights[i-1]);

//         int right=INT_MAX;
        
//         if(i>1){
//             right=dp[i-2]+abs(heights[i]-heights[i-2]);

//         }

//         dp[i]=min(left,right);
//     }

// return dp[n-1]; 

// }

int frogJump(int n,vector<int>&heights){

    int prev=0;
    int prev2=0;
    
    for(int i=1;i<n;i++){
        int left=prev+abs(heights[i]-heights[i-1]);

        int right=INT_MAX;
        
        if(i>1){
            right=prev2+abs(heights[i]-heights[i-2]);

        }

        int curr=min(left,right);
        prev2=prev;
        prev=curr;
    }

return prev;

}
    

