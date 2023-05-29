func search(nums []int, target int) int {
    l, r, p := -1, len(nums), len(nums)
    for ; l + 1 < r; {
        mid := (l + r) / 2
        if nums[addmod(mid, -1, p)] > nums[mid] && nums[mid] < nums[addmod(mid, 1, p)] {
            r = mid
            break
        }
        if nums[mid] > nums[r - 1] {
            l = mid
        } else {
            r = mid
        }
    }
    
    m := r
    l, r = -1, len(nums)
    for ; l + 1 < r; {
        mid := (l + r) / 2
        if nums[addmod(mid, m, p)] < target {
            l = mid
        } else {
            r = mid
        }
    }

    idx := addmod(r, m, p)
    if nums[idx] == target {
        return idx
    } else {
        return -1
    }
}

func addmod(a, b, p int) int {
    return (a + p + b) % p
}

