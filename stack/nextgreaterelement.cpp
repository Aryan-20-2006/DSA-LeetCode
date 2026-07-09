//Problem-Next Greater Element
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>&arr){


    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){ //if the topmost element and all the other elements in stacks are smaller than the current element
            st.pop();
        }
            if(st.empty()){
                ans[i]=-1;
            }

            else{
                ans[i]=st.top();
            }

        st.push(arr[i]);

        } 

    return ans;

}



int main(){

    vector<int>arr={1,3,2,4};
    vector<int>ans=nextLargerElement(arr);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}