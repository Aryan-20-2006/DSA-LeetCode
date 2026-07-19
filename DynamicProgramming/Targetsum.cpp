//Problem-Target Sum
//Difficulty-Hard


#include<bits/stdc++.h>
using namespace std;


//subset sum
// int f(int ind, int k, vector<int>&arr, vector<vector<int>>&dp){

//     if(k==0)
//         return 1;

//     if(ind==0)
//         return (arr[0]==k);

//     if(dp[ind][k]!=-1)
//         return dp[ind][k];

//     int nottake=f(ind-1,k,arr,dp);

//     int take=0;
    
//     if(arr[ind]<=k){
//         take=f(ind-1,k-arr[ind],arr,dp);
//     }

//     return dp[ind][k]=take+nottake;
        
// }

//Tabulation

//Paritition a susbet into subsets with a difference equal to target
int findWays(vector<int>&nums, int target){

    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    if(nums[0]==0)
        dp[0][0]=2;

    else
        dp[0][0]=1;

    if(nums[0]!=0 && nums[0]<=target)
        dp[0][nums[0]]=1;
    
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    for(int i=1;i<n;i++){
        for(int t=0;t<=target;t++){

            int nottake=dp[i-1][t];

            int take=0;

            if(nums[i]<=t){
                take=dp[i-1][t-nums[i]];
            }

            dp[i][t]=take+nottake;


        }
    }

return dp[n-1][target];

}

int countPartitions(int n, int diff, vector<int>&nums){


    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

     //s1-s2=D and s2=totalSum-s1 and target=(totalSum-dff)/2

    if((totalSum-diff)<0 || (totalSum-diff)%2!=0)
        return 0;

    return findWays(nums,(totalSum-diff)/2);

}

int targetSum(int n,int target,vector<int>&nums){

    return countPartitions(n,target,nums);

}

