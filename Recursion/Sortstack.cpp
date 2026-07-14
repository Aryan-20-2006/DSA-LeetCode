//Problem-Sort a stack using recursion
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;


//helper function
void insert(stack<int>&st, int temp){

    if(st.empty() || st.top()<=temp ){
        st.push(temp);
        return;
    }

    int val=st.top();
    st.pop();
    insert(st,temp);

    st.push(val);

}

void sortStack(stack<int>&st){

    //pop all the elements until it becomes empty
    if(!st.empty()){
        int temp=st.top();
        st.pop();
    

    sortStack(st); //recursively call until the stack becomes empty

    insert(st,temp);

    }

}

int main(){

    stack<int>st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);

    sortStack(st);

    while(!st.empty()){ //in descending order
        cout<<st.top()<<" ";
        st.pop();
    }

return 0;

}

