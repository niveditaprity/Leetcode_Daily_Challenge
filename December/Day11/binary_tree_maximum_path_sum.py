class Solution:
    def __init__(self):
        self.maxsum = float("-inf")
    
    def solve(self, root):
        if root == None:
            return 0

        left_sum = self.solve(root.left)
        right_sum = self.solve(root.right)

        all_good_sum = left_sum + right_sum + root.val
        one_good_sum = max(left_sum, right_sum) + root.val
        only_root_is_good = root.val
        
        self.maxsum = max(self.maxsum, all_good_sum, one_good_sum, only_root_is_good)

        return max(one_good_sum, only_root_is_good)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.maxsum