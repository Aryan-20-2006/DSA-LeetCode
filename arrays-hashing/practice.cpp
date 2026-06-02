/*Two Sum-Easy

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>&nums, int target){

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }

return {};

}

int main(){
    vector<int>nums={2,7,11,15};
    int target=9;

    vector<int>result=twoSum(nums, target);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }



return 0;

}
*/

/*Contains Duplicate*/

#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums){

sort(nums.begin(),nums.end());

    for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                return true;
    }


return false;

}

int main(){

    vector<int>nums={1,2,3,1};
    cout<<containsDuplicate(nums)<<endl;
    return 0;


}

