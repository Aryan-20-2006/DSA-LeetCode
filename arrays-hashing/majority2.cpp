#include<bits/stdc++.h>
using namespace std;

 vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();

        unordered_map<int,int>freq;

        vector<int>result;

    

        for(int i=0;i<n;i++){
            freq[nums[i]]++;

            if(freq[nums[i]]==n/3+1)
                result.push_back(nums[i]);
        }


        return result;
}

int main(){
    vector<int>nums={2,2};
    vector<int>result=majorityElement(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}