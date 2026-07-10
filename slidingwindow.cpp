#include<bits/stdc++.h>
using namespace std;

//Maximum Average SubArray

// double maxSubarray(vector<int>&nums, int k){

//     int sum=0;
//     int n=nums.size();
    
//     for(int i=0;i<k;i++){
//         sum+=nums[i];
//     }

//     double maxSum=sum;

//     for(int i=k;i<n;i++){
//         sum+=nums[i];
//         sum-=nums[i-k];

//         maxSum=max(maxSum,(double)sum);
//     }

// return maxSum/k;


// }

// int main(){
//     vector<int>nums={1,12,-5,-6,50,3};
//     int k=4;
//     cout<<maxSubarray(nums,k)<<"";
//     return 0;

// }

//SubArray Sum equals k

// int maxSubarray(vector<int>&nums, int k){


//     unordered_map<int,int>map;

//     map[0]=1;

//     int sum=0;
//     int count=0;
//     int n=nums.size();

//     for(int i=0;i<n;i++){
//         sum+=nums[i];
//         count+=map[sum-k];

//         map[sum]++;
//     }

// return count;

// }

int longestSubarray(vector<int>&nums, int k){

    int n=nums.size();

    int maxlen=0;
    int sum=0;
    int i=0;

    for(int j=0;j<n;j++){
        sum+=nums[j];

        //if the sum exceeds the sum k,shrink the window
        while(sum>k){
            sum-=nums[i];
            i++;
        }

        if(sum==k){
            int length=j-i+1;
            maxlen=max(maxlen,length);
        }

    }

return maxlen;

}

int main(){
    vector<int>nums={1,2,3,1,1,1,1,3,3};
    int k=6;
    cout<<longestSubarray(nums,k)<<" ";
    return 0;
}