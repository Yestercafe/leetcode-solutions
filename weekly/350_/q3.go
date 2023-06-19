func specialPerm(nums []int) (ans int) {
    const MOD int = 1e9 + 7
    n := len(nums)
    m := 1 << n
    // f[x][y]:n
    // x means nums[x] can be used
    // y means the previous selected one is nums[y]
    f := make([][]int, m)
    for i := range f {
        f[i] = make([]int, n)
    }
    for j := range f[0] {
        f[0][j] = 1
    }
    for i := 1; i < m; i++ {
        for j, x := range nums {
            a, k := i, 0
            for a > 0 {
                if a & 1 == 1 && (x % nums[k] == 0 || nums[k] % x == 0) {
                    f[i][j] = (f[i][j] + f[i ^ (1 << k)][k]) % MOD
                }
                k++
                a >>= 1
            }
        }
    }

    for j := range nums {
        ans = (ans + f[(m - 1) ^ (1 << j)][j]) % MOD
    }
    return
}

