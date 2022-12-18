/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void preorder(TreeNode*root,vector<int>&leafNodes)
   {
       if(root==NULL)
       {
           return;
       }
       if(root && root->left == NULL && root->right== NULL)
       {
           leafNodes.push_back(root->val);
       }
       preorder(root->left,leafNodes);
       preorder(root->right,leafNodes);
   }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int>leafNodes1,leafNodes2;
      preorder(root1,leafNodes1);
      preorder(root2,leafNodes2);
      int n = leafNodes1.size();
      if(leafNodes1 == leafNodes2)
      {
          return true;
      }
      return false;  
    }
};
