class Solution:
    def __init__(self):
        self.maxV = 0
        self.minV = 100_000

    def get_diff(self, root, min_value, max_value):
        if root == None:
            return abs(max_value - min_value)

        min_value = min(min_value, root.val)
        max_value = max(max_value, root.val)
        
        res1 = self.get_diff(root.left, min_value, max_value)
        res2 = self.get_diff(root.right, min_value, max_value)
        return max(res2, res1)


    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        return self.get_diff(root, self.minV, self.maxV)