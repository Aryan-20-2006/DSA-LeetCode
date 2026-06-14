//Problem-Maximum Subarray
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>&nums){

    int maxSum=INT_MIN;
    int sum=0;

    int n=nums.size();

    for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum>maxSum)
            maxSum=sum;
        if(sum<0)
            sum=0; //reset sum to zero

    }

return maxSum;


}

int main(){

    vector<int>nums={1};
    cout<<maxSubArray(nums)<<" ";
    return 0;

}