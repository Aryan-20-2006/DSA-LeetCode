//Problem-Move Zeroes
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){

    int n=nums.size();


    
    //Finding the first zero element
    int j=-1; //initially nothing is there in j. We dont know where the first zero is

    for(int i=0;i<n;i++){
        if(nums[i]==0){
            j=i; //store this index
        }
        break; //otherwise it goes out if j=-1
    }

    //if the array only has non zero elements-base case

    if(j==-1)
        return; 


    //Finding the non-zero element
    for(int i=j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i], nums[j]); //j is always at zero so when i is at place where its non zero , swap
            j++; //after swapping update j since i keeps moving forward 
    }

}

}

int main(){

    vector<int>nums={0,1,4,0,5,2};

    moveZeroes(nums);

    for(int i=0;i<nums.size();i++){
        cout<< nums[i] << " ";
    }


    return 0;
    
}