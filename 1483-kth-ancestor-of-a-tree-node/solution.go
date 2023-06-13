type TreeAncestor struct {
    f [][]int
}


func ffs(k int) (ret int) {
    for k % 2 == 0 {
        ret++
        k /= 2
    }
    return
}


func Constructor(n int, parent []int) TreeAncestor {
    k := 0
    for 1 << k < n {
        k++
    }

    ta := TreeAncestor {
        f: make([][]int, n),
    }

    for i := range parent {
        ta.f[i] = append(ta.f[i], parent[i])
    }
    for j := 0; ; j++ {
        done := true
        for i := range parent {
            p := -1
            if ta.f[i][j] != -1 {
                p = ta.f[ta.f[i][j]][j]
            }
            ta.f[i] = append(ta.f[i], p)
            if p != -1 {
                done = false
            }
        }
        if done {
            break
        }
    }

    return ta
}


func (this *TreeAncestor) GetKthAncestor(node int, k int) int {
    if k == 0 || node == -1 {
        return node
    }
    pos := ffs(k)
    if pos >= len(this.f[node]) {
        return -1
    }
    return this.GetKthAncestor(this.f[node][pos], k - (1 << pos))
}


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * obj := Constructor(n, parent);
 * param_1 := obj.GetKthAncestor(node,k);
 */

