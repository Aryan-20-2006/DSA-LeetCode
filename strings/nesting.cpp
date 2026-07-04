//Problem-Maximum Nesting Depth of the Parentheses
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s){


    int maxi=0;
    int count=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            count++;
        if(s[i]==')')
            count--;
        
        maxi=max(maxi,count);
    }

return maxi;

}

int main(){

    string s="(1)+((2))+(((3)))";
    cout<<maxDepth(s)<<" ";
    return 0;

}