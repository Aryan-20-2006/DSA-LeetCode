//Problem-Combination Sum
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

void findCombinationSum(int ind, vector<int>&arr,int target, vector<vector<int>>&anslist, vector<int>&ds){

    if(ind==arr.size()){
        if(target==0){ //this means we found a possible combination sum
            anslist.push_back(ds);
        }

        return;
    }

    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findCombinationSum(ind,arr,target-arr[ind],anslist,ds); //if we are picking
        ds.pop_back();
    }

    //not picking the current index, move to the next index
    findCombinationSum(ind+1,arr,target,anslist,ds);

}

vector<vector<int>>combinationSum(vector<int>&candidates, int target){

    vector<int>ds;
    vector<vector<int>>anslist;
    findCombinationSum(0,candidates,target,anslist,ds);
    return anslist;
}



