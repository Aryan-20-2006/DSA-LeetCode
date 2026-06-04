//return the second largest element, if it doesnt exist, return -1

#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int>&nums){

    int largest=nums[0];
    int slargest=-1; //will be replaced later

    for(int i=1;i<nums.size();i++){ 
        if(nums[i]>largest){
            slargest=largest;
            largest=nums[i];
        } 

        else if(nums[i]<largest && nums[i]>slargest)
            slargest=nums[i];
    }

    return slargest;

}


int main(){

    vector<int>nums={7,7,2,2,10,10,10};
    cout<<secondLargestElement(nums)<<endl;
    return 0;

}
