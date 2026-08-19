//Problem-Remove Nth Node from End of List
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Brute Force-To delete the the nth node of the linked list from the end
//It is the same as deleting the (L-N+1)th node from the start
class Solution {
public: //TC-O(L)+O(L-N) SC-O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        //if it is only one node, delete it
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }

        //Find the length first
        int cnt=0;
        ListNode* temp=head;

        while(temp!=nullptr){
            cnt++; //this stores the length of the list
            temp=temp->next;
        }

        //if n==1, we're deleting the tail of the linked list
        if(n==1){
            ListNode* temp=head;
            
            //to delete the tail, I need the second last node
            while(temp->next->next!=nullptr){
                temp=temp->next;
                
            }

            delete(temp->next); //this deletes the last node
            return head;
        }

        //n==length of the list i.e deleting the head
        if(cnt==n){
            ListNode* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }

        //deleting any other node from end i.e deleting (L-N+1) th node from the start
        int res=(cnt-n); //node before the node ur about to delete

        ListNode* temp=head;
        while(temp!=nullptr){
            res--;

            if(res==0){
                ListNode* todelete=temp->next; //save the noe you want to delete
                temp->next=temp->next->next;
                delete(todelete) ;//the node we want to delete
            }
        }

        return head;


    }
};

//Optimal Soln-O(N), SC-O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        
ListNode* fast=head;

//fast will be ahead of slow by n steps
for(int i=0;i<n;i++){
    fast=fast->next;
}

//if the fast pointer reaches null i.e delete the head
if(fast=nullptr){
    return head->next; //this is the newhead
}


//once fast pointer is done moving now slow and fast will move simultaneously
ListNode* slow=head;
while(fast->next!=nullptr){
    fast=fast->next;
    slow=slow->next; 
}


//slow will be the node before the one to be deleted
ListNode* delnode=slow->next;
slow->next=slow->next->next;
delete(slow->next);

return head;   
    
}