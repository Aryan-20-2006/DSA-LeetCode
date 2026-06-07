#include<bits/stdc++.h>
using namespace std;

// void rotateArraybyOne(vector<int> &nums){

//     int n=nums.size();

//     int temp=nums[0]; //only the first element is moving to the last

//     for(int i=1;i<n;i++){

//         nums[i-1]=nums[i];
//     }

//     nums[n-1]=temp;

// }

// int main(){

//     vector<int>nums={1,2,3,4,5};
    
//     rotateArraybyOne(nums); //call the function

//     //print the array
//     for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<" ";
//     }

    
//     return 0;

// }


//if we were to rotate by k places


void rotateArray(vector<int>&nums, int k){

    // int n=nums.size();

    // k=k%n; //no of rotations

    // //Put the first k elements in a temp array

    // int temp[k];

    // for(int i=0;i<k;i++){
    //     temp[i]=nums[i];
    // }

    // //Shifting takes place at the kth index

    // for(int i=k;i<n;i++){

    //     nums[i-k]=nums[i];
    // }

    // //put back temp at n-k position

    // for(int i=n-k;i<n;i++){
    //     nums[i]=temp[i-(n-k)];
    // }
    

    //Optimal soln-not using extra space like temp

    // int n=nums.size();


    // reverse(nums,nums+k);
    // reverse(nums+k,nums+n);
    // reverse(nums, nums+k);



}


int main(){

    int k;

    vector<int>nums={1,2,3,4,5,6,7};


    rotateArray(nums, k);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;

}
