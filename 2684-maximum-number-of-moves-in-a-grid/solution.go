func maxMoves(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    f := make([][]bool, n)
    for i := range grid {
        f[i] = make([]bool, m)
    }
    for i := range grid {
        f[i][0] = true
    }
    
    transfer := func (i, j int) bool {
        if grid[i][j - 1] < grid[i][j] && f[i][j - 1] {
            return true
        }
        if i - 1 >= 0 && grid[i - 1][j - 1] < grid[i][j] && f[i - 1][j - 1] {
            return true
        }
        if i + 1 < n && grid[i + 1][j - 1] < grid[i][j] && f[i + 1][j - 1] {
            return true
        }
        return false
    }

    for j := range f[0] {
        if j == 0 { continue }
        for i := range f {
            f[i][j] = transfer(i, j)
            if f[i][j] {
                ans = j
            }
        }
    }

    return
}

