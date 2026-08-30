//Problem-Binary Subarrays with Sum
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC-O(N2), SC-O(1)
// int numSubarrayWithSum(vector<int>&nums, int goal){

//     int n=nums.size();
//     int sum=0;
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             sum+=nums[j];

//             if(sum>goal){
//                 sum-=nums[i];
//             }

//             if(sum==goal){
//                 cnt++;
//             }
//         }
//     }

//     return cnt;
// }

//Optimal Solution-We will find all the subarrays where sum<=goal first
int sumlesserthangoal(vector<int>&nums, int goal){


    int l=0;
    int r=0;
    int n=nums.size();
    int sum=0;
    int cnt=0;

    //this check is important 
    if(goal<0)
        return 0;

    while(r<n){
        sum+=nums[r];

        while(sum>goal){
            sum-=nums[l];
            l++;
        }

        cnt+=(r-l+1); //this finds all the valid subarrays of that segment
        r++;
    }

    return cnt;
}

int numSubarrayWithSum(vector<int>&nums,int goal){
    return sumlesserthangoal(nums,goal)-sumlesserthangoal(nums,goal-1); //this gives the subarrays with sum==goal
}



int main(){

    vector<int>nums={0,0,0,0,0};
    int goal=0;
    cout<<numSubarrayWithSum(nums,goal)<<" ";
    return 0;

}