//Problem-Minimum Size SubArray Sum
//Difficuly-Medium

#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>&nums){

    int i=0;
    int minlength=INT_MAX; //will be updated later
    int sum=0;
    int n=nums.size();

    for(int j=i;j<n;j++){
        sum+=nums[j]; //add elements on the right and increase window size

        while(sum>=target){

            int length=j-i+1;
            minlength=min(minlength,length); //update minlength
            sum-=nums[i]; //remove elements from the left and shrink window
            i++; //move the left pointer as you shrink
    
        }
    }

    //if the minlengtt never gets updated
    if(minlength==INT_MAX)
        return 0;

    return minlength;

}

int main(){

    int target=7;
    vector<int>nums={2,3,1,2,4,3};
    cout<<minSubArrayLen(target,nums)<<" ";
    return 0;

}