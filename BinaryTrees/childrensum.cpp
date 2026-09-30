//Problem-Children Sum Property in Binary Tree
//Diffifculty-Medium

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//TC-O(N),SC-O(H)
bool checkChildrenSum(TreeNode* root){

//checking if the root is null or if it is a leaf node, then it automatically becomes true
if(root==nullptr || (root->left==nullptr && root->right==nullptr))
    return true;

int l;
int r;

//if its not null
if(root->left!=nullptr){
    l=root->left->val;
}

else{
    l=0;
}

if(root->right!=nullptr){
    r=root->right->val;
}

else{
    r=0;
}


return ((l+r)==root->val) && checkChildrenSum(root->left) && checkChildrenSum(root->right);


}