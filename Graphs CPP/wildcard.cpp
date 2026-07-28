//Problem-Wildcard Matching
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

bool f(int i, int j,string str,string pat){
    
    //base cases
    //1.When the pattern and string get exhausted, this means all the characters have been matched
    if(i<0 && j<0) return true;

    //if the pattern string gets exhausted but the string still has some characters left
    if(i<0 && j>=0) return false;

    if(i>=0 && j<0){ //if my string2 gets exhausted and some are remaining from the first
        for(int c=0;c<=i;i++){
            if(pat[c]!='*'){
                return false;
            }

            return true;
        }
    }

    //matching
    if(pat[i]==str[j]){
        return f(i-1,j-1,str,pat);
    }

    //if it is an *
    if(pat[i]=='*'){
        return f(i-1,j,str,pat) || f(i,j-1,str,pat);
    }

    return false;

}




bool wildCard(string str,string pat){


int m=str.size();
int n=pat.size();

return f(m-1,n-1,str,pat);

}

//Memoization
bool f(int i, int j,string str,string pat,vector<vector<int>>&dp){
    
    //base cases
    //1.When the pattern and string get exhausted, this means all the characters have been matched
    if(i<0 && j<0) return true;

    //if the pattern string gets exhausted but the string still has some characters left
    if(i<0 && j>=0) return false;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i>=0 && j<0){ //if my string2 gets exhausted and some are remaining from the first
        for(int c=0;c<=i;i++){
            if(pat[c]!='*'){
                return false;
            }

            return true;
        }
    }

    //matching
    if(pat[i]==str[j]){
        return dp[i][j]=f(i-1,j-1,str,pat);
    }

    //if it is an *
    if(pat[i]=='*'){
        return dp[i][j]=f(i-1,j,str,pat) || f(i,j-1,str,pat);
    }

    return false;

}

bool f(int i, int j,string str,string pat,vector<vector<int>>&dp){
    
    //base cases
    //1.When the pattern and string get exhausted, this means all the characters have been matched
    if(i==0 && j==0) return true;

    //if the pattern string gets exhausted but the string still has some characters left
    if(i==0 && j>=0) return false;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i>=0 && j==0){ //if my string2 gets exhausted and some are remaining from the first
        for(int c=0;c<=i;i++){
            if(pat[c]!='*'){
                return false;
            }

            return true;
        }
    }

    //matching
    if(pat[i]==str[j]){
        return dp[i][j]=f(i-1,j-1,str,pat);
    }

    //if it is an *
    if(pat[i]=='*'){
        return dp[i][j]=f(i-1,j,str,pat) || f(i,j-1,str,pat);
    }

    return false;

}

//Tabulation - f(n-1,m-1) where n=pat.size() && m=str.size();
bool wildCard(string str,string pat){

int n=pat.size();
int m=str.size();

vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));

//Base cases

dp[0][0]=true;//return true;

//j==0 is already used so we start from j==1
//if j>=0 and i==0
for(int j=1;j<=m;j++){
    dp[0][j]=false; //return false;
}

//if i>=0 && j==0
for(int i=1;i<=n;i++){
    dp[i][0]=true;
    for(int c=1;c<=i;c++){
          if(pat[c-1]!='*'){
                dp[i][0]=false;
                break;
          }
    }
}

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        //matching
        if(pat[i-1]==str[j-1] || pat[i-1]=='?'){
            dp[i][j]=dp[i-1][j-1];
        }

        else if(pat[i-1]=='*'){
            dp[i][j]=dp[i-1][j] || dp[i][j-1];
        }

        else{
            dp[i][j]=false;
        }
    }
}

return dp[n][m];
}

//Space Optimization
bool wildCard(string str,string pat){

int n=pat.size();
int m=str.size();

vector<bool>prev(m+1,false);
vector<bool>curr(m+1,false);

//Base cases

prev[0]=true;//return true;

//j==0 is already used so we start from j==1
//if j>=0 and i==0
for(int j=1;j<=m;j++){
    prev[j]=false; //return false;
}


for(int i=1;i<=n;i++){

    //for every row you are assigning the 0th's column value
    curr[0]=true;
    for(int c=1;c<=i;c++){
          if(pat[c-1]!='*'){
                curr[0]=false;
                break;
          }
    }


    for(int j=1;j<=m;j++){
        //matching
        if(pat[i-1]==str[j-1] || pat[i-1]=='?'){
            curr[j]=prev[j-1];
        }

        else if(pat[i-1]=='*'){
            curr[j]=prev[j] || curr[j-1];
        }

        else{
            curr[j]=false;
        }
    }

    prev=curr;
}

return prev[m];
}



