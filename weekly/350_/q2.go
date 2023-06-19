func findValueOfPartition(nums []int) int {
    sort.Ints(nums)
    ans := math.MaxInt
    n := len(nums)
    for i := 0; i < n - 1; i++ {
        ans = min(ans, abs(nums[i] - nums[i + 1]))
    }
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

