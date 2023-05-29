func averageValue(nums []int) (ans int) {
    cnt := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] % 6 == 0 {
            ans += nums[i]
            cnt++
        }
    }
    if cnt > 0 {
        ans /= cnt
    }
    return
}

