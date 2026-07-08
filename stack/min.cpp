//Problem-Implement Min stack
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

class MinStack {

    stack<int>st;
    int mini;

public:
    MinStack() {
        mini=INT_MAX;
    }

  void push(int value) {
    if(st.empty()){
        mini=value;
    }

    else{
        if(value>mini){
            st.push(value);
        }

        else{
            st.push(2*value-mini);
            mini=value;
        }

        }
    }

void pop() {
    
    if(st.empty())
        return;

    int x=st.top();
    st.pop();

    if(x<mini){
        mini=2*mini-x;
    }
  
}

  int top() {
    if(st.empty())
        return 0;

    int x=st.top();

    if(mini<x){
        return x;
    }

    else
        return mini;
}

  int getMin() {

    return mini;

  }
};

int main(){


MinStack minStack;

minStack.push(-2);

minStack.push(0);

minStack.push(-3);

cout<<minStack.getMin()<<" "; // returns -3

minStack.pop();

cout<<minStack.top()<<" ";  // returns 0

cout<<minStack.getMin()<<" "; // returns -2

}