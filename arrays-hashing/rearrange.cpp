//Problem-Rearrange Elements by Sign
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Brute Force-TC-O(N)(to assign +ve and -ve elements)+O(N/2)(to reassign them back to the array), SC-O(n/2)+O(n/2)
vector<int>rearrangeArray(vector<int>&nums){

    vector<int>pos; //storing the positive elements
    vector<int>neg; //storing the negative elements
    int n=nums.size();

    //traverse the array and put the positive and negative elements
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            neg.push_back(nums[i]);
        }

        else{
            pos.push_back(nums[i]);
        }

    }

    //since n is even , there will be n/2 positive elements and n/2 negative elements
    //Observation-Positive numbers are at even indices and Negative numbers are at odd indices

    for(int i=0;i<n/2;i++){
        nums[2*i]=pos[i];
        nums[2*i+1]=neg[i];
    }

    

    return nums;


}

//Optimal Approach-TC-O(N),SC-O(N)-Needs to be optimized further
// vector<int>rearrangeArray(vector<int>&nums){

//     int n=nums.size();
//     vector<int>ans(n,0);

//     int posInd=0;
//     int negInd=1;

//     for(int i=0;i<n;i++){
//         if(nums[i]<0){
//             ans[negInd]=nums[i];
//             negInd+=2;
//         }

//         else{
//             ans[posInd]=nums[i];
//             posInd+=2;
//         }
//     }

//     return ans;

// }



//What if its something like Eg:-[1,2,-4,-5,3,6], here the no of +ves>no of -ves so final arr [1,-4,2,-5,3,6]
// vector<int>rearrangeArray(vector<int>&nums){


//     vector<int>pos;
//     vector<int>neg;
//    int n=nums.size();

//    for(int i=0;i<n;i++){
//     if(nums[i]>0){
//         pos.push_back(nums[i]);
//     }

//     else{
//         neg.push_back(nums[i]);
//     }
//    }


//    //Since I know negatives is less than positives i.e pos!=neg


// if(pos.size()>neg.size()){
//    for(int i=0;i<neg.size();i++){ //since there are 2 negatives here

//         //this works only if no of +ves==no of -ves;
//         nums[i*2]=pos[i];
//         nums[i*2+1]=neg[i];
//    }

   
//    //There would remaining postive elements
//    int ind=neg.size()*2;    
//    for(int i=neg.size();i<n;i++){
//         nums[ind]=pos[i];
//         ind++;
//    }

// }

//    //if no of neg>no of pos
//    else{
//       for(int i=0;i<neg.size();i++){ //since there are 2 negatives here
//         //this works only if no of +ves==no of -ves;
//         nums[i*2]=pos[i];
//         nums[i*2+1]=neg[i];
//     }

//    //There would remaining negative elements
//    int ind=pos.size()*2;    
//    for(int i=pos.size();i<n;i++){
//         nums[ind]=neg[i];
//         ind++;
//    }

// }

// return nums;


// }


int main(){

    vector<int>nums={3,1,-2,-5,2,-4};
    rearrangeArray(nums);

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    
return 0;

}