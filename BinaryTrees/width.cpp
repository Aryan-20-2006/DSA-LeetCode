//Problem-Maximum Width of a binary tree
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

int widthofBinaryTree(TreeNode* root){

    if(root==NULL)
        return 0; //if its a null node, the width is zero

    int maxwidth=0;

    queue<pair<TreeNode*,int>>q; //{Node,index}

    q.push({root,0});

    //we're doing a level order traversal here
    while(!q.empty()){
        int size=q.size();
        int mini=q.front().second; //to avoid overflow we're subtracting it from the min index
        //Eg:- if its 1 then it should be 0 and 2 becomes 1
        int first,last; //to store the first and the last index

        for(int i=0;i<q.size();i++){
            int cur_index=q.front().second-mini; //Eg:- If min is 1 then (1-1)=0 ,(2-1)=1
            TreeNode* node=q.front().first;
            q.pop();

            if(i==0)
                first=cur_index;
            if(i==size-1)
                last=cur_index;

            //recursively go left and right
            if(node->left!=nullptr)
                q.push({node->left,cur_index*2+1});

            if(node->right!=nullptr)
                q.push({node->right,cur_index*2+2});

      
        }

        maxwidth=max(maxwidth,last-first+1);

    }

    return maxwidth;

}
