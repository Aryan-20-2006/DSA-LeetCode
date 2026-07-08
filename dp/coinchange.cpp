//Problem-Coin Change
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int T, vector<int>&nums,vector<vector<int>>&dp){

    if(ind==0){
        if(T%nums[0]==0)
            return T/nums[0];
        else
            return 1e9; //we wont write INT_MAX;
    }

    if(dp[ind][T]!=-1)
        return dp[ind][T];

    int notTake=0 + f(ind-1,T,nums,dp);
    int take=INT_MAX; //since we're looking for min here

    if(nums[ind]<=T)
        take=1+f(ind, T-nums[ind],nums,dp);

    return dp[ind][T]=min(take,notTake);
}

int coinChange(vector<int>&nums,int target){
    
    int n=nums.size();
    vector<int>prev(target+1,0),curr(target+1,0);
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    //we're using tabulation to optimize the space
    for(int T=0;T<=target;T++){
        if(T%nums[0]==0){
            prev[T]=T/nums[0];
        }

        else{
            prev[T]=1e9;
        }

    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=target;T++){
            int notTake=0 + prev[T];
            int take=INT_MAX; //since we're looking for min here

        if(nums[ind]<=T)
            take=1+curr[T-nums[ind]];

        curr[T]=min(take,notTake);
        }

        prev=curr;
    }

    int ans=prev[target]; //can be previous or current

    if(ans>=1e9)
        return -1; //since the question asks if its not possible, return -1

    return ans;

}

int main(){

    vector<int>nums={1,2,5};
    int target=11;
    cout<<coinChange(nums,target)<<"";
    return 0;
}