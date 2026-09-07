//Problem-Balanced Binary Tree
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };


//Brute Force-O(N2)
int height(TreeNode* root){

if(root==nullptr)
    return 0;

int lh=height(root->left);

int rh=height(root->right);

return 1+max(lh,rh);


}


bool isBalanced(TreeNode* root){

    if(root==nullptr)
        return true;

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(rh-lh)<=1)
        return false;

    return true;
}

//Optimal Solution-TC-O(N),SC-O(N)
int height(TreeNode* root){

    if(root==nullptr)
        return 0;

    int lh=height(root->left);

    //if at any point lh==-1, it becomes unbalanced
    if(lh==-1)
        return -1;

    int rh=height(root->right);

    if(rh==-1)
        return -1;

    if(abs(rh-lh)>1)
        return -1;

    
    return 1+max(lh,rh);
}

bool isBalanced(TreeNode* root) {
        
    return height(root)!=-1; //since the height function already returns -1, this is a better way to write

}