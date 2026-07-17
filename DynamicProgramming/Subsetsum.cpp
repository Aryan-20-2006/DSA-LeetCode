//Problem-Subset Sum
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// here k refers to the target
// bool f(int ind, int k, vector<int>&arr){

//     if(k==0){
//         return true;
//     }

//     if(ind==0){
//         return (arr[0]==k);
//     }

//     bool nottake=f(ind-1,k,arr);

//     bool take=false;

//     if(k>=arr[ind]){
//         take=f(ind-1,k-arr[ind],arr);
//     }

//     return take | nottake;

// }


// bool isSubsetSum(vector<int>&arr, int target){

//     return f(arr,target);

// }

//Memoization


// bool f(int ind, int target,vector<int>&arr, vector<vector<int>>&dp){

//     if(ind==0)
//         return (arr[0]==target);

//     if(target==0)
//         return true;

//     if(dp[ind][target]!=-1){
//         return dp[ind][target];
//     }

//     bool nottake=f(ind-1,target,arr,dp);

//     bool take=false;

//     if(target>=arr[ind]){
//         take=f(ind-1,target-arr[ind],arr,dp);
//     }

//     return dp[ind][target]=take | nottake;

// }


// bool isSubsetSum(int n,vector<int>&arr, int k){

//     vector<vector<bool>>dp(n+1,vector<bool>(k+1,-1));
//     return f(n-1,k,arr,dp);

// }

//Tabulation

// bool isSubsetSum(int n,vector<int>&arr, int k){


//     vector<vector<bool>>dp(n+1,vector<bool>(k+1,-1));

//     for(int i=0;i<n;i++){
//         dp[0][k]=true;

//         dp[i][arr[0]]=true; //same as writing if(target==0) return (arr[0]==target)
//     }

//     //since my call starts from n-1 to 0 and in tabulation we do bottom up
//     for(int i=1;i<n;i++){
//         for(int target=1;target<=k;target++){

//             bool nottake=dp[i-1][k];

//             bool take=false;

//             if(arr[i]<=target){
//                 take=dp[i-1][k-arr[i]];
//             }

//             dp[i][target]=take|nottake;

//         }
//     }

//     return dp[n-1][k]; //dp[ind-1][k] is the answer that we are looking for
// }

//Space optimization

bool subsetsum(int n, int k, vector<int>&arr){

    //always remember everytime we delcare a row, the 0th index is marked true
    vector<int>prev(k+1,0), curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool nottake=prev[k];
            bool take=false;

            if(arr[i]<=target){
                take=prev[k-arr[i]];
                curr[target]=take||nottake;
            }
        }

        prev=curr;
    }


    return prev[k];
}