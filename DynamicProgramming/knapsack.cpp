//Problem-0/1 Knapsack

#include<bits/stdc++.h>
using namespace std;

//Recurrence
// int f(int ind, int W,vector<int>weight, vector<int>&value){

//     //Here W is the knapsack capacity
//     if(ind==0){
//         if(weight[0]<=W){
//             return value[0];
//         }

//         else{
//             return 0;
//         }

//     }

//         int nottake=0+f(ind-1,W,weight, value);

//         int take=INT_MIN;

//         if(weight[ind]<=W){
//             take=value[ind]+f(ind-1,W-weight[ind],weight,value);
//         }


//         return max(take,nottake);

// }

//Memoization

// int f(int ind, int W,vector<int>weight, vector<int>&value, vector<vector<int>>&dp){

//     //Here W is the knapsack capacity
//     if(ind==0){
//         if(weight[0]<=W){
//             return value[0];
//         }

//         else{
//             return 0;
//         }

//     }

//     if(dp[ind][W]!=-1){
//         return dp[ind][W];
//     }

//         int nottake=0+f(ind-1,W,weight, value,dp);

//         int take=INT_MIN;

//         if(weight[ind]<=W){
//             take=value[ind]+f(ind-1,W-weight[ind],weight,value,dp);
//         }


//         return dp[ind][W]=max(take,nottake);

// }

//Tabulation

// int knapsack(vector<int>&wt,vector<int>&value, int n, int maxWeight){



//     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

//     for(int W=wt[0];W<=maxWeight;W++){
//         dp[0][W]=value[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int weight=0;weight<=maxWeight;weight++){

//             int nottake=0+dp[ind-1][weight];

//             int take=INT_MIN;

//             if(wt[ind]<=maxWeight){
//                 take=value[ind]+dp[ind-1][maxWeight-wt[ind]];
//             }

//             dp[ind][weight]=max(take,nottake);
//         }
//     }

// return dp[n-1][maxWeight];

// }

//Space Optimization-using two rows
// int knapsack(vector<int>&wt,vector<int>&value, int n, int maxWeight){



//     vector<int>prev(maxWeight+1,0);
//     vector<int>curr(maxWeight+1,0);

//     for(int W=wt[0];W<=maxWeight;W++){
//         prev[W]=value[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int weight=0;weight<=maxWeight;weight++){

//             int nottake=0+prev[weight];

//             int take=INT_MIN;

//             if(wt[ind]<=maxWeight){
//                 take=value[ind]+prev[weight-wt[ind]];
//             }

//             curr[weight]=max(take,nottake);
//         }

//         prev=curr;
//     }

// return prev[maxWeight];

// }

//Space optmization-Using only the prev row by filling from right to left
/*Why?-Because when ur doing maxWeight-weight[i], we're not concerned about the right half, so the current value we wnat find depends on the values in the previous row, so we can use the previous row only



*/

int knapsack(vector<int>&wt,vector<int>&value, int n, int maxWeight){



    vector<int>prev(maxWeight+1,0);

    for(int W=wt[0];W<=maxWeight;W++){
        prev[W]=value[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int weight=maxWeight;weight>=0;weight--){

            int nottake=0+prev[weight];

            int take=INT_MIN;

            if(wt[ind]<=maxWeight){
                take=value[ind]+prev[weight-wt[ind]];
            }

            prev[weight]=max(take,nottake);
        }
    }

return prev[maxWeight];

}