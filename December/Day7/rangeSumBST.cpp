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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
       if(root == NULL)
       {
           return 0;
       } 
       if(root->val >= low && root->val <= high)
       {
           sum+=root->val;
       }
       rangeSumBST(root->left,low,high);
       rangeSumBST(root->right,low,high);
       return sum;
    }
};
