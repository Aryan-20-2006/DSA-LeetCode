#include<bits/stdc++.h>
using namespace std;

//Optimal Approach-We track both the max and min product ending at each index , a -ve number can flip min to max
int maxProduct(vector<int>&nums){

    int curmax=nums[0];
        int curmin=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int x=nums[i];

            if(x<0)
                swap(curmax,curmin);

            curmax=max(x,curmax*x);
            curmin=min(x,curmin*x);

            ans=max(ans,curmax);

        }

        return ans;

}

int main(){

    vector<int>nums={0,2};
    cout<<maxProduct(nums)<<" ";
    return 0;

}