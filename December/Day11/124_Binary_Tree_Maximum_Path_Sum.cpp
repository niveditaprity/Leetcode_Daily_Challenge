class Solution {
public:
    int ans = INT_MIN;
    int find(TreeNode*root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = find(root->left);
        int right = find(root->right);
        left = left>0 ? left : 0;
        right = right>0 ? right : 0;
        ans = max(ans ,root->val + left + right);
        return  root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
      find(root);
      return ans;  
    }
};
