//Problem-Longest Subarray with a given sum
//Difficulty-Medium


#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>&nums,int k){

int i=0;
int n=nums.size();
int sum=0;

int maxlen=0;

for(int j=i;j<n;j++){
    sum+=nums[j];

    while(sum>k){
        sum-=nums[i];
        i=i+1;
    }

    if(sum==k){
        int len=j-i+1;
        maxlen=max(maxlen,len);
    }

}

return maxlen;


}

int main(){
    vector<int>nums={-3,2,1};
    int k=15;
    cout<<longestSubarray(nums,k)<<" ";
    return 0;
}