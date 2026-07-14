//Problem-Permutations
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//First Approach

// void findPermutations(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int freq[]){

//     //Base case
//     if(ds.size()==nums.size()){
//         ans.push_back(ds);
//         return;
//     }

//     for(int i=0;i<nums.size();i++){
//         if(!freq[i]){ //if the element we're about to add isnt there in the map currently
//             ds.push_back(nums[i]);
//             freq[i]=1; //mark that as taken
//             findPermutations(nums,ds,ans,freq);
//             freq[i]=0;
//             ds.pop_back();
//         }
//     }

// }

// vector<vector<int>>permute(vector<int>&nums){

//     vector<vector<int>>ans;
//     vector<int>ds;
//     int freq[nums.size()];

//     for(int i=0;i<nums.size();i++){
//         findPermutations(nums,ds,ans,freq);
//     }
//     return ans;

// }

//Second Approach-Swapping each index

void combinations(int ind, vector<int>&nums, vector<vector<int>>&ans){

    //base case
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        combinations(ind+1,nums,ans);
        swap(nums[ind],nums[i]); //once you're coming back(backtracking), reswap it

    }

}

vector<vector<int>>Permute(vector<int>&nums){
    vector<vector<int>>ans;
    combinations(0,nums,ans);
    return ans;
}















