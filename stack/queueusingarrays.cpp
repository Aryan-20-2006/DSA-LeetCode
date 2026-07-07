//Problem-Implement Queue using Arrays
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

class ArrayQueue{


    int queue[100];
    int currsize;
    int start;
    int end;


public:
    ArrayQueue() {
        currsize=0;
        start=-1;
        end=-1;

    }
    
    void push(int x) {

        if(currsize==100) //if the queue is full
            return;


        if(currsize==0){
            start=0;
            end=0;
        }

        else{
            end=(end+1)%100;
        }
        queue[end]=x;
        currsize++;
        


    }
    
    int pop() {
        if(currsize==0){ //Queue is empty
            return -1;
        }

        int element=queue[start];

        if(currsize==1){

            start=end=-1;
            currsize--;
        }

        else{
            start=(start+1)%100;
            currsize--;
        }

    return element;
  
}
    
int peek() {

    //if the queue is empty
    if(currsize==0)
        return -1;
    
    return queue[start];
}


    
bool isEmpty() {

    return currsize==0; //could also write start==-1 or start==-1 && end==-1
    
}
};

int main(){

ArrayQueue q;
q.push(5);

q.push(10);

cout<<q.peek()<<" "; // returns 5

cout<<q.pop()<<" "; // returns 5

cout<<boolalpha<<q.isEmpty()<<" "; // returns false


}