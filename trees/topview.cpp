//Problem-Top View
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

//here we will use the concept of lines from vertical order traversal

vector<int>topView(TreeNode* root){

    vector<int>ans;

    map<int,int>map; //this stores the {line,node} we need map for the sorted order

    queue<pair<TreeNode*,int>>q; //{node,line}

    //push the root and the line on which it is at the start
    q.push({root,0});

    while(!q.empty()){

        auto it=q.front();
        q.pop();

        TreeNode* node=it.first;
        int line=it.second;

        //if node hasnt been already there having the same line, add it in the map
        if(map.find(line)==map.end())
            map[line]=node->val;

        if(node->left!=NULL)
            q.push({node->left,line-1});

        if(node->right!=NULL)
            q.push({node->right,line+1});

        
    }


    for(auto it:map){
        ans.push_back(it.second); //{line,node}
    }

    return ans;



}