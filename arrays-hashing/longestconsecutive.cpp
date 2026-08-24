//Problem-Longest Consecutive Sequence
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>&nums){

int n=nums.size();

if(n==0)
    return 0;

int longest=1;

unordered_set<int>st;

//put all the element of the array into the set
for(int i=0;i<n;i++){
    st.insert(nums[i]);
}

//iterating through the set 
for(auto it:st){
    
    //if I dont find a previous element in the set, then the current element is my starting point
    if(st.find(it-1)==st.end()){
        int cnt=1;
        int x=it; //this is the first element where the sequence would start from

        //In case, you find the next element
        while(st.find(x+1)!=st.end()){
            cnt=cnt+1;
            x=x+1; //going to the next element
        }

        longest=max(longest,cnt);
    }

    
}

return longest;

}

int main(){
    vector<int>nums={1,0,1,2};
    cout<<longestConsecutive(nums)<<" ";
    return 0;
}