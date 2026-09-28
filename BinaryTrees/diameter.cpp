//Problem-Diameter of a Binary Tree
//Difficulty-Easy

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


//Brute Force-O(n2)-Finding the height at each and every single node and returning the max
int height(TreeNode* root ){

    if(root==nullptr)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    return 1+max(lh,rh);

}


int findmax(TreeNode* root){

    int maxi=0;


    int lh=height(root->left);

    int rh=height(root->right);

    maxi=max(maxi,lh+rh);

    findmax(root->left);

    findmax(root->right);

    
}


//Optimal Solution-Using O(N)-finding the height of the tree
int height(TreeNode* root,int &diameter){ //since diameter is a gloabl variable it is passed by refernce here otherwise it wont update

    if(root==nullptr)
        return 0;


    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);

    diameter=max(diameter,lh+rh);

    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root){

    int diameter=0;
    height(root,diameter);
    return diameter;


}