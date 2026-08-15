//Problem-Single numbers
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>&nums){

int n=nums.size();

unordered_map<int,int>freq;//{number,freq}

for(int i=0;i<n;i++){
    freq[nums[i]]++; //counting freq of each number
}

for(int i=0;i<n;i++){
    if(freq[nums[i]]==1){
        return nums[i];
    }
}

return -1;

}


int main(){
    vector<int>nums={2,2,1};
    cout<<singleNumber(nums)<<" ";
    return 0;
}