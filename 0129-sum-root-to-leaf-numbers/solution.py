# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    sum = 0
    def dfs(self, root: TreeNode, pref: int):
        nxt_pref = pref * 10 + root.val
        if root.left is None and root.right is None:
            self.sum += nxt_pref
            return
        if not root.left is None:
            self.dfs(root.left, nxt_pref)
        if not root.right is None:
            self.dfs(root.right, nxt_pref)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        self.dfs(root, 0)
        return self.sum

