//Problem-Maximum Consecutive Ones
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int>&nums){

    int n=nums.size();

    int maxi=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(nums[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }

        if(nums[i]==0){
            cnt=0;
        }
    }

return maxi;

}

int main(){
    vector<int>nums={1,0,1,1,0,1};
    cout<<maxConsecutiveOnes(nums)<<" ";
    return 0;
}