//Maximum Average Subarray I
//Difficuly:Easy

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>&nums,int k){

int sum=0;

for(int i=0;i<k;i++){ //first window
    sum+=nums[i];
}

double maxSum=sum;

for(int i=k;i<nums.size();i++){ //nums.size() is the size of the array
    sum+=nums[i];
    sum-=nums[i-k];

    maxSum=max(maxSum,double(sum));


}

return maxSum/k;


}

int main(){

    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;

    cout<<findMaxAverage(nums,k)<<endl;

    return 0;


}