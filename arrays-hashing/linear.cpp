//Problem:Linear Search
//Difficulty:Easy


#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>&nums, int target){

    //normal linear search

    for(int i=0;i<nums.size();i++){
        if(nums[i]==target)
            return i;
    }

    return -1;

}

int main(){

    vector<int>nums={1,1,3,4};
    int target=1;
    cout<<linearSearch(nums,target)<<" ";
    return 0;

}