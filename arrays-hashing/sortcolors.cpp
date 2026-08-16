//Problem-Sort Colors
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

// void sortColors(vector<int>&nums){

//     int n=nums.size();
    
//     int cnt0=0,cnt1=0,cnt2=0;

//     //first write 0's,1's and then 2's
//     for(int i=0;i<n;i++){
//         if(nums[i]==0){
//             cnt0++;
//         }

//         else if(nums[i]==1){
//             cnt1++;
//         }

//         else{
//             cnt2++;
//         }
//     }

//     //fill with zeroes
//     for(int i=0;i<cnt0;i++){
//         nums[i]=0;
//     }
//     //fill with ones
//     for(int i=cnt0;i<cnt0+cnt1;i++){
//         nums[i]=1;
//     }
//     //fill the remaining element with twos
//     for(int i=cnt0+cnt1;i<n;i++){
//         nums[i]=2;
//     }


//     //TC-O(4N) SC=O(1)

// }

//Optimal approach
void sortColors(vector<int>&nums){
    int low=0;
    int mid=0;
    int n=nums.size();
    int high=n-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }

        //this means its at the right place 
        else if(nums[mid]==1){
            mid++;
        }

        //if nums[mid]==2, it has to go the right half
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main(){

    vector<int>nums={2,0,2,1,1,0};
    sortColors(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
    

}