//Problem-Subsets 2
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void findSubsets(int ind,vector<int>&nums,vector<int>&ds, vector<vector<int>>anslist){

    anslist.push_back(ds); //we're pushing back and increasing the list size
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]){ //if you find duplicates, skip it
            continue;
        } 

        ds.push_back(nums[i]); 
        findSubsets(i+1,nums,ds,anslist);
        ds.pop_back(); //used to remove the last element so we dont end up with duplicates again

        
    }
}

vector<vector<int>> subsetswithDupli(vector<int>&nums){

    sort(nums.begin(),nums.end());
    vector<int>ds;
    vector<vector<int>>anslist;
    findSubsets(0,nums,ds,anslist);
    return anslist;

}

