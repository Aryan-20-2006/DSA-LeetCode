//Problem-Shortest Common Supersequence
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//using the concept of lcs

string shortestCommonSupersequence(string str1,string str2){

    int n=str1.size();
    int m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int j=0;j<m;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }

            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

//since here I have to print the the supersequence

string ans=" ";

int i=n;
int j=m;

while(i>0 && j>0){
    if(str1[i-1]==str2[j-1]){
        ans+=str1[i-1];
        i--;
        j--; //go to the upper diagonal
    }

    else if(dp[i-1][j]>dp[i][j-1]){
        ans+=str1[i-1]; 
        i--;
    }

    else{
        ans+=str2[j-1];
        j--;
    }
}

//if there are any remaining characters left from either str1 or str2 , add it to the answer

while(i>0){
    ans+=str1[i-1];
    i--;
}

while(j>0){
    ans+=str2[j-1];
    j--;
}

//the final supersequence is our reversed answer

reverse(ans.begin(),ans.end());

return ans;



}