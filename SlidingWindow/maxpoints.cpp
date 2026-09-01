//Problem-Maximum Points you can obtain from cards
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//Brute Force
// int maxScore(vector<int>&cardPoints, int k){

// int n=cardPoints.size();
// int leftsum=0;
// int rightsum=0;

// //try to find the max of left and rightsum

// //LeftSum
// for(int i=0;i<k;i++){
//     leftsum+=cardPoints[i];
// }

// //RightSum-this is work if my array length is odd

// //if my array is of odd length
// if(n%2!=0){
//     for(int i=n-1;i>k;i--){
//         rightsum+=cardPoints[i];
//     }

// }

// //if my array is of even length
// if(n%2==0){
//     for(int i=n-1;i>k+1;i--){
//         rightsum+=cardPoints[i];
//     }
// }


// return max(leftsum,rightsum);


// }


//Optimal Solution-TC-O(2k),SC-O(1)
int maxScore(vector<int>&cardPoints, int k){
    int lsum=0,rsum=0,maxSum=0;

    //initally adding elements on the left
    for(int i=0;i<k;i++){
        lsum+=cardPoints[i];
        maxSum=lsum; //assuming I have picked up all the elements from the left, so this would be my maxSum
    }

    //shrink the window-as you're removing elements from the left , add it from the right at the end
    int n=cardPoints.size();
    int rindex=n-1;
    for(int i=k-1;i>=0;i--){
        lsum=lsum-cardPoints[i];
        rsum=rsum+cardPoints[rindex];
        rindex--; //at the same time while adding from the end ,make sure to decrement the right index
        maxSum=max(maxSum,lsum+rsum);
    }

   
    return maxSum;
}

int main(){
    vector<int>cardPoints={100,40,17,9,73,75};
    int k=3;
    cout<<maxScore(cardPoints,k)<<" ";
    return 0;
}

