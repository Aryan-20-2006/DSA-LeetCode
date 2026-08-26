//Problem-Merge K Sorted Lists
//Difficulty-Hard

#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//Optimal Soln-Using a minheap(Priority Queue)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //create the priority queue-min heap
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>pq;

        //iterate through all the lists and put the {head->val,head} in the priority queue
        for(int i=0;i<lists.size();i++){

            //checking if the lists are not null

            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});

            }
        }

        //Create a dummy node-this will help us in returning the head of the merged list
        ListNode* dnode=new ListNode(-1); 
        ListNode* temp=dnode;

        while(!pq.empty()){

            //look for the minimum
            pair<int,ListNode*>p=pq.top(); //once this is in the pq, we need the next element of that list
            temp->next=p.second; //this is pointing the next node of the current node we just popped out
            pq.pop();

            //Since I have deleted it, I want its next element to get into the priority queue
            if(p.second->next){
                pq.push({p.second->next->val,p.second->next}); //pushing the next val and the node

            }

            temp=temp->next;

        }

        return dnode->next;//this returns the head of the final merged list

    }   
};