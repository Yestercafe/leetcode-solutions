func canMakePaliQueries(s_ string, queries [][]int) []bool {
    n := len(s_)
    s := []rune(s_)
    pref := make([][]int, n + 1)
    pref[0] = make([]int, 26)
    for i := 0; i < n; i++ {
        pref[i + 1] = make([]int, 26)
        for j := range pref[i + 1] {
            pref[i + 1][j] = pref[i][j]
        }
        pref[i + 1][s[i] - 'a']++
    }
    
    nq := len(queries)
    ans := make([]bool, nq)
    for iq, q := range queries {
        need := 0
        left, right, k := q[0], q[1], q[2]
        for j := range pref[0] {
            if (pref[right + 1][j] - pref[left][j]) % 2 == 1 {
                need++
            }
        }
        
        if need / 2 <= k {
            ans[iq] = true
        }
    }
    return ans
}

