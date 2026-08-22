//Problem-Sort List
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
    struct ListNode {
    int val; ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Merge two sorted lists
ListNode* sortTwoLists(ListNode* list1,ListNode* list2){

    ListNode* t1=list1;
    ListNode* t2=list2;
    ListNode* dnode=new ListNode(-1); //creating a dummy node 
    ListNode* temp=dnode; //this will be pointing to the node after comparing the values

    while(t1!=nullptr && t2!=nullptr){
        if(t1->val<t2->val){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }   

        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
 
    }

    //if either list1 or list2 gets exhausted

    if(t1->next!=nullptr){
        temp->next=t1; //which means there are still remaining elements in t1
    }

    else{
        temp->next=t2;
    }

    return dnode->next; //dnode->next points to the head of the newlinked list


}


//One edge case to consider Eg:-1->2->3->4 , if I use fast and slow pointers then it would return the second middle i.e 3
//Since im using the concept of merge sort, it should split into [1,2] and [3,4]
ListNode* findmiddle(ListNode* head){

    //if it is a single node, then that is only the middle
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    ListNode* slow=head;
    ListNode* fast=head->next; //since I want the first middle

    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
       
        //if it is a single node, then return that
        if(head==nullptr || head->next==nullptr){
            return head;
        }

        //find the middle
        ListNode* middle=findmiddle(head);

        //Eg-1->2->3->4->5 . Since im using the concept of merge sort, I need to split it into two halves
        //i.e [1,2,3] and [4,5] both the lists should be separate . So I need two pointers and play around with the links

       
        ListNode* lefthead=head; //this is for the left half
        ListNode* righthead=middle->next; //this is where the right half starts from

        //Since I have to split it into two halves
        middle->next=nullptr;

        //recursively sorting both the halves
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        //Since I need the final list contain both the lists in sorted order, call the sorted2lists function
        return sortTwoLists(lefthead,righthead);

    }
};