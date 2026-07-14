//Problem-Climbing stairs
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Assuming n to be the index here

// int climbStairs(int n){

//     if(n==0 || n==1)
//         return 1;

//     int left=climbStairs(n-1);
//     int right=climbStairs(n-2);
    
//     return left+right;

// }


//Better way to write this
int climbStairs(int n){

    if(n==0 || n==1)
        return 1;

    int prev2=1;
    int prev=2;

    for(int i=3;i<=n;i++){
        int curi=prev+prev2;
        prev2=prev;
        prev=curi;
    }

return prev;
}


int main(){

    int n;
    cin>>n;
    cout<<climbStairs(n)<<" ";
    return 0;
}
