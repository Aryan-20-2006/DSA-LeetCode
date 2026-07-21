//Problem-Rod Cutting 
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//Recurrence
int f(int ind,int N,vector<int>&price){

    //base case
    if(ind==0){
        return (N*price[0]);//suppose I have one element of 6 at index 0 and the rodlength that im looking for is 12. So I can take 12 rods each of length 1
    }

    int nottake=0+f(ind-1,N,price);

    int take=INT_MIN;

    //the 1 based indexing refers to the rodlength, since im using 0 based indexing i.e rodlength=i+1

    int rodlength=ind+1;

    //N is the rodlength that we're looking for 
    if(rodlength<=N){
        take=price[ind]+f(ind,N-price[ind],price);
    }


    return max(take,nottake);
}

//Memoization
// int f(int ind,int N,vector<int>&price,vector<vector<int>>&dp){

//     //base case
//     if(ind==0){
//         return (N*price[0]);

//     if(dp[ind][N]!=-1)
//         return dp[ind][N];

//     int nottake=0+f(ind-1,N,price,dp);

//     int take=INT_MIN;

//     //the 1 based indexing refers to the rodlength, since im using 0 based indexing i.e rodlength=i+1

//     int rodlength=ind+1;

//     //N is the rodlength that we're looking for 
//     if(rodlength<=N){
//         take=price[ind]+f(ind,N-rodlen,price,dp);
//     }


//     return dp[ind][N]=max(take,nottake);
// }


// int rodCutting(vector<int>&price, int N){

//     vector<vector<int>>dp(n,vector<int>(N+1,0));
//     return f(n-1,N,price,dp);
// }

//Tabulation-Base Case to Recursion
// int rodCutting(vector<int>&price, int n){

//     
//     vector<vector<int>>dp(n,vector<int>(n+1,0));

//     for(int N=0;N<=n;N++){
//         dp[0][N]=N*price[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int rodlen=0;rodlen<=n;rodlen){

//             int nottake=0+dp[ind-1][rodlen];

//             int take=INT_MIN;

//             if(price[ind]<=N){
//                 take=price[ind]+dp[ind][n-rodlen];
//             }

//             dp[ind][rodlen]=max(take,nottake);

//         }
//     }

// return dp[n-1][n];
// }

//Space Optimization-Using 2 arrays
// int rodCutting(vector<int>&price, int n){

//     int n=price.size();
//     vector<int>prev(n+1,0);
//     vector<int>curr(n+1,0);

//     for(int N=0;N<=n;N++){
//         prev[N]=N*price[0];
//     }

//     for(int ind=1;ind<n;ind++){
//         for(int rodlen=0;rodlen<=N;rodlen){

//             int nottake=0+prev[rodlen];

//             int take=INT_MIN;

//             if(price[ind]<=N){
//                 take=price[ind]+curr[N-rodlen];
//             }

//             curr[rodlen]=max(take,nottake);

//         }

//         prev=curr;
//     }

// return prev[N];
// }

//Space Optimization-Using 1 array
int rodCutting(vector<int>&price, int n){

    int n=price.size();
    vector<int>prev(n+1,0);

    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int rodlen=0;rodlen<=n;rodlen){

            int nottake=0+prev[rodlen];

            int take=INT_MIN;

            if(price[ind]<=n){
                take=price[ind]+prev[n-rodlen];
            }

            prev[rodlen]=max(take,nottake);

        }
    }

return prev[n];
}