//Problem-Maximum Average Subarray I
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>&nums, int k){


    
    int i=0;
    int sum=0;
    int n=nums.size();

    //k is the window size-so you will add elements upto the window size only

    //first window
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }

    //since we're finding maxAverage, we'll declare a maxSum(in decimals)

    double maxSum=sum;

    for(int i=k;i<n;i++){
        sum+=nums[i]; //add the next element
        sum-=nums[i-k]; //subtract element at the start

        //update maxSum
        maxSum=max(maxSum,double(sum)); //since I have taken double maxSum, so even sum should be double
    }


    return maxSum/k;


}

int main(){

    int k=4;
    vector<int>nums={1,12,-5,-6,50,3};
    cout<<findMaxAverage(nums,k)<<"";
    return 0;



}