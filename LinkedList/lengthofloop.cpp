//Problem-Length of the loop
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;



//Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        int cnt=0;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            

            //once slow is equal to fast, that means cycle has been detected, now move only fast by 1 until it reaches slow again and increment the cnt
            if(slow==fast){

                while(slow!=fast){
                    fast=fast->next;
                    cnt++;
                }

                return cnt;
            }

            return 0;
    }
}
};