//Problem-Longest Consecutive Sequence
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>&nums){

//sort the array
sort(nums.begin(),nums.end()); //this takes nlogn so its not optimal

int maxlen=0;
int len=1;

int n=nums.size();

for(int i=0;i<n-1;i++){
    if(nums[i]<nums[i+1] && nums[i+1]==1+nums[i]){
        len++;
        maxlen=max(maxlen,len);
    }
}

return maxlen;


}

int main(){
    vector<int>nums={1,0,1,2};
    cout<<longestConsecutive(nums)<<" ";
    return 0;
}