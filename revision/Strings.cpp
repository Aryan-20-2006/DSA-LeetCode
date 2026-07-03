#include<bits/stdc++.h>
using namespace std;


//Reversing words in a string
// string Rev(string &s){

//     int n=s.size();
//     string ans;

//     reverse(s.begin(),s.end());

//     for(int i=0;i<n;i++){
//         string word;
//         while(i<n && s[i]!=' '){
//             word+=s[i];
//             i++;

//         }

//         reverse(word.begin(),word.end());

//         if(word.size()>0)
//             ans+=" "+word;
//     }

// return ans.substr(1);

// }

// int main(){

//     string s="I am Aryan";
//     cout<<Rev(s)<<" ";
//     return 0;

// }