//Problem-Fruits into baskets
//Diffculty-Medium

#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC-O(2N),SC-O(1)
// int totalFruit(vector<int>&fruits){

//     int n=fruits.size();

//     unordered_map<int,int>map;

//     int left=0;
//     int right=0;
//     int maxlen=0;

//     while(right<n){

//         map[fruits[right]]++; //increases the freq of fruit of each type

//         if(map.size()>2){ //if the no of distinct fruits exceeds 2, then shrink the window
//             while(map.size()>2){
//                 //remove outgoing element
//                 map[fruits[left]]--;

//                 //if at any point the freq becomes zero, remove it from the map
//                 if(map[fruits[left]]==0)
//                     map.erase(fruits[left]);

//                 left=left+1; //move the left pointer

//             }
            
//         }

//         if(map.size()<=2){
//             int len=right-left+1;
//             maxlen=max(maxlen,len);
//         }

//         right++;
//     }

// return maxlen;

// }

//How to further reduce the complexity from O(2N) to O(N)
int totalFruit(vector<int>&fruits){

    int n=fruits.size();

    unordered_map<int,int>map;

    int left=0;
    int right=0;
    int maxlen=0;

    while(right<n){

        map[fruits[right]]++; //increases the freq of fruit of each type

        if(map.size()>2){ //if the no of distinct fruits exceeds 2, then shrink the window
                //remove outgoing element
                map[fruits[left]]--;

                //if at any point the freq becomes zero, remove it from the map
                if(map[fruits[left]]==0)
                    map.erase(fruits[left]);

                left=left+1; //move the left pointer

            }
            
    
        if(map.size()<=2){
            int len=right-left+1;
            maxlen=max(maxlen,len);
        }

        right++;
    }
return maxlen;

    }

int main(){
    vector<int>fruits={1,2,1};
    cout<<totalFruit(fruits)<<" ";
    return 0;
}