#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//Iterative approach-using two stacks
//TC-O(N),SC-O(2N)
vector<int>postorderTraversal(TreeNode* root){

    vector<int>postorder;

    if(root==nullptr)
        return postorder;

    stack<TreeNode*>s1,s2;

    s1.push(root);

    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root); //wheatver node gets popped from s1 push it into s2

        if(root->left!=nullptr)
            s1.push(root->left);

        if(root->right!=nullptr)
            s1.push(root->right);
    }

    while(!s2.empty()){
        postorder.push_back(s2.top()->data); //since it is last in first out
        s2.pop();
    }

    return postorder;


}

//Using one stack
//TC-O(2N),SC-O(N)
vector<int>postorderTraversal(TreeNode* root){

TreeNode* curr=root;

stack<TreeNode*>st;

vector<int>postorder;

while(curr!=nullptr || !st.empty()){
    if(curr!=nullptr){
        st.push(curr);
        curr=curr->left;
    }

    else{
        TreeNode* temp=st.top()->right;

        if(temp==nullptr){
            temp=st.top();
            st.pop();
            postorder.push_back(temp->data);

            while(!st.empty() && temp==st.top()->right){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
            }
        }

        else{
            curr=temp;
        }
    }

}

return postorder;
}
