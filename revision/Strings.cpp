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

//Remove Outermost Parentheses

// string removeoutermostParenthese(string s){

//     string ans="";
//     int count=0;

//     for(int i=0;i<s.size();i++){
//         if(s[i]==')')
//             count--;
//         if(count!=0)
//             ans+=s[i];
//         if(s[i]=='(')
//             count++;
        
//     }

// return ans;

// }

//Check if string is palindrome or not-Based on two pointer approach
// bool isPalindrome(string s){

//     int i=0;
//     int n=s.size();
//     int j=n-1;

//     while(i<j){
        
//         if(s[i]!=s[j])
//             return false;

//         else{
//             i=i+1;
//             j=j-1;
//         }
//     }

// return true;

// }

// int main(){

//     string s="abba";
//     cout<<isPalindrome(s)<<" ";
//     return 0;

// }

//Count number of substrings

// int countSubstr(string str){

//     int count=0;

//     int n=str.size();

//     //Brute Force Approach
//     for(int i=0;i<n;i++){
//         string substr=" ";
//         for(int j=i;j<n;j++){
//             substr+=str[j];
//             count++;
//         }
//     }

//     return count;

// // return n*(n+1)/2; //shortcut to solving counting all substrings

// }

// int main(){

//     string str="abc";
//     cout<<countSubstr(str)<<" ";
//     return 0;
// }

//Roman to Integer-Alternative way of solving

// int romantoInt(string s){


//     unordered_map<char,int>map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

//     int n=s.size();

//     int result=map[s[n-1]]; //assuming im starting from the end

//     for(int i=n-2;i>=0;i--){
//         if(map[s[i]]<map[s[i+1]])
//             result-=map[s[i]];
//         else
//             result+=map[s[i]];
//     }


// return result;
// }

// int main(){

//     string s="XLII";
//     cout<<romantoInt(s)<<" ";
//     return 0;

// }