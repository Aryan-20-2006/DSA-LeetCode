//Problem-Coin Change 2
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//Recurrence
// int f(int ind,int target,vector<int>&nums){

//     if(ind==0){
//         if(target%nums[ind]==0){
//             return target/nums[ind];
//         }
//     }

//     int nottake=f(ind-1,target,nums);

//     int take=0;

//     if(nums[ind]<=target){
//         take=f(ind,target-nums[ind],nums); //you dont need a 1+ since take already counts all the possible combinations
//     }

//     return take+nottake;

// }

//Memoization
// int f(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){

//     if(ind==0){
// 
//             return (target%nums[0]==0);
//         }
//     }

//     int nottake=f(ind-1,target,nums,dp);

//     if(dp[ind][target]!=-1)
//         return dp[ind][target];

//     int take=0;

//     if(nums[ind]<=target){
//         take=f(ind,target-nums[ind],nums,dp);
//     }

//     int ans=dp[ind][target]=take+nottake;

//     if(ans>=1e9)
//         return 0;//since the question is asking

//     return ans;


// }


// int count(vector<int>&coins, int N, int amount){

//     vector<vector<int>>dp(N,vector<int>(amount+1,0));
//     return f(N-1,amount,coins,dp);
// }

//Tabulation-Base Case to Recursion

int count(vector<int>&coins, int N, int amount){

    vector<vector<int>>dp(N,vector<int>(amount+1,0));

    for(int t=0;t<=amount;t++){
            dp[0][t]=(t%coins[0]==0);
        }
    

    for(int i=1;i<N;i++){
        for(int target=0;target<=amount;target++){
            int nottake=dp[i-1][target];

            int take=0;

            if(coins[i]<=target){
                take=dp[i][target-coins[i]];
            }

            dp[i][target]=take+nottake;
        }
    }

return dp[N-1][amount];

}

