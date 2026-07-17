//Problem-Partition equal subset sum
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

// bool subsetsum(int n, int k, vector<int>&arr){

//     //always remember everytime we delcare a row, the 0th index is marked true
//     vector<int>prev(k+1,0), curr(k+1,0);
//     prev[0]=curr[0]=true;
//     prev[arr[0]]=true;

//     for(int i=1;i<n;i++){
//         for(int target=1;target<=k;target++){
//             bool nottake=prev[k];
//             bool take=false;

//             if(arr[i]<=target){
//                 take=prev[k-arr[i]];
//                 curr[target]=take|nottake;
//             }
//         }

//         prev=curr;
//     }


//     return prev[k];
// }

// bool equalPartittion(int n, vector<int>&arr){

//     int sum=0;
    
//     for(int i=0;i<n;i++){
//         sum+=arr[i];

//     }

//     //if the sum is an odd number
//     if(sum%2!=0){
//         return false;
//     }

//     int target=sum/2;

//     return subsetsum(n,target,arr);


// }

//Parition a set into two subsets with minimum absolute sum difference
//But this works for only positive numbers

// int minDifference(vector<int>&arr, int n){


//     int totalsum=0;
//     for(int i=0;i<n;i++){
//         totalsum+=arr[i];
//     }

//     int k=totalsum;

//     vector<bool>curr(k+1,false),prev(k+1,false);
//     prev[0]=curr[0]=true;
//     prev[arr[0]]=true;

//     for(int i=1;i<n;i++){
//         for(int target=1;target<=k;target++){
//             bool nottake=prev[k];

//             bool take=false;

//             if(arr[i]<=target){
//                 take=prev[target-arr[i]];
//                 
//             }

            //curr[target]=take || nottake;
//         }

//         prev=curr;

//     }

//     int mini=1e9;
//     for(int s1=0;s1<n;s1++){
//         if(prev[s1]==true){
//             mini=min(mini,abs((totalsum-s1)- s1));
//         }
//     }

// return mini;


// }

//For negative numbers, we use an offset value

// int minDifference(vector<int>&arr, int n){


//     int minSum=0;
//     int maxSum=0;

//     for(int x:arr){
//         if(x<0){
//             minSum+=x;
//         }

//         else{
//             maxSum+=x;
//         }
//     }

//     int offset=-minSum;

//     //instead of total sum, we do maxSum-minSum+1
//     vector<bool>prev(maxSum-minSum+1,false); //this is the same as writing k+1
    

//     prev[0+offset]=true;
//     prev[arr[0]+offset]=true;

//     for(int i=1;i<n;i++){
//         vector<bool>curr(maxSum-minSum+1,false);
//         for(int sum=minSum;sum<=maxSum;sum++){
//             bool nottake=prev[sum+offset];

//             bool take=false;

//             //here the target value is sum-arr[i]
//             if(sum-arr[i]>=minSum && sum-arr[i]<=maxSum){
//                 take=prev[sum-arr[i]+offset];
//             } 
            
//             curr[sum+offset]=take || nottake;
//         }

//         prev=curr;


//     }

//     int totalSum=0;

//     for(int j=0;j<n;j++){
//         totalSum+=arr[j];
//     }

//     int mini=1e9;
//     for(int s1=minSum;s1<=maxSum;s1++){

//         if(prev[s1+offset]){
//             int s2=totalSum-s1;
//             mini=min(mini,abs(s1-s2));
//         }
//     }

//     return mini;

// }

//Problem-Paritions with a given difference


//This function we used from before is counting the subsets having a target value
// int f(int ind, int sum,vector<int>&nums, vector<vector<int>>&dp){

//     //this is to handle cases where zeroes are there
//     if(ind==0){
//         if(sum==0 && nums[0]==0){
//             return 2;
//         }

//         if(sum==0 && sum==nums[0]){
//             return 1;
//         }

//         return 0;

//     }


//     if(dp[ind][sum]!=-1)
//         return dp[ind][sum];

//     int nottake=f(ind-1,sum,nums,dp);
//     int take=f(ind-1,sum-nums[ind],nums,dp);

//     return dp[ind][sum]=take+nottake;


// }

int findWays(vector<int>&nums,int tar){

    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));

    if(nums[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    

    //what if nums[0]=0, then if(nums[0]<=tar) dp[0][arr[0]]=1; //which would mean dp[0][0]=1 but we already have a case for that


    if(nums[0]!=0 && nums[0]<=tar){
        dp[0][nums[0]]=1;
    }



    
    for(int i=1;i<n;i++){
        for(int k=0;k<=tar;k++){

            int nottake=dp[i-1][k];

            int take=0;

            if(nums[i]<=k){
                take=dp[i-1][k-nums[i]];
            }

            dp[i][k]=take+nottake;

        }
    }

    return dp[n-1][tar];


}

int countPartitions(int n, int diff, vector<int>&nums){

    int n=nums.size();
    
    int totalSum=0;

    int target=(totalSum-diff)/2;

    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    if(totalSum<0 || target%2!=0)
        return 0; //doesnt count the subset

    return findWays(nums,target);


}