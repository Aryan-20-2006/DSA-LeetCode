#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>&nums){

int n=nums.size();

//better to use an unordered map, otherwise it would go out of bounds
unordered_map<int,int>freq;

for(int i=0;i<n;i++){
    freq[nums[i]]++;

    if(freq[nums[i]]>floor(n/2))
        return nums[i];
}

return 0;


}

int main(){

vector<int>nums={2,2,1,1,1,2,2};
cout<<majorityElement(nums)<<" ";
return 0;


}