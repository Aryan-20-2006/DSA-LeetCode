//Problem-Preorder Traversal
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };

//TC-O(N)-processing traversals only once, SC-O(N)-stack space
void preorder(TreeNode* root,vector<int>&arr){

//if the current root is NULL , return

if(root==nullptr)
    return;

arr.push_back(root->data);

preorder(root->left,arr);

preorder(root->right,arr);

}

vector<int>preorderTraversal(TreeNode* root){

    vector<int>arr;

    preorder(root,arr);


    return arr;

}