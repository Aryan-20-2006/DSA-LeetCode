//Problem-Check if an array represents a min heap


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

// void insert(int x){
//     if(size==capacity){
//         cout<<"Binary Heap Overflow"<<endl;
//         return;
//     }

//     nums[size]=x; //inserting element at the end

//     int k=size;

//     size++;

//     while(k!=0 && nums[parent(k)]>nums[k]){
//         swap(nums[parent(k)],nums[k]);
//         k=parent(k);
//     }
// }

// void Heapify(int ind){
//     int ri=right(ind);

//     int li=left(ind);

//     int smallest=ind;

//     if(li<size && nums[li]<nums[smallest])
//         smallest=li;

//     if(ri<size && nums[ri]<nums[smallest])
//         smallest=ri;

//     if(smallest!=ind){
//         swap(nums[ind],nums[smallest]);
//         Heapify(smallest);
//     }

    
// }

bool isHeap(vector<int>&nums){

    int n=nums.size();

    for(int i=0;i<n;i++){
        int li=left(i);
        int ri=right(i);

        int smallest=i;

        if(li<n && nums[li]<nums[smallest])
            return false;

        if(ri<n && nums[ri]<nums[smallest])
            return false;

        
    }

return true;

}

int main(){
    vector<int>nums={10,20,30,25,15};
    cout<<isHeap(nums)<<" ";
    return 0;
}





