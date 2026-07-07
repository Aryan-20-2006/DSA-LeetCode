//Problem-Implement Stack using arrays
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

class ArrayStack { //class name-creating your own datatype
    int arr[100]; //these are my member variables
    int topIndex;

public:
    ArrayStack() { //constructor-it has the same name as the class
        topIndex=-1;
    
    }
    
    void push(int x) {
        arr[++topIndex]=x;
    }
    
    int pop() {
        return arr[topIndex--];
    }
    
    int top() {
        return arr[topIndex];
    }
    
    bool isEmpty() {  //here the question is asking for true or false
        if(topIndex==-1) //this can also be written as return top==-1;
            return true;
        else
            return false;
    }
};

int main(){

//Note-The array is already there in ArrayStack Object

ArrayStack st; //creating an object name st of type ArrayStack

st.push(5);
st.push(10);

cout<<st.top()<<" ";

cout<<st.pop()<<" ";

cout<<boolalpha<<st.isEmpty()<<" "; //you can use boolalpha to print booleans as words instead of numbers

return 0;

}