//Problem-Subarrays with k different integers
//Difficulty

//This problem is similar to count nice subarrays

#include<bits/stdc++.h>
using namespace std;

//Brute Force-TC-O(N2),SC-O(1)
// int subarrayswithkdistinct(vector<int>&nums, int k){

//     int n=nums.size();

//     int cnt=0;

//     for(int i=0;i<n;i++){
//         unordered_map<int,int>map; //this needs to be udpated so put this inside the loop
//         for(int j=i;j<n;j++){
//             map[nums[j]]++;

//             if(map.size()==k){
//                 cnt++;
//             }

//             if(map.size()>k)
//                 break;
//         }
//     }

// return cnt;


// }

//Optimal Solution-We will find the number of subarrays lesser than equal to k and then for k-1
//This is for <=k

//TC-O(2N),SC-(O(1))
int subarrayswithlesserthank(vector<int>&nums, int k){

int l=0;
int r=0;
int n=nums.size();

int cnt=0;

unordered_map<int,int>map;

while(r<n){
    map[nums[r]]++;

    while(map.size()>k){

        map[nums[l]]--;
        if(map[nums[l]]==0){
            map.erase(nums[l]);
        }
        l=l+1;
    }

    //if the no of different integers is lesser than equal to k
    cnt+=r-l+1;
    r++;
}

return cnt;
}

//To find subarrays with k distinct, then I need (<=k) and (<=k-1)
int subarrayswithkdistinct(vector<int>&nums,int k){

    return subarrayswithlesserthank(nums,k)-subarrayswithlesserthank(nums,k-1);
}

int main(){
    vector<int>nums={1,2,1,2,3};
    int k=2;
    cout<<subarrayswithkdistinct(nums,k)<<" ";
    return 0;
}