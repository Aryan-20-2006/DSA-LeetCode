//Problem-Majority Element
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>&nums){

    int n=nums.size();
    //if there is only one elemnt 
    if(n==1){
        return nums[0];
    }

    int n=nums.size();
    unordered_map<int,int>freq;
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }

    for(int i=0;i<nums.size();i++){
        if(freq[nums[i]]>floor(n/2)){
            return nums[i];
        }
    }

    return -1;
}

int main(){
    vector<int>nums={8,8,7,7,7};
    cout<<majorityElement(nums)<<" ";
    return 0;
}