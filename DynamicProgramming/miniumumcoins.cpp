//Problem-Minimum coins
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;


// int f(int ind,int target,vector<int>&coins){

//     //base cases
//     if(ind==0)
//         if(target%coins[ind]==0){
//             return target/coins[ind];
//         }

//         else{
//             return 1e9; //to prevent overflow
//         }
    

//     int nottake=0+f(ind-1,target,coins);

//     int take=INT_MAX; //since if I am taking, I have to look for minimum no of coins, so Ill assign it to something like INT_MAX

//     if(coins[ind]<=target){
//         take=1+f(ind,target,coins); //since I have an infinite supply of coins, I am not going back to the previous index
//     }

//     return min(take, nottake);


// }

//Memoization

// int f(int ind, int target,vector<int>&coins, vector<vector<int>>&dp){

//     if(ind==0){
//         if(target%coins[ind]==0)
//             return target/coins[ind];
//     }

//     if(dp[ind][target]!=-1)
//         return dp[ind][target];

//     int nottake=0+f(ind-1,target,coins,dp);

//     int take=INT_MAX;

//     if(coins[ind]<=target)
//         take=1+f(ind,target,coins,dp);

//     return dp[ind][target]=min(take,nottake);
// }

// int minimumCoins(vector<int>&coins,int amount){

//     int n=coins.size();
//     vector<vector<int>>dp(n,vector<int>(amount+1,0));
//     int ans=f(n-1,amount,coins,dp);
//     if(ans>=1e9)
//         return -1; //since the question is asking if its not possible return -1

// }

//Tabulation-Base case to recursion

int minimumCoins(vector<int>&coins, int amount){

    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));

    //base case
    for(int t=0;t<=amount;t++){
        if(t%coins[0]==0){
            dp[0][t]=t/coins[0];
        }

        else{
            return 1e9;
        }
    }

    for(int i=1;i<n;i++){
        for(int target=0;target<=amount;target++){

        int nottake=0+dp[i-1][target];

        int take=INT_MAX;

        if(coins[i]<=target){
            take=1+dp[i][target-coins[i]];
        }

         dp[i][target]=min(take,nottake);
    }

    }

    int ans=dp[n-1][amount];
    if(ans>=1e9)
        return -1;

    return ans;

}



