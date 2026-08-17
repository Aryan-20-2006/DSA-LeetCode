//Problem-Detect Cycle in a Linked List
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

 
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:

    //Brute Force-Using hashing-TC-O(N), SC-O(1)
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*,int>map;
        ListNode* temp=head;

        while(temp!=nullptr){
            if(map.find(temp)!=map.end()){ //which means you find the same node again
                return true; //cycle is found
            }

            temp=temp->next;//if not found

        }


        return false;
    }

    //Optimal Solution-Using fast and slow pointers , TC-O(N),SC-O(1)
     bool hasCycle(ListNode *head) {

      ListNode* slow=head;
      ListNode* fast=head;
      
      //we will stop if the fast pointer reaches the last node or reaches null
      while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return true; //we have found a cycle
            }
      }

      return false; //this means its a linear data structure

    }
};


//Similar question-To return the starting point of the linked list-Linked list cycle II
ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

            //if cycle is detected
            if(slow==fast){
                
                slow=head;//reset slow to head
                
                //move the fast and slow pointers by 1, if they reach again then we are at the starting point
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }

                return slow;
            }
        }

    return nullptr;
       
}