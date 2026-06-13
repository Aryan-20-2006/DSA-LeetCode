//Problem-Container with the most water
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){

    int n=height.size();

    int i=0; //left pointer
    int j=n-1; //right pointer
    int maxArea=0;


    while(i<j){
        int width=j-i;//distance between the pointers
        int h=min(height[i],height[j]);
        int area=h*width;

        if(area>maxArea)
            maxArea=area;

        if(height[i]<height[j])
            i++;
        else
            j--;
    
    }

    return maxArea;

}

int main(){

    vector<int>height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<" ";
    return 0;

}