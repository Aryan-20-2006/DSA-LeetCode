//Problem-Segregate odd and even nodes 
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

class Solution {
public:
//Brute Force-Replacing the values, TC-O(N) , SC(N)
    ListNode* oddEvenList(ListNode* head) {
        vector<int>arr;

        //Step1-odd indices
        ListNode* temp=head;

        while(temp!=nullptr && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }

        //if temp is not null after all this , then push the remaining node
        if(temp!=nullptr){
            arr.push_back(temp->val);
        }

        
        //Step2-even indices
        ListNode* temp=head->next; //even index node starts from here

        while(temp!=nullptr && temp->next!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next->next;
        }

        //if temp is not null after all this , then push the remaining node
        if(temp!=nullptr){
            arr.push_back(temp->val);
        }

        //Step3-Replace the values
        int i=0;
        ListNode* temp=head;

        while(temp!=nullptr){
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }

    return head;
    }
};


//Optimal Solution(TC-O(N),SC-O(1))-Changing the links
class Solution {
public:
//Brute Force-Replacing the values, TC-O(N) , SC(N)
    ListNode* oddEvenList(ListNode* head) {
        //Before this check if there is an empty list or a single node, return that
        if(head==nullptr || head->next==nullptr){
            return head;
        }

       ListNode* odd=head;
       ListNode* even=head->next;
       ListNode* evenhead=head->next; //this will be used later for connecting the last odd node to the even node
    
        //even will be always ahead of odd so the checks will be based on even
        while(even!=nullptr && even->next!=nullptr){
            odd=odd->next->next;
            even=even->next->next;

            odd=odd->next;
            even=even->next; //since they are both jumping 2 two times so move to the next no need of next->next
        }

        //now connect the last odd node to the even node
        odd->next=evenhead;
        return head;
    
    
    }
};