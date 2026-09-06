#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };

//Iterative approach-Left,Root,Right
vector<int> inorderTraversal(TreeNode* root){

stack<TreeNode*>st;

TreeNode* node=root; //storing root in node

vector<int>inorder;

while(true){

    //if the node is not null, push that node and go to the left
    if(node!=nullptr){
        st.push(node);
        node=node->left;
    }

    //if it is NULL
    else{
        //once your stack become empty break
        if(st.empty())
            break;
        node=st.top(); //if it is null, whatever is at the the top of the stack , take it
        inorder.push_back(node->data);
        st.pop();
        node=node->right;
    }


}

return inorder;


}