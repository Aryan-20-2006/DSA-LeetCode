//Problem-Aggressive Cows
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

bool canwePlace(vector<int>&nums,int distance,int k){

    int countcows=1;
    int last=nums[0];
    int n=nums.size();

    for(int i=1;i<n;i++){
        if(nums[i]-last>=distance){
            countcows++;
            last=nums[i];
        }

        
    if(countcows>=k){
        return true;
    }
}

return false;

}

//k refers to the number of cows
int aggressiveCows(vector<int>&nums, int k){

    sort(nums.begin(),nums.end());
    int low=0;
    int n=nums.size();
    int high=nums[n-1]-nums[0]; //max-min

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canwePlace(nums,mid,k)==true){
            low=mid+1;
        }

        else{
            high=mid-1;
        }


    }

return high;

}

int main(){

    vector<int>nums={0,3,4,7,10,9};
    int k=4;
    cout<<aggressiveCows(nums,k)<<" ";
    return 0;

}