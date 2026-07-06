//Problem-Longest Palindromic Substring
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//Brute Force Approach
// bool isPalindrome(string s,int i,int j){

//     while(i<j){
//         if(s[i]!=s[j]){
//             return false;
//         }

//         else{
//             i=i+1;
//             j=j-1;
//         }

//     }

// return true;

// }

// string longestPalindrome(string s){

//     int n=s.size();

//     string res=" ";

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             if(isPalindrome(s,i,j)){
//                 int length=j-i+1;
//                 if(length>res.size()){
//                     res.substr(i,j+1);
//                 }
                
//             }
//         }
//     }

// return res;

// }

// int main(){

//     string s="cbbd";
//     string res=longestPalindrome(s);

//     for(int i=0;i<res.size();i++){
//         cout<<res[i]<<" ";
//     }

//     return 0;


// }

int expand(string s, int l, int r){

    int n=s.size();

    while(l>=0 && r<n && s[l]==s[r]){
        l--;//here we're trying to rexpand
        r++;
    }

    
return r-l-1;

}

string longestPalindrome(string s){

    int n=s.size();
    int start=0;
    int end=0;

    for(int i=0;i<n;i++){
        int len1=expand(s,i,i); //for odd length palindrome
        int len2=expand(s,i,i+1); //for odd length palindrome
        int len=max(len1,len2);

        int currlen=end-start+1;

        //if the new palindrome is longer than the current one
        if(len>currlen){
            start=i-(len-1)/2;
            end=i + len/2;
        }   

    }

return s.substr(start,end-start+1);

}
    
int main(){

    string s="babad";
    cout<<longestPalindrome(s)<<" ";
    return 0;
}


