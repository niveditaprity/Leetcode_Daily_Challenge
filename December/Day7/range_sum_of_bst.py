class Solution:
    def __init__(self):
        self.total = 0

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root == None:
            return
        if root.val >= low and root.val <= high:
            self.total += root.val 
        self.rangeSumBST(root.left, low, high)
        self.rangeSumBST(root.right, low, high)
        return self.total


# Optimized solution based on value comparison
class Solution:

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if root == None:
            return 0

        total = root.val if root.val >= low and root.val <= high else 0

        if root.val >= low:
            total += self.rangeSumBST(root.left, low, high)
        if root.val <= high:
            total += self.rangeSumBST(root.right, low, high)

        return total