# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    paths = []

    def dfs(self, root: TreeNode, path: List[str]):
        path.append(str(root.val))
        if root.left is None and root.right is None:
            self.paths.append('->'.join(path))
            path.pop()
            return
        if not root.left is None:
            self.dfs(root.left, path)
        if not root.right is None:
            self.dfs(root.right, path)
        path.pop()

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.paths = []
        if root is None:
            return []
        self.dfs(root, [])
        return self.paths
