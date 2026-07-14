//Problem-Subsets I
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum,vector<int>&nums,int n,vector<int>&subset){

    //base case
    if(ind==n){
        subset.push_back(sum);
        return;
    }

    //If the element is taken
    func(ind+1,sum+nums[ind],nums,n,subset);

    //If the element is not taken
    func(ind+1,sum,nums,n,subset);

}

vector<int> subsetSums(vector<int>&nums, int n){

    vector<int>subset;
    func(0,0,nums,n,subset); //it goes to that func and index==n so we have our subset
    sort(subset.begin(),subset.end());
    return subset;
}

int main(){


    vector<int>nums={3,1,2};
    int n=nums.size();
    vector<int>subset=subsetSums(nums,n);
    

    for(int i=0;i<subset.size();i++){
        cout<<subset[i]<<" ";
    }

    return 0;

}