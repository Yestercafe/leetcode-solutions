func numTimesAllBlue(flips []int) int {
    maxx := -1
    ans := 0
    for i, v := range flips {
        maxx = max(maxx, v)
        if i + 1 == maxx {
            ans++
        }
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

