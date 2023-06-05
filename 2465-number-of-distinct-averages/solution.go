func distinctAverages(nums []int) int {
    sort.Slice(nums, func (i, j int) bool { return nums[i] < nums[j] })
    n := len(nums) / 2
    s := map[float32]bool{}
    for i := 0; i < n; i++ {
        s[float32(nums[i] + nums[2 * n - 1 - i]) / 2] = true
    }
    return int(len(s))
}

