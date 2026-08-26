//Problem-Kth largest element in an array

#include<bits/stdc++.h>
using namespace std;

// //Brute Force
// int kthLargestElement(vector<int>&nums, int k){

// int n=nums.size();

// sort(nums.begin(),nums.end()); //TC=O(nlogn)

// return nums[n-k]; //the kth largest element is the (n-k)th element from the front

// }

//Correct Brute Force-TC-O(k)+O(n-k)(logk), SC-O(1)
int kthLargestElement(vector<int>&nums, int k){

    //Create the min heap
    priority_queue<int,vector<int>,greater<int>>pq;

    //Step 1:Build the min heap of the first k elements
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }

    //Step 2:Push the remaining elements,one at a time
    for(int i=k;k<nums.size();i++){
        //check if a larger element is found
        if(nums[i]>pq.top()){

            //remove the smallest and insert the new element
            pq.pop();

            pq.push(nums[i]);
        }
    }

    //the kth largest element would be the root of the the min heap
    return pq.top();

}



int main(){
    vector<int>nums={-5,4,1,2,-3};
    int k=5;

    cout<<kthLargestElement(nums,k)<<" ";
    return 0;
}

