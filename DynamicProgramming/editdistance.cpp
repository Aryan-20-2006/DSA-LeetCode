//Problem-Edit distance
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string start,string target){

//Base cases

//1.If the string s1 gets exhausted, then we need j+1 insert operations to form the string s2
if(i<0){
    return j+1;
}

//2.If the string s2 gets exhausted, then we need i+1 delete operations to form the string s2
if(j<0){
    return i+1;
}

//if the characters match
if(start[i]==target[j]){
    return 0+f(i-1,j-1,start,target); //if the characters match, there is no need to add it to the number of operations
}

return 1+min((f(i,j-1,start,target)),min(f(i-1,j,start,target),f(i-1,j-1,start,target)));


}

//Memoization
// int f(int i,int j,string start,string target,vector<vector<int>>&dp){

// //Base cases

// //1.If the string s1 gets exhausted, then we need j+1 insert operations to form the string s2
// if(i<0){
//     return j+1;
// }

// //2.If the string s2 gets exhausted, then we need i+1 delete operations to form the string s2
// if(j<0){
//     return i+1;
// }

// if(dp[i][j]!=-1)
//     return dp[i][j];

// //if the characters match
// if(start[i]==target[j]){
//     return dp[i][j]=0+f(i-1,j-1,start,target); //if the characters match, there is no need to add it to the number of operations
// }

// return dp[i][j]=1+min((f(i,j-1,start,target)),min(f(i-1,j,start,target),f(i-1,j-1,start,target)));


// }

// int editDistance(string start,string target){

// int n=start.size();
// int m=target.size();
// vector<vector<int>>dp(n,vector<int>(m,-1));
// return f(n-1,m-1,start,target,dp);

// }

//Tabulation
int editDistance(string start,string target){

    int n=start.size();
    int m=target.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    //base cases 

    //2.If s2 gets exhausted i.e if j<0. Here since we're handling negatives so we'll consider j=0;
    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }

     //1.If s1 gets exhausted i.e if i<0 . Here since we're handling negatives so we'll consider i=0
    for(int j=1;j<=m;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(start[i-1]==target[j-1]){
                dp[i][j]=0+dp[i-1][j-1]; //when it is matching
            }

            else{
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }

        }
    }

return dp[n][m];

}

//Space Optimization-Using 1D array
int editDistance(string start,string target){

    int n=start.size();
    int m=target.size();

    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);

    //base cases 
    for(int j=0;j<=m;j++){
        prev[j]=j;// I dont need for every single row when I know that my first row is storing all the values of j
    }

    for(int i=1;i<=n;i++){
        curr[0]=i; //every time you're updating the row, it should have the value at i
        for(int j=1;j<=m;j++){
            if(start[i-1]==target[j-1]){
                curr[j]=0+prev[j-1]; //when it is matching
            }

            else{
                curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));
            }

        }
        prev=curr;
    }

return prev[m];

}

