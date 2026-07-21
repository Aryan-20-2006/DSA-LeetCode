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

// int knapsack(vector<int>&wt,vector<int>&value, int n, int maxWeight){



//     vector<int>prev(maxWeight+1,0);

//     for(int W=wt[0];W<=maxWeight;W++){
//         prev[W]=value[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int weight=maxWeight;weight>=0;weight--){

//             int nottake=0+prev[weight];

//             int take=INT_MIN;

//             if(wt[ind]<=maxWeight){
//                 take=value[ind]+prev[weight-wt[ind]];
//             }

//             prev[weight]=max(take,nottake);
//         }
//     }

// return prev[maxWeight];

// }

//Unbounded Knapsack-Here you can take an infinite supply of items

//Recurrence

// int f(int ind, int W,vector<int>&wt,vector<int>&value){


//     if(ind==0){
//         return ((W/wt[0])+value[0]); //lets say at index 0 if I have one item of weight 3 and value 10 and W=8. The person can steal twice i.e 8/3=2 times and the value gets added
//     }
    
    
//     int nottake=0+f(ind-1,W,wt,value);

//     int take=INT_MIN;

//     if(wt[ind]<=W){
//         take=value[ind]+f(ind,W-wt[ind],wt,value);
//     }

//     return max(take,nottake);

// }


//Memoization
int f(int ind, int W,vector<int>&wt,vector<int>&value,vector<vector<int>>&dp){


    if(ind==0){
        return ((W/wt[0])+value[0]); //lets say at index 0 if I have one item of weight 3 and value 10 and W=8. The person can steal twice i.e 8/3=2 times and the value gets added
    }

    if(dp[ind][W]!=-1)
        return dp[ind][W];
    
    
    int nottake=0+f(ind-1,W,wt,value,dp);

    int take=INT_MIN;

    if(wt[ind]<=W){
        take=value[ind]+f(ind,W-wt[ind],wt,value,dp);
    }

    return dp[ind][W]=max(take,nottake);

}

// int unboundedKnapsack(vector<int>&wt,vector<int>&value,int n,int W){

//     vector<vector<int>>dp(n,vector<int>(W+1,0));

//     return f(n-1,W,wt,value,dp);


// }

//Tabulation-Base case to Recursion
// int unboundedKnapsack(vector<int>&wt,vector<int>&value,int n,int W){

//     vector<vector<int>>dp(n,vector<int>(W+1,0));

//     for(int i=wt[0];i<=W;i++){
//         dp[0][W]=((int)W/wt[0])+value[0]; //since we dont want decimal values
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int w=0;w<=W;w++){
//             int nottake=0+dp[ind-1][w];

//             int take=INT_MIN;

//             if(wt[ind]<=W){
//                 take=value[ind]+dp[ind][w-wt[ind]];
//             }

//             dp[ind][w]=max(take,nottake);
//         }
//     }

//     return dp[n-1][W];


// }

//Space Optimization-using 2 arrays
// int unboundedKnapsack(vector<int>&wt,vector<int>&value,int n,int W){

//     vector<int>prev(W+1,0);
//     vector<int>curr(W+1,0);

//     for(int i=0;i<=W;i++){
//         prev[W]=((int)W/wt[0])+value[0];
//     }
    

//     for(int ind=1;ind<n;ind++){
//         for(int w=0;w<=W;w++){
//             int nottake=0+prev[w];

//             int take=INT_MIN;

//             if(wt[ind]<=W){
//                 take=value[ind]+curr[w-wt[ind]];
//             }

//             curr[w]=max(take,nottake);
//         }

//         prev=curr;
//     }

//     return prev[W];


// }

//Space Optimization-using 1 array
int unboundedKnapsack(vector<int>&wt,vector<int>&value,int n,int W){

    vector<int>prev(W+1,0);


    for(int i=0;i<=W;i++){
        prev[W]=((int)W/wt[0])+value[0];
    }
    

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int nottake=0+prev[w];

            int take=INT_MIN;

            if(wt[ind]<=W){
                take=value[ind]+prev[w-wt[ind]];
            }

            prev[w]=max(take,nottake);
        }
    }

    return prev[W];


}

