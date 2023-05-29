/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) (ans []*TreeNode) {
    del := map[int]bool{}
    for _, v := range to_delete {
        del[v] = true
    }

    var dfs func(*TreeNode, *TreeNode, bool)
    dfs = func (root, parent *TreeNode, par_del bool) {
        if root == nil { return }
        if _, exists := del[root.Val]; exists {
            if parent != nil {
                if parent.Left == root { parent.Left = nil }
                if parent.Right == root { parent.Right = nil }
            }
            dfs(root.Left, root, true)
            dfs(root.Right, root, true)
            root.Left, root.Right = nil, nil
        } else {
            if par_del {
                ans = append(ans, root)
            }
            dfs(root.Left, root, false)
            dfs(root.Right, root, false)
        }
    }

    dfs(root, nil, true)
    return
}

