#include<bits/stdc++.h>
using namespace std;

/*How we represnted singly linked list
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    
    
    }

    public:{
    Node(int data1){
        data=data1
        next=nullptr
    
    }
    
    }


}
*/

//Representation of doubly linked list
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    
    
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    
    }

    //Converting array to linked list
    Node* convertarr(vector<int>&arr){
        Node* head=new Node(arr[0]);
        Node* prev=head;

        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr,prev); //the prev is assigned to prev
            prev->next=temp;
            prev=temp;
        }

        return head;
        
    }


    void print(Node* head){
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }

    Node* deletehead(Node* head){
        
        //if there are no nodes
        if(head==nullptr){
            delete head;
            return nullptr;
        }

        //if there is only one node
        if(head->next==nullptr){
            delete head;
            return nullptr;
        }

        //More than one node
        Node* prev=head;
        //move the head to the next node
        head=head->next;
        head->prev=nullptr;
        prev->next=nullptr;
        delete prev;
    }

    //Deleting the tail of the linked list
    Node* deletetail(Node* head){

        //if Node is empty or has a single element
        if(head==nullptr || head->next==nullptr)
            delete head;
            return nullptr;

        Node* tail=head;
        while(tail->next!=nullptr){ //this will stop at the last node
            tail=tail->next;

        }
        Node* prev=tail->prev; //the previous here is your new tail
        prev->next=nullptr;
        delete tail;

        

        return head;

    }

    //Deleting the kth element of the doubly linked list
    Node* deleteKelement(Node* head, int k){
        Node* temp=head;
        int cnt=0;

        //finding the kth element to delete
        while(temp!=nullptr){
            cnt++;
            if(cnt==k){
                break;
            }

            temp=temp->next;
        }

        //if k is invalid
        if(temp==nullptr){
            return head;
        }

        Node* prev=temp->prev;
        Node* front=temp->next;


        //if it has only one node, them front and prev both point to null;
        if(prev==nullptr && front==nullptr){
            delete temp;
            return nullptr;
        }

        //If only prev is null-i.e it is the first element
        else if(prev==nullptr){
            return deletehead(head);
    
        }

        //if the front is NULL i.e deleting the tail
        else if(front==nullptr){
            return deletetail(head);
        }

        //otherwise we are deleting the kth element
        else{
            prev->next=front;
            front->prev=prev;
            temp->next=nullptr; //since we are deleting this
            temp->prev=nullptr;
            delete temp;
        }

        return head;

    }


    //Deleting a given node
    void deleteNode(Node* temp){
        Node* prev=temp->prev;
        Node* front=temp->next;

        //if the front is null
        if(front==nullptr){
            prev->next=nullptr;
            temp->prev=nullptr;
            delete(temp);
            return;
        }

        //if it has a front and prev
        prev->next=front;
        front->prev=prev;
        temp->next=nullptr;
        temp->prev=nullptr;
        free(temp); //since it is a void function
    }

    //Inserting before head
    Node* insertbeforehead(Node* head, int val){
        Node* newHead=new Node(val,next,nullptr); //the new node you are inserting before head
        head->prev=newHead;
        return newHead;
    }

    //Inserting before the tail
    Node* insertbeforetail(Node* head, int val){

        //if only one node
        if(head->next==nullptr){
            return insertbeforehead(head,val);
        }


        Node* tail=head;
        while(tail->next!=nullptr){ //go to the last node
            tail=tail->next;
        }

        //first create the node you want to insert before tail
        Node* newNode= new Node(10,tail,prev);
        prev->next=newNode;
        tail->prev=newNode;
        return head;
    }

    //Inserting before the kth element
    Node* insertbeforeK(Node* head,int val,int k){

        //if its the first node
        if(k==1){
            return insertbeforehead(head,val);
        }


        //first find the node we have to inset before
        Node* temp=head;
        int cnt=0;

        while(temp->next!=nullptr){
            cnt++;
            if(cnt==k){
                break;
            }
            temp=temp->next;
        }

        //if k is out of range
        if(temp==nullptr){
            return head;
        }

        if(temp->next==nullptr){
            return insertbeforetail(head,val);
        }
        
        Node* prev=temp->prev;
        Node* newNode= new Node(val,temp,prev);
        prev->next=newNode;
        temp->prev=newNode;
    }

    //Inserting before a given node
    void insertbeforeanode(Node* node, int val){
        Node* prev=node->prev;

        Node* newNode=new Node(val,next,prev);
        prev->next=newNode;
        node->prev=newNode;
    }
    
};


int main(){
}
