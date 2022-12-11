class Solution {
private:
    int compute(TreeNode* root, int &maxPath) {
        // if there is no further subtrees then take that subtree path as 0.
        if(root==NULL) {
            return 0;
        }
        
        // Traverse in both the subtrees to find the maximum path
        int left = compute(root->left, maxPath);
        int right = compute(root->right, maxPath);
        
        // Avoid subtree which is giving -ve value as it will reduce the answer for maximum path.
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        
        // Answer is getting stored in maxPath variable.
        maxPath = max(maxPath, root->val + left + right);
        
        // Out of left and right subtrees, take only that subtree which is giving the largest value.
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        // Initialize ans with -∞ as node values can be -ve also.
        int ans = INT_MIN;
        // Get the maximum path stored in answer variable.
        compute(root, ans);
        return ans;
    }
};