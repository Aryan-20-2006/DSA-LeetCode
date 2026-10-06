//Problem-Vertical order traversal 
//Difficulty-Hard

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

vector<vector<int>> verticalTraversal(TreeNode* root){


    map<int,map<int,multiset<int>>>nodes; //{verticals,map<int,multiset<int>>>} which means on each vertical there would be levels, on every level there would be multinodes
    //we're using a multiset because here duplicate values are also possible

    queue<pair<TreeNode*,pair<int,int>>>queue;
    queue.push({root,{0,0}}); //the queue will have (node,vertical,level)

    while(!queue.empty()){
        auto p=queue.front(); //here p={node,{vertical,level}}
        queue.pop();
        TreeNode* node=p.first;
        int x=p.second.first , y=p.second.second;

        //take the node off the queue and record its value at nodes[x][y], that is what the map is used for 
        //Eg:- 1->1->{3}

        nodes[x][y].insert(node->val);

        if(node->left)
            queue.push({node->left,{x-1,y+1}});//if you're going left, then -1 and then increase the level by 1

        if(node->right)
            queue.push({node->right,{x+1,y+1}}); //similarly if you are going right, then +1 and then increase the level by 1
        
    }

    vector<vector<int>>ans;
    //traverse across the map nodes
    for(auto p:nodes){
        vector<int> col;

        for(auto q:p.second){ //traversing across map<int,multiset<int>
            for(int val:q.second){ //q.second is the multiset
                col.push_back(val);
            }
        }

        ans.push_back(col);
    }

    return ans;
    
}