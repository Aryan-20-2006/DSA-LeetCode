//Problem:Max Average SubArray I
//Difficulty:Easy

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>&nums,int k){

double sum=0;

//first build the window
for(int i=0;i<k;i++){
    sum+=nums[i];
}

double maxSum=sum; //since the output is in decimal

//slide the window
for(int i=k;i<nums.size();i++){
    sum+=nums[i];//adding the incoming element
    sum-=nums[i-k]; //remove the outgoing element

    maxSum=max(maxSum,sum);
  
}

return maxSum/k;

    
}

int main(){


int k=4;
vector<int>nums={1,12,-5,-6,50,3};
cout<<findMaxAverage(nums,k)<<endl;
return 0;


}
