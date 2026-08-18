//Problem-Palindrome Linked List
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;


 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head){


    if(head==nullptr || head->next==nullptr){
        return head;
    }

    ListNode* newHead=reverse(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;



}

//TC-O(N),SC-O(1)
bool isPalindrome(ListNode* head){

ListNode* fast=head;
ListNode* slow=head;


//we have to first find the middle node and reverse the second half
while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
}

ListNode* newHead=reverse(slow->next); //reverses the second half
ListNode* first=head;
ListNode* second=newHead;

//the second pointer will get exhausted
while(second!=nullptr){
    if(first->val!=second->val){
        reverse(newHead); //it is better to reverse to preserve the original data before returning false
        return false;

    }

    else{
        first=first->next;
        second=second->next;
    }
}

reverse(newHead);
return true;

}