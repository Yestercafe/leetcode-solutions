func paintWalls(cs []int, ts []int) int {
    n := len(cs)
    f := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        f[i] = math.MaxInt / 4
    }
    for i, c := range cs {
        t := ts[i] + 1
        for j := n; j > 0; j-- {
            f[j] = min(f[j], f[max(j - t, 0)] + c)
        }
    }

    return f[n]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

