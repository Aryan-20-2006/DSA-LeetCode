//Problem-Check if the Array is Sorted II
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>&nums){

    //in a sorted array, we know that the previous element is smaller than the current element
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1])
            return false;
    }

    return true;

}

int main(){

    vector<int>nums={1,2,3,4,5};

    cout<<isSorted(nums)<<endl;

    return 0;


}