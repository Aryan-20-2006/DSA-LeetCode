//Minimum insertions to make string a palindrome
//Difficulty-Hard



#include<bits/stdc++.h>
using namespace std;

// int lcs(string s, string s2){

//     int n=s.size();
//     int m=s2.size();

//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     for(int j=0;j<m;j++){
//         dp[0][j]=0;
//     }

//     for(int i=0;i<n;i++){
//         dp[i][0]=0;
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){

//         if(s[i-1]==s2[j-1]){
//             dp[i][j]=1+dp[i-1][j-1];
//         }

//         else{
//             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//         }
//     }
// }

// return dp[n][m];

// }

// int longestPalindrome(string s){

//     string s2=s;
//     reverse(s2.begin(),s2.end());
//     return lcs(s,s2);
// }


// //for minimum insertions, its the length of the string - longestPalindromicSubsequence
// int minInsertion(string s){

//     int len=s.size();
//     int LPS=longestPalindrome(s);
//     return len-LPS;
// }

//Minimum Insertions to convert string A to string B
int LCS(string s1,string s2){

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int j=0;j<m;j++){
        dp[0][j]=0;
    }

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

return dp[n][m];

}

int minOperations(string str1,string str2){

    int deletions=str1.size()-LCS(str1,str2);
    int insertions=str2.size()-LCS(str1,str2);
    return deletions+insertions;



}