//Problem-Longest Substring with K Uniques
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Brute Force-TC-O(N2),SC-O(k)
// int longestKSubstr(string &s, int k){

//     int n=s.size();
//     int maxlen=0;
    
  

//     for(int i=0;i<n;i++){

//         unordered_map<char,int>map; //we are tracking the distinct character so this has to update

//         for(int j=i;j<n;j++){
//             map[s[j]]++;


//             //if the no of distinct characters exceed k
//             if(map.size()>k){
//                 break;
//             } 

//             int len=j-i+1;
//             maxlen=max(maxlen,len);
//         }

//     }

//     return maxlen;

// }

//Optimal Solution-TC-O(N), SC-O(k) 
int longestKSubstring(string &s, int k){

int n=s.size();
int l=0;
int r=0;
int maxlen=0;

unordered_map<char,int>freq;

//First we check for the distinct characters
for(int i=0;i<s.size();i++){
    freq[s[i]]++;
}

//Eg:-aaaa, k=2 , but there is only one distinct character so return -1;
if(freq.size()<k){
    return -1;
}


unordered_map<char,int>map;
while(r<n){
    map[s[r]]++;

    //Shrink the window
    while(map.size()>k){
        map[s[l]]--;

        if(map[s[l]]==0){
            map.erase(s[l]);
        }

        l=l+1;
    }

    //if you have found the k distinct elements
    if(map.size()==k){
        int len=r-l+1;
        maxlen=max(maxlen,len);
    }

    r++;

}

return maxlen;

}

int main(){
    string s="eceba";
    int k=2;
    cout<<longestKSubstring(s,k)<<" ";
    return 0;
}