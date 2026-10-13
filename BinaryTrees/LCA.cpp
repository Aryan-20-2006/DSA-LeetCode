//Problem-Lowest Common Ancestor
//Difficulty-Medium

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

//TC-O(N),SC-O(N)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
    //Base case-if you find the node that you are looking for , return it
    if(root==NULL || root==p || root==q)
        return root;

    //Recursive traversal
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    TreeNode* right=lowestCommonAncestor(root->right,p,q);

    //if either left or right is null , return the value which is not null
    if(left==NULL)
        return root->right;
    else if(right==NULL)
        return root->left;

    //if neither are null, then we have found our LCA
    else
        return root;

}
