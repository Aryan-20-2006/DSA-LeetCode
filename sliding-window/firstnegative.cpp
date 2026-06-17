//Problem-First negative in every window of size k
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//k is the window size

vector<int> firstNegInt(vector<int>&arr, int k){
    
   vector<int>result;
   queue<int>q; 

   int n=arr.size();

   //traverse the array
   for(int i=0;i<n;i++){
        if(arr[i]<0) //add the incoming negative elements
        {
            q.push(arr[i]);
        }

        //check if a window is complete
        if(i>=k-1){
            if(q.empty()){
                result.push_back(0);
            }

            else{
                result.push_back(q.front());
            }
        

            if(!q.empty() && arr[i-k+1]==q.front()){ //if the outgoing element is the same as q.front()
                q.pop();
            }  
    }

}   

return result;

}

int main(){

    int k=2;
    vector<int>arr={-8,2,3,-6,10};
    vector<int>result=firstNegInt(arr,k);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;


}