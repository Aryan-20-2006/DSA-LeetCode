//Problem-DP on strings-Longest Common Subsequence
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

//Recurrence

// int f(int ind1,int ind2,string str1,string str2){
    
//     //base case
//     if(ind1<0 || ind2<0){
//         return 0; //if the indices become negative, then the the longest length would be zero
//     }


//     //if it matches
//     if(str1[ind1]==str2[ind2]){
//         return 1+f(ind1-1,ind2-2,str1,str2);
//     }

//     //if it doesent match, either ind1 can go back or ind2 can go back and take max of both the possibilities

//     return 0+max(f(ind1-1,ind2,str1,str2),f(ind1,ind2-1,str1,str2));
// }

//Memoization
// int f(int ind1,int ind2,string str1,string str2,vector<vector<int>>&dp){
    
//     //base case
//     if(ind1<0 || ind2<0){
//         return 0; //if the indices become negative, then the the longest length would be zero
//     }


//     //if it matches
//     if(str1[ind1]==str2[ind2]){
//         return dp[ind1][ind2]=1+f(ind1-1,ind2-2,str1,str2);
//     }

//     //if it doesent match, either ind1 can go back or ind2 can go back and take max of both the possibilities

//     return dp[ind1][ind2]=0+max(f(ind1-1,ind2,str1,str2),f(ind1,ind2-1,str1,str2));
// }


// int lcs(string str1, string str2){

//     int n=str1.size();
//     int m=str2.size();
    
//     vector<vector<int>>dp(n,vector<int>(m,-1));

//     return f(n-1,m-1,str1,str2,dp);


// }

//Since we cant write dp[-1], we'll use the concept of shifting the indices i.e i to i-1 and j to j-1

// int f(int i, int j, string s1, string s2,vector<vector<int>>&dp){

//     //in this case if we're shifting i to i-1 and j to j-1 , which means your 0 now points to -1 and n points to n-1 , f(1) points to 0 and so on
//     if(i==0 || j==0){
//         return 0;
//     }

//     if(dp[i][j]!=-1)
//         return dp[i][j];

//     //match
//     if(s1[i-1]==s2[j-1]){
//         return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
//     }

//     return dp[i][j]=0+max(f(i,j-1,s1,s2,dp),f(i-1,j,s1,s2,dp));

// }

// int lcs(string s1,string s2){

//     int n=s1.size();
//     int m=s2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0)); //im declaring an extra size +1 since im calling the states m and n . Because in right shifting, you're going back . So you need one extra space
//     return f(n,m,s1,s2,dp);
// }

//Tabulation-Base Case to Recursion
// int lcs(string str1,string str2){


//     int n=str1.size();
//     int m=str2.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    
//     //Base case-Using shifting of indices
//     for(int j=0;j<m;j++){
//         dp[0][j]=0; //this is when i==0
//     }

//     for(int i=0;i<n;i++){
//         dp[i][0]=0; //this is when j==0
//     }

//     //since im shifting my indices here from i to i-1 and j to j-1
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){

//             //if it matches
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
            

//             //if it doesnt match
//             else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]); //use else otherwise it wont return

//         }
//     }
    

// return dp[n][m];

// }

//Space Optimization
// int lcs(string str1,string str2){




//     int n=str1.size();
//     int m=str2.size();
//     vector<int>prev(m+1,0);
//     vector<int>curr(m+1,0);
    
//     //Base case-Using shifting of indices
//     for(int j=0;j<m;j++){
//         prev[j]=0; //this is when i==0
//     }
    
//     //we dont need curr , since for the first row everyone is zero


//     //since im shifting my indices here from i to i-1 and j to j-1
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){

//             //if it matches
//             if(str1[i-1]==str2[j-1]){
//                 curr[j]=1+prev[j-1];
//             }
            

//             //if it doesnt match
//             else curr[j]=0+max(prev[j],curr[j-1]); //use else otherwise it wont return

//         }

//         prev=curr;
//     }
    

// return prev[m];

// }

//In case if we have to print the LCS
// void lcs(string str1,string str2){


//     int n=str1.size();
//     int m=str2.size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
    
//     //Base case-Using shifting of indices
//     for(int j=0;j<m;j++){
//         dp[0][j]=0; //this is when i==0
//     }

//     for(int i=0;i<n;i++){
//         dp[i][0]=0; //this is when j==0
//     }

//     //since im shifting my indices here from i to i-1 and j to j-1
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){

//             //if it matches
//             if(str1[i-1]==str2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//             }
            

//             //if it doesnt match
//             else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]); //use else otherwise it wont return

//         }
//     }

//     int len=dp[n][m];
    
//     int index=len-1; //because im storing the matched character from the last index

//     int i=n;
//     int j=m;

//     //we need to store the answer in a string
//     string s=" ";

//     for(int i =0;i<len;i++){
//         s+='#'; //fill it with dummy values for now
//     }

//     //in the table if either i or j becomes 0 zero, you stop
//     while(i>0 && j>0){

//         //when it matches . Here, we're using 0 based indexity
//         if(str1[i-1]==str2[j-1]){
//             s[index]=str1[i-1]; //store the answer at that index
//             index--;
//             i--,j--; //if it matches, you go to the diagonal in the previous row and column
//         }

//         //if it doesnt match
//         else if(dp[i-1][j]>dp[i][j-1]){ //if the value at the previous row is greater
//             i=i-1; //go to that row
//         }

//         else{
//             j=j-1;
//         }
//     }

//     cout<<s;

// }

//Longest Common Substring
// int f(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){

//     if(ind1==0 & ind2==0){
//         return 0;
//     }

//     if(dp[ind1][ind2]!=-1){
//         return -1;
//     }


// if(s1[ind1-1]==s2[ind2-1])
//     return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s1,s2,dp);

//     return dp[ind1][ind2]=0;

// }

// int longestcommomSubstr(string s1, string s2){

//     int n=s1.size();
//     int m=s2.size();
//     int ans=0;
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

//     //shifting of indices
//     for(int j=0;j<m;j++){
//         dp[0][j]=0;
//     }

//     for(int i=0;i<n;i++){
//         dp[i][0]=0; 
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(s1[i-1]==s2[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//                 ans=max(ans,dp[i][j]);
//             }

//             else{
//                 dp[i][j]=0; //since we're looking for consecutive characters to match not subsequence, only if matches it will depend on its previous state
//             }
//         }
//     }

//     return ans;

// }

//Space Optimization
int longestcommomSubstr(string s1, string s2){

    int n=s1.size();
    int m=s2.size();
    int ans=0;//since I need to longest common substring
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0); //these columns are already filled with zeroes so we dont need the for loops again

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }

            else{
                curr[j]=0; //since we're looking for consecutive characters to match not subsequence, only if matches it will depend on its previous state
            }
        }

        prev=curr;
    }

    return ans;

}