//Problem-Infix to Postfix
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

int priority(char ch){

        if(ch=='^')
            return 3;
        if(ch=='*' || ch=='/')
            return 2;
        if(ch=='+' || ch=='-')
            return 1;

return -1;


}

string infixtoPostfix(string s){

    int i=0;
    stack<char>st;
    int n=s.size();
    string ans="";

    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i]; //add the operands to your answer string
        }

        //checking for brackets
        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){ //if you find a closing bracket, keep removing operators until you find an opening bracket
            while(!st.empty() && st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }

            st.pop(); //pop the opening bracket

        }

        else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            
                st.push(s[i]);

            }

        i++;

        }

    while(!st.empty()){ //if the stack isnt empty after all the iterations, 
        ans+=st.top();
        st.pop();
    }


    return ans;

}

int main(){

    string s="a+b*(c^d-e)";
    cout<<infixtoPostfix(s)<<" ";
    return 0;


}