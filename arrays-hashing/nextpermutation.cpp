//Problem-Next Permutation
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//TC-O(3N) in the worst case , SC-O(1) not using an extra data structure
void nextPermutation(vector<int>&nums){

   //edge case-if there is no dip moving from the right, then reverse the array to find the largest lexicographic order

   int ind=-1;
   

   int n=nums.size();

   //1.Find the dip (the last place you can find a dip is at n-2),the dip is possible when nums[i]<nums[i+1]
   for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            ind=i ;//store the index where the dip is happening 
            break;
        }
   }

    //edge case-if there is no dip moving from the right, then reverse the array to find the largest lexicographic order
    //Note-Check this only if you dont find a dip dont check it at the start
    if(ind==-1){
        reverse(nums.begin(),nums.end());
   }


   //2. Find someone greater than that number, but look for the smallest one (from the right)
   for(int i=n-1;i>ind;i--){
        if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;
        }
   }

   //since we have the next greater number after swapping, what about the remaining elements. We want it to be as small as possible. So we reverse from ind+1 up to the end of the array
   reverse(nums.begin() + ind+1,nums.end());

}

int main(){

    vector<int>nums={2,1,5,4,3,0,0};
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;


}