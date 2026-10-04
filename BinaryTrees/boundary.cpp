//Problem-Boundary Traversal
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//check if a node is leaf node or not
bool isLeaf(TreeNode* node){
    return node!=nullptr && node->left==nullptr && node->right==nullptr;
}


//left boundary exlcuding the leaf nodes
void Left(TreeNode* root,vector<int>&result){

    TreeNode* curr=root->left;

    while(curr){
        //if it is not a leaf node
        if(!isLeaf(curr)){
            result.push_back(curr->data);
        }

        //if there is a left,go to the left
        if(curr->left)
            curr=curr->left;

        else curr=curr->right; //otherwise go to the right
    }
}

//right boundary in the reverse order excluding the leaf nodes 
void Right(TreeNode* root,vector<int>&result){
    TreeNode* curr=root->right;

    vector<int>temp;

    while(curr){
        if(!isLeaf(curr))
            temp.push_back(curr->data);

        if(curr->right)
            curr=curr->right;

        else curr=curr->left;
    }

    //since we need it in the reverse order
    int n=temp.size();
    for(int i=n-1;i>=0;i--){
        result.push_back(temp[i]);
    }
}

//leaf nodes

void leaves(TreeNode* root,vector<int>&result){

    if(isLeaf(root)){
        result.push_back(root->data);
        return;
    }

    if(root->left)
        leaves(root->left,result);
    if(root->right)
        leaves(root->right,result);
}

vector<int> boundary(TreeNode* root){

    vector<int>result;

    //if the root is empty, then just return the result
    if(!root)
        return result;

    //if it is not a leaf node, then just push the data
    if(!isLeaf(root))
        result.push_back(root->data);

    Left(root,result);
    leaves(root,result);
    Right(root,result);

    return result;


}