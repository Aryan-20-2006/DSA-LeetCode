//Problem-Frog Jump With K distances
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// int f(int ind, vector<int>&heights, vector<int>&dp){

//     if(ind==0)
//         return 0;

//     if(dp[ind]!=-1)
//         return dp[ind];

//     int left=f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);

//     int right=INT_MAX;

//     if(ind>1){
//         right=f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
//     }

//     return dp[ind]=min(left,right);

// }

// int frogJump(int n,vector<int>&heights){

//     vector<int>dp(n+1,-1);
//     return f(n-1,heights,dp);
// }

//Memoization Approach
int frogJump(int n, vector<int>&heights){

    vector<int>dp(n,0);
    
    //base case 
    dp[0]=0;

    for(int i=1;i<n;i++){
        int left=dp[i-1]+abs(heights[i]-heights[i-1]);

        int right=INT_MAX;

        if(i>1){
            right=dp[i-2]+abs(heights[i]-heights[i-2]);
        }

        dp[i]=min(left,right);

    }

   return dp[n-1];
    
}


//Better Approach-Tabulation

// int frogJump(int n, vector<int>&heights){

//     int prev=0;
//     int prev2=0;

//     for(int i=1;i<n;i++){
//         int left=prev+abs(heights[i]-heights[i-1]);

//         int right=INT_MAX;

//         if(i>1){
//             right=prev2+abs(heights[i]-heights[i-2]);
//         }   

//         int curr=min(left,right);

//         prev2=prev;
//         prev=curr;
//     }

// return prev;


// }



int main(){

    vector<int>heights={30,10,60,10,60,50};
    int n=6;
    cout<<frogJump(n,heights)<<"";
    return 0;

}