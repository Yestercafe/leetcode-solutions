func minNumberOfSemesters(n int, relations [][]int, k int) int {
    pre := make([]int, n)
    for _, r := range relations {
        p, s := r[0] - 1, r[1] - 1
        pre[s] |= 1 << p
    }

    f := make([]int, 1 << n)
    u := (1 << n) - 1
    for s := 1; s < 1 << n; s++ {
        cs := u ^ s
        js := 0
        for j, p := range pre {
            if s >> j & 1 > 0 && cs | p == cs {
                js |= 1 << j
            }
        }
        if bits.OnesCount(uint(js)) <= k {
            f[s] = f[s ^ js] + 1
            continue
        }

        f[s] = math.MaxInt
        for j := js; j > 0; j = (j - 1) & js {
            if bits.OnesCount(uint(j)) == k {
                f[s] = min(f[s], f[s ^ j] + 1)
            }
        }
    }

    return f[u]
}

func min(a, b int) int {
    if a < b {
        return a
    } else {
        return b
    }
}

