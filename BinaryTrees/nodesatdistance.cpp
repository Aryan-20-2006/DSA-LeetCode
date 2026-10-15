//Problem-Print all nodes at a distance k
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

/*
1.Find the parent pointers
2.From each node, travel radially outwards

*/


 void markParents(TreeNode* root,unordered_map<TreeNode*, TreeNode*>&parent_track, TreeNode* target){

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current=q.front();
        q.pop();

        if(current->left){
            parent_track[current->left]=current; //{node,parent}
            q.push(current->left);
        }

        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }

    }

}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode*,TreeNode*>parent_track; //node->parent

    markParents(root,parent_track,target);
    //create a visited array, so that we dont consider the same node twice
    unordered_map<TreeNode*,bool>visited;

    queue<TreeNode*>q;

    q.push(target);

    visited[target]=true;

    int curr_level=0;

    //doing a level order traversal
    while(!q.empty()){
        int size=q.size();

        if(curr_level==k) break;

        curr_level++;

        for(int i=0;i<size;i++){
            TreeNode* curr=q.front();
            q.pop();

            //in case it has not been visited i.e left,right or parent
            
            //if the left node hasnt been visited
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            //if the right node hasnt been visited
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            //if the parent node hasnt been visited
            if(parent_track[curr] && !visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }




    }

    //the remaining nodes will be at a distance k from the target node. Because once currlevel=k
    //we break out

    vector<int>result;
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        result.push_back(curr->val);
    }

    return result;
    }
