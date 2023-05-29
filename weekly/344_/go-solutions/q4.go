func minIncrements(n int, cost []int) (ans int) {
    left := func (x int) int {
        return 2 * x + 1
    }
    right := func (x int) int {
        return 2 * x + 2
    }

    for i := n / 2 - 1; i >= 0; i-- {
        l, r := left(i), right(i)
        d := abs(cost[l] - cost[r])
        ans += d
        cost[i] += max(cost[l], cost[r])
    }

    return 
}

func abs(a int) int {
    if a < 0 {
        return -a
    } else {
        return a
    }
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

