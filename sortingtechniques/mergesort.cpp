#include<bits/stdc++.h>
using namespace std;


vector<int> merge(vector<int>&nums, int low, int mid, int high){

    vector<int>temp;
    int left=low; //left half starts from here
    int right=mid+1;

    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }

        else{
            temp.push_back(nums[right]);
            right++;
        }
    }

    //if either half has remaining element
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right<high){
        temp.push_back(nums[right]);
        right++;
    }

    //Finally the merged array is from low to high
    for(int i=low;low<high;low){
        nums[i]=temp[i-low];
    }

return nums;

}

void mergeSort(vector<int>&nums,int low, int high){

int n=nums.size();
int low=0;
int high=n-1;

int mid=(low+high)/2;

if(low==high){
    return;
}

//call the left and right half recursively 
mergeSort(nums,low,mid); //left half
mergeSort(nums,mid+1,high); //right half
                            //need to merge it back




}







vector<int> mergeSort(vector<int>&nums){




}