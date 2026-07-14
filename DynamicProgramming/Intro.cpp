//Fibnonacci Number

#include<bits/stdc++.h>
using namespace std;

// int f(int n, vector<int>&dp){

//     //base case
//     if(n<=1)
//         return n;

//     if(dp[n]!=-1)
//         return dp[n];

//     return dp[n]=dp[n-1]+dp[n-2];

// }

// int main(){

//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);

//     cout<<f(n,dp)<<" ";
//     return 0;


// }

//Better way to write it 
// int f(int n, vector<int>&dp){

//     //base case
//     if(n<=1)
//         return n;

//     if(dp[n]!=-1)
//         return dp[n];

//     return dp[n]=dp[n-1]+dp[n-2];

// }

int main(){
    int n;
    cin>>n;

    int prev2=0;
    int prev=1;

    for(int i=2;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }

    cout<<prev;
    return 0;
}