//Problem-Binary Tree Right Side View
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

//TC-O(N),SC-O(H)
//Doing a reverse preorder-Root Right Left
void reversePreorder(TreeNode* node, int level,vector<int>&ds){

        if(node==NULL)
            return;

        if(level==ds.size())
            ds.push_back(node->val);

        reversePreorder(node->right,level+1,ds);

        reversePreorder(node->left,level+1,ds);

    }

vector<int> rightSideView(TreeNode* root) {

    vector<int>ds;  
    reversePreorder(root,0,ds);
    return ds;

    }