//Problem-Reverse a stack
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

//Write a helper function to insert and element at the bottom

void insert(stack<int>&st,int val){

    //if the stack is empty,push the value
    if(st.empty()){
        st.push(val);
        return;
    }

    //if its not empty, pop the top element and push the popped element back
    
        int temp=st.top();
        st.pop();

        insert(st,val);//recursively calling the function

        st.push(temp);
    
}


void reverseStack(stack<int>&st){

    if(st.empty())
        return;

    int temp=st.top();
    st.pop();

    reverseStack(st);

    insert(st,temp);

}

int main(){

   stack<int>st;
   st.push(4);
   st.push(1);
   st.push(3);
   st.push(2);

   reverseStack(st);

   while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
   }

return 0;

}

