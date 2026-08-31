//Problem-Number of substrigns containing all three characters
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//TC-O(N2),SC-O(3)
// int numberofSubstrings(string s){

// int n=s.size();

// int cnt=0;

// for(int i=0;i<n;i++){

//     vector<int>freq(3,0); //the freq array will update here

//     for(int j=i;j<n;j++){
//         freq[s[j]-'a']++;

//         //checking if all the characters are there
//         if(freq[0]>0 && freq[1]>0 && freq[2]>0){
//             cnt++;
//         }
//     }

// }
// return cnt;

// }

//Optimal Solution 
int numberofSusbtrings(string s){

    int cnt=0;

    int l=0;
    int r=0;
    unordered_map<char,int>freq;

    int n=s.size();

    while(r<n){
        freq[s[r]-'a']++;

        //shrink the window-valid only when I know even after shrinking my string would be valid i.e have at least one a,b,c
        while(freq[0]>0 && freq[1] && freq[2]>0){
            freq[s[l]-'a']--; //decrement the freq of the outgoing element
            l=l+1;
        }

        cnt+=l; //because all the substrings from 0...l-1 ann edning at r are valid
        r++;
    }

return cnt;

}

int main(){
    string s="abcabc";
    cout<<numberofSusbtrings(s)<<" ";
    return 0;
}