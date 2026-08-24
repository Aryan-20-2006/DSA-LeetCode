#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&nums){

int n=nums.size();
vector<int>freq(n+1,0);

//counting freq
for(int i=0;i<n;i++){
    freq[nums[i]]++;
}

//finding the missing number
for(int i=0;i<=n;i++){
    if(freq[i]==0){
        return i;
    }
}

return -1;

}

int main(){
    vector<int>nums={0,1,2,4,5,6};
    cout<<missingNumber(nums)<<" ";
    return 0;
}