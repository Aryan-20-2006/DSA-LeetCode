#include<bits/stdc++.h>
using namespace std;


 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head){

    //To delete the middle node, we have to find the middle node first

    //if there is a single node
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;  //slow gives us the middle node
        fast=fast->next->next;
    }


    //From here, we use the concept of deleting a node of a particular value
    ListNode* temp=head;
    ListNode* prev=head;

    while(temp!=nullptr){
        if(temp==slow){ //if you find the middle node
            prev->next=prev->next->next;
            delete(temp);
        }
        prev=temp; //storing previous state
        temp=temp->next;
    }

return head;
}