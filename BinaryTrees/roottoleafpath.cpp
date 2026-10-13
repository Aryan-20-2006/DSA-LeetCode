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



void getPath(TreeNode* root,vector<int>&path,vector<vector<int>>&result){

    if(root==nullptr)
        return;

    //start by pushing the root->val
    path.push_back(root->val);

    //if you reach a leaf node , the path is added to your result
    if(root->left==nullptr || root->right==nullptr)
        result.push_back(path);

    //if its not the leaf node,recurse both the left and right half
    else 
        getPath(root->left,path,result);
        getPath(root->right,path,result);

    //everytime you backtrack, remove the last node
    path.pop_back();
}

vector<vector<int>>allRootToLeaf(TreeNode* root){

    vector<vector<int>>result;
    vector<int>path;
    if(root==nullptr)
        return result;

    getPath(root,path,result);

    return result;


}