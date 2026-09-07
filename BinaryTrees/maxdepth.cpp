//Problem-Max depth of a binary tree
//Difficulty-Easy

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };

int maxDepth(TreeNode* root){

    queue<TreeNode*>q;
    

    q.push(root);
    int currlevel=0; 

    if(root==NULL)
        return currlevel;

    while(!q.empty()){

        currlevel++;
        int levelsize=q.size();//this processes nodes at the start of the level so it only pushes the node upto that levelsize

        //no of nodes at the current level-q.size();
        for(int i=0;i<levelsize;i++){
            TreeNode* node=q.front();
            q.pop();

            if(node->left!=NULL)
                q.push(node->left);

            if(node->right!=NULL)
                q.push(node->right);
        }

    }

    return currlevel;

}


