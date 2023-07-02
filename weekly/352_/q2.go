func findPrimePairs(n int) (ans [][]int) {
    if n == 1 { return }
    euler := make([]bool, n)    // false is prime
    var primes []int
    euler[0], euler[1] = true, true
    init_euler := func () {
        for i := 2; i < n; i++ {
            if !euler[i] {
                primes = append(primes, i)
                
            }
            for _, pj := range primes {
                if pj * i >= n { break }
                euler[pj * i] = true
                if i % pj == 0 {
                    break
                }
            }
        }
    }

    init_euler()

    // x <= y
    for x := 1; x <= n - x; x++ {
        y := n - x
        if !euler[x] && !euler[y] {
            ans = append(ans, []int{x, y})
        }
    }

    return 
}

