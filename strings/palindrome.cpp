//Problem-Palindrome String
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

//Brute Force-For a Simple Palindrome (characters are already in lowercase)
 
// bool isPalindrome(string &s){

//     string rev=s;
//     reverse(rev.begin(),rev.end());
    
//     if(rev==s)
//         return true;

//     return false;
// }

bool isPalindrome(string &s){

    int n=s.size();
    int i=0;
    int j=n-1;

    while(i<j){
        if(s[i]!=s[j])
            return false;

        i++;
        j--;


    }

return true;

}

int main(){

    string s="abba";
    cout<<isPalindrome(s)<<" ";
    return 0;

    
}