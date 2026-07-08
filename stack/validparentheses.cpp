//Problem-Valid Parentheses
//Diffculty-Easy

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){


    stack<char>st;

    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]); //pushing all the opening brackets
        }
          
    else{
        if(st.empty()) //no matching opening bracket
            return false;
        char ch=st.top(); //getting the character other than opening brackets
        st.pop(); //these closing brackets will get poppped

        if((s[i]==')' && ch=='(') || 
            (s[i]=='}' && ch=='{') || 
            (s[i]==']' && ch=='[')){
                continue; //if it matches, skip the iteration
         }

        else
            return false;

}

}

        
return st.empty(); //means everything is matching

}

int main(){

    string s="()";
    cout<<isValid(s)<<" ";
    return 0;


}


