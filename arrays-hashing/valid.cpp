//Problem:Valid Palindrom
//Difficulty:Easy
/*
Approach:To use the concept of left and right pointers
one pointer at the start and another one at the end
compare both the pointers if they are symmetric
if they match move left pointer towards right by 1 and right pointer towards left by 1


*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){

int n=s.size(); //length of string

int i=0; //left pointer
int j=n-1; //right pointer

while(i<j){
    if(!isalnum(s[i])){ //check for alphanumeric character like alphabets but ignores anything else like ,,;,""
        i++;
        continue; //if u skip a pointer u must not compare in the same iteration
    }

    if(!isalnum(s[j])){
        j--;
        continue;
    }

    char left=tolower(s[i]);
    char right=tolower(s[j]);

    if(left!=right) //compare the pointers at the start and end
        return false;

    else{
        i=i+1;
        j=j-1;
    }



}

return true;


}

int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s)<<endl;
    return 0;
}