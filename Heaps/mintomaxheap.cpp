//Problem-Converting Min Heap to Max Heap

#include<bits/stdc++.h>
using namespace std;

int parent(int i){

return (i-1)/2;

}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

vector<int> minToMaxHeap(vector<int>&nums){

int n=nums.size();

//starting from the last non-leaf node
for(int i=n/2-1;i>=0;i--){

    int ind=i;

while(true){
    int li=left(ind);

    int ri=right(ind);

    int largest=ind;

    if(li<n && nums[li]>nums[largest]){
        largest=li;
    }

    if(ri<n && nums[ri]>nums[largest]){
       largest=ri;
    }

    //otherwise swap if your child node is greater than the parent node

    if(largest==ind){
        break; //this means the operations were done properly
    }

    //otherwise swap until the parent node becomes largest
    swap(nums[ind],nums[largest]);
    ind=largest;

}



}


return nums;

}

int main(){

    vector<int>nums={10,20,30,21,23};
    vector<int>result=minToMaxHeap(nums);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;


}