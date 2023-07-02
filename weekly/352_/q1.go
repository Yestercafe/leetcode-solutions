func longestAlternatingSubarray(nums []int, th int) (ans int) {
    cons := 0
    for _, a := range nums {
        if cons != 0 {
            if cons % 2 == 0 && a % 2 == 0 && a <= th {
                cons++
                continue
            }
            if cons % 2 == 1 && a % 2 == 1 && a <= th {
                cons++
                continue
            }
            ans = max(ans, cons)
            cons = 0
        }

        if cons == 0 && a % 2 == 0 && a <= th {
            cons++
            continue
        }
    }

    if cons != 0 {
        ans = max(ans, cons)
    }

    return
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

