#include<bits/stdc++.h>
using namespace std;


//class Node also works
class Node{
    public: //constructor function-used to initialize objects
    int data;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

    //this constructor only takes the data
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};

//converting an array to a linked list
Node* convert(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next; //or mover=temp;
    }

    return head;

}

//length of a LL
int length(Node* head){
    int count=0;
    Node* temp=head;

    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }

    return count;
}

//searching for an element in the linked list
int check(Node* head, int val){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            return 1;
        }

        temp=temp->next;
    }

    return 0;
}

int main(){

vector<int>arr={1,2,3,4};
// Node* y=new Node(arr[0],nullptr); //pointer to the memory location
// cout<<y;

//traversal 
Node* head=convert(arr);
Node* temp=head;
// while(temp!=NULL){
//     cout<<temp->data<<" ";
//     temp=temp->next;
// }

cout<<length(head)<<" ";


}


