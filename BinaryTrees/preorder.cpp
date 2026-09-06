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

//Recursive Solution
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

//Iterative Solution-Using a stack
//TC-O(N), SC-O(N)
vector<int>preorderTraversal(TreeNode* root){
    vector<int>preorder;

    if(root==nullptr)
        return preorder;

    stack<TreeNode*>st;

    st.push(root);

    while(!st.empty()){

        root=st.top();
        st.pop();

        preorder.push_back(root->data);

        //push right and then left -why?-Since stack is LIFO and in preoder we want Root,Left,Right
        if(root->right!=nullptr)
            st.push(root->right);

        if(root->left!=nullptr)
            st.push(root->left);
    }

return preorder;

}