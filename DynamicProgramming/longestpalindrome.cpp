//Problem-Longest Palindromic Subsequence
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int longestcommonSubseq(string s,string s2){

    int n=s.size();
    int m=s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    for(int j=0;j<m;j++){
        dp[0][j]=0;
    }

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

return dp[n][m];

}

int longestPalindrome(string s){

    
    string s2=s;
    reverse(s2.begin(),s2.end());
    return longestcommonSubseq(s,s2);
}