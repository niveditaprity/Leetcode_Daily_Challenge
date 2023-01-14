/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<Integer> ls= new ArrayList<Integer>();
    public List<Integer> preorderTraversal(TreeNode root) {
       helper(root);
       return ls;
    }
    private void helper(TreeNode root){
        if(root==null)return;
        ls.add(root.val);
        if(root.left!=null) helper(root.left);
        if(root.right!=null)helper(root.right);
        return ;
    }
}
