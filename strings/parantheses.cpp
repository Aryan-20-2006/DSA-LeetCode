//Problem-Remove Outermost Parentheses
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){

    
    string ans="";
    int count=0; //using a counter variable
    int n=s.size();

    for(int i=0;i<n;i++){
        if(s[i]==')')
            count--;
        
        if(count!=0)
            ans+=s[i]; //if the counter isnt 0, add it to the answer string
        
        if(s[i]=='(')
            count++;
        
        
    }

return ans;

}

int main(){

    string s="(())";
    cout<<removeOuterParentheses(s)<<" ";
    return 0;

}