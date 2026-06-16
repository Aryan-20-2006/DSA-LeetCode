//Problem-Longest SubArray with Sum K(positive elements)
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// int longestSubArray(vector<int>&arr, int k){

//     //k is the target k
//     int i=0;
//     int maxlength=0; //cant use INT_MIN since length of longest subbaray cant be negative
//     int sum=0;
//     int n=arr.size();

//     for(int j=0;j<n;j++){
//         sum+=arr[j];

//         while(sum>k){
            
//             sum-=arr[i]; //shrink the window if the sum is too large
//             i++; //move the left pointer
//         }

//         //only when the sum is equal to target, update the maxlength
//         if(sum==k){
//             int length=j-i+1;
//             maxlength=max(maxlength,length);
//         }

//     }


//     return maxlength;

// }


//Better solution-using the concept of prefix sum-handles both positive and negative elements

int longestSubArray(vector<int>&nums, int k){

    map<int,int>preSumMap;
    int sum=0;
    int maxlen=0;
    int n=nums.size();

    for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum==k){
            maxlen=max(maxlen,i+1);
        }

        int rem=sum-k;

        if(preSumMap.find(rem)!=preSumMap.end()){ //if you find it
            int len=i-preSumMap[rem];
            maxlen=max(maxlen,len);
        }

        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }


    }

    return maxlen;

}

int main(){

    int k=15;
    vector<int>arr={10,5,2,7,1,-10};
    cout<<longestSubArray(arr,k)<<" ";
    return 0;



}