//Problem-Count number of nice subarrays
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Converting this problem to binary subarrays/
/*
Convert the odd odd numbers to 1 
Convert the odd even numbers to 0

then its finding subarrays with sum==k

*/

//TC-O(2*2*N) , SC-O(1)
int sumlesserthank(vector<int>&nums, int k){

    //converting all odd odd numbers to 1
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2!=0){
            nums[i]=1;
        }

        //all even numbers to zero
        else{
            nums[i]=0;
        }
    }

    if(k<0)
        return 0;

    int l=0;
    int r=0;
    int n=nums.size();
    int cnt=0;
    int sum=0;

    while(r<n){

        sum+=nums[r];

        while(sum>k){
            sum-=nums[l];
            l++;
        }

        cnt+=(r-l+1);
        r++;
    }

    
return cnt;

}


int numberOfSubarrays(vector<int>&nums, int k){

    return sumlesserthank(nums,k)-sumlesserthank(nums,k-1); //this returns the count of subarrays with sum equal to k
    
}

int main(){
    vector<int>nums={2,2,2,1,2,2,1,2,2,2};
    int k=2;
    cout<<numberOfSubarrays(nums,k);
    
    return 0;

}