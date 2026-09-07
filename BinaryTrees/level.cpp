//Problem-Level order traversal
//Difficulty-Easy
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };

//TC-O(N), SC-O(N)
vector<vector<int>> levelOrder(TreeNode* root){

vector<vector<int>>ans; //storing the level order traversal

if(root==nullptr)
    return ans;

queue<TreeNode*>q;

q.push(root);

while(!q.empty()){
    
    
    int size=q.size();
    vector<int>level;

    for(int i=0;i<size;i++){ //this traverses level wise eg:-1,then 2,3 , then 4,5,6,7
        TreeNode* node=q.front();
        q.pop();

        if(node->left!=nullptr) 
            q.push(node->left);

        if(node->right!=nullptr)
            q.push(node->right);

        level.push_back(node->data);
    }

    ans.push_back(level); //since we're storing the vector of vectors

}


return ans;

}