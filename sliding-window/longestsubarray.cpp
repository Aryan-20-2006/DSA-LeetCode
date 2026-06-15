//Problem-Longest SubArray with Sum K(positive elements)
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>&arr, int k){

    //k is the target k
    int i=0;
    int maxlength=0; //cant use INT_MIN since length of longest subbaray cant be negative
    int sum=0;
    int n=arr.size();

    for(int j=0;j<n;j++){
        sum+=arr[j];

        while(sum>k){
            
            sum-=arr[i]; //shrink the window if the sum is too large
            i++; //move the left pointer
        }

        //only when the sum is equal to target, update the maxlength
        if(sum==k){
            int length=j-i+1;
            maxlength=max(maxlength,length);
        }

    }


    return maxlength;

}

int main(){

    int k=3;
    vector<int>arr={1,2,1,1,1};
    cout<<longestSubarray(arr,k)<<" ";
    return 0;



}