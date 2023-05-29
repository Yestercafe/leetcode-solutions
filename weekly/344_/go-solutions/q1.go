func distinctDifferenceArray(nums []int) (ans []int) {
    cnt := func (arr []int) int {
        m := map[int]int{}
        for _, v := range arr {
            m[v]++
        }
        return len(m)
    }

    for i := range nums {
        ans = append(ans, cnt(nums[:i+1]) - cnt(nums[i+1:]))
    }
    return
}

