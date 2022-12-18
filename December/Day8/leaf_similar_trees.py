class Solution:
    def __init__(self):
        self.l1 = []
        self.l2 = []

    def get_leaves(self, root, l):
        if root == None:
            return
        if root.left == None and root.right == None:
            l.append(root.val)

        self.get_leaves(root.left, l)
        self.get_leaves(root.right, l)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        self.get_leaves(root1, self.l1)
        self.get_leaves(root2, self.l2)
        return self.l1 == self.l2