#include<bits/stdc++.h>
using namespace std;

//Printing subsequences whose sum is k
// void subs(int ind,vector<int>&ds, int s,int sum,vector<int>&arr, int n){

//     //here sum is the target sum that wont change

//     if(ind==n){
//         if(s==sum){
//             for(int i=0;i<ds.size();i++){
//                 cout<<ds[i]<<" "; //printing the data structure
//             }
//         }

//         return;
//     }

//     ds.push_back(arr[ind]);

//     subs(ind+1,ds,s+arr[ind],sum,arr,n); //picking
//     ds.pop_back();

//     //not picking
//     subs(ind+1,ds,s,sum,arr,n);
    
// }

// int main(){

//     vector<int>arr={1,2,1};
//     int n=3;
//     int sum=2;
//     vector<int>ds;

//     subs(0,ds,0,sum,arr,n);

//     return 0;
// }


//Count subsequences with sum equals to k
int count(int ind,vector<int>&ds,int s,int sum, vector<int>&arr, int n){


    //condition not satisfied, if array has only positives only
    if(s>sum)
        return 0;


    //base case
    if(ind==n){
        if(s==sum){
            return 1;
        }

        else{
            return 0;
        }
    }

    ds.push_back(arr[ind]);

    int left=count(ind, ds, s+arr[ind], sum, arr, n );

    ds.pop_back();

    int right=count(ind,ds,s,sum,arr,n);

    return left+right;

}