//Problem-Intersection of two linked lists
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//Brute Force-
/*
1. Keep any of the list to check its node is present in the other list
2. Iterate through the other list
3. Check if both the nodes are the same, then we get our first intersection node
4. If not , continue iteration
4. If we didnt find our intersection node, then return null


*/
class Solution {
public: //TC-O(M*N)-For each node in list2,we're iterating the entire list1, SC-O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    while(headB!=nullptr){ //we're keeping the head of the second to check if one of its node is present in the other list
        ListNode* temp=headA;
        while(temp!=nullptr){ //iterating through the other list i.e the first list to check if temp==headB , in that case it would be our intersection
            if(temp==headB){
                return temp;
            }

            temp=temp->next;
        }

        headB=headB->next;
    }

    return nullptr;

    }
};

//Optimal Solution-TC-O(N1+N2) SC-O(1)
class Solution {
public: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* t1=headA;
        ListNode* t2=headB;

        //if both the heads are pointing to null , that means there isnt any intersection
        if(headA==nullptr || headB==nullptr)
            return nullptr;

        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;

            //if an intersection point is found
            if(t1==t2)
                return t1; //or you could return t2;

            //if t1 reaches nullptr, then move t1 to the second head, from there again both move simulatneouly until it meets
            if(t1==nullptr)
                t1=headB;
            

            //if t2 reaches nullptr, then move t2 to the first head
            if(t2==nullptr)
                t2=headA;
        }

        return t1;

    }
};