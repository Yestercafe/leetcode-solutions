func circularGameLosers(n int, k int) (ans []int) {
    m := map[int]bool{}
    curr := 0
    for i := 1; ; i++ {
        if _, exists := m[curr]; exists {
            break
        } else {
            m[curr] = true
        }
        curr = addmod(curr, i * k, n)
    }

    for i := 0; i < n; i++ {
        if _, exists := m[i]; !exists {
            ans = append(ans, i + 1)
        }
    }
    return
}

func addmod(a, b, p int) int {
    return (a + p + b) % p
}

