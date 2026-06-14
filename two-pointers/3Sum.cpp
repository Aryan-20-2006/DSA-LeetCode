//Problem-3 Sum
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>threeSum(vector<int>&nums){

    //Brute Force method

    // set<vector<int>>st;

    // for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         for(int k=j+1;k<nums.size();k++){
    //             if(nums[i]+nums[j]+nums[k]==0){
    //                 vector<int>result={nums[i],nums[j],nums[k]};
    //                 sort(result.begin(),result.end()); //since the elements in each of the triplets are sorted
    //                 st.insert(result);
                
    //             }
    //         }
    //     }

    // }

    // //convert set to vector
    // vector<vector<int>>ans(st.begin(),st.end());
    // return ans;

    //Optimal solution-First sort the array
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue; //go back to doing i++
        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }

            else if(sum>0){
                k--;
            }

            //otherwise we have the triplet
            else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;

                //when you are moving j and the next element is same as previous, ingore and keep moving j
                while(j<k && nums[j]==nums[j-1]){
                    j++;
                }

                while(j<k && nums[k]==nums[k+1]){
                    k--;
                }
            }

        }

    }

    return ans;

}

int main(){

vector<int> nums = {2,-2,0,3,-3,5};

vector<vector<int>> result = threeSum(nums);

for(int i = 0; i < result.size(); i++)
{
    for(int j = 0; j < result[i].size(); j++)
    {
        cout << result[i][j] << " ";
    }

    cout << endl;
}

}

