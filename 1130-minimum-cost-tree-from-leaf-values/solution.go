const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)

func mctFromLeafValues(arr []int) int {
    n := len(arr)
    maxValueIn := make([][]int, n)
    for i := range maxValueIn {
        maxValueIn[i] = make([]int, n)
        maxValueIn[i][i] = arr[i]
        for j := i + 1; j < n; j++ {
            maxValueIn[i][j] = max(maxValueIn[i][j - 1], arr[j])
        }
    }

    f := make([][]int, n)
    for i := range f {
        f[i] = make([]int, n)
        f[i][i] = arr[i]
    }

    for d := 1; d < n; d++ {
        for i := 0; i + d < n; i++ {
            j := i + d
            // [i, sp], [sp + 1, j]
            minC := MaxInt
            for sp := i; sp + 1 <= j; sp++ {
                c := (maxValueIn[i][sp] * maxValueIn[sp + 1][j]) + f[i][sp] + f[sp + 1][j]
                minC = c + minC - max(c, minC)
            }
            f[i][j] = minC
        }
    }

    leafSum := 0
    for _, v := range arr {
        leafSum += v
    }
    return f[0][n - 1] - leafSum
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

