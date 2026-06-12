//Problem-Merge Sorted Array(without using extra space)
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;


//m is the size of nums1 and n is the size of nums2

//This approach is without using extra space
// void merge(vector<int>& nums1, int m, vector<int>&nums2, int n){

//     //take two pointers-left and right
//     int left=m-1;//last place of the first array
//     int right=0;//starts at the first place of the second array

//     while(left>=0 && right<n){
//         if(nums1[left]>nums2[right]){
//             swap(nums1[left],nums2[right]);
//             left--;
//             right++;
//         }

//         else{
//             break;//if the order is fine do nothing
//         }
//     }

//     sort(nums1.begin(),nums1.end()); //sort(nums1,nums1+m)
//     sort(nums2.begin(),nums2.end()); //sort(nums1,nums2+n)

// }

void merge(vector<int>& nums1, int m, vector<int>&nums2, int n){

    int p1=m-1;//inidcates where the first array ends
    int p2=n-1;
    int i=m+n-1;//index at which we're going to write

    while(p2>=0){
        if(p1>=0 && nums1[p1]>nums2[p2]){
            nums1[i]=nums1[p1];
            i--;
            p1--;
        }
        else{
            nums1[i]=nums2[p2];
            i--;
            p2--;
        }
    }
}

int main(){

    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,5,6};

    int m=3; //valid elements in nums1
    int n=3; //valid elements in nums2
    
    merge(nums1,m,nums2,n);
    
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<" ";
    }

    return 0;

}

