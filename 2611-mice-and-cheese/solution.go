func miceAndCheese(reward1 []int, reward2 []int, k int) (ans int) {
    n := len(reward1)
    diff := make([]int, n)
    for i := range reward1 {
        ans += reward1[i]
        diff[i] = reward2[i] - reward1[i]
    }
    
    sort.Ints(diff)
    for i := k; i < n; i++ {
        ans += diff[i]
    }
    return
}

