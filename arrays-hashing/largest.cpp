#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& nums){

    int largest=0; //initially largest is 0

    for(int i=1;i<nums.size()-1;i++){  // or from i=0 to nums.size()-1 since by the time you reach the last index , the number is not even there
        if(nums[i]>largest)
            largest=nums[i];
    }

    return largest;
        
}

int main(){

    vector<int>nums={3,3,7,1};
    cout<<largestElement(nums)<< endl;
    return 0;


}