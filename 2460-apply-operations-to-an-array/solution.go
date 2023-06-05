func applyOperations(nums []int) []int {
    n := len(nums)
    for i := 0; i < n - 1; i++ {
        if nums[i] == nums[i + 1] {
            nums[i] *= 2
            nums[i + 1] = 0
        }
    }

    ans := make([]int, n)
    p := 0
    for _, v := range nums {
        if v != 0 {
            ans[p] = v
            p++
        }
    }
    return ans
}

