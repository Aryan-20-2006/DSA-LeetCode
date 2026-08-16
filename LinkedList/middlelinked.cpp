//Problem-Median of the linked list
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
 
//Brute-Find the length of the linked list
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        int cnt=0;
        ListNode* temp=head;
        

        //One pass-O(N)
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }

        int midnode=(cnt/2)+1;

        //second pass-TC-O(N/2),SC-O(1)
        ListNode* temp=head;
        
        while(temp!=nullptr){
            midnode=midnode-1;
            if(midnode==0){
                break;
            }
            temp=temp->next;
        }

        return temp;
        
    }

    //Optimized Approach-Tortoise and Hare(Fast and Slow pointers)
    ListNode* middleNode(ListNode* head) {

        ListNode* temp=head;
        
        ListNode* slow=head;
        ListNode* fast=head;

        //One pass-TC-O(N/2),SC-O(N)
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next; //moves 1 step
            fast=fast->next->next; //moves 2 steps
        }

        return slow; //this gives us the middle node
        
        
    }



};