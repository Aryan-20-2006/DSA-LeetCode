//Problem-Zig Zag Traversal
//Difficulty-Medium

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root){


    vector<vector<int>>result;

    if(root==NULL)
        return result;

    queue<TreeNode*>q;

    bool lefttoright=true; //this tell us if we're moving from left to right or right to left

    q.push(root);

    //If the flag=0 (left to right) and flag=1 (right to left)
    while(!q.empty()){
        int size=q.size();

        vector<int>level(size); //why level(size)-because im putting values at specific postions instead of appending

        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();

            //checking if the flag is true, insert it from left to right , if not then right to left
            int index;

            if(lefttoright)
                index=i;    
            
            else 
                index=size-1-i; //this will insert from right to left;

            level[index]=node->data;

            if(node->left!=NULL)
                q.push(node->left);

            if(node->right!=NULL)
                q.push(node->right); 
        }

        //after every level the flag should switch from 0 to 1 to 0 and so on
        lefttoright=!lefttoright;
        result.push_back(level);

    }

    return result;

}