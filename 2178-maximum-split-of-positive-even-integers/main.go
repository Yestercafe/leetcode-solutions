func maximumEvenSplit(finalSum int64) (ans []int64) {
    if finalSum % 2 == 1 {
        return []int64{}
    }
    curr := int64(2)
    for finalSum >= curr {
        ans = append(ans, curr)
        finalSum -= curr
        curr += 2
    }

    if finalSum != 0 {
        tail := len(ans) - 1
        ans[tail] = finalSum + ans[tail]
    }
    return
}

