//Problem-House Robber
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//Tabulation-Base Case to Recursion
int houseRobber(vector<int>&nums){

    int n=nums.size();
    vector<int>dp(n,0);

    //base case
    dp[0]=nums[0];

    //if it has only one element
    for(int i=1;i<n;i++){
        int take=nums[i];

        if(i>1)
            take+=dp[i-2];

        int nottake=0+dp[i-1];

        dp[i]=max(take,nottake);

    }

    return dp[n-1];

}

int main(){

    vector<int>nums={2,1,4,9};
    int n=4;
    vector<int>dp(n,0);

    cout<<houseRobber(nums)<<" ";
    return 0;

}




//Space optimized approach
// int houseRobber(vector<int>&nums){

//     int prev=nums[0];
    
//     int prev2=0;

//     for(int i=1;i<nums.size();i++){
//         int take=nums[i];

//         if(i>1)
//             take+=prev2;

//         int nottake=0+prev;
//         int curr=max(take,nottake);

//         prev2=prev;
//         prev=curr;
        

//     }

//     return prev;

// }