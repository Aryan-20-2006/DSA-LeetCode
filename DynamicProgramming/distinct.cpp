//Problem-Distinct Subsequences
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s,string t){

    //Base case
    if(j<0)
        return 1; //this means all the characters have matched
    if(i<0)
        return 0; //if the first string gets exhausted, then there are characters remaining in s2;

    if(s[i]==t[j]){
        return f(i-1,j-1,s,t)+f(i-1,j,s,t); //if the characters match go back one place behind in s, otherwise if you want to start at a different point then i-1
    }

    //if not matching
    return f(i-1,j,s,t);

}

//Memoization
int f(int i,int j,string s,string t,vector<vector<int>>&dp){

    //Base case
    if(j<0)
        return 1; //this means all the characters have matched
    if(i<0)
        return 0; //if the first string gets exhausted, then there are characters remaining in s2;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp); //if the characters match go back one place behind in s, otherwise if you want to start at a different point then i-1
    }

    //if not matching
    return dp[i][j]=f(i-1,j,s,t,dp);

}

//Tabulation
// int distincSubequences(string s, string t){

//     int n=s.size();
//     int m=t.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     //if we see when i<0 the index can become negative which is the same for j<0 where j can become negative. To deal with this we add +1 to everything
//     for(int i=0;i<=n;i++){
//         dp[i][0]=1; //when j==0 return 1
//     }

//     //in the previous case, I wrote for j==0, since that state is already taken, then I have to start from j=1
//     for(int j=1;j<=m;j++){
//         dp[0][j]=0; //when i==0 return 0;
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             //if the characters match
//             if(s[i-1]==t[j-1]){
//                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
//             }

//             else{
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }

//     return dp[n][m];

// }

//Space Optimization-2D array
// int distincSubequences(string s, string t){

//     int n=s.size();
//     int m=t.size();
//     vector<int>prev(m+1,0);
//     vector<int>curr(m+1,0);

//     //if we see when i<0 the index can become negative which is the same for j<0 where j can become negative. To deal with this we add +1 to everything

//     prev[0]=curr[0]=1; //when j==0 return 1

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             //if the characters match
//             if(s[i-1]==t[j-1]){
//                 curr[j]=prev[j-1]+prev[j];
//             }

//             else{
//                 curr[j]=prev[j];
//             }
//         }

//         prev=curr;
//     }

//     return prev[m];

// }

int distincSubequences(string s, string t){

    int n=s.size();
    int m=t.size();
    vector<int>prev(m+1,0);

    prev[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j>=1;j--){
            //if the characters match
            if(s[i-1]==t[j-1]){
                prev[j]=prev[j-1]+prev[j];
            }

            else{
                prev[j]=prev[j]; //since to compute the curr row we require the prev row, so we can just store the values in the prev row itself
            }
    }

    return prev[m];

}