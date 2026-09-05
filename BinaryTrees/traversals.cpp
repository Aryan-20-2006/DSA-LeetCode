//Binary Tree Traversals

#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
  };


class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			//your code goes here
            
            //{node,num}
            stack<pair<TreeNode*,int>> st;

            st.push({root,1});

            vector<int>pre,in,post; //creating lists to store the pre,in and post order traversals

            if(root==NULL)
                return {};

            while(!st.empty()){
                auto it=st.top();
                st.pop();


                //this is a part of preorder
                //if num==1 i.e preorder then increment 1 to 2 
                //push the left side of the tree

                if(it.second==1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it); //after incrementing , again push it back into the stack

                    //if a left exists,push it
                    if(it.first->left!=NULL){
                        st.push({it.first->left,1});
                    }
                }

                //this is a part of inorder
                //if num==2 i.e inorder then increment 2 to 3
                //push the right side of the tree
                else if(it.second==2){
                    in.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    //if a right exists, push it 
                    if(it.first->right!=NULL){
                        st.push({it.first->right,1});
                    }
                }

                //for postorder, dont push it back again
                else{
                    post.push_back(it.first->data);
                }
            }

            //Storing the traversals
            vector<vector<int>>result;
            result.push_back(pre);
            result.push_back(in);
            result.push_back(post);

            return result;

        
        
        }
};