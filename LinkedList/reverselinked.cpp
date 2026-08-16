//Problem-Reverse a linked list
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


class Solution {
public:
//Iterative Solution-TC-O(N),SC-O(1)
    ListNode* reverseList(ListNode* head) {

        //Iterative Solution
        ListNode* temp=head;
        ListNode* prev=nullptr;

        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp; //after every rotatio you have to store prev
            temp=front;
        }

        return prev;
    }

    //Recursive Solution-TC-O(N),SC-O(N)(Recursion stack space)
     ListNode* reverseList(ListNode* head) {

       //If only one node or no node
       if(head==nullptr || head->next==nullptr){
            return head;
       }

       ListNode* newhead=reverseList(head->next); //this goes into the recursion call and finds the head until it is a single node and then backtracks
       ListNode* front=head->next;
       front->next=head;
       head->next=nullptr; //reversing the links
       return newhead;
    }


};
