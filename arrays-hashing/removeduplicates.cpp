//Problem-Remove duplicates from sorted array
//Difficulty-Easy

//Since we need unique elements, we can use a set data structure

#include<bits/stdc++.h>
using namespace std;


int removeDuplicates(vector<int> &nums){

    //if array is empty, return 0
    if(nums.empty())
        return 0;

    int i=0; //pointer of the position of the last unique element

    for(int j=1;j<nums.size();j++){
        if(nums[j]!=nums[i]) //no duplicate elements
            i++; //update and move forward
            nums[i]=nums[j]; //at that positon, place the unique element

    }

    return i+1;

}


   
int main(){

    vector<int>nums={0,0,3,3,5,6};
    cout<<removeDuplicates(nums)<<endl;
    return 0;

}