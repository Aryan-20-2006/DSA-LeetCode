#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>&nums, int k){

    int n=nums.size();
    
    vector<int>prev(k+1,0);
    vector<int>curr(k+1,0);

    prev[0]=curr[0]=1;

    if(nums[0]<=k){
        prev[nums[0]]=1;
    }


    for(int i=1;i<n;i++){
        for(int sum=0;sum<=k;sum++){
            int notpick=prev[sum];

            int pick=0;

            if(nums[i]<=sum){
                pick=prev[sum-nums[i]];
            }

            curr[sum]=pick+notpick;

        }

        prev=curr;
    }

return prev[k];

}

int main(){

    vector<int>nums={1,2,3,4,5};
    int k=5;
    cout<<countSubsets(nums,k)<<" ";
    return 0;
}