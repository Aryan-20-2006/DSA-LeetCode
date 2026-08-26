//Problem:Merge two sorted lists
//Difficult:Easy


#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr) {} //list has val x and next=NULL
    
};

struct ListNode* mergeTwolists(ListNode* l1,ListNode* l2){

    ListNode temp(-1); //create a temp node-this is the dummy variable
    ListNode* curr=&temp;

    while(l1!=nullptr && l2!=nullptr){
        if(l1->val<=l2->val){
            curr->next=l1;
            l1=l1->next;
        }

        else{
            curr->next=l2;
            l2=l2->next;
        }

        curr=curr->next;
    }

    if(l1!=nullptr){
        curr->next=l1;
    }

    else if(l2!=NULL){
        curr->next=l2;
    }

    return temp.next;

}