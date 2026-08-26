//Problem-Max Consecutive Ones III
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//Brute Force-Generate all subarrays 
//TC-O(n2), SC-O(1)

int longestOnes(vector<int>&nums, int k){

    int maxlen=0;
    
    int n=nums.size();

    for(int i=0;i<n;i++){
        int zeroes=0;

        for(int j=i;j<n;j++){
            if(nums[j]==0){
                zeroes++;
            }

            if(zeroes<=k){
                int len=j-i+1;
                maxlen=max(maxlen,len);
            }

            else{
                break; //if the no of zeroes exceeds k
            }
        }
    }

    return maxlen;


}

//This problem can be understood as Longest Subarray with atmost K zeroes

//Better Solution-TC-O(2N), SC-O(1)
// int longestOnes(vector<int>&nums, int k){

// int l=0;
// int r=0;
// int n=nums.size();
// int maxlen=0;
// int zeroes=0; //keeping a count of zeroes

// while(r<n){
//     if(nums[r]==0){
//         zeroes++;//if you find a 0
//     }

//     //if no of zeroes exceeds k, we will try to trim it from the left
//     while(zeroes>k){
//         if(nums[l]==0){
//             zeroes--;

//         }
//         l++;
//     }

//     //if no of zeroes <=k i.e within the range
//     if(zeroes<=k){
//         int len=r-l+1;
//         maxlen=max(maxlen,len);
//     }

//     r++;
// }

// return maxlen;

// }

//Most Optimal Solution-Removing the inner while loop
//TC-O(N), SC-O(1)

int longestOnes(vector<int>&nums, int k){

    int l=0;
    int r=0;
    int n=nums.size();
    int maxlen=0;
    int zeroes=0;

    while(r<n){
        if(nums[r]==0){
            zeroes++;
        }

        //if zeroes exceeds k
        if(zeroes>k){
            if(nums[l]==0){
                zeroes--;
                
            }

            l++; //move the left pointer regardless or not its a zero
        }

        if(zeroes<=k){
            int len=r-l+1;
            maxlen=max(maxlen,len);
        }

        r++;
    }

return maxlen;


}

int main(){
    vector<int>nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<longestOnes(nums,k)<<" ";
    return 0;
}