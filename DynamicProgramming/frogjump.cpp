//Problem-Frog Jump
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


int frogJump(vector<int>&heights){

    if(heights.empty())
        return 0;

    int n=heights.size();

    int prev=0;
    int prev2=0;

    for(int i=1;i<n;i++){
        int left=prev+abs(heights[i]-heights[i-1]);

        int right=INT_MAX;

        right=prev2+abs(heights[i]-heights[i-2]);

        int curr=min(left,right);

        prev2=prev;
        prev=curr;
    }

    return prev;
}

