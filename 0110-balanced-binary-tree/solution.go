/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    var height func(*TreeNode) int
    height = func (root *TreeNode) int {
        if root == nil {
            return 0
        }
        l_height := height(root.Left)
        if l_height < 0 {
            return -1
        }
        r_height := height(root.Right)
        if r_height < 0 {
            return -1
        }
        if 2 * max(l_height, r_height) - (l_height + r_height) > 1 {
            return -1
        }

        return 1 + max(l_height, r_height)
    }
    return height(root) != -1
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

