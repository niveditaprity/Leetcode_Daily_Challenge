class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) {
            return 0;
        }

        // Get the current node value.
        int currVal = root->val;
        // If the node value is within range, take the value into sum else leave it.
        int sum = (currVal >= low && currVal <= high) ? currVal : 0;        

        // If the current node >= low, go to left to find the node with lesser value. 
        if(currVal >= low) {
            sum += rangeSumBST(root->left, low, high);    
        }

        // If the current node <= high, go to right to find the node with greater value.
        if(currVal <= high) {
            sum += rangeSumBST(root->right, low, high);    
        }
        
        // Return the final sum.
        return sum;
    }
};