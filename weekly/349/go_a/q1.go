func findNonMinOrMax(nums []int) int {
    arr := make([]int, 3)
    PH := -114514
    for i := range arr {
        arr[i] = PH
    }
    for _, v := range nums {
        if arr[0] != PH && arr[1] != PH && arr[2] != PH {
            sort.Ints(arr)
            return arr[1]
        }
        if v != arr[0] && v != arr[1] && v != arr[2] {
            for i := range arr {
                if arr[i] == PH {
                    arr[i] = v
                    break
                }
            }
        }
    }

    if arr[0] != PH && arr[1] != PH && arr[2] != PH {
        sort.Ints(arr)
        return arr[1]
    }
    return -1
}

