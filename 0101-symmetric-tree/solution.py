# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def f(p: TreeNode, q: TreeNode) -> bool:
            if p is None or q is None:
                return p is q
            return p.val == q.val and f(p.left, q.right) and f(p.right, q.left)
        return f(root.left, root.right)

