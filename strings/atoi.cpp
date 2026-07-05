//Problem-String to integer(atoi)
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

const int INT_MIN_VAL=-2147483648;
const int INT_MAX_VAL=2147483647;

int helper(const string &s, int i,long long num, int sign){

    //if it is out of bounds or if its not a digit
    if(i>=s.size() || !isdigit(s[i])){
        return (int)(sign*num); //since we have a long num and int sign, better to convert both to int
    }

    //forming the number
    num=(num*10)+(s[i]-'0'); //converting character to digit

    if(num*sign>INT_MAX_VAL)
        return INT_MAX_VAL;

    if(num*sign<INT_MIN_VAL)
        return INT_MIN_VAL;

    return helper(s,i+1,num,sign); //it has to move to the next character

}

int myAtoi(string s){

    int n=s.size();
    int sign=1;
    int i=0;

    //removing leading spaces
    while(i<n && s[i]==' '){
        i++;
    }

    //Handle the sign-if -ve, -1 . If +ve, +1
    if(i<s.size() && (s[i]=='-' || s[i]=='+')){
        if(s[i]=='-')
            sign=-1;
        else
            sign=1;
        i++;
    }
        
    
    return helper(s,i,0,sign);

}

int main(){

    string s=" -12345";
    cout<<myAtoi(s)<<" ";
    return 0;


}

