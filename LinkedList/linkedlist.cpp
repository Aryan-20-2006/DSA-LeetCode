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

//deleting the head of the linked list
Node* deletehead(Node* head){

    //edge case-if there is nothing to delete, then just return the head
    if(head==NULL)
        return head;

    Node* temp=head;
    head=head->next;
    free(temp); //we have to free this memory
    return head;


}

//deleting the tail of the linked list
Node* deletetail(Node* head){

    //edge case-either you have no node or a single node
    if(head==NULL || head->next==NULL)
        return NULL; 

    Node* temp=head;
    while(temp->next->next!=NULL){ //since we want to remove the tail, the temp points to the second last element and we want it to point it to NULL
        temp=temp->next; //keep traversing until temp->next->next=NULL


    }

    free(temp->next); //eg:- 9->3 I want to delete 3, then 9's temp->next is 3 so free(temp->next)
    temp->next=NULL;

    return head;

}

//deleting kth node of the linked list
Node* deletekNode(Node* head, int k){

    if(head==NULL)
        return head;

    //deleting the first element
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    //deleting any k node
    Node* temp=head;
    Node* prev=NULL;
    int cnt=0; //to check if its an element

    while(temp!=NULL){
        cnt++;

        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;

    }

return head;


}

//deleting a particular element
Node* deleteelement(Node* head, int ele){

    if(head==NULL)
        return head;

    //deleting the first element with that value
    if(head->data==ele){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    //deleting any other element-just do a linear search
    Node* temp=head;
    Node* prev=NULL;
   

    while(temp!=NULL){

        if(temp->data==ele){
            prev->next=prev->next->next;
            free(temp);
            break;
        }

        prev=temp;
        temp=temp->next;

    }

return head;


}

/*
void deleteNode(ListNode* node) {
        
       if(node==NULL){
            return;
       }

        ListNode* temp=node->next;

        node->val=node->next->val; //copying the next node's value into this

        node->next=node->next->next; //skip the current node


        delete temp; //free the node that we saved earlier




    }

*/

//Insertion at the head
Node* inserthead(Node* head,int val){
    Node* temp=new Node(val,head);  //takes the val and what is the next
    return temp;//or return new Node(head,val);
}

//Insertion at the tail
Node* insertTail(Node* head, int val){
    if(head==NULL){ //if the list is empty
        return new Node(val);
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

//Inserting the kth element
Node* insertk(Node* head,int ele, int k){
    if(head==NULL){ //then u can insert only at the fist position
        if(k==1){
            return new Node(ele);
        }

        else{
            return NULL;
        }
    }

    int cnt=0;
    Node* temp=head;
    
    while(temp!=NULL){
        cnt++;

        //I can only insert at that position if I am one behind the head
        if(cnt==k-1){
            Node* newNode=new Node(ele);
            newNode->next=temp->next; //first connect
            temp->next=newNode;
            break;
        }


        temp=temp->next;
    }

    return head;

}

Node* insert_before_val(Node* head,int ele, int val){
    if(head==NULL){ //if the list is empty, then you cant find the val
        return NULL;
    }

    Node* temp=head;
    
    while(temp!=NULL){

        //Eg:3->1->5->8 suppose temp is at 5 i.e temp->next->data=8, so the temp at worst case can be at the second last element
        if(temp->next->data==val){
            Node* newNode=new Node(ele);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }


        temp=temp->next;
    }

    return head;

}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
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

vector<int>arr={10,20,30,40};
// Node* y=new Node(arr[0],nullptr); //pointer to the memory location
// cout<<y;

//traversal 
Node* head=convert(arr);
// // Node* temp=head;
// // // while(temp!=NULL){
// // //     cout<<temp->data<<" ";
// // //     temp=temp->next;
// // // }

// // cout<<length(head)<<" ";

// head=deletehead(head);

// head=deletetail(head);

// int k=3;

// head=deletekNode(head,k);


// head=deleteelement(head,30);

// head=inserthead(head,100);

// head=insertTail(head,200);

// head=insertk(head,5,3);

head=insert_before_val(head,3,30);



print(head);

return 0;


}


