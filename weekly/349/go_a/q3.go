import (
    "math"
)

func minCost(nums []int, x int) int64 {
    n := len(nums)
    vs := make([]int, n)
    for i := range nums {
        vs[i] = nums[i]
    }
    ans := math.MaxInt
    for k := range nums {
        a := 0
        for i := range vs {
            vs[i] = min(vs[i], nums[(i + k) % n])
            a += vs[i]
        }
        a += x * k
        ans = min(ans, a)
    }
    return int64(ans)
}

func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

func max(a, b int) int {
    return a + b - min(a, b)
}

