//Sales by match

#include<bits/stdc++.h>
using namespace std;

// int sockMerchant(int n, vector<int> arr){

//     //use an array which stores the count of each sock or hashmap
//     vector<int>freq(101,0); //according to the constraints
//     int count=0;
    

//     for(int i=0;i<n;i++){
//         freq[arr[i]]++;

//         if(freq[arr[i]]%2==0)
//             count++;
//     }

//     return count;

// }

// int main(){

//     int n=7;
//     vector<int>arr={1,2,1,2,1,3,2};
//     cout<<sockMerchant(n,arr)<<"";
//     return 0;


// }

//Counting Valleys
int countingValleys(int steps, string path){

    int altitude=0;
    int valleys=0;

    for(int i=0;i<path.size();i++){
        if(path[i]=='U'){
            altitude+=1;
        }

        else
            altitude-=1;

        if(path[i]=='U' && altitude==0){
            valleys++;
        }

    }

return valleys;

}


int main(){

    string path="DDUU";
    int steps=4;
    cout<<countingValleys(steps,path)<<" ";
    return 0;

}